@@ -0,0 +1,1321 @@
+/* Functions to support link list bitsets.
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
+  Usually if all the bits in an element are zero we remove the element
+  from the list.  However, a side effect of the bit caching is that we
+  do not always notice when an element becomes zero.  Hence the
+  lbitset_weed function which removes zero elements.  */
+
+enum lbitset_find_mode {LBITSET_FIND, LBITSET_CREATE, LBITSET_SUBST};
+
+static lbitset_elt lbitset_zero_elts[3]; /* Elements of all zero bits.  */
+
+/* Obstack to allocate bitset elements from.  */
+static struct obstack lbitset_obstack;
+static int lbitset_obstack_init = 0;
+static lbitset_elt *lbitset_free_list; /* Free list of bitset elements.  */
+
+static lbitset_elt *lbitset_elt_alloc PARAMS ((void));
+static lbitset_elt *lbitset_elt_calloc PARAMS ((void));
+static void lbitset_elt_link PARAMS ((bitset, lbitset_elt *));
+static void lbitset_elt_unlink PARAMS ((bitset, lbitset_elt *));
+static void lbitset_elt_free PARAMS ((lbitset_elt *));
+static lbitset_elt *lbitset_elt_find PARAMS ((bitset, bitset_windex,
+					      enum lbitset_find_mode));
+static int lbitset_elt_zero_p PARAMS ((lbitset_elt *));
+
+static void lbitset_prune PARAMS ((bitset, lbitset_elt *));
+static void lbitset_weed PARAMS ((bitset));
+static void lbitset_zero PARAMS((bitset));
+static int lbitset_equal_p PARAMS((bitset, bitset));
+static void lbitset_copy PARAMS((bitset, bitset));
+static int lbitset_copy_compare PARAMS((bitset, bitset));
+static void lbitset_set PARAMS((bitset, bitset_bindex));
+static void lbitset_reset PARAMS((bitset, bitset_bindex));
+static int lbitset_test PARAMS((bitset, bitset_bindex));
+static int lbitset_size PARAMS((bitset));
+static int lbitset_op1 PARAMS((bitset, enum bitset_ops));
+static int lbitset_op2 PARAMS((bitset, bitset, enum bitset_ops));
+static int lbitset_op3 PARAMS((bitset, bitset, bitset, enum bitset_ops));
+static int lbitset_op4 PARAMS((bitset, bitset, bitset, bitset,
+			       enum bitset_ops));
+static int lbitset_list PARAMS((bitset, bitset_bindex *, bitset_bindex,
+				bitset_bindex *));
+static int lbitset_reverse_list PARAMS((bitset, bitset_bindex *, bitset_bindex,
+					bitset_bindex *));
+static void lbitset_free PARAMS((bitset));
+
+
+#define LBITSET_CURRENT1(X) (lbitset_elt *)((char *)(X) + ((char *)&(((lbitset_elt *)(X))->next) - (char *)&(((lbitset_elt *)(X))->words)))
+
+#define LBITSET_CURRENT(X) LBITSET_CURRENT1((X)->cdata)
+
+#define LBITSET_HEAD(X) ((X)->u.l.head)
+#define LBITSET_TAIL(X) ((X)->u.l.tail)
+
+/* Allocate a lbitset element.  The bits are not cleared.  */
+static inline lbitset_elt *
+lbitset_elt_alloc ()
+{
+  lbitset_elt *elt;
+
+  if (lbitset_free_list != 0)
+    {
+      elt = lbitset_free_list;
+      lbitset_free_list = elt->next;
+    }
+  else
+    {
+      /* We can't use gcc_obstack_init to initialize the obstack since
+	 print-rtl.c now calls bitset functions, and bitset is linked
+	 into the gen* functions.  */
+      if (!lbitset_obstack_init)
+	{
+	  lbitset_obstack_init = 1;
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
+	  obstack_specify_allocation (&lbitset_obstack, OBSTACK_CHUNK_SIZE,
+				      __alignof__ (lbitset_elt),
+				      (void *(*) PARAMS ((long))) OBSTACK_CHUNK_ALLOC,
+				      (void (*) PARAMS ((void *))) OBSTACK_CHUNK_FREE);
+	}
+
+      /* Perhaps we should add a number of new elements to the free
+         list.  */
+      elt = (lbitset_elt *) obstack_alloc (&lbitset_obstack,
+					   sizeof (lbitset_elt));
+    }
+
+  return elt;
+}
+
+
+/* Allocate a lbitset element.  The bits are not cleared.  */
+static inline lbitset_elt *
+lbitset_elt_calloc ()
+{
+  lbitset_elt *elt;
+
+  elt = lbitset_elt_alloc ();
+  memset (elt->words, 0, sizeof (elt->words));
+  return elt;
+}
+
+
+static inline void
+lbitset_elt_free (elt)
+     lbitset_elt *elt;
+{
+  elt->next = lbitset_free_list;
+  lbitset_free_list = elt;
+}
+
+
+/* Unlink element ELT from bitset BSET.  */
+static inline void
+lbitset_elt_unlink (bset, elt)
+     bitset bset;
+     lbitset_elt *elt;
+{
+  lbitset_elt *next = elt->next;
+  lbitset_elt *prev = elt->prev;
+
+  if (prev)
+    prev->next = next;
+
+  if (next)
+    next->prev = prev;
+
+  if (LBITSET_HEAD (bset) == elt)
+    LBITSET_HEAD (bset) = next;
+  if (LBITSET_TAIL (bset) == elt)
+    LBITSET_TAIL (bset) = prev;
+
+  /* Update cache pointer.  Since the first thing we try is to insert
+     before current, make current the next entry in preference to the
+     previous.  */
+  if (LBITSET_CURRENT (bset) == elt)
+    {
+      if (next)
+	{
+	  bset->cdata = next->words;
+	  bset->cindex = next->index;
+	}
+      else if (prev)
+	{
+	  bset->cdata = prev->words;
+	  bset->cindex = prev->index;
+	}
+      else
+	{
+	  bset->csize = 0;
+	  bset->cdata = 0;
+	}
+    }
+
+  lbitset_elt_free (elt);
+}
+
+
+/* Cut the chain of bitset BSET before element ELT and free the
+   elements.  */
+static inline void
+lbitset_prune (bset, elt)
+     bitset bset;
+     lbitset_elt *elt;
+{
+  lbitset_elt *next;
+
+  if (!elt)
+      return;
+
+  if (elt->prev)
+  {
+      LBITSET_TAIL (bset) = elt->prev;
+      bset->cdata = elt->prev->words;
+      bset->cindex = elt->prev->index;
+      elt->prev->next = 0;
+  }
+  else
+  {
+      LBITSET_HEAD (bset) = 0;
+      LBITSET_TAIL (bset) = 0;
+      bset->cdata = 0;
+      bset->csize = 0;
+  }
+
+  for (; elt; elt = next)
+    {
+      next = elt->next;
+      lbitset_elt_free (elt);
+    }
+}
+
+
+/* Return nonzero if all bits in an element are zero.  */
+static inline int
+lbitset_elt_zero_p (elt)
+     lbitset_elt *elt;
+{
+  int i;
+
+  for (i = 0; i < LBITSET_ELT_WORDS; i++)
+    if (elt->words[i])
+      return 0;
+
+  return 1;
+}
+
+
+/* Link the bitset element into the current bitset linked list.  */
+static inline void
+lbitset_elt_link (bset, elt)
+     bitset bset;
+     lbitset_elt *elt;
+{
+  bitset_windex index = elt->index;
+  lbitset_elt *ptr;
+  lbitset_elt *current;
+
+  if (bset->csize)
+      current = LBITSET_CURRENT (bset);
+  else
+      current = LBITSET_HEAD (bset);
+
+  /* If this is the first and only element, add it in.  */
+  if (LBITSET_HEAD (bset) == 0)
+    {
+      elt->next = elt->prev = 0;
+      LBITSET_HEAD (bset) = elt;
+      LBITSET_TAIL (bset) = elt;
+    }
+
+  /* If this index is less than that of the current element, it goes
+     somewhere before the current element.  */
+  else if (index < bset->cindex)
+    {
+      for (ptr = current;
+	   ptr->prev && ptr->prev->index > index;
+	   ptr = ptr->prev)
+	continue;
+
+      if (ptr->prev)
+	ptr->prev->next = elt;
+      else
+	LBITSET_HEAD (bset) = elt;
+
+      elt->prev = ptr->prev;
+      elt->next = ptr;
+      ptr->prev = elt;
+    }
+
+  /* Otherwise, it must go somewhere after the current element.  */
+  else
+    {
+      for (ptr = current;
+	   ptr->next && ptr->next->index < index;
+	   ptr = ptr->next)
+	continue;
+
+      if (ptr->next)
+	ptr->next->prev = elt;
+      else
+	LBITSET_TAIL (bset) = elt;
+
+      elt->next = ptr->next;
+      elt->prev = ptr;
+      ptr->next = elt;
+    }
+
+  /* Set up so this is the first element searched.  */
+  bset->cindex = index;
+  bset->csize = LBITSET_ELT_WORDS;
+  bset->cdata = elt->words;
+}
+
+
+static lbitset_elt *
+lbitset_elt_find (bset, index, mode)
+     bitset bset;
+     bitset_windex index;
+     enum lbitset_find_mode mode;
+{
+  lbitset_elt *elt;
+  lbitset_elt *current;
+
+  if (bset->csize)
+    {
+      current = LBITSET_CURRENT (bset);
+      /* Check if element is the cached element.  */
+      if ((index - bset->cindex) < bset->csize)
+	return current;
+    }
+  else
+    {
+      current = LBITSET_HEAD (bset);
+    }
+
+  if (current)
+    {
+      if (index < bset->cindex)
+	{
+	  for (elt = current;
+	       elt->prev && elt->index > index;
+	       elt = elt->prev)
+	    continue;
+	}
+      else
+	{
+	  for (elt = current;
+	       elt->next && (elt->index + LBITSET_ELT_WORDS - 1) < index;
+	       elt = elt->next)
+	    continue;
+	}
+
+      /* `element' is the nearest to the one we want.  If it's not the one
+	 we want, the one we want does not exist.  */
+      if (elt && (index - elt->index) < LBITSET_ELT_WORDS)
+	{
+	  bset->cindex = elt->index;
+          bset->csize = LBITSET_ELT_WORDS;
+	  bset->cdata = elt->words;
+	  return elt;
+	}
+    }
+
+  switch (mode)
+    {
+    case LBITSET_FIND:
+      return 0;
+
+    case LBITSET_CREATE:
+      index = (index / (unsigned) LBITSET_ELT_WORDS) * LBITSET_ELT_WORDS;
+
+      elt = lbitset_elt_calloc ();
+      elt->index = index;
+      lbitset_elt_link (bset, elt);
+      return elt;
+
+    case LBITSET_SUBST:
+      return &lbitset_zero_elts[0];
+
+    default:
+      abort ();
+    }
+}
+
+
+/* Weed out the zero elements from the list.  */
+static inline void
+lbitset_weed (bset)
+     bitset bset;
+{
+  lbitset_elt *elt;
+  lbitset_elt *next;
+
+  for (elt = LBITSET_HEAD (bset); elt; elt = next)
+    {
+      next = elt->next;
+      if (lbitset_elt_zero_p (elt))
+	lbitset_elt_unlink (bset, elt);
+    }
+}
+
+
+/* Set all bits in the bitset to zero.  */
+static inline void
+lbitset_zero (bset)
+     bitset bset;
+{
+  lbitset_elt *head;
+
+  head = LBITSET_HEAD (bset);
+  if (!head)
+    return;
+
+  /* Clear a bitset by freeing the linked list at the head element.  */
+  lbitset_prune (bset, head);
+}
+
+
+static inline int
+lbitset_equal_p (dst, src)
+     bitset dst;
+     bitset src;
+{
+  lbitset_elt *selt;
+  lbitset_elt *delt;
+  int j;
+
+  if (src == dst)
+    return 1;
+
+  lbitset_weed (src);
+  lbitset_weed (dst);
+  for (selt = LBITSET_HEAD (src), delt = LBITSET_HEAD (dst);
+       selt && delt; selt = selt->next, delt = delt->next)
+    {
+      if (selt->index != delt->index)
+	return 0;
+
+      for (j = 0; j < LBITSET_ELT_WORDS; j++)
+	if (delt->words[j] != selt->words[j])
+	  return 0;
+    }
+  return ! selt && ! delt;
+}
+
+
+/* Copy bits from bitset SRC to bitset DST.  */
+static inline void
+lbitset_copy (dst, src)
+     bitset dst;
+     bitset src;
+{
+  lbitset_elt *elt;
+  lbitset_elt *head;
+  lbitset_elt *prev;
+  lbitset_elt *tmp;
+
+  if (src == dst)
+    return;
+
+  lbitset_zero (dst);
+
+  head = LBITSET_HEAD (src);
+  if (!head)
+    return;
+
+  prev = 0;
+  for (elt = head; elt; elt = elt->next)
+    {
+      tmp = lbitset_elt_alloc ();
+      tmp->index = elt->index;
+      tmp->prev = prev;
+      tmp->next = 0;
+      if (prev)
+	prev->next = tmp;
+      else
+	LBITSET_HEAD (dst) = tmp;
+      prev = tmp;
+
+      memcpy (tmp->words, elt->words, sizeof (elt->words));
+    }
+  LBITSET_TAIL (dst) = tmp;
+
+  dst->csize = LBITSET_ELT_WORDS;
+  dst->cdata = LBITSET_HEAD (dst)->words;
+  dst->cindex = LBITSET_HEAD (dst)->index;
+}
+
+
+/* Copy bits from bitset SRC to bitset DST.  Return non-zero if
+   bitsets different.  */
+static inline int
+lbitset_copy_compare (dst, src)
+     bitset dst;
+     bitset src;
+{
+  if (src == dst)
+    return 0;
+
+  if (! LBITSET_HEAD (dst))
+    {
+      lbitset_copy (dst, src);
+      return LBITSET_HEAD (src) != 0;
+    }
+
+  if (lbitset_equal_p (dst, src))
+    return 0;
+
+  lbitset_copy (dst, src);
+  return 1;
+}
+
+
+/* Return size in bits of bitset SRC.  */
+static int
+lbitset_size (src)
+     bitset src;
+{
+  lbitset_elt *elt;
+
+  elt = LBITSET_TAIL (src);
+  if (!elt)
+	return 0;
+
+  /* Return current size of bitset in bits.  */
+  return (elt->index + LBITSET_ELT_WORDS) * BITSET_WORD_BITS;
+}
+
+
+/* Set bit BITNO in bitset DST.  */
+static void
+lbitset_set (dst, bitno)
+     bitset dst;
+     bitset_bindex bitno;
+{
+  bitset_windex index = bitno / BITSET_WORD_BITS;
+
+  lbitset_elt_find (dst, index, LBITSET_CREATE);
+
+  dst->cdata[index - dst->cindex] |= (1 << (bitno % BITSET_WORD_BITS));
+}
+
+
+/* Reset bit BITNO in bitset DST.  */
+static void
+lbitset_reset (dst, bitno)
+     bitset dst;
+     bitset_bindex bitno;
+{
+  bitset_windex index = bitno / BITSET_WORD_BITS;
+
+  if (!lbitset_elt_find (dst, index, LBITSET_FIND))
+      return;
+
+  dst->cdata[index - dst->cindex] &= ~(1 << (bitno % BITSET_WORD_BITS));
+
+  /* If all the data is zero, perhaps we should unlink it now...  */
+}
+
+
+/* Test bit BITNO in bitset SRC.  */
+static int
+lbitset_test (src, bitno)
+     bitset src;
+     bitset_bindex bitno;
+{
+  bitset_windex index = bitno / BITSET_WORD_BITS;
+
+  if (!lbitset_elt_find (src, index, LBITSET_FIND))
+    return 0;
+
+  return (src->cdata[index - src->cindex] >> (bitno % BITSET_WORD_BITS)) & 1;
+}
+
+
+static void
+lbitset_free (bset)
+     bitset bset;
+{
+  lbitset_zero (bset);
+}
+
+
+/* Find list of up to NUM bits set in BSET starting from and including
+   *NEXT and store in array LIST.  Return with actual number of bits
+   found and with *NEXT indicating where search stopped.  */
+static int
+lbitset_reverse_list (bset, list, num, next)
+     bitset bset;
+     bitset_bindex *list;
+     bitset_bindex num;
+     bitset_bindex *next;
+{
+  bitset_bindex rbitno;
+  bitset_bindex bitno;
+  unsigned int bitcnt;
+  bitset_bindex bitoff;
+  bitset_windex index;
+  bitset_bindex count;
+  lbitset_elt *elt;
+  bitset_word word;
+  bitset_bindex n_bits;
+
+  elt = LBITSET_TAIL (bset);
+  if (!elt)
+    return 0;
+
+  n_bits = (elt->index + LBITSET_ELT_WORDS) * BITSET_WORD_BITS;
+  rbitno = *next;
+
+  if (rbitno >= n_bits)
+      return 0;
+
+  bitno = n_bits - (rbitno + 1);
+
+  index = bitno / BITSET_WORD_BITS;
+
+  /* Skip back to starting element.  */
+  for (; elt && elt->index > index; elt = elt->prev)
+    continue;
+
+  if (!elt)
+    return 0;
+
+  /* If num is 1, we could speed things up with a binary search
+     of the word of interest.  */
+
+  count = 0;
+  bitcnt = bitno % BITSET_WORD_BITS;
+  bitoff = index * BITSET_WORD_BITS;
+
+  while (elt)
+    {
+      bitset_word *srcp = elt->words;
+
+      for (; (index - elt->index) < LBITSET_ELT_WORDS;
+	   index--, bitoff -= BITSET_WORD_BITS,
+	       bitcnt = BITSET_WORD_BITS - 1)
+	{
+	  word = srcp[index - elt->index] << (BITSET_WORD_BITS - 1 - bitcnt);
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
+      elt = elt->prev;
+      if (elt)
+	{
+	  index = elt->index + LBITSET_ELT_WORDS - 1;
+	  bitoff = index * BITSET_WORD_BITS;
+	}
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
+lbitset_list (bset, list, num, next)
+     bitset bset;
+     bitset_bindex *list;
+     bitset_bindex num;
+     bitset_bindex *next;
+{
+  bitset_bindex bitno;
+  bitset_windex index;
+  bitset_bindex count;
+  lbitset_elt *elt;
+  lbitset_elt *head;
+  bitset_word word;
+
+  head = LBITSET_HEAD (bset);
+  if (!head)
+      return 0;
+
+  bitno = *next;
+  count = 0;
+
+  if (!bitno)
+    {
+      /* This is the most common case.  */
+
+      /* Start with the first element.  */
+      elt = head;
+      index = elt->index;
+      bitno = index * BITSET_WORD_BITS;
+    }
+  else
+    {
+      index = bitno / BITSET_WORD_BITS;
+
+      /* Skip to starting element.  */
+      for (elt = head;
+	   elt && (elt->index + LBITSET_ELT_WORDS - 1) < index;
+	   elt = elt->next)
+	continue;
+
+      if (!elt)
+	return 0;
+
+      if (index < elt->index)
+	{
+	  index = elt->index;
+	  bitno = index * BITSET_WORD_BITS;
+	}
+      else
+	{
+	  bitset_word *srcp = elt->words;
+
+	  /* We are starting within an element.  */
+
+	  for (; (index - elt->index) < LBITSET_ELT_WORDS; index++)
+	    {
+	      word = srcp[index - elt->index] >> (bitno % BITSET_WORD_BITS);
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
+
+	  elt = elt->next;
+	  if (elt)
+	    {
+	      index = elt->index;
+	      bitno = index * BITSET_WORD_BITS;
+	    }
+	}
+    }
+
+
+  /* If num is 1, we could speed things up with a binary search
+     of the word of interest.  */
+
+  while (elt)
+    {
+      int i;
+      bitset_word *srcp = elt->words;
+
+      if ((count + LBITSET_ELT_BITS) < num)
+	{
+	  /* The coast is clear, plant boot!  */
+
+#if LBITSET_ELT_WORDS == 2
+	  word = srcp[0];
+	  if (word)
+	    {
+	      if (! (word & 0xffff))
+		{
+		  word >>= 16;
+		  bitno += 16;
+		}
+	      if (! (word & 0xff))
+		{
+		  word >>= 8;
+		  bitno += 8;
+		}
+	      for (; word; bitno++)
+		{
+		  if (word & 1)
+		    list[count++] = bitno;
+		  word >>= 1;
+		}
+	    }
+	  index++;
+	  bitno = index * BITSET_WORD_BITS;
+
+	  word = srcp[1];
+	  if (word)
+	    {
+	      if (! (word & 0xffff))
+		{
+		  word >>= 16;
+		  bitno += 16;
+		}
+	      for (; word; bitno++)
+		{
+		  if (word & 1)
+		    list[count++] = bitno;
+		  word >>= 1;
+		}
+	    }
+	  index++;
+	  bitno = index * BITSET_WORD_BITS;
+#else
+	  for (i = 0; i < LBITSET_ELT_WORDS; i++)
+	    {
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
+	      index++;
+	      bitno = index * BITSET_WORD_BITS;
+	    }
+#endif
+	}
+      else
+	{
+	  /* Tread more carefully since we need to check
+	     if array overflows.  */
+
+	  for (i = 0; i < LBITSET_ELT_WORDS; i++)
+	    {
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
+	      index++;
+	      bitno = index * BITSET_WORD_BITS;
+	    }
+	}
+
+      elt = elt->next;
+      if (elt)
+	{
+	  index = elt->index;
+	  bitno = index * BITSET_WORD_BITS;
+	}
+    }
+
+  *next = bitno;
+  return count;
+}
+
+
+static int
+lbitset_op1 (dst, op)
+     bitset dst;
+     enum bitset_ops op;
+{
+  unsigned int i;
+  bitset_windex index;
+  lbitset_elt *elt;
+
+  switch (op)
+    {
+    case BITSET_ZERO:
+      lbitset_zero (dst);
+      break;
+
+    case BITSET_ONES:
+      /* This is a decidedly unfriendly operation for a linked list
+	 bitset!   */
+      elt = LBITSET_TAIL (dst);
+      /* Ignore empty set.  */
+      if (!elt)
+	return 0;
+
+      index = elt->index;
+      for (i = 0; i < index; i += LBITSET_ELT_WORDS)
+	{
+	  /* Create new elements if they cannot be found.  */
+	  elt = lbitset_elt_find (dst, i, LBITSET_CREATE);
+	  memset (elt->words, ~0, sizeof (elt->words));
+	}
+      break;
+
+    case BITSET_EMPTY_P:
+      lbitset_weed (dst);
+      if (LBITSET_HEAD (dst))
+	return 0;
+      break;
+
+    default:
+      abort ();
+    }
+
+  return 1;
+}
+
+
+static int
+lbitset_op2 (dst, src, op)
+     bitset dst;
+     bitset src;
+     enum bitset_ops op;
+{
+  lbitset_elt *elt;
+  lbitset_elt *selt;
+  lbitset_elt *delt;
+  unsigned int i;
+  unsigned int j;
+  bitset_windex index;
+
+  switch (op)
+    {
+    case BITSET_COPY:
+      lbitset_copy (dst, src);
+      break;
+
+    case BITSET_NOT:
+      /* This is another unfriendly operation for a linked list
+	 bitset!  */
+      elt = LBITSET_TAIL (dst);
+      /* Ignore empty set.  */
+      if (!elt)
+	return 0;
+
+      index = elt->index;
+      for (i = 0; i < index; i += LBITSET_ELT_WORDS)
+	{
+	  /* Create new elements for dst if they cannot be found
+	     or substitute zero elements if src elements not found.  */
+	  selt = lbitset_elt_find (dst, i, LBITSET_SUBST);
+	  delt = lbitset_elt_find (dst, i, LBITSET_CREATE);
+
+	  for (j = 0; j < LBITSET_ELT_WORDS; j++)
+	    delt->words[j] = ~selt->words[j];
+	}
+      lbitset_weed (dst);
+      break;
+
+    case BITSET_EQUAL_P:
+      return lbitset_equal_p (dst, src);
+      break;
+
+    case BITSET_SUBSET_P:
+      for (selt = LBITSET_HEAD (src), delt = LBITSET_HEAD (dst);
+	   selt || delt; selt = selt->next, delt = delt->next)
+	{
+	  if (!selt)
+	    selt = &lbitset_zero_elts[0];
+	  else if (!delt)
+	    delt = &lbitset_zero_elts[0];
+	  else if (selt->index != delt->index)
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
+	    if (delt->words[j] != (selt->words[j] | delt->words[j]))
+	      return 0;
+	}
+      break;
+
+    default:
+      abort ();
+    }
+
+  return 1;
+}
+
+
+static int
+lbitset_op3 (dst, src1, src2, op)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     enum bitset_ops op;
+{
+  lbitset_elt *selt1 = LBITSET_HEAD (src1);
+  lbitset_elt *selt2 = LBITSET_HEAD (src2);
+  lbitset_elt *delt = LBITSET_HEAD (dst);
+  bitset_windex index1;
+  bitset_windex index2;
+  bitset_windex index;
+  lbitset_elt *stmp1;
+  lbitset_elt *stmp2;
+  lbitset_elt *dtmp;
+  bitset_word *srcp1;
+  bitset_word *srcp2;
+  bitset_word *dstp;
+  int changed = 0;
+  unsigned int i;
+
+  /* Fast track common, simple cases.  */
+  if (!selt2)
+    {
+      if (op == BITSET_AND)
+	{
+	  lbitset_weed (dst);
+	  changed = ! LBITSET_HEAD (dst);
+	  lbitset_zero (dst);
+	  return changed;
+	}
+      else if (op == BITSET_ANDN || op == BITSET_OR || op == BITSET_XOR)
+	{
+	  return lbitset_copy_compare (dst, src1);
+	}
+    }
+  else if (!selt1)
+    {
+      if (op == BITSET_AND || op == BITSET_ANDN)
+	{
+	  lbitset_weed (dst);
+	  changed = ! LBITSET_HEAD (dst);
+	  lbitset_zero (dst);
+	  return changed;
+	}
+      else if (op == BITSET_OR || op == BITSET_XOR)
+	{
+	  return lbitset_copy_compare (dst, src2);
+	}
+    }
+
+
+  LBITSET_HEAD (dst) = 0;
+  dst->csize = 0;
+
+  index1 = (selt1) ? selt1->index : BITSET_INDEX_MAX;
+  index2 = (selt2) ? selt2->index : BITSET_INDEX_MAX;
+
+  while (selt1 || selt2)
+    {
+      /* Figure out whether we need to substitute zero elements for
+	 missing links.  */
+      if (index1 == index2)
+	{
+	  index = index1;
+	  stmp1 = selt1;
+	  stmp2 = selt2;
+	  selt1 = selt1->next;
+	  index1 = (selt1) ? selt1->index : BITSET_INDEX_MAX;
+	  selt2 = selt2->next;
+	  index2 = (selt2) ? selt2->index : BITSET_INDEX_MAX;
+	}
+      else if (index1 < index2)
+	{
+	  index = index1;
+	  stmp1 = selt1;
+	  stmp2 = &lbitset_zero_elts[0];
+	  selt1 = selt1->next;
+	  index1 = (selt1) ? selt1->index : BITSET_INDEX_MAX;
+	}
+      else
+	{
+	  index = index2;
+	  stmp1 = &lbitset_zero_elts[0];
+	  stmp2 = selt2;
+	  selt2 = selt2->next;
+	  index2 = (selt2) ? selt2->index : BITSET_INDEX_MAX;
+	}
+
+      /* Find the appropriate element from DST.  Begin by discarding
+	 elements that we've skipped.  */
+      while (delt && delt->index < index)
+	{
+	  changed = 1;
+	  dtmp = delt;
+	  delt = delt->next;
+	  lbitset_elt_free (dtmp);
+	}
+      if (delt && delt->index == index)
+	{
+	  dtmp = delt;
+	  delt = delt->next;
+	}
+      else
+	dtmp = lbitset_elt_calloc ();
+
+      /* Do the operation, and if any bits are set, link it into the
+	 linked list.  */
+      srcp1 = stmp1->words;
+      srcp2 = stmp2->words;
+      dstp = dtmp->words;
+      switch (op)
+	{
+	case BITSET_OR:
+	  for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
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
+	  for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
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
+	  for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
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
+	  for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
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
+	  for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
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
+      if (! lbitset_elt_zero_p (dtmp))
+	{
+	  dtmp->index = index;
+	  /* Perhaps this could be optimised...  */
+	  lbitset_elt_link (dst, dtmp);
+	}
+      else
+	{
+	  lbitset_elt_free (dtmp);
+	}
+    }
+
+  /* If we have elements of DST left over, free them all.  */
+  if (delt)
+    {
+      changed = 1;
+      lbitset_prune (dst, delt);
+    }
+
+  return changed;
+}
+
+
+static int
+lbitset_op4 (dst, src1, src2, src3, op)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+     enum bitset_ops op;
+{
+  int changed = 0;
+  bitset tmp;
+
+#ifdef ENABLE_CHECKING
+  /* Check for compatiblity.  */
+  if (src1->ops != dst->ops || src2->ops != dst->ops || src3->ops != dst->ops)
+    abort ();
+#endif
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
+  return changed;
+}
+
+
+/* Vector of operations for linked-list bitsets.  */
+struct bitset_ops_struct lbitset_ops =
+  {
+    lbitset_set,
+    lbitset_reset,
+    lbitset_test,
+    lbitset_size,
+    lbitset_op1,
+    lbitset_op2,
+    lbitset_op3,
+    lbitset_op4,
+    lbitset_list,
+    lbitset_reverse_list,
+    lbitset_free,
+    BITSET_LIST
+  };
+
+
+/* Return size of initial structure.  */
+int
+lbitset_bytes (n_bits)
+     bitset_bindex n_bits ATTRIBUTE_UNUSED;
+{
+  return sizeof (struct bitset_struct);
+}
+
+
+/* Initialize a bitset.  */
+
+bitset
+lbitset_init (bset, n_bits)
+     bitset bset;
+     bitset_bindex n_bits ATTRIBUTE_UNUSED;
+{
+  LBITSET_HEAD (bset) = 0;
+  LBITSET_TAIL (bset) = 0;
+
+  bset->ops = &lbitset_ops;
+
+  bset->cindex = 0;
+  /* Disable cache until have some elements allocated.
+     If we have variable length arrays, then we may
+     need to allocate dummy element.  */
+  bset->csize = 0;
+  bset->cdata = 0;
+  return bset;
+}
+
+
+void
+lbitset_release_memory ()
+{
+  lbitset_free_list = 0;
+  if (lbitset_obstack_init)
+    {
+      lbitset_obstack_init = 0;
+      obstack_free (&lbitset_obstack, NULL);
+    }
+}
