@@ -23,6 +23,7 @@
 #include "system.h"
 
 #include <argmatch.h>
+#include <ctype.h>
 #include <progname.h>
 #include <stdarg.h>
 #include <sys/stat.h>
@@ -263,6 +264,20 @@ severity_prefix (severity s)
 }
 
 
+static void
+severity_print (severity s, FILE *out)
+{
+  if (s != severity_disabled)
+    {
+      const char* style = severity_style (s);
+      begin_use_class (style, out);
+      fprintf (out, "%s:", severity_prefix (s));
+      end_use_class (style, out);
+      fputc (' ', out);
+    }
+}
+
+
 /*-----------.
 | complain.  |
 `-----------*/
@@ -442,16 +457,7 @@ error_message (const location *loc, int *indent, warnings flags,
         fprintf (stderr, "%*s", *indent - pos, "");
     }
 
-  const char* style = severity_style (sever);
-
-  if (sever != severity_disabled)
-    {
-      begin_use_class (style, stderr);
-      fprintf (stderr, "%s:", severity_prefix (sever));
-      end_use_class (style, stderr);
-      fputc (' ', stderr);
-    }
-
+  severity_print (sever, stderr);
   vfprintf (stderr, message, args);
   /* Print the type of warning, only if this is not a sub message
      (in which case the prefix is null).  */
@@ -465,7 +471,7 @@ error_message (const location *loc, int *indent, warnings flags,
         putc ('\n', stderr);
         flush (stderr);
         if (loc && !(flags & no_caret))
-          location_caret (*loc, style, stderr);
+          location_caret (*loc, severity_style (sever), stderr);
       }
   }
   flush (stderr);
@@ -587,3 +593,53 @@ duplicate_rule_directive (char const *directive,
                    _("previous declaration"));
   fixits_register (&second, "");
 }
+
+void
+syntax_error (location loc,
+              int argc, const char* argv[])
+{
+  if (complaint_status < status_complaint)
+    complaint_status = status_complaint;
+  assert (argc <= 5);
+  const char *format = NULL;
+  switch (argc)
+    {
+# define CASE(N, S)                         \
+      case N:                               \
+        format = S;                         \
+        break
+    default: /* Avoid compiler warnings. */
+      CASE (0, _("syntax error"));
+      CASE (1, _("unexpected %0$s"));
+      CASE (2, _("expected %1$s before %0$s"));
+      CASE (3, _("expected %1$s or %2$s before %0$s"));
+      CASE (4, _("expected %1$s or %2$s or %3$s before %0$s"));
+      CASE (5, _("expected %1$s or %2$s or %4$s or %5$s before %0$s"));
+# undef CASE
+    }
+  location_print (loc, stderr);
+  fputs (": ", stderr);
+  severity_print (severity_error, stderr);
+
+  while (*format)
+    if (format[0] == '%'
+        && isdigit (format[1])
+        && format[2] == '$'
+        && format[3] == 's'
+        && (format[1] - '0') < argc)
+      {
+        int i = format[1] - '0';
+        const char *style = i == 0 ? "unexpected" : "expected";
+        begin_use_class (style, stderr);
+        fputs (argv[i], stderr);
+        end_use_class (style, stderr);
+        format += 4;
+      }
+    else
+      {
+        fputc (*format, stderr);
+        ++format;
+      }
+  fputc ('\n', stderr);
+  location_caret (loc, "error", stderr);
+}
