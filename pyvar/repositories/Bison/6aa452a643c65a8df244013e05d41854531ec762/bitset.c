@@ -28,6 +28,8 @@
 #include "bitset_stats.h"
 #include "obstack.h"
 
+const char * const bitset_type_names[] = BITSET_TYPE_NAMES;
+
 static void bitset_print PARAMS ((FILE *, bitset, int));
 
 
@@ -108,10 +110,8 @@ bitset_type_choose (n_bits, attr)
   if (attr & BITSET_SPARSE && attr & BITSET_DENSE)
     abort ();
 
-  /* Note that sometimes we will be asked for a zero length
-     fixed size bitset.  */
-
-  /* Choose the type of bitset.  */
+  /* Choose the type of bitset. Note that sometimes we will be asked
+  for a zero length fixed size bitset.  */
 
   type = BITSET_ARRAY;
   /* Currently, the simple bitsets do not support a variable size.  */
@@ -215,6 +215,19 @@ bitset_type_get (bset)
 }
 
 
+/* Return name of bitset type.  */
+const char *
+bitset_type_name_get (bset)
+     bitset bset;
+{
+  enum bitset_type type;
+
+  type = bitset_type_get (bset);
+
+  return bitset_type_names[type];
+}
+
+
 /* Find next bit set in SRC starting from and including BITNO.
    Return -1 if SRC empty.  */
 int
@@ -241,7 +254,7 @@ bitset_prev (src, bitno)
   bitset_bindex val;
   bitset_bindex next = bitno;
 
-  if (!bitset_reverse_list (src, &val, 1, &next))
+  if (!bitset_list_reverse (src, &val, 1, &next))
     return -1;
   return val;
 }
@@ -280,27 +293,6 @@ bitset_only_set_p (src, bitno)
 }
 
 
-/* Toggle bit BITNO in bitset BSET and return non-zero if now set.  */
-int
-bitset_toggle (bset, bitno)
-    bitset bset;
-    bitset_bindex bitno;
-{
-  /* This routine is for completeness.  It could be optimized if
-     required.  */
-  if (bitset_test (bset, bitno))
-    {
-      bitset_reset (bset, bitno);
-      return 0;
-    }
-  else
-    {
-      bitset_set (bset, bitno);
-      return 1;
-    }
-}
-
-
 /* Print contents of bitset BSET to FILE.   */
 static void
 bitset_print (file, bset, verbose)
@@ -308,7 +300,8 @@ bitset_print (file, bset, verbose)
      bitset bset;
      int verbose;
 {
-  unsigned int i, pos;
+  unsigned int pos;
+  bitset_bindex i;
   bitset_iterator iter;
 
   if (verbose)
@@ -332,42 +325,51 @@ bitset_print (file, bset, verbose)
 }
 
 
-/* DST = SRC.  Return non-zero if DST != SRC.  */
-int
-bitset_copy (dst, src)
-     bitset dst;
-     bitset src;
+/* Dump bitset BSET to FILE.  */
+void
+bitset_dump (file, bset)
+     FILE *file;
+     bitset bset;
 {
-  unsigned int i;
-  bitset_iterator iter;
+  bitset_print (file, bset, 0);
+}
 
-  if (BITSET_COMPATIBLE_ (dst, src))
-    return BITSET_COPY_ (dst, src);
 
-  /* Convert bitset types.  We assume that the DST bitset
-     is large enough to hold the SRC bitset.  */
-  bitset_zero (dst);
-  BITSET_FOR_EACH (iter, src, i, 0)
-  {
-     bitset_set (dst, i);
-  };
 
-  return 1;
+/* Release memory associated with bitsets.  */
+void
+bitset_release_memory ()
+{
+  lbitset_release_memory ();
+  ebitset_release_memory ();
 }
 
 
-/* Return size in bits of bitset SRC.  */
+
+/* Toggle bit BITNO in bitset BSET and return non-zero if not set.  */
 int
