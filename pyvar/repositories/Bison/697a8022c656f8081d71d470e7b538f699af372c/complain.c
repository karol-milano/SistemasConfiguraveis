@@ -34,7 +34,7 @@ warnings warnings_flag =
 
 warnings errors_flag;
 
-bool complaint_issued;
+err_status complaint_status = status_none;
 static unsigned *indent_ptr = 0;
 
 void
@@ -129,8 +129,11 @@ complains (const location *loc, warnings flags, const char *message,
     : flags & (errors_flag | complaint) ? _("error")
     : _("warning");
 
-  complaint_issued |= flags & (complaint | errors_flag);
-  if (flags & (warnings_flag | silent | fatal | complaint))
+  if ((flags & complaint) && complaint_status < status_complaint)
+    complaint_status = status_complaint;
+  else if ((flags & (warnings_flag & errors_flag)) && ! complaint_status)
+    complaint_status = status_warning_as_error;
+  if (flags & (warnings_flag | fatal | complaint))
     error_message (loc, flags, prefix, message, args);
   if (flags & fatal)
     exit (EXIT_FAILURE);
