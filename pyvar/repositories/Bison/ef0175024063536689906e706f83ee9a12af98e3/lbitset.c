@@ -2,50 +2,92 @@
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
 /* This file implements linked-list bitsets.  These bitsets can be of
    arbitrary length and are more efficient than arrays of bits for
    large sparse sets.
 
-  Usually if all the bits in an element are zero we remove the element
-  from the list.  However, a side effect of the bit caching is that we
-  do not always notice when an element becomes zero.  Hence the
-  lbitset_weed function which removes zero elements.  */
+   Usually if all the bits in an element are zero we remove the element
+   from the list.  However, a side effect of the bit caching is that we
+   do not always notice when an element becomes zero.  Hence the
+   lbitset_weed function which removes zero elements.  */
+
+
+/* Number of words to use for each element.  The larger the value the
+   greater the size of the cache and the shorter the time to find a given bit
+   but the more memory wasted for sparse bitsets and the longer the time
+   to search for set bits.  */
+
+#ifndef LBITSET_ELT_WORDS
+#define LBITSET_ELT_WORDS 2
+#endif
+
+typedef bitset_word lbitset_word;
+
+#define LBITSET_WORD_BITS BITSET_WORD_BITS
+
+/* Number of bits stored in each element.  */
+#define LBITSET_ELT_BITS \
+  ((unsigned) (LBITSET_ELT_WORDS * LBITSET_WORD_BITS))
+
+/* Lbitset element.   We use an array of bits for each element.
+   These are linked together in a doubly-linked list.  */
+typedef struct lbitset_elt_struct
+{
+  struct lbitset_elt_struct *next;	/* Next element.  */
+  struct lbitset_elt_struct *prev;	/* Previous element.  */
+  bitset_windex index;	/* bitno / BITSET_WORD_BITS.  */
+  bitset_word words[LBITSET_ELT_WORDS];	/* Bits that are set.  */
+}
+lbitset_elt;
+
+
+/* Head of lbitset linked list.  */
+typedef struct lbitset_struct
+{
+  lbitset_elt *head;		/* First element in linked list.  */
+  lbitset_elt *tail;		/* Last element in linked list.  */
+}
+*lbitset;
+
 
-enum lbitset_find_mode {LBITSET_FIND, LBITSET_CREATE, LBITSET_SUBST};
+struct bitset_struct
+{
+  struct bbitset_struct b;
+  struct lbitset_struct l;
+};
 
-static lbitset_elt lbitset_zero_elts[3]; /* Elements of all zero bits.  */
+
+enum lbitset_find_mode
+  { LBITSET_FIND, LBITSET_CREATE, LBITSET_SUBST };
+
+static lbitset_elt lbitset_zero_elts[3];	/* Elements of all zero bits.  */
 
 /* Obstack to allocate bitset elements from.  */
 static struct obstack lbitset_obstack;
 static int lbitset_obstack_init = 0;
-static lbitset_elt *lbitset_free_list; /* Free list of bitset elements.  */
+static lbitset_elt *lbitset_free_list;	/* Free list of bitset elements.  */
 
 static lbitset_elt *lbitset_elt_alloc PARAMS ((void));
 static lbitset_elt *lbitset_elt_calloc PARAMS ((void));
@@ -58,32 +100,30 @@ static int lbitset_elt_zero_p PARAMS ((lbitset_elt *));
 
 static void lbitset_prune PARAMS ((bitset, lbitset_elt *));
 static void lbitset_weed PARAMS ((bitset));
