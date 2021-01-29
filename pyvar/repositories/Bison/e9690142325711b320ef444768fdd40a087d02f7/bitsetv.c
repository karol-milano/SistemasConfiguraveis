@@ -27,7 +27,7 @@
    type TYPE.  */
 bitset *
 bitsetv_alloc (bitset_bindex n_vecs, bitset_bindex n_bits,
-	       enum bitset_type type)
+               enum bitset_type type)
 {
   size_t vector_bytes;
   size_t bytes;
@@ -116,7 +116,7 @@ bitsetv_transitive_closure (bitsetv bsetv)
   for (i = 0; bsetv[i]; i++)
     for (j = 0; bsetv[j]; j++)
       if (bitset_test (bsetv[j], i))
-	bitset_or (bsetv[j], bsetv[j], bsetv[i]);
+        bitset_or (bsetv[j], bsetv[j], bsetv[i]);
 }
 
 
@@ -139,7 +139,7 @@ bitsetv_reflexive_transitive_closure (bitsetv bsetv)
    FILE.  */
 void
 bitsetv_dump (FILE *file, char const *title, char const *subtitle,
-	      bitsetv bsetv)
+              bitsetv bsetv)
 {
   bitset_windex i;
 
