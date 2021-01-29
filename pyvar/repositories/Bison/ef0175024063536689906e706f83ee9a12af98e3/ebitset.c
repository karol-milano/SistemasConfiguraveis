@@ -1,43 +1,33 @@
-/* Functions to support efficient bitsets.
+/* Functions to support expandable bitsets.
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
+#include "bbitset.h"
 #include "obstack.h"
 #include <stdlib.h>
 
-# if WITH_DMALLOC
-#  define DMALLOC_FUNC_CHECK
-#  include <dmalloc.h>
-# endif /* WITH_DMALLOC */
-
-/* This file implements linked-list bitsets.  These bitsets can be of
+/* This file implements expandable bitsets.  These bitsets can be of
    arbitrary length and are more efficient than arrays of bits for
    large sparse sets.
 
-   Usually if all the bits in an element are zero we remove the element
-   from the list.  However, a side effect of the bit caching is that we
-   do not always notice when an element becomes zero.  Hence the
-   ebitset_weed function which removes zero elements.
-
    Empty elements are represented by a NULL pointer in the table of
    element pointers.  An alternative is to point to a special zero
    element.  Similarly, we could represent an all 1's element with
@@ -46,33 +36,76 @@ Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
    Bitsets are commonly empty so we need to ensure that this special
    case is fast.  A zero bitset is indicated when cdata is 0.  This is
    conservative since cdata may be non zero and the bitset may still
-   be zero.
+   be zero. 
 
    The bitset cache can be disabled either by setting cindex to
-   some large number or by setting csize to 0.  Here
+   some large number or by setting csize to 0.  Here 
    we use the former approach since cindex needs to be updated whenever
-   cdata is changed.
+   cdata is changed.   
 */
 
+
+/* Number of words to use for each element.  */
+
+#ifndef EBITSET_ELT_WORDS
+#define EBITSET_ELT_WORDS 2
+#endif
+
+/* Number of bits stored in each element.  */
+#define EBITSET_ELT_BITS \
+  ((unsigned) (EBITSET_ELT_WORDS * BITSET_WORD_BITS))
+
+/* Ebitset element.  We use an array of bits.  */
+typedef struct ebitset_elt_struct
+{
+  union
+  {
+    bitset_word words[EBITSET_ELT_WORDS];	/* Bits that are set.  */
+    struct ebitset_elt_struct *next;
+  }
+  u;
+}
+ebitset_elt;
+
+
+typedef ebitset_elt *ebitset_elts;
+
+/* Head of ebitset linked list.  */
+typedef struct ebitset_struct
+{
+  unsigned int size;		/* Number of elements.  */
+  ebitset_elts *elts;		/* Expanding array of pointers to elements.  */
+}
+*ebitset;
+
+
 /* Number of elements to initially allocate.  */
+
 #ifndef EBITSET_INITIAL_SIZE
 #define EBITSET_INITIAL_SIZE 2
 #endif
 
 /* Minimum number of elements to grow table.  */
+
 #ifndef EBITSET_GROW_SIZE
 #define EBITSET_GROW_SIZE 4
 #endif
 
+struct bitset_struct
+{
+  struct bbitset_struct b;
+  struct ebitset_struct e;
+};
 
-enum ebitset_find_mode {EBITSET_FIND, EBITSET_CREATE, EBITSET_SUBST};
+enum ebitset_find_mode
+  { EBITSET_FIND, EBITSET_CREATE, EBITSET_SUBST };
 
 static ebitset_elt ebitset_zero_elts[1]; /* Elements of all zero bits.  */
 
 /* Obstack to allocate bitset elements from.  */
 static struct obstack ebitset_obstack;
 static int ebitset_obstack_init = 0;
-static ebitset_elt *ebitset_free_list; /* Free list of bitset elements.  */
+static ebitset_elt *ebitset_free_list;	/* Free list of bitset elements.  */
 
 static void ebitset_elts_grow PARAMS ((bitset, unsigned int));
 static ebitset_elt *ebitset_elt_alloc PARAMS ((void));
@@ -86,58 +119,55 @@ static ebitset_elt *ebitset_elt_last PARAMS ((bitset));
 static int ebitset_elt_zero_p PARAMS ((ebitset_elt *));
 
 static int ebitset_weed PARAMS ((bitset));