-static void lbitset_zero PARAMS((bitset));
-static int lbitset_equal_p PARAMS((bitset, bitset));
-static void lbitset_copy PARAMS((bitset, bitset));
-static int lbitset_copy_compare PARAMS((bitset, bitset));
-static void lbitset_set PARAMS((bitset, bitset_bindex));
-static void lbitset_reset PARAMS((bitset, bitset_bindex));
-static int lbitset_test PARAMS((bitset, bitset_bindex));
-static int lbitset_size PARAMS((bitset));
-static int lbitset_op1 PARAMS((bitset, enum bitset_ops));
-static int lbitset_op2 PARAMS((bitset, bitset, enum bitset_ops));
-static int lbitset_op3 PARAMS((bitset, bitset, bitset, enum bitset_ops));
-static int lbitset_op4 PARAMS((bitset, bitset, bitset, bitset,
-			       enum bitset_ops));
-static int lbitset_list PARAMS((bitset, bitset_bindex *, bitset_bindex,
-				bitset_bindex *));
-static int lbitset_reverse_list PARAMS((bitset, bitset_bindex *, bitset_bindex,
-					bitset_bindex *));
-static void lbitset_free PARAMS((bitset));
+static void lbitset_zero PARAMS ((bitset));
+static int lbitset_equal_p PARAMS ((bitset, bitset));
+static void lbitset_copy PARAMS ((bitset, bitset));
+static int lbitset_copy_compare PARAMS ((bitset, bitset));
+static void lbitset_set PARAMS ((bitset, bitset_bindex));
+static void lbitset_reset PARAMS ((bitset, bitset_bindex));
+static int lbitset_test PARAMS ((bitset, bitset_bindex));
+static int lbitset_size PARAMS ((bitset));
+static int lbitset_op1 PARAMS ((bitset, enum bitset_ops));
+static int lbitset_op2 PARAMS ((bitset, bitset, enum bitset_ops));
+static int lbitset_op3 PARAMS ((bitset, bitset, bitset, enum bitset_ops));
+static int lbitset_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
+				 bitset_bindex *));
+static int lbitset_reverse_list
+PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
+static void lbitset_free PARAMS ((bitset));
 
 
 #define LBITSET_CURRENT1(X) (lbitset_elt *)((char *)(X) + ((char *)&(((lbitset_elt *)(X))->next) - (char *)&(((lbitset_elt *)(X))->words)))
 
-#define LBITSET_CURRENT(X) LBITSET_CURRENT1((X)->cdata)
+#define LBITSET_CURRENT(X) LBITSET_CURRENT1((X)->b.cdata)
 
-#define LBITSET_HEAD(X) ((X)->u.l.head)
-#define LBITSET_TAIL(X) ((X)->u.l.tail)
+#define LBITSET_HEAD(X) ((X)->l.head)
+#define LBITSET_TAIL(X) ((X)->l.tail)
 
 /* Allocate a lbitset element.  The bits are not cleared.  */
 static inline lbitset_elt *
@@ -106,13 +146,17 @@ lbitset_elt_alloc ()
 	  lbitset_obstack_init = 1;
 
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
@@ -123,12 +167,14 @@ lbitset_elt_alloc ()
 
 	  obstack_specify_allocation (&lbitset_obstack, OBSTACK_CHUNK_SIZE,
 				      __alignof__ (lbitset_elt),
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
       elt = (lbitset_elt *) obstack_alloc (&lbitset_obstack,
 					   sizeof (lbitset_elt));
     }
@@ -185,18 +231,18 @@ lbitset_elt_unlink (bset, elt)
     {
       if (next)
 	{
-	  bset->cdata = next->words;
-	  bset->cindex = next->index;
+	  bset->b.cdata = next->words;
+	  bset->b.cindex = next->index;
 	}
       else if (prev)
 	{
-	  bset->cdata = prev->words;
-	  bset->cindex = prev->index;
+	  bset->b.cdata = prev->words;
+	  bset->b.cindex = prev->index;
 	}
       else
 	{
-	  bset->csize = 0;
-	  bset->cdata = 0;
+	  bset->b.csize = 0;
+	  bset->b.cdata = 0;
 	}
     }
 
@@ -214,22 +260,22 @@ lbitset_prune (bset, elt)
   lbitset_elt *next;
 
   if (!elt)
-      return;
+    return;
 
   if (elt->prev)
-  {
+    {
       LBITSET_TAIL (bset) = elt->prev;
-      bset->cdata = elt->prev->words;
-      bset->cindex = elt->prev->index;
+      bset->b.cdata = elt->prev->words;
+      bset->b.cindex = elt->prev->index;
       elt->prev->next = 0;
-  }
+    }
   else
