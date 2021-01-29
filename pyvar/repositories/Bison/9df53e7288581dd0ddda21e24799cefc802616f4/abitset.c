@@ -146,7 +146,7 @@ abitset_list_reverse (bitset src, bitset_bindex *list,
   bitset_bindex rbitno;
   bitset_bindex count;
   bitset_windex windex;
-  unsigned int bitcnt;
+  unsigned bitcnt;
   bitset_bindex bitoff;
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_bindex n_bits = BITSET_SIZE_ (src);
@@ -302,7 +302,7 @@ abitset_list (bitset src, bitset_bindex *list,
 static inline void
 abitset_unused_clear (bitset dst)
 {
-  unsigned int last_bit;
+  unsigned last_bit;
 
   last_bit = BITSET_SIZE_ (dst) % BITSET_WORD_BITS;
   if (last_bit)
