@@ -123,14 +123,11 @@ static ebitset_elt *ebitset_free_list;  /* Free list of bitset elements.  */
 static bitset_bindex
 ebitset_resize (bitset src, bitset_bindex n_bits)
 {
-  bitset_windex oldsize;
-  bitset_windex newsize;
-
   if (n_bits == BITSET_NBITS_ (src))
     return n_bits;
 
-  oldsize = EBITSET_SIZE (src);
-  newsize = EBITSET_N_ELTS (n_bits);
+  bitset_windex oldsize = EBITSET_SIZE (src);
+  bitset_windex newsize = EBITSET_N_ELTS (n_bits);
 
   if (oldsize < newsize)
     {
@@ -234,9 +231,7 @@ ebitset_elt_alloc (void)
 static inline ebitset_elt *
 ebitset_elt_calloc (void)
 {
-  ebitset_elt *elt;
-
-  elt = ebitset_elt_alloc ();
+  ebitset_elt *elt = ebitset_elt_alloc ();
   memset (EBITSET_WORDS (elt), 0, sizeof (EBITSET_WORDS (elt)));
   return elt;
 }
@@ -254,12 +249,8 @@ ebitset_elt_free (ebitset_elt *elt)
 static inline void
 ebitset_elt_remove (bitset bset, bitset_windex eindex)
 {
-  ebitset_elts *elts;
-  ebitset_elt *elt;
-
-  elts = EBITSET_ELTS (bset);
-
-  elt = elts[eindex];
+  ebitset_elts *elts = EBITSET_ELTS (bset);
+  ebitset_elt *elt = elts[eindex];
 
   elts[eindex] = 0;
   ebitset_elt_free (elt);
@@ -270,9 +261,7 @@ ebitset_elt_remove (bitset bset, bitset_windex eindex)
 static inline void
 ebitset_elt_add (bitset bset, ebitset_elt *elt, bitset_windex eindex)
 {
-  ebitset_elts *elts;
-
-  elts = EBITSET_ELTS (bset);
+  ebitset_elts *elts = EBITSET_ELTS (bset);
   /* Assume that the elts entry not allocated.  */
   elts[eindex] = elt;
 }
@@ -282,9 +271,7 @@ ebitset_elt_add (bitset bset, ebitset_elt *elt, bitset_windex eindex)
 static inline bool
 ebitset_elt_zero_p (ebitset_elt *elt)
 {
-  int i;
-
-  for (i = 0; i < EBITSET_ELT_WORDS; i++)
+  for (int i = 0; i < EBITSET_ELT_WORDS; i++)
     if (EBITSET_WORDS (elt)[i])
       return false;
 
@@ -296,24 +283,18 @@ static ebitset_elt *
 ebitset_elt_find (bitset bset, bitset_bindex bindex,
                   enum ebitset_find_mode mode)
 {
-  ebitset_elt *elt;
-  bitset_windex size;
-  bitset_windex eindex;
-  ebitset_elts *elts;
-
-  eindex = bindex / EBITSET_ELT_BITS;
+  bitset_windex eindex = bindex / EBITSET_ELT_BITS;
 
-  elts = EBITSET_ELTS (bset);
-  size = EBITSET_SIZE (bset);
+  ebitset_elts *elts = EBITSET_ELTS (bset);
+  bitset_windex size = EBITSET_SIZE (bset);
 
   if (eindex < size)
     {
-      if ((elt = elts[eindex]))
+      ebitset_elt *elt = elts[eindex];
+      if (elt)
         {
-          if (EBITSET_WORDS (elt) == bset->b.cdata)
-            return elt;
-
-          EBITSET_CACHE_SET (bset, eindex);
+          if (EBITSET_WORDS (elt) != bset->b.cdata)
+            EBITSET_CACHE_SET (bset, eindex);
           return elt;
         }
     }
@@ -333,10 +314,12 @@ ebitset_elt_find (bitset bset, bitset_bindex bindex,
         ebitset_resize (bset, bindex);
 
       /* Create a new element.  */
-      elt = ebitset_elt_calloc ();
-      ebitset_elt_add (bset, elt, eindex);
-      EBITSET_CACHE_SET (bset, eindex);
-      return elt;
+      {
+        ebitset_elt *elt = ebitset_elt_calloc ();
+        ebitset_elt_add (bset, elt, eindex);
+        EBITSET_CACHE_SET (bset, eindex);
+        return elt;
+      }
 
     case EBITSET_SUBST:
       return &ebitset_zero_elts[0];
@@ -348,15 +331,12 @@ ebitset_elt_find (bitset bset, bitset_bindex bindex,
 static inline bitset_windex
 ebitset_weed (bitset bset)
 {
-  ebitset_elts *elts;
-  bitset_windex j;
-  bitset_windex count;
-
   if (EBITSET_ZERO_P (bset))
     return 0;
 
-  elts = EBITSET_ELTS (bset);
-  count = 0;
+  ebitset_elts *elts = EBITSET_ELTS (bset);
+  bitset_windex count = 0;
+  bitset_windex j;
   for (j = 0; j < EBITSET_SIZE (bset); j++)
     {
       ebitset_elt *elt = elts[j];
@@ -391,14 +371,11 @@ ebitset_weed (bitset bset)
 static inline void
 ebitset_zero (bitset bset)
 {
-  ebitset_elts *elts;
-  bitset_windex j;
-
   if (EBITSET_ZERO_P (bset))
     return;
 
-  elts = EBITSET_ELTS (bset);
-  for (j = 0; j < EBITSET_SIZE (bset); j++)
+  ebitset_elts *elts = EBITSET_ELTS (bset);
+  for (bitset_windex j = 0; j < EBITSET_SIZE (bset); j++)
     {
       ebitset_elt *elt = elts[j];
 
@@ -415,10 +392,6 @@ ebitset_zero (bitset bset)
 static inline bool
 ebitset_equal_p (bitset dst, bitset src)
 {
-  ebitset_elts *selts;
-  ebitset_elts *delts;
-  bitset_windex j;
-
   if (src == dst)
     return true;
 
@@ -428,12 +401,11 @@ ebitset_equal_p (bitset dst, bitset src)
   if (EBITSET_SIZE (src) != EBITSET_SIZE (dst))
     return false;
 
-  selts = EBITSET_ELTS (src);
-  delts = EBITSET_ELTS (dst);
+  ebitset_elts *selts = EBITSET_ELTS (src);
+  ebitset_elts *delts = EBITSET_ELTS (dst);
 
-  for (j = 0; j < EBITSET_SIZE (src); j++)
+  for (bitset_windex j = 0; j < EBITSET_SIZE (src); j++)
     {
-      unsigned i;
       ebitset_elt *selt = selts[j];
       ebitset_elt *delt = delts[j];
 
@@ -442,7 +414,7 @@ ebitset_equal_p (bitset dst, bitset src)
       if ((selt && !delt) || (!selt && delt))
         return false;
 
-      for (i = 0; i < EBITSET_ELT_WORDS; i++)
+      for (unsigned i = 0; i < EBITSET_ELT_WORDS; i++)
         if (EBITSET_WORDS (selt)[i] != EBITSET_WORDS (delt)[i])
           return false;
     }
@@ -454,10 +426,6 @@ ebitset_equal_p (bitset dst, bitset src)
 static inline void
 ebitset_copy_ (bitset dst, bitset src)
 {
-  ebitset_elts *selts;
-  ebitset_elts *delts;
-  bitset_windex j;
-
   if (src == dst)
     return;
 
@@ -466,17 +434,15 @@ ebitset_copy_ (bitset dst, bitset src)
   if (BITSET_NBITS_ (dst) != BITSET_NBITS_ (src))
     ebitset_resize (dst, BITSET_NBITS_ (src));
 
-  selts = EBITSET_ELTS (src);
-  delts = EBITSET_ELTS (dst);
-  for (j = 0; j < EBITSET_SIZE (src); j++)
+  ebitset_elts *selts = EBITSET_ELTS (src);
+  ebitset_elts *delts = EBITSET_ELTS (dst);
+  for (bitset_windex j = 0; j < EBITSET_SIZE (src); j++)
     {
       ebitset_elt *selt = selts[j];
 
       if (selt)
         {
-          ebitset_elt *tmp;
-
-          tmp = ebitset_elt_alloc ();
+          ebitset_elt *tmp = ebitset_elt_alloc ();
           delts[j] = tmp;
           memcpy (EBITSET_WORDS (tmp), EBITSET_WORDS (selt),
                   sizeof (EBITSET_WORDS (selt)));
@@ -567,60 +533,41 @@ static bitset_bindex
 ebitset_list_reverse (bitset bset, bitset_bindex *list,
                       bitset_bindex num, bitset_bindex *next)
 {
-  bitset_bindex n_bits;
-  bitset_bindex bitno;
-  bitset_bindex rbitno;
-  unsigned bcount;
-  bitset_bindex boffset;
-  bitset_windex windex;
-  bitset_windex eindex;
-  bitset_windex woffset;
-  bitset_bindex count;
-  bitset_windex size;
-  ebitset_elts *elts;
-
   if (EBITSET_ZERO_P (bset))
     return 0;
 
-  size = EBITSET_SIZE (bset);
-  n_bits = size * EBITSET_ELT_BITS;
-  rbitno = *next;
+  bitset_windex size = EBITSET_SIZE (bset);
+  bitset_bindex n_bits = size * EBITSET_ELT_BITS;
+  bitset_bindex rbitno = *next;
 
   if (rbitno >= n_bits)
     return 0;
 
-  elts = EBITSET_ELTS (bset);
+  ebitset_elts *elts = EBITSET_ELTS (bset);
 
-  bitno = n_bits - (rbitno + 1);
+  bitset_bindex bitno = n_bits - (rbitno + 1);
 
-  windex = bitno / BITSET_WORD_BITS;
-  eindex = bitno / EBITSET_ELT_BITS;
-  woffset = windex - eindex * EBITSET_ELT_WORDS;
+  bitset_windex windex = bitno / BITSET_WORD_BITS;
+  bitset_windex eindex = bitno / EBITSET_ELT_BITS;
+  bitset_windex woffset = windex - eindex * EBITSET_ELT_WORDS;
 
   /* If num is 1, we could speed things up with a binary search
      of the word of interest.  */
-
-  count = 0;
-  bcount = bitno % BITSET_WORD_BITS;
-  boffset = windex * BITSET_WORD_BITS;
+  bitset_bindex count = 0;
+  unsigned bcount = bitno % BITSET_WORD_BITS;
+  bitset_bindex boffset = windex * BITSET_WORD_BITS;
 
   do
     {
-      ebitset_elt *elt;
-      bitset_word *srcp;
-
-      elt = elts[eindex];
+      ebitset_elt *elt = elts[eindex];
       if (elt)
         {
-          srcp = EBITSET_WORDS (elt);
+          bitset_word *srcp = EBITSET_WORDS (elt);
 
           do
             {
-              bitset_word word;
-
-              word = srcp[woffset] << (BITSET_WORD_BITS - 1 - bcount);
-
-              for (; word; bcount--)
+              for (bitset_word word = srcp[woffset] << (BITSET_WORD_BITS - 1 - bcount);
+                   word; bcount--)
                 {
                   if (word & BITSET_MSB)
                     {
@@ -656,41 +603,32 @@ static bitset_bindex
 ebitset_list (bitset bset, bitset_bindex *list,
               bitset_bindex num, bitset_bindex *next)
 {
-  bitset_bindex bitno;
-  bitset_windex windex;
-  bitset_windex eindex;
-  bitset_bindex count;
-  bitset_windex size;
-  ebitset_elt *elt;
-  bitset_word word;
-  ebitset_elts *elts;
-
   if (EBITSET_ZERO_P (bset))
     return 0;
 
-  bitno = *next;
-  count = 0;
+  bitset_bindex bitno = *next;
+  bitset_bindex count = 0;
 
-  elts = EBITSET_ELTS (bset);
-  size = EBITSET_SIZE (bset);
-  eindex = bitno / EBITSET_ELT_BITS;
+  ebitset_elts *elts = EBITSET_ELTS (bset);
+  bitset_windex size = EBITSET_SIZE (bset);
+  bitset_windex eindex = bitno / EBITSET_ELT_BITS;
 
   if (bitno % EBITSET_ELT_BITS)
     {
       /* We need to start within an element.  This is not very common.  */
 
-      elt = elts[eindex];
+      ebitset_elt *elt = elts[eindex];
       if (elt)
         {
           bitset_windex woffset;
           bitset_word *srcp = EBITSET_WORDS (elt);
 
-          windex = bitno / BITSET_WORD_BITS;
+          bitset_windex windex = bitno / BITSET_WORD_BITS;
           woffset = eindex * EBITSET_ELT_WORDS;
 
           for (; (windex - woffset) < EBITSET_ELT_WORDS; windex++)
             {
-              word = srcp[windex - woffset] >> (bitno % BITSET_WORD_BITS);
+              bitset_word word = srcp[windex - woffset] >> (bitno % BITSET_WORD_BITS);
 
               for (; word; bitno++)
                 {
@@ -718,22 +656,21 @@ ebitset_list (bitset bset, bitset_bindex *list,
 
   for (; eindex < size; eindex++)
     {
-      int i;
       bitset_word *srcp;
 
-      elt = elts[eindex];
+      ebitset_elt *elt = elts[eindex];
       if (!elt)
         continue;
 
       srcp = EBITSET_WORDS (elt);
-      windex = eindex * EBITSET_ELT_WORDS;
+      bitset_windex windex = eindex * EBITSET_ELT_WORDS;
 
       if ((count + EBITSET_ELT_BITS) < num)
         {
           /* The coast is clear, plant boot!  */
 
 #if EBITSET_ELT_WORDS == 2
-          word = srcp[0];
+          bitset_word word = srcp[0];
           if (word)
             {
               if (!(word & 0xffff))
@@ -774,7 +711,7 @@ ebitset_list (bitset bset, bitset_bindex *list,
           windex++;
           bitno = windex * BITSET_WORD_BITS;
 #else
-          for (i = 0; i < EBITSET_ELT_WORDS; i++, windex++)
+          for (int i = 0; i < EBITSET_ELT_WORDS; i++, windex++)
             {
               bitno = windex * BITSET_WORD_BITS;
 
@@ -806,11 +743,11 @@ ebitset_list (bitset bset, bitset_bindex *list,
           /* Tread more carefully since we need to check
              if array overflows.  */
 
-          for (i = 0; i < EBITSET_ELT_WORDS; i++, windex++)
+          for (int i = 0; i < EBITSET_ELT_WORDS; i++, windex++)
             {
               bitno = windex * BITSET_WORD_BITS;
 
-              for (word = srcp[i]; word; bitno++)
+              for (bitset_word word = srcp[i]; word; bitno++)
                 {
                   if (word & 1)
                     {
@@ -836,31 +773,22 @@ ebitset_list (bitset bset, bitset_bindex *list,
 static inline void
 ebitset_unused_clear (bitset dst)
 {
-  unsigned last_bit;
-  bitset_bindex n_bits;
-
-  n_bits = BITSET_NBITS_ (dst);
-  last_bit = n_bits % EBITSET_ELT_BITS;
+  bitset_bindex n_bits = BITSET_NBITS_ (dst);
+  unsigned last_bit = n_bits % EBITSET_ELT_BITS;
 
   if (last_bit)
     {
-      bitset_windex eindex;
-      ebitset_elts *elts;
-      ebitset_elt *elt;
-
-      elts = EBITSET_ELTS (dst);
+      ebitset_elts *elts = EBITSET_ELTS (dst);
 
-      eindex = n_bits / EBITSET_ELT_BITS;
+      bitset_windex eindex = n_bits / EBITSET_ELT_BITS;
 
-      elt = elts[eindex];
+      ebitset_elt *elt = elts[eindex];
       if (elt)
         {
-          bitset_windex windex;
-          bitset_windex woffset;
           bitset_word *srcp = EBITSET_WORDS (elt);
 
-          windex = n_bits / BITSET_WORD_BITS;
-          woffset = eindex * EBITSET_ELT_WORDS;
+          bitset_windex windex = n_bits / BITSET_WORD_BITS;
+          bitset_windex woffset = eindex * EBITSET_ELT_WORDS;
 
           srcp[windex - woffset] &= ((bitset_word) 1 << last_bit) - 1;
           windex++;
@@ -874,14 +802,11 @@ ebitset_unused_clear (bitset dst)
 static void
 ebitset_ones (bitset dst)
 {
-  bitset_windex j;
-  ebitset_elt *elt;
-
-  for (j = 0; j < EBITSET_SIZE (dst); j++)
+  for (bitset_windex j = 0; j < EBITSET_SIZE (dst); j++)
     {
       /* Create new elements if they cannot be found.  Perhaps
          we should just add pointers to a ones element?  */
-      elt =
+      ebitset_elt *elt =
         ebitset_elt_find (dst, j * EBITSET_ELT_BITS, EBITSET_CREATE);
       memset (EBITSET_WORDS (elt), -1, sizeof (EBITSET_WORDS (elt)));
     }
@@ -893,14 +818,11 @@ ebitset_ones (bitset dst)
 static bool
 ebitset_empty_p (bitset dst)
 {
-  ebitset_elts *elts;
-  bitset_windex j;
-
   if (EBITSET_ZERO_P (dst))
     return 1;
 
-  elts = EBITSET_ELTS (dst);
-  for (j = 0; j < EBITSET_SIZE (dst); j++)
+  ebitset_elts *elts = EBITSET_ELTS (dst);
+  for (bitset_windex j = 0; j < EBITSET_SIZE (dst); j++)
     {
       ebitset_elt *elt = elts[j];
 
@@ -923,23 +845,18 @@ ebitset_empty_p (bitset dst)
 static void
 ebitset_not (bitset dst, bitset src)
 {
-  unsigned i;
-  ebitset_elt *selt;
-  ebitset_elt *delt;
-  bitset_windex j;
-
   ebitset_resize (dst, BITSET_NBITS_ (src));
 
-  for (j = 0; j < EBITSET_SIZE (src); j++)
+  for (bitset_windex j = 0; j < EBITSET_SIZE (src); j++)
     {
       /* Create new elements for dst if they cannot be found
          or substitute zero elements if src elements not found.  */
-      selt =
+      ebitset_elt *selt =
         ebitset_elt_find (dst, j * EBITSET_ELT_BITS, EBITSET_SUBST);
-      delt =
+      ebitset_elt *delt =
         ebitset_elt_find (dst, j * EBITSET_ELT_BITS, EBITSET_CREATE);
 
-      for (i = 0; i < EBITSET_ELT_WORDS; i++)
+      for (unsigned i = 0; i < EBITSET_ELT_WORDS; i++)
         EBITSET_WORDS (delt)[i] = ~EBITSET_WORDS (selt)[i];
     }
   EBITSET_NONZERO_SET (dst);
@@ -951,26 +868,16 @@ ebitset_not (bitset dst, bitset src)
 static bool
 ebitset_subset_p (bitset dst, bitset src)
 {
-  bitset_windex j;
-  ebitset_elts *selts;
-  ebitset_elts *delts;
-  bitset_windex ssize;
-  bitset_windex dsize;
-
-  selts = EBITSET_ELTS (src);
-  delts = EBITSET_ELTS (dst);
+  ebitset_elts *selts = EBITSET_ELTS (src);
+  ebitset_elts *delts = EBITSET_ELTS (dst);
 
-  ssize = EBITSET_SIZE (src);
-  dsize = EBITSET_SIZE (dst);
+  bitset_windex ssize = EBITSET_SIZE (src);
+  bitset_windex dsize = EBITSET_SIZE (dst);
 
-  for (j = 0; j < ssize; j++)
+  for (bitset_windex j = 0; j < ssize; j++)
     {
-      unsigned i;
-      ebitset_elt *selt;
-      ebitset_elt *delt;
-
-      selt = j < ssize ? selts[j] : 0;
-      delt = j < dsize ? delts[j] : 0;
+      ebitset_elt *selt = j < ssize ? selts[j] : 0;
+      ebitset_elt *delt = j < dsize ? delts[j] : 0;
 
       if (!selt && !delt)
         continue;
@@ -980,7 +887,7 @@ ebitset_subset_p (bitset dst, bitset src)
       if (!delt)
         delt = &ebitset_zero_elts[0];
 
-      for (i = 0; i < EBITSET_ELT_WORDS; i++)
+      for (unsigned i = 0; i < EBITSET_ELT_WORDS; i++)
         if (EBITSET_WORDS (delt)[i]
             != (EBITSET_WORDS (selt)[i] | EBITSET_WORDS (delt)[i]))
           return false;
@@ -993,31 +900,21 @@ ebitset_subset_p (bitset dst, bitset src)
 static bool
 ebitset_disjoint_p (bitset dst, bitset src)
 {
-  bitset_windex j;
-  ebitset_elts *selts;
-  ebitset_elts *delts;
-  bitset_windex ssize;
-  bitset_windex dsize;
+  ebitset_elts *selts = EBITSET_ELTS (src);
+  ebitset_elts *delts = EBITSET_ELTS (dst);
 
-  selts = EBITSET_ELTS (src);
-  delts = EBITSET_ELTS (dst);
+  bitset_windex ssize = EBITSET_SIZE (src);
+  bitset_windex dsize = EBITSET_SIZE (dst);
 
-  ssize = EBITSET_SIZE (src);
-  dsize = EBITSET_SIZE (dst);
-
-  for (j = 0; j < ssize; j++)
+  for (bitset_windex j = 0; j < ssize; j++)
     {
-      unsigned i;
-      ebitset_elt *selt;
-      ebitset_elt *delt;
-
-      selt = j < ssize ? selts[j] : 0;
-      delt = j < dsize ? delts[j] : 0;
+      ebitset_elt *selt = j < ssize ? selts[j] : 0;
+      ebitset_elt *delt = j < dsize ? delts[j] : 0;
 
       if (!selt || !delt)
         continue;
 
-      for (i = 0; i < EBITSET_ELT_WORDS; i++)
+      for (unsigned i = 0; i < EBITSET_ELT_WORDS; i++)
         if ((EBITSET_WORDS (selt)[i] & EBITSET_WORDS (delt)[i]))
           return false;
     }
@@ -1029,42 +926,27 @@ ebitset_disjoint_p (bitset dst, bitset src)
 static bool
 ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 {
-  bitset_windex ssize1;
-  bitset_windex ssize2;
-  bitset_windex dsize;
-  bitset_windex size;
-  ebitset_elts *selts1;
-  ebitset_elts *selts2;
-  ebitset_elts *delts;
-  bitset_word *srcp1;
-  bitset_word *srcp2;
-  bitset_word *dstp;
   bool changed = false;
-  unsigned i;
-  bitset_windex j;
 
   ebitset_resize (dst, max (BITSET_NBITS_ (src1), BITSET_NBITS_ (src2)));
 
-  ssize1 = EBITSET_SIZE (src1);
-  ssize2 = EBITSET_SIZE (src2);
-  dsize = EBITSET_SIZE (dst);
-  size = ssize1;
+  bitset_windex ssize1 = EBITSET_SIZE (src1);
+  bitset_windex ssize2 = EBITSET_SIZE (src2);
+  bitset_windex dsize = EBITSET_SIZE (dst);
+  bitset_windex size = ssize1;
   if (size < ssize2)
     size = ssize2;
 
-  selts1 = EBITSET_ELTS (src1);
-  selts2 = EBITSET_ELTS (src2);
-  delts = EBITSET_ELTS (dst);
+  ebitset_elts *selts1 = EBITSET_ELTS (src1);
+  ebitset_elts *selts2 = EBITSET_ELTS (src2);
+  ebitset_elts *delts = EBITSET_ELTS (dst);
 
+  bitset_windex j = 0;
   for (j = 0; j < size; j++)
     {
-      ebitset_elt *selt1;
-      ebitset_elt *selt2;
-      ebitset_elt *delt;
-
-      selt1 = j < ssize1 ? selts1[j] : 0;
-      selt2 = j < ssize2 ? selts2[j] : 0;
-      delt = j < dsize ? delts[j] : 0;
+      ebitset_elt *selt1 = j < ssize1 ? selts1[j] : 0;
+      ebitset_elt *selt2 = j < ssize2 ? selts2[j] : 0;
+      ebitset_elt *delt = j < dsize ? delts[j] : 0;
 
       if (!selt1 && !selt2)
         {
@@ -1085,16 +967,16 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
       else
         delts[j] = 0;
 
-      srcp1 = EBITSET_WORDS (selt1);
-      srcp2 = EBITSET_WORDS (selt2);
-      dstp = EBITSET_WORDS (delt);
+      bitset_word *srcp1 = EBITSET_WORDS (selt1);
+      bitset_word *srcp2 = EBITSET_WORDS (selt2);
+      bitset_word *dstp = EBITSET_WORDS (delt);
       switch (op)
         {
         default:
           abort ();
 
         case BITSET_OP_OR:
-          for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
+          for (unsigned i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
             {
               bitset_word tmp = *srcp1++ | *srcp2++;
 
@@ -1107,7 +989,7 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
           break;
 
         case BITSET_OP_AND:
-          for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
+          for (unsigned i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
             {
               bitset_word tmp = *srcp1++ & *srcp2++;
 
@@ -1120,7 +1002,7 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
           break;
 
         case BITSET_OP_XOR:
-          for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
+          for (unsigned i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
             {
               bitset_word tmp = *srcp1++ ^ *srcp2++;
 
@@ -1133,7 +1015,7 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
           break;
 
         case BITSET_OP_ANDN:
-          for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
+          for (unsigned i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
             {
               bitset_word tmp = *srcp1++ & ~(*srcp2++);
 
@@ -1159,12 +1041,9 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
   /* If we have elements of DST left over, free them all.  */
   for (; j < dsize; j++)
     {
-      ebitset_elt *delt;
-
       changed = true;
 
-      delt = delts[j];
-
+      ebitset_elt *delt = delts[j];
       if (delt)
         ebitset_elt_remove (dst, j);
     }
@@ -1177,19 +1056,17 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 static bool
 ebitset_and_cmp (bitset dst, bitset src1, bitset src2)
 {
-  bool changed;
-
   if (EBITSET_ZERO_P (src2))
     {
       ebitset_weed (dst);
-      changed = EBITSET_ZERO_P (dst);
+      bool changed = EBITSET_ZERO_P (dst);
       ebitset_zero (dst);
       return changed;
     }
   else if (EBITSET_ZERO_P (src1))
     {
       ebitset_weed (dst);
-      changed = EBITSET_ZERO_P (dst);
+      bool changed = EBITSET_ZERO_P (dst);
       ebitset_zero (dst);
       return changed;
     }
@@ -1207,8 +1084,6 @@ ebitset_and (bitset dst, bitset src1, bitset src2)
 static bool
 ebitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 {
-  bool changed;
-
   if (EBITSET_ZERO_P (src2))
     {
       return ebitset_copy_cmp (dst, src1);
@@ -1216,7 +1091,7 @@ ebitset_andn_cmp (bitset dst, bitset src1, bitset src2)
   else if (EBITSET_ZERO_P (src1))
     {
       ebitset_weed (dst);
-      changed = EBITSET_ZERO_P (dst);
+      bool changed = EBITSET_ZERO_P (dst);
       ebitset_zero (dst);
       return changed;
     }
@@ -1279,9 +1154,9 @@ static void
 ebitset_copy (bitset dst, bitset src)
 {
   if (BITSET_COMPATIBLE_ (dst, src))
-      ebitset_copy_ (dst, src);
+    ebitset_copy_ (dst, src);
   else
-      bitset_copy_ (dst, src);
+    bitset_copy_ (dst, src);
 }
 
 
