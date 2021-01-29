@@ -36,6 +36,7 @@ named_ref_new (uniqstr id, location loc)
 void
 named_ref_free (named_ref *r)
 {
-  free (r);
+  if (r)
+    free (r);
 }
 
