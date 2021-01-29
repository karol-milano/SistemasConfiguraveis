@@ -66,7 +66,6 @@ lbitset_elt;
 
 enum lbitset_find_mode
   { LBITSET_FIND, LBITSET_CREATE, LBITSET_SUBST };
-typedef int enum_lbitset_find_mode;
 
 static lbitset_elt lbitset_zero_elts[3]; /* Elements of all zero bits.  */
 
@@ -75,44 +74,6 @@ static struct obstack lbitset_obstack;
 static int lbitset_obstack_init = 0;
 static lbitset_elt *lbitset_free_list;	/* Free list of bitset elements.  */
 
-static lbitset_elt *lbitset_elt_alloc PARAMS ((void));
-static lbitset_elt *lbitset_elt_calloc PARAMS ((void));
-static void lbitset_elt_link PARAMS ((bitset, lbitset_elt *));
-static void lbitset_elt_unlink PARAMS ((bitset, lbitset_elt *));
-static void lbitset_elt_free PARAMS ((lbitset_elt *));
-static lbitset_elt *lbitset_elt_find PARAMS ((bitset, bitset_windex,
-					      enum_lbitset_find_mode));
-static int lbitset_elt_zero_p PARAMS ((lbitset_elt *));
-
-static void lbitset_prune PARAMS ((bitset, lbitset_elt *));
-static void lbitset_weed PARAMS ((bitset));
-static void lbitset_zero PARAMS ((bitset));
-static int lbitset_equal_p PARAMS ((bitset, bitset));
-static void lbitset_copy PARAMS ((bitset, bitset));
-static int lbitset_copy_cmp PARAMS ((bitset, bitset));
-static void lbitset_set PARAMS ((bitset, bitset_bindex));
-static void lbitset_reset PARAMS ((bitset, bitset_bindex));
-static int lbitset_test PARAMS ((bitset, bitset_bindex));
-static bitset_bindex lbitset_size PARAMS ((bitset));
-static int lbitset_op3_cmp PARAMS ((bitset, bitset, bitset, enum_bitset_ops));
-static void lbitset_and PARAMS ((bitset, bitset, bitset));
-static int lbitset_and_cmp PARAMS ((bitset, bitset, bitset));
-static void lbitset_andn PARAMS ((bitset, bitset, bitset));
-static int lbitset_andn_cmp PARAMS ((bitset, bitset, bitset));
-static void lbitset_or PARAMS ((bitset, bitset, bitset));
-static int lbitset_or_cmp PARAMS ((bitset, bitset, bitset));
-static void lbitset_xor PARAMS ((bitset, bitset, bitset));
-static int lbitset_xor_cmp PARAMS ((bitset, bitset, bitset));
-static bitset_bindex lbitset_list PARAMS ((bitset, bitset_bindex *,
-					   bitset_bindex, bitset_bindex *));
-static bitset_bindex lbitset_list_reverse
-PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
-static int lbitset_empty_p PARAMS ((bitset));
-static void lbitset_ones PARAMS ((bitset));
-static void lbitset_not PARAMS ((bitset, bitset));
-static int lbitset_subset_p PARAMS ((bitset, bitset));
-static int lbitset_disjoint_p PARAMS ((bitset, bitset));
-static void lbitset_free PARAMS ((bitset));
 extern void debug_lbitset PARAMS ((bitset));
 
 #define LBITSET_CURRENT1(X) \
@@ -125,7 +86,7 @@ extern void debug_lbitset PARAMS ((bitset));
 
 /* Allocate a lbitset element.  The bits are not cleared.  */
 static inline lbitset_elt *
