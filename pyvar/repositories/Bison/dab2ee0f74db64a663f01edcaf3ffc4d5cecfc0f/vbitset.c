@@ -56,19 +56,14 @@ static bitset_bindex vbitset_list_reverse (bitset, bitset_bindex *,
 static bitset_bindex
 vbitset_resize (bitset src, bitset_bindex n_bits)
 {
-  bitset_windex oldsize;
-  bitset_windex newsize;
-
   if (n_bits == BITSET_NBITS_ (src))
     return n_bits;
 
-  oldsize = VBITSET_SIZE (src);
-  newsize = VBITSET_N_WORDS (n_bits);
+  bitset_windex oldsize = VBITSET_SIZE (src);
+  bitset_windex newsize = VBITSET_N_WORDS (n_bits);
 
   if (oldsize < newsize)
     {
-      bitset_windex size;
-
       /* The bitset needs to grow.  If we already have enough memory
          allocated, then just zero what we need.  */
       if (newsize > VBITSET_ASIZE (src))
@@ -78,6 +73,7 @@ vbitset_resize (bitset src, bitset_bindex n_bits)
              grow the bitset 25% larger than requested to reduce
              number of reallocations.  */
 
+          bitset_windex size;
           if (oldsize == 0)
             size = newsize;
           else
@@ -115,9 +111,7 @@ vbitset_resize (bitset src, bitset_bindex n_bits)
 
 /* Set bit BITNO in bitset DST.  */
 static void
-vbitset_set (dst, bitno)
-     bitset dst;
-     bitset_bindex bitno;
+vbitset_set (bitset dst, bitset_bindex bitno)
 {
   bitset_windex windex = bitno / BITSET_WORD_BITS;
 
@@ -134,9 +128,7 @@ vbitset_set (dst, bitno)
 
 /* Reset bit BITNO in bitset DST.  */
 static void
-vbitset_reset (dst, bitno)
-     bitset dst ATTRIBUTE_UNUSED;
-     bitset_bindex bitno ATTRIBUTE_UNUSED;
+vbitset_reset (bitset dst ATTRIBUTE_UNUSED, bitset_bindex bitno ATTRIBUTE_UNUSED)
 {
   /* We must be accessing outside the cache so the bit is
      zero anyway.  */
@@ -145,9 +137,8 @@ vbitset_reset (dst, bitno)
 
 /* Test bit BITNO in bitset SRC.  */
 static bool
-vbitset_test (src, bitno)
-     bitset src ATTRIBUTE_UNUSED;
-     bitset_bindex bitno ATTRIBUTE_UNUSED;
+vbitset_test (bitset src ATTRIBUTE_UNUSED,
+              bitset_bindex bitno ATTRIBUTE_UNUSED)
 {
   /* We must be accessing outside the cache so the bit is
      zero anyway.  */
@@ -160,22 +151,13 @@ vbitset_test (src, bitno)
    actual number of bits found and with *NEXT indicating where search
    stopped.  */
 static bitset_bindex
-vbitset_list_reverse (src, list, num, next)
-     bitset src;
-     bitset_bindex *list;
-     bitset_bindex num;
-     bitset_bindex *next;
+vbitset_list_reverse (bitset src, bitset_bindex *list,
+                      bitset_bindex num, bitset_bindex *next)
 {
-  bitset_bindex bitno;
-  bitset_bindex rbitno;
-  bitset_bindex count;
-  bitset_windex windex;
-  unsigned bitcnt;
-  bitset_bindex bitoff;
   bitset_word *srcp = VBITSET_WORDS (src);
   bitset_bindex n_bits = BITSET_SIZE_ (src);
 
-  rbitno = *next;
+  bitset_bindex rbitno = *next;
 
   /* If num is 1, we could speed things up with a binary search
      of the word of interest.  */
@@ -183,19 +165,17 @@ vbitset_list_reverse (src, list, num, next)
   if (rbitno >= n_bits)
     return 0;
 
-  count = 0;
+  bitset_bindex count = 0;
 
-  bitno = n_bits - (rbitno + 1);
+  bitset_bindex bitno = n_bits - (rbitno + 1);
 
-  windex = bitno / BITSET_WORD_BITS;
-  bitcnt = bitno % BITSET_WORD_BITS;
-  bitoff = windex * BITSET_WORD_BITS;
+  bitset_windex windex = bitno / BITSET_WORD_BITS;
+  unsigned bitcnt = bitno % BITSET_WORD_BITS;
+  bitset_bindex bitoff = windex * BITSET_WORD_BITS;
 
   do
     {
-      bitset_word word;
-
-      word = srcp[windex] << (BITSET_WORD_BITS - 1 - bitcnt);
+      bitset_word word = srcp[windex] << (BITSET_WORD_BITS - 1 - bitcnt);
       for (; word; bitcnt--)
         {
           if (word & BITSET_MSB)
@@ -220,26 +200,21 @@ vbitset_list_reverse (src, list, num, next)
 
 
 /* Find list of up to NUM bits set in BSET starting from and including
- *NEXT and store in array LIST.  Return with actual number of bits
- found and with *NEXT indicating where search stopped.  */
+   *NEXT and store in array LIST.  Return with actual number of bits
+   found and with *NEXT indicating where search stopped.  */
 static bitset_bindex
-vbitset_list (src, list, num, next)
-     bitset src;
-     bitset_bindex *list;
-     bitset_bindex num;
-     bitset_bindex *next;
+vbitset_list (bitset src, bitset_bindex *list,
+              bitset_bindex num, bitset_bindex *next)
 {
-  bitset_bindex bitno;
-  bitset_bindex count;
   bitset_windex windex;
   bitset_bindex bitoff;
   bitset_windex size = VBITSET_SIZE (src);
   bitset_word *srcp = VBITSET_WORDS (src);
   bitset_word word;
 
-  bitno = *next;
+  bitset_bindex bitno = *next;
 
-  count = 0;
+  bitset_bindex count = 0;
   if (!bitno)
     {
       /* Many bitsets are zero, so make this common case fast.  */
@@ -327,12 +302,9 @@ vbitset_list (src, list, num, next)
 
 /* Ensure that any unused bits within the last word are clear.  */
 static inline void
-vbitset_unused_clear (dst)
-     bitset dst;
+vbitset_unused_clear (bitset dst)
 {
-  unsigned last_bit;
-
-  last_bit = BITSET_SIZE_ (dst) % BITSET_WORD_BITS;
+  unsigned last_bit = BITSET_SIZE_ (dst) % BITSET_WORD_BITS;
   if (last_bit)
     VBITSET_WORDS (dst)[VBITSET_SIZE (dst) - 1] &=
       ((bitset_word) 1 << last_bit) - 1;
@@ -343,9 +315,7 @@ static void
 vbitset_ones (bitset dst)
 {
   bitset_word *dstp = VBITSET_WORDS (dst);
-  unsigned bytes;
-
-  bytes = sizeof (bitset_word) * VBITSET_SIZE (dst);
+  unsigned bytes = sizeof (bitset_word) * VBITSET_SIZE (dst);
 
   memset (dstp, -1, bytes);
   vbitset_unused_clear (dst);
@@ -356,9 +326,7 @@ static void
 vbitset_zero (bitset dst)
 {
   bitset_word *dstp = VBITSET_WORDS (dst);
-  unsigned bytes;
-
-  bytes = sizeof (bitset_word) * VBITSET_SIZE (dst);
+  unsigned bytes = sizeof (bitset_word) * VBITSET_SIZE (dst);
 
   memset (dstp, 0, bytes);
 }
@@ -367,10 +335,9 @@ vbitset_zero (bitset dst)
 static bool
 vbitset_empty_p (bitset dst)
 {
-  unsigned i;
   bitset_word *dstp = VBITSET_WORDS (dst);
 
-  for (i = 0; i < VBITSET_SIZE (dst); i++)
+  for (unsigned i = 0; i < VBITSET_SIZE (dst); i++)
     if (dstp[i])
       return 0;
 
@@ -381,20 +348,15 @@ vbitset_empty_p (bitset dst)
 static void
 vbitset_copy1 (bitset dst, bitset src)
 {
-  bitset_word *srcp;
-  bitset_word *dstp;
-  bitset_windex ssize;
-  bitset_windex dsize;
-
   if (src == dst)
       return;
 
   vbitset_resize (dst, BITSET_SIZE_ (src));
 
-  srcp = VBITSET_WORDS (src);
-  dstp = VBITSET_WORDS (dst);
-  ssize = VBITSET_SIZE (src);
-  dsize = VBITSET_SIZE (dst);
+  bitset_word *srcp = VBITSET_WORDS (src);
+  bitset_word *dstp = VBITSET_WORDS (dst);
+  bitset_windex ssize = VBITSET_SIZE (src);
+  bitset_windex dsize = VBITSET_SIZE (dst);
 
   memcpy (dstp, srcp, sizeof (bitset_word) * ssize);
 
@@ -406,21 +368,15 @@ vbitset_copy1 (bitset dst, bitset src)
 static void
 vbitset_not (bitset dst, bitset src)
 {
-  unsigned i;
-  bitset_word *srcp;
-  bitset_word *dstp;
-  bitset_windex ssize;
-  bitset_windex dsize;
-
   vbitset_resize (dst, BITSET_SIZE_ (src));
 
-  srcp = VBITSET_WORDS (src);
-  dstp = VBITSET_WORDS (dst);
-  ssize = VBITSET_SIZE (src);
-  dsize = VBITSET_SIZE (dst);
+  bitset_word *srcp = VBITSET_WORDS (src);
+  bitset_word *dstp = VBITSET_WORDS (dst);
+  bitset_windex ssize = VBITSET_SIZE (src);
+  bitset_windex dsize = VBITSET_SIZE (dst);
 
-  for (i = 0; i < ssize; i++)
-      *dstp++ = ~(*srcp++);
+  for (unsigned i = 0; i < ssize; i++)
+    *dstp++ = ~(*srcp++);
 
   vbitset_unused_clear (dst);
   memset (dstp + sizeof (bitset_word) * ssize, 0,
@@ -431,15 +387,15 @@ vbitset_not (bitset dst, bitset src)
 static bool
 vbitset_equal_p (bitset dst, bitset src)
 {
-  unsigned i;
   bitset_word *srcp = VBITSET_WORDS (src);
   bitset_word *dstp = VBITSET_WORDS (dst);
   bitset_windex ssize = VBITSET_SIZE (src);
   bitset_windex dsize = VBITSET_SIZE (dst);
 
+  unsigned i;
   for (i = 0; i < min (ssize, dsize); i++)
-      if (*srcp++ != *dstp++)
-          return 0;
+    if (*srcp++ != *dstp++)
+      return 0;
 
   if (ssize > dsize)
     {
@@ -461,15 +417,15 @@ vbitset_equal_p (bitset dst, bitset src)
 static bool
 vbitset_subset_p (bitset dst, bitset src)
 {
-  unsigned i;
   bitset_word *srcp = VBITSET_WORDS (src);
   bitset_word *dstp = VBITSET_WORDS (dst);
   bitset_windex ssize = VBITSET_SIZE (src);
   bitset_windex dsize = VBITSET_SIZE (dst);
 
+  unsigned i;
   for (i = 0; i < min (ssize, dsize); i++, dstp++, srcp++)
-      if (*dstp != (*srcp | *dstp))
-          return 0;
+    if (*dstp != (*srcp | *dstp))
+      return 0;
 
   if (ssize > dsize)
     {
@@ -485,15 +441,14 @@ vbitset_subset_p (bitset dst, bitset src)
 static bool
 vbitset_disjoint_p (bitset dst, bitset src)
 {
-  unsigned i;
   bitset_word *srcp = VBITSET_WORDS (src);
   bitset_word *dstp = VBITSET_WORDS (dst);
   bitset_windex ssize = VBITSET_SIZE (src);
   bitset_windex dsize = VBITSET_SIZE (dst);
 
-  for (i = 0; i < min (ssize, dsize); i++)
-      if (*srcp++ & *dstp++)
-          return 0;
+  for (unsigned i = 0; i < min (ssize, dsize); i++)
+    if (*srcp++ & *dstp++)
+      return 0;
 
   return 1;
 }
@@ -502,25 +457,17 @@ vbitset_disjoint_p (bitset dst, bitset src)
 static void
 vbitset_and (bitset dst, bitset src1, bitset src2)
 {
-  unsigned i;
-  bitset_word *src1p;
-  bitset_word *src2p;
-  bitset_word *dstp;
-  bitset_windex ssize1;
-  bitset_windex ssize2;
-  bitset_windex dsize;
-
   vbitset_resize (dst, max (BITSET_SIZE_ (src1), BITSET_SIZE_ (src2)));
 
-  dsize = VBITSET_SIZE (dst);
-  ssize1 = VBITSET_SIZE (src1);
-  ssize2 = VBITSET_SIZE (src2);
-  dstp = VBITSET_WORDS (dst);
-  src1p = VBITSET_WORDS (src1);
-  src2p = VBITSET_WORDS (src2);
+  bitset_windex dsize = VBITSET_SIZE (dst);
+  bitset_windex ssize1 = VBITSET_SIZE (src1);
+  bitset_windex ssize2 = VBITSET_SIZE (src2);
+  bitset_word *dstp = VBITSET_WORDS (dst);
+  bitset_word *src1p = VBITSET_WORDS (src1);
+  bitset_word *src2p = VBITSET_WORDS (src2);
 
-  for (i = 0; i < min (ssize1, ssize2); i++)
-      *dstp++ = *src1p++ & *src2p++;
+  for (unsigned i = 0; i < min (ssize1, ssize2); i++)
+    *dstp++ = *src1p++ & *src2p++;
 
   memset (dstp, 0, sizeof (bitset_word) * (dsize - min (ssize1, ssize2)));
 }
@@ -529,24 +476,17 @@ vbitset_and (bitset dst, bitset src1, bitset src2)
 static bool
 vbitset_and_cmp (bitset dst, bitset src1, bitset src2)
 {
-  unsigned i;
   int changed = 0;
-  bitset_word *src1p;
-  bitset_word *src2p;
-  bitset_word *dstp;
-  bitset_windex ssize1;
-  bitset_windex ssize2;
-  bitset_windex dsize;
-
   vbitset_resize (dst, max (BITSET_SIZE_ (src1), BITSET_SIZE_ (src2)));
 
-  dsize = VBITSET_SIZE (dst);
-  ssize1 = VBITSET_SIZE (src1);
-  ssize2 = VBITSET_SIZE (src2);
-  dstp = VBITSET_WORDS (dst);
-  src1p = VBITSET_WORDS (src1);
-  src2p = VBITSET_WORDS (src2);
+  bitset_windex dsize = VBITSET_SIZE (dst);
+  bitset_windex ssize1 = VBITSET_SIZE (src1);
+  bitset_windex ssize2 = VBITSET_SIZE (src2);
+  bitset_word *dstp = VBITSET_WORDS (dst);
+  bitset_word *src1p = VBITSET_WORDS (src1);
+  bitset_word *src2p = VBITSET_WORDS (src2);
 
+  unsigned i;
   for (i = 0; i < min (ssize1, ssize2); i++, dstp++)
     {
       bitset_word tmp = *src1p++ & *src2p++;
@@ -582,25 +522,18 @@ vbitset_and_cmp (bitset dst, bitset src1, bitset src2)
 static void
 vbitset_andn (bitset dst, bitset src1, bitset src2)
 {
-  unsigned i;
-  bitset_word *src1p;
-  bitset_word *src2p;
-  bitset_word *dstp;
-  bitset_windex ssize1;
-  bitset_windex ssize2;
-  bitset_windex dsize;
-
   vbitset_resize (dst, max (BITSET_SIZE_ (src1), BITSET_SIZE_ (src2)));
 
-  dsize = VBITSET_SIZE (dst);
-  ssize1 = VBITSET_SIZE (src1);
-  ssize2 = VBITSET_SIZE (src2);
-  dstp = VBITSET_WORDS (dst);
-  src1p = VBITSET_WORDS (src1);
-  src2p = VBITSET_WORDS (src2);
+  bitset_windex dsize = VBITSET_SIZE (dst);
+  bitset_windex ssize1 = VBITSET_SIZE (src1);
+  bitset_windex ssize2 = VBITSET_SIZE (src2);
+  bitset_word *dstp = VBITSET_WORDS (dst);
+  bitset_word *src1p = VBITSET_WORDS (src1);
+  bitset_word *src2p = VBITSET_WORDS (src2);
 
+  unsigned i;
   for (i = 0; i < min (ssize1, ssize2); i++)
-      *dstp++ = *src1p++ & ~(*src2p++);
+    *dstp++ = *src1p++ & ~(*src2p++);
 
   if (ssize2 > ssize1)
     {
@@ -622,24 +555,17 @@ vbitset_andn (bitset dst, bitset src1, bitset src2)
 static bool
 vbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 {
-  unsigned i;
   int changed = 0;
-  bitset_word *src1p;
-  bitset_word *src2p;
-  bitset_word *dstp;
-  bitset_windex ssize1;
-  bitset_windex ssize2;
-  bitset_windex dsize;
-
   vbitset_resize (dst, max (BITSET_SIZE_ (src1), BITSET_SIZE_ (src2)));
 
-  dsize = VBITSET_SIZE (dst);
-  ssize1 = VBITSET_SIZE (src1);
-  ssize2 = VBITSET_SIZE (src2);
-  dstp = VBITSET_WORDS (dst);
-  src1p = VBITSET_WORDS (src1);
-  src2p = VBITSET_WORDS (src2);
+  bitset_windex dsize = VBITSET_SIZE (dst);
+  bitset_windex ssize1 = VBITSET_SIZE (src1);
+  bitset_windex ssize2 = VBITSET_SIZE (src2);
+  bitset_word *dstp = VBITSET_WORDS (dst);
+  bitset_word *src1p = VBITSET_WORDS (src1);
+  bitset_word *src2p = VBITSET_WORDS (src2);
 
+  unsigned i;
   for (i = 0; i < min (ssize1, ssize2); i++, dstp++)
     {
       bitset_word tmp = *src1p++ & ~(*src2p++);
@@ -687,25 +613,18 @@ vbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 static void
 vbitset_or (bitset dst, bitset src1, bitset src2)
 {
-  unsigned i;
-  bitset_word *src1p;
-  bitset_word *src2p;
-  bitset_word *dstp;
-  bitset_windex ssize1;
-  bitset_windex ssize2;
-  bitset_windex dsize;
-
   vbitset_resize (dst, max (BITSET_SIZE_ (src1), BITSET_SIZE_ (src2)));
 
-  dsize = VBITSET_SIZE (dst);
-  ssize1 = VBITSET_SIZE (src1);
-  ssize2 = VBITSET_SIZE (src2);
-  dstp = VBITSET_WORDS (dst);
-  src1p = VBITSET_WORDS (src1);
-  src2p = VBITSET_WORDS (src2);
+  bitset_windex dsize = VBITSET_SIZE (dst);
+  bitset_windex ssize1 = VBITSET_SIZE (src1);
+  bitset_windex ssize2 = VBITSET_SIZE (src2);
+  bitset_word *dstp = VBITSET_WORDS (dst);
+  bitset_word *src1p = VBITSET_WORDS (src1);
+  bitset_word *src2p = VBITSET_WORDS (src2);
 
+  unsigned i;
   for (i = 0; i < min (ssize1, ssize2); i++)
-      *dstp++ = *src1p++ | *src2p++;
+    *dstp++ = *src1p++ | *src2p++;
 
   if (ssize2 > ssize1)
     {
@@ -723,24 +642,18 @@ vbitset_or (bitset dst, bitset src1, bitset src2)
 static bool
 vbitset_or_cmp (bitset dst, bitset src1, bitset src2)
 {
-  unsigned i;
   int changed = 0;
-  bitset_word *src1p;
-  bitset_word *src2p;
-  bitset_word *dstp;
-  bitset_windex ssize1;
-  bitset_windex ssize2;
-  bitset_windex dsize;
 
   vbitset_resize (dst, max (BITSET_SIZE_ (src1), BITSET_SIZE_ (src2)));
 
-  dsize = VBITSET_SIZE (dst);
-  ssize1 = VBITSET_SIZE (src1);
-  ssize2 = VBITSET_SIZE (src2);
-  dstp = VBITSET_WORDS (dst);
-  src1p = VBITSET_WORDS (src1);
-  src2p = VBITSET_WORDS (src2);
+  bitset_windex dsize = VBITSET_SIZE (dst);
+  bitset_windex ssize1 = VBITSET_SIZE (src1);
+  bitset_windex ssize2 = VBITSET_SIZE (src2);
+  bitset_word *dstp = VBITSET_WORDS (dst);
+  bitset_word *src1p = VBITSET_WORDS (src1);
+  bitset_word *src2p = VBITSET_WORDS (src2);
 
+  unsigned i;
   for (i = 0; i < min (ssize1, ssize2); i++, dstp++)
     {
       bitset_word tmp = *src1p++ | *src2p++;
@@ -778,25 +691,18 @@ vbitset_or_cmp (bitset dst, bitset src1, bitset src2)
 static void
 vbitset_xor (bitset dst, bitset src1, bitset src2)
 {
-  unsigned i;
-  bitset_word *src1p;
-  bitset_word *src2p;
-  bitset_word *dstp;
-  bitset_windex ssize1;
-  bitset_windex ssize2;
-  bitset_windex dsize;
-
   vbitset_resize (dst, max (BITSET_SIZE_ (src1), BITSET_SIZE_ (src2)));
 
-  dsize = VBITSET_SIZE (dst);
-  ssize1 = VBITSET_SIZE (src1);
-  ssize2 = VBITSET_SIZE (src2);
-  dstp = VBITSET_WORDS (dst);
-  src1p = VBITSET_WORDS (src1);
-  src2p = VBITSET_WORDS (src2);
+  bitset_windex dsize = VBITSET_SIZE (dst);
+  bitset_windex ssize1 = VBITSET_SIZE (src1);
+  bitset_windex ssize2 = VBITSET_SIZE (src2);
+  bitset_word *dstp = VBITSET_WORDS (dst);
+  bitset_word *src1p = VBITSET_WORDS (src1);
+  bitset_word *src2p = VBITSET_WORDS (src2);
 
+  unsigned i;
   for (i = 0; i < min (ssize1, ssize2); i++)
-      *dstp++ = *src1p++ ^ *src2p++;
+    *dstp++ = *src1p++ ^ *src2p++;
 
   if (ssize2 > ssize1)
     {
@@ -814,24 +720,17 @@ vbitset_xor (bitset dst, bitset src1, bitset src2)
 static bool
 vbitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 {
-  unsigned i;
   int changed = 0;
-  bitset_word *src1p;
-  bitset_word *src2p;
-  bitset_word *dstp;
-  bitset_windex ssize1;
-  bitset_windex ssize2;
-  bitset_windex dsize;
-
   vbitset_resize (dst, max (BITSET_SIZE_ (src1), BITSET_SIZE_ (src2)));
 
-  dsize = VBITSET_SIZE (dst);
-  ssize1 = VBITSET_SIZE (src1);
-  ssize2 = VBITSET_SIZE (src2);
-  dstp = VBITSET_WORDS (dst);
-  src1p = VBITSET_WORDS (src1);
-  src2p = VBITSET_WORDS (src2);
+  bitset_windex dsize = VBITSET_SIZE (dst);
+  bitset_windex ssize1 = VBITSET_SIZE (src1);
+  bitset_windex ssize2 = VBITSET_SIZE (src2);
+  bitset_word *dstp = VBITSET_WORDS (dst);
+  bitset_word *src1p = VBITSET_WORDS (src1);
+  bitset_word *src2p = VBITSET_WORDS (src2);
 
+  unsigned i;
   for (i = 0; i < min (ssize1, ssize2); i++, dstp++)
     {
       bitset_word tmp = *src1p++ ^ *src2p++;
@@ -872,7 +771,6 @@ vbitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 static void
 vbitset_and_or (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  unsigned i;
   bitset_word *src1p;
   bitset_word *src2p;
   bitset_word *src3p;
@@ -894,15 +792,14 @@ vbitset_and_or (bitset dst, bitset src1, bitset src2, bitset src3)
   dstp = VBITSET_WORDS (dst);
   size = VBITSET_SIZE (dst);
 
-  for (i = 0; i < size; i++)
-      *dstp++ = (*src1p++ & *src2p++) | *src3p++;
+  for (unsigned i = 0; i < size; i++)
+    *dstp++ = (*src1p++ & *src2p++) | *src3p++;
 }
 
 
 static bool
 vbitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  unsigned i;
   int changed = 0;
   bitset_word *src1p;
   bitset_word *src2p;
@@ -922,7 +819,7 @@ vbitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
   dstp = VBITSET_WORDS (dst);
   size = VBITSET_SIZE (dst);
 
-  for (i = 0; i < size; i++, dstp++)
+  for (unsigned i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ & *src2p++) | *src3p++;
 
@@ -939,7 +836,6 @@ vbitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 static void
 vbitset_andn_or (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  unsigned i;
   bitset_word *src1p;
   bitset_word *src2p;
   bitset_word *src3p;
@@ -961,15 +857,14 @@ vbitset_andn_or (bitset dst, bitset src1, bitset src2, bitset src3)
   dstp = VBITSET_WORDS (dst);
   size = VBITSET_SIZE (dst);
 
-  for (i = 0; i < size; i++)
-      *dstp++ = (*src1p++ & ~(*src2p++)) | *src3p++;
+  for (unsigned i = 0; i < size; i++)
+    *dstp++ = (*src1p++ & ~(*src2p++)) | *src3p++;
 }
 
 
 static bool
 vbitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  unsigned i;
   int changed = 0;
   bitset_word *src1p;
   bitset_word *src2p;
@@ -989,7 +884,7 @@ vbitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
   dstp = VBITSET_WORDS (dst);
   size = VBITSET_SIZE (dst);
 
-  for (i = 0; i < size; i++, dstp++)
+  for (unsigned i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ & ~(*src2p++)) | *src3p++;
 
@@ -1006,13 +901,6 @@ vbitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 static void
 vbitset_or_and (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  unsigned i;
-  bitset_word *src1p;
-  bitset_word *src2p;
-  bitset_word *src3p;
-  bitset_word *dstp;
-  bitset_windex size;
-
   if (BITSET_NBITS_ (src1) != BITSET_NBITS_ (src2)
       || BITSET_NBITS_ (src1) != BITSET_NBITS_ (src3))
     {
@@ -1022,14 +910,14 @@ vbitset_or_and (bitset dst, bitset src1, bitset src2, bitset src3)
 
   vbitset_resize (dst, BITSET_NBITS_ (src1));
 
-  src1p = VBITSET_WORDS (src1);
-  src2p = VBITSET_WORDS (src2);
-  src3p = VBITSET_WORDS (src3);
-  dstp = VBITSET_WORDS (dst);
-  size = VBITSET_SIZE (dst);
+  bitset_word *src1p = VBITSET_WORDS (src1);
+  bitset_word *src2p = VBITSET_WORDS (src2);
+  bitset_word *src3p = VBITSET_WORDS (src3);
+  bitset_word *dstp = VBITSET_WORDS (dst);
+  bitset_windex size = VBITSET_SIZE (dst);
 
-  for (i = 0; i < size; i++)
-      *dstp++ = (*src1p++ | *src2p++) & *src3p++;
+  for (unsigned i = 0; i < size; i++)
+    *dstp++ = (*src1p++ | *src2p++) & *src3p++;
 }
 
 
@@ -1119,17 +1007,14 @@ struct bitset_vtable vbitset_vtable = {
 
 
 size_t
-vbitset_bytes (n_bits)
-     bitset_bindex n_bits ATTRIBUTE_UNUSED;
+vbitset_bytes (bitset_bindex n_bits ATTRIBUTE_UNUSED)
 {
   return sizeof (struct vbitset_struct);
 }
 
 
 bitset
-vbitset_init (bset, n_bits)
-     bitset bset;
-     bitset_bindex n_bits;
+vbitset_init (bitset bset, bitset_bindex n_bits)
 {
   bset->b.vtable = &vbitset_vtable;
 
