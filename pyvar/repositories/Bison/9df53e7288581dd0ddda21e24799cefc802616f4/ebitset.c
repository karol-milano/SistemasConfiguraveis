@@ -52,7 +52,7 @@
 
 /* Number of bits stored in each element.  */
 #define EBITSET_ELT_BITS \
-  ((unsigned int) (EBITSET_ELT_WORDS * BITSET_WORD_BITS))
+  ((unsigned) (EBITSET_ELT_WORDS * BITSET_WORD_BITS))
 
 /* Ebitset element.  We use an array of bits.  */
 typedef struct ebitset_elt_struct
@@ -433,7 +433,7 @@ ebitset_equal_p (bitset dst, bitset src)
 
   for (j = 0; j < EBITSET_SIZE (src); j++)
     {
-      unsigned int i;
+      unsigned i;
       ebitset_elt *selt = selts[j];
       ebitset_elt *delt = delts[j];
 
@@ -570,7 +570,7 @@ ebitset_list_reverse (bitset bset, bitset_bindex *list,
   bitset_bindex n_bits;
   bitset_bindex bitno;
   bitset_bindex rbitno;
-  unsigned int bcount;
+  unsigned bcount;
   bitset_bindex boffset;
   bitset_windex windex;
   bitset_windex eindex;
@@ -836,7 +836,7 @@ ebitset_list (bitset bset, bitset_bindex *list,
 static inline void
 ebitset_unused_clear (bitset dst)
 {
-  unsigned int last_bit;
+  unsigned last_bit;
   bitset_bindex n_bits;
 
   n_bits = BITSET_NBITS_ (dst);
@@ -923,7 +923,7 @@ ebitset_empty_p (bitset dst)
 static void
 ebitset_not (bitset dst, bitset src)
 {
-  unsigned int i;
+  unsigned i;
   ebitset_elt *selt;
   ebitset_elt *delt;
   bitset_windex j;
@@ -965,7 +965,7 @@ ebitset_subset_p (bitset dst, bitset src)
 
   for (j = 0; j < ssize; j++)
     {
-      unsigned int i;
+      unsigned i;
       ebitset_elt *selt;
       ebitset_elt *delt;
 
@@ -1007,7 +1007,7 @@ ebitset_disjoint_p (bitset dst, bitset src)
 
   for (j = 0; j < ssize; j++)
     {
-      unsigned int i;
+      unsigned i;
       ebitset_elt *selt;
       ebitset_elt *delt;
 
@@ -1040,7 +1040,7 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
   bitset_word *srcp2;
   bitset_word *dstp;
   bool changed = false;
-  unsigned int i;
+  unsigned i;
   bitset_windex j;
 
   ebitset_resize (dst, max (BITSET_NBITS_ (src1), BITSET_NBITS_ (src2)));
