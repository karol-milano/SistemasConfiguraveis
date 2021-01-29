@@ -68,7 +68,6 @@ error_message (location *loc,
     fprintf (stderr, "%s: ", prefix);
 
   vfprintf (stderr, message, args);
-  va_end (args);
   putc ('\n', stderr);
   fflush (stderr);
 }
@@ -79,6 +78,7 @@ error_message (location *loc,
   va_list args;					\
   va_start (args, Message);			\
   error_message (Loc, Prefix, Message, args);	\
+  va_end (args);				\
 }
 
 
