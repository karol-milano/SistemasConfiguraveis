@@ -139,7 +139,7 @@ complains (const location *loc, warnings flags, const char *message,
 }
 
 void
-complain (location const* loc, warnings flags, const char *message, ...)
+complain (location const *loc, warnings flags, const char *message, ...)
 {
   va_list args;
   va_start (args, message);
@@ -148,13 +148,13 @@ complain (location const* loc, warnings flags, const char *message, ...)
 }
 
 void
-complain_at_indent (location loc, warnings flags, unsigned *indent,
-                    const char *message, ...)
+complain_indent (location const *loc, warnings flags, unsigned *indent,
+                 const char *message, ...)
 {
   va_list args;
   indent_ptr = indent;
   va_start (args, message);
-  complains (&loc, flags, message, args);
+  complains (loc, flags, message, args);
   va_end (args);
 }
 
