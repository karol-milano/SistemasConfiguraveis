@@ -55,9 +55,7 @@ static bitset_bindex vbitset_list_reverse PARAMS ((bitset, bitset_bindex *,
 #define max(a, b) ((a) > (b) ? (a) : (b))
 
 static bitset_bindex
-vbitset_resize (src, n_bits)
-     bitset src;
-     bitset_bindex n_bits;
+vbitset_resize (bitset src, bitset_bindex n_bits)
 {
   bitset_windex oldsize;
   bitset_windex newsize;
@@ -343,8 +341,7 @@ vbitset_unused_clear (dst)
 
 
 static void
-vbitset_ones (dst)
-     bitset dst;
+vbitset_ones (bitset dst)
 {
   bitset_word *dstp = VBITSET_WORDS (dst);
   unsigned int bytes;
@@ -357,8 +354,7 @@ vbitset_ones (dst)
 
 
 static void
-vbitset_zero (dst)
-     bitset dst;
+vbitset_zero (bitset dst)
 {
   bitset_word *dstp = VBITSET_WORDS (dst);
   unsigned int bytes;
@@ -370,8 +366,7 @@ vbitset_zero (dst)
 
 
 static bool
-vbitset_empty_p (dst)
-     bitset dst;
+vbitset_empty_p (bitset dst)
 {
   unsigned int i;
   bitset_word *dstp = VBITSET_WORDS (dst);
@@ -385,9 +380,7 @@ vbitset_empty_p (dst)
 
 
 static void
-vbitset_copy1 (dst, src)
-     bitset dst;
-     bitset src;
+vbitset_copy1 (bitset dst, bitset src)
 {
   bitset_word *srcp;
   bitset_word *dstp;
@@ -412,9 +405,7 @@ vbitset_copy1 (dst, src)
 
 
 static void
-vbitset_not (dst, src)
-     bitset dst;
-     bitset src;
+vbitset_not (bitset dst, bitset src)
 {
   unsigned int i;
   bitset_word *srcp;
@@ -439,9 +430,7 @@ vbitset_not (dst, src)
 
  
 static bool
-vbitset_equal_p (dst, src)
-     bitset dst;
-     bitset src;
+vbitset_equal_p (bitset dst, bitset src)
 {
   unsigned int i;
   bitset_word *srcp = VBITSET_WORDS (src);
@@ -471,9 +460,7 @@ vbitset_equal_p (dst, src)
 
 
 static bool
-vbitset_subset_p (dst, src)
-     bitset dst;
-     bitset src;
+vbitset_subset_p (bitset dst, bitset src)
 {
   unsigned int i;
   bitset_word *srcp = VBITSET_WORDS (src);
@@ -497,9 +484,7 @@ vbitset_subset_p (dst, src)
 
 
 static bool
-vbitset_disjoint_p (dst, src)
-     bitset dst;
-     bitset src;
+vbitset_disjoint_p (bitset dst, bitset src)
 {
   unsigned int i;
   bitset_word *srcp = VBITSET_WORDS (src);
@@ -516,10 +501,7 @@ vbitset_disjoint_p (dst, src)
 
 
 static void
-vbitset_and (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+vbitset_and (bitset dst, bitset src1, bitset src2)
 {
   unsigned int i;
   bitset_word *src1p;
@@ -546,10 +528,7 @@ vbitset_and (dst, src1, src2)
 
 
 static bool
-vbitset_and_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+vbitset_and_cmp (bitset dst, bitset src1, bitset src2)
 {
   unsigned int i;
   int changed = 0;
@@ -602,10 +581,7 @@ vbitset_and_cmp (dst, src1, src2)
 
 
 static void
-vbitset_andn (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+vbitset_andn (bitset dst, bitset src1, bitset src2)
 {
   unsigned int i;
   bitset_word *src1p;
@@ -645,10 +621,7 @@ vbitset_andn (dst, src1, src2)
 
 
 static bool
-vbitset_andn_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+vbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 {
   unsigned int i;
   int changed = 0;
@@ -713,10 +686,7 @@ vbitset_andn_cmp (dst, src1, src2)
 
 
 static void
-vbitset_or (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+vbitset_or (bitset dst, bitset src1, bitset src2)
 {
   unsigned int i;
   bitset_word *src1p;
@@ -752,10 +722,7 @@ vbitset_or (dst, src1, src2)
 
 
 static bool
-vbitset_or_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+vbitset_or_cmp (bitset dst, bitset src1, bitset src2)
 {
   unsigned int i;
   int changed = 0;
@@ -810,10 +777,7 @@ vbitset_or_cmp (dst, src1, src2)
 
 
 static void
-vbitset_xor (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+vbitset_xor (bitset dst, bitset src1, bitset src2)
 {
   unsigned int i;
   bitset_word *src1p;
@@ -849,10 +813,7 @@ vbitset_xor (dst, src1, src2)
 
 
 static bool
-vbitset_xor_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+vbitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 {
   unsigned int i;
   int changed = 0;
@@ -910,11 +871,7 @@ vbitset_xor_cmp (dst, src1, src2)
    bitsets.  */
 
 static void
-vbitset_and_or (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+vbitset_and_or (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   unsigned int i;
   bitset_word *src1p;
@@ -944,11 +901,7 @@ vbitset_and_or (dst, src1, src2, src3)
 
 
 static bool
-vbitset_and_or_cmp (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+vbitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   unsigned int i;
   int changed = 0;
@@ -985,11 +938,7 @@ vbitset_and_or_cmp (dst, src1, src2, src3)
 
 
 static void
-vbitset_andn_or (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+vbitset_andn_or (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   unsigned int i;
   bitset_word *src1p;
@@ -1019,11 +968,7 @@ vbitset_andn_or (dst, src1, src2, src3)
 
 
 static bool
-vbitset_andn_or_cmp (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+vbitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   unsigned int i;
   int changed = 0;
@@ -1060,11 +1005,7 @@ vbitset_andn_or_cmp (dst, src1, src2, src3)
 
 
 static void
-vbitset_or_and (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+vbitset_or_and (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   unsigned int i;
   bitset_word *src1p;
@@ -1094,11 +1035,7 @@ vbitset_or_and (dst, src1, src2, src3)
 
 
 static bool
-vbitset_or_and_cmp (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+vbitset_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   unsigned int i;
   int changed = 0;
@@ -1135,9 +1072,7 @@ vbitset_or_and_cmp (dst, src1, src2, src3)
 
 
 void
-vbitset_copy (dst, src)
-     bitset dst;
-     bitset src;
+vbitset_copy (bitset dst, bitset src)
 {
   if (BITSET_COMPATIBLE_ (dst, src))
       vbitset_copy1 (dst, src);
