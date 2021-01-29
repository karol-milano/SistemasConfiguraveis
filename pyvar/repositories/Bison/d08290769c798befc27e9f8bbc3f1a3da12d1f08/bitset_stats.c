@@ -100,7 +100,7 @@ struct bitset_stats_info_struct
 
 struct bitset_stats_info_struct bitset_stats_info_data;
 struct bitset_stats_info_struct *bitset_stats_info;
-int bitset_stats_enabled = 0;
+bool bitset_stats_enabled = false;
 
 
 /* Print a percentage histogram with message MSG to FILE.  */
@@ -203,7 +203,7 @@ bitset_stats_print_1 (FILE *file, const char *name,
 
 /* Print all bitset statistics to FILE.  */
 static void
-bitset_stats_print (FILE *file, int verbose ATTRIBUTE_UNUSED)
+bitset_stats_print (FILE *file, bool verbose ATTRIBUTE_UNUSED)
 {
   int i;
 
@@ -227,14 +227,14 @@ bitset_stats_enable (void)
 {
   if (!bitset_stats_info)
     bitset_stats_info = &bitset_stats_info_data;
-  bitset_stats_enabled = 1;
+  bitset_stats_enabled = true;
 }
 
 
 void
 bitset_stats_disable (void)
 {
-  bitset_stats_enabled = 0;
+  bitset_stats_enabled = false;
 }
 
 
@@ -298,7 +298,7 @@ bitset_stats_write (const char *filename)
 void
 bitset_stats_dump (FILE *file)
 {
-  bitset_stats_print (file, 0);
+  bitset_stats_print (file, false);
 }
 
 
@@ -306,7 +306,7 @@ bitset_stats_dump (FILE *file)
 void
 debug_bitset_stats (void)
 {
-  bitset_stats_print (stderr, 1);
+  bitset_stats_print (stderr, true);
 }
 
 
@@ -349,14 +349,14 @@ bitset_stats_reset (bitset dst, bitset_bindex bitno)
 }
 
 
-static int
+static bool
 bitset_stats_toggle (bitset src, bitset_bindex bitno)
 {
     return BITSET_TOGGLE_ (src->s.bset, bitno);
 }
 
 
-static int
+static bool
 bitset_stats_test (bitset src, bitset_bindex bitno)
 {
   bitset bset = src->s.bset;
@@ -389,7 +389,7 @@ bitset_stats_count (bitset src)
 }
 
 
-static int
+static bool
 bitset_stats_empty_p (bitset dst)
 {
   return BITSET_EMPTY_P_ (dst->s.bset);
@@ -418,7 +418,7 @@ bitset_stats_copy (bitset dst, bitset src)
 }
 
 
-static int
+static bool
 bitset_stats_disjoint_p (bitset dst, bitset src)
 {
   BITSET_CHECK2_ (dst, src);
@@ -426,7 +426,7 @@ bitset_stats_disjoint_p (bitset dst, bitset src)
 }
 
 
-static int
+static bool
 bitset_stats_equal_p (bitset dst, bitset src)
 {
   BITSET_CHECK2_ (dst, src);
@@ -442,7 +442,7 @@ bitset_stats_not (bitset dst, bitset src)
 }
 
 
-static int
+static bool
 bitset_stats_subset_p (bitset dst, bitset src)
 {
   BITSET_CHECK2_ (dst, src);
@@ -458,7 +458,7 @@ bitset_stats_and (bitset dst, bitset src1, bitset src2)
 }
 
 
-static int
+static bool
 bitset_stats_and_cmp (bitset dst, bitset src1, bitset src2)
 {
   BITSET_CHECK3_ (dst, src1, src2);
@@ -474,7 +474,7 @@ bitset_stats_andn (bitset dst, bitset src1, bitset src2)
 }
 
 
-static int
+static bool
 bitset_stats_andn_cmp (bitset dst, bitset src1, bitset src2)
 {
   BITSET_CHECK3_ (dst, src1, src2);
@@ -490,7 +490,7 @@ bitset_stats_or (bitset dst, bitset src1, bitset src2)
 }
 
 
-static int
+static bool
 bitset_stats_or_cmp (bitset dst, bitset src1, bitset src2)
 {
   BITSET_CHECK3_ (dst, src1, src2);
@@ -506,7 +506,7 @@ bitset_stats_xor (bitset dst, bitset src1, bitset src2)
 }
 
 
-static int
+static bool
 bitset_stats_xor_cmp (bitset dst, bitset src1, bitset src2)
 {
   BITSET_CHECK3_ (dst, src1, src2);
@@ -523,7 +523,7 @@ bitset_stats_and_or (bitset dst, bitset src1, bitset src2, bitset src3)
 }
 
 
-static int
+static bool
 bitset_stats_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   BITSET_CHECK4_ (dst, src1, src2, src3);
@@ -541,7 +541,7 @@ bitset_stats_andn_or (bitset dst, bitset src1, bitset src2, bitset src3)
 }
 
 
-static int
+static bool
 bitset_stats_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   BITSET_CHECK4_ (dst, src1, src2, src3);
@@ -559,7 +559,7 @@ bitset_stats_or_and (bitset dst, bitset src1, bitset src2, bitset src3)
 }
 
 
-static int
+static bool
 bitset_stats_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   BITSET_CHECK4_ (dst, src1, src2, src3);
