@@ -36,7 +36,6 @@ named_ref_new (uniqstr id, location loc)
 void
 named_ref_free (named_ref *r)
 {
-  if (r)
-    free (r);
+  free (r);
 }
 