-  {
+    {
       LBITSET_HEAD (bset) = 0;
       LBITSET_TAIL (bset) = 0;
-      bset->cdata = 0;
-      bset->csize = 0;
-  }
+      bset->b.cdata = 0;
+      bset->b.csize = 0;
+    }
 
   for (; elt; elt = next)
     {
@@ -264,10 +310,10 @@ lbitset_elt_link (bset, elt)
   lbitset_elt *ptr;
   lbitset_elt *current;
 
-  if (bset->csize)
-      current = LBITSET_CURRENT (bset);
+  if (bset->b.csize)
+    current = LBITSET_CURRENT (bset);
   else
-      current = LBITSET_HEAD (bset);
+    current = LBITSET_HEAD (bset);
 
   /* If this is the first and only element, add it in.  */
   if (LBITSET_HEAD (bset) == 0)
@@ -279,11 +325,10 @@ lbitset_elt_link (bset, elt)
 
   /* If this index is less than that of the current element, it goes
      somewhere before the current element.  */
-  else if (index < bset->cindex)
+  else if (index < bset->b.cindex)
     {
       for (ptr = current;
-	   ptr->prev && ptr->prev->index > index;
-	   ptr = ptr->prev)
+	   ptr->prev && ptr->prev->index > index; ptr = ptr->prev)
 	continue;
 
       if (ptr->prev)
@@ -300,8 +345,7 @@ lbitset_elt_link (bset, elt)
   else
     {
       for (ptr = current;
-	   ptr->next && ptr->next->index < index;
-	   ptr = ptr->next)
+	   ptr->next && ptr->next->index < index; ptr = ptr->next)
 	continue;
 
       if (ptr->next)
@@ -315,9 +359,9 @@ lbitset_elt_link (bset, elt)
     }
 
   /* Set up so this is the first element searched.  */
-  bset->cindex = index;
-  bset->csize = LBITSET_ELT_WORDS;
-  bset->cdata = elt->words;
+  bset->b.cindex = index;
+  bset->b.csize = LBITSET_ELT_WORDS;
+  bset->b.cdata = elt->words;
 }
 
 
@@ -330,11 +374,11 @@ lbitset_elt_find (bset, index, mode)
   lbitset_elt *elt;
   lbitset_elt *current;
 
-  if (bset->csize)
+  if (bset->b.csize)
     {
       current = LBITSET_CURRENT (bset);
       /* Check if element is the cached element.  */
-      if ((index - bset->cindex) < bset->csize)
+      if ((index - bset->b.cindex) < bset->b.csize)
 	return current;
     }
   else
@@ -344,11 +388,10 @@ lbitset_elt_find (bset, index, mode)
 
   if (current)
     {
-      if (index < bset->cindex)
+      if (index < bset->b.cindex)
 	{
 	  for (elt = current;
-	       elt->prev && elt->index > index;
-	       elt = elt->prev)
+	       elt->prev && elt->index > index; elt = elt->prev)
 	    continue;
 	}
       else
@@ -363,9 +406,9 @@ lbitset_elt_find (bset, index, mode)
 	 we want, the one we want does not exist.  */
       if (elt && (index - elt->index) < LBITSET_ELT_WORDS)
 	{
-	  bset->cindex = elt->index;
-          bset->csize = LBITSET_ELT_WORDS;
-	  bset->cdata = elt->words;
+	  bset->b.cindex = elt->index;
+	  bset->b.csize = LBITSET_ELT_WORDS;
+	  bset->b.cdata = elt->words;
 	  return elt;
 	}
     }
@@ -449,7 +492,7 @@ lbitset_equal_p (dst, src)
 	if (delt->words[j] != selt->words[j])
 	  return 0;
     }
-  return ! selt && ! delt;
+  return !selt && !delt;
 }
 
 
@@ -490,9 +533,9 @@ lbitset_copy (dst, src)
     }
   LBITSET_TAIL (dst) = tmp;
 
-  dst->csize = LBITSET_ELT_WORDS;
-  dst->cdata = LBITSET_HEAD (dst)->words;
-  dst->cindex = LBITSET_HEAD (dst)->index;
+  dst->b.csize = LBITSET_ELT_WORDS;
+  dst->b.cdata = LBITSET_HEAD (dst)->words;
+  dst->b.cindex = LBITSET_HEAD (dst)->index;
 }
 
 
@@ -506,7 +549,7 @@ lbitset_copy_compare (dst, src)
   if (src == dst)
     return 0;
 
