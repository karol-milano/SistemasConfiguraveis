@@ -1,4 +1,4 @@
-/* Simple bitsets.
+/* Array bitsets.
    Copyright (C) 2002 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
@@ -21,57 +21,57 @@
 #include "config.h"
 #endif
 
-#include "sbitset.h"
+#include "abitset.h"
 #include <stdlib.h>
 #include <string.h>
 
 /* This file implements fixed size bitsets stored as an array
    of words.  Any unused bits in the last word must be zero.  */
 
-typedef struct sbitset_struct
+typedef struct abitset_struct
 {
   unsigned int n_bits;	/* Number of bits.  */
   bitset_word words[1];	/* The array of bits.  */
 }
-*sbitset;
+*abitset;
 
 
 struct bitset_struct
 {
   struct bbitset_struct b;
-  struct sbitset_struct s;
+  struct abitset_struct a;
 };
 
-static void sbitset_unused_clear PARAMS ((bitset));
+static void abitset_unused_clear PARAMS ((bitset));
 
-static int sbitset_small_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
+static int abitset_small_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
 				       bitset_bindex *));
 
-static void sbitset_set PARAMS ((bitset, bitset_bindex));
-static void sbitset_reset PARAMS ((bitset, bitset_bindex));
-static int sbitset_test PARAMS ((bitset, bitset_bindex));
-static int sbitset_size PARAMS ((bitset));
-static int sbitset_op1 PARAMS ((bitset, enum bitset_ops));
-static int sbitset_op2 PARAMS ((bitset, bitset, enum bitset_ops));
-static int sbitset_op3 PARAMS ((bitset, bitset, bitset, enum bitset_ops));
-static int sbitset_op4 PARAMS ((bitset, bitset, bitset, bitset,
+static void abitset_set PARAMS ((bitset, bitset_bindex));
+static void abitset_reset PARAMS ((bitset, bitset_bindex));
+static int abitset_test PARAMS ((bitset, bitset_bindex));
+static int abitset_size PARAMS ((bitset));
+static int abitset_op1 PARAMS ((bitset, enum bitset_ops));
+static int abitset_op2 PARAMS ((bitset, bitset, enum bitset_ops));
+static int abitset_op3 PARAMS ((bitset, bitset, bitset, enum bitset_ops));
+static int abitset_op4 PARAMS ((bitset, bitset, bitset, bitset,
 				enum bitset_ops));
-static int sbitset_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
+static int abitset_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
 				 bitset_bindex *));
-static int sbitset_reverse_list
+static int abitset_reverse_list
 PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
 
-#define SBITSET_N_WORDS(N) (((N) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS)
-#define SBITSET_WORDS(X) ((X)->s.words)
-#define SBITSET_N_BITS(X) ((X)->s.n_bits)
+#define ABITSET_N_WORDS(N) (((N) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS)
+#define ABITSET_WORDS(X) ((X)->a.words)
+#define ABITSET_N_BITS(X) ((X)->a.n_bits)
 
 
 /* Return size in bits of bitset SRC.  */
 static int
-sbitset_size (src)
+abitset_size (src)
      bitset src;
 {
-  return SBITSET_N_BITS (src);
+  return ABITSET_N_BITS (src);
 }
 
 
@@ -79,7 +79,7 @@ sbitset_size (src)
  *NEXT and store in array LIST.  Return with actual number of bits
  found and with *NEXT indicating where search stopped.  */
 static int
-sbitset_small_list (src, list, num, next)
+abitset_small_list (src, list, num, next)
      bitset src;
      bitset_bindex *list;
      bitset_bindex num;
@@ -90,13 +90,13 @@ sbitset_small_list (src, list, num, next)
   bitset_windex size;
   bitset_word word;
 
-  word = SBITSET_WORDS (src)[0];
+  word = ABITSET_WORDS (src)[0];
 
   /* Short circuit common case.  */
   if (!word)
     return 0;
 
-  size = SBITSET_N_BITS (src);
+  size = ABITSET_N_BITS (src);
   bitno = *next;
   if (bitno >= size)
     return 0;
@@ -139,33 +139,33 @@ sbitset_small_list (src, list, num, next)
 
 /* Set bit BITNO in bitset DST.  */
 static void
-sbitset_set (dst, bitno)
+abitset_set (dst, bitno)
      bitset dst ATTRIBUTE_UNUSED;
      bitset_bindex bitno ATTRIBUTE_UNUSED;
 {
-  /* This should never occur for sbitsets.  */
+  /* This should never occur for abitsets.  */
   abort ();
 }
 
 
 /* Reset bit BITNO in bitset DST.  */
 static void
-sbitset_reset (dst, bitno)
+abitset_reset (dst, bitno)
      bitset dst ATTRIBUTE_UNUSED;
      bitset_bindex bitno ATTRIBUTE_UNUSED;
 {
-  /* This should never occur for sbitsets.  */
+  /* This should never occur for abitsets.  */
   abort ();
 }
 
 
 /* Test bit BITNO in bitset SRC.  */
 static int
