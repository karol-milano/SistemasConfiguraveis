@@ -116,6 +116,6 @@ derives_compute (void)
 void
 derives_free (void)
 {
-  free (derives[0]);
-  free (derives);
+  XFREE (derives[0]);
+  XFREE (derives);
 }
