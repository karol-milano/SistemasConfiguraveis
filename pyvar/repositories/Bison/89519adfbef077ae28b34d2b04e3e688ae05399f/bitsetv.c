@@ -47,7 +47,7 @@ bitsetv_alloc (bitset_bindex n_vecs, bitset_bindex n_bits,
   /* Allocate vector table at head of bitset array.  */
   vector_bytes = (n_vecs + 1) * sizeof (bitset) + bytes - 1;
   vector_bytes -= vector_bytes % bytes;
-  bsetv = (bitset *) xcalloc (1, vector_bytes + bytes * n_vecs);
+  bsetv = xcalloc (1, vector_bytes + bytes * n_vecs);
 
   for (i = 0; i < n_vecs; i++)
     {
