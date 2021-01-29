@@ -143,29 +143,20 @@ complains (const location *loc, warnings flags, const char *message,
 }
 
 void
-complain (warnings flags, const char *message, ...)
+complain (location const* loc, warnings flags, const char *message, ...)
 {
   va_list args;
   va_start (args, message);
-  complains (NULL, flags, message, args);
+  complains (loc, flags, message, args);
   va_end (args);
 }
 
 void
-complain_at (location loc, warnings flags, const char *message, ...)
+complain_at_indent (location loc, warnings flags, unsigned *indent,
+                    const char *message, ...)
 {
   va_list args;
-  va_start (args, message);
-  complains (&loc, flags, message, args);
-  va_end (args);
-}
-
-void complain_at_indent (location loc, warnings flags, unsigned *indent,
-                         const char *message, ...)
-{
   indent_ptr = indent;
-
-  va_list args;
   va_start (args, message);
   complains (&loc, flags, message, args);
   va_end (args);