-bitset_size (src)
-     bitset src;
+bitset_toggle_ (bset, bitno)
+    bitset bset;
+    bitset_bindex bitno;
 {
-  return BITSET_SIZE_ (src);
+  /* This routine is for completeness.  It could be optimized if
+     required.  */
+  if (bitset_test (bset, bitno))
+    {
+      bitset_reset (bset, bitno);
+      return 0;
+    }
+  else
+    {
+      bitset_set (bset, bitno);
+      return 1;
+    }
 }
 
 
 /* Return number of bits set in bitset SRC.  */
 int
-bitset_count (src)
+bitset_count_ (src)
      bitset src;
 {
   bitset_bindex list[BITSET_LIST_SIZE];
@@ -388,121 +390,33 @@ bitset_count (src)
 }
 
 
-/* DST = 0.  */
-int
-bitset_zero (dst)
-     bitset dst;
-{
-  return BITSET_ZERO_ (dst);
-}
-
-
-/* DST = ~0.  */
-int
-bitset_ones (dst)
-     bitset dst;
-{
-  return BITSET_ONES_ (dst);
-}
-
-
-/* Return SRC == 0.  */
-int
-bitset_empty_p (src)
-     bitset src;
-{
-  return BITSET_EMPTY_P_ (src);
-}
-
-
-/* Return DST == DST | SRC.  */
-int
-bitset_subset_p (dst, src)
-     bitset dst;
-     bitset src;
-{
-  return BITSET_SUBSET_P_ (dst, src);
-}
-
-
-/* Return DST == SRC.  */
-int
-bitset_equal_p (dst, src)
-     bitset dst;
-     bitset src;
-{
-  return BITSET_EQUAL_P_ (dst, src);
-}
-
-
-/* Return DST & SRC == 0.  */
+/* DST = SRC.  Return non-zero if DST != SRC. 
+   This is a fallback for the case where SRC and DST are different
+   bitset types.  */
 int
