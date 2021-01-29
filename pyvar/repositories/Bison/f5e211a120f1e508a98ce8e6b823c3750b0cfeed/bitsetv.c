@@ -32,7 +32,7 @@ bitset *
 bitsetv_alloc (n_vecs, n_bits, type)
      bitset_bindex n_vecs;
      bitset_bindex n_bits;
-     enum bitset_type type;
+     enum_bitset_type type;
 {
   size_t vector_bytes;
   size_t bytes;
@@ -47,12 +47,13 @@ bitsetv_alloc (n_vecs, n_bits, type)
     xalloc_die ();
   
   /* Allocate vector table at head of bitset array.  */
-  vector_bytes = (n_vecs + 1) * sizeof (bitset);
+  vector_bytes = (n_vecs + 1) * sizeof (bitset) + bytes - 1;
+  vector_bytes -= vector_bytes % bytes;
   bsetv = (bitset *) xcalloc (1, vector_bytes + bytes * n_vecs);
   
   for (i = 0; i < n_vecs; i++)
     {
-      bsetv[i] = (bitset) ((char *) bsetv + vector_bytes + i * bytes);
+      bsetv[i] = (bitset) (void *) ((char *) bsetv + vector_bytes + i * bytes);
       
       bitset_init (bsetv[i], n_bits, type);
     }
@@ -94,7 +95,7 @@ bitsetv_free (bsetv)
 /* Zero a vector of bitsets.  */
 void
 bitsetv_zero (bsetv)
-     struct bitset_struct **bsetv;
+     bitsetv bsetv;
 {
   bitset_bindex i;
   
