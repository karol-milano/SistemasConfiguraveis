@@ -49,7 +49,7 @@ bitsetv_alloc (n_vecs, n_bits, type)
   for (i = 0; i < n_vecs; i++)
     {
       bsetv[i] = (bitset) ((char *) bsetv + vector_bytes + i * bytes);
-
+      
       bitset_init (bsetv[i], n_bits, type);
     }
   
