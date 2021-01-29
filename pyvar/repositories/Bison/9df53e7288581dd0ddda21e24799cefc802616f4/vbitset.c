@@ -170,7 +170,7 @@ vbitset_list_reverse (src, list, num, next)
   bitset_bindex rbitno;
   bitset_bindex count;
   bitset_windex windex;
-  unsigned int bitcnt;
+  unsigned bitcnt;
   bitset_bindex bitoff;
   bitset_word *srcp = VBITSET_WORDS (src);
   bitset_bindex n_bits = BITSET_SIZE_ (src);
@@ -330,7 +330,7 @@ static inline void
 vbitset_unused_clear (dst)
      bitset dst;
 {
-  unsigned int last_bit;
+  unsigned last_bit;
 
   last_bit = BITSET_SIZE_ (dst) % BITSET_WORD_BITS;
   if (last_bit)
@@ -343,7 +343,7 @@ static void
 vbitset_ones (bitset dst)
 {
   bitset_word *dstp = VBITSET_WORDS (dst);
-  unsigned int bytes;
+  unsigned bytes;
 
   bytes = sizeof (bitset_word) * VBITSET_SIZE (dst);
 
@@ -356,7 +356,7 @@ static void
 vbitset_zero (bitset dst)
 {
   bitset_word *dstp = VBITSET_WORDS (dst);
-  unsigned int bytes;
+  unsigned bytes;
 
   bytes = sizeof (bitset_word) * VBITSET_SIZE (dst);
 
@@ -367,7 +367,7 @@ vbitset_zero (bitset dst)
 static bool
 vbitset_empty_p (bitset dst)
 {
-  unsigned int i;
+  unsigned i;
   bitset_word *dstp = VBITSET_WORDS (dst);
 
   for (i = 0; i < VBITSET_SIZE (dst); i++)
@@ -406,7 +406,7 @@ vbitset_copy1 (bitset dst, bitset src)
 static void
 vbitset_not (bitset dst, bitset src)
 {
-  unsigned int i;
+  unsigned i;
   bitset_word *srcp;
   bitset_word *dstp;
   bitset_windex ssize;
@@ -431,7 +431,7 @@ vbitset_not (bitset dst, bitset src)
 static bool
 vbitset_equal_p (bitset dst, bitset src)
 {
-  unsigned int i;
+  unsigned i;
   bitset_word *srcp = VBITSET_WORDS (src);
   bitset_word *dstp = VBITSET_WORDS (dst);
   bitset_windex ssize = VBITSET_SIZE (src);
@@ -461,7 +461,7 @@ vbitset_equal_p (bitset dst, bitset src)
 static bool
 vbitset_subset_p (bitset dst, bitset src)
 {
-  unsigned int i;
+  unsigned i;
   bitset_word *srcp = VBITSET_WORDS (src);
   bitset_word *dstp = VBITSET_WORDS (dst);
   bitset_windex ssize = VBITSET_SIZE (src);
@@ -485,7 +485,7 @@ vbitset_subset_p (bitset dst, bitset src)
 static bool
 vbitset_disjoint_p (bitset dst, bitset src)
 {
-  unsigned int i;
+  unsigned i;
   bitset_word *srcp = VBITSET_WORDS (src);
   bitset_word *dstp = VBITSET_WORDS (dst);
   bitset_windex ssize = VBITSET_SIZE (src);
@@ -502,7 +502,7 @@ vbitset_disjoint_p (bitset dst, bitset src)
 static void
 vbitset_and (bitset dst, bitset src1, bitset src2)
 {
-  unsigned int i;
+  unsigned i;
   bitset_word *src1p;
   bitset_word *src2p;
   bitset_word *dstp;
@@ -529,7 +529,7 @@ vbitset_and (bitset dst, bitset src1, bitset src2)
 static bool
 vbitset_and_cmp (bitset dst, bitset src1, bitset src2)
 {
-  unsigned int i;
+  unsigned i;
   int changed = 0;
   bitset_word *src1p;
   bitset_word *src2p;
@@ -582,7 +582,7 @@ vbitset_and_cmp (bitset dst, bitset src1, bitset src2)
 static void
 vbitset_andn (bitset dst, bitset src1, bitset src2)
 {
-  unsigned int i;
+  unsigned i;
   bitset_word *src1p;
   bitset_word *src2p;
   bitset_word *dstp;
@@ -622,7 +622,7 @@ vbitset_andn (bitset dst, bitset src1, bitset src2)
 static bool
 vbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 {
-  unsigned int i;
+  unsigned i;
   int changed = 0;
   bitset_word *src1p;
   bitset_word *src2p;
@@ -687,7 +687,7 @@ vbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 static void
 vbitset_or (bitset dst, bitset src1, bitset src2)
 {
-  unsigned int i;
+  unsigned i;
   bitset_word *src1p;
   bitset_word *src2p;
   bitset_word *dstp;
@@ -723,7 +723,7 @@ vbitset_or (bitset dst, bitset src1, bitset src2)
 static bool
 vbitset_or_cmp (bitset dst, bitset src1, bitset src2)
 {
-  unsigned int i;
+  unsigned i;
   int changed = 0;
   bitset_word *src1p;
   bitset_word *src2p;
@@ -778,7 +778,7 @@ vbitset_or_cmp (bitset dst, bitset src1, bitset src2)
 static void
 vbitset_xor (bitset dst, bitset src1, bitset src2)
 {
-  unsigned int i;
+  unsigned i;
   bitset_word *src1p;
   bitset_word *src2p;
   bitset_word *dstp;
@@ -814,7 +814,7 @@ vbitset_xor (bitset dst, bitset src1, bitset src2)
 static bool
 vbitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 {
-  unsigned int i;
+  unsigned i;
   int changed = 0;
   bitset_word *src1p;
   bitset_word *src2p;
@@ -872,7 +872,7 @@ vbitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 static void
 vbitset_and_or (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  unsigned int i;
+  unsigned i;
   bitset_word *src1p;
   bitset_word *src2p;
   bitset_word *src3p;
@@ -902,7 +902,7 @@ vbitset_and_or (bitset dst, bitset src1, bitset src2, bitset src3)
 static bool
 vbitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  unsigned int i;
+  unsigned i;
   int changed = 0;
   bitset_word *src1p;
   bitset_word *src2p;
@@ -939,7 +939,7 @@ vbitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 static void
 vbitset_andn_or (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  unsigned int i;
+  unsigned i;
   bitset_word *src1p;
   bitset_word *src2p;
   bitset_word *src3p;
@@ -969,7 +969,7 @@ vbitset_andn_or (bitset dst, bitset src1, bitset src2, bitset src3)
 static bool
 vbitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  unsigned int i;
+  unsigned i;
   int changed = 0;
   bitset_word *src1p;
   bitset_word *src2p;
@@ -1006,7 +1006,7 @@ vbitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 static void
 vbitset_or_and (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  unsigned int i;
+  unsigned i;
   bitset_word *src1p;
   bitset_word *src2p;
   bitset_word *src3p;
@@ -1036,7 +1036,7 @@ vbitset_or_and (bitset dst, bitset src1, bitset src2, bitset src3)
 static bool
 vbitset_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  unsigned int i;
+  unsigned i;
   int changed = 0;
   bitset_word *src1p;
   bitset_word *src2p;