-static void ebitset_zero PARAMS((bitset));
-static int ebitset_equal_p PARAMS((bitset, bitset));
-static void ebitset_copy PARAMS((bitset, bitset));
-static int ebitset_copy_compare PARAMS((bitset, bitset));
-static void ebitset_set PARAMS((bitset, bitset_bindex));
-static void ebitset_reset PARAMS((bitset, bitset_bindex));
-static int ebitset_test PARAMS((bitset, bitset_bindex));
-static int ebitset_size PARAMS((bitset));
-static int ebitset_op1 PARAMS((bitset, enum bitset_ops));
-static int ebitset_op2 PARAMS((bitset, bitset, enum bitset_ops));
-static int ebitset_op3 PARAMS((bitset, bitset, bitset, enum bitset_ops));
-static int ebitset_op4 PARAMS((bitset, bitset, bitset, bitset,
-			       enum bitset_ops));
-static int ebitset_list PARAMS((bitset, bitset_bindex *, bitset_bindex,
-				bitset_bindex *));
-static int ebitset_reverse_list PARAMS((bitset, bitset_bindex *, bitset_bindex,
-					bitset_bindex *));
-static void ebitset_free PARAMS((bitset));
-
-
-#define EBITSET_ELTS(BSET) ((BSET)->u.e.elts)
-#define EBITSET_SIZE(BSET) ((BSET)->u.e.size)
+static void ebitset_zero PARAMS ((bitset));
+static int ebitset_equal_p PARAMS ((bitset, bitset));
+static void ebitset_copy PARAMS ((bitset, bitset));
+static int ebitset_copy_compare PARAMS ((bitset, bitset));
+static void ebitset_set PARAMS ((bitset, bitset_bindex));
+static void ebitset_reset PARAMS ((bitset, bitset_bindex));
+static int ebitset_test PARAMS ((bitset, bitset_bindex));
+static int ebitset_size PARAMS ((bitset));
+static int ebitset_op1 PARAMS ((bitset, enum bitset_ops));
+static int ebitset_op2 PARAMS ((bitset, bitset, enum bitset_ops));
+static int ebitset_op3 PARAMS ((bitset, bitset, bitset, enum bitset_ops));
+static int ebitset_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
+				 bitset_bindex *));
+static int ebitset_reverse_list
+PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
+static void ebitset_free PARAMS ((bitset));
+
+#define EBITSET_ELTS(BSET) ((BSET)->e.elts)
+#define EBITSET_SIZE(BSET) ((BSET)->e.size)
 
 #define EBITSET_NEXT(ELT) ((ELT)->u.next)
 #define EBITSET_WORDS(ELT) ((ELT)->u.words)
 
 /* Disable bitset cache and mark BSET as being zero.  */
-#define EBITSET_ZERO_SET(BSET) ((BSET)->cindex = BITSET_INDEX_MAX, \
-        (BSET)->cdata = 0)
+#define EBITSET_OP_ZERO_SET(BSET) ((BSET)->b.cindex = BITSET_INDEX_MAX, \
+        (BSET)->b.cdata = 0)
 
-#define EBITSET_CACHE_DISABLE(BSET)  ((BSET)->cindex = BITSET_INDEX_MAX)
+#define EBITSET_CACHE_DISABLE(BSET)  ((BSET)->b.cindex = BITSET_INDEX_MAX)
 
 /* Disable bitset cache and mark BSET as being possibly non-zero.  */
 #define EBITSET_NONZERO_SET(BSET) \
- (EBITSET_CACHE_DISABLE (BSET), (BSET)->cdata = (bitset_word *)~0)
+ (EBITSET_CACHE_DISABLE (BSET), (BSET)->b.cdata = (bitset_word *)~0)
 
 /* A conservative estimate of whether the bitset is zero.
    This is non-zero only if we know for sure that the bitset is zero.  */
-#define EBITSET_ZERO_P(BSET) ((BSET)->cdata == 0)
+#define EBITSET_OP_ZERO_P(BSET) ((BSET)->b.cdata == 0)
 
