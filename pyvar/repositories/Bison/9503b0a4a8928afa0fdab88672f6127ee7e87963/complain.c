@@ -32,6 +32,8 @@
 warnings warnings_flag =
   Wconflicts_sr | Wconflicts_rr | Wdeprecated  | Wother;
 
+warnings errors_flag;
+
 bool complaint_issued;
 static unsigned *indent_ptr = 0;
 
@@ -141,7 +143,7 @@ complains (const location *loc, warnings flags, const char *message,
         }
       else if (warnings_flag & Wyacc)
         {
-          set_warning_issued ();
+          set_warning_issued (Wyacc);
           error_message (loc, flags,
                          indent_ptr && *indent_ptr ? NULL : _("warning"),
                          message, args);
@@ -149,7 +151,7 @@ complains (const location *loc, warnings flags, const char *message,
     }
   else if (warnings_flag & flags)
     {
-      set_warning_issued ();
+      set_warning_issued (flags);
       error_message (loc, flags,
                      indent_ptr && *indent_ptr ? NULL : _("warning"),
                      message, args);
@@ -191,10 +193,10 @@ void complain_at_indent (location loc, warnings flags, unsigned *indent,
 `--------------------------------*/
 
 void
-set_warning_issued (void)
+set_warning_issued (warnings warning)
 {
   static bool warning_issued = false;
-  if (!warning_issued && (warnings_flag & Werror))
+  if (!warning_issued && (warning & warnings_flag & errors_flag))
     {
       fprintf (stderr, "%s: warnings being treated as errors\n", program_name);
       complaint_issued = true;
