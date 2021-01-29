@@ -100,7 +100,7 @@ void
 set_warning_issued (void)
 {
   static bool warning_issued = false;
-  if (!warning_issued && (warnings_flag & warnings_error))
+  if (!warning_issued && (warnings_flag & Werror))
     {
       fprintf (stderr, "%s: warnings being treated as errors\n", program_name);
       complaint_issued = true;
@@ -111,7 +111,7 @@ set_warning_issued (void)
 void
 warn_at (location loc, const char *message, ...)
 {
-  if (!(warnings_flag & warnings_other))
+  if (!(warnings_flag & Wother))
     return;
   set_warning_issued ();
   ERROR_MESSAGE (&loc, _("warning"), message);
@@ -121,7 +121,7 @@ void
 warn_at_indent (location loc, unsigned *indent,
                 const char *message, ...)
 {
-  if (!(warnings_flag & warnings_other))
+  if (!(warnings_flag & Wother))
     return;
   set_warning_issued ();
   indent_ptr = indent;
@@ -131,7 +131,7 @@ warn_at_indent (location loc, unsigned *indent,
 void
 warn (const char *message, ...)
 {
-  if (!(warnings_flag & warnings_other))
+  if (!(warnings_flag & Wother))
     return;
   set_warning_issued ();
   ERROR_MESSAGE (NULL, _("warning"), message);
@@ -179,7 +179,7 @@ yacc_at (location loc, const char *message, ...)
       ERROR_MESSAGE (&loc, NULL, message);
       complaint_issued = true;
     }
-  else if (warnings_flag & warnings_yacc)
+  else if (warnings_flag & Wyacc)
     {
       set_warning_issued ();
       ERROR_MESSAGE (&loc, _("warning"), message);
@@ -189,7 +189,7 @@ yacc_at (location loc, const char *message, ...)
 void
 midrule_value_at (location loc, const char *message, ...)
 {
-  if (!(warnings_flag & warnings_midrule_values))
+  if (!(warnings_flag & Wmidrule_values))
     return;
   set_warning_issued ();
   ERROR_MESSAGE (&loc, _("warning"), message);
