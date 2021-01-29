@@ -28,6 +28,7 @@
 
 #include "complain.h"
 #include "files.h"
+#include "getargs.h"
 
 /* The calling program should define program_name and set it to the
    name of the executing program.  */
@@ -79,15 +80,29 @@ error_message (location *loc,
 | Report a warning, and proceed.  |
 `--------------------------------*/
 
+static void
+set_warning_issued (void)
+{
+  static bool warning_issued = false;
+  if (!warning_issued && (warnings_flag & warnings_error))
+    {
+      fprintf (stderr, "%s: warnings being treated as errors\n", program_name);
+      complaint_issued = true;
+    }
+  warning_issued = true;
+}
+
 void
 warn_at (location loc, const char *message, ...)
 {
+  set_warning_issued ();
   ERROR_MESSAGE (&loc, _("warning"), message);
 }
 
 void
 warn (const char *message, ...)
 {
+  set_warning_issued ();
   ERROR_MESSAGE (NULL, _("warning"), message);
 }
 