-sbitset_test (src, bitno)
+abitset_test (src, bitno)
      bitset src ATTRIBUTE_UNUSED;
      bitset_bindex bitno ATTRIBUTE_UNUSED;
 {
-  /* This should never occur for sbitsets.  */
+  /* This should never occur for abitsets.  */
   abort ();
   return 0;
 }
@@ -176,7 +176,7 @@ sbitset_test (src, bitno)
    actual number of bits found and with *NEXT indicating where search
    stopped.  */
 static int
-sbitset_reverse_list (src, list, num, next)
+abitset_reverse_list (src, list, num, next)
      bitset src;
      bitset_bindex *list;
      bitset_bindex num;
@@ -189,8 +189,8 @@ sbitset_reverse_list (src, list, num, next)
   unsigned int bitcnt;
   bitset_bindex bitoff;
   bitset_word word;
-  bitset_word *srcp = SBITSET_WORDS (src);
-  bitset_bindex n_bits = SBITSET_N_BITS (src);
+  bitset_word *srcp = ABITSET_WORDS (src);
+  bitset_bindex n_bits = ABITSET_N_BITS (src);
 
   rbitno = *next;
 
@@ -236,7 +236,7 @@ sbitset_reverse_list (src, list, num, next)
  *NEXT and store in array LIST.  Return with actual number of bits
  found and with *NEXT indicating where search stopped.  */
 static int
-sbitset_list (src, list, num, next)
+abitset_list (src, list, num, next)
      bitset src;
      bitset_bindex *list;
      bitset_bindex num;
@@ -247,7 +247,7 @@ sbitset_list (src, list, num, next)
   bitset_windex windex;
   bitset_bindex bitoff;
   bitset_windex size = src->b.csize;
-  bitset_word *srcp = SBITSET_WORDS (src);
+  bitset_word *srcp = ABITSET_WORDS (src);
   bitset_word word;
 
   bitno = *next;
