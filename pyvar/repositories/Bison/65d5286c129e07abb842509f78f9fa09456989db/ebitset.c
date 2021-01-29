@@ -24,6 +24,7 @@
 #include "ebitset.h"
 #include "obstack.h"
 #include <stdlib.h>
+#include <string.h>
 
 /* This file implements expandable bitsets.  These bitsets can be of
    arbitrary length and are more efficient than arrays of bits for
@@ -75,11 +76,6 @@ typedef ebitset_elt *ebitset_elts;
 #define EBITSET_INITIAL_SIZE 2
 #endif
 
-/* Minimum number of elements to grow table.  */
-
-#ifndef EBITSET_GROW_SIZE
-#define EBITSET_GROW_SIZE 4
-#endif
 
 enum ebitset_find_mode
   { EBITSET_FIND, EBITSET_CREATE, EBITSET_SUBST };
@@ -91,8 +87,10 @@ static struct obstack ebitset_obstack;
 static bool ebitset_obstack_init = false;
 static ebitset_elt *ebitset_free_list;	/* Free list of bitset elements.  */
 
+#define EBITSET_N_ELTS(N) (((N) + EBITSET_ELT_BITS - 1) / EBITSET_ELT_BITS)
 #define EBITSET_ELTS(BSET) ((BSET)->e.elts)
-#define EBITSET_SIZE(BSET) ((BSET)->e.size)
+#define EBITSET_SIZE(BSET) EBITSET_N_ELTS (BITSET_NBITS_ (BSET))
+#define EBITSET_ASIZE(BSET) ((BSET)->e.size)
 
 #define EBITSET_NEXT(ELT) ((ELT)->u.next)
 #define EBITSET_WORDS(ELT) ((ELT)->u.words)
@@ -118,24 +116,66 @@ static ebitset_elt *ebitset_free_list;	/* Free list of bitset elements.  */
   (BSET)->b.cdata = EBITSET_WORDS (EBITSET_ELTS (BSET) [EINDEX]))
 
 
-/* Grow the expandable table for BSET by SIZE elements.  */
-static void
-ebitset_elts_grow (bitset bset, bitset_windex size)
+#define min(a, b) ((a) > (b) ? (b) : (a))
+#define max(a, b) ((a) > (b) ? (a) : (b))
+
+
+static bitset_bindex
+ebitset_resize (src, n_bits)
+     bitset src;
+     bitset_bindex n_bits;
 {
   bitset_windex oldsize;
   bitset_windex newsize;
 
-  oldsize = EBITSET_SIZE (bset);
-  newsize = oldsize + size;
+  if (n_bits == BITSET_NBITS_ (src))
+    return n_bits;
+
+  oldsize = EBITSET_SIZE (src);
+  newsize = EBITSET_N_ELTS (n_bits);
+
+  if (oldsize < newsize)
+    {
+      bitset_windex size;
+
+      /* The bitset needs to grow.  If we already have enough memory 
+	 allocated, then just zero what we need.  */
+      if (newsize > EBITSET_ASIZE (src))
+	{
+	  /* We need to allocate more memory.  When oldsize is
+	     non-zero this means that we are changing the size, so
+	     grow the bitset 25% larger than requested to reduce
+	     number of reallocations.  */
+
+	  if (oldsize == 0)
+	    size = newsize;
+	  else
+	    size = newsize + newsize / 4;
+	  
+	  EBITSET_ELTS (src)
+	    = realloc (EBITSET_ELTS (src), size * sizeof (ebitset_elt *));
+	  EBITSET_ASIZE (src) = size;
+	}
 
-  if (BITSET_SIZE_MAX / sizeof (ebitset_elt *) < newsize)
-    xalloc_die ();
+      memset (EBITSET_ELTS (src) + oldsize, 0, 
+	      (newsize - oldsize) * sizeof (ebitset_elt *));
+    }
+  else
+    {
+      /* The bitset needs to shrink.  There's no point deallocating
+	 the memory unless it is shrinking by a reasonable amount.  */
+      if ((oldsize - newsize) >= oldsize / 2)
+	{
+	  EBITSET_ELTS (src)
+	    = realloc (EBITSET_ELTS (src), newsize * sizeof (ebitset_elt *));
+	  EBITSET_ASIZE (src) = newsize;
+	}
 
-  EBITSET_ELTS (bset) = xrealloc (EBITSET_ELTS (bset),
-				  newsize * sizeof (ebitset_elt *));
-  EBITSET_SIZE (bset) = newsize;
+      /* Need to prune any excess bits.  FIXME.  */
+    }
 
-  memset (EBITSET_ELTS (bset) + oldsize, 0, size * sizeof (ebitset_elt *));
+  BITSET_NBITS_ (src) = n_bits;
+  return n_bits;
 }
 
 
