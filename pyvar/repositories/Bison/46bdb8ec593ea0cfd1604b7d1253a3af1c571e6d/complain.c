@@ -134,9 +134,8 @@ complains (const location *loc, warnings flags, const char *message,
     {
       const char* prefix =
         flags & (errors_flag | complaint) ? _("error") : _("warning");
-      if (flags & complaint)
+      if (flags & (complaint | errors_flag))
         complaint_issued = true;
-      set_warning_issued (flags);
       error_message (loc, flags,
                      indent_ptr && *indent_ptr ? NULL : prefix,
                      message, args);
@@ -171,20 +170,3 @@ void complain_at_indent (location loc, warnings flags, unsigned *indent,
   complains (&loc, flags, message, args);
   va_end (args);
 }
-
-
-/*--------------------------------.
-| Report a warning, and proceed.  |
-`--------------------------------*/
-
-void
-set_warning_issued (warnings warning)
-{
-  static bool warning_issued = false;
-  if (!warning_issued && (warning & warnings_flag & errors_flag))
-    {
-      fprintf (stderr, "%s: warnings being treated as errors\n", program_name);
-      complaint_issued = true;
-    }
-  warning_issued = true;
-}