@@ -268,7 +268,7 @@ sbitset_list (src, list, num, next)
     }
   else
     {
-      if (bitno >= SBITSET_N_BITS (src))
+      if (bitno >= ABITSET_N_BITS (src))
 	return 0;
 
       windex = bitno / BITSET_WORD_BITS;
@@ -340,25 +340,25 @@ sbitset_list (src, list, num, next)
 
 /* Ensure that any unused bits within the last word are clear.  */
 static inline void
-sbitset_unused_clear (dst)
+abitset_unused_clear (dst)
      bitset dst;
 {
   unsigned int last_bit;
 
-  last_bit = SBITSET_N_BITS (dst) % BITSET_WORD_BITS;
+  last_bit = ABITSET_N_BITS (dst) % BITSET_WORD_BITS;
   if (last_bit)
-    SBITSET_WORDS (dst)[dst->b.csize - 1] &=
+    ABITSET_WORDS (dst)[dst->b.csize - 1] &=
       (bitset_word) ((1 << last_bit) - 1);
 }
 
 
 static int
-sbitset_op1 (dst, op)
+abitset_op1 (dst, op)
      bitset dst;
      enum bitset_ops op;
 {
   unsigned int i;
-  bitset_word *dstp = SBITSET_WORDS (dst);
+  bitset_word *dstp = ABITSET_WORDS (dst);
   unsigned int bytes;
 
   bytes = sizeof (bitset_word) * dst->b.csize;
@@ -371,7 +371,7 @@ sbitset_op1 (dst, op)
 
     case BITSET_OP_ONES:
       memset (dstp, ~0, bytes);
-      sbitset_unused_clear (dst);
+      abitset_unused_clear (dst);
       break;
 
     case BITSET_OP_EMPTY_P:
@@ -389,22 +389,16 @@ sbitset_op1 (dst, op)
 
 
 static int
-sbitset_op2 (dst, src, op)
+abitset_op2 (dst, src, op)
      bitset dst;
      bitset src;
      enum bitset_ops op;
 {
   unsigned int i;
-  bitset_word *srcp = SBITSET_WORDS (src);
-  bitset_word *dstp = SBITSET_WORDS (dst);
+  bitset_word *srcp = ABITSET_WORDS (src);
+  bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-#ifdef ENABLE_CHECKING
-  /* Check for compatiblity.  */
-  if (SBITSET_N_BITS (src) != SBITSET_N_BITS (dst))
-    abort ();
-#endif
-
   switch (op)
     {
     case BITSET_OP_COPY:
@@ -416,7 +410,7 @@ sbitset_op2 (dst, src, op)
     case BITSET_OP_NOT:
       for (i = 0; i < size; i++)
 	*dstp++ = ~(*srcp++);
-      sbitset_unused_clear (dst);
+      abitset_unused_clear (dst);
       break;
 
     case BITSET_OP_EQUAL_P:
@@ -446,7 +440,7 @@ sbitset_op2 (dst, src, op)
 
 
 static int
-sbitset_op3 (dst, src1, src2, op)
+abitset_op3 (dst, src1, src2, op)
      bitset dst;
      bitset src1;
      bitset src2;
@@ -454,18 +448,11 @@ sbitset_op3 (dst, src1, src2, op)
 {
   unsigned int i;
   int changed = 0;
-  bitset_word *src1p = SBITSET_WORDS (src1);
-  bitset_word *src2p = SBITSET_WORDS (src2);
-  bitset_word *dstp = SBITSET_WORDS (dst);
+  bitset_word *src1p = ABITSET_WORDS (src1);
+  bitset_word *src2p = ABITSET_WORDS (src2);
+  bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-#ifdef ENABLE_CHECKING
-  /* Check for compatiblity.  */
-  if (SBITSET_N_BITS (src1) != SBITSET_N_BITS (dst)
-      SBITSET_N_BITS (src2) != SBITSET_N_BITS (dst))
-    abort ();
-#endif
-
   switch (op)
     {
     case BITSET_OP_OR:
@@ -529,7 +516,7 @@ sbitset_op3 (dst, src1, src2, op)
 
 
 static int
-sbitset_op4 (dst, src1, src2, src3, op)
+abitset_op4 (dst, src1, src2, src3, op)
      bitset dst;
      bitset src1;
      bitset src2;
@@ -538,20 +525,12 @@ sbitset_op4 (dst, src1, src2, src3, op)
 {
   unsigned int i;
   int changed = 0;
-  bitset_word *src1p = SBITSET_WORDS (src1);
-  bitset_word *src2p = SBITSET_WORDS (src2);
-  bitset_word *src3p = SBITSET_WORDS (src3);
-  bitset_word *dstp = SBITSET_WORDS (dst);
+  bitset_word *src1p = ABITSET_WORDS (src1);
+  bitset_word *src2p = ABITSET_WORDS (src2);
+  bitset_word *src3p = ABITSET_WORDS (src3);
+  bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-#ifdef ENABLE_CHECKING
-  /* Check for compatiblity.  */
-  if (SBITSET_N_BITS (src1) != SBITSET_N_BITS (dst)
-      || SBITSET_N_BITS (src2) != SBITSET_N_BITS (dst)
-      || SBITSET_N_BITS (src3) != SBITSET_N_BITS (dst))
-    abort ();
-#endif
-
   switch (op)
     {
     case BITSET_OP_OR_AND:
@@ -602,71 +581,71 @@ sbitset_op4 (dst, src1, src2, src3, op)
 
 
 /* Vector of operations for single word bitsets.  */
-struct bitset_ops_struct sbitset_small_ops = {
-  sbitset_set,
-  sbitset_reset,
-  sbitset_test,
-  sbitset_size,
-  sbitset_op1,
-  sbitset_op2,
-  sbitset_op3,
-  sbitset_op4,
-  sbitset_small_list,
-  sbitset_reverse_list,
+struct bitset_ops_struct abitset_small_ops = {
+  abitset_set,
+  abitset_reset,
+  abitset_test,
+  abitset_size,
+  abitset_op1,
+  abitset_op2,
+  abitset_op3,
+  abitset_op4,
+  abitset_small_list,
+  abitset_reverse_list,
   NULL,
   BITSET_ARRAY
 };
 
 
 /* Vector of operations for multiple word bitsets.  */
-struct bitset_ops_struct sbitset_ops = {
-  sbitset_set,
-  sbitset_reset,
-  sbitset_test,
-  sbitset_size,
-  sbitset_op1,
-  sbitset_op2,
-  sbitset_op3,
-  sbitset_op4,
-  sbitset_list,
-  sbitset_reverse_list,
+struct bitset_ops_struct abitset_ops = {
+  abitset_set,
+  abitset_reset,
+  abitset_test,
+  abitset_size,
+  abitset_op1,
+  abitset_op2,
+  abitset_op3,
+  abitset_op4,
+  abitset_list,
+  abitset_reverse_list,
   NULL,
   BITSET_ARRAY
 };
 
 
 int
-sbitset_bytes (n_bits)
+abitset_bytes (n_bits)
      bitset_bindex n_bits;
 {
   unsigned int bytes, size;
 
-  size = SBITSET_N_WORDS (n_bits);
+  size = ABITSET_N_WORDS (n_bits);
   bytes = size * sizeof (bitset_word);
   return sizeof (struct bitset_struct) + bytes - sizeof (bitset_word);
 }
 
 
 bitset
-sbitset_init (bset, n_bits)
+abitset_init (bset, n_bits)
      bitset bset;
      bitset_bindex n_bits;
 {
   bitset_windex size;
 
-  size = SBITSET_N_WORDS (n_bits);
-  SBITSET_N_BITS (bset) = n_bits;
+  size = ABITSET_N_WORDS (n_bits);
+  ABITSET_N_BITS (bset) = n_bits;
 
   /* Use optimized routines if bitset fits within a single word.
      There is probably little merit if using caching since
      the small bitset will always fit in the cache.  */
   if (size == 1)
-    bset->b.ops = &sbitset_small_ops;
+    bset->b.ops = &abitset_small_ops;
   else
-    bset->b.ops = &sbitset_ops;
+    bset->b.ops = &abitset_ops;
 
   bset->b.cindex = 0;
   bset->b.csize = size;
-  bset->b.cdata = SBITSET_WORDS (bset);
+  bset->b.cdata = ABITSET_WORDS (bset);
   return bset;
 }