-/* Enable cache to point to element with table index EINDEX.
+/* Enable cache to point to element with table index EINDEX. 
    The element must exist.  */
 #define EBITSET_CACHE_SET(BSET, EINDEX) \
- ((BSET)->cindex = (EINDEX) * EBITSET_ELT_WORDS, \
-  (BSET)->cdata = EBITSET_WORDS (EBITSET_ELTS (BSET) [EINDEX]))
+ ((BSET)->b.cindex = (EINDEX) * EBITSET_ELT_WORDS, \
+  (BSET)->b.cdata = EBITSET_WORDS (EBITSET_ELTS (BSET) [EINDEX]))
 
 
 /* Grow the expandable table for BSET by SIZE elements.  */
 static void
 ebitset_elts_grow (bset, size)
-    bitset bset;
-    unsigned int size;
+     bitset bset;
+     unsigned int size;
 {
   unsigned int oldsize;
   unsigned int newsize;
@@ -146,7 +176,7 @@ ebitset_elts_grow (bset, size)
   newsize = oldsize + size;
 
   EBITSET_ELTS (bset) = xrealloc (EBITSET_ELTS (bset),
-				   newsize * sizeof (ebitset_elt *));
+				  newsize * sizeof (ebitset_elt *));
   EBITSET_SIZE (bset) = newsize;
 
   memset (EBITSET_ELTS (bset) + oldsize, 0, size * sizeof (ebitset_elt *));
@@ -174,13 +204,17 @@ ebitset_elt_alloc ()
 	  ebitset_obstack_init = 1;
 
 	  /* Let particular systems override the size of a chunk.  */
+
 #ifndef OBSTACK_CHUNK_SIZE
 #define OBSTACK_CHUNK_SIZE 0
 #endif
+
 	  /* Let them override the alloc and free routines too.  */
+
 #ifndef OBSTACK_CHUNK_ALLOC
 #define OBSTACK_CHUNK_ALLOC xmalloc
 #endif
+
 #ifndef OBSTACK_CHUNK_FREE
 #define OBSTACK_CHUNK_FREE free
 #endif
@@ -191,12 +225,14 @@ ebitset_elt_alloc ()
 
 	  obstack_specify_allocation (&ebitset_obstack, OBSTACK_CHUNK_SIZE,
 				      __alignof__ (ebitset_elt),
-				      (void *(*) PARAMS ((long))) OBSTACK_CHUNK_ALLOC,
-				      (void (*) PARAMS ((void *))) OBSTACK_CHUNK_FREE);
+				      (void *(*)PARAMS ((long)))
+				      OBSTACK_CHUNK_ALLOC,
+				      (void (*)PARAMS ((void *)))
+				      OBSTACK_CHUNK_FREE);
 	}
 
       /* Perhaps we should add a number of new elements to the free
-         list.  */
+	 list.  */
       elt = (ebitset_elt *) obstack_alloc (&ebitset_obstack,
 					   sizeof (ebitset_elt));
     }
@@ -296,7 +332,7 @@ ebitset_elt_find (bset, index, mode)
 
       if ((elt = elts[eindex]))
 	{
-	  if (EBITSET_WORDS (elt) == bset->cdata)
+	  if (EBITSET_WORDS (elt) == bset->b.cdata)
 	    return elt;
 
 	  EBITSET_CACHE_SET (bset, eindex);
@@ -366,7 +402,7 @@ ebitset_weed (bset)
   bitset_windex j;
   int count;
 
-  if (EBITSET_ZERO_P (bset))
+  if (EBITSET_OP_ZERO_P (bset))
     return 0;
 
   elts = EBITSET_ELTS (bset);
@@ -390,14 +426,14 @@ ebitset_weed (bset)
   count = j - count;
   if (!count)
     {
-      /* All the bits are zero.  We could shrink the elts.
+      /* All the bits are zero.  We could shrink the elts. 
 	 For now just mark BSET as known to be zero.  */
-      EBITSET_ZERO_SET (bset);
+      EBITSET_OP_ZERO_SET (bset);
     }
   else
     EBITSET_NONZERO_SET (bset);
 
-  return  count;
+  return count;
 }
 
 
