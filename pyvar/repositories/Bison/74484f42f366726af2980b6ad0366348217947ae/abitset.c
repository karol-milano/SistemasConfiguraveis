@@ -36,10 +36,10 @@ static bitset_bindex
 abitset_resize (bitset src, bitset_bindex size)
 {
     /* These bitsets have a fixed size.  */
-    if (BITSET_SIZE_ (src) != size)
-      abort ();
+  if (BITSET_SIZE_ (src) != size)
+    abort ();
 
-    return size;
+  return size;
 }
 
 /* Find list of up to NUM bits set in BSET starting from and including
@@ -49,19 +49,14 @@ static bitset_bindex
 abitset_small_list (bitset src, bitset_bindex *list,
                     bitset_bindex num, bitset_bindex *next)
 {
-  bitset_bindex bitno;
-  bitset_bindex count;
-  bitset_windex size;
-  bitset_word word;
-
-  word = ABITSET_WORDS (src)[0];
+  bitset_word word = ABITSET_WORDS (src)[0];
 
   /* Short circuit common case.  */
   if (!word)
     return 0;
 
-  size = BITSET_SIZE_ (src);
-  bitno = *next;
+  bitset_windex size = BITSET_SIZE_ (src);
+  bitset_bindex bitno = *next;
   if (bitno >= size)
     return 0;
 
