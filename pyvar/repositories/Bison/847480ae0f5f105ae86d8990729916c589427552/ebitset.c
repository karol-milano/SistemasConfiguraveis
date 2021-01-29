@@ -1335,17 +1335,12 @@ ebitset_bytes (bitset_bindex n_bits ATTRIBUTE_UNUSED)
 bitset
 ebitset_init (bitset bset, bitset_bindex n_bits)
 {
-  bitset_windex size;
-
   bset->b.vtable = &ebitset_vtable;
 
   bset->b.csize = EBITSET_ELT_WORDS;
 
   EBITSET_ZERO_SET (bset);
 
-  size = n_bits ? (n_bits + EBITSET_ELT_BITS - 1) / EBITSET_ELT_BITS
-    : EBITSET_INITIAL_SIZE;
-
   EBITSET_ASIZE (bset) = 0;
   EBITSET_ELTS (bset) = 0;
   ebitset_resize (bset, n_bits);