@@ -409,7 +445,7 @@ ebitset_zero (bset)
   ebitset_elts *elts;
   bitset_windex j;
 
-  if (EBITSET_ZERO_P (bset))
+  if (EBITSET_OP_ZERO_P (bset))
     return;
 
   elts = EBITSET_ELTS (bset);
@@ -421,9 +457,9 @@ ebitset_zero (bset)
 	ebitset_elt_remove (bset, j);
     }
 
-  /* All the bits are zero.  We could shrink the elts.
+  /* All the bits are zero.  We could shrink the elts. 
      For now just mark BSET as known to be zero.  */
-  EBITSET_ZERO_SET (bset);
+  EBITSET_OP_ZERO_SET (bset);
 }
 
 
@@ -454,9 +490,9 @@ ebitset_equal_p (dst, src)
       ebitset_elt *selt = selts[j];
       ebitset_elt *delt = delts[j];
 
-      if (! selt && ! delt)
+      if (!selt && !delt)
 	continue;
-      if ((selt && ! delt) || (!selt && delt))
+      if ((selt && !delt) || (!selt && delt))
 	return 0;
 
       for (i = 0; i < EBITSET_ELT_WORDS; i++)
@@ -515,10 +551,10 @@ ebitset_copy_compare (dst, src)
   if (src == dst)
     return 0;
 
-  if (EBITSET_ZERO_P (dst))
+  if (EBITSET_OP_ZERO_P (dst))
     {
       ebitset_copy (dst, src);
-      return ! EBITSET_ZERO_P (src);
+      return !EBITSET_OP_ZERO_P (src);
     }
 
   if (ebitset_equal_p (dst, src))
@@ -549,7 +585,7 @@ ebitset_set (dst, bitno)
 
   ebitset_elt_find (dst, index, EBITSET_CREATE);
 
-  dst->cdata[index - dst->cindex] |= (1 << (bitno % BITSET_WORD_BITS));
+  dst->b.cdata[index - dst->b.cindex] |= (1 << (bitno % BITSET_WORD_BITS));
 }
 
 
@@ -562,11 +598,11 @@ ebitset_reset (dst, bitno)
   bitset_windex index = bitno / BITSET_WORD_BITS;
 
   if (!ebitset_elt_find (dst, index, EBITSET_FIND))
-      return;
+    return;
 
-  dst->cdata[index - dst->cindex] &= ~(1 << (bitno % BITSET_WORD_BITS));
+  dst->b.cdata[index - dst->b.cindex] &= ~(1 << (bitno % BITSET_WORD_BITS));
 
-  /* If all the data is zero, perhaps we should remove it now...
+  /* If all the data is zero, perhaps we should remove it now... 
      However, there could be a good chance that the element will be needed
      again soon.  */
 }
@@ -583,7 +619,8 @@ ebitset_test (src, bitno)
   if (!ebitset_elt_find (src, index, EBITSET_FIND))
     return 0;
 
-  return (src->cdata[index - src->cindex] >> (bitno % BITSET_WORD_BITS)) & 1;
+  return (src->b.
+	  cdata[index - src->b.cindex] >> (bitno % BITSET_WORD_BITS)) & 1;
 }
 
 
@@ -597,8 +634,8 @@ ebitset_free (bset)
 
 
 /* Find list of up to NUM bits set in BSET starting from and including
-   *NEXT and store in array LIST.  Return with actual number of bits
-   found and with *NEXT indicating where search stopped.  */
+ *NEXT and store in array LIST.  Return with actual number of bits
+ found and with *NEXT indicating where search stopped.  */
 static int
 ebitset_reverse_list (bset, list, num, next)
      bitset bset;
@@ -619,7 +656,7 @@ ebitset_reverse_list (bset, list, num, next)
   bitset_word word;
   ebitset_elts *elts;
 
-  if (EBITSET_ZERO_P (bset))
+  if (EBITSET_OP_ZERO_P (bset))
     return 0;
 
   size = EBITSET_SIZE (bset);
@@ -627,13 +664,13 @@ ebitset_reverse_list (bset, list, num, next)
   rbitno = *next;
 
   if (rbitno >= n_bits)
