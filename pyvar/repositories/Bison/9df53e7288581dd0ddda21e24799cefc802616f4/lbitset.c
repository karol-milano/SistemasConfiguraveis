@@ -54,7 +54,7 @@ typedef bitset_word lbitset_word;
 
 /* Number of bits stored in each element.  */
 #define LBITSET_ELT_BITS \
-  ((unsigned int) (LBITSET_ELT_WORDS * LBITSET_WORD_BITS))
+  ((unsigned) (LBITSET_ELT_WORDS * LBITSET_WORD_BITS))
 
 /* Lbitset element.   We use an array of bits for each element.
    These are linked together in a doubly-linked list.  */
@@ -571,7 +571,7 @@ lbitset_list_reverse (bitset bset, bitset_bindex *list,
 {
   bitset_bindex rbitno;
   bitset_bindex bitno;
-  unsigned int bcount;
+  unsigned bcount;
   bitset_bindex boffset;
   bitset_windex windex;
   bitset_bindex count;
@@ -883,7 +883,7 @@ lbitset_empty_p (bitset dst)
 static inline void
 lbitset_unused_clear (bitset dst)
 {
-  unsigned int last_bit;
+  unsigned last_bit;
   bitset_bindex n_bits;
 
   n_bits = BITSET_SIZE_ (dst);
@@ -939,7 +939,7 @@ lbitset_not (bitset dst, bitset src)
   lbitset_elt *selt;
   lbitset_elt *delt;
   bitset_windex i;
-  unsigned int j;
+  unsigned j;
   bitset_windex windex;
 
   windex = (BITSET_SIZE_ (dst) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS;
@@ -966,7 +966,7 @@ lbitset_subset_p (bitset dst, bitset src)
 {
   lbitset_elt *selt;
   lbitset_elt *delt;
-  unsigned int j;
+  unsigned j;
 
   for (selt = LBITSET_HEAD (src), delt = LBITSET_HEAD (dst);
        selt || delt; selt = selt->next, delt = delt->next)
@@ -1003,7 +1003,7 @@ lbitset_disjoint_p (bitset dst, bitset src)
 {
   lbitset_elt *selt;
   lbitset_elt *delt;
-  unsigned int j;
+  unsigned j;
 
   for (selt = LBITSET_HEAD (src), delt = LBITSET_HEAD (dst);
        selt && delt; selt = selt->next, delt = delt->next)
@@ -1049,7 +1049,7 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
   bitset_word *srcp2;
   bitset_word *dstp;
   bool changed = false;
-  unsigned int i;
+  unsigned i;
 
   LBITSET_HEAD (dst) = 0;
   dst->b.csize = 0;
@@ -1376,17 +1376,17 @@ void
 debug_lbitset (bitset bset)
 {
   lbitset_elt *elt;
-  unsigned int i;
+  unsigned i;
 
   if (!bset)
     return;
 
   for (elt = LBITSET_HEAD (bset); elt; elt = elt->next)
     {
-      fprintf (stderr, "Elt %lu\n", (unsigned long int) elt->index);
+      fprintf (stderr, "Elt %lu\n", (unsigned long) elt->index);
       for (i = 0; i < LBITSET_ELT_WORDS; i++)
         {
-          unsigned int j;
+          unsigned j;
           bitset_word word;
 
           word = elt->words[i];
