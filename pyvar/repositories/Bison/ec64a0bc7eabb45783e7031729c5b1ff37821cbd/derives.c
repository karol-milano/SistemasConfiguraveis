@@ -109,6 +109,9 @@ derives_compute (void)
 void
 derives_free (void)
 {
-  free (derives[0]);
-  free (derives);
+  if (derives)
+    {
+      free (derives[0]);
+      free (derives);
+    }
 }