-      return 0;
+    return 0;
 
   elts = EBITSET_ELTS (bset);
 
   bitno = n_bits - (rbitno + 1);
 
-  index = bitno /  BITSET_WORD_BITS;
+  index = bitno / BITSET_WORD_BITS;
   eindex = bitno / EBITSET_ELT_BITS;
   windex = index - eindex * EBITSET_ELT_WORDS;
 
@@ -684,8 +721,8 @@ ebitset_reverse_list (bset, list, num, next)
 
 
 /* Find list of up to NUM bits set in BSET starting from and including
-   *NEXT and store in array LIST.  Return with actual number of bits
-   found and with *NEXT indicating where search stopped.  */
+ *NEXT and store in array LIST.  Return with actual number of bits
+ found and with *NEXT indicating where search stopped.  */
 static int
 ebitset_list (bset, list, num, next)
      bitset bset;
@@ -702,7 +739,7 @@ ebitset_list (bset, list, num, next)
   bitset_word word;
   ebitset_elts *elts;
 
-  if (EBITSET_ZERO_P (bset))
+  if (EBITSET_OP_ZERO_P (bset))
     return 0;
 
   bitno = *next;
@@ -777,12 +814,12 @@ ebitset_list (bset, list, num, next)
 	      word = srcp[i];
 	      if (word)
 		{
-		  if (! (word & 0xffff))
+		  if (!(word & 0xffff))
 		    {
 		      word >>= 16;
 		      bitno += 16;
 		    }
-		  if (! (word & 0xff))
+		  if (!(word & 0xff))
 		    {
 		      word >>= 8;
 		      bitno += 8;
@@ -837,22 +874,23 @@ ebitset_op1 (dst, op)
 
   switch (op)
     {
-    case BITSET_ZERO:
+    case BITSET_OP_ZERO:
       ebitset_zero (dst);
       return 1;
 
-    case BITSET_ONES:
+    case BITSET_OP_ONES:
       for (j = 0; j < EBITSET_SIZE (dst); j++)
 	{
 	  /* Create new elements if they cannot be found.  Perhaps
-	   we should just add pointers to a ones element.  */
-	  elt = ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_CREATE);
+	     we should just add pointers to a ones element.  */
+	  elt =
+	    ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_CREATE);
 	  memset (EBITSET_WORDS (elt), ~0, sizeof (EBITSET_WORDS (elt)));
 	}
       break;
 
-    case BITSET_EMPTY_P:
-      return ! ebitset_weed (dst);
+    case BITSET_OP_EMPTY_P:
+      return !ebitset_weed (dst);
 
     default:
       abort ();
@@ -876,28 +914,31 @@ ebitset_op2 (dst, src, op)
 
   switch (op)
     {
-    case BITSET_COPY:
+    case BITSET_OP_COPY:
       ebitset_copy (dst, src);
       break;
 
-    case BITSET_NOT:
+    case BITSET_OP_NOT:
       for (j = 0; j < EBITSET_SIZE (src); j++)
 	{
 	  /* Create new elements for dst if they cannot be found
 	     or substitute zero elements if src elements not found.  */
-	  selt = ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_SUBST);
-	  delt = ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_CREATE);
+	  selt =
+	    ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_SUBST);
+	  delt =
+	    ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_CREATE);
 
 	  for (i = 0; i < EBITSET_ELT_WORDS; i++)
 	    EBITSET_WORDS (delt)[i] = ~EBITSET_WORDS (selt)[i];
 	}
       break;
 
-    case BITSET_EQUAL_P:
+      /* Return 1 if DST == SRC.  */
+    case BITSET_OP_EQUAL_P:
       return ebitset_equal_p (dst, src);
 
       /* Return 1 if DST == DST | SRC.  */
-    case BITSET_SUBSET_P:
+    case BITSET_OP_SUBSET_P:
       {
 	ebitset_elts *selts;
 	ebitset_elts *delts;
@@ -918,7 +959,7 @@ ebitset_op2 (dst, src, op)
 	    selt = j < ssize ? selts[j] : 0;
 	    delt = j < dsize ? delts[j] : 0;
 
-	    if (! selt && ! delt)
+	    if (!selt && !delt)
 	      continue;
 
 	    if (!selt)
@@ -935,6 +976,44 @@ ebitset_op2 (dst, src, op)
       }
       break;
 