-  if (! LBITSET_HEAD (dst))
+  if (!LBITSET_HEAD (dst))
     {
       lbitset_copy (dst, src);
       return LBITSET_HEAD (src) != 0;
@@ -529,7 +572,7 @@ lbitset_size (src)
 
   elt = LBITSET_TAIL (src);
   if (!elt)
-	return 0;
+    return 0;
 
   /* Return current size of bitset in bits.  */
   return (elt->index + LBITSET_ELT_WORDS) * BITSET_WORD_BITS;
@@ -546,7 +589,7 @@ lbitset_set (dst, bitno)
 
   lbitset_elt_find (dst, index, LBITSET_CREATE);
 
-  dst->cdata[index - dst->cindex] |= (1 << (bitno % BITSET_WORD_BITS));
+  dst->b.cdata[index - dst->b.cindex] |= (1 << (bitno % BITSET_WORD_BITS));
 }
 
 
@@ -559,9 +602,9 @@ lbitset_reset (dst, bitno)
   bitset_windex index = bitno / BITSET_WORD_BITS;
 
   if (!lbitset_elt_find (dst, index, LBITSET_FIND))
-      return;
+    return;
 
-  dst->cdata[index - dst->cindex] &= ~(1 << (bitno % BITSET_WORD_BITS));
+  dst->b.cdata[index - dst->b.cindex] &= ~(1 << (bitno % BITSET_WORD_BITS));
 
   /* If all the data is zero, perhaps we should unlink it now...  */
 }
@@ -578,7 +621,8 @@ lbitset_test (src, bitno)
   if (!lbitset_elt_find (src, index, LBITSET_FIND))
     return 0;
 
-  return (src->cdata[index - src->cindex] >> (bitno % BITSET_WORD_BITS)) & 1;
+  return (src->b.
+	  cdata[index - src->b.cindex] >> (bitno % BITSET_WORD_BITS)) & 1;
 }
 
 
@@ -591,8 +635,8 @@ lbitset_free (bset)
 
 
 /* Find list of up to NUM bits set in BSET starting from and including
-   *NEXT and store in array LIST.  Return with actual number of bits
-   found and with *NEXT indicating where search stopped.  */
+ *NEXT and store in array LIST.  Return with actual number of bits
+ found and with *NEXT indicating where search stopped.  */
 static int
 lbitset_reverse_list (bset, list, num, next)
      bitset bset;
@@ -618,7 +662,7 @@ lbitset_reverse_list (bset, list, num, next)
   rbitno = *next;
 
   if (rbitno >= n_bits)
-      return 0;
+    return 0;
 
   bitno = n_bits - (rbitno + 1);
 
