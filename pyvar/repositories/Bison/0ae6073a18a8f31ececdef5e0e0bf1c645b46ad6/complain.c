@@ -83,11 +83,11 @@ private_strerror (int errnum)
 # endif /* HAVE_STRERROR */
 #endif	/* not _LIBC */
 
-/* This variable is incremented each time `warn' is called.  */
-unsigned int warn_message_count;
+/* This variable is set each time `warn' is called.  */
+bool warning_issued;
 
-/* This variable is incremented each time `complain' is called.  */
-unsigned int complain_message_count;
+/* This variable is set each time `complain' is called.  */
+bool complaint_issued;
 
 
 /*--------------------------------.
@@ -108,7 +108,7 @@ warn_at (location_t location, const char *message, ...)
   vfprintf (stderr, message, args);
   va_end (args);
 
-  ++warn_message_count;
+  warning_issued = true;
   putc ('\n', stderr);
   fflush (stderr);
 }
@@ -125,7 +125,7 @@ warn (const char *message, ...)
   vfprintf (stderr, message, args);
   va_end (args);
 
-  ++warn_message_count;
+  warning_issued = true;
   putc ('\n', stderr);
   fflush (stderr);
 }
@@ -147,7 +147,7 @@ complain_at (location_t location, const char *message, ...)
   vfprintf (stderr, message, args);
   va_end (args);
 
-  ++complain_message_count;
+  complaint_issued = true;
   putc ('\n', stderr);
   fflush (stderr);
 }
@@ -164,7 +164,7 @@ complain (const char *message, ...)
   vfprintf (stderr, message, args);
   va_end (args);
 
-  ++complain_message_count;
+  complaint_issued = true;
   putc ('\n', stderr);
   fflush (stderr);
 }
@@ -188,7 +188,7 @@ fatal_at (location_t location, const char *message, ...)
   va_end (args);
   putc ('\n', stderr);
   fflush (stderr);
-  exit (1);
+  exit (EXIT_FAILURE);
 }
 
 void
@@ -206,5 +206,5 @@ fatal (const char *message, ...)
   va_end (args);
   putc ('\n', stderr);
   fflush (stderr);
-  exit (1);
+  exit (EXIT_FAILURE);
 }
