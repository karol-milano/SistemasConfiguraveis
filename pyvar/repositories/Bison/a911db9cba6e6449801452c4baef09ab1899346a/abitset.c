@@ -14,7 +14,7 @@
 
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
-   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. 
+   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
 
 #ifdef HAVE_CONFIG_H
@@ -29,44 +29,6 @@
 /* This file implements fixed size bitsets stored as an array
    of words.  Any unused bits in the last word must be zero.  */
 
-static void abitset_unused_clear PARAMS ((bitset));
-static void abitset_ones PARAMS ((bitset));
-static void abitset_zero PARAMS ((bitset));
-static int abitset_empty_p PARAMS ((bitset));
-static void abitset_copy1 PARAMS ((bitset, bitset));
-static void abitset_not PARAMS ((bitset, bitset));
-static int abitset_equal_p PARAMS ((bitset, bitset));
-static int abitset_subset_p PARAMS ((bitset, bitset));
-static int abitset_disjoint_p PARAMS ((bitset, bitset));
-static void abitset_and PARAMS ((bitset, bitset, bitset));
-static int abitset_and_cmp PARAMS ((bitset, bitset, bitset));
-static void abitset_andn PARAMS ((bitset, bitset, bitset));
-static int abitset_andn_cmp PARAMS ((bitset, bitset, bitset));
-static void abitset_or PARAMS ((bitset, bitset, bitset));
-static int abitset_or_cmp PARAMS ((bitset, bitset, bitset));
-static void abitset_xor PARAMS ((bitset, bitset, bitset));
-static int abitset_xor_cmp PARAMS ((bitset, bitset, bitset));
-static void abitset_and_or PARAMS ((bitset, bitset, bitset, bitset));
-static int abitset_and_or_cmp PARAMS ((bitset, bitset, bitset, bitset));
-static void abitset_andn_or PARAMS ((bitset, bitset, bitset, bitset));
-static int abitset_andn_or_cmp PARAMS ((bitset, bitset, bitset, bitset));
-static void abitset_or_and PARAMS ((bitset, bitset, bitset, bitset));
-static int abitset_or_and_cmp PARAMS ((bitset, bitset, bitset, bitset));
-static void abitset_copy PARAMS ((bitset, bitset));
-
-static bitset_bindex abitset_small_list PARAMS ((bitset, bitset_bindex *,
-						 bitset_bindex,
-						 bitset_bindex *));
-
-static void abitset_set PARAMS ((bitset, bitset_bindex));
-static void abitset_reset PARAMS ((bitset, bitset_bindex));
-static int abitset_test PARAMS ((bitset, bitset_bindex));
-static bitset_bindex abitset_size PARAMS ((bitset));
-static bitset_bindex abitset_list PARAMS ((bitset, bitset_bindex *,
-					   bitset_bindex, bitset_bindex *));
-static bitset_bindex abitset_list_reverse
-PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
-
 #define ABITSET_N_WORDS(N) (((N) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS)
 #define ABITSET_WORDS(X) ((X)->a.words)
 #define ABITSET_N_BITS(X) ((X)->a.n_bits)
@@ -74,8 +36,7 @@ PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
 
 /* Return size in bits of bitset SRC.  */
 static bitset_bindex
-abitset_size (src)
-     bitset src;
+abitset_size (bitset src)
 {
   return ABITSET_N_BITS (src);
 }
@@ -85,11 +46,8 @@ abitset_size (src)
  *NEXT and store in array LIST.  Return with actual number of bits
  found and with *NEXT indicating where search stopped.  */
 static bitset_bindex
