@@ -30,7 +30,7 @@
 
 typedef struct abitset_struct
 {
-  unsigned int n_bits;	/* Number of bits.  */
+  bitset_bindex n_bits;	/* Number of bits.  */
   bitset_word words[1];	/* The array of bits.  */
 }
 *abitset;
@@ -44,16 +44,17 @@ struct bitset_struct
 
 static void abitset_unused_clear PARAMS ((bitset));
 
-static int abitset_small_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
-				       bitset_bindex *));
+static bitset_bindex abitset_small_list PARAMS ((bitset, bitset_bindex *,
+						 bitset_bindex,
+						 bitset_bindex *));
 
 static void abitset_set PARAMS ((bitset, bitset_bindex));
 static void abitset_reset PARAMS ((bitset, bitset_bindex));
 static int abitset_test PARAMS ((bitset, bitset_bindex));
-static int abitset_size PARAMS ((bitset));
-static int abitset_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
-				 bitset_bindex *));
-static int abitset_list_reverse
+static bitset_bindex abitset_size PARAMS ((bitset));
+static bitset_bindex abitset_list PARAMS ((bitset, bitset_bindex *,
+					   bitset_bindex, bitset_bindex *));
+static bitset_bindex abitset_list_reverse
 PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
 
 #define ABITSET_N_WORDS(N) (((N) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS)
@@ -62,7 +63,7 @@ PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
 
 
 /* Return size in bits of bitset SRC.  */
-static int
+static bitset_bindex
 abitset_size (src)
      bitset src;
 {
@@ -73,7 +74,7 @@ abitset_size (src)
 /* Find list of up to NUM bits set in BSET starting from and including
  *NEXT and store in array LIST.  Return with actual number of bits
  found and with *NEXT indicating where search stopped.  */
-static int
+static bitset_bindex
 abitset_small_list (src, list, num, next)
      bitset src;
      bitset_bindex *list;
@@ -173,7 +174,7 @@ abitset_test (src, bitno)
    from and including NEXT and store in array LIST.  Return with
    actual number of bits found and with *NEXT indicating where search
    stopped.  */
-static int
+static bitset_bindex
 abitset_list_reverse (src, list, num, next)
      bitset src;
      bitset_bindex *list;
@@ -236,7 +237,7 @@ abitset_list_reverse (src, list, num, next)
 /* Find list of up to NUM bits set in BSET starting from and including
  *NEXT and store in array LIST.  Return with actual number of bits
  found and with *NEXT indicating where search stopped.  */
-static int
+static bitset_bindex
 abitset_list (src, list, num, next)
      bitset src;
      bitset_bindex *list;
@@ -358,7 +359,7 @@ abitset_ones (dst)
      bitset dst;
 {
   bitset_word *dstp = ABITSET_WORDS (dst);
-  unsigned int bytes;
+  size_t bytes;
 
   bytes = sizeof (bitset_word) * dst->b.csize;
 
@@ -372,7 +373,7 @@ abitset_zero (dst)
      bitset dst;
 {
   bitset_word *dstp = ABITSET_WORDS (dst);
-  unsigned int bytes;
+  size_t bytes;
 
   bytes = sizeof (bitset_word) * dst->b.csize;
 
@@ -384,7 +385,7 @@ static int
 abitset_empty_p (dst)
      bitset dst;
 {
-  unsigned int i;
+  bitset_windex i;
   bitset_word *dstp = ABITSET_WORDS (dst);
 
   for (i = 0; i < dst->b.csize; i++)
@@ -415,7 +416,7 @@ abitset_not (dst, src)
      bitset dst;
      bitset src;
 {
-  unsigned int i;
+  bitset_windex i;
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
@@ -431,7 +432,7 @@ abitset_equal_p (dst, src)
      bitset dst;
      bitset src;
 {
-  unsigned int i;
+  bitset_windex i;
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
@@ -448,7 +449,7 @@ abitset_subset_p (dst, src)
      bitset dst;
      bitset src;
 {
-  unsigned int i;
+  bitset_windex i;
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
@@ -465,7 +466,7 @@ abitset_disjoint_p (dst, src)
      bitset dst;
      bitset src;
 {
-  unsigned int i;
+  bitset_windex i;
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
@@ -484,7 +485,7 @@ abitset_and (dst, src1, src2)
      bitset src1;
      bitset src2;
 {
-  unsigned int i;
+  bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
@@ -501,7 +502,7 @@ abitset_and_cmp (dst, src1, src2)
      bitset src1;
      bitset src2;
 {
-  unsigned int i;
+  bitset_windex i;
   int changed = 0;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
@@ -528,7 +529,7 @@ abitset_andn (dst, src1, src2)
      bitset src1;
      bitset src2;
 {
-  unsigned int i;
+  bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
@@ -545,7 +546,7 @@ abitset_andn_cmp (dst, src1, src2)
      bitset src1;
      bitset src2;
 {
-  unsigned int i;
+  bitset_windex i;
   int changed = 0;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
@@ -572,7 +573,7 @@ abitset_or (dst, src1, src2)
      bitset src1;
      bitset src2;
 {
-  unsigned int i;
+  bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
@@ -589,7 +590,7 @@ abitset_or_cmp (dst, src1, src2)
      bitset src1;
      bitset src2;
 {
-  unsigned int i;
+  bitset_windex i;
   int changed = 0;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
@@ -616,7 +617,7 @@ abitset_xor (dst, src1, src2)
      bitset src1;
      bitset src2;
 {
-  unsigned int i;
+  bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
@@ -633,7 +634,7 @@ abitset_xor_cmp (dst, src1, src2)
      bitset src1;
      bitset src2;
 {
-  unsigned int i;
+  bitset_windex i;
   int changed = 0;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
@@ -661,7 +662,7 @@ abitset_and_or (dst, src1, src2, src3)
      bitset src2;
      bitset src3;
 {
-  unsigned int i;
+  bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *src3p = ABITSET_WORDS (src3);
@@ -680,7 +681,7 @@ abitset_and_or_cmp (dst, src1, src2, src3)
      bitset src2;
      bitset src3;
 {
-  unsigned int i;
+  bitset_windex i;
   int changed = 0;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
@@ -709,7 +710,7 @@ abitset_andn_or (dst, src1, src2, src3)
      bitset src2;
      bitset src3;
 {
-  unsigned int i;
+  bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *src3p = ABITSET_WORDS (src3);
@@ -728,7 +729,7 @@ abitset_andn_or_cmp (dst, src1, src2, src3)
      bitset src2;
      bitset src3;
 {
-  unsigned int i;
+  bitset_windex i;
   int changed = 0;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
@@ -757,7 +758,7 @@ abitset_or_and (dst, src1, src2, src3)
      bitset src2;
      bitset src3;
 {
-  unsigned int i;
+  bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *src3p = ABITSET_WORDS (src3);
@@ -776,7 +777,7 @@ abitset_or_and_cmp (dst, src1, src2, src3)
      bitset src2;
      bitset src3;
 {
-  unsigned int i;
+  bitset_windex i;
   int changed = 0;
   bitset_word *src1p = ABITSET_WORDS (src1);
   bitset_word *src2p = ABITSET_WORDS (src2);
@@ -884,11 +885,12 @@ struct bitset_vtable abitset_vtable = {
 };
 
 
-int
+size_t
 abitset_bytes (n_bits)
      bitset_bindex n_bits;
 {
-  unsigned int bytes, size;
+  bitset_windex size;
+  size_t bytes;
 
   size = ABITSET_N_WORDS (n_bits);
   bytes = size * sizeof (bitset_word);
