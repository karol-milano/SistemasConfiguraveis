@@ -145,9 +145,7 @@ lbitset_elt_alloc (void)
 static inline lbitset_elt *
 lbitset_elt_calloc (void)
 {
-  lbitset_elt *elt;
-
-  elt = lbitset_elt_alloc ();
+  lbitset_elt *elt = lbitset_elt_alloc ();
   memset (elt->words, 0, sizeof (elt->words));
   return elt;
 }
@@ -210,8 +208,6 @@ lbitset_elt_unlink (bitset bset, lbitset_elt *elt)
 static inline void
 lbitset_prune (bitset bset, lbitset_elt *elt)
 {
-  lbitset_elt *next;
-
   if (!elt)
     return;
 
@@ -230,6 +226,7 @@ lbitset_prune (bitset bset, lbitset_elt *elt)
       bset->b.csize = 0;
     }
 
+  lbitset_elt *next;
   for (; elt; elt = next)
     {
       next = elt->next;
@@ -242,9 +239,7 @@ lbitset_prune (bitset bset, lbitset_elt *elt)
 static inline bool
 lbitset_elt_zero_p (lbitset_elt *elt)
 {
-  int i;
-
-  for (i = 0; i < LBITSET_ELT_WORDS; i++)
+  for (int i = 0; i < LBITSET_ELT_WORDS; i++)
     if (elt->words[i])
       return false;
 
@@ -257,9 +252,8 @@ static inline void
 lbitset_elt_link (bitset bset, lbitset_elt *elt)
 {
   bitset_windex windex = elt->index;
-  lbitset_elt *ptr;
-  lbitset_elt *current;
 
+  lbitset_elt *current;
   if (bset->b.csize)
     current = LBITSET_CURRENT (bset);
   else
@@ -277,6 +271,7 @@ lbitset_elt_link (bitset bset, lbitset_elt *elt)
      somewhere before the current element.  */
   else if (windex < bset->b.cindex)
     {
+      lbitset_elt *ptr;
       for (ptr = current;
            ptr->prev && ptr->prev->index > windex; ptr = ptr->prev)
         continue;
@@ -294,6 +289,7 @@ lbitset_elt_link (bitset bset, lbitset_elt *elt)
   /* Otherwise, it must go somewhere after the current element.  */
   else
     {
+      lbitset_elt *ptr;
       for (ptr = current;
            ptr->next && ptr->next->index < windex; ptr = ptr->next)
         continue;
@@ -319,7 +315,6 @@ static lbitset_elt *
 lbitset_elt_find (bitset bset, bitset_windex windex,
                   enum lbitset_find_mode mode)
 {
-  lbitset_elt *elt;
   lbitset_elt *current;
 
   if (bset->b.csize)
@@ -336,6 +331,7 @@ lbitset_elt_find (bitset bset, bitset_windex windex,
 
   if (current)
     {
+      lbitset_elt *elt;
       if (windex < bset->b.cindex)
         {
           for (elt = current;
@@ -371,8 +367,7 @@ lbitset_elt_find (bitset bset, bitset_windex windex,
 
     case LBITSET_CREATE:
       windex -= windex % LBITSET_ELT_WORDS;
-
-      elt = lbitset_elt_calloc ();
+      lbitset_elt *elt = lbitset_elt_calloc ();
       elt->index = windex;
       lbitset_elt_link (bset, elt);
       return elt;
@@ -387,10 +382,8 @@ lbitset_elt_find (bitset bset, bitset_windex windex,
 static inline void
 lbitset_weed (bitset bset)
 {
-  lbitset_elt *elt;
   lbitset_elt *next;
-
-  for (elt = LBITSET_HEAD (bset); elt; elt = next)
+  for (lbitset_elt *elt = LBITSET_HEAD (bset); elt; elt = next)
     {
       next = elt->next;
       if (lbitset_elt_zero_p (elt))
@@ -403,9 +396,7 @@ lbitset_weed (bitset bset)
 static void
 lbitset_zero (bitset bset)
 {
-  lbitset_elt *head;
-
-  head = LBITSET_HEAD (bset);
+  lbitset_elt *head = LBITSET_HEAD (bset);
   if (!head)
     return;
 
@@ -418,22 +409,20 @@ lbitset_zero (bitset bset)
 static inline bool
 lbitset_equal_p (bitset dst, bitset src)
 {
-  lbitset_elt *selt;
-  lbitset_elt *delt;
-  int j;
-
   if (src == dst)
     return true;
 
   lbitset_weed (src);
   lbitset_weed (dst);
+  lbitset_elt *selt;
+  lbitset_elt *delt;
   for (selt = LBITSET_HEAD (src), delt = LBITSET_HEAD (dst);
        selt && delt; selt = selt->next, delt = delt->next)
     {
       if (selt->index != delt->index)
         return false;
 
-      for (j = 0; j < LBITSET_ELT_WORDS; j++)
+      for (int j = 0; j < LBITSET_ELT_WORDS; j++)
         if (delt->words[j] != selt->words[j])
           return false;
     }
@@ -445,22 +434,18 @@ lbitset_equal_p (bitset dst, bitset src)
 static inline void
 lbitset_copy (bitset dst, bitset src)
 {
-  lbitset_elt *elt;
-  lbitset_elt *head;
-  lbitset_elt *prev;
-  lbitset_elt *tmp;
-
   if (src == dst)
     return;
 
   lbitset_zero (dst);
 
-  head = LBITSET_HEAD (src);
+  lbitset_elt *head = LBITSET_HEAD (src);
   if (!head)
     return;
 
-  prev = 0;
-  for (elt = head; elt; elt = elt->next)
+  lbitset_elt *prev = 0;
+  lbitset_elt *tmp;
+  for (lbitset_elt *elt = head; elt; elt = elt->next)
     {
       tmp = lbitset_elt_alloc ();
       tmp->index = elt->index;
@@ -507,10 +492,10 @@ lbitset_copy_cmp (bitset dst, bitset src)
 static bitset_bindex
 lbitset_resize (bitset src, bitset_bindex size)
 {
-    BITSET_NBITS_ (src) = size;
+  BITSET_NBITS_ (src) = size;
 
-    /* Need to prune any excess bits.  FIXME.  */
-    return size;
+  /* Need to prune any excess bits.  FIXME.  */
+  return size;
 }
 
 /* Set bit BITNO in bitset DST.  */
@@ -569,29 +554,19 @@ static bitset_bindex
 lbitset_list_reverse (bitset bset, bitset_bindex *list,
                       bitset_bindex num, bitset_bindex *next)
 {
-  bitset_bindex rbitno;
-  bitset_bindex bitno;
-  unsigned bcount;
-  bitset_bindex boffset;
-  bitset_windex windex;
-  bitset_bindex count;
-  lbitset_elt *elt;
-  bitset_word word;
-  bitset_bindex n_bits;
-
-  elt = LBITSET_TAIL (bset);
+  lbitset_elt *elt = LBITSET_TAIL (bset);
   if (!elt)
     return 0;
 
-  n_bits = (elt->index + LBITSET_ELT_WORDS) * BITSET_WORD_BITS;
-  rbitno = *next;
+  bitset_bindex n_bits = (elt->index + LBITSET_ELT_WORDS) * BITSET_WORD_BITS;
+  bitset_bindex rbitno = *next;
 
   if (rbitno >= n_bits)
     return 0;
 
-  bitno = n_bits - (rbitno + 1);
+  bitset_bindex bitno = n_bits - (rbitno + 1);
 
-  windex = bitno / BITSET_WORD_BITS;
+  bitset_windex windex = bitno / BITSET_WORD_BITS;
 
   /* Skip back to starting element.  */
   for (; elt && elt->index > windex; elt = elt->prev)
@@ -600,6 +575,7 @@ lbitset_list_reverse (bitset bset, bitset_bindex *list,
   if (!elt)
     return 0;
 
+  unsigned bcount;
   if (windex >= elt->index + LBITSET_ELT_WORDS)
     {
       /* We are trying to start in no-mans land so start
@@ -612,8 +588,8 @@ lbitset_list_reverse (bitset bset, bitset_bindex *list,
       bcount = bitno % BITSET_WORD_BITS;
     }
 
-  count = 0;
-  boffset = windex * BITSET_WORD_BITS;
+  bitset_bindex count = 0;
+  bitset_bindex boffset = windex * BITSET_WORD_BITS;
 
   /* If num is 1, we could speed things up with a binary search
      of the word of interest.  */
@@ -626,7 +602,7 @@ lbitset_list_reverse (bitset bset, bitset_bindex *list,
            windex--, boffset -= BITSET_WORD_BITS,
              bcount = BITSET_WORD_BITS - 1)
         {
-          word =
+          bitset_word word =
             srcp[windex - elt->index] << (BITSET_WORD_BITS - 1 - bcount);
 
           for (; word; bcount--)
@@ -664,19 +640,16 @@ static bitset_bindex
 lbitset_list (bitset bset, bitset_bindex *list,
               bitset_bindex num, bitset_bindex *next)
 {
-  bitset_bindex bitno;
+  lbitset_elt *head = LBITSET_HEAD (bset);
+  if (!head)
+    return 0;
+
   bitset_windex windex;
-  bitset_bindex count;
   lbitset_elt *elt;
-  lbitset_elt *head;
   bitset_word word;
 
-  head = LBITSET_HEAD (bset);
-  if (!head)
-    return 0;
-
-  bitno = *next;
-  count = 0;
+  bitset_bindex bitno = *next;
+  bitset_bindex count = 0;
 
   if (!bitno)
     {
@@ -746,7 +719,6 @@ lbitset_list (bitset bset, bitset_bindex *list,
 
   while (elt)
     {
-      int i;
       bitset_word *srcp = elt->words;
 
       if ((count + LBITSET_ELT_BITS) < num)
@@ -795,7 +767,7 @@ lbitset_list (bitset bset, bitset_bindex *list,
           windex++;
           bitno = windex * BITSET_WORD_BITS;
 #else
-          for (i = 0; i < LBITSET_ELT_WORDS; i++)
+          for (int i = 0; i < LBITSET_ELT_WORDS; i++)
             {
               word = srcp[i];
               if (word)
@@ -827,7 +799,7 @@ lbitset_list (bitset bset, bitset_bindex *list,
           /* Tread more carefully since we need to check
              if array overflows.  */
 
-          for (i = 0; i < LBITSET_ELT_WORDS; i++)
+          for (int i = 0; i < LBITSET_ELT_WORDS; i++)
             {
               for (word = srcp[i]; word; bitno++)
                 {
@@ -911,21 +883,18 @@ lbitset_unused_clear (bitset dst)
 static void
 lbitset_ones (bitset dst)
 {
-  bitset_windex i;
-  bitset_windex windex;
-  lbitset_elt *elt;
-
   /* This is a decidedly unfriendly operation for a linked list
-      bitset!  It makes a sparse bitset become dense.  An alternative
-      is to have a flag that indicates that the bitset stores the
-      complement of what it indicates.  */
-
-  windex = (BITSET_SIZE_ (dst) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS;
-
-  for (i = 0; i < windex; i += LBITSET_ELT_WORDS)
+     bitset!  It makes a sparse bitset become dense.  An alternative
+     is to have a flag that indicates that the bitset stores the
+     complement of what it indicates.  */
+  
+  bitset_windex windex
+    = (BITSET_SIZE_ (dst) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS;
+
+  for (bitset_windex i = 0; i < windex; i += LBITSET_ELT_WORDS)
     {
       /* Create new elements if they cannot be found.  */
-      elt = lbitset_elt_find (dst, i, LBITSET_CREATE);
+      lbitset_elt *elt = lbitset_elt_find (dst, i, LBITSET_CREATE);
       memset (elt->words, -1, sizeof (elt->words));
     }
 
@@ -936,22 +905,17 @@ lbitset_ones (bitset dst)
 static void
 lbitset_not (bitset dst, bitset src)
 {
-  lbitset_elt *selt;
-  lbitset_elt *delt;
-  bitset_windex i;
-  unsigned j;
-  bitset_windex windex;
+  bitset_windex windex
+    = (BITSET_SIZE_ (dst) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS;
 
-  windex = (BITSET_SIZE_ (dst) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS;
-
-  for (i = 0; i < windex; i += LBITSET_ELT_WORDS)
+  for (bitset_windex i = 0; i < windex; i += LBITSET_ELT_WORDS)
     {
       /* Create new elements for dst if they cannot be found
          or substitute zero elements if src elements not found.  */
-      selt = lbitset_elt_find (src, i, LBITSET_SUBST);
-      delt = lbitset_elt_find (dst, i, LBITSET_CREATE);
+      lbitset_elt *selt = lbitset_elt_find (src, i, LBITSET_SUBST);
+      lbitset_elt *delt = lbitset_elt_find (dst, i, LBITSET_CREATE);
 
-      for (j = 0; j < LBITSET_ELT_WORDS; j++)
+      for (unsigned j = 0; j < LBITSET_ELT_WORDS; j++)
         delt->words[j] = ~selt->words[j];
     }
   lbitset_unused_clear (dst);
@@ -964,11 +928,7 @@ lbitset_not (bitset dst, bitset src)
 static bool
 lbitset_subset_p (bitset dst, bitset src)
 {
-  lbitset_elt *selt;
-  lbitset_elt *delt;
-  unsigned j;
-
-  for (selt = LBITSET_HEAD (src), delt = LBITSET_HEAD (dst);
+  for (lbitset_elt *selt = LBITSET_HEAD (src), *delt = LBITSET_HEAD (dst);
        selt || delt; selt = selt->next, delt = delt->next)
     {
       if (!selt)
@@ -989,7 +949,7 @@ lbitset_subset_p (bitset dst, bitset src)
             }
         }
 
-      for (j = 0; j < LBITSET_ELT_WORDS; j++)
+      for (unsigned j = 0; j < LBITSET_ELT_WORDS; j++)
         if (delt->words[j] != (selt->words[j] | delt->words[j]))
           return false;
     }
@@ -1001,11 +961,7 @@ lbitset_subset_p (bitset dst, bitset src)
 static bool
 lbitset_disjoint_p (bitset dst, bitset src)
 {
-  lbitset_elt *selt;
-  lbitset_elt *delt;
-  unsigned j;
-
-  for (selt = LBITSET_HEAD (src), delt = LBITSET_HEAD (dst);
+  for (lbitset_elt *selt = LBITSET_HEAD (src), *delt = LBITSET_HEAD (dst);
        selt && delt; selt = selt->next, delt = delt->next)
     {
       if (selt->index != delt->index)
@@ -1025,7 +981,7 @@ lbitset_disjoint_p (bitset dst, bitset src)
           continue;
         }
 
-      for (j = 0; j < LBITSET_ELT_WORDS; j++)
+      for (unsigned j = 0; j < LBITSET_ELT_WORDS; j++)
         if (selt->words[j] & delt->words[j])
           return false;
     }
@@ -1039,8 +995,6 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
   lbitset_elt *selt1 = LBITSET_HEAD (src1);
   lbitset_elt *selt2 = LBITSET_HEAD (src2);
   lbitset_elt *delt = LBITSET_HEAD (dst);
-  bitset_windex windex1;
-  bitset_windex windex2;
   bitset_windex windex;
   lbitset_elt *stmp1;
   lbitset_elt *stmp2;
@@ -1049,13 +1003,12 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
   bitset_word *srcp2;
   bitset_word *dstp;
   bool changed = false;
-  unsigned i;
 
   LBITSET_HEAD (dst) = 0;
   dst->b.csize = 0;
 
-  windex1 = (selt1) ? selt1->index : BITSET_WINDEX_MAX;
-  windex2 = (selt2) ? selt2->index : BITSET_WINDEX_MAX;
+  bitset_windex windex1 = (selt1) ? selt1->index : BITSET_WINDEX_MAX;
+  bitset_windex windex2 = (selt2) ? selt2->index : BITSET_WINDEX_MAX;
 
   while (selt1 || selt2)
     {
@@ -1116,7 +1069,7 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
           abort ();
 
         case BITSET_OP_OR:
-          for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
+          for (unsigned i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
             {
               bitset_word tmp = *srcp1++ | *srcp2++;
 
@@ -1129,7 +1082,7 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
           break;
 
         case BITSET_OP_AND:
-          for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
+          for (unsigned i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
             {
               bitset_word tmp = *srcp1++ & *srcp2++;
 
@@ -1142,7 +1095,7 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
           break;
 
         case BITSET_OP_XOR:
-          for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
+          for (unsigned i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
             {
               bitset_word tmp = *srcp1++ ^ *srcp2++;
 
@@ -1155,7 +1108,7 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
           break;
 
         case BITSET_OP_ANDN:
-          for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
+          for (unsigned i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
             {
               bitset_word tmp = *srcp1++ & ~(*srcp2++);
 
@@ -1196,19 +1149,18 @@ lbitset_and_cmp (bitset dst, bitset src1, bitset src2)
 {
   lbitset_elt *selt1 = LBITSET_HEAD (src1);
   lbitset_elt *selt2 = LBITSET_HEAD (src2);
-  bool changed;
 
   if (!selt2)
     {
       lbitset_weed (dst);
-      changed = !LBITSET_HEAD (dst);
+      bool changed = !LBITSET_HEAD (dst);
       lbitset_zero (dst);
       return changed;
     }
   else if (!selt1)
     {
       lbitset_weed (dst);
-      changed = !LBITSET_HEAD (dst);
+      bool changed = !LBITSET_HEAD (dst);
       lbitset_zero (dst);
       return changed;
     }
@@ -1228,7 +1180,6 @@ lbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 {
   lbitset_elt *selt1 = LBITSET_HEAD (src1);
   lbitset_elt *selt2 = LBITSET_HEAD (src2);
-  bool changed;
 
   if (!selt2)
     {
@@ -1237,7 +1188,7 @@ lbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
   else if (!selt1)
     {
       lbitset_weed (dst);
-      changed = !LBITSET_HEAD (dst);
+      bool changed = !LBITSET_HEAD (dst);
       lbitset_zero (dst);
       return changed;
     }
@@ -1375,24 +1326,18 @@ lbitset_release_memory (void)
 void
 debug_lbitset (bitset bset)
 {
-  lbitset_elt *elt;
-  unsigned i;
-
   if (!bset)
     return;
 
-  for (elt = LBITSET_HEAD (bset); elt; elt = elt->next)
+  for (lbitset_elt *elt = LBITSET_HEAD (bset); elt; elt = elt->next)
     {
       fprintf (stderr, "Elt %lu\n", (unsigned long) elt->index);
-      for (i = 0; i < LBITSET_ELT_WORDS; i++)
+      for (unsigned i = 0; i < LBITSET_ELT_WORDS; i++)
         {
-          unsigned j;
-          bitset_word word;
-
-          word = elt->words[i];
+          bitset_word word = elt->words[i];
 
           fprintf (stderr, "  Word %u:", i);
-          for (j = 0; j < LBITSET_WORD_BITS; j++)
+          for (unsigned j = 0; j < LBITSET_WORD_BITS; j++)
             if ((word & ((bitset_word) 1 << j)))
               fprintf (stderr, " %u", j);
           fprintf (stderr, "\n");
