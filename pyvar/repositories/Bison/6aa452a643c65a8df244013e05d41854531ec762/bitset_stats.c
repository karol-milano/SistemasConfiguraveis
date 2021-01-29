@@ -118,16 +118,12 @@ int bitset_stats_enabled = 0;
 
 static void bitset_stats_set PARAMS ((bitset, bitset_bindex));
 static void bitset_stats_reset PARAMS ((bitset, bitset_bindex));
+static int bitset_stats_toggle PARAMS ((bitset, bitset_bindex));
 static int bitset_stats_test PARAMS ((bitset, bitset_bindex));
 static int bitset_stats_size PARAMS ((bitset));
-static int bitset_stats_op1 PARAMS ((bitset, enum bitset_ops));
-static int bitset_stats_op2 PARAMS ((bitset, bitset, enum bitset_ops));
-static int bitset_stats_op3 PARAMS ((bitset, bitset, bitset, enum bitset_ops));
-static int bitset_stats_op4 PARAMS ((bitset, bitset, bitset, bitset,
-				     enum bitset_ops));
 static int bitset_stats_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
 				      bitset_bindex *));
-static int bitset_stats_reverse_list
+static int bitset_stats_list_reverse
 PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
 static void bitset_stats_free PARAMS ((bitset));
 static void bitset_percent_histogram_print PARAMS ((FILE *, const char *,
@@ -183,7 +179,6 @@ bitset_log_histogram_print (file, name, msg, n_bins, bins)
   unsigned int i;
   unsigned int total;
   unsigned int max_width;
-  unsigned int last_bin;
 
   total = 0;
   for (i = 0; i < n_bins; i++)
@@ -192,9 +187,10 @@ bitset_log_histogram_print (file, name, msg, n_bins, bins)
   if (!total)
     return;
 
+  /* Determine number of useful bins.  */
   for (i = n_bins; i > 3 && ! bins[i - 1]; i--)
      continue;
-  last_bin = i - 1;
+  n_bins = i;
 
   /* 2 * ceil (log10 (2) * (N - 1)) + 1.  */
   max_width = 2 * (unsigned int) (0.30103 * (n_bins - 1) + 0.9999) + 1;
@@ -204,7 +200,7 @@ bitset_log_histogram_print (file, name, msg, n_bins, bins)
     fprintf (file, "%*d\t%8d (%5.1f%%)\n",
 	     max_width, i, bins[i], 100.0 * bins[i] / total);
 
-  for (; i <= last_bin; i++)
+  for (; i < n_bins; i++)
     fprintf (file, "%*d-%d\t%8d (%5.1f%%)\n",
 	     max_width - ((unsigned int) (0.30103 * (i) + 0.9999) + 1),
 	     1 << (i - 1), (1 << i) - 1, bins[i],
@@ -256,7 +252,6 @@ bitset_stats_print (file, verbose)
      int verbose ATTRIBUTE_UNUSED;
 {
   int i;
-  static const char *names[] = BITSET_TYPE_NAMES;
 
   if (!bitset_stats_info)
     return;
@@ -267,7 +262,8 @@ bitset_stats_print (file, verbose)
     fprintf (file, _("Accumulated runs = %d\n"), bitset_stats_info->runs);
 
   for (i = 0; i < BITSET_TYPE_NUM; i++)
-    bitset_stats_print_1 (file, names[i], &bitset_stats_info->types[i]);
+    bitset_stats_print_1 (file, bitset_type_names[i], 
+			  &bitset_stats_info->types[i]);
 }
 
 
@@ -404,6 +400,15 @@ bitset_stats_reset (dst, bitno)
 }
 
 
+static int
+bitset_stats_toggle (src, bitno)
+     bitset src;
+     bitset_bindex bitno;
+{
+    return BITSET_TOGGLE_ (src->s.bset, bitno);
+}
+
+
 static int
 bitset_stats_test (src, bitno)
      bitset src;
@@ -434,56 +439,250 @@ bitset_stats_size (src)
 
 
 static int
-bitset_stats_op1 (dst, op)
+bitset_stats_count (src)
+     bitset src;
+{
+  return BITSET_COUNT_ (src->s.bset);
+}
+
+
+static int
+bitset_stats_empty_p (dst)
+     bitset dst;
+{
+  return BITSET_EMPTY_P_ (dst->s.bset);
+}
+
+
+static void
+bitset_stats_ones (dst)
+     bitset dst;
+{
+  BITSET_ONES_ (dst->s.bset);
+}
+
+
+static void
+bitset_stats_zero (dst)
+     bitset dst;
+{
+  BITSET_ZERO_ (dst->s.bset);
+}
+
+
+static void
+bitset_stats_copy (dst, src)
+     bitset dst;
+     bitset src;
+{
+  BITSET_CHECK2_ (dst, src);
+  BITSET_COPY_ (dst->s.bset, src->s.bset);
+}
+
+
+static int
+bitset_stats_disjoint_p (dst, src)
      bitset dst;
-     enum bitset_ops op;
+     bitset src;
 {
-  return BITSET_OP1_ (dst->s.bset, op);
+  BITSET_CHECK2_ (dst, src);
+  return BITSET_DISJOINT_P_ (dst->s.bset, src->s.bset);
 }
 
 
 static int
-bitset_stats_op2 (dst, src, op)
+bitset_stats_equal_p (dst, src)
      bitset dst;
      bitset src;
-     enum bitset_ops op;
 {
   BITSET_CHECK2_ (dst, src);
-  return BITSET_OP2_ (dst->s.bset, src->s.bset, op);
+  return BITSET_EQUAL_P_ (dst->s.bset, src->s.bset);
+}
+
+
+static void
+bitset_stats_not (dst, src)
+     bitset dst;
+     bitset src;
+{
+  BITSET_CHECK2_ (dst, src);
+  BITSET_NOT_ (dst->s.bset, src->s.bset);
+}
+
+
+static int
+bitset_stats_subset_p (dst, src)
+     bitset dst;
+     bitset src;
+{
+  BITSET_CHECK2_ (dst, src);
+  return BITSET_SUBSET_P_ (dst->s.bset, src->s.bset);
+}
+
+
+static void
+bitset_stats_and (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  BITSET_CHECK3_ (dst, src1, src2);
+  BITSET_AND_ (dst->s.bset, src1->s.bset, src2->s.bset);
+}
+
+
+static int
+bitset_stats_and_cmp (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  BITSET_CHECK3_ (dst, src1, src2);
+  return BITSET_AND_CMP_ (dst->s.bset, src1->s.bset, src2->s.bset);
+}
+
+
+static void
+bitset_stats_andn (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  BITSET_CHECK3_ (dst, src1, src2);
+  BITSET_ANDN_ (dst->s.bset, src1->s.bset, src2->s.bset);
+}
+
+
+static int
+bitset_stats_andn_cmp (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  BITSET_CHECK3_ (dst, src1, src2);
+  return BITSET_ANDN_CMP_ (dst->s.bset, src1->s.bset, src2->s.bset);
+}
+
+
+static void
+bitset_stats_or (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  BITSET_CHECK3_ (dst, src1, src2);
+  BITSET_OR_ (dst->s.bset, src1->s.bset, src2->s.bset);
+}
+
+
+static int
+bitset_stats_or_cmp (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  BITSET_CHECK3_ (dst, src1, src2);
+  return BITSET_OR_CMP_ (dst->s.bset, src1->s.bset, src2->s.bset);
+}
+
+
+static void
+bitset_stats_xor (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  BITSET_CHECK3_ (dst, src1, src2);
+  BITSET_XOR_ (dst->s.bset, src1->s.bset, src2->s.bset);
 }
 
 
 static int
-bitset_stats_op3 (dst, src1, src2, op)
+bitset_stats_xor_cmp (dst, src1, src2)
      bitset dst;
      bitset src1;
      bitset src2;
-     enum bitset_ops op;
 {
   BITSET_CHECK3_ (dst, src1, src2);
-  return BITSET_OP3_ (dst->s.bset, src1->s.bset, src2->s.bset, op);
+  return BITSET_XOR_CMP_ (dst->s.bset, src1->s.bset, src2->s.bset);
+}
+
+
+static void
+bitset_stats_and_or (dst, src1, src2, src3)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+{
+  BITSET_CHECK4_ (dst, src1, src2, src3);
+
+  BITSET_AND_OR_ (dst->s.bset, src1->s.bset, src2->s.bset, src3->s.bset);
 }
 
 
 static int
-bitset_stats_op4 (dst, src1, src2, src3, op)
+bitset_stats_and_or_cmp (dst, src1, src2, src3)
      bitset dst;
      bitset src1;
      bitset src2;
      bitset src3;
-     enum bitset_ops op;
 {
   BITSET_CHECK4_ (dst, src1, src2, src3);
 
-  /* This is a bit of a hack.  If the implementation handles
-     a four operand operation then vector to it, passing
-     the enclosed bitsets.  Otherwise use the fallback 
-     bitset_op4 routine.  */
-  if (dst->s.bset->b.ops->op4 != bitset_op4)
-     return BITSET_OP4_ (dst->s.bset, src1->s.bset, src2->s.bset,
-			 src3->s.bset, op);
+  return BITSET_AND_OR_CMP_ (dst->s.bset, src1->s.bset, src2->s.bset, src3->s.bset);
+}
+
+
+static void
+bitset_stats_andn_or (dst, src1, src2, src3)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+{
+  BITSET_CHECK4_ (dst, src1, src2, src3);
+
+  BITSET_ANDN_OR_ (dst->s.bset, src1->s.bset, src2->s.bset, src3->s.bset);
+}
+
+
+static int
+bitset_stats_andn_or_cmp (dst, src1, src2, src3)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+{
+  BITSET_CHECK4_ (dst, src1, src2, src3);
+
+  return BITSET_ANDN_OR_CMP_ (dst->s.bset, src1->s.bset, src2->s.bset, src3->s.bset);
+}
+
+
+static void
+bitset_stats_or_and (dst, src1, src2, src3)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+{
+  BITSET_CHECK4_ (dst, src1, src2, src3);
+
+  BITSET_OR_AND_ (dst->s.bset, src1->s.bset, src2->s.bset, src3->s.bset);
+}
+
+
+static int
+bitset_stats_or_and_cmp (dst, src1, src2, src3)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+{
+  BITSET_CHECK4_ (dst, src1, src2, src3);
 
-  return bitset_op4 (dst, src1, src2, src3, op);
+  return BITSET_OR_AND_CMP_ (dst->s.bset, src1->s.bset, src2->s.bset, src3->s.bset);
 }
 
 
@@ -530,13 +729,13 @@ bitset_stats_list (bset, list, num, next)
 
 
 static int
-bitset_stats_reverse_list (bset, list, num, next)
+bitset_stats_list_reverse (bset, list, num, next)
      bitset bset;
      bitset_bindex *list;
      bitset_bindex num;
      bitset_bindex *next;
 {
-  return BITSET_REVERSE_LIST_ (bset->s.bset, list, num, next);
+  return BITSET_LIST_REVERSE_ (bset->s.bset, list, num, next);
 }
 
 
@@ -549,17 +748,37 @@ bitset_stats_free (bset)
 }
 
 
-struct bitset_ops_struct bitset_stats_ops = {
+struct bitset_vtable bitset_stats_vtable = {
   bitset_stats_set,
   bitset_stats_reset,
+  bitset_stats_toggle,
   bitset_stats_test,
   bitset_stats_size,
-  bitset_stats_op1,
-  bitset_stats_op2,
-  bitset_stats_op3,
-  bitset_stats_op4,
+  bitset_stats_count,
+  bitset_stats_empty_p,
+  bitset_stats_ones,
+  bitset_stats_zero,
+  bitset_stats_copy,
+  bitset_stats_disjoint_p,
+  bitset_stats_equal_p,
+  bitset_stats_not,
+  bitset_stats_subset_p,
+  bitset_stats_and,
+  bitset_stats_and_cmp,
+  bitset_stats_andn,
+  bitset_stats_andn_cmp,
+  bitset_stats_or,
+  bitset_stats_or_cmp,
+  bitset_stats_xor,
+  bitset_stats_xor_cmp,
+  bitset_stats_and_or,
+  bitset_stats_and_or_cmp,
+  bitset_stats_andn_or,
+  bitset_stats_andn_or_cmp,
+  bitset_stats_or_and,
+  bitset_stats_or_and_cmp,
   bitset_stats_list,
-  bitset_stats_reverse_list,
+  bitset_stats_list_reverse,
   bitset_stats_free,
   BITSET_STATS
 };
@@ -589,7 +808,7 @@ bitset_stats_init (bset, n_bits, type)
   unsigned int bytes;
   bitset sbset;
 
-  bset->b.ops = &bitset_stats_ops;
+  bset->b.vtable = &bitset_stats_vtable;
 
   /* Disable cache.  */
   bset->b.cindex = 0;
