@@ -25,6 +25,11 @@
 #include <argmatch.h>
 #include <stdarg.h>
 #include <progname.h>
+#include <sys/stat.h>
+
+#if HAVE_LIBTEXTSTYLE
+# include <textstyle.h>
+#endif
 
 #include "complain.h"
 #include "files.h"
@@ -63,6 +68,44 @@ static severity warnings_flag[warnings_size];
 
 static unsigned *indent_ptr = NULL;
 
+#if HAVE_LIBTEXTSTYLE
+styled_ostream_t errstream = NULL;
+#endif
+
+void
+begin_use_class (const char *s _GL_UNUSED, FILE *out _GL_UNUSED)
+{
+#if HAVE_LIBTEXTSTYLE
+  if (out == stderr)
+    {
+      styled_ostream_begin_use_class (errstream, s);
+      styled_ostream_flush_to_current_style (errstream);
+    }
+#endif
+}
+
+void
+end_use_class (const char *s _GL_UNUSED, FILE *out _GL_UNUSED)
+{
+#if HAVE_LIBTEXTSTYLE
+  if (out == stderr)
+    {
+      styled_ostream_end_use_class (errstream, s);
+      styled_ostream_flush_to_current_style (errstream);
+    }
+#endif
+}
+
+void
+flush (FILE *out _GL_UNUSED)
+{
+#if HAVE_LIBTEXTSTYLE
+  if (out == stderr)
+    ostream_flush (errstream, FLUSH_THIS_STREAM);
+#endif
+  fflush (out);
+}
+
 /*------------------------.
 | --warnings's handling.  |
 `------------------------*/
@@ -165,6 +208,22 @@ warnings_argmatch (char *args)
     warning_argmatch ("all", 0, 0);
 }
 
+static const char*
+severity_style (severity s)
+{
+  switch (s)
+    {
+    case severity_disabled:
+    case severity_unset:
+      return "note";
+    case severity_warning:
+      return "warning";
+    case severity_error:
+    case severity_fatal:
+      return "error";
+    }
+  abort ();
+}
 
 static const char*
 severity_prefix (severity s)
@@ -189,6 +248,31 @@ severity_prefix (severity s)
 | complain.  |
 `-----------*/
 
+void
+complain_init_color (void)
+{
+#if HAVE_LIBTEXTSTYLE
+  if (color_mode == color_yes
+      || (color_mode == color_tty && isatty (STDERR_FILENO)))
+    {
+      style_file_prepare ("BISON_DIAGNOSTICS_STYLE", NULL,
+                          pkgdatadir (),
+                          "diagnostics.css");
+      /* As a fallback, use the default in the current directory.  */
+      struct stat statbuf;
+      if ((style_file_name == NULL || stat (style_file_name, &statbuf) < 0)
+          && stat ("diagnostics.css", &statbuf) == 0)
+        style_file_name = "diagnostics.css";
+    }
+  else
+    /* No styling.  */
+    style_file_name = NULL;
+  errstream =
+    styled_ostream_create (STDERR_FILENO, "(stderr)", TTYCTL_AUTO,
+                           style_file_name);
+#endif
+}
+
 void
 complain_init (void)
 {
@@ -248,19 +332,24 @@ warning_is_unset (warnings flags)
   return true;
 }
 
-/** Display a "[-Wyacc]" like message on \a f.  */
+/** Display a "[-Wyacc]" like message on \a out.  */
 
 static void
-warnings_print_categories (warnings warn_flags, FILE *f)
+warnings_print_categories (warnings warn_flags, FILE *out)
 {
   /* Display only the first match, the second is "-Wall".  */
   for (size_t i = 0; warnings_args[i]; ++i)
     if (warn_flags & warnings_types[i])
       {
         severity s = warning_severity (warnings_types[i]);
-        fprintf (f, " [-W%s%s]",
+        const char* style = severity_style (s);
+        fputs (" [", out);
+        begin_use_class (style, out);
+        fprintf (out, "-W%s%s",
                  s == severity_error ? "error=" : "",
                  warnings_args[i]);
+        end_use_class (style, out);
+        fputc (']', out);
         return;
       }
 }
@@ -302,8 +391,15 @@ error_message (const location *loc, warnings flags, severity sever,
       indent_ptr = NULL;
     }
 
+  const char* style = severity_style (sever);
+
   if (sever != severity_disabled)
-    fprintf (stderr, "%s: ", severity_prefix (sever));
+    {
+      begin_use_class (style, stderr);
+      fprintf (stderr, "%s:", severity_prefix (sever));
+      end_use_class (style, stderr);
+      fputc (' ', stderr);
+    }
 
   vfprintf (stderr, message, args);
   /* Print the type of warning, only if this is not a sub message
@@ -318,7 +414,7 @@ error_message (const location *loc, warnings flags, severity sever,
         putc ('\n', stderr);
         fflush (stderr);
         if (loc && feature_flag & feature_caret && !(flags & no_caret))
-          location_caret (*loc, stderr);
+          location_caret (*loc, style, stderr);
       }
   }
   fflush (stderr);
