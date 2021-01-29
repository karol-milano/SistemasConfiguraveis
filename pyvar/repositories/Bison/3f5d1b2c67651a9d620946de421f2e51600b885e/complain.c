@@ -74,11 +74,15 @@ error_message (location *loc,
   vfprintf (stderr, message, args);
   {
     size_t l = strlen (message);
-    if (l < 2 || message[l-2] != ':' || message[l-1] != ' ') {
-      putc ('\n', stderr);
-      fflush (stderr);
-    }
+    if (l < 2 || message[l - 2] != ':' || message[l - 1] != ' ')
+      {
+        putc ('\n', stderr);
+        fflush (stderr);
+        if (loc && feature_flag & feature_caret)
+          location_caret (stderr, *loc);
+      }
   }
+  fflush (stderr);
 }
 
 /** Wrap error_message() with varargs handling. */
