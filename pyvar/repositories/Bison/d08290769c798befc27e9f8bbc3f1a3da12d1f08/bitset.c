@@ -1,5 +1,5 @@
 /* General bitsets.
-   Copyright (C) 2002 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -253,22 +253,22 @@ bitset_last (bitset src)
 }
 
 
-/* Return non-zero if BITNO in SRC is the only set bit.  */
-int
+/* Is BITNO in SRC the only set bit?  */
+bool
 bitset_only_set_p (bitset src, bitset_bindex bitno)
 {
   bitset_bindex val[2];
   bitset_bindex next = 0;
 
   if (bitset_list (src, val, 2, &next) != 1)
-    return 0;
+    return false;
   return val[0] == bitno;
 }
 
 
 /* Print contents of bitset BSET to FILE.   */
 static void
-bitset_print (FILE *file, bitset bset, int verbose)
+bitset_print (FILE *file, bitset bset, bool verbose)
 {
   unsigned int pos;
   bitset_bindex i;
@@ -300,7 +300,7 @@ bitset_print (FILE *file, bitset bset, int verbose)
 void
 bitset_dump (FILE *file, bitset bset)
 {
-  bitset_print (file, bset, 0);
+  bitset_print (file, bset, false);
 }
 
 
@@ -315,8 +315,8 @@ bitset_release_memory (void)
 
 
 
-/* Toggle bit BITNO in bitset BSET and return non-zero if not set.  */
-int
+/* Toggle bit BITNO in bitset BSET and the new value of the bit.  */
+bool
 bitset_toggle_ (bitset bset, bitset_bindex bitno)
 {
   /* This routine is for completeness.  It could be optimized if
@@ -324,12 +324,12 @@ bitset_toggle_ (bitset bset, bitset_bindex bitno)
   if (bitset_test (bset, bitno))
     {
       bitset_reset (bset, bitno);
-      return 0;
+      return false;
     }
   else
     {
       bitset_set (bset, bitno);
-      return 1;
+      return true;
     }
 }
 
@@ -356,10 +356,10 @@ bitset_count_ (bitset src)
 }
 
 
-/* DST = SRC.  Return non-zero if DST != SRC.
+/* DST = SRC.  Return true if DST != SRC.
    This is a fallback for the case where SRC and DST are different
    bitset types.  */
-int
+bool
 bitset_copy_ (bitset dst, bitset src)
 {
   bitset_bindex i;
@@ -373,23 +373,23 @@ bitset_copy_ (bitset dst, bitset src)
      bitset_set (dst, i);
   };
 
-  return 1;
+  return true;
 }
 
 
 /* This is a fallback for implementations that do not support
    four operand operations.  */
-static inline int
+static inline bool
 bitset_op4_cmp (bitset dst, bitset src1, bitset src2, bitset src3,
 		enum bitset_ops op)
 {
-  int changed = 0;
-  int stats_enabled_save;
+  bool changed = false;
+  bool stats_enabled_save;
   bitset tmp;
 
   /* Create temporary bitset.  */
   stats_enabled_save = bitset_stats_enabled;
-  bitset_stats_enabled = 0;
+  bitset_stats_enabled = false;
   tmp = bitset_alloc (0, bitset_type_get (dst));
   bitset_stats_enabled = stats_enabled_save;
 
@@ -429,7 +429,7 @@ bitset_and_or_ (bitset dst, bitset src1, bitset src2, bitset src3)
 
 /* DST = (SRC1 & SRC2) | SRC3.  Return non-zero if
    DST != (SRC1 & SRC2) | SRC3.  */
-int
+bool
 bitset_and_or_cmp_ (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   return bitset_op4_cmp (dst, src1, src2, src3, BITSET_OP_AND_OR);
@@ -446,7 +446,7 @@ bitset_andn_or_ (bitset dst, bitset src1, bitset src2, bitset src3)
 
 /* DST = (SRC1 & ~SRC2) | SRC3.  Return non-zero if
    DST != (SRC1 & ~SRC2) | SRC3.  */
-int
+bool
 bitset_andn_or_cmp_ (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   return bitset_op4_cmp (dst, src1, src2, src3, BITSET_OP_ANDN_OR);
@@ -463,7 +463,7 @@ bitset_or_and_ (bitset dst, bitset src1, bitset src2, bitset src3)
 
 /* DST = (SRC1 | SRC2) & SRC3.  Return non-zero if
    DST != (SRC1 | SRC2) & SRC3.  */
-int
+bool
 bitset_or_and_cmp_ (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   return bitset_op4_cmp (dst, src1, src2, src3, BITSET_OP_OR_AND);
@@ -475,5 +475,5 @@ void
 debug_bitset (bitset bset)
 {
   if (bset)
-    bitset_print (stderr, bset, 1);
+    bitset_print (stderr, bset, true);
 }
