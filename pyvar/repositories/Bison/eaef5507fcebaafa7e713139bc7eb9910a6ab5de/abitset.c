@@ -31,16 +31,18 @@
 
 #define ABITSET_N_WORDS(N) (((N) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS)
 #define ABITSET_WORDS(X) ((X)->a.words)
-#define ABITSET_N_BITS(X) ((X)->a.n_bits)
 
 
-/* Return size in bits of bitset SRC.  */
 static bitset_bindex
-abitset_size (bitset src)
+abitset_resize (bitset src ATTRIBUTE_UNUSED,
+		bitset_bindex size ATTRIBUTE_UNUSED)
 {
-  return ABITSET_N_BITS (src);
-}
+    if (BITSET_SIZE_ (src) == size)
+	return size;
 
+    /* These bitsets have a fixed size.  */
+    abort ();
+}
 
 /* Find list of up to NUM bits set in BSET starting from and including
  *NEXT and store in array LIST.  Return with actual number of bits
@@ -60,7 +62,7 @@ abitset_small_list (bitset src, bitset_bindex *list,
   if (!word)
     return 0;
 
-  size = ABITSET_N_BITS (src);
+  size = BITSET_SIZE_ (src);
   bitno = *next;
   if (bitno >= size)
     return 0;
@@ -105,8 +107,9 @@ abitset_small_list (bitset src, bitset_bindex *list,
 static void
 abitset_set (bitset dst ATTRIBUTE_UNUSED, bitset_bindex bitno ATTRIBUTE_UNUSED)
 {
-  /* This should never occur for abitsets since we should always
-     hit the cache.  */
+  /* This should never occur for abitsets since we should always hit
+     the cache.  It is likely someone is trying to access outside the
+     bounds of the bitset.  */
   abort ();
 }
 
@@ -116,9 +119,9 @@ static void
 abitset_reset (bitset dst ATTRIBUTE_UNUSED,
 	       bitset_bindex bitno ATTRIBUTE_UNUSED)
 {
-  /* This should never occur for abitsets since we should always
-     hit the cache.  */
-  abort ();
+  /* This should never occur for abitsets since we should always hit
+     the cache.  It is likely someone is trying to access outside the
+     bounds of the bitset.  Since the bit is zero anyway, let it pass.  */
 }
 
 
@@ -129,7 +132,6 @@ abitset_test (bitset src ATTRIBUTE_UNUSED,
 {
   /* This should never occur for abitsets since we should always
      hit the cache.  */
-  abort ();
   return false;
 }
 
@@ -149,7 +151,7 @@ abitset_list_reverse (bitset src, bitset_bindex *list,
   unsigned int bitcnt;
   bitset_bindex bitoff;
   bitset_word *srcp = ABITSET_WORDS (src);
-  bitset_bindex n_bits = ABITSET_N_BITS (src);
+  bitset_bindex n_bits = BITSET_SIZE_ (src);
 
   rbitno = *next;
 
@@ -228,7 +230,7 @@ abitset_list (bitset src, bitset_bindex *list,
     }
   else
     {
-      if (bitno >= ABITSET_N_BITS (src))
+      if (bitno >= BITSET_SIZE_ (src))
 	return 0;
 
       windex = bitno / BITSET_WORD_BITS;
@@ -304,7 +306,7 @@ abitset_unused_clear (bitset dst)
 {
   unsigned int last_bit;
 
-  last_bit = ABITSET_N_BITS (dst) % BITSET_WORD_BITS;
+  last_bit = BITSET_SIZE_ (dst) % BITSET_WORD_BITS;
   if (last_bit)
     ABITSET_WORDS (dst)[dst->b.csize - 1] &=
       ((bitset_word) 1 << last_bit) - 1;
@@ -711,7 +713,8 @@ struct bitset_vtable abitset_small_vtable = {
   abitset_reset,
   bitset_toggle_,
   abitset_test,
-  abitset_size,
+  abitset_resize,
+  bitset_size_,
   bitset_count_,
   abitset_empty_p,
   abitset_ones,
@@ -748,7 +751,8 @@ struct bitset_vtable abitset_vtable = {
   abitset_reset,
   bitset_toggle_,
   abitset_test,
-  abitset_size,
+  abitset_resize,
+  bitset_size_,
   bitset_count_,
   abitset_empty_p,
   abitset_ones,
@@ -809,7 +813,7 @@ abitset_init (bitset bset, bitset_bindex n_bits)
   bitset_windex size;
 
   size = ABITSET_N_WORDS (n_bits);
-  ABITSET_N_BITS (bset) = n_bits;
+  BITSET_NBITS_ (bset) = n_bits;
 
   /* Use optimized routines if bitset fits within a single word.
      There is probably little merit if using caching since
