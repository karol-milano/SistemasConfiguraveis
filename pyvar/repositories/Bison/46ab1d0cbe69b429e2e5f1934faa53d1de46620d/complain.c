@@ -477,10 +477,10 @@ static void
 complains (const location *loc, int *indent, warnings flags,
            const char *message, va_list args)
 {
-  severity s = warning_severity (flags);
   if ((flags & complaint) && complaint_status < status_complaint)
     complaint_status = status_complaint;
 
+  severity s = warning_severity (flags);
   if (severity_warning <= s)
     {
       if (severity_error <= s && ! complaint_status)
