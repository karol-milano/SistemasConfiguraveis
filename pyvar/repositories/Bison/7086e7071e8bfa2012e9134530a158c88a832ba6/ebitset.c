@@ -0,0 +1,1245 @@
+/* Functions to support efficient bitsets.
+   Copyright (C) 2002 Free Software Foundation, Inc.
+   Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
+
+This program is free software; you can redistribute it and/or modify
+it under the terms of the GNU General Public License as published by
+the Free Software Foundation; either version 2 of the License, or
+(at your option) any later version.
+
+This program is distributed in the hope that it will be useful,
+but WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+GNU General Public License for more details.
+
+You should have received a copy of the GNU General Public License
+along with this program; if not, write to the Free Software
+Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
+
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
+#include "bitset.h"
+#include "obstack.h"
+#include <stdlib.h>
+
+# if WITH_DMALLOC
+#  define DMALLOC_FUNC_CHECK
+#  include <dmalloc.h>
+# endif /* WITH_DMALLOC */
+
+/* This file implements linked-list bitsets.  These bitsets can be of
+   arbitrary length and are more efficient than arrays of bits for
+   large sparse sets.
+
+   Usually if all the bits in an element are zero we remove the element
+   from the list.  However, a side effect of the bit caching is that we
+   do not always notice when an element becomes zero.  Hence the
+   ebitset_weed function which removes zero elements.
+
+   Empty elements are represented by a NULL pointer in the table of
+   element pointers.  An alternative is to point to a special zero
+   element.  Similarly, we could represent an all 1's element with
+   another special ones element pointer.
+
+   Bitsets are commonly empty so we need to ensure that this special
+   case is fast.  A zero bitset is indicated when cdata is 0.  This is
+   conservative since cdata may be non zero and the bitset may still
+   be zero.
+
+   The bitset cache can be disabled either by setting cindex to
+   some large number or by setting csize to 0.  Here
+   we use the former approach since cindex needs to be updated whenever
+   cdata is changed.
+*/
+
+/* Number of elements to initially allocate.  */
+#ifndef EBITSET_INITIAL_SIZE
+#define EBITSET_INITIAL_SIZE 2
+#endif
+
+/* Minimum number of elements to grow table.  */
+#ifndef EBITSET_GROW_SIZE
+#define EBITSET_GROW_SIZE 4
+#endif
+
+
+enum ebitset_find_mode {EBITSET_FIND, EBITSET_CREATE, EBITSET_SUBST};
+
+static ebitset_elt ebitset_zero_elts[1]; /* Elements of all zero bits.  */
+
+/* Obstack to allocate bitset elements from.  */
+static struct obstack ebitset_obstack;
+static int ebitset_obstack_init = 0;
+static ebitset_elt *ebitset_free_list; /* Free list of bitset elements.  */
+
+static void ebitset_elts_grow PARAMS ((bitset, unsigned int));
+static ebitset_elt *ebitset_elt_alloc PARAMS ((void));
+static ebitset_elt *ebitset_elt_calloc PARAMS ((void));
+static void ebitset_elt_add PARAMS ((bitset, ebitset_elt *, unsigned int));
+static void ebitset_elt_remove PARAMS ((bitset, unsigned int));
+static void ebitset_elt_free PARAMS ((ebitset_elt *));
+static ebitset_elt *ebitset_elt_find PARAMS ((bitset, bitset_windex,
+					      enum ebitset_find_mode));
+static ebitset_elt *ebitset_elt_last PARAMS ((bitset));
+static int ebitset_elt_zero_p PARAMS ((ebitset_elt *));
+
+static int ebitset_weed PARAMS ((bitset));
+static void ebitset_zero PARAMS((bitset));
+static int ebitset_equal_p PARAMS((bitset, bitset));
+static void ebitset_copy PARAMS((bitset, bitset));
+static int ebitset_copy_compare PARAMS((bitset, bitset));
+static void ebitset_set PARAMS((bitset, bitset_bindex));
+static void ebitset_reset PARAMS((bitset, bitset_bindex));
+static int ebitset_test PARAMS((bitset, bitset_bindex));
+static int ebitset_size PARAMS((bitset));
+static int ebitset_op1 PARAMS((bitset, enum bitset_ops));
+static int ebitset_op2 PARAMS((bitset, bitset, enum bitset_ops));
+static int ebitset_op3 PARAMS((bitset, bitset, bitset, enum bitset_ops));
+static int ebitset_op4 PARAMS((bitset, bitset, bitset, bitset,
+			       enum bitset_ops));
+static int ebitset_list PARAMS((bitset, bitset_bindex *, bitset_bindex,
+				bitset_bindex *));
+static int ebitset_reverse_list PARAMS((bitset, bitset_bindex *, bitset_bindex,
+					bitset_bindex *));
+static void ebitset_free PARAMS((bitset));
+
+
+#define EBITSET_ELTS(BSET) ((BSET)->u.e.elts)
+#define EBITSET_SIZE(BSET) ((BSET)->u.e.size)
+
+#define EBITSET_NEXT(ELT) ((ELT)->u.next)
+#define EBITSET_WORDS(ELT) ((ELT)->u.words)
+
+/* Disable bitset cache and mark BSET as being zero.  */
+#define EBITSET_ZERO_SET(BSET) ((BSET)->cindex = BITSET_INDEX_MAX, \
+        (BSET)->cdata = 0)
+
+#define EBITSET_CACHE_DISABLE(BSET)  ((BSET)->cindex = BITSET_INDEX_MAX)
+
+/* Disable bitset cache and mark BSET as being possibly non-zero.  */
+#define EBITSET_NONZERO_SET(BSET) \
+ (EBITSET_CACHE_DISABLE (BSET), (BSET)->cdata = (bitset_word *)~0)
+
+/* A conservative estimate of whether the bitset is zero.
+   This is non-zero only if we know for sure that the bitset is zero.  */
+#define EBITSET_ZERO_P(BSET) ((BSET)->cdata == 0)
+
+/* Enable cache to point to element with table index EINDEX.
+   The element must exist.  */
+#define EBITSET_CACHE_SET(BSET, EINDEX) \
+ ((BSET)->cindex = (EINDEX) * EBITSET_ELT_WORDS, \
+  (BSET)->cdata = EBITSET_WORDS (EBITSET_ELTS (BSET) [EINDEX]))
+
+
+/* Grow the expandable table for BSET by SIZE elements.  */
+static void
+ebitset_elts_grow (bset, size)
+    bitset bset;
+    unsigned int size;
+{
+  unsigned int oldsize;
+  unsigned int newsize;
+
+  oldsize = EBITSET_SIZE (bset);
+  newsize = oldsize + size;
+
+  EBITSET_ELTS (bset) = xrealloc (EBITSET_ELTS (bset),
+				   newsize * sizeof (ebitset_elt *));
+  EBITSET_SIZE (bset) = newsize;
+
+  memset (EBITSET_ELTS (bset) + oldsize, 0, size * sizeof (ebitset_elt *));
+}
+
+
+/* Allocate a ebitset element.  The bits are not cleared.  */
+static inline ebitset_elt *
+ebitset_elt_alloc ()
+{
+  ebitset_elt *elt;
+
+  if (ebitset_free_list != 0)
+    {
+      elt = ebitset_free_list;
+      ebitset_free_list = EBITSET_NEXT (elt);
+    }
+  else
+    {
+      /* We can't use gcc_obstack_init to initialize the obstack since
+	 print-rtl.c now calls bitset functions, and bitset is linked
+	 into the gen* functions.  */
+      if (!ebitset_obstack_init)
+	{
+	  ebitset_obstack_init = 1;
+
+	  /* Let particular systems override the size of a chunk.  */
+#ifndef OBSTACK_CHUNK_SIZE
+#define OBSTACK_CHUNK_SIZE 0
+#endif
+	  /* Let them override the alloc and free routines too.  */
+#ifndef OBSTACK_CHUNK_ALLOC
+#define OBSTACK_CHUNK_ALLOC xmalloc
+#endif
+#ifndef OBSTACK_CHUNK_FREE
+#define OBSTACK_CHUNK_FREE free
+#endif
+
+#if !defined(__GNUC__) || (__GNUC__ < 2)
+#define __alignof__(type) 0
+#endif
+
+	  obstack_specify_allocation (&ebitset_obstack, OBSTACK_CHUNK_SIZE,
+				      __alignof__ (ebitset_elt),
+				      (void *(*) PARAMS ((long))) OBSTACK_CHUNK_ALLOC,
+				      (void (*) PARAMS ((void *))) OBSTACK_CHUNK_FREE);
+	}
+
+      /* Perhaps we should add a number of new elements to the free
+         list.  */
+      elt = (ebitset_elt *) obstack_alloc (&ebitset_obstack,
+					   sizeof (ebitset_elt));
+    }
+
+  return elt;
+}
+
+
+/* Allocate a ebitset element.  The bits are not cleared.  */
+static inline ebitset_elt *
+ebitset_elt_calloc ()
+{
+  ebitset_elt *elt;
+
+  elt = ebitset_elt_alloc ();
+  memset (EBITSET_WORDS (elt), 0, sizeof (EBITSET_WORDS (elt)));
+  return elt;
+}
+
+
+static inline void
+ebitset_elt_free (elt)
+     ebitset_elt *elt;
+{
+  EBITSET_NEXT (elt) = ebitset_free_list;
+  ebitset_free_list = elt;
+}
+
+
+/* Remove element with index EINDEX from bitset BSET.  */
+static inline void
+ebitset_elt_remove (bset, eindex)
+     bitset bset;
+     unsigned int eindex;
+{
+  ebitset_elts *elts;
+  ebitset_elt *elt;
+
+  elts = EBITSET_ELTS (bset);
+
+  elt = elts[eindex];
+
+  elts[eindex] = 0;
+  ebitset_elt_free (elt);
+}
+
+
+/* Add ELT into elts at index EINDEX of bitset BSET.  */
+static inline void
+ebitset_elt_add (bset, elt, eindex)
+     bitset bset;
+     ebitset_elt *elt;
+     unsigned int eindex;
+{
+  ebitset_elts *elts;
+
+  elts = EBITSET_ELTS (bset);
+  /* Assume that the elts entry not allocated.  */
+  elts[eindex] = elt;
+}
+
+
+/* Return nonzero if all bits in an element are zero.  */
+static inline int
+ebitset_elt_zero_p (elt)
+     ebitset_elt *elt;
+{
+  int i;
+
+  for (i = 0; i < EBITSET_ELT_WORDS; i++)
+    if (EBITSET_WORDS (elt)[i])
+      return 0;
+
+  return 1;
+}
+
+
+static ebitset_elt *
+ebitset_elt_find (bset, index, mode)
+     bitset bset;
+     bitset_windex index;
+     enum ebitset_find_mode mode;
+{
+  ebitset_elt *elt;
+  bitset_windex size;
+  unsigned int eindex;
+  ebitset_elts *elts;
+
+  eindex = index / EBITSET_ELT_WORDS;
+
+  elts = EBITSET_ELTS (bset);
+  size = EBITSET_SIZE (bset);
+
+  if (eindex < size)
+    {
+      ebitset_elt *elt;
+
+      if ((elt = elts[eindex]))
+	{
+	  if (EBITSET_WORDS (elt) == bset->cdata)
+	    return elt;
+
+	  EBITSET_CACHE_SET (bset, eindex);
+	  return elt;
+	}
+    }
+
+  /* The element could not be found.  */
+
+  switch (mode)
+    {
+    case EBITSET_FIND:
+      return 0;
+
+    case EBITSET_CREATE:
+      if (eindex >= size)
+	{
+	  unsigned int extra;
+
+	  extra = eindex - size + 1;
+
+	  /* We need to expand the table by EXTRA elements.  It may be
+	     better with large bitsets to grow the number of
+	     elements by some fraction of the current size otherwise
+	     we can spend a lot of time slowly increasing the size of the
+	     bitset.  */
+	  if (extra < EBITSET_GROW_SIZE)
+	    extra = EBITSET_GROW_SIZE;
+
+	  ebitset_elts_grow (bset, extra);
+	}
+
+      /* Create a new element.  */
+      elt = ebitset_elt_calloc ();
+      ebitset_elt_add (bset, elt, eindex);
+      EBITSET_CACHE_SET (bset, eindex);
+      return elt;
+
+    case EBITSET_SUBST:
+      return &ebitset_zero_elts[0];
+
+    default:
+      abort ();
+    }
+}
+
+
+static inline ebitset_elt *
+ebitset_elt_last (bset)
+     bitset bset;
+{
+  ebitset_elts *elts;
+
+  elts = EBITSET_ELTS (bset);
+
+  /* Assume that have at least one element in elts.  */
+  return elts[EBITSET_SIZE (bset) - 1];
+}
+
+
+/* Weed out the zero elements from the elts.  */
+static inline int
+ebitset_weed (bset)
+     bitset bset;
+{
+  ebitset_elts *elts;
+  bitset_windex j;
+  int count;
+
+  if (EBITSET_ZERO_P (bset))
+    return 0;
+
+  elts = EBITSET_ELTS (bset);
+  count = 0;
+  for (j = 0; j < EBITSET_SIZE (bset); j++)
+    {
+      ebitset_elt *elt = elts[j];
+
+      if (elt)
+	{
+	  if (elt && ebitset_elt_zero_p (elt))
+	    {
+	      ebitset_elt_remove (bset, j);
+	      count++;
+	    }
+	}
+      else
+	count++;
+    }
+
+  count = j - count;
+  if (!count)
+    {
+      /* All the bits are zero.  We could shrink the elts.
+	 For now just mark BSET as known to be zero.  */
+      EBITSET_ZERO_SET (bset);
+    }
+  else
+    EBITSET_NONZERO_SET (bset);
+
+  return  count;
+}
+
+
+/* Set all bits in the bitset to zero.  */
+static inline void
+ebitset_zero (bset)
+     bitset bset;
+{
+  ebitset_elts *elts;
+  bitset_windex j;
+
+  if (EBITSET_ZERO_P (bset))
+    return;
+
+  elts = EBITSET_ELTS (bset);
+  for (j = 0; j < EBITSET_SIZE (bset); j++)
+    {
+      ebitset_elt *elt = elts[j];
+
+      if (elt)
+	ebitset_elt_remove (bset, j);
+    }
+
+  /* All the bits are zero.  We could shrink the elts.
+     For now just mark BSET as known to be zero.  */
+  EBITSET_ZERO_SET (bset);
+}
+
+
+static inline int
+ebitset_equal_p (dst, src)
+     bitset dst;
+     bitset src;
+{
+  ebitset_elts *selts;
+  ebitset_elts *delts;
+  bitset_windex j;
+
+  if (src == dst)
+    return 1;
+
+  ebitset_weed (dst);
+  ebitset_weed (src);
+
+  if (EBITSET_SIZE (src) != EBITSET_SIZE (dst))
+    return 0;
+
+  selts = EBITSET_ELTS (src);
+  delts = EBITSET_ELTS (dst);
+
+  for (j = 0; j < EBITSET_SIZE (src); j++)
+    {
+      unsigned int i;
+      ebitset_elt *selt = selts[j];
+      ebitset_elt *delt = delts[j];
+
+      if (! selt && ! delt)
+	continue;
+      if ((selt && ! delt) || (!selt && delt))
+	return 0;
+
+      for (i = 0; i < EBITSET_ELT_WORDS; i++)
+	if (EBITSET_WORDS (selt)[i] != EBITSET_WORDS (delt)[i])
+	  return 0;
+    }
+  return 1;
+}
+
+
+/* Copy bits from bitset SRC to bitset DST.  */
+static inline void
+ebitset_copy (dst, src)
+     bitset dst;
+     bitset src;
+{
+  ebitset_elts *selts;
+  ebitset_elts *delts;
+  bitset_windex j;
+
+  if (src == dst)
+    return;
+
+  ebitset_zero (dst);
+
+  if (EBITSET_SIZE (dst) < EBITSET_SIZE (src))
+    ebitset_elts_grow (dst, EBITSET_SIZE (src) - EBITSET_SIZE (dst));
+
+  selts = EBITSET_ELTS (src);
+  delts = EBITSET_ELTS (dst);
+  for (j = 0; j < EBITSET_SIZE (src); j++)
+    {
+      ebitset_elt *selt = selts[j];
+
+      if (selt)
+	{
+	  ebitset_elt *tmp;
+
+	  tmp = ebitset_elt_alloc ();
+	  delts[j] = tmp;
+	  memcpy (EBITSET_WORDS (tmp), EBITSET_WORDS (selt),
+		  sizeof (EBITSET_WORDS (selt)));
+	}
+    }
+  EBITSET_NONZERO_SET (dst);
+}
+
+
+/* Copy bits from bitset SRC to bitset DST.  Return non-zero if
+   bitsets different.  */
+static inline int
+ebitset_copy_compare (dst, src)
+     bitset dst;
+     bitset src;
+{
+  if (src == dst)
+    return 0;
+
+  if (EBITSET_ZERO_P (dst))
+    {
+      ebitset_copy (dst, src);
+      return ! EBITSET_ZERO_P (src);
+    }
+
+  if (ebitset_equal_p (dst, src))
+    return 0;
+
+  ebitset_copy (dst, src);
+  return 1;
+}
+
+
+/* Return size in bits of bitset SRC.  */
+static int
+ebitset_size (src)
+     bitset src;
+{
+  /* Return current size of bitset in bits.  */
+  return EBITSET_SIZE (src) * EBITSET_ELT_BITS;
+}
+
+
+/* Set bit BITNO in bitset DST.  */
+static void
+ebitset_set (dst, bitno)
+     bitset dst;
+     bitset_bindex bitno;
+{
+  bitset_windex index = bitno / BITSET_WORD_BITS;
+
+  ebitset_elt_find (dst, index, EBITSET_CREATE);
+
+  dst->cdata[index - dst->cindex] |= (1 << (bitno % BITSET_WORD_BITS));
+}
+
+
+/* Reset bit BITNO in bitset DST.  */
+static void
+ebitset_reset (dst, bitno)
+     bitset dst;
+     bitset_bindex bitno;
+{
+  bitset_windex index = bitno / BITSET_WORD_BITS;
+
+  if (!ebitset_elt_find (dst, index, EBITSET_FIND))
+      return;
+
+  dst->cdata[index - dst->cindex] &= ~(1 << (bitno % BITSET_WORD_BITS));
+
+  /* If all the data is zero, perhaps we should remove it now...
+     However, there could be a good chance that the element will be needed
+     again soon.  */
+}
+
+
+/* Test bit BITNO in bitset SRC.  */
+static int
+ebitset_test (src, bitno)
+     bitset src;
+     bitset_bindex bitno;
+{
+  bitset_windex index = bitno / BITSET_WORD_BITS;
+
+  if (!ebitset_elt_find (src, index, EBITSET_FIND))
+    return 0;
+
+  return (src->cdata[index - src->cindex] >> (bitno % BITSET_WORD_BITS)) & 1;
+}
+
+
+static void
+ebitset_free (bset)
+     bitset bset;
+{
+  ebitset_zero (bset);
+  free (EBITSET_ELTS (bset));
+}
+
+
+/* Find list of up to NUM bits set in BSET starting from and including
+   *NEXT and store in array LIST.  Return with actual number of bits
+   found and with *NEXT indicating where search stopped.  */
+static int
+ebitset_reverse_list (bset, list, num, next)
+     bitset bset;
+     bitset_bindex *list;
+     bitset_bindex num;
+     bitset_bindex *next;
+{
+  bitset_bindex n_bits;
+  bitset_bindex bitno;
+  bitset_bindex rbitno;
+  unsigned int bitcnt;
+  bitset_bindex bitoff;
+  bitset_windex index;
+  unsigned int eindex;
+  bitset_windex windex;
+  bitset_bindex count;
+  bitset_windex size;
+  bitset_word word;
+  ebitset_elts *elts;
+
+  if (EBITSET_ZERO_P (bset))
+    return 0;
+
+  size = EBITSET_SIZE (bset);
+  n_bits = size * EBITSET_ELT_BITS;
+  rbitno = *next;
+
+  if (rbitno >= n_bits)
+      return 0;
+
+  elts = EBITSET_ELTS (bset);
+
+  bitno = n_bits - (rbitno + 1);
+
+  index = bitno /  BITSET_WORD_BITS;
+  eindex = bitno / EBITSET_ELT_BITS;
+  windex = index - eindex * EBITSET_ELT_WORDS;
+
+  /* If num is 1, we could speed things up with a binary search
+     of the word of interest.  */
+
+  count = 0;
+  bitcnt = bitno % BITSET_WORD_BITS;
+  bitoff = index * BITSET_WORD_BITS;
+
+  for (; eindex != ~0U; eindex--)
+    {
+      ebitset_elt *elt;
+      bitset_word *srcp;
+
+      elt = elts[eindex];
+      if (!elt)
+	continue;
+
+      srcp = EBITSET_WORDS (elt);
+
+      for (; windex != ~0U; windex--, bitoff -= BITSET_WORD_BITS,
+	     bitcnt = BITSET_WORD_BITS - 1)
+	{
+	  word = srcp[windex] << (BITSET_WORD_BITS - 1 - bitcnt);
+
+	  for (; word; bitcnt--)
+	    {
+	      if (word & BITSET_MSB)
+		{
+		  list[count++] = bitoff + bitcnt;
+		  if (count >= num)
+		    {
+		      *next = n_bits - (bitoff + bitcnt);
+		      return count;
+		    }
+		}
+	      word <<= 1;
+	    }
+	}
+
+      windex = EBITSET_ELT_WORDS;
+    }
+
+  *next = n_bits - (bitoff + 1);
+  return count;
+}
+
+
+/* Find list of up to NUM bits set in BSET starting from and including
+   *NEXT and store in array LIST.  Return with actual number of bits
+   found and with *NEXT indicating where search stopped.  */
+static int
+ebitset_list (bset, list, num, next)
+     bitset bset;
+     bitset_bindex *list;
+     bitset_bindex num;
+     bitset_bindex *next;
+{
+  bitset_bindex bitno;
+  bitset_windex index;
+  unsigned int eindex;
+  bitset_bindex count;
+  bitset_windex size;
+  ebitset_elt *elt;
+  bitset_word word;
+  ebitset_elts *elts;
+
+  if (EBITSET_ZERO_P (bset))
+    return 0;
+
+  bitno = *next;
+  count = 0;
+
+  elts = EBITSET_ELTS (bset);
+  size = EBITSET_SIZE (bset);
+  eindex = bitno / EBITSET_ELT_BITS;
+
+  if (bitno % EBITSET_ELT_BITS)
+    {
+      /* We need to start within an element.  This is not very common.  */
+
+      elt = elts[eindex];
+      if (elt)
+	{
+	  bitset_windex windex;
+	  bitset_word *srcp = EBITSET_WORDS (elt);
+
+	  index = bitno / BITSET_WORD_BITS;
+	  windex = eindex / EBITSET_ELT_WORDS;
+
+	  for (; (index - windex) < EBITSET_ELT_WORDS; index++)
+	    {
+	      word = srcp[index - windex] >> (bitno % BITSET_WORD_BITS);
+
+	      for (; word; bitno++)
+		{
+		  if (word & 1)
+		    {
+		      list[count++] = bitno;
+		      if (count >= num)
+			{
+			  *next = bitno + 1;
+			  return count;
+			}
+		    }
+		  word >>= 1;
+		}
+	      bitno = (index + 1) * BITSET_WORD_BITS;
+	    }
+	}
+
+      /* Skip to next element.  */
+      eindex++;
+    }
+
+  /* If num is 1, we could speed things up with a binary search
+     of the word of interest.  */
+
+  for (; eindex < size; eindex++)
+    {
+      int i;
+      ebitset_elt *elt;
+      bitset_word *srcp;
+
+      elt = elts[eindex];
+      if (!elt)
+	continue;
+
+      srcp = EBITSET_WORDS (elt);
+      index = eindex * EBITSET_ELT_WORDS;
+
+      if ((count + EBITSET_ELT_BITS) < num)
+	{
+	  /* The coast is clear, plant boot!  */
+
+	  for (i = 0; i < EBITSET_ELT_WORDS; i++, index++)
+	    {
+	      bitno = index * BITSET_WORD_BITS;
+
+	      word = srcp[i];
+	      if (word)
+		{
+		  if (! (word & 0xffff))
+		    {
+		      word >>= 16;
+		      bitno += 16;
+		    }
+		  if (! (word & 0xff))
+		    {
+		      word >>= 8;
+		      bitno += 8;
+		    }
+		  for (; word; bitno++)
+		    {
+		      if (word & 1)
+			list[count++] = bitno;
+		      word >>= 1;
+		    }
+		}
+	    }
+	}
+      else
+	{
+	  /* Tread more carefully since we need to check
+	     if array overflows.  */
+
+	  for (i = 0; i < EBITSET_ELT_WORDS; i++, index++)
+	    {
+	      bitno = index * BITSET_WORD_BITS;
+
+	      for (word = srcp[i]; word; bitno++)
+		{
+		  if (word & 1)
+		    {
+		      list[count++] = bitno;
+		      if (count >= num)
+			{
+			  *next = bitno + 1;
+			  return count;
+			}
+		    }
+		  word >>= 1;
+		}
+	    }
+	}
+    }
+
+  *next = bitno;
+  return count;
+}
+
+
+static int
+ebitset_op1 (dst, op)
+     bitset dst;
+     enum bitset_ops op;
+{
+  bitset_windex j;
+  ebitset_elt *elt;
+
+  switch (op)
+    {
+    case BITSET_ZERO:
+      ebitset_zero (dst);
+      return 1;
+
+    case BITSET_ONES:
+      for (j = 0; j < EBITSET_SIZE (dst); j++)
+	{
+	  /* Create new elements if they cannot be found.  Perhaps
+	   we should just add pointers to a ones element.  */
+	  elt = ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_CREATE);
+	  memset (EBITSET_WORDS (elt), ~0, sizeof (EBITSET_WORDS (elt)));
+	}
+      break;
+
+    case BITSET_EMPTY_P:
+      return ! ebitset_weed (dst);
+
+    default:
+      abort ();
+    }
+
+  EBITSET_NONZERO_SET (dst);
+  return 1;
+}
+
+
+static int
+ebitset_op2 (dst, src, op)
+     bitset dst;
+     bitset src;
+     enum bitset_ops op;
+{
+  ebitset_elt *selt;
+  ebitset_elt *delt;
+  unsigned int i;
+  bitset_windex j;
+
+  switch (op)
+    {
+    case BITSET_COPY:
+      ebitset_copy (dst, src);
+      break;
+
+    case BITSET_NOT:
+      for (j = 0; j < EBITSET_SIZE (src); j++)
+	{
+	  /* Create new elements for dst if they cannot be found
+	     or substitute zero elements if src elements not found.  */
+	  selt = ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_SUBST);
+	  delt = ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_CREATE);
+
+	  for (i = 0; i < EBITSET_ELT_WORDS; i++)
+	    EBITSET_WORDS (delt)[i] = ~EBITSET_WORDS (selt)[i];
+	}
+      break;
+
+    case BITSET_EQUAL_P:
+      return ebitset_equal_p (dst, src);
+
+      /* Return 1 if DST == DST | SRC.  */
+    case BITSET_SUBSET_P:
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
+	    if (! selt && ! delt)
+	      continue;
+
+	    if (!selt)
+	      selt = &ebitset_zero_elts[0];
+	    if (!delt)
+	      delt = &ebitset_zero_elts[0];
+
+	    for (i = 0; i < EBITSET_ELT_WORDS; i++)
+	      if (EBITSET_WORDS (delt)[i]
+		  != (EBITSET_WORDS (selt)[i] | EBITSET_WORDS (delt)[i]))
+		return 0;
+	  }
+	return 1;
+      }
+      break;
+
+    default:
+      abort ();
+    }
+
+  EBITSET_NONZERO_SET (dst);
+  return 1;
+}
+
+
+static int
+ebitset_op3 (dst, src1, src2, op)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     enum bitset_ops op;
+{
+  bitset_windex ssize1;
+  bitset_windex ssize2;
+  bitset_windex dsize;
+  bitset_windex size;
+  ebitset_elts *selts1;
+  ebitset_elts *selts2;
+  ebitset_elts *delts;
+  bitset_word *srcp1;
+  bitset_word *srcp2;
+  bitset_word *dstp;
+  int changed = 0;
+  unsigned int i;
+  bitset_windex j;
+
+  /* Fast track common, simple cases.  */
+  if (EBITSET_ZERO_P (src2))
+    {
+      if (op == BITSET_AND)
+	{
+	  ebitset_weed (dst);
+	  changed = EBITSET_ZERO_P (dst);
+	  ebitset_zero (dst);
+	  return changed;
+	}
+      else if (op == BITSET_ANDN || op == BITSET_OR || op == BITSET_XOR)
+	{
+	  return ebitset_copy_compare (dst, src1);
+	}
+    }
+  else if (EBITSET_ZERO_P (src1))
+    {
+      if (op == BITSET_AND || op == BITSET_ANDN)
+	{
+	  ebitset_weed (dst);
+	  changed = EBITSET_ZERO_P (dst);
+	  ebitset_zero (dst);
+	  return changed;
+	}
+      else if (op == BITSET_OR || op == BITSET_XOR)
+	{
+	  return ebitset_copy_compare (dst, src2);
+	}
+    }
+
+  ssize1 = EBITSET_SIZE (src1);
+  ssize2 = EBITSET_SIZE (src2);
+  dsize = EBITSET_SIZE (dst);
+  size = ssize1;
+  if (size < ssize2)
+    size = ssize2;
+
+  if (size > dsize)
+      ebitset_elts_grow (dst, size - dsize);
+
+  selts1 = EBITSET_ELTS (src1);
+  selts2 = EBITSET_ELTS (src2);
+  delts = EBITSET_ELTS (dst);
+
+  for (j = 0; j < size; j++)
+    {
+      ebitset_elt *selt1;
+      ebitset_elt *selt2;
+      ebitset_elt *delt;
+
+      selt1 = j < ssize1 ? selts1[j] : 0;
+      selt2 = j < ssize2 ? selts2[j] : 0;
+      delt = j < dsize ? delts[j] : 0;
+
+      if (! selt1 && ! selt2)
+	{
+	  if (delt)
+	    {
+	      changed = 1;
+	      ebitset_elt_remove (dst, j);
+	    }
+	  continue;
+	}
+
+      if (!selt1)
+	selt1 = &ebitset_zero_elts[0];
+      if (!selt2)
+	selt2 = &ebitset_zero_elts[0];
+      if (!delt)
+	delt = ebitset_elt_calloc ();
+      else
+	delts[j] = 0;
+
+      srcp1 = EBITSET_WORDS (selt1);
+      srcp2 = EBITSET_WORDS (selt2);
+      dstp = EBITSET_WORDS (delt);
+      switch (op)
+	{
+	case BITSET_OR:
+	  for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
+	    {
+	      bitset_word tmp = *srcp1++ | *srcp2++;
+
+	      if (*dstp != tmp)
+		{
+		  changed = 1;
+		  *dstp = tmp;
+		}
+	    }
+	  break;
+
+	case BITSET_AND:
+	  for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
+	    {
+	      bitset_word tmp = *srcp1++ & *srcp2++;
+
+	      if (*dstp != tmp)
+		{
+		  changed = 1;
+		  *dstp = tmp;
+		}
+	    }
+	  break;
+
+	case BITSET_XOR:
+	  for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
+	    {
+	      bitset_word tmp = *srcp1++ ^ *srcp2++;
+
+	      if (*dstp != tmp)
+		{
+		  changed = 1;
+		  *dstp = tmp;
+		}
+	    }
+	  break;
+
+	case BITSET_ANDN:
+	  for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
+	    {
+	      bitset_word tmp = *srcp1++ & ~(*srcp2++);
+
+	      if (*dstp != tmp)
+		{
+		  changed = 1;
+		  *dstp = tmp;
+		}
+	    }
+	  break;
+
+	case BITSET_ORN:
+	  for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
+	    {
+	      bitset_word tmp = *srcp1++ | ~(*srcp2++);
+
+	      if (*dstp != tmp)
+		{
+		  changed = 1;
+		  *dstp = tmp;
+		}
+	    }
+	  break;
+
+	default:
+	  abort ();
+	}
+
+      if (! ebitset_elt_zero_p (delt))
+	{
+	  ebitset_elt_add (dst, delt, j);
+	}
+      else
+	{
+	  ebitset_elt_free (delt);
+	}
+    }
+
+  /* If we have elements of DST left over, free them all.  */
+  for (; j < dsize; j++)
+    {
+      ebitset_elt *delt;
+
+      changed = 1;
+
+      delt = delts[j];
+
+      if (delt)
+	ebitset_elt_remove (dst, j);
+    }
+
+  EBITSET_NONZERO_SET (dst);
+  return changed;
+}
+
+
+static int
+ebitset_op4 (dst, src1, src2, src3, op)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+     enum bitset_ops op;
+{
+  int changed = 0;
+  bitset tmp;
+
+  tmp = bitset_create (BITSET_LIST, 0);
+
+  switch (op)
+    {
+    case BITSET_OR_AND:
+      bitset_or (tmp, src1, src2);
+      changed = bitset_and (dst, src3, tmp);
+      break;
+
+    case BITSET_AND_OR:
+      bitset_and (tmp, src1, src2);
+      changed = bitset_or (dst, src3, tmp);
+      break;
+
+    case BITSET_ANDN_OR:
+      bitset_andn (tmp, src1, src2);
+      changed = bitset_or (dst, src3, tmp);
+      break;
+
+    default:
+      abort ();
+    }
+
+  bitset_free (tmp);
+  EBITSET_NONZERO_SET (dst);
+  return changed;
+}
+
+
+/* Vector of operations for linked-list bitsets.  */
+struct bitset_ops_struct ebitset_ops =
+  {
+    ebitset_set,
+    ebitset_reset,
+    ebitset_test,
+    ebitset_size,
+    ebitset_op1,
+    ebitset_op2,
+    ebitset_op3,
+    ebitset_op4,
+    ebitset_list,
+    ebitset_reverse_list,
+    ebitset_free,
+    BITSET_TABLE
+  };
+
+
+/* Return size of initial structure.  */
+int
+ebitset_bytes (n_bits)
+     bitset_bindex n_bits ATTRIBUTE_UNUSED;
+{
+  return sizeof (struct bitset_struct);
+}
+
+
+/* Initialize a bitset.  */
+
+bitset
+ebitset_init (bset, n_bits)
+     bitset bset;
+     bitset_bindex n_bits;
+{
+  unsigned int size;
+
+  bset->ops = &ebitset_ops;
+
+  bset->csize = EBITSET_ELT_WORDS;
+
+  EBITSET_ZERO_SET (bset);
+
+  size = n_bits ? (n_bits + EBITSET_ELT_BITS - 1) / EBITSET_ELT_BITS
+    : EBITSET_INITIAL_SIZE;
+
+  EBITSET_SIZE (bset) = 0;
+  EBITSET_ELTS (bset) = 0;
+  ebitset_elts_grow (bset, size);
+
+  return bset;
+}
+
+
+void
+ebitset_release_memory ()
+{
+  ebitset_free_list = 0;
+  if (ebitset_obstack_init)
+    {
+      ebitset_obstack_init = 0;
+      obstack_free (&ebitset_obstack, NULL);
+    }
+}
