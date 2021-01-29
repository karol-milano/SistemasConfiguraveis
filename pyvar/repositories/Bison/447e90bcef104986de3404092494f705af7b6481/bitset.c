@@ -30,16 +30,11 @@
 
 const char * const bitset_type_names[] = BITSET_TYPE_NAMES;
 
-static void bitset_print PARAMS ((FILE *, bitset, int));
-static int bitset_op4_cmp PARAMS ((bitset, bitset, bitset, bitset, int));
-
 
 /* Return number of bytes required to create a N_BIT bitset
    of TYPE.  The bitset may grow to require more bytes than this.  */
 size_t
-bitset_bytes (type, n_bits)
-     enum_bitset_type type;
-     bitset_bindex n_bits;
+bitset_bytes (enum bitset_type type, bitset_bindex n_bits)
 {
   size_t bytes;
 
@@ -70,14 +65,11 @@ bitset_bytes (type, n_bits)
 
 /* Initialise bitset BSET of TYPE for N_BITS.  */
 bitset
-bitset_init (bset, n_bits, type)
-     bitset bset;
-     bitset_bindex n_bits;
-     enum_bitset_type type;
+bitset_init (bitset bset, bitset_bindex n_bits, enum bitset_type type)
 {
   if (bitset_stats_enabled)
     return bitset_stats_init (bset, n_bits, type);
-  
+
   switch (type)
     {
     case BITSET_ARRAY:
@@ -99,9 +91,7 @@ bitset_init (bset, n_bits, type)
    specified by ATTR.  For variable size bitsets, N_BITS is only a
    hint and may be zero.  */
 enum bitset_type
-bitset_type_choose (n_bits, attr)
-     bitset_bindex n_bits ATTRIBUTE_UNUSED;
-     unsigned int attr;
+bitset_type_choose (bitset_bindex n_bits ATTRIBUTE_UNUSED, unsigned int attr)
 {
   enum bitset_type type;
 
@@ -129,9 +119,7 @@ bitset_type_choose (n_bits, attr)
 
 /* Create a bitset of N_BITS of type TYPE.  */
 bitset
-bitset_alloc (n_bits, type)
-     bitset_bindex n_bits;
-     enum_bitset_type type;
+bitset_alloc (bitset_bindex n_bits, enum bitset_type type)
 {
   size_t bytes;
   bitset bset;
@@ -150,10 +138,8 @@ bitset_alloc (n_bits, type)
 
 /* Create a bitset of N_BITS of type TYPE.  */
 bitset
-bitset_obstack_alloc (bobstack, n_bits, type)
-     struct obstack *bobstack;
-     bitset_bindex n_bits;
-     enum_bitset_type type;
+bitset_obstack_alloc (struct obstack *bobstack,
+		      bitset_bindex n_bits, enum bitset_type type)
 {
   size_t bytes;
   bitset bset;
@@ -170,9 +156,7 @@ bitset_obstack_alloc (bobstack, n_bits, type)
 /* Create a bitset of N_BITS and with attribute hints specified by
    ATTR.  */
 bitset
-bitset_create (n_bits, attr)
-     bitset_bindex n_bits;
-     unsigned int attr;
+bitset_create (bitset_bindex n_bits, unsigned int attr)
 {
   enum bitset_type type;
 
@@ -184,8 +168,7 @@ bitset_create (n_bits, attr)
 
 /* Free bitset BSET.  */
 void
-bitset_free (bset)
-     bitset bset;
+bitset_free (bitset bset)
 {
   BITSET_FREE_ (bset);
   free (bset);
@@ -194,8 +177,7 @@ bitset_free (bset)
 
 /* Free bitset BSET allocated on obstack.  */
 void
-bitset_obstack_free (bset)
-     bitset bset;
+bitset_obstack_free (bitset bset)
 {
   BITSET_FREE_ (bset);
 }
@@ -203,23 +185,21 @@ bitset_obstack_free (bset)
 
 /* Return bitset type.  */
 enum bitset_type
-bitset_type_get (bset)
-   bitset bset;
+bitset_type_get (bitset bset)
 {
    enum bitset_type type;
 
    type = BITSET_TYPE_ (bset);
    if (type != BITSET_STATS)
       return type;
-   
+
    return bitset_stats_type_get (bset);
 }
 
 
 /* Return name of bitset type.  */
 const char *
-bitset_type_name_get (bset)
-     bitset bset;
+bitset_type_name_get (bitset bset)
 {
   enum bitset_type type;
 
@@ -232,9 +212,7 @@ bitset_type_name_get (bset)
 /* Find next bit set in SRC starting from and including BITNO.
    Return BITSET_BINDEX_MAX if SRC empty.  */
 bitset_bindex
-bitset_next (src, bitno)
-     bitset src;
-     bitset_bindex bitno;
+bitset_next (bitset src, bitset_bindex bitno)
 {
   bitset_bindex val;
   bitset_bindex next = bitno;
@@ -248,9 +226,7 @@ bitset_next (src, bitno)
 /* Find previous bit set in SRC starting from and including BITNO.
    Return BITSET_BINDEX_MAX if SRC empty.  */
 bitset_bindex
-bitset_prev (src, bitno)
-     bitset src;
-     bitset_bindex bitno;
+bitset_prev (bitset src, bitset_bindex bitno)
 {
   bitset_bindex val;
   bitset_bindex next = bitno;
@@ -263,8 +239,7 @@ bitset_prev (src, bitno)
 
 /* Find first set bit.   */
 bitset_bindex
-bitset_first (src)
-     bitset src;
+bitset_first (bitset src)
 {
   return bitset_next (src, 0);
 }
@@ -272,8 +247,7 @@ bitset_first (src)
 
 /* Find last set bit.   */
 bitset_bindex
-bitset_last (src)
-     bitset src;
+bitset_last (bitset src)
 {
   return bitset_prev (src, 0);
 }
@@ -281,9 +255,7 @@ bitset_last (src)
 
 /* Return non-zero if BITNO in SRC is the only set bit.  */
 int
-bitset_only_set_p (src, bitno)
-     bitset src;
-     bitset_bindex bitno;
+bitset_only_set_p (bitset src, bitset_bindex bitno)
 {
   bitset_bindex val[2];
   bitset_bindex next = 0;
@@ -296,10 +268,7 @@ bitset_only_set_p (src, bitno)
 
 /* Print contents of bitset BSET to FILE.   */
 static void
-bitset_print (file, bset, verbose)
-     FILE *file;
-     bitset bset;
-     int verbose;
+bitset_print (FILE *file, bitset bset, int verbose)
 {
   unsigned int pos;
   bitset_bindex i;
@@ -329,9 +298,7 @@ bitset_print (file, bset, verbose)
 
 /* Dump bitset BSET to FILE.  */
 void
-bitset_dump (file, bset)
-     FILE *file;
-     bitset bset;
+bitset_dump (FILE *file, bitset bset)
 {
   bitset_print (file, bset, 0);
 }
@@ -340,7 +307,7 @@ bitset_dump (file, bset)
 
 /* Release memory associated with bitsets.  */
 void
-bitset_release_memory ()
+bitset_release_memory (void)
 {
   lbitset_release_memory ();
   ebitset_release_memory ();
@@ -350,9 +317,7 @@ bitset_release_memory ()
 
 /* Toggle bit BITNO in bitset BSET and return non-zero if not set.  */
 int
-bitset_toggle_ (bset, bitno)
-    bitset bset;
-    bitset_bindex bitno;
+bitset_toggle_ (bitset bset, bitset_bindex bitno)
 {
   /* This routine is for completeness.  It could be optimized if
      required.  */
@@ -371,14 +336,13 @@ bitset_toggle_ (bset, bitno)
 
 /* Return number of bits set in bitset SRC.  */
 bitset_bindex
-bitset_count_ (src)
-     bitset src;
+bitset_count_ (bitset src)
 {
   bitset_bindex list[BITSET_LIST_SIZE];
   bitset_bindex next;
   bitset_bindex num;
   bitset_bindex count;
-  
+
   /* This could be greatly sped up by adding a count method for each
      bitset implementation that uses a direct technique (based on
      masks) for counting the number of bits set in a word.  */
@@ -387,18 +351,16 @@ bitset_count_ (src)
   for (count = 0; (num = bitset_list (src, list, BITSET_LIST_SIZE, &next));
        count += num)
     continue;
-  
+
   return count;
 }
 
 
-/* DST = SRC.  Return non-zero if DST != SRC. 
+/* DST = SRC.  Return non-zero if DST != SRC.
    This is a fallback for the case where SRC and DST are different
    bitset types.  */
 int
-bitset_copy_ (dst, src)
-     bitset dst;
-     bitset src;
+bitset_copy_ (bitset dst, bitset src)
 {
   bitset_bindex i;
   bitset_iterator iter;
@@ -418,12 +380,8 @@ bitset_copy_ (dst, src)
 /* This is a fallback for implementations that do not support
    four operand operations.  */
 static inline int
-bitset_op4_cmp (dst, src1, src2, src3, op)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
-     enum_bitset_ops op;
+bitset_op4_cmp (bitset dst, bitset src1, bitset src2, bitset src3,
+		enum bitset_ops op)
 {
   int changed = 0;
   int stats_enabled_save;
@@ -463,11 +421,7 @@ bitset_op4_cmp (dst, src1, src2, src3, op)
 
 /* DST = (SRC1 & SRC2) | SRC3.  */
 void
-bitset_and_or_ (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+bitset_and_or_ (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   bitset_and_or_cmp_ (dst, src1, src2, src3);
 }
@@ -476,11 +430,7 @@ bitset_and_or_ (dst, src1, src2, src3)
 /* DST = (SRC1 & SRC2) | SRC3.  Return non-zero if
    DST != (SRC1 & SRC2) | SRC3.  */
 int
-bitset_and_or_cmp_ (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+bitset_and_or_cmp_ (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   return bitset_op4_cmp (dst, src1, src2, src3, BITSET_OP_AND_OR);
 }
@@ -488,11 +438,7 @@ bitset_and_or_cmp_ (dst, src1, src2, src3)
 
 /* DST = (SRC1 & ~SRC2) | SRC3.  */
 void
-bitset_andn_or_ (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+bitset_andn_or_ (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   bitset_andn_or_cmp_ (dst, src1, src2, src3);
 }
@@ -501,11 +447,7 @@ bitset_andn_or_ (dst, src1, src2, src3)
 /* DST = (SRC1 & ~SRC2) | SRC3.  Return non-zero if
    DST != (SRC1 & ~SRC2) | SRC3.  */
 int
-bitset_andn_or_cmp_ (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+bitset_andn_or_cmp_ (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   return bitset_op4_cmp (dst, src1, src2, src3, BITSET_OP_ANDN_OR);
 }
@@ -513,11 +455,7 @@ bitset_andn_or_cmp_ (dst, src1, src2, src3)
 
 /* DST = (SRC1 | SRC2) & SRC3.  */
 void
-bitset_or_and_ (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+bitset_or_and_ (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   bitset_or_and_cmp_ (dst, src1, src2, src3);
 }
@@ -526,11 +464,7 @@ bitset_or_and_ (dst, src1, src2, src3)
 /* DST = (SRC1 | SRC2) & SRC3.  Return non-zero if
    DST != (SRC1 | SRC2) & SRC3.  */
 int
-bitset_or_and_cmp_ (dst, src1, src2, src3)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
+bitset_or_and_cmp_ (bitset dst, bitset src1, bitset src2, bitset src3)
 {
   return bitset_op4_cmp (dst, src1, src2, src3, BITSET_OP_OR_AND);
 }
@@ -538,8 +472,7 @@ bitset_or_and_cmp_ (dst, src1, src2, src3)
 
 /* Function to be called from debugger to print bitset.  */
 void
-debug_bitset (bset)
-     bitset bset;
+debug_bitset (bitset bset)
 {
   if (bset)
     bitset_print (stderr, bset, 1);
