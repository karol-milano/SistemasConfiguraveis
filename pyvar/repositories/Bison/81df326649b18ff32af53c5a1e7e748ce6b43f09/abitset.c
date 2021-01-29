@@ -35,7 +35,7 @@
 static bitset_bindex
 abitset_resize (bitset src, bitset_bindex size)
 {
-    /* These bitsets have a fixed size.  */
+  /* These bitsets have a fixed size.  */
   if (BITSET_SIZE_ (src) != size)
     abort ();
 
@@ -43,8 +43,8 @@ abitset_resize (bitset src, bitset_bindex size)
 }
 
 /* Find list of up to NUM bits set in BSET starting from and including
- *NEXT and store in array LIST.  Return with actual number of bits
- found and with *NEXT indicating where search stopped.  */
+   *NEXT and store in array LIST.  Return with actual number of bits
+   found and with *NEXT indicating where search stopped.  */
 static bitset_bindex
 abitset_small_list (bitset src, bitset_bindex *list,
                     bitset_bindex num, bitset_bindex *next)
@@ -138,11 +138,10 @@ static bitset_bindex
 abitset_list_reverse (bitset src, bitset_bindex *list,
                       bitset_bindex num, bitset_bindex *next)
 {
+  bitset_bindex rbitno = *next;
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_bindex n_bits = BITSET_SIZE_ (src);
 
-  bitset_bindex rbitno = *next;
-
   /* If num is 1, we could speed things up with a binary search
      of the word of interest.  */
 
@@ -194,7 +193,6 @@ abitset_list (bitset src, bitset_bindex *list,
   bitset_bindex bitoff;
   bitset_windex size = src->b.csize;
   bitset_word *srcp = ABITSET_WORDS (src);
-  bitset_word word;
 
   bitset_bindex bitno = *next;
 
@@ -228,7 +226,7 @@ abitset_list (bitset src, bitset_bindex *list,
              on the previous call to this function.  */
 
           bitoff = windex * BITSET_WORD_BITS;
-          word = srcp[windex] >> bitno;
+          bitset_word word = srcp[windex] >> bitno;
           for (bitno = bitoff + bitno; word; bitno++)
             {
               if (word & 1)
@@ -249,7 +247,8 @@ abitset_list (bitset src, bitset_bindex *list,
 
   for (; windex < size; windex++, bitoff += BITSET_WORD_BITS)
     {
-      if (!(word = srcp[windex]))
+      bitset_word word = srcp[windex];
+      if (!word)
         continue;
 
       if ((count + BITSET_WORD_BITS) < num)
@@ -324,7 +323,6 @@ abitset_empty_p (bitset dst)
   for (bitset_windex i = 0; i < dst->b.csize; i++)
     if (dstp[i])
       return false;
-
   return true;
 }
 
@@ -334,10 +332,9 @@ abitset_copy1 (bitset dst, bitset src)
 {
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_word *dstp = ABITSET_WORDS (dst);
-  bitset_windex size = dst->b.csize;
-
   if (srcp == dstp)
-      return;
+    return;
+  bitset_windex size = dst->b.csize;
   memcpy (dstp, srcp, sizeof (bitset_word) * size);
 }
 
@@ -393,7 +390,6 @@ abitset_disjoint_p (bitset dst, bitset src)
   for (bitset_windex i = 0; i < size; i++)
     if (*srcp++ & *dstp++)
       return false;
-
   return true;
 }
 
@@ -423,7 +419,6 @@ abitset_and_cmp (bitset dst, bitset src1, bitset src2)
   for (bitset_windex i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = *src1p++ & *src2p++;
-
       if (*dstp != tmp)
         {
           changed = true;
@@ -459,7 +454,6 @@ abitset_andn_cmp (bitset dst, bitset src1, bitset src2)
   for (bitset_windex i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = *src1p++ & ~(*src2p++);
-
       if (*dstp != tmp)
         {
           changed = true;
@@ -515,7 +509,7 @@ abitset_xor (bitset dst, bitset src1, bitset src2)
   bitset_windex size = dst->b.csize;
 
   for (bitset_windex i = 0; i < size; i++)
-      *dstp++ = *src1p++ ^ *src2p++;
+    *dstp++ = *src1p++ ^ *src2p++;
 }
 
 
@@ -569,7 +563,6 @@ abitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
   for (bitset_windex i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ & *src2p++) | *src3p++;
-
       if (*dstp != tmp)
         {
           changed = true;
@@ -607,7 +600,6 @@ abitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
   for (bitset_windex i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ & ~(*src2p++)) | *src3p++;
-
       if (*dstp != tmp)
         {
           changed = true;
@@ -645,7 +637,6 @@ abitset_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
   for (bitset_windex i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ | *src2p++) & *src3p++;
-
       if (*dstp != tmp)
         {
           changed = true;
@@ -773,11 +764,7 @@ abitset_init (bitset bset, bitset_bindex n_bits)
   /* Use optimized routines if bitset fits within a single word.
      There is probably little merit if using caching since
      the small bitset will always fit in the cache.  */
-  if (size == 1)
-    bset->b.vtable = &abitset_small_vtable;
-  else
-    bset->b.vtable = &abitset_vtable;
-
+  bset->b.vtable = size == 1 ? &abitset_small_vtable : &abitset_vtable;
   bset->b.cindex = 0;
   bset->b.csize = size;
   bset->b.cdata = ABITSET_WORDS (bset);
