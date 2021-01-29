@@ -2,57 +2,67 @@
    Copyright (C) 2002 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
-This program is free software; you can redistribute it and/or modify
-it under the terms of the GNU General Public License as published by
-the Free Software Foundation; either version 2 of the License, or
-(at your option) any later version.
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2 of the License, or
+   (at your option) any later version.
 
-This program is distributed in the hope that it will be useful,
-but WITHOUT ANY WARRANTY; without even the implied warranty of
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-GNU General Public License for more details.
+   This program is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
 
-You should have received a copy of the GNU General Public License
-along with this program; if not, write to the Free Software
-Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
+   You should have received a copy of the GNU General Public License
+   along with this program; if not, write to the Free Software
+   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
 
-#include "bitset.h"
+#include "sbitset.h"
 #include <stdlib.h>
-
-# if WITH_DMALLOC
-#  define DMALLOC_FUNC_CHECK
-#  include <dmalloc.h>
-# endif /* WITH_DMALLOC */
+#include <string.h>
 
 /* This file implements fixed size bitsets stored as an array
    of words.  Any unused bits in the last word must be zero.  */
 
-static void sbitset_unused_clear PARAMS((bitset));
-
-static int sbitset_small_list PARAMS((bitset, bitset_bindex *, bitset_bindex,
-				      bitset_bindex *));
-
-static void sbitset_set PARAMS((bitset, bitset_bindex));
-static void sbitset_reset PARAMS((bitset, bitset_bindex));
-static int sbitset_test PARAMS((bitset, bitset_bindex));
-static int sbitset_size PARAMS((bitset));
-static int sbitset_op1 PARAMS((bitset, enum bitset_ops));
-static int sbitset_op2 PARAMS((bitset, bitset, enum bitset_ops));
-static int sbitset_op3 PARAMS((bitset, bitset, bitset, enum bitset_ops));
-static int sbitset_op4 PARAMS((bitset, bitset, bitset, bitset,
-			       enum bitset_ops));
-static int sbitset_list PARAMS((bitset, bitset_bindex *, bitset_bindex,
-				bitset_bindex *));
-static int sbitset_reverse_list PARAMS((bitset, bitset_bindex *, bitset_bindex,
-					bitset_bindex *));
+typedef struct sbitset_struct
+{
+  unsigned int n_bits;	/* Number of bits.  */
+  bitset_word words[1];	/* The array of bits.  */
+}
+*sbitset;
+
+
+struct bitset_struct
+{
+  struct bbitset_struct b;
+  struct sbitset_struct s;
+};
+
+static void sbitset_unused_clear PARAMS ((bitset));
+
+static int sbitset_small_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
+				       bitset_bindex *));
+
+static void sbitset_set PARAMS ((bitset, bitset_bindex));
+static void sbitset_reset PARAMS ((bitset, bitset_bindex));
+static int sbitset_test PARAMS ((bitset, bitset_bindex));
+static int sbitset_size PARAMS ((bitset));
+static int sbitset_op1 PARAMS ((bitset, enum bitset_ops));
+static int sbitset_op2 PARAMS ((bitset, bitset, enum bitset_ops));
+static int sbitset_op3 PARAMS ((bitset, bitset, bitset, enum bitset_ops));
+static int sbitset_op4 PARAMS ((bitset, bitset, bitset, bitset,
+				enum bitset_ops));
+static int sbitset_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
+				 bitset_bindex *));
+static int sbitset_reverse_list
+PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
 
 #define SBITSET_N_WORDS(N) (((N) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS)
-#define SBITSET_WORDS(X) ((X)->u.s.words)
-#define SBITSET_N_BITS(X) ((X)->u.s.n_bits)
+#define SBITSET_WORDS(X) ((X)->s.words)
+#define SBITSET_N_BITS(X) ((X)->s.n_bits)
 
 
 /* Return size in bits of bitset SRC.  */
