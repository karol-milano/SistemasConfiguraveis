@@ -29,6 +29,7 @@
 #include "getargs.h"
 
 bool complaint_issued;
+static unsigned *indent_ptr = 0;
 
 
 
@@ -46,11 +47,22 @@ error_message (location *loc,
 	       const char *prefix,
 	       const char *message, va_list args)
 {
+  unsigned pos = 0;
+
   if (loc)
-    location_print (stderr, *loc);
+    pos += location_print (stderr, *loc);
   else
-    fputs (current_file ? current_file : program_name, stderr);
-  fputs (": ", stderr);
+    pos += fprintf(stderr, "%s", current_file ? current_file : program_name);
+  pos += fprintf(stderr, ": ");
+
+  if (indent_ptr)
+    {
+      if (!*indent_ptr)
+        *indent_ptr = pos;
+      else if (*indent_ptr > pos)
+        fprintf (stderr, "%*s", *indent_ptr - pos, "");
+      indent_ptr = 0;
+    }
 
   if (prefix)
     fprintf (stderr, "%s: ", prefix);
@@ -93,6 +105,15 @@ warn_at (location loc, const char *message, ...)
   ERROR_MESSAGE (&loc, _("warning"), message);
 }
 
+void
+warn_at_indent (location loc, unsigned *indent,
+                const char *message, ...)
+{
+  set_warning_issued ();
+  indent_ptr = indent;
+  ERROR_MESSAGE (&loc, _("warning"), message);
+}
+
 void
 warn (const char *message, ...)
 {
@@ -112,6 +133,15 @@ complain_at (location loc, const char *message, ...)
   complaint_issued = true;
 }
 
+void
+complain_at_indent (location loc, unsigned *indent,
+                    const char *message, ...)
+{
+  indent_ptr = indent;
+  ERROR_MESSAGE (&loc, NULL, message);
+  complaint_issued = true;
+}
+
 void
 complain (const char *message, ...)
 {
