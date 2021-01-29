@@ -14,7 +14,7 @@
 
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
-   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. 
+   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
 
 /* This file is a wrapper bitset implementation for the other bitset
@@ -22,7 +22,7 @@
    statistics gathering without having to instrument the bitset
    implementations.  When statistics gathering is enabled, the bitset
    operations get vectored through here and we then call the appropriate
-   routines.  
+   routines.
 */
 
 #ifdef HAVE_CONFIG_H
@@ -103,61 +103,10 @@ struct bitset_stats_info_struct *bitset_stats_info;
 int bitset_stats_enabled = 0;
 
 
-static void bitset_stats_set PARAMS ((bitset, bitset_bindex));
-static void bitset_stats_reset PARAMS ((bitset, bitset_bindex));
-static int bitset_stats_toggle PARAMS ((bitset, bitset_bindex));
-static int bitset_stats_test PARAMS ((bitset, bitset_bindex));
-static bitset_bindex bitset_stats_size PARAMS ((bitset));
-static bitset_bindex bitset_stats_count PARAMS ((bitset));
-static int bitset_stats_empty_p PARAMS ((bitset));
-static void bitset_stats_ones PARAMS ((bitset));
-static void bitset_stats_zero PARAMS ((bitset));
-static void bitset_stats_copy PARAMS ((bitset, bitset));
-static int bitset_stats_disjoint_p PARAMS ((bitset, bitset));
-static int bitset_stats_equal_p PARAMS ((bitset, bitset));
-static void bitset_stats_not PARAMS ((bitset, bitset));
-static int bitset_stats_subset_p PARAMS ((bitset, bitset));
-static void bitset_stats_and PARAMS ((bitset, bitset, bitset));
-static int bitset_stats_and_cmp PARAMS ((bitset, bitset, bitset));
-static void bitset_stats_andn PARAMS ((bitset, bitset, bitset));
-static int bitset_stats_andn_cmp PARAMS ((bitset, bitset, bitset));
-static void bitset_stats_or PARAMS ((bitset, bitset, bitset));
-static int bitset_stats_or_cmp PARAMS ((bitset, bitset, bitset));
-static void bitset_stats_xor PARAMS ((bitset, bitset, bitset));
-static int bitset_stats_xor_cmp PARAMS ((bitset, bitset, bitset));
-static void bitset_stats_and_or PARAMS ((bitset, bitset, bitset, bitset));
-static int bitset_stats_and_or_cmp PARAMS ((bitset, bitset, bitset, bitset));
-static void bitset_stats_andn_or PARAMS ((bitset, bitset, bitset, bitset));
-static int bitset_stats_andn_or_cmp PARAMS ((bitset, bitset, bitset, bitset));
-static void bitset_stats_or_and PARAMS ((bitset, bitset, bitset, bitset));
-static int bitset_stats_or_and_cmp PARAMS ((bitset, bitset, bitset, bitset));
-static bitset_bindex bitset_stats_list PARAMS ((bitset, bitset_bindex *,
-						bitset_bindex,
-						bitset_bindex *));
-static bitset_bindex bitset_stats_list_reverse
-PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
-static void bitset_stats_free PARAMS ((bitset));
-static void bitset_percent_histogram_print PARAMS ((FILE *, const char *,
-						    const char *,
-						    unsigned int,
-						    unsigned int *));
-static void bitset_log_histogram_print PARAMS ((FILE *, const char *,
-						const char *,
-						unsigned int,
-						unsigned int *));
-static void bitset_stats_print_1
-PARAMS ((FILE *, const char *, struct bitset_type_info_struct *));
-static void bitset_stats_print PARAMS ((FILE *, int));
-
-
 /* Print a percentage histogram with message MSG to FILE.  */
 static void