@@ -60,13 +70,13 @@ static int
 sbitset_size (src)
      bitset src;
 {
-    return SBITSET_N_BITS (src);
+  return SBITSET_N_BITS (src);
 }
 
 
 /* Find list of up to NUM bits set in BSET starting from and including
-   *NEXT and store in array LIST.  Return with actual number of bits
-   found and with *NEXT indicating where search stopped.  */
+ *NEXT and store in array LIST.  Return with actual number of bits
+ found and with *NEXT indicating where search stopped.  */
 static int
 sbitset_small_list (src, list, num, next)
      bitset src;
@@ -96,30 +106,30 @@ sbitset_small_list (src, list, num, next)
      of the word of interest.  */
 
   if (num >= BITSET_WORD_BITS)
-  {
+    {
       for (count = 0; word; bitno++)
-      {
+	{
 	  if (word & 1)
-	      list[count++] = bitno;
+	    list[count++] = bitno;
 	  word >>= 1;
-      }
-  }
+	}
+    }
   else
-  {
+    {
       for (count = 0; word; bitno++)
-      {
+	{
 	  if (word & 1)
-	  {
+	    {
 	      list[count++] = bitno;
 	      if (count >= num)
-	      {
+		{
 		  bitno++;
 		  break;
-	      }
-	  }
+		}
+	    }
 	  word >>= 1;
-      }
-  }
+	}
+    }
 
   *next = bitno;
   return count;
@@ -132,8 +142,8 @@ sbitset_set (dst, bitno)
      bitset dst ATTRIBUTE_UNUSED;
      bitset_bindex bitno ATTRIBUTE_UNUSED;
 {
-    /* This should never occur for sbitsets.  */
-    abort ();
+  /* This should never occur for sbitsets.  */
+  abort ();
 }
 
 
@@ -143,8 +153,8 @@ sbitset_reset (dst, bitno)
      bitset dst ATTRIBUTE_UNUSED;
      bitset_bindex bitno ATTRIBUTE_UNUSED;
 {
-    /* This should never occur for sbitsets.  */
-    abort ();
+  /* This should never occur for sbitsets.  */
+  abort ();
 }
 
 
@@ -154,9 +164,9 @@ sbitset_test (src, bitno)
      bitset src ATTRIBUTE_UNUSED;
      bitset_bindex bitno ATTRIBUTE_UNUSED;
 {
-    /* This should never occur for sbitsets.  */
-    abort ();
-    return 0;
+  /* This should never occur for sbitsets.  */
+  abort ();
+  return 0;
 }
 
 
@@ -187,7 +197,7 @@ sbitset_reverse_list (src, list, num, next)
      of the word of interest.  */
 
   if (rbitno >= n_bits)
-      return 0;
+    return 0;
 
   count = 0;
 
