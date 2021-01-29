@@ -31,13 +31,14 @@
 const char * const bitset_type_names[] = BITSET_TYPE_NAMES;
 
 static void bitset_print PARAMS ((FILE *, bitset, int));
+static int bitset_op4_cmp PARAMS ((bitset, bitset, bitset, bitset, int));
 
 
 /* Return number of bytes required to create a N_BIT bitset
    of TYPE.  The bitset may grow to require more bytes than this.  */
 size_t
 bitset_bytes (type, n_bits)
-     enum bitset_type type;
+     enum_bitset_type type;
      bitset_bindex n_bits;
 {
   size_t bytes;
@@ -72,7 +73,7 @@ bitset
 bitset_init (bset, n_bits, type)
      bitset bset;
      bitset_bindex n_bits;
-     enum bitset_type type;
+     enum_bitset_type type;
 {
   if (bitset_stats_enabled)
     return bitset_stats_init (bset, n_bits, type);
@@ -130,7 +131,7 @@ bitset_type_choose (n_bits, attr)
 bitset
 bitset_alloc (n_bits, type)
      bitset_bindex n_bits;
-     enum bitset_type type;
+     enum_bitset_type type;
 {
   size_t bytes;
   bitset bset;
@@ -152,7 +153,7 @@ bitset
 bitset_obstack_alloc (bobstack, n_bits, type)
      struct obstack *bobstack;
      bitset_bindex n_bits;
-     enum bitset_type type;
+     enum_bitset_type type;
 {
   size_t bytes;
   bitset bset;
@@ -422,7 +423,7 @@ bitset_op4_cmp (dst, src1, src2, src3, op)
      bitset src1;
      bitset src2;
      bitset src3;
-     enum bitset_ops op;
+     enum_bitset_ops op;
 {
   int changed = 0;
   int stats_enabled_save;
@@ -460,6 +461,18 @@ bitset_op4_cmp (dst, src1, src2, src3, op)
 }
 
 
+/* DST = (SRC1 & SRC2) | SRC3.  */
+void
+bitset_and_or_ (dst, src1, src2, src3)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+{
+  bitset_and_or_cmp_ (dst, src1, src2, src3);
+}
+
+
 /* DST = (SRC1 & SRC2) | SRC3.  Return non-zero if
    DST != (SRC1 & SRC2) | SRC3.  */
 int
@@ -473,6 +486,18 @@ bitset_and_or_cmp_ (dst, src1, src2, src3)
 }
 
 
+/* DST = (SRC1 & ~SRC2) | SRC3.  */
+void
+bitset_andn_or_ (dst, src1, src2, src3)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+{
+  bitset_andn_or_cmp_ (dst, src1, src2, src3);
+}
+
+
 /* DST = (SRC1 & ~SRC2) | SRC3.  Return non-zero if
    DST != (SRC1 & ~SRC2) | SRC3.  */
 int
@@ -486,6 +511,18 @@ bitset_andn_or_cmp_ (dst, src1, src2, src3)
 }
 
 
+/* DST = (SRC1 | SRC2) & SRC3.  */
+void
+bitset_or_and_ (dst, src1, src2, src3)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+{
+  bitset_or_and_cmp_ (dst, src1, src2, src3);
+}
+
+
 /* DST = (SRC1 | SRC2) & SRC3.  Return non-zero if
    DST != (SRC1 | SRC2) & SRC3.  */
 int