@@ -257,7 +297,7 @@ ebitset_elt_zero_p (ebitset_elt *elt)
 
 
 static ebitset_elt *
-ebitset_elt_find (bitset bset, bitset_windex windex,
+ebitset_elt_find (bitset bset, bitset_bindex bindex,
 		  enum ebitset_find_mode mode)
 {
   ebitset_elt *elt;
@@ -265,7 +305,7 @@ ebitset_elt_find (bitset bset, bitset_windex windex,
   bitset_windex eindex;
   ebitset_elts *elts;
 
-  eindex = windex / EBITSET_ELT_WORDS;
+  eindex = bindex / EBITSET_ELT_BITS;
 
   elts = EBITSET_ELTS (bset);
   size = EBITSET_SIZE (bset);
@@ -291,21 +331,7 @@ ebitset_elt_find (bitset bset, bitset_windex windex,
 
     case EBITSET_CREATE:
       if (eindex >= size)
-	{
-	  bitset_windex extra;
-
-	  extra = eindex - size + 1;
-
-	  /* We need to expand the table by EXTRA elements.  It may be
-	     better with large bitsets to grow the number of
-	     elements by some fraction of the current size otherwise
-	     we can spend a lot of time slowly increasing the size of the
-	     bitset.  */
-	  if (extra < EBITSET_GROW_SIZE)
-	    extra = EBITSET_GROW_SIZE;
-
-	  ebitset_elts_grow (bset, extra);
-	}
+	ebitset_resize (bset, bindex);
 
       /* Create a new element.  */
       elt = ebitset_elt_calloc ();
@@ -322,18 +348,6 @@ ebitset_elt_find (bitset bset, bitset_windex windex,
 }
 
 
-static inline ebitset_elt *
-ebitset_elt_last (bitset bset)
-{
-  ebitset_elts *elts;
-
-  elts = EBITSET_ELTS (bset);
-
-  /* Assume that have at least one element in elts.  */
-  return elts[EBITSET_SIZE (bset) - 1];
-}
-
-
 /* Weed out the zero elements from the elts.  */
 static inline bitset_windex
 ebitset_weed (bitset bset)
@@ -353,7 +367,7 @@ ebitset_weed (bitset bset)
 
       if (elt)
 	{
-	  if (elt && ebitset_elt_zero_p (elt))
+	  if (ebitset_elt_zero_p (elt))
 	    {
 	      ebitset_elt_remove (bset, j);
 	      count++;
@@ -453,8 +467,8 @@ ebitset_copy_ (bitset dst, bitset src)
 
   ebitset_zero (dst);
 
-  if (EBITSET_SIZE (dst) < EBITSET_SIZE (src))
-    ebitset_elts_grow (dst, EBITSET_SIZE (src) - EBITSET_SIZE (dst));
+  if (BITSET_NBITS_ (dst) != BITSET_NBITS_ (src))
+    ebitset_resize (dst, BITSET_NBITS_ (src));
 
   selts = EBITSET_ELTS (src);
   delts = EBITSET_ELTS (dst);
@@ -498,22 +512,13 @@ ebitset_copy_cmp (bitset dst, bitset src)
 }
 
 
-/* Return size in bits of bitset SRC.  */
-static bitset_bindex
-ebitset_size (bitset src)
-{
-  /* Return current size of bitset in bits.  */
-  return EBITSET_SIZE (src) * EBITSET_ELT_BITS;
-}
-
-
 /* Set bit BITNO in bitset DST.  */
 static void
 ebitset_set (bitset dst, bitset_bindex bitno)
 {
   bitset_windex windex = bitno / BITSET_WORD_BITS;
 
-  ebitset_elt_find (dst, windex, EBITSET_CREATE);
+  ebitset_elt_find (dst, bitno, EBITSET_CREATE);
 
   dst->b.cdata[windex - dst->b.cindex] |=
     (bitset_word) 1 << (bitno % BITSET_WORD_BITS);
@@ -526,7 +531,7 @@ ebitset_reset (bitset dst, bitset_bindex bitno)
 {
   bitset_windex windex = bitno / BITSET_WORD_BITS;
 
-  if (!ebitset_elt_find (dst, windex, EBITSET_FIND))
+  if (!ebitset_elt_find (dst, bitno, EBITSET_FIND))
     return;
 
   dst->b.cdata[windex - dst->b.cindex] &=
@@ -544,7 +549,7 @@ ebitset_test (bitset src, bitset_bindex bitno)
 {
   bitset_windex windex = bitno / BITSET_WORD_BITS;
 
-  return (ebitset_elt_find (src, windex, EBITSET_FIND)
+  return (ebitset_elt_find (src, bitno, EBITSET_FIND)
 	  && ((src->b.cdata[windex - src->b.cindex]
 	       >> (bitno % BITSET_WORD_BITS))
 	      & 1));
@@ -731,6 +736,48 @@ ebitset_list (bitset bset, bitset_bindex *list,
 	{
 	  /* The coast is clear, plant boot!  */
 
+#if EBITSET_ELT_WORDS == 2
+	  word = srcp[0];
+	  if (word)
+	    {
+	      if (!(word & 0xffff))
+		{
+		  word >>= 16;
+		  bitno += 16;
+		}
+	      if (!(word & 0xff))
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
+	  windex++;
+	  bitno = windex * BITSET_WORD_BITS;
+
+	  word = srcp[1];
+	  if (word)
+	    {
+	      if (!(word & 0xffff))
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
+	  windex++;
+	  bitno = windex * BITSET_WORD_BITS;
+#else
 	  for (i = 0; i < EBITSET_ELT_WORDS; i++, windex++)
 	    {
 	      bitno = windex * BITSET_WORD_BITS;
@@ -756,6 +803,7 @@ ebitset_list (bitset bset, bitset_bindex *list,
 		    }
 		}
 	    }
+#endif
 	}
       else
 	{
@@ -788,29 +836,92 @@ ebitset_list (bitset bset, bitset_bindex *list,
 }
 
 
+/* Ensure that any unused bits within the last element are clear.  */
+static inline void
+ebitset_unused_clear (dst)
+     bitset dst;
+{
+  unsigned int last_bit;
+  bitset_bindex n_bits;
+  
+  n_bits = BITSET_NBITS_ (dst);
+  last_bit = n_bits % EBITSET_ELT_BITS;
+  
+  if (last_bit)
+    {
+      bitset_windex eindex;
+      ebitset_elts *elts;
+      ebitset_elt *elt;
+
+      elts = EBITSET_ELTS (dst);
+      
+      eindex = n_bits / EBITSET_ELT_BITS;
+      
+      elt = elts[eindex];
+      if (elt)
+	{
+	  bitset_windex windex;
+	  bitset_windex woffset;
+	  bitset_word *srcp = EBITSET_WORDS (elt);
+	  
+	  windex = n_bits / BITSET_WORD_BITS;
+	  woffset = eindex * EBITSET_ELT_WORDS;
+	  
+	  srcp[windex - woffset] &= ((bitset_word) 1 << last_bit) - 1;	  
+	  windex++;
+	  for (; (windex - woffset) < EBITSET_ELT_WORDS; windex++)
+	    srcp[windex - woffset] = 0;
+	}
+    }
+}
+
+
 static void
 ebitset_ones (bitset dst)
 {
   bitset_windex j;
   ebitset_elt *elt;
 
-
   for (j = 0; j < EBITSET_SIZE (dst); j++)
     {
       /* Create new elements if they cannot be found.  Perhaps
-	 we should just add pointers to a ones element.  */
+	 we should just add pointers to a ones element?  */
       elt =
-	ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_CREATE);
+	ebitset_elt_find (dst, j * EBITSET_ELT_BITS, EBITSET_CREATE);
       memset (EBITSET_WORDS (elt), -1, sizeof (EBITSET_WORDS (elt)));
     }
   EBITSET_NONZERO_SET (dst);
+  ebitset_unused_clear (dst);
 }
 
 
 static bool
 ebitset_empty_p (bitset dst)
 {
-  return !ebitset_weed (dst);
+  ebitset_elts *elts;
+  bitset_windex j;
+
+  if (EBITSET_ZERO_P (dst))
+    return 1;
+
+  elts = EBITSET_ELTS (dst);
+  for (j = 0; j < EBITSET_SIZE (dst); j++)
+    {
+      ebitset_elt *elt = elts[j];
+
+      if (elt)
+	{
+	  if (!ebitset_elt_zero_p (elt))
+	    return 0;
+	  /* Do some weeding as we go.  */
+	  ebitset_elt_remove (dst, j);
+	}
+    }
+
+  /* All the bits are zero.  We could shrink the elts.
+     For now just mark DST as known to be zero.  */
+  EBITSET_ZERO_SET (dst);
+  return 1;
 }
 
 
@@ -822,19 +933,22 @@ ebitset_not (bitset dst, bitset src)
   ebitset_elt *delt;
   bitset_windex j;
 
+  ebitset_resize (dst, BITSET_NBITS_ (src));
+
   for (j = 0; j < EBITSET_SIZE (src); j++)
     {
       /* Create new elements for dst if they cannot be found
-	     or substitute zero elements if src elements not found.  */
+	 or substitute zero elements if src elements not found.  */
       selt =
-	ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_SUBST);
+	ebitset_elt_find (dst, j * EBITSET_ELT_BITS, EBITSET_SUBST);
       delt =
-	ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_CREATE);
+	ebitset_elt_find (dst, j * EBITSET_ELT_BITS, EBITSET_CREATE);
 
       for (i = 0; i < EBITSET_ELT_WORDS; i++)
 	EBITSET_WORDS (delt)[i] = ~EBITSET_WORDS (selt)[i];
     }
   EBITSET_NONZERO_SET (dst);
+  ebitset_unused_clear (dst);
 }
 
 
@@ -934,6 +1048,8 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
   unsigned int i;
   bitset_windex j;
 
+  ebitset_resize (dst, max (BITSET_NBITS_ (src1), BITSET_NBITS_ (src2)));
+
   ssize1 = EBITSET_SIZE (src1);
   ssize2 = EBITSET_SIZE (src2);
   dsize = EBITSET_SIZE (dst);
@@ -941,9 +1057,6 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
   if (size < ssize2)
     size = ssize2;
 
-  if (size > dsize)
-    ebitset_elts_grow (dst, size - dsize);
-
   selts1 = EBITSET_ELTS (src1);
   selts2 = EBITSET_ELTS (src2);
   delts = EBITSET_ELTS (dst);
@@ -1183,7 +1296,8 @@ struct bitset_vtable ebitset_vtable = {
   ebitset_reset,
   bitset_toggle_,
   ebitset_test,
-  ebitset_size,
+  ebitset_resize,
+  bitset_size_,
   bitset_count_,
   ebitset_empty_p,
   ebitset_ones,
@@ -1238,9 +1352,9 @@ ebitset_init (bitset bset, bitset_bindex n_bits)
   size = n_bits ? (n_bits + EBITSET_ELT_BITS - 1) / EBITSET_ELT_BITS
     : EBITSET_INITIAL_SIZE;
 
-  EBITSET_SIZE (bset) = 0;
+  EBITSET_ASIZE (bset) = 0;
   EBITSET_ELTS (bset) = 0;
-  ebitset_elts_grow (bset, size);
+  ebitset_resize (bset, n_bits);
 
   return bset;
 }