+      /* Return 1 if DST & SRC == 0.  */
+    case BITSET_OP_DISJOINT_P:
+      {
+	ebitset_elts *selts;
+	ebitset_elts *delts;
+	bitset_windex ssize;
+	bitset_windex dsize;
+
+	selts = EBITSET_ELTS (src);
+	delts = EBITSET_ELTS (dst);
+
+	ssize = EBITSET_SIZE (src);
+	dsize = EBITSET_SIZE (dst);
+
+	for (j = 0; j < ssize; j++)
+	  {
+	    ebitset_elt *selt;
+	    ebitset_elt *delt;
+
+	    selt = j < ssize ? selts[j] : 0;
+	    delt = j < dsize ? delts[j] : 0;
+
+	    if (!selt && !delt)
+	      continue;
+
+	    if (!selt)
+	      selt = &ebitset_zero_elts[0];
+	    if (!delt)
+	      delt = &ebitset_zero_elts[0];
+
+	    for (i = 0; i < EBITSET_ELT_WORDS; i++)
+	      if ((EBITSET_WORDS (selt)[i] & EBITSET_WORDS (delt)[i]))
+		return 0;
+	  }
+	return 1;
+      }
+      break;
+
     default:
       abort ();
     }
@@ -966,30 +1045,31 @@ ebitset_op3 (dst, src1, src2, op)
   bitset_windex j;
 
   /* Fast track common, simple cases.  */
-  if (EBITSET_ZERO_P (src2))
+  if (EBITSET_OP_ZERO_P (src2))
     {
-      if (op == BITSET_AND)
+      if (op == BITSET_OP_AND)
 	{
 	  ebitset_weed (dst);
-	  changed = EBITSET_ZERO_P (dst);
+	  changed = EBITSET_OP_ZERO_P (dst);
 	  ebitset_zero (dst);
 	  return changed;
 	}
-      else if (op == BITSET_ANDN || op == BITSET_OR || op == BITSET_XOR)
+      else if (op == BITSET_OP_ANDN || op == BITSET_OP_OR
+	       || op == BITSET_OP_XOR)
 	{
 	  return ebitset_copy_compare (dst, src1);
 	}
     }