@@ -198,7 +208,7 @@ sbitset_reverse_list (src, list, num, next)
   bitoff = index * BITSET_WORD_BITS;
 
   for (; index != ~0U; index--, bitoff -= BITSET_WORD_BITS,
-	   bitcnt = BITSET_WORD_BITS - 1)
+	 bitcnt = BITSET_WORD_BITS - 1)
     {
       word = srcp[index] << (BITSET_WORD_BITS - 1 - bitcnt);
       for (; word; bitcnt--)
@@ -222,8 +232,8 @@ sbitset_reverse_list (src, list, num, next)
 
 
 /* Find list of up to NUM bits set in BSET starting from and including
-   *NEXT and store in array LIST.  Return with actual number of bits
-   found and with *NEXT indicating where search stopped.  */
+ *NEXT and store in array LIST.  Return with actual number of bits
+ found and with *NEXT indicating where search stopped.  */
 static int
 sbitset_list (src, list, num, next)
      bitset src;
@@ -235,17 +245,17 @@ sbitset_list (src, list, num, next)
   bitset_bindex count;
   bitset_windex index;
   bitset_bindex bitoff;
-  bitset_windex size = src->csize;
+  bitset_windex size = src->b.csize;
   bitset_word *srcp = SBITSET_WORDS (src);
   bitset_word word;
 
   bitno = *next;
 
   count = 0;
-  if (! bitno)
+  if (!bitno)
     {
       /* Many bitsets are zero, so make this common case fast.  */
-      for (index = 0; index < size && ! srcp[index]; index++)
+      for (index = 0; index < size && !srcp[index]; index++)
 	continue;
       if (index >= size)
 	return 0;
@@ -292,18 +302,18 @@ sbitset_list (src, list, num, next)
 
   for (; index < size; index++, bitoff += BITSET_WORD_BITS)
     {
-      if (! (word = srcp[index]))
+      if (!(word = srcp[index]))
 	continue;
 
       if ((count + BITSET_WORD_BITS) < num)
-      {
-	for (bitno = bitoff; word; bitno++)
-	  {
-	    if (word & 1)
-	      list[count++] = bitno;
-	    word >>= 1;
-	  }
-      }
+	{
+	  for (bitno = bitoff; word; bitno++)
+	    {
+	      if (word & 1)
+		list[count++] = bitno;
+	      word >>= 1;
+	    }
+	}
       else
 	{
 	  for (bitno = bitoff; word; bitno++)
@@ -336,7 +346,8 @@ sbitset_unused_clear (dst)
 
   last_bit = SBITSET_N_BITS (dst) % BITSET_WORD_BITS;
   if (last_bit)
-    SBITSET_WORDS (dst)[dst->csize - 1] &= (bitset_word)((1 << last_bit) - 1);
+    SBITSET_WORDS (dst)[dst->b.csize - 1] &=
+      (bitset_word) ((1 << last_bit) - 1);
 }
 
 
@@ -349,21 +360,21 @@ sbitset_op1 (dst, op)
   bitset_word *dstp = SBITSET_WORDS (dst);
   unsigned int bytes;
 
-  bytes = sizeof (bitset_word) * dst->csize;
+  bytes = sizeof (bitset_word) * dst->b.csize;
 
   switch (op)
     {
-    case BITSET_ZERO:
+    case BITSET_OP_ZERO:
       memset (dstp, 0, bytes);
       break;
 
-    case BITSET_ONES:
+    case BITSET_OP_ONES:
       memset (dstp, ~0, bytes);
       sbitset_unused_clear (dst);
       break;
 
-    case BITSET_EMPTY_P:
-      for (i = 0; i < dst->csize; i++)
+    case BITSET_OP_EMPTY_P:
+      for (i = 0; i < dst->b.csize; i++)
 	if (dstp[i])
 	  return 0;
       break;
@@ -385,42 +396,46 @@ sbitset_op2 (dst, src, op)
   unsigned int i;
   bitset_word *srcp = SBITSET_WORDS (src);
   bitset_word *dstp = SBITSET_WORDS (dst);
-  bitset_windex size = dst->csize;
+  bitset_windex size = dst->b.csize;
 
 #ifdef ENABLE_CHECKING
   /* Check for compatiblity.  */
-  if (src->ops != dst->ops || SBITSET_N_BITS (src) != SBITSET_N_BITS (dst))
+  if (SBITSET_N_BITS (src) != SBITSET_N_BITS (dst))
     abort ();
 #endif
 
   switch (op)
     {
-    case BITSET_COPY:
+    case BITSET_OP_COPY:
       if (srcp == dstp)
 	break;
       memcpy (dstp, srcp, sizeof (bitset_word) * size);
       break;
 
-    case BITSET_NOT:
+    case BITSET_OP_NOT:
       for (i = 0; i < size; i++)
 	*dstp++ = ~(*srcp++);
       sbitset_unused_clear (dst);
       break;
 
-    case BITSET_EQUAL_P:
+    case BITSET_OP_EQUAL_P:
       for (i = 0; i < size; i++)
-	if (*dstp++ != *srcp++)
+	if (*srcp++ != *dstp++)
 	  return 0;
       break;
-
-    case BITSET_SUBSET_P:
+      
+    case BITSET_OP_SUBSET_P:
       for (i = 0; i < size; i++, dstp++, srcp++)
-	{
-	  if (*dstp != (*srcp | *dstp))
-	    return 0;
-	}
+	if (*dstp != (*srcp | *dstp))
+	  return 0;
       break;
-
+      
+    case BITSET_OP_DISJOINT_P:
+      for (i = 0; i < size; i++)
+	if (*srcp++ & *dstp++)
+	  return 0;
+      break;
+      
     default:
       abort ();
     }
@@ -441,18 +456,18 @@ sbitset_op3 (dst, src1, src2, op)
   bitset_word *src1p = SBITSET_WORDS (src1);
   bitset_word *src2p = SBITSET_WORDS (src2);
   bitset_word *dstp = SBITSET_WORDS (dst);
-  bitset_windex size = dst->csize;
+  bitset_windex size = dst->b.csize;
 
 #ifdef ENABLE_CHECKING
   /* Check for compatiblity.  */
-  if (src1->ops != dst->ops || SBITSET_N_BITS (src1) != SBITSET_N_BITS (dst)
-      || src2->ops != dst->ops || SBITSET_N_BITS (src2) != SBITSET_N_BITS (dst))
+  if (SBITSET_N_BITS (src1) != SBITSET_N_BITS (dst)
+      SBITSET_N_BITS (src2) != SBITSET_N_BITS (dst))
     abort ();
 #endif
 
   switch (op)
     {
-    case BITSET_OR:
+    case BITSET_OP_OR:
       for (i = 0; i < size; i++, dstp++)
 	{
 	  bitset_word tmp = *src1p++ | *src2p++;
@@ -465,7 +480,7 @@ sbitset_op3 (dst, src1, src2, op)
 	}
       break;
 
-    case BITSET_AND:
+    case BITSET_OP_AND:
       for (i = 0; i < size; i++, dstp++)
 	{
 	  bitset_word tmp = *src1p++ & *src2p++;
@@ -478,7 +493,7 @@ sbitset_op3 (dst, src1, src2, op)
 	}
       break;
 
-    case BITSET_XOR:
+    case BITSET_OP_XOR:
       for (i = 0; i < size; i++, dstp++)
 	{
 	  bitset_word tmp = *src1p++ ^ *src2p++;
@@ -491,7 +506,7 @@ sbitset_op3 (dst, src1, src2, op)
 	}
       break;
 
-    case BITSET_ANDN:
+    case BITSET_OP_ANDN:
       for (i = 0; i < size; i++, dstp++)
 	{
 	  bitset_word tmp = *src1p++ & ~(*src2p++);
@@ -504,7 +519,7 @@ sbitset_op3 (dst, src1, src2, op)
 	}
       break;
 
-    case BITSET_ORN:
+    case BITSET_OP_ORN:
       for (i = 0; i < size; i++, dstp++)
 	{
 	  bitset_word tmp = *src1p++ | ~(*src2p++);
@@ -540,19 +555,19 @@ sbitset_op4 (dst, src1, src2, src3, op)
   bitset_word *src2p = SBITSET_WORDS (src2);
   bitset_word *src3p = SBITSET_WORDS (src3);
   bitset_word *dstp = SBITSET_WORDS (dst);
-  bitset_windex size = dst->csize;
+  bitset_windex size = dst->b.csize;
 
 #ifdef ENABLE_CHECKING
   /* Check for compatiblity.  */
-  if (src1->ops != dst->ops || SBITSET_N_BITS (src1) != SBITSET_N_BITS (dst)
-      || src2->ops != dst->ops || SBITSET_N_BITS (src2) != SBITSET_N_BITS (dst)
-      || src3->ops != dst->ops || SBITSET_N_BITS (src3) != SBITSET_N_BITS (dst))
+  if (SBITSET_N_BITS (src1) != SBITSET_N_BITS (dst)
+      || SBITSET_N_BITS (src2) != SBITSET_N_BITS (dst)
+      || SBITSET_N_BITS (src3) != SBITSET_N_BITS (dst))
     abort ();
 #endif
 
   switch (op)
     {
-    case BITSET_OR_AND:
+    case BITSET_OP_OR_AND:
       for (i = 0; i < size; i++, dstp++)
 	{
 	  bitset_word tmp = (*src1p++ | *src2p++) & *src3p++;
@@ -565,7 +580,7 @@ sbitset_op4 (dst, src1, src2, src3, op)
 	}
       break;
 
-    case BITSET_AND_OR:
+    case BITSET_OP_AND_OR:
       for (i = 0; i < size; i++, dstp++)
 	{
 	  bitset_word tmp = (*src1p++ & *src2p++) | *src3p++;
@@ -578,7 +593,7 @@ sbitset_op4 (dst, src1, src2, src3, op)
 	}
       break;
 
-    case BITSET_ANDN_OR:
+    case BITSET_OP_ANDN_OR:
       for (i = 0; i < size; i++, dstp++)
 	{
 	  bitset_word tmp = (*src1p++ & ~(*src2p++)) | *src3p++;
@@ -600,38 +615,36 @@ sbitset_op4 (dst, src1, src2, src3, op)
 
 
 /* Vector of operations for single word bitsets.  */
-struct bitset_ops_struct sbitset_small_ops =
-  {
-    sbitset_set,
-    sbitset_reset,
-    sbitset_test,
-    sbitset_size,
-    sbitset_op1,
-    sbitset_op2,
-    sbitset_op3,
-    sbitset_op4,
-    sbitset_small_list,
-    sbitset_reverse_list,
-    NULL,
-    BITSET_ARRAY
-  };
+struct bitset_ops_struct sbitset_small_ops = {
+  sbitset_set,
+  sbitset_reset,
+  sbitset_test,
+  sbitset_size,
+  sbitset_op1,
+  sbitset_op2,
+  sbitset_op3,
+  sbitset_op4,
+  sbitset_small_list,
+  sbitset_reverse_list,
+  NULL,
+  BITSET_ARRAY
+};
 
 
 /* Vector of operations for multiple word bitsets.  */
-struct bitset_ops_struct sbitset_ops =
-  {
-    sbitset_set,
-    sbitset_reset,
-    sbitset_test,
-    sbitset_size,
-    sbitset_op1,
-    sbitset_op2,
-    sbitset_op3,
-    sbitset_op4,
-    sbitset_list,
-    sbitset_reverse_list,
-    NULL,
-    BITSET_ARRAY
+struct bitset_ops_struct sbitset_ops = {
+  sbitset_set,
+  sbitset_reset,
+  sbitset_test,
+  sbitset_size,
+  sbitset_op1,
+  sbitset_op2,
+  sbitset_op3,
+  sbitset_op4,
+  sbitset_list,
+  sbitset_reverse_list,
+  NULL,
+  BITSET_ARRAY
 };
 
 
@@ -661,12 +674,12 @@ sbitset_init (bset, n_bits)
      There is probably little merit if using caching since
      the small bitset will always fit in the cache.  */
   if (size == 1)
-    bset->ops = &sbitset_small_ops;
+    bset->b.ops = &sbitset_small_ops;
   else
-    bset->ops = &sbitset_ops;
+    bset->b.ops = &sbitset_ops;
 
-  bset->cindex = 0;
-  bset->csize = size;
-  bset->cdata = SBITSET_WORDS (bset);
+  bset->b.cindex = 0;
+  bset->b.csize = size;
+  bset->b.cdata = SBITSET_WORDS (bset);
   return bset;
 }
