@@ -33,6 +33,12 @@ named_ref_new (uniqstr id, location loc)
   return res;
 }
 
+named_ref *
+named_ref_copy (const named_ref *r)
+{
+  return named_ref_new (r->id, r->loc);
+}
+
 void
 named_ref_free (named_ref *r)
 {