-abitset_small_list (src, list, num, next)
-     bitset src;
-     bitset_bindex *list;
-     bitset_bindex num;
-     bitset_bindex *next;
+abitset_small_list (bitset src, bitset_bindex *list,
+		    bitset_bindex num, bitset_bindex *next)
 {
   bitset_bindex bitno;
   bitset_bindex count;
@@ -145,9 +103,7 @@ abitset_small_list (src, list, num, next)
 
 /* Set bit BITNO in bitset DST.  */
 static void
-abitset_set (dst, bitno)
-     bitset dst ATTRIBUTE_UNUSED;
-     bitset_bindex bitno ATTRIBUTE_UNUSED;
+abitset_set (bitset dst ATTRIBUTE_UNUSED, bitset_bindex bitno ATTRIBUTE_UNUSED)
 {
   /* This should never occur for abitsets since we should always
      hit the cache.  */
@@ -157,9 +113,8 @@ abitset_set (dst, bitno)
 
 /* Reset bit BITNO in bitset DST.  */
 static void
-abitset_reset (dst, bitno)
-     bitset dst ATTRIBUTE_UNUSED;
-     bitset_bindex bitno ATTRIBUTE_UNUSED;
+abitset_reset (bitset dst ATTRIBUTE_UNUSED,
+	       bitset_bindex bitno ATTRIBUTE_UNUSED)
 {
   /* This should never occur for abitsets since we should always
      hit the cache.  */
@@ -169,9 +124,8 @@ abitset_reset (dst, bitno)
 
 /* Test bit BITNO in bitset SRC.  */
 static int
-abitset_test (src, bitno)
-     bitset src ATTRIBUTE_UNUSED;
-     bitset_bindex bitno ATTRIBUTE_UNUSED;
+abitset_test (bitset src ATTRIBUTE_UNUSED,
+	      bitset_bindex bitno ATTRIBUTE_UNUSED)
 {
   /* This should never occur for abitsets since we should always
      hit the cache.  */
@@ -185,11 +139,8 @@ abitset_test (src, bitno)
    actual number of bits found and with *NEXT indicating where search
    stopped.  */
 static bitset_bindex
-abitset_list_reverse (src, list, num, next)
-     bitset src;
-     bitset_bindex *list;
-     bitset_bindex num;
-     bitset_bindex *next;
+abitset_list_reverse (bitset src, bitset_bindex *list,
+		      bitset_bindex num, bitset_bindex *next)
 {
   bitset_bindex bitno;
   bitset_bindex rbitno;
@@ -248,11 +199,8 @@ abitset_list_reverse (src, list, num, next)
  *NEXT and store in array LIST.  Return with actual number of bits
  found and with *NEXT indicating where search stopped.  */
 static bitset_bindex
-abitset_list (src, list, num, next)
-     bitset src;
-     bitset_bindex *list;
-     bitset_bindex num;
-     bitset_bindex *next;
+abitset_list (bitset src, bitset_bindex *list,
+	      bitset_bindex num, bitset_bindex *next)
 {
   bitset_bindex bitno;
   bitset_bindex count;
@@ -352,8 +300,7 @@ abitset_list (src, list, num, next)
 
 /* Ensure that any unused bits within the last word are clear.  */
 static inline void
-abitset_unused_clear (dst)
-     bitset dst;
+abitset_unused_clear (bitset dst)
 {
   unsigned int last_bit;
 
@@ -365,8 +312,7 @@ abitset_unused_clear (dst)
 
 
 static void
-abitset_ones (dst)
-     bitset dst;
+abitset_ones (bitset dst)
 {
   bitset_word *dstp = ABITSET_WORDS (dst);
   size_t bytes;
@@ -379,8 +325,7 @@ abitset_ones (dst)
 
 
 static void
-abitset_zero (dst)
-     bitset dst;
+abitset_zero (bitset dst)
 {
   bitset_word *dstp = ABITSET_WORDS (dst);
   size_t bytes;
@@ -392,8 +337,7 @@ abitset_zero (dst)
 
 
 static int
-abitset_empty_p (dst)
-     bitset dst;
+abitset_empty_p (bitset dst)
 {
   bitset_windex i;
   bitset_word *dstp = ABITSET_WORDS (dst);
@@ -407,9 +351,7 @@ abitset_empty_p (dst)
 
 
 static void
-abitset_copy1 (dst, src)
-     bitset dst;
-     bitset src;
+abitset_copy1 (bitset dst, bitset src)
 {
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_word *dstp = ABITSET_WORDS (dst);
@@ -422,9 +364,7 @@ abitset_copy1 (dst, src)
 
 
 static void
-abitset_not (dst, src)
-     bitset dst;
-     bitset src;
+abitset_not (bitset dst, bitset src)
 {
   bitset_windex i;
   bitset_word *srcp = ABITSET_WORDS (src);
@@ -436,11 +376,9 @@ abitset_not (dst, src)
   abitset_unused_clear (dst);
 }
 
- 
+
 static int
-abitset_equal_p (dst, src)
-     bitset dst;
-     bitset src;
+abitset_equal_p (bitset dst, bitset src)
 {
   bitset_windex i;
   bitset_word *srcp = ABITSET_WORDS (src);
@@ -455,15 +393,13 @@ abitset_equal_p (dst, src)
 
 
 static int
-abitset_subset_p (dst, src)
-     bitset dst;
-     bitset src;
+abitset_subset_p (bitset dst, bitset src)
 {
   bitset_windex i;
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
-  
+
   for (i = 0; i < size; i++, dstp++, srcp++)
       if (*dstp != (*srcp | *dstp))
 	  return 0;
@@ -472,9 +408,7 @@ abitset_subset_p (dst, src)
 
 
 static int
-abitset_disjoint_p (dst, src)
-     bitset dst;
-     bitset src;
+abitset_disjoint_p (bitset dst, bitset src)
 {
   bitset_windex i;
   bitset_word *srcp = ABITSET_WORDS (src);
@@ -490,10 +424,7 @@ abitset_disjoint_p (dst, src)
 
 
 static void
-abitset_and (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+abitset_and (bitset dst, bitset src1, bitset src2)
 {
   bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
@@ -507,10 +438,7 @@ abitset_and (dst, src1, src2)
 
 
 static int
-abitset_and_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+abitset_and_cmp (bitset dst, bitset src1, bitset src2)
 {
   bitset_windex i;
   int changed = 0;
@@ -522,7 +450,7 @@ abitset_and_cmp (dst, src1, src2)
   for (i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = *src1p++ & *src2p++;
-      
+
       if (*dstp != tmp)
 	{
 	  changed = 1;
@@ -534,10 +462,7 @@ abitset_and_cmp (dst, src1, src2)
 
 
 static void
-abitset_andn (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+abitset_andn (bitset dst, bitset src1, bitset src2)
 {
   bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
@@ -551,10 +476,7 @@ abitset_andn (dst, src1, src2)
 
 
 static int
-abitset_andn_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+abitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 {
   bitset_windex i;
   int changed = 0;
@@ -562,11 +484,11 @@ abitset_andn_cmp (dst, src1, src2)
   bitset_word *src2p = ABITSET_WORDS (src2);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
-  
+
   for (i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = *src1p++ & ~(*src2p++);
-      
+
       if (*dstp != tmp)
 	{
 	  changed = 1;
@@ -578,10 +500,7 @@ abitset_andn_cmp (dst, src1, src2)
 
 
 static void
-abitset_or (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+abitset_or (bitset dst, bitset src1, bitset src2)
 {
   bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
@@ -595,10 +514,7 @@ abitset_or (dst, src1, src2)
 
 
 static int
-abitset_or_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+abitset_or_cmp (bitset dst, bitset src1, bitset src2)
 {
   bitset_windex i;
   int changed = 0;
@@ -610,7 +526,7 @@ abitset_or_cmp (dst, src1, src2)
   for (i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = *src1p++ | *src2p++;
-      
+
       if (*dstp != tmp)
 	{
 	  changed = 1;
@@ -622,10 +538,7 @@ abitset_or_cmp (dst, src1, src2)
 
 
 static void
-abitset_xor (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+abitset_xor (bitset dst, bitset src1, bitset src2)
 {
   bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
@@ -639,10 +552,7 @@ abitset_xor (dst, src1, src2)
 
 
 static int
-abitset_xor_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+abitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 {
   bitset_windex i;
   int changed = 0;
@@ -654,7 +564,7 @@ abitset_xor_cmp (dst, src1, src2)
   for (i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = *src1p++ ^ *src2p++;
-      
+
       if (*dstp != tmp)
 	{
 	  changed = 1;
@@ -666,11 +576,7 @@ abitset_xor_cmp (dst, src1, src2)
 
 
 static void
-abitset_and_or (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+abitset_and_or (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
@@ -678,18 +584,14 @@ abitset_and_or (dst, src1, src2, src3)
   bitset_word *src3p = ABITSET_WORDS (src3);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
-  
+
   for (i = 0; i < size; i++)
       *dstp++ = (*src1p++ & *src2p++) | *src3p++;
 }
 
 
 static int
-abitset_and_or_cmp (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+abitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   bitset_windex i;
   int changed = 0;
@@ -698,11 +600,11 @@ abitset_and_or_cmp (dst, src1, src2, src3)
   bitset_word *src3p = ABITSET_WORDS (src3);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
-  
+
   for (i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ & *src2p++) | *src3p++;
-      
+
       if (*dstp != tmp)
 	{
 	  changed = 1;
@@ -714,11 +616,7 @@ abitset_and_or_cmp (dst, src1, src2, src3)
 
 
 static void
-abitset_andn_or (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+abitset_andn_or (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
@@ -726,18 +624,14 @@ abitset_andn_or (dst, src1, src2, src3)
   bitset_word *src3p = ABITSET_WORDS (src3);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
-  
+
   for (i = 0; i < size; i++)
       *dstp++ = (*src1p++ & ~(*src2p++)) | *src3p++;
 }
 
 
 static int
-abitset_andn_or_cmp (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+abitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   bitset_windex i;
   int changed = 0;
@@ -746,11 +640,11 @@ abitset_andn_or_cmp (dst, src1, src2, src3)
   bitset_word *src3p = ABITSET_WORDS (src3);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
-  
+
   for (i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ & ~(*src2p++)) | *src3p++;
-      
+
       if (*dstp != tmp)
 	{
 	  changed = 1;
@@ -762,11 +656,7 @@ abitset_andn_or_cmp (dst, src1, src2, src3)
 
 
 static void
-abitset_or_and (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+abitset_or_and (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   bitset_windex i;
   bitset_word *src1p = ABITSET_WORDS (src1);
@@ -774,18 +664,14 @@ abitset_or_and (dst, src1, src2, src3)
   bitset_word *src3p = ABITSET_WORDS (src3);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
-  
+
   for (i = 0; i < size; i++)
       *dstp++ = (*src1p++ | *src2p++) & *src3p++;
 }
 
 
 static int
-abitset_or_and_cmp (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+abitset_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   bitset_windex i;
   int changed = 0;
@@ -794,11 +680,11 @@ abitset_or_and_cmp (dst, src1, src2, src3)
   bitset_word *src3p = ABITSET_WORDS (src3);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
-  
+
   for (i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ | *src2p++) & *src3p++;
-      
+
       if (*dstp != tmp)
 	{
 	  changed = 1;
@@ -810,9 +696,7 @@ abitset_or_and_cmp (dst, src1, src2, src3)
 
 
 static void
-abitset_copy (dst, src)
-     bitset dst;
-     bitset src;
+abitset_copy (bitset dst, bitset src)
 {
   if (BITSET_COMPATIBLE_ (dst, src))
       abitset_copy1 (dst, src);
@@ -896,8 +780,7 @@ struct bitset_vtable abitset_vtable = {
 
 
 size_t
-abitset_bytes (n_bits)
-     bitset_bindex n_bits;
+abitset_bytes (bitset_bindex n_bits)
 {
   bitset_windex size;
   size_t bytes;
@@ -921,9 +804,7 @@ abitset_bytes (n_bits)
 
 
 bitset
-abitset_init (bset, n_bits)
-     bitset bset;
-     bitset_bindex n_bits;
+abitset_init (bitset bset, bitset_bindex n_bits)
 {
   bitset_windex size;
 