@@ -644,9 +688,10 @@ lbitset_reverse_list (bset, list, num, next)
 
       for (; (index - elt->index) < LBITSET_ELT_WORDS;
 	   index--, bitoff -= BITSET_WORD_BITS,
-	       bitcnt = BITSET_WORD_BITS - 1)
+	     bitcnt = BITSET_WORD_BITS - 1)
 	{
-	  word = srcp[index - elt->index] << (BITSET_WORD_BITS - 1 - bitcnt);
+	  word =
+	    srcp[index - elt->index] << (BITSET_WORD_BITS - 1 - bitcnt);
 
 	  for (; word; bitcnt--)
 	    {
@@ -677,8 +722,8 @@ lbitset_reverse_list (bset, list, num, next)
 
 
 /* Find list of up to NUM bits set in BSET starting from and including
-   *NEXT and store in array LIST.  Return with actual number of bits
-   found and with *NEXT indicating where search stopped.  */
+ *NEXT and store in array LIST.  Return with actual number of bits
+ found and with *NEXT indicating where search stopped.  */
 static int
 lbitset_list (bset, list, num, next)
      bitset bset;
@@ -695,7 +740,7 @@ lbitset_list (bset, list, num, next)
 
   head = LBITSET_HEAD (bset);
   if (!head)
-      return 0;
+    return 0;
 
   bitno = *next;
   count = 0;
@@ -779,12 +824,12 @@ lbitset_list (bset, list, num, next)
 	  word = srcp[0];
 	  if (word)
 	    {
-	      if (! (word & 0xffff))
+	      if (!(word & 0xffff))
 		{
 		  word >>= 16;
 		  bitno += 16;
 		}
-	      if (! (word & 0xff))
+	      if (!(word & 0xff))
 		{
 		  word >>= 8;
 		  bitno += 8;
@@ -802,7 +847,7 @@ lbitset_list (bset, list, num, next)
 	  word = srcp[1];
 	  if (word)
 	    {
-	      if (! (word & 0xffff))
+	      if (!(word & 0xffff))
 		{
 		  word >>= 16;
 		  bitno += 16;
@@ -822,12 +867,12 @@ lbitset_list (bset, list, num, next)
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
@@ -893,11 +938,11 @@ lbitset_op1 (dst, op)
 
   switch (op)
     {
-    case BITSET_ZERO:
+    case BITSET_OP_ZERO:
       lbitset_zero (dst);
       break;
 
-    case BITSET_ONES:
+    case BITSET_OP_ONES:
       /* This is a decidedly unfriendly operation for a linked list
 	 bitset!   */
       elt = LBITSET_TAIL (dst);
@@ -914,7 +959,7 @@ lbitset_op1 (dst, op)
 	}
       break;
 
-    case BITSET_EMPTY_P:
+    case BITSET_OP_EMPTY_P:
       lbitset_weed (dst);
       if (LBITSET_HEAD (dst))
 	return 0;
@@ -943,11 +988,11 @@ lbitset_op2 (dst, src, op)
 
   switch (op)
     {
-    case BITSET_COPY:
+    case BITSET_OP_COPY:
       lbitset_copy (dst, src);
       break;
 
-    case BITSET_NOT:
+    case BITSET_OP_NOT:
       /* This is another unfriendly operation for a linked list
 	 bitset!  */
       elt = LBITSET_TAIL (dst);
@@ -969,11 +1014,13 @@ lbitset_op2 (dst, src, op)
       lbitset_weed (dst);
       break;
 
-    case BITSET_EQUAL_P:
+      /* Return 1 if DST == SRC.  */
+    case BITSET_OP_EQUAL_P:
       return lbitset_equal_p (dst, src);
       break;
 
-    case BITSET_SUBSET_P:
+      /* Return 1 if DST == DST | SRC.  */
+    case BITSET_OP_SUBSET_P:
       for (selt = LBITSET_HEAD (src), delt = LBITSET_HEAD (dst);
 	   selt || delt; selt = selt->next, delt = delt->next)
 	{
@@ -1001,6 +1048,31 @@ lbitset_op2 (dst, src, op)
 	}
       break;
 
+      /* Return 1 if DST & SRC == 0.  */
+    case BITSET_OP_DISJOINT_P:
+      for (selt = LBITSET_HEAD (src), delt = LBITSET_HEAD (dst);
+	   selt && delt; selt = selt->next, delt = delt->next)
+	{
+	  if (selt->index != delt->index)
+	    {
+	      if (selt->index < delt->index)
+		{
+		  lbitset_zero_elts[2].next = delt;
+		  delt = &lbitset_zero_elts[2];
+		}
+	      else
+		{
+		  lbitset_zero_elts[1].next = selt;
+		  selt = &lbitset_zero_elts[1];
+		}
+	    }
+
+	  for (j = 0; j < LBITSET_ELT_WORDS; j++)
+	    if (selt->words[j] & delt->words[j])
+	      return 0;
+	}
+      break;
+
     default:
       abort ();
     }
@@ -1034,36 +1106,36 @@ lbitset_op3 (dst, src1, src2, op)
   /* Fast track common, simple cases.  */
   if (!selt2)
     {
-      if (op == BITSET_AND)
+      if (op == BITSET_OP_AND)
 	{
 	  lbitset_weed (dst);
-	  changed = ! LBITSET_HEAD (dst);
+	  changed = !LBITSET_HEAD (dst);
 	  lbitset_zero (dst);
 	  return changed;
 	}
-      else if (op == BITSET_ANDN || op == BITSET_OR || op == BITSET_XOR)
+      else if (op == BITSET_OP_ANDN || op == BITSET_OP_OR
+	       || op == BITSET_OP_XOR)
 	{
 	  return lbitset_copy_compare (dst, src1);
 	}
     }
   else if (!selt1)
     {
-      if (op == BITSET_AND || op == BITSET_ANDN)
+      if (op == BITSET_OP_AND || op == BITSET_OP_ANDN)
 	{
 	  lbitset_weed (dst);
-	  changed = ! LBITSET_HEAD (dst);
+	  changed = !LBITSET_HEAD (dst);
 	  lbitset_zero (dst);
 	  return changed;
 	}
-      else if (op == BITSET_OR || op == BITSET_XOR)
+      else if (op == BITSET_OP_OR || op == BITSET_OP_XOR)
 	{
 	  return lbitset_copy_compare (dst, src2);
 	}
     }
 
-
   LBITSET_HEAD (dst) = 0;
-  dst->csize = 0;
+  dst->b.csize = 0;
 
   index1 = (selt1) ? selt1->index : BITSET_INDEX_MAX;
   index2 = (selt2) ? selt2->index : BITSET_INDEX_MAX;
@@ -1123,7 +1195,7 @@ lbitset_op3 (dst, src1, src2, op)
       dstp = dtmp->words;
       switch (op)
 	{
-	case BITSET_OR:
+	case BITSET_OP_OR:
 	  for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
 	    {
 	      bitset_word tmp = *srcp1++ | *srcp2++;
@@ -1136,7 +1208,7 @@ lbitset_op3 (dst, src1, src2, op)
 	    }
 	  break;
 
-	case BITSET_AND:
+	case BITSET_OP_AND:
 	  for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
 	    {
 	      bitset_word tmp = *srcp1++ & *srcp2++;
@@ -1149,7 +1221,7 @@ lbitset_op3 (dst, src1, src2, op)
 	    }
 	  break;
 
-	case BITSET_XOR:
+	case BITSET_OP_XOR:
 	  for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
 	    {
 	      bitset_word tmp = *srcp1++ ^ *srcp2++;
@@ -1162,7 +1234,7 @@ lbitset_op3 (dst, src1, src2, op)
 	    }
 	  break;
 
-	case BITSET_ANDN:
+	case BITSET_OP_ANDN:
 	  for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
 	    {
 	      bitset_word tmp = *srcp1++ & ~(*srcp2++);
@@ -1175,7 +1247,7 @@ lbitset_op3 (dst, src1, src2, op)
 	    }
 	  break;
 
-	case BITSET_ORN:
+	case BITSET_OP_ORN:
 	  for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
 	    {
 	      bitset_word tmp = *srcp1++ | ~(*srcp2++);
@@ -1192,7 +1264,7 @@ lbitset_op3 (dst, src1, src2, op)
 	  abort ();
 	}
 
-      if (! lbitset_elt_zero_p (dtmp))
+      if (!lbitset_elt_zero_p (dtmp))
 	{
 	  dtmp->index = index;
 	  /* Perhaps this could be optimised...  */
@@ -1215,67 +1287,21 @@ lbitset_op3 (dst, src1, src2, op)
 }
 
 
-static int
-lbitset_op4 (dst, src1, src2, src3, op)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     bitset src3;
-     enum bitset_ops op;
-{
-  int changed = 0;
-  bitset tmp;
-
-#ifdef ENABLE_CHECKING
-  /* Check for compatiblity.  */
-  if (src1->ops != dst->ops || src2->ops != dst->ops || src3->ops != dst->ops)
-    abort ();
-#endif
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
-  return changed;
-}
-
-
 /* Vector of operations for linked-list bitsets.  */
-struct bitset_ops_struct lbitset_ops =
-  {
-    lbitset_set,
-    lbitset_reset,
-    lbitset_test,
-    lbitset_size,
-    lbitset_op1,
-    lbitset_op2,
-    lbitset_op3,
-    lbitset_op4,
-    lbitset_list,
-    lbitset_reverse_list,
-    lbitset_free,
-    BITSET_LIST
-  };
+struct bitset_ops_struct lbitset_ops = {
+  lbitset_set,
+  lbitset_reset,
+  lbitset_test,
+  lbitset_size,
+  lbitset_op1,
+  lbitset_op2,
+  lbitset_op3,
+  bitset_op4,
+  lbitset_list,
+  lbitset_reverse_list,
+  lbitset_free,
+  BITSET_LIST
+};
 
 
 /* Return size of initial structure.  */
@@ -1294,17 +1320,7 @@ lbitset_init (bset, n_bits)
      bitset bset;
      bitset_bindex n_bits ATTRIBUTE_UNUSED;
 {
-  LBITSET_HEAD (bset) = 0;
-  LBITSET_TAIL (bset) = 0;
-
-  bset->ops = &lbitset_ops;
-
-  bset->cindex = 0;
-  /* Disable cache until have some elements allocated.
-     If we have variable length arrays, then we may
-     need to allocate dummy element.  */
-  bset->csize = 0;
-  bset->cdata = 0;
+  bset->b.ops = &lbitset_ops;
   return bset;
 }
 