-  else if (EBITSET_ZERO_P (src1))
+  else if (EBITSET_OP_ZERO_P (src1))
     {
-      if (op == BITSET_AND || op == BITSET_ANDN)
+      if (op == BITSET_OP_AND || op == BITSET_OP_ANDN)
 	{
 	  ebitset_weed (dst);
-	  changed = EBITSET_ZERO_P (dst);
+	  changed = EBITSET_OP_ZERO_P (dst);
 	  ebitset_zero (dst);
 	  return changed;
 	}
-      else if (op == BITSET_OR || op == BITSET_XOR)
+      else if (op == BITSET_OP_OR || op == BITSET_OP_XOR)
 	{
 	  return ebitset_copy_compare (dst, src2);
 	}
@@ -1003,7 +1083,7 @@ ebitset_op3 (dst, src1, src2, op)
     size = ssize2;
 
   if (size > dsize)
-      ebitset_elts_grow (dst, size - dsize);
+    ebitset_elts_grow (dst, size - dsize);
 
   selts1 = EBITSET_ELTS (src1);
   selts2 = EBITSET_ELTS (src2);
@@ -1019,7 +1099,7 @@ ebitset_op3 (dst, src1, src2, op)
       selt2 = j < ssize2 ? selts2[j] : 0;
       delt = j < dsize ? delts[j] : 0;
 
-      if (! selt1 && ! selt2)
+      if (!selt1 && !selt2)
 	{
 	  if (delt)
 	    {
@@ -1043,7 +1123,7 @@ ebitset_op3 (dst, src1, src2, op)
       dstp = EBITSET_WORDS (delt);
       switch (op)
 	{
-	case BITSET_OR:
+	case BITSET_OP_OR:
 	  for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
 	    {
 	      bitset_word tmp = *srcp1++ | *srcp2++;
@@ -1056,7 +1136,7 @@ ebitset_op3 (dst, src1, src2, op)
 	    }
 	  break;
 
-	case BITSET_AND:
+	case BITSET_OP_AND:
 	  for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
 	    {
 	      bitset_word tmp = *srcp1++ & *srcp2++;
@@ -1069,7 +1149,7 @@ ebitset_op3 (dst, src1, src2, op)
 	    }
 	  break;
 
-	case BITSET_XOR:
+	case BITSET_OP_XOR:
 	  for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
 	    {
 	      bitset_word tmp = *srcp1++ ^ *srcp2++;
@@ -1082,7 +1162,7 @@ ebitset_op3 (dst, src1, src2, op)
 	    }
 	  break;
 
-	case BITSET_ANDN:
+	case BITSET_OP_ANDN:
 	  for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
 	    {
 	      bitset_word tmp = *srcp1++ & ~(*srcp2++);
@@ -1095,7 +1175,7 @@ ebitset_op3 (dst, src1, src2, op)
 	    }
 	  break;
 
-	case BITSET_ORN:
+	case BITSET_OP_ORN:
 	  for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
 	    {
 	      bitset_word tmp = *srcp1++ | ~(*srcp2++);
@@ -1112,7 +1192,7 @@ ebitset_op3 (dst, src1, src2, op)
 	  abort ();
 	}
 
-      if (! ebitset_elt_zero_p (delt))
+      if (!ebitset_elt_zero_p (delt))
 	{
 	  ebitset_elt_add (dst, delt, j);
 	}
@@ -1140,62 +1220,21 @@ ebitset_op3 (dst, src1, src2, op)
 }
 
 
-static int
-ebitset_op4 (dst, src1, src2, src3, op)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
-     enum bitset_ops op;
-{
-  int changed = 0;
-  bitset tmp;
-
-  tmp = bitset_create (BITSET_LIST, 0);
-
-  switch (op)
-    {
-    case BITSET_OR_AND:
-      bitset_or (tmp, src1, src2);
-      changed = bitset_and (dst, src3, tmp);
-      break;
-
-    case BITSET_AND_OR:
-      bitset_and (tmp, src1, src2);
-      changed = bitset_or (dst, src3, tmp);
-      break;
-
-    case BITSET_ANDN_OR:
-      bitset_andn (tmp, src1, src2);
-      changed = bitset_or (dst, src3, tmp);
-      break;
-
-    default:
-      abort ();
-    }
-
-  bitset_free (tmp);
-  EBITSET_NONZERO_SET (dst);
-  return changed;
-}
-
-
 /* Vector of operations for linked-list bitsets.  */
-struct bitset_ops_struct ebitset_ops =
-  {
-    ebitset_set,
-    ebitset_reset,
-    ebitset_test,
-    ebitset_size,
-    ebitset_op1,
-    ebitset_op2,
-    ebitset_op3,
-    ebitset_op4,
-    ebitset_list,
-    ebitset_reverse_list,
-    ebitset_free,
-    BITSET_TABLE
-  };
+struct bitset_ops_struct ebitset_ops = {
+  ebitset_set,
+  ebitset_reset,
+  ebitset_test,
+  ebitset_size,
+  ebitset_op1,
+  ebitset_op2,
+  ebitset_op3,
+  bitset_op4,
+  ebitset_list,
+  ebitset_reverse_list,
+  ebitset_free,
+  BITSET_TABLE
+};
 
 
 /* Return size of initial structure.  */
@@ -1216,11 +1255,11 @@ ebitset_init (bset, n_bits)
 {
   unsigned int size;
 
-  bset->ops = &ebitset_ops;
+  bset->b.ops = &ebitset_ops;
 
-  bset->csize = EBITSET_ELT_WORDS;
+  bset->b.csize = EBITSET_ELT_WORDS;
 
-  EBITSET_ZERO_SET (bset);
+  EBITSET_OP_ZERO_SET (bset);
 
   size = n_bits ? (n_bits + EBITSET_ELT_BITS - 1) / EBITSET_ELT_BITS
     : EBITSET_INITIAL_SIZE;