-bitset_percent_histogram_print (file, name, msg, n_bins, bins)
-     FILE *file;
-     const char *name;
-     const char *msg;
-     unsigned int n_bins;
-     unsigned int *bins;
+bitset_percent_histogram_print (FILE *file, const char *name, const char *msg,
+				unsigned int n_bins, unsigned int *bins)
 {
   unsigned int i;
   unsigned int total;
@@ -180,12 +129,8 @@ bitset_percent_histogram_print (file, name, msg, n_bins, bins)
 
 /* Print a log histogram with message MSG to FILE.  */
 static void
-bitset_log_histogram_print (file, name, msg, n_bins, bins)
-     FILE *file;
-     const char *name;
-     const char *msg;
-     unsigned int n_bins;
-     unsigned int *bins;
+bitset_log_histogram_print (FILE *file, const char *name, const char *msg,
+			    unsigned int n_bins, unsigned int *bins)
 {
   unsigned int i;
   unsigned int total;
@@ -223,14 +168,12 @@ bitset_log_histogram_print (file, name, msg, n_bins, bins)
 
 /* Print bitset statistics to FILE.  */
 static void
-bitset_stats_print_1 (file, name, stats)
-     FILE *file;
-     const char *name;
-     struct bitset_type_info_struct *stats;
+bitset_stats_print_1 (FILE *file, const char *name,
+		      struct bitset_type_info_struct *stats)
 {
   if (!stats)
     return;
-  
+
   fprintf (file, "%s:\n", name);
   fprintf (file, _("%u bitset_allocs, %u freed (%.2f%%).\n"),
 	   stats->allocs, stats->frees,
@@ -260,9 +203,7 @@ bitset_stats_print_1 (file, name, stats)
 
 /* Print all bitset statistics to FILE.  */
 static void
-bitset_stats_print (file, verbose)
-     FILE *file;
-     int verbose ATTRIBUTE_UNUSED;
+bitset_stats_print (FILE *file, int verbose ATTRIBUTE_UNUSED)
 {
   int i;
 
@@ -275,14 +216,14 @@ bitset_stats_print (file, verbose)
     fprintf (file, _("Accumulated runs = %u\n"), bitset_stats_info->runs);
 
   for (i = 0; i < BITSET_TYPE_NUM; i++)
-    bitset_stats_print_1 (file, bitset_type_names[i], 
+    bitset_stats_print_1 (file, bitset_type_names[i],
 			  &bitset_stats_info->types[i]);
 }
 
 
 /* Initialise bitset statistics logging.  */
 void
-bitset_stats_enable ()
+bitset_stats_enable (void)
 {
   if (!bitset_stats_info)
     bitset_stats_info = &bitset_stats_info_data;
@@ -291,7 +232,7 @@ bitset_stats_enable ()
 
 
 void
-bitset_stats_disable ()
+bitset_stats_disable (void)
 {
   bitset_stats_enabled = 0;
 }
@@ -299,14 +240,13 @@ bitset_stats_disable ()
 
 /* Read bitset statistics file.  */
 void
-bitset_stats_read (filename)
-     const char *filename;
+bitset_stats_read (const char *filename)
 {
   FILE *file;
 
   if (!bitset_stats_info)
     return;
-  
+
   if (!filename)
     filename = BITSET_STATS_FILE;
 
@@ -329,8 +269,7 @@ bitset_stats_read (filename)
 
 /* Write bitset statistics file.  */
 void
-bitset_stats_write (filename)
-     const char *filename;
+bitset_stats_write (const char *filename)
 {
   FILE *file;
 
@@ -355,8 +294,7 @@ bitset_stats_write (filename)
 
 /* Dump bitset statistics to FILE.  */
 void
-bitset_stats_dump (file)
-     FILE *file;
+bitset_stats_dump (FILE *file)
 {
   bitset_stats_print (file, 0);
 }
@@ -371,14 +309,12 @@ debug_bitset_stats (void)
 
 
 static void
-bitset_stats_set (dst, bitno)
-     bitset dst;
-     bitset_bindex bitno;
+bitset_stats_set (bitset dst, bitset_bindex bitno)
 {
   bitset bset = dst->s.bset;
   bitset_windex wordno = bitno / BITSET_WORD_BITS;
   bitset_windex offset = wordno - bset->b.cindex;
-  
+
   BITSET_STATS_SETS_INC (bset);
 
   if (offset < bset->b.csize)
@@ -392,14 +328,12 @@ bitset_stats_set (dst, bitno)
 
 
 static void
-bitset_stats_reset (dst, bitno)
-     bitset dst;
-     bitset_bindex bitno;
+bitset_stats_reset (bitset dst, bitset_bindex bitno)
 {
   bitset bset = dst->s.bset;
   bitset_windex wordno = bitno / BITSET_WORD_BITS;
   bitset_windex offset = wordno - bset->b.cindex;
-  
+
   BITSET_STATS_RESETS_INC (bset);
 
   if (offset < bset->b.csize)
@@ -414,25 +348,21 @@ bitset_stats_reset (dst, bitno)
 
 
 static int
-bitset_stats_toggle (src, bitno)
-     bitset src;
-     bitset_bindex bitno;
+bitset_stats_toggle (bitset src, bitset_bindex bitno)
 {
     return BITSET_TOGGLE_ (src->s.bset, bitno);
 }
 
 
 static int
-bitset_stats_test (src, bitno)
-     bitset src;
-     bitset_bindex bitno;
+bitset_stats_test (bitset src, bitset_bindex bitno)
 {
   bitset bset = src->s.bset;
   bitset_windex wordno = bitno / BITSET_WORD_BITS;
   bitset_windex offset = wordno - bset->b.cindex;
 
   BITSET_STATS_TESTS_INC (bset);
-  
+
   if (offset < bset->b.csize)
     {
       BITSET_STATS_CACHE_TESTS_INC (bset);
@@ -444,49 +374,42 @@ bitset_stats_test (src, bitno)
 
 
 static bitset_bindex
-bitset_stats_size (src)
-     bitset src;
+bitset_stats_size (bitset src)
 {
   return BITSET_SIZE_ (src->s.bset);
 }
 
 
 static bitset_bindex
-bitset_stats_count (src)
-     bitset src;
+bitset_stats_count (bitset src)
 {
   return BITSET_COUNT_ (src->s.bset);
 }
 
 
 static int
-bitset_stats_empty_p (dst)
-     bitset dst;
+bitset_stats_empty_p (bitset dst)
 {
   return BITSET_EMPTY_P_ (dst->s.bset);
 }
 
 
 static void
-bitset_stats_ones (dst)
-     bitset dst;
+bitset_stats_ones (bitset dst)
 {
   BITSET_ONES_ (dst->s.bset);
 }
 
 
 static void
-bitset_stats_zero (dst)
-     bitset dst;
+bitset_stats_zero (bitset dst)
 {
   BITSET_ZERO_ (dst->s.bset);
 }
 
 
 static void
-bitset_stats_copy (dst, src)
-     bitset dst;
-     bitset src;
+bitset_stats_copy (bitset dst, bitset src)
 {
   BITSET_CHECK2_ (dst, src);
   BITSET_COPY_ (dst->s.bset, src->s.bset);
@@ -494,9 +417,7 @@ bitset_stats_copy (dst, src)
 
 
 static int
-bitset_stats_disjoint_p (dst, src)
-     bitset dst;
-     bitset src;
+bitset_stats_disjoint_p (bitset dst, bitset src)
 {
   BITSET_CHECK2_ (dst, src);
   return BITSET_DISJOINT_P_ (dst->s.bset, src->s.bset);
@@ -504,9 +425,7 @@ bitset_stats_disjoint_p (dst, src)
 
 
 static int
-bitset_stats_equal_p (dst, src)
-     bitset dst;
-     bitset src;
+bitset_stats_equal_p (bitset dst, bitset src)
 {
   BITSET_CHECK2_ (dst, src);
   return BITSET_EQUAL_P_ (dst->s.bset, src->s.bset);
@@ -514,9 +433,7 @@ bitset_stats_equal_p (dst, src)
 
 
 static void
-bitset_stats_not (dst, src)
-     bitset dst;
-     bitset src;
+bitset_stats_not (bitset dst, bitset src)
 {
   BITSET_CHECK2_ (dst, src);
   BITSET_NOT_ (dst->s.bset, src->s.bset);
@@ -524,9 +441,7 @@ bitset_stats_not (dst, src)
 
 
 static int
-bitset_stats_subset_p (dst, src)
-     bitset dst;
-     bitset src;
+bitset_stats_subset_p (bitset dst, bitset src)
 {
   BITSET_CHECK2_ (dst, src);
   return BITSET_SUBSET_P_ (dst->s.bset, src->s.bset);
@@ -534,10 +449,7 @@ bitset_stats_subset_p (dst, src)
 
 
 static void
-bitset_stats_and (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+bitset_stats_and (bitset dst, bitset src1, bitset src2)
 {
   BITSET_CHECK3_ (dst, src1, src2);
   BITSET_AND_ (dst->s.bset, src1->s.bset, src2->s.bset);
@@ -545,10 +457,7 @@ bitset_stats_and (dst, src1, src2)
 
 
 static int
-bitset_stats_and_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+bitset_stats_and_cmp (bitset dst, bitset src1, bitset src2)
 {
   BITSET_CHECK3_ (dst, src1, src2);
   return BITSET_AND_CMP_ (dst->s.bset, src1->s.bset, src2->s.bset);
@@ -556,10 +465,7 @@ bitset_stats_and_cmp (dst, src1, src2)
 
 
 static void
-bitset_stats_andn (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+bitset_stats_andn (bitset dst, bitset src1, bitset src2)
 {
   BITSET_CHECK3_ (dst, src1, src2);
   BITSET_ANDN_ (dst->s.bset, src1->s.bset, src2->s.bset);
@@ -567,10 +473,7 @@ bitset_stats_andn (dst, src1, src2)
 
 
 static int
-bitset_stats_andn_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+bitset_stats_andn_cmp (bitset dst, bitset src1, bitset src2)
 {
   BITSET_CHECK3_ (dst, src1, src2);
   return BITSET_ANDN_CMP_ (dst->s.bset, src1->s.bset, src2->s.bset);
@@ -578,10 +481,7 @@ bitset_stats_andn_cmp (dst, src1, src2)
 
 
 static void
-bitset_stats_or (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+bitset_stats_or (bitset dst, bitset src1, bitset src2)
 {
   BITSET_CHECK3_ (dst, src1, src2);
   BITSET_OR_ (dst->s.bset, src1->s.bset, src2->s.bset);
@@ -589,10 +489,7 @@ bitset_stats_or (dst, src1, src2)
 
 
 static int
-bitset_stats_or_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+bitset_stats_or_cmp (bitset dst, bitset src1, bitset src2)
 {
   BITSET_CHECK3_ (dst, src1, src2);
   return BITSET_OR_CMP_ (dst->s.bset, src1->s.bset, src2->s.bset);
@@ -600,10 +497,7 @@ bitset_stats_or_cmp (dst, src1, src2)
 
 
 static void
-bitset_stats_xor (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+bitset_stats_xor (bitset dst, bitset src1, bitset src2)
 {
   BITSET_CHECK3_ (dst, src1, src2);
   BITSET_XOR_ (dst->s.bset, src1->s.bset, src2->s.bset);
@@ -611,10 +505,7 @@ bitset_stats_xor (dst, src1, src2)
 
 
 static int
-bitset_stats_xor_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+bitset_stats_xor_cmp (bitset dst, bitset src1, bitset src2)
 {
   BITSET_CHECK3_ (dst, src1, src2);
   return BITSET_XOR_CMP_ (dst->s.bset, src1->s.bset, src2->s.bset);
@@ -622,11 +513,7 @@ bitset_stats_xor_cmp (dst, src1, src2)
 
 
 static void
-bitset_stats_and_or (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+bitset_stats_and_or (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   BITSET_CHECK4_ (dst, src1, src2, src3);
 
@@ -635,11 +522,7 @@ bitset_stats_and_or (dst, src1, src2, src3)
 
 
 static int
-bitset_stats_and_or_cmp (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+bitset_stats_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   BITSET_CHECK4_ (dst, src1, src2, src3);
 
@@ -648,11 +531,7 @@ bitset_stats_and_or_cmp (dst, src1, src2, src3)
 
 
 static void
-bitset_stats_andn_or (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+bitset_stats_andn_or (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   BITSET_CHECK4_ (dst, src1, src2, src3);
 
@@ -661,11 +540,7 @@ bitset_stats_andn_or (dst, src1, src2, src3)
 
 
 static int
-bitset_stats_andn_or_cmp (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+bitset_stats_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   BITSET_CHECK4_ (dst, src1, src2, src3);
 
@@ -674,11 +549,7 @@ bitset_stats_andn_or_cmp (dst, src1, src2, src3)
 
 
 static void
-bitset_stats_or_and (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+bitset_stats_or_and (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   BITSET_CHECK4_ (dst, src1, src2, src3);
 
@@ -687,11 +558,7 @@ bitset_stats_or_and (dst, src1, src2, src3)
 
 
 static int
-bitset_stats_or_and_cmp (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+bitset_stats_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   BITSET_CHECK4_ (dst, src1, src2, src3);
 
@@ -700,11 +567,8 @@ bitset_stats_or_and_cmp (dst, src1, src2, src3)
 
 
 static bitset_bindex
-bitset_stats_list (bset, list, num, next)
-     bitset bset;
-     bitset_bindex *list;
-     bitset_bindex num;
-     bitset_bindex *next;
+bitset_stats_list (bitset bset, bitset_bindex *list,
+		   bitset_bindex num, bitset_bindex *next)
 {
   bitset_bindex count;
   bitset_bindex tmp;
@@ -713,17 +577,17 @@ bitset_stats_list (bset, list, num, next)
   enum bitset_type type;
 
   count = BITSET_LIST_ (bset->s.bset, list, num, next);
-  
+
   type = BITSET_TYPE_ (bset->s.bset);
   BITSET_STATS_LISTS_INC (bset->s.bset);
-  
+
   /* Log histogram of number of set bits.  */
   for (i = 0, tmp = count; tmp; tmp >>= 1, i++)
      continue;
   if (i >= BITSET_LOG_COUNT_BINS)
      i = BITSET_LOG_COUNT_BINS - 1;
   BITSET_STATS_LIST_COUNTS_INC (bset->s.bset, i);
-  
+
   /* Log histogram of number of bits in set.  */
   size = BITSET_SIZE_ (bset->s.bset);
   for (i = 0, tmp = size; tmp; tmp >>= 1, i++)
@@ -731,7 +595,7 @@ bitset_stats_list (bset, list, num, next)
   if (i >= BITSET_LOG_SIZE_BINS)
      i = BITSET_LOG_SIZE_BINS - 1;
   BITSET_STATS_LIST_SIZES_INC (bset->s.bset, i);
-  
+
   /* Histogram of fraction of bits set.  */
   i = size ? (count * BITSET_DENSITY_BINS) / size : 0;
   if (i >= BITSET_DENSITY_BINS)
@@ -742,19 +606,15 @@ bitset_stats_list (bset, list, num, next)
 
 
 static bitset_bindex
-bitset_stats_list_reverse (bset, list, num, next)
-     bitset bset;
-     bitset_bindex *list;
-     bitset_bindex num;
-     bitset_bindex *next;
+bitset_stats_list_reverse (bitset bset, bitset_bindex *list,
+			   bitset_bindex num, bitset_bindex *next)
 {
   return BITSET_LIST_REVERSE_ (bset->s.bset, list, num, next);
 }
 
 
 static void
-bitset_stats_free (bset)
-     bitset bset;
+bitset_stats_free (bitset bset)
 {
   BITSET_STATS_FREES_INC (bset->s.bset);
   BITSET_FREE_ (bset->s.bset);
@@ -799,8 +659,7 @@ struct bitset_vtable bitset_stats_vtable = {
 
 /* Return enclosed bitset type.  */
 enum bitset_type
-bitset_stats_type_get (bset)
-   bitset bset;
+bitset_stats_type_get (bitset bset)
 {
    return BITSET_TYPE_ (bset->s.bset);
 }
@@ -814,10 +673,7 @@ bitset_stats_bytes (void)
 
 
 bitset
-bitset_stats_init (bset, n_bits, type)
-     bitset bset;
-     bitset_bindex n_bits;
-     enum_bitset_type type;
+bitset_stats_init (bitset bset, bitset_bindex n_bits, enum bitset_type type)
 {
   size_t bytes;
   bitset sbset;
@@ -858,6 +714,6 @@ bitset_stats_init (bset, n_bits, type)
   bset->s.bset = sbset;
 
   BITSET_STATS_ALLOCS_INC (type);
-  
+
   return bset;
 }
