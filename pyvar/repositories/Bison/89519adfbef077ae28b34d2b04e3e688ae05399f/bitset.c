@@ -138,7 +138,7 @@ bitset_alloc (bitset_bindex n_bits, enum bitset_type type)
 
   bytes = bitset_bytes (type, n_bits);
 
-  bset = (bitset) xcalloc (1, bytes);
+  bset = xcalloc (1, bytes);
 
   /* The cache is disabled until some elements are allocated.  If we
      have variable length arrays, then we may need to allocate a dummy