-bitset_disjoint_p (dst, src)
+bitset_copy_ (dst, src)
      bitset dst;
      bitset src;
 {
-  return BITSET_DISJOINT_P_ (dst, src);
-}
-
-
-/* DST = ~SRC.  */
-int
-bitset_not (dst, src)
-     bitset dst;
-     bitset src;
-{
-  return BITSET_NOT_ (dst, src);
-}
-
-
-/* DST = SRC1 | SRC2.  Return non-zero if DST != SRC1 | SRC2.  */
-int
-bitset_or (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-{
-  return BITSET_OR_ (dst, src1, src2);
-}
-
-
-/* DST = SRC1 & SRC2.  Return non-zero if DST != SRC1 & SRC2.  */
-int
-bitset_and (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-{
-  return BITSET_AND_ (dst, src1, src2);
-}
-
-
-/* DST = SRC1 ^ SRC2.  Return non-zero if DST != SRC1 ^ SRC2.  */
-int
-bitset_xor (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-{
-  return BITSET_XOR_ (dst, src1, src2);
-}
+  bitset_bindex i;
+  bitset_iterator iter;
 
+  /* Convert bitset types.  We assume that the DST bitset
+     is large enough to hold the SRC bitset.  */
+  bitset_zero (dst);
+  BITSET_FOR_EACH (iter, src, i, 0)
+  {
+     bitset_set (dst, i);
+  };
 
-/* DST = SRC1 & ~SRC2.  Return non-zero if DST != SRC1 & ~SRC2.  */
-int
-bitset_andn (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-{
-  return BITSET_ANDN_ (dst, src1, src2);
+  return 1;
 }
 
 
 /* This is a fallback for implementations that do not support
    four operand operations.  */
-int
-bitset_op4 (dst, src1, src2, src3, op)
+static inline int
+bitset_op4_cmp (dst, src1, src2, src3, op)
      bitset dst;
      bitset src1;
      bitset src2;
@@ -510,26 +424,30 @@ bitset_op4 (dst, src1, src2, src3, op)
      enum bitset_ops op;
 {
   int changed = 0;
+  int stats_enabled_save;
   bitset tmp;
 
   /* Create temporary bitset.  */
+  stats_enabled_save = bitset_stats_enabled;
+  bitset_stats_enabled = 0;
   tmp = bitset_alloc (0, bitset_type_get (dst));
+  bitset_stats_enabled = stats_enabled_save;
 
   switch (op)
     {
     case BITSET_OP_OR_AND:
-      BITSET_OR_ (tmp, src1, src2);
-      changed = BITSET_AND_ (dst, src3, tmp);
+      bitset_or (tmp, src1, src2);
+      changed = bitset_and_cmp (dst, src3, tmp);
       break;
 
     case BITSET_OP_AND_OR:
-      BITSET_AND_ (tmp, src1, src2);
-      changed = BITSET_OR_ (dst, src3, tmp);
+      bitset_and (tmp, src1, src2);
+      changed = bitset_or_cmp (dst, src3, tmp);
       break;
 
     case BITSET_OP_ANDN_OR:
-      BITSET_ANDN_ (tmp, src1, src2);
-      changed = BITSET_OR_ (dst, src3, tmp);
+      bitset_andn (tmp, src1, src2);
+      changed = bitset_or_cmp (dst, src3, tmp);
       break;
 
     default:
@@ -541,52 +459,42 @@ bitset_op4 (dst, src1, src2, src3, op)
 }
 
 
-/* DST = (SRC1 | SRC2) & SRC3.  Return non-zero if
-   DST != (SRC1 | SRC2) & SRC3.  */
+/* DST = (SRC1 & SRC2) | SRC3.  Return non-zero if
+   DST != (SRC1 & SRC2) | SRC3.  */
 int
-bitset_or_and (dst, src1, src2, src3)
+bitset_and_or_cmp_ (dst, src1, src2, src3)
      bitset dst;
      bitset src1;
      bitset src2;
      bitset src3;
 {
-  return BITSET_OR_AND_ (dst, src1, src2, src3);
+  return bitset_op4_cmp (dst, src1, src2, src3, BITSET_OP_AND_OR);
 }
 
 
-/* DST = (SRC1 & SRC2) | SRC3.  Return non-zero if
-   DST != (SRC1 & SRC2) | SRC3.  */
+/* DST = (SRC1 & ~SRC2) | SRC3.  Return non-zero if
+   DST != (SRC1 & ~SRC2) | SRC3.  */
 int
-bitset_and_or (dst, src1, src2, src3)
+bitset_andn_or_cmp_ (dst, src1, src2, src3)
      bitset dst;
      bitset src1;
      bitset src2;
      bitset src3;
 {
-  return BITSET_AND_OR_ (dst, src1, src2, src3);
+  return bitset_op4_cmp (dst, src1, src2, src3, BITSET_OP_ANDN_OR);
 }
 
 
-/* DST = (SRC1 & ~SRC2) | SRC3.  Return non-zero if
-   DST != (SRC1 & ~SRC2) | SRC3.  */
+/* DST = (SRC1 | SRC2) & SRC3.  Return non-zero if
+   DST != (SRC1 | SRC2) & SRC3.  */
 int
-bitset_andn_or (dst, src1, src2, src3)
+bitset_or_and_cmp_ (dst, src1, src2, src3)
      bitset dst;
      bitset src1;
      bitset src2;
      bitset src3;
 {
-  return BITSET_ANDN_OR_ (dst, src1, src2, src3);
-}
-
-
-/* Dump bitset BSET to FILE.  */
-void
-bitset_dump (file, bset)
-     FILE *file;
-     bitset bset;
-{
-  bitset_print (file, bset, 0);
+  return bitset_op4_cmp (dst, src1, src2, src3, BITSET_OP_OR_AND);
 }
 
 
@@ -598,12 +506,3 @@ debug_bitset (bset)
   if (bset)
     bitset_print (stderr, bset, 1);
 }
-
-
-/* Release memory associated with bitsets.  */
-void
-bitset_release_memory ()
-{
-  lbitset_release_memory ();
-  ebitset_release_memory ();
-}
