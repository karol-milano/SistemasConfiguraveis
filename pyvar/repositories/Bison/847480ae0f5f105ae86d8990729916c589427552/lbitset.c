@@ -936,17 +936,12 @@ lbitset_ones (bitset dst)
 static void
 lbitset_not (bitset dst, bitset src)
 {
-  lbitset_elt *elt;
   lbitset_elt *selt;
   lbitset_elt *delt;
   bitset_windex i;
   unsigned int j;
   bitset_windex windex;
 
-  /* This is another unfriendly operation for a linked list
-     bitset!  */
-  elt = LBITSET_TAIL (dst);
-
   windex = (BITSET_SIZE_ (dst) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS;
 
   for (i = 0; i < windex; i += LBITSET_ELT_WORDS)
