@@ -74,10 +74,11 @@ error_message (location *loc,
   vfprintf (stderr, message, args);
   {
     size_t l = strlen (message);
-    if (l < 2 || message[l-2] != ':' || message[l-1] != ' ') {
-      putc ('\n', stderr);
-      fflush (stderr);
-    }
+    if (l < 2 || message[l-2] != ':' || message[l-1] != ' ')
+      {
+        putc ('\n', stderr);
+        fflush (stderr);
+      }
   }
 }
 