@@ -70,6 +65,7 @@ abitset_small_list (bitset src, bitset_bindex *list,
   /* If num is 1, we could speed things up with a binary search
      of the word of interest.  */
 
+  bitset_bindex count;
   if (num >= BITSET_WORD_BITS)
     {
       for (count = 0; word; bitno++)
@@ -142,16 +138,10 @@ static bitset_bindex
 abitset_list_reverse (bitset src, bitset_bindex *list,
                       bitset_bindex num, bitset_bindex *next)
 {
-  bitset_bindex bitno;
-  bitset_bindex rbitno;
-  bitset_bindex count;
-  bitset_windex windex;
-  unsigned bitcnt;
-  bitset_bindex bitoff;
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_bindex n_bits = BITSET_SIZE_ (src);
 
-  rbitno = *next;
+  bitset_bindex rbitno = *next;
 
   /* If num is 1, we could speed things up with a binary search
      of the word of interest.  */
@@ -159,19 +149,17 @@ abitset_list_reverse (bitset src, bitset_bindex *list,
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
@@ -196,23 +184,21 @@ abitset_list_reverse (bitset src, bitset_bindex *list,
 
 
 /* Find list of up to NUM bits set in BSET starting from and including
- *NEXT and store in array LIST.  Return with actual number of bits
- found and with *NEXT indicating where search stopped.  */
+   *NEXT and store in array LIST.  Return with actual number of bits
+   found and with *NEXT indicating where search stopped.  */
 static bitset_bindex
 abitset_list (bitset src, bitset_bindex *list,
               bitset_bindex num, bitset_bindex *next)
 {
-  bitset_bindex bitno;
-  bitset_bindex count;
   bitset_windex windex;
   bitset_bindex bitoff;
   bitset_windex size = src->b.csize;
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_word word;
 
-  bitno = *next;
+  bitset_bindex bitno = *next;
 
-  count = 0;
+  bitset_bindex count = 0;
   if (!bitno)
     {
       /* Many bitsets are zero, so make this common case fast.  */
@@ -302,9 +288,7 @@ abitset_list (bitset src, bitset_bindex *list,
 static inline void
 abitset_unused_clear (bitset dst)
 {
-  unsigned last_bit;
-
-  last_bit = BITSET_SIZE_ (dst) % BITSET_WORD_BITS;
+  unsigned last_bit = BITSET_SIZE_ (dst) % BITSET_WORD_BITS;
   if (last_bit)
     ABITSET_WORDS (dst)[dst->b.csize - 1] &=
       ((bitset_word) 1 << last_bit) - 1;
@@ -315,9 +299,7 @@ static void
 abitset_ones (bitset dst)
 {
   bitset_word *dstp = ABITSET_WORDS (dst);
-  size_t bytes;
-
-  bytes = sizeof (bitset_word) * dst->b.csize;
+  size_t bytes = sizeof (bitset_word) * dst->b.csize;
 
   memset (dstp, -1, bytes);
   abitset_unused_clear (dst);
@@ -328,9 +310,7 @@ static void
 abitset_zero (bitset dst)
 {
   bitset_word *dstp = ABITSET_WORDS (dst);
-  size_t bytes;
-
-  bytes = sizeof (bitset_word) * dst->b.csize;
+  size_t bytes = sizeof (bitset_word) * dst->b.csize;
 
   memset (dstp, 0, bytes);
 }
@@ -339,10 +319,9 @@ abitset_zero (bitset dst)
 static bool
 abitset_empty_p (bitset dst)
 {
-  bitset_windex i;
   bitset_word *dstp = ABITSET_WORDS (dst);
 
-  for (i = 0; i < dst->b.csize; i++)
+  for (bitset_windex i = 0; i < dst->b.csize; i++)
     if (dstp[i])
       return false;
 
@@ -366,13 +345,12 @@ abitset_copy1 (bitset dst, bitset src)
 static void
 abitset_not (bitset dst, bitset src)
 {
-  bitset_windex i;
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++)
-      *dstp++ = ~(*srcp++);
+  for (bitset_windex i = 0; i < size; i++)
+    *dstp++ = ~(*srcp++);
   abitset_unused_clear (dst);
 }
 
@@ -380,14 +358,13 @@ abitset_not (bitset dst, bitset src)
 static bool
 abitset_equal_p (bitset dst, bitset src)
 {
-  bitset_windex i;
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++)
-      if (*srcp++ != *dstp++)
-          return false;
+  for (bitset_windex i = 0; i < size; i++)
+    if (*srcp++ != *dstp++)
+      return false;
   return true;
 }
 
@@ -395,14 +372,13 @@ abitset_equal_p (bitset dst, bitset src)
 static bool
 abitset_subset_p (bitset dst, bitset src)
 {
-  bitset_windex i;
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++, dstp++, srcp++)
-      if (*dstp != (*srcp | *dstp))
-          return false;
+  for (bitset_windex i = 0; i < size; i++, dstp++, srcp++)
+    if (*dstp != (*srcp | *dstp))
+      return false;
   return true;
 }
 
@@ -410,14 +386,13 @@ abitset_subset_p (bitset dst, bitset src)
 static bool
 abitset_disjoint_p (bitset dst, bitset src)
 {
-  bitset_windex i;
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++)
-      if (*srcp++ & *dstp++)
-          return false;
+  for (bitset_windex i = 0; i < size; i++)
+    if (*srcp++ & *dstp++)
+      return false;
 
   return true;
 }
@@ -426,28 +401,26 @@ abitset_disjoint_p (bitset dst, bitset src)
 static void
 abitset_and (bitset dst, bitset src1, bitset src2)
 {
-  bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++)
-      *dstp++ = *src1p++ & *src2p++;
+  for (bitset_windex i = 0; i < size; i++)
+    *dstp++ = *src1p++ & *src2p++;
 }
 
 
 static bool
 abitset_and_cmp (bitset dst, bitset src1, bitset src2)
 {
-  bitset_windex i;
   bool changed = false;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++, dstp++)
+  for (bitset_windex i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = *src1p++ & *src2p++;
 
@@ -464,28 +437,26 @@ abitset_and_cmp (bitset dst, bitset src1, bitset src2)
 static void
 abitset_andn (bitset dst, bitset src1, bitset src2)
 {
-  bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++)
-      *dstp++ = *src1p++ & ~(*src2p++);
+  for (bitset_windex i = 0; i < size; i++)
+    *dstp++ = *src1p++ & ~(*src2p++);
 }
 
 
 static bool
 abitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 {
-  bitset_windex i;
   bool changed = false;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++, dstp++)
+  for (bitset_windex i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = *src1p++ & ~(*src2p++);
 
@@ -502,28 +473,26 @@ abitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 static void
 abitset_or (bitset dst, bitset src1, bitset src2)
 {
-  bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++)
-      *dstp++ = *src1p++ | *src2p++;
+  for (bitset_windex i = 0; i < size; i++)
+    *dstp++ = *src1p++ | *src2p++;
 }
 
 
 static bool
 abitset_or_cmp (bitset dst, bitset src1, bitset src2)
 {
-  bitset_windex i;
   bool changed = false;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++, dstp++)
+  for (bitset_windex i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = *src1p++ | *src2p++;
 
@@ -540,13 +509,12 @@ abitset_or_cmp (bitset dst, bitset src1, bitset src2)
 static void
 abitset_xor (bitset dst, bitset src1, bitset src2)
 {
-  bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++)
+  for (bitset_windex i = 0; i < size; i++)
       *dstp++ = *src1p++ ^ *src2p++;
 }
 
@@ -554,14 +522,13 @@ abitset_xor (bitset dst, bitset src1, bitset src2)
 static bool
 abitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 {
-  bitset_windex i;
   bool changed = false;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++, dstp++)
+  for (bitset_windex i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = *src1p++ ^ *src2p++;
 
@@ -578,22 +545,20 @@ abitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 static void
 abitset_and_or (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *src3p = ABITSET_WORDS (src3);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++)
-      *dstp++ = (*src1p++ & *src2p++) | *src3p++;
+  for (bitset_windex i = 0; i < size; i++)
+    *dstp++ = (*src1p++ & *src2p++) | *src3p++;
 }
 
 
 static bool
 abitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  bitset_windex i;
   bool changed = false;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
@@ -601,7 +566,7 @@ abitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++, dstp++)
+  for (bitset_windex i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ & *src2p++) | *src3p++;
 
@@ -618,22 +583,20 @@ abitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 static void
 abitset_andn_or (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *src3p = ABITSET_WORDS (src3);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++)
-      *dstp++ = (*src1p++ & ~(*src2p++)) | *src3p++;
+  for (bitset_windex i = 0; i < size; i++)
+    *dstp++ = (*src1p++ & ~(*src2p++)) | *src3p++;
 }
 
 
 static bool
 abitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  bitset_windex i;
   bool changed = false;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
@@ -641,7 +604,7 @@ abitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++, dstp++)
+  for (bitset_windex i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ & ~(*src2p++)) | *src3p++;
 
@@ -658,22 +621,20 @@ abitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 static void
 abitset_or_and (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *src3p = ABITSET_WORDS (src3);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++)
-      *dstp++ = (*src1p++ | *src2p++) & *src3p++;
+  for (bitset_windex i = 0; i < size; i++)
+    *dstp++ = (*src1p++ | *src2p++) & *src3p++;
 }
 
 
 static bool
 abitset_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  bitset_windex i;
   bool changed = false;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
@@ -681,7 +642,7 @@ abitset_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  for (i = 0; i < size; i++, dstp++)
+  for (bitset_windex i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ | *src2p++) & *src3p++;
 
@@ -699,9 +660,9 @@ static void
 abitset_copy (bitset dst, bitset src)
 {
   if (BITSET_COMPATIBLE_ (dst, src))
-      abitset_copy1 (dst, src);
+    abitset_copy1 (dst, src);
   else
-      bitset_copy_ (dst, src);
+    bitset_copy_ (dst, src);
 }
 
 
@@ -784,14 +745,12 @@ struct bitset_vtable abitset_vtable = {
 size_t
 abitset_bytes (bitset_bindex n_bits)
 {
-  bitset_windex size;
-  size_t bytes;
   size_t header_size = offsetof (union bitset_union, a.words);
   struct bitset_align_struct { char a; union bitset_union b; };
   size_t bitset_alignment = offsetof (struct bitset_align_struct, b);
 
-  size = ABITSET_N_WORDS (n_bits);
-  bytes = header_size + size * sizeof (bitset_word);
+  bitset_windex size = ABITSET_N_WORDS (n_bits);
+  size_t bytes = header_size + size * sizeof (bitset_word);
 
   /* Align the size properly for a vector of abitset objects.  */
   if (header_size % bitset_alignment != 0
@@ -808,9 +767,7 @@ abitset_bytes (bitset_bindex n_bits)
 bitset
 abitset_init (bitset bset, bitset_bindex n_bits)
 {
-  bitset_windex size;
-
-  size = ABITSET_N_WORDS (n_bits);
+  bitset_windex size = ABITSET_N_WORDS (n_bits);
   BITSET_NBITS_ (bset) = n_bits;
 
   /* Use optimized routines if bitset fits within a single word.
