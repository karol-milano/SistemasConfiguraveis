@@ -84,7 +84,6 @@ void
 error_message (const location *loc, warnings flags, const char *prefix,
                const char *message, va_list args)
 {
-  (void) flags;
   unsigned pos = 0;
 
   if (loc)
@@ -95,6 +94,8 @@ error_message (const location *loc, warnings flags, const char *prefix,
 
   if (indent_ptr)
     {
+      if (*indent_ptr)
+        prefix = NULL;
       if (!*indent_ptr)
         *indent_ptr = pos;
       else if (*indent_ptr > pos)
@@ -125,21 +126,16 @@ complains (const location *loc, warnings flags, const char *message,
            va_list args)
 
 {
+  const char* prefix =
+    flags & fatal ? _("fatal error")
+    : flags & (errors_flag | complaint) ? _("error")
+    : _("warning");
+
+  complaint_issued |= flags & (complaint | errors_flag);
+  if (flags & (warnings_flag | silent | fatal | complaint))
+    error_message (loc, flags, prefix, message, args);
   if (flags & fatal)
-    {
-       error_message (loc, fatal, _("fatal error"), message, args);
-       exit (EXIT_FAILURE);
-    }
-  else if (flags & (complaint | warnings_flag | silent))
-    {
-      const char* prefix =
-        flags & (errors_flag | complaint) ? _("error") : _("warning");
-      if (flags & (complaint | errors_flag))
-        complaint_issued = true;
-      error_message (loc, flags,
-                     indent_ptr && *indent_ptr ? NULL : prefix,
-                     message, args);
-    }
+    exit (EXIT_FAILURE);
 }
 
 void
