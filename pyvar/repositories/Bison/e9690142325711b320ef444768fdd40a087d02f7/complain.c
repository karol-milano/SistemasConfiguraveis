@@ -47,8 +47,8 @@ static unsigned *indent_ptr = 0;
 static
 void
 error_message (location *loc,
-	       const char *prefix,
-	       const char *message, va_list args)
+               const char *prefix,
+               const char *message, va_list args)
 {
   unsigned pos = 0;
 
@@ -81,12 +81,12 @@ error_message (location *loc,
 }
 
 /** Wrap error_message() with varargs handling. */
-#define ERROR_MESSAGE(Loc, Prefix, Message)	\
-{						\
-  va_list args;					\
-  va_start (args, Message);			\
-  error_message (Loc, Prefix, Message, args);	\
-  va_end (args);				\
+#define ERROR_MESSAGE(Loc, Prefix, Message)     \
+{                                               \
+  va_list args;                                 \
+  va_start (args, Message);                     \
+  error_message (Loc, Prefix, Message, args);   \
+  va_end (args);                                \
 }
 
 