-lbitset_elt_alloc ()
+lbitset_elt_alloc (void)
 {
   lbitset_elt *elt;
 
@@ -180,7 +141,7 @@ lbitset_elt_alloc ()
 
 /* Allocate a lbitset element.  The bits are cleared.  */
 static inline lbitset_elt *
-lbitset_elt_calloc ()
+lbitset_elt_calloc (void)
 {
   lbitset_elt *elt;
 
@@ -191,8 +152,7 @@ lbitset_elt_calloc ()
 
 
 static inline void
-lbitset_elt_free (elt)
-     lbitset_elt *elt;
+lbitset_elt_free (lbitset_elt *elt)
 {
   elt->next = lbitset_free_list;
   lbitset_free_list = elt;
@@ -201,9 +161,7 @@ lbitset_elt_free (elt)
 
 /* Unlink element ELT from bitset BSET.  */
 static inline void
-lbitset_elt_unlink (bset, elt)
-     bitset bset;
-     lbitset_elt *elt;
+lbitset_elt_unlink (bitset bset, lbitset_elt *elt)
 {
   lbitset_elt *next = elt->next;
   lbitset_elt *prev = elt->prev;
@@ -248,9 +206,7 @@ lbitset_elt_unlink (bset, elt)
 /* Cut the chain of bitset BSET before element ELT and free the
    elements.  */
 static inline void
-lbitset_prune (bset, elt)
-     bitset bset;
-     lbitset_elt *elt;
+lbitset_prune (bitset bset, lbitset_elt *elt)
 {
   lbitset_elt *next;
 
@@ -282,8 +238,7 @@ lbitset_prune (bset, elt)
 
 /* Return nonzero if all bits in an element are zero.  */
 static inline int
-lbitset_elt_zero_p (elt)
-     lbitset_elt *elt;
+lbitset_elt_zero_p (lbitset_elt *elt)
 {
   int i;
 
@@ -297,9 +252,7 @@ lbitset_elt_zero_p (elt)
 
 /* Link the bitset element into the current bitset linked list.  */
 static inline void
-lbitset_elt_link (bset, elt)
-     bitset bset;
-     lbitset_elt *elt;
+lbitset_elt_link (bitset bset, lbitset_elt *elt)
 {
   bitset_windex windex = elt->index;
   lbitset_elt *ptr;
@@ -361,10 +314,8 @@ lbitset_elt_link (bset, elt)
 
 
 static lbitset_elt *
-lbitset_elt_find (bset, windex, mode)
-     bitset bset;
-     bitset_windex windex;
-     enum_lbitset_find_mode mode;
+lbitset_elt_find (bitset bset, bitset_windex windex,
+		  enum lbitset_find_mode mode)
 {
   lbitset_elt *elt;
   lbitset_elt *current;
@@ -432,8 +383,7 @@ lbitset_elt_find (bset, windex, mode)
 
 /* Weed out the zero elements from the list.  */
 static inline void
-lbitset_weed (bset)
-     bitset bset;
+lbitset_weed (bitset bset)
 {
   lbitset_elt *elt;
   lbitset_elt *next;
@@ -449,8 +399,7 @@ lbitset_weed (bset)
 
 /* Set all bits in the bitset to zero.  */
 static void
-lbitset_zero (bset)
-     bitset bset;
+lbitset_zero (bitset bset)
 {
   lbitset_elt *head;
 
@@ -465,9 +414,7 @@ lbitset_zero (bset)
 
 /* Return 1 if DST == SRC.  */
 static inline int
-lbitset_equal_p (dst, src)
-     bitset dst;
-     bitset src;
+lbitset_equal_p (bitset dst, bitset src)
 {
   lbitset_elt *selt;
   lbitset_elt *delt;
@@ -494,9 +441,7 @@ lbitset_equal_p (dst, src)
 
 /* Copy bits from bitset SRC to bitset DST.  */
 static inline void
-lbitset_copy (dst, src)
-     bitset dst;
-     bitset src;
+lbitset_copy (bitset dst, bitset src)
 {
   lbitset_elt *elt;
   lbitset_elt *head;
@@ -538,9 +483,7 @@ lbitset_copy (dst, src)
 /* Copy bits from bitset SRC to bitset DST.  Return non-zero if
    bitsets different.  */
 static inline int
-lbitset_copy_cmp (dst, src)
-     bitset dst;
-     bitset src;
+lbitset_copy_cmp (bitset dst, bitset src)
 {
   if (src == dst)
     return 0;
@@ -561,8 +504,7 @@ lbitset_copy_cmp (dst, src)
 
 /* Return size in bits of bitset SRC.  */
 static bitset_bindex
-lbitset_size (src)
-     bitset src;
+lbitset_size (bitset src)
 {
   lbitset_elt *elt;
 
@@ -577,9 +519,7 @@ lbitset_size (src)
 
 /* Set bit BITNO in bitset DST.  */
 static void
-lbitset_set (dst, bitno)
-     bitset dst;
-     bitset_bindex bitno;
+lbitset_set (bitset dst, bitset_bindex bitno)
 {
   bitset_windex windex = bitno / BITSET_WORD_BITS;
 
@@ -592,9 +532,7 @@ lbitset_set (dst, bitno)
 
 /* Reset bit BITNO in bitset DST.  */
 static void
-lbitset_reset (dst, bitno)
-     bitset dst;
-     bitset_bindex bitno;
+lbitset_reset (bitset dst, bitset_bindex bitno)
 {
   bitset_windex windex = bitno / BITSET_WORD_BITS;
 
@@ -610,23 +548,20 @@ lbitset_reset (dst, bitno)
 
 /* Test bit BITNO in bitset SRC.  */
 static int
-lbitset_test (src, bitno)
-     bitset src;
-     bitset_bindex bitno;
+lbitset_test (bitset src, bitset_bindex bitno)
 {
   bitset_windex windex = bitno / BITSET_WORD_BITS;
 
   if (!lbitset_elt_find (src, windex, LBITSET_FIND))
     return 0;
 
-  return (src->b.cdata[windex - src->b.cindex] 
+  return (src->b.cdata[windex - src->b.cindex]
 	  >> (bitno % BITSET_WORD_BITS)) & 1;
 }
 
 
 static void
-lbitset_free (bset)
-     bitset bset;
+lbitset_free (bitset bset)
 {
   lbitset_zero (bset);
 }
@@ -636,11 +571,8 @@ lbitset_free (bset)
  *NEXT and store in array LIST.  Return with actual number of bits
  found and with *NEXT indicating where search stopped.  */
 static bitset_bindex
-lbitset_list_reverse (bset, list, num, next)
-     bitset bset;
-     bitset_bindex *list;
-     bitset_bindex num;
-     bitset_bindex *next;
+lbitset_list_reverse (bitset bset, bitset_bindex *list,
+		      bitset_bindex num, bitset_bindex *next)
 {
   bitset_bindex rbitno;
   bitset_bindex bitno;
@@ -734,11 +666,8 @@ lbitset_list_reverse (bset, list, num, next)
  *NEXT and store in array LIST.  Return with actual number of bits
  found and with *NEXT indicating where search stopped.  */
 static bitset_bindex
-lbitset_list (bset, list, num, next)
-     bitset bset;
-     bitset_bindex *list;
-     bitset_bindex num;
-     bitset_bindex *next;
+lbitset_list (bitset bset, bitset_bindex *list,
+	      bitset_bindex num, bitset_bindex *next)
 {
   bitset_bindex bitno;
   bitset_windex windex;
@@ -937,8 +866,7 @@ lbitset_list (bset, list, num, next)
 
 
 static int
-lbitset_empty_p (dst)
-     bitset dst;
+lbitset_empty_p (bitset dst)
 {
   lbitset_weed (dst);
   if (LBITSET_HEAD (dst))
@@ -948,8 +876,7 @@ lbitset_empty_p (dst)
 
 
 static void
-lbitset_ones (dst)
-     bitset dst;
+lbitset_ones (bitset dst)
 {
   bitset_windex i;
   bitset_windex windex;
@@ -963,7 +890,7 @@ lbitset_ones (dst)
   /* Ignore empty set.  */
   if (!elt)
     return;
-  
+
   windex = elt->index;
   for (i = 0; i < windex; i += LBITSET_ELT_WORDS)
     {
@@ -975,9 +902,7 @@ lbitset_ones (dst)
 
 
 static void
-lbitset_not (dst, src)
-     bitset dst;
-     bitset src;
+lbitset_not (bitset dst, bitset src)
 {
   lbitset_elt *elt;
   lbitset_elt *selt;
@@ -992,7 +917,7 @@ lbitset_not (dst, src)
   /* Ignore empty set.  */
   if (!elt)
     return;
-  
+
   windex = elt->index;
   for (i = 0; i < windex; i += LBITSET_ELT_WORDS)
     {
@@ -1000,7 +925,7 @@ lbitset_not (dst, src)
 	 or substitute zero elements if src elements not found.  */
       selt = lbitset_elt_find (src, i, LBITSET_SUBST);
       delt = lbitset_elt_find (dst, i, LBITSET_CREATE);
-      
+
       for (j = 0; j < LBITSET_ELT_WORDS; j++)
 	delt->words[j] = ~selt->words[j];
     }
@@ -1011,9 +936,7 @@ lbitset_not (dst, src)
 
 /* Return 1 if DST == DST | SRC.  */
 static int
-lbitset_subset_p (dst, src)
-     bitset dst;
-     bitset src;
+lbitset_subset_p (bitset dst, bitset src)
 {
   lbitset_elt *selt;
   lbitset_elt *delt;
@@ -1039,7 +962,7 @@ lbitset_subset_p (dst, src)
 	      selt = &lbitset_zero_elts[1];
 	    }
 	}
-      
+
       for (j = 0; j < LBITSET_ELT_WORDS; j++)
 	if (delt->words[j] != (selt->words[j] | delt->words[j]))
 	  return 0;
@@ -1050,9 +973,7 @@ lbitset_subset_p (dst, src)
 
 /* Return 1 if DST & SRC == 0.  */
 static int
-lbitset_disjoint_p (dst, src)
-     bitset dst;
-     bitset src;
+lbitset_disjoint_p (bitset dst, bitset src)
 {
   lbitset_elt *selt;
   lbitset_elt *delt;
@@ -1077,7 +998,7 @@ lbitset_disjoint_p (dst, src)
 	     intersection of these elements.  */
 	  continue;
 	}
-      
+
       for (j = 0; j < LBITSET_ELT_WORDS; j++)
 	if (selt->words[j] & delt->words[j])
 	  return 0;
@@ -1087,11 +1008,7 @@ lbitset_disjoint_p (dst, src)
 
 
 static int
-lbitset_op3_cmp (dst, src1, src2, op)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     enum_bitset_ops op;
+lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 {
   lbitset_elt *selt1 = LBITSET_HEAD (src1);
   lbitset_elt *selt2 = LBITSET_HEAD (src2);
@@ -1248,21 +1165,8 @@ lbitset_op3_cmp (dst, src1, src2, op)
 }
 
 
-static void
-lbitset_and (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-{
-  lbitset_and_cmp (dst, src1, src2);
-}
-
-
 static int
-lbitset_and_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+lbitset_and_cmp (bitset dst, bitset src1, bitset src2)
 {
   lbitset_elt *selt1 = LBITSET_HEAD (src1);
   lbitset_elt *selt2 = LBITSET_HEAD (src2);
@@ -1287,20 +1191,14 @@ lbitset_and_cmp (dst, src1, src2)
 
 
 static void
-lbitset_andn (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+lbitset_and (bitset dst, bitset src1, bitset src2)
 {
-  lbitset_andn_cmp (dst, src1, src2);
+  lbitset_and_cmp (dst, src1, src2);
 }
 
 
 static int
-lbitset_andn_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+lbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 {
   lbitset_elt *selt1 = LBITSET_HEAD (src1);
   lbitset_elt *selt2 = LBITSET_HEAD (src2);
@@ -1322,20 +1220,14 @@ lbitset_andn_cmp (dst, src1, src2)
 
 
 static void
-lbitset_or (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+lbitset_andn (bitset dst, bitset src1, bitset src2)
 {
-  lbitset_or_cmp (dst, src1, src2);
+  lbitset_andn_cmp (dst, src1, src2);
 }
 
 
 static int
-lbitset_or_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+lbitset_or_cmp (bitset dst, bitset src1, bitset src2)
 {
   lbitset_elt *selt1 = LBITSET_HEAD (src1);
   lbitset_elt *selt2 = LBITSET_HEAD (src2);
@@ -1353,20 +1245,14 @@ lbitset_or_cmp (dst, src1, src2)
 
 
 static void
-lbitset_xor (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+lbitset_or (bitset dst, bitset src1, bitset src2)
 {
-  lbitset_xor_cmp (dst, src1, src2);
+  lbitset_or_cmp (dst, src1, src2);
 }
 
 
 static int
-lbitset_xor_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+lbitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 {
   lbitset_elt *selt1 = LBITSET_HEAD (src1);
   lbitset_elt *selt2 = LBITSET_HEAD (src2);
@@ -1383,6 +1269,13 @@ lbitset_xor_cmp (dst, src1, src2)
 }
 
 
+static void
+lbitset_xor (bitset dst, bitset src1, bitset src2)
+{
+  lbitset_xor_cmp (dst, src1, src2);
+}
+
+
 
 /* Vector of operations for linked-list bitsets.  */
 struct bitset_vtable lbitset_vtable = {
@@ -1423,8 +1316,7 @@ struct bitset_vtable lbitset_vtable = {
 
 /* Return size of initial structure.  */
 size_t
-lbitset_bytes (n_bits)
-     bitset_bindex n_bits ATTRIBUTE_UNUSED;
+lbitset_bytes (bitset_bindex n_bits ATTRIBUTE_UNUSED)
 {
   return sizeof (struct lbitset_struct);
 }
@@ -1432,9 +1324,7 @@ lbitset_bytes (n_bits)
 
 /* Initialize a bitset.  */
 bitset
-lbitset_init (bset, n_bits)
-     bitset bset;
-     bitset_bindex n_bits ATTRIBUTE_UNUSED;
+lbitset_init (bitset bset, bitset_bindex n_bits ATTRIBUTE_UNUSED)
 {
   bset->b.vtable = &lbitset_vtable;
   return bset;
@@ -1442,7 +1332,7 @@ lbitset_init (bset, n_bits)
 
 
 void
-lbitset_release_memory ()
+lbitset_release_memory (void)
 {
   lbitset_free_list = 0;
   if (lbitset_obstack_init)
@@ -1455,15 +1345,14 @@ lbitset_release_memory ()
 
 /* Function to be called from debugger to debug lbitset.  */
 void
-debug_lbitset (bset)
-     bitset bset;
+debug_lbitset (bitset bset)
 {
   lbitset_elt *elt;
   unsigned int i;
 
   if (!bset)
     return;
-  
+
   for (elt = LBITSET_HEAD (bset); elt; elt = elt->next)
     {
       fprintf (stderr, "Elt %lu\n", (unsigned long) elt->index);
@@ -1471,9 +1360,9 @@ debug_lbitset (bset)
 	{
 	  unsigned int j;
 	  bitset_word word;
-	  
+
 	  word = elt->words[i];
-	  
+
 	  fprintf (stderr, "  Word %u:", i);
 	  for (j = 0; j < LBITSET_WORD_BITS; j++)
 	    if ((word & ((bitset_word) 1 << j)))
