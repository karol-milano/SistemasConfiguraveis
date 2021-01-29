@@ -116,6 +116,6 @@ derives_compute (void)
 void
 derives_free (void)
 {
-  XFREE (derives[0]);
-  XFREE (derives);
+  free (derives[0]);
+  free (derives);
 }
