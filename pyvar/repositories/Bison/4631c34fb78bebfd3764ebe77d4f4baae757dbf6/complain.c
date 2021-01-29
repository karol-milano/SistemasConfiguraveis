@@ -38,7 +38,10 @@ static unsigned *indent_ptr = 0;
  * \param loc     the location, defaulting to the current file,
  *                or the program name.
  * \param prefix  put before the message (e.g., "warning").
- * \param message the error message, a printf format string.
+ * \param message the error message, a printf format string.  Iff it
+ *                ends with ": ", then no trailing newline is printed,
+ *                and the caller should print the remaining
+ *                newline-terminated message to stderr.
  * \param args    the arguments of the format string.
  */
 static
@@ -68,8 +71,13 @@ error_message (location *loc,
     fprintf (stderr, "%s: ", prefix);
 
   vfprintf (stderr, message, args);
-  putc ('\n', stderr);
-  fflush (stderr);
+  {
+    size_t l = strlen (message);
+    if (l < 2 || message[l-2] != ':' || message[l-1] != ' ') {
+      putc ('\n', stderr);
+      fflush (stderr);
+    }
+  }
 }
 
 /** Wrap error_message() with varargs handling. */
