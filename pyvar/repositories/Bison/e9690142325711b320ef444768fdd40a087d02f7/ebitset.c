@@ -58,7 +58,7 @@ typedef struct ebitset_elt_struct
 {
   union
   {
-    bitset_word words[EBITSET_ELT_WORDS];	/* Bits that are set.  */
+    bitset_word words[EBITSET_ELT_WORDS];       /* Bits that are set.  */
     struct ebitset_elt_struct *next;
   }
   u;
@@ -84,7 +84,7 @@ static ebitset_elt ebitset_zero_elts[1]; /* Elements of all zero bits.  */
 /* Obstack to allocate bitset elements from.  */
 static struct obstack ebitset_obstack;
 static bool ebitset_obstack_init = false;
-static ebitset_elt *ebitset_free_list;	/* Free list of bitset elements.  */
+static ebitset_elt *ebitset_free_list;  /* Free list of bitset elements.  */
 
 #define EBITSET_N_ELTS(N) (((N) + EBITSET_ELT_BITS - 1) / EBITSET_ELT_BITS)
 #define EBITSET_ELTS(BSET) ((BSET)->e.elts)
@@ -96,7 +96,7 @@ static ebitset_elt *ebitset_free_list;	/* Free list of bitset elements.  */
 
 /* Disable bitset cache and mark BSET as being zero.  */
 #define EBITSET_ZERO_SET(BSET) ((BSET)->b.cindex = BITSET_WINDEX_MAX, \
-	(BSET)->b.cdata = 0)
+        (BSET)->b.cdata = 0)
 
 #define EBITSET_CACHE_DISABLE(BSET)  ((BSET)->b.cindex = BITSET_WINDEX_MAX)
 
@@ -136,37 +136,37 @@ ebitset_resize (bitset src, bitset_bindex n_bits)
       bitset_windex size;
 
       /* The bitset needs to grow.  If we already have enough memory
-	 allocated, then just zero what we need.  */
+         allocated, then just zero what we need.  */
       if (newsize > EBITSET_ASIZE (src))
-	{
-	  /* We need to allocate more memory.  When oldsize is
-	     non-zero this means that we are changing the size, so
-	     grow the bitset 25% larger than requested to reduce
-	     number of reallocations.  */
-
-	  if (oldsize == 0)
-	    size = newsize;
-	  else
-	    size = newsize + newsize / 4;
-
-	  EBITSET_ELTS (src)
-	    = realloc (EBITSET_ELTS (src), size * sizeof (ebitset_elt *));
-	  EBITSET_ASIZE (src) = size;
-	}
+        {
+          /* We need to allocate more memory.  When oldsize is
+             non-zero this means that we are changing the size, so
+             grow the bitset 25% larger than requested to reduce
+             number of reallocations.  */
+
+          if (oldsize == 0)
+            size = newsize;
+          else
+            size = newsize + newsize / 4;
+
+          EBITSET_ELTS (src)
+            = realloc (EBITSET_ELTS (src), size * sizeof (ebitset_elt *));
+          EBITSET_ASIZE (src) = size;
+        }
 
       memset (EBITSET_ELTS (src) + oldsize, 0,
-	      (newsize - oldsize) * sizeof (ebitset_elt *));
+              (newsize - oldsize) * sizeof (ebitset_elt *));
     }
   else
     {
       /* The bitset needs to shrink.  There's no point deallocating
-	 the memory unless it is shrinking by a reasonable amount.  */
+         the memory unless it is shrinking by a reasonable amount.  */
       if ((oldsize - newsize) >= oldsize / 2)
-	{
-	  EBITSET_ELTS (src)
-	    = realloc (EBITSET_ELTS (src), newsize * sizeof (ebitset_elt *));
-	  EBITSET_ASIZE (src) = newsize;
-	}
+        {
+          EBITSET_ELTS (src)
+            = realloc (EBITSET_ELTS (src), newsize * sizeof (ebitset_elt *));
+          EBITSET_ASIZE (src) = newsize;
+        }
 
       /* Need to prune any excess bits.  FIXME.  */
     }
@@ -190,16 +190,16 @@ ebitset_elt_alloc (void)
   else
     {
       if (!ebitset_obstack_init)
-	{
-	  ebitset_obstack_init = true;
+        {
+          ebitset_obstack_init = true;
 
-	  /* Let particular systems override the size of a chunk.  */
+          /* Let particular systems override the size of a chunk.  */
 
 #ifndef OBSTACK_CHUNK_SIZE
 #define OBSTACK_CHUNK_SIZE 0
 #endif
 
-	  /* Let them override the alloc and free routines too.  */
+          /* Let them override the alloc and free routines too.  */
 
 #ifndef OBSTACK_CHUNK_ALLOC
 #define OBSTACK_CHUNK_ALLOC xmalloc
@@ -213,16 +213,16 @@ ebitset_elt_alloc (void)
 #define __alignof__(type) 0
 #endif
 
-	  obstack_specify_allocation (&ebitset_obstack, OBSTACK_CHUNK_SIZE,
-				      __alignof__ (ebitset_elt),
-				      OBSTACK_CHUNK_ALLOC,
-				      OBSTACK_CHUNK_FREE);
-	}
+          obstack_specify_allocation (&ebitset_obstack, OBSTACK_CHUNK_SIZE,
+                                      __alignof__ (ebitset_elt),
+                                      OBSTACK_CHUNK_ALLOC,
+                                      OBSTACK_CHUNK_FREE);
+        }
 
       /* Perhaps we should add a number of new elements to the free
-	 list.  */
+         list.  */
       elt = (ebitset_elt *) obstack_alloc (&ebitset_obstack,
-					   sizeof (ebitset_elt));
+                                           sizeof (ebitset_elt));
     }
 
   return elt;
@@ -293,7 +293,7 @@ ebitset_elt_zero_p (ebitset_elt *elt)
 
 static ebitset_elt *
 ebitset_elt_find (bitset bset, bitset_bindex bindex,
-		  enum ebitset_find_mode mode)
+                  enum ebitset_find_mode mode)
 {
   ebitset_elt *elt;
   bitset_windex size;
@@ -308,13 +308,13 @@ ebitset_elt_find (bitset bset, bitset_bindex bindex,
   if (eindex < size)
     {
       if ((elt = elts[eindex]))
-	{
-	  if (EBITSET_WORDS (elt) == bset->b.cdata)
-	    return elt;
+        {
+          if (EBITSET_WORDS (elt) == bset->b.cdata)
+            return elt;
 
-	  EBITSET_CACHE_SET (bset, eindex);
-	  return elt;
-	}
+          EBITSET_CACHE_SET (bset, eindex);
+          return elt;
+        }
     }
 
   /* The element could not be found.  */
@@ -329,7 +329,7 @@ ebitset_elt_find (bitset bset, bitset_bindex bindex,
 
     case EBITSET_CREATE:
       if (eindex >= size)
-	ebitset_resize (bset, bindex);
+        ebitset_resize (bset, bindex);
 
       /* Create a new element.  */
       elt = ebitset_elt_calloc ();
@@ -361,22 +361,22 @@ ebitset_weed (bitset bset)
       ebitset_elt *elt = elts[j];
 
       if (elt)
-	{
-	  if (ebitset_elt_zero_p (elt))
-	    {
-	      ebitset_elt_remove (bset, j);
-	      count++;
-	    }
-	}
+        {
+          if (ebitset_elt_zero_p (elt))
+            {
+              ebitset_elt_remove (bset, j);
+              count++;
+            }
+        }
       else
-	count++;
+        count++;
     }
 
   count = j - count;
   if (!count)
     {
       /* All the bits are zero.  We could shrink the elts.
-	 For now just mark BSET as known to be zero.  */
+         For now just mark BSET as known to be zero.  */
       EBITSET_ZERO_SET (bset);
     }
   else
@@ -402,7 +402,7 @@ ebitset_zero (bitset bset)
       ebitset_elt *elt = elts[j];
 
       if (elt)
-	ebitset_elt_remove (bset, j);
+        ebitset_elt_remove (bset, j);
     }
 
   /* All the bits are zero.  We could shrink the elts.
@@ -437,13 +437,13 @@ ebitset_equal_p (bitset dst, bitset src)
       ebitset_elt *delt = delts[j];
 
       if (!selt && !delt)
-	continue;
+        continue;
       if ((selt && !delt) || (!selt && delt))
-	return false;
+        return false;
 
       for (i = 0; i < EBITSET_ELT_WORDS; i++)
-	if (EBITSET_WORDS (selt)[i] != EBITSET_WORDS (delt)[i])
-	  return false;
+        if (EBITSET_WORDS (selt)[i] != EBITSET_WORDS (delt)[i])
+          return false;
     }
   return true;
 }
@@ -472,14 +472,14 @@ ebitset_copy_ (bitset dst, bitset src)
       ebitset_elt *selt = selts[j];
 
       if (selt)
-	{
-	  ebitset_elt *tmp;
-
-	  tmp = ebitset_elt_alloc ();
-	  delts[j] = tmp;
-	  memcpy (EBITSET_WORDS (tmp), EBITSET_WORDS (selt),
-		  sizeof (EBITSET_WORDS (selt)));
-	}
+        {
+          ebitset_elt *tmp;
+
+          tmp = ebitset_elt_alloc ();
+          delts[j] = tmp;
+          memcpy (EBITSET_WORDS (tmp), EBITSET_WORDS (selt),
+                  sizeof (EBITSET_WORDS (selt)));
+        }
     }
   EBITSET_NONZERO_SET (dst);
 }
@@ -545,9 +545,9 @@ ebitset_test (bitset src, bitset_bindex bitno)
   bitset_windex windex = bitno / BITSET_WORD_BITS;
 
   return (ebitset_elt_find (src, bitno, EBITSET_FIND)
-	  && ((src->b.cdata[windex - src->b.cindex]
-	       >> (bitno % BITSET_WORD_BITS))
-	      & 1));
+          && ((src->b.cdata[windex - src->b.cindex]
+               >> (bitno % BITSET_WORD_BITS))
+              & 1));
 }
 
 
@@ -564,7 +564,7 @@ ebitset_free (bitset bset)
  found and with *NEXT indicating where search stopped.  */
 static bitset_bindex
 ebitset_list_reverse (bitset bset, bitset_bindex *list,
-		      bitset_bindex num, bitset_bindex *next)
+                      bitset_bindex num, bitset_bindex *next)
 {
   bitset_bindex n_bits;
   bitset_bindex bitno;
@@ -610,33 +610,33 @@ ebitset_list_reverse (bitset bset, bitset_bindex *list,
 
       elt = elts[eindex];
       if (elt)
-	{
-	  srcp = EBITSET_WORDS (elt);
-
-	  do
-	    {
-	      bitset_word word;
-
-	      word = srcp[woffset] << (BITSET_WORD_BITS - 1 - bcount);
-
-	      for (; word; bcount--)
-		{
-		  if (word & BITSET_MSB)
-		    {
-		      list[count++] = boffset + bcount;
-		      if (count >= num)
-			{
-			  *next = n_bits - (boffset + bcount);
-			  return count;
-			}
-		    }
-		  word <<= 1;
-		}
-	      boffset -= BITSET_WORD_BITS;
-	      bcount = BITSET_WORD_BITS - 1;
-	    }
-	  while (woffset--);
-	}
+        {
+          srcp = EBITSET_WORDS (elt);
+
+          do
+            {
+              bitset_word word;
+
+              word = srcp[woffset] << (BITSET_WORD_BITS - 1 - bcount);
+
+              for (; word; bcount--)
+                {
+                  if (word & BITSET_MSB)
+                    {
+                      list[count++] = boffset + bcount;
+                      if (count >= num)
+                        {
+                          *next = n_bits - (boffset + bcount);
+                          return count;
+                        }
+                    }
+                  word <<= 1;
+                }
+              boffset -= BITSET_WORD_BITS;
+              bcount = BITSET_WORD_BITS - 1;
+            }
+          while (woffset--);
+        }
 
       woffset = EBITSET_ELT_WORDS - 1;
       boffset = eindex * EBITSET_ELT_BITS - BITSET_WORD_BITS;
@@ -653,7 +653,7 @@ ebitset_list_reverse (bitset bset, bitset_bindex *list,
  found and with *NEXT indicating where search stopped.  */
 static bitset_bindex
 ebitset_list (bitset bset, bitset_bindex *list,
-	      bitset_bindex num, bitset_bindex *next)
+              bitset_bindex num, bitset_bindex *next)
 {
   bitset_bindex bitno;
   bitset_windex windex;
@@ -680,33 +680,33 @@ ebitset_list (bitset bset, bitset_bindex *list,
 
       elt = elts[eindex];
       if (elt)
-	{
-	  bitset_windex woffset;
-	  bitset_word *srcp = EBITSET_WORDS (elt);
-
-	  windex = bitno / BITSET_WORD_BITS;
-	  woffset = eindex * EBITSET_ELT_WORDS;
-
-	  for (; (windex - woffset) < EBITSET_ELT_WORDS; windex++)
-	    {
-	      word = srcp[windex - woffset] >> (bitno % BITSET_WORD_BITS);
-
-	      for (; word; bitno++)
-		{
-		  if (word & 1)
-		    {
-		      list[count++] = bitno;
-		      if (count >= num)
-			{
-			  *next = bitno + 1;
-			  return count;
-			}
-		    }
-		  word >>= 1;
-		}
-	      bitno = (windex + 1) * BITSET_WORD_BITS;
-	    }
-	}
+        {
+          bitset_windex woffset;
+          bitset_word *srcp = EBITSET_WORDS (elt);
+
+          windex = bitno / BITSET_WORD_BITS;
+          woffset = eindex * EBITSET_ELT_WORDS;
+
+          for (; (windex - woffset) < EBITSET_ELT_WORDS; windex++)
+            {
+              word = srcp[windex - woffset] >> (bitno % BITSET_WORD_BITS);
+
+              for (; word; bitno++)
+                {
+                  if (word & 1)
+                    {
+                      list[count++] = bitno;
+                      if (count >= num)
+                        {
+                          *next = bitno + 1;
+                          return count;
+                        }
+                    }
+                  word >>= 1;
+                }
+              bitno = (windex + 1) * BITSET_WORD_BITS;
+            }
+        }
 
       /* Skip to next element.  */
       eindex++;
@@ -722,108 +722,108 @@ ebitset_list (bitset bset, bitset_bindex *list,
 
       elt = elts[eindex];
       if (!elt)
-	continue;
+        continue;
 
       srcp = EBITSET_WORDS (elt);
       windex = eindex * EBITSET_ELT_WORDS;
 
       if ((count + EBITSET_ELT_BITS) < num)
-	{
-	  /* The coast is clear, plant boot!  */
+        {
+          /* The coast is clear, plant boot!  */
 
 #if EBITSET_ELT_WORDS == 2
-	  word = srcp[0];
-	  if (word)
-	    {
-	      if (!(word & 0xffff))
-		{
-		  word >>= 16;
-		  bitno += 16;
-		}
-	      if (!(word & 0xff))
-		{
-		  word >>= 8;
-		  bitno += 8;
-		}
-	      for (; word; bitno++)
-		{
-		  if (word & 1)
-		    list[count++] = bitno;
-		  word >>= 1;
-		}
-	    }
-	  windex++;
-	  bitno = windex * BITSET_WORD_BITS;
-
-	  word = srcp[1];
-	  if (word)
-	    {
-	      if (!(word & 0xffff))
-		{
-		  word >>= 16;
-		  bitno += 16;
-		}
-	      for (; word; bitno++)
-		{
-		  if (word & 1)
-		    list[count++] = bitno;
-		  word >>= 1;
-		}
-	    }
-	  windex++;
-	  bitno = windex * BITSET_WORD_BITS;
+          word = srcp[0];
+          if (word)
+            {
+              if (!(word & 0xffff))
+                {
+                  word >>= 16;
+                  bitno += 16;
+                }
+              if (!(word & 0xff))
+                {
+                  word >>= 8;
+                  bitno += 8;
+                }
+              for (; word; bitno++)
+                {
+                  if (word & 1)
+                    list[count++] = bitno;
+                  word >>= 1;
+                }
+            }
+          windex++;
+          bitno = windex * BITSET_WORD_BITS;
+
+          word = srcp[1];
+          if (word)
+            {
+              if (!(word & 0xffff))
+                {
+                  word >>= 16;
+                  bitno += 16;
+                }
+              for (; word; bitno++)
+                {
+                  if (word & 1)
+                    list[count++] = bitno;
+                  word >>= 1;
+                }
+            }
+          windex++;
+          bitno = windex * BITSET_WORD_BITS;
 #else
-	  for (i = 0; i < EBITSET_ELT_WORDS; i++, windex++)
-	    {
-	      bitno = windex * BITSET_WORD_BITS;
-
-	      word = srcp[i];
-	      if (word)
-		{
-		  if (!(word & 0xffff))
-		    {
-		      word >>= 16;
-		      bitno += 16;
-		    }
-		  if (!(word & 0xff))
-		    {
-		      word >>= 8;
-		      bitno += 8;
-		    }
-		  for (; word; bitno++)
-		    {
-		      if (word & 1)
-			list[count++] = bitno;
-		      word >>= 1;
-		    }
-		}
-	    }
+          for (i = 0; i < EBITSET_ELT_WORDS; i++, windex++)
+            {
+              bitno = windex * BITSET_WORD_BITS;
+
+              word = srcp[i];
+              if (word)
+                {
+                  if (!(word & 0xffff))
+                    {
+                      word >>= 16;
+                      bitno += 16;
+                    }
+                  if (!(word & 0xff))
+                    {
+                      word >>= 8;
+                      bitno += 8;
+                    }
+                  for (; word; bitno++)
+                    {
+                      if (word & 1)
+                        list[count++] = bitno;
+                      word >>= 1;
+                    }
+                }
+            }
 #endif
-	}
+        }
       else
-	{
-	  /* Tread more carefully since we need to check
-	     if array overflows.  */
-
-	  for (i = 0; i < EBITSET_ELT_WORDS; i++, windex++)
-	    {
-	      bitno = windex * BITSET_WORD_BITS;
-
-	      for (word = srcp[i]; word; bitno++)
-		{
-		  if (word & 1)
-		    {
-		      list[count++] = bitno;
-		      if (count >= num)
-			{
-			  *next = bitno + 1;
-			  return count;
-			}
-		    }
-		  word >>= 1;
-		}
-	    }
-	}
+        {
+          /* Tread more carefully since we need to check
+             if array overflows.  */
+
+          for (i = 0; i < EBITSET_ELT_WORDS; i++, windex++)
+            {
+              bitno = windex * BITSET_WORD_BITS;
+
+              for (word = srcp[i]; word; bitno++)
+                {
+                  if (word & 1)
+                    {
+                      list[count++] = bitno;
+                      if (count >= num)
+                        {
+                          *next = bitno + 1;
+                          return count;
+                        }
+                    }
+                  word >>= 1;
+                }
+            }
+        }
     }
 
   *next = bitno;
@@ -853,19 +853,19 @@ ebitset_unused_clear (bitset dst)
 
       elt = elts[eindex];
       if (elt)
-	{
-	  bitset_windex windex;
-	  bitset_windex woffset;
-	  bitset_word *srcp = EBITSET_WORDS (elt);
-
-	  windex = n_bits / BITSET_WORD_BITS;
-	  woffset = eindex * EBITSET_ELT_WORDS;
-
-	  srcp[windex - woffset] &= ((bitset_word) 1 << last_bit) - 1;
-	  windex++;
-	  for (; (windex - woffset) < EBITSET_ELT_WORDS; windex++)
-	    srcp[windex - woffset] = 0;
-	}
+        {
+          bitset_windex windex;
+          bitset_windex woffset;
+          bitset_word *srcp = EBITSET_WORDS (elt);
+
+          windex = n_bits / BITSET_WORD_BITS;
+          woffset = eindex * EBITSET_ELT_WORDS;
+
+          srcp[windex - woffset] &= ((bitset_word) 1 << last_bit) - 1;
+          windex++;
+          for (; (windex - woffset) < EBITSET_ELT_WORDS; windex++)
+            srcp[windex - woffset] = 0;
+        }
     }
 }
 
@@ -879,9 +879,9 @@ ebitset_ones (bitset dst)
   for (j = 0; j < EBITSET_SIZE (dst); j++)
     {
       /* Create new elements if they cannot be found.  Perhaps
-	 we should just add pointers to a ones element?  */
+         we should just add pointers to a ones element?  */
       elt =
-	ebitset_elt_find (dst, j * EBITSET_ELT_BITS, EBITSET_CREATE);
+        ebitset_elt_find (dst, j * EBITSET_ELT_BITS, EBITSET_CREATE);
       memset (EBITSET_WORDS (elt), -1, sizeof (EBITSET_WORDS (elt)));
     }
   EBITSET_NONZERO_SET (dst);
@@ -904,12 +904,12 @@ ebitset_empty_p (bitset dst)
       ebitset_elt *elt = elts[j];
 
       if (elt)
-	{
-	  if (!ebitset_elt_zero_p (elt))
-	    return 0;
-	  /* Do some weeding as we go.  */
-	  ebitset_elt_remove (dst, j);
-	}
+        {
+          if (!ebitset_elt_zero_p (elt))
+            return 0;
+          /* Do some weeding as we go.  */
+          ebitset_elt_remove (dst, j);
+        }
     }
 
   /* All the bits are zero.  We could shrink the elts.
@@ -932,14 +932,14 @@ ebitset_not (bitset dst, bitset src)
   for (j = 0; j < EBITSET_SIZE (src); j++)
     {
       /* Create new elements for dst if they cannot be found
-	 or substitute zero elements if src elements not found.  */
+         or substitute zero elements if src elements not found.  */
       selt =
-	ebitset_elt_find (dst, j * EBITSET_ELT_BITS, EBITSET_SUBST);
+        ebitset_elt_find (dst, j * EBITSET_ELT_BITS, EBITSET_SUBST);
       delt =
-	ebitset_elt_find (dst, j * EBITSET_ELT_BITS, EBITSET_CREATE);
+        ebitset_elt_find (dst, j * EBITSET_ELT_BITS, EBITSET_CREATE);
 
       for (i = 0; i < EBITSET_ELT_WORDS; i++)
-	EBITSET_WORDS (delt)[i] = ~EBITSET_WORDS (selt)[i];
+        EBITSET_WORDS (delt)[i] = ~EBITSET_WORDS (selt)[i];
     }
   EBITSET_NONZERO_SET (dst);
   ebitset_unused_clear (dst);
@@ -972,17 +972,17 @@ ebitset_subset_p (bitset dst, bitset src)
       delt = j < dsize ? delts[j] : 0;
 
       if (!selt && !delt)
-	continue;
+        continue;
 
       if (!selt)
-	selt = &ebitset_zero_elts[0];
+        selt = &ebitset_zero_elts[0];
       if (!delt)
-	delt = &ebitset_zero_elts[0];
+        delt = &ebitset_zero_elts[0];
 
       for (i = 0; i < EBITSET_ELT_WORDS; i++)
-	if (EBITSET_WORDS (delt)[i]
-	    != (EBITSET_WORDS (selt)[i] | EBITSET_WORDS (delt)[i]))
-	  return false;
+        if (EBITSET_WORDS (delt)[i]
+            != (EBITSET_WORDS (selt)[i] | EBITSET_WORDS (delt)[i]))
+          return false;
     }
   return true;
 }
@@ -1014,11 +1014,11 @@ ebitset_disjoint_p (bitset dst, bitset src)
       delt = j < dsize ? delts[j] : 0;
 
       if (!selt || !delt)
-	continue;
+        continue;
 
       for (i = 0; i < EBITSET_ELT_WORDS; i++)
-	if ((EBITSET_WORDS (selt)[i] & EBITSET_WORDS (delt)[i]))
-	  return false;
+        if ((EBITSET_WORDS (selt)[i] & EBITSET_WORDS (delt)[i]))
+          return false;
     }
   return true;
 }
@@ -1066,93 +1066,93 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
       delt = j < dsize ? delts[j] : 0;
 
       if (!selt1 && !selt2)
-	{
-	  if (delt)
-	    {
-	      changed = true;
-	      ebitset_elt_remove (dst, j);
-	    }
-	  continue;
-	}
+        {
+          if (delt)
+            {
+              changed = true;
+              ebitset_elt_remove (dst, j);
+            }
+          continue;
+        }
 
       if (!selt1)
-	selt1 = &ebitset_zero_elts[0];
+        selt1 = &ebitset_zero_elts[0];
       if (!selt2)
-	selt2 = &ebitset_zero_elts[0];
+        selt2 = &ebitset_zero_elts[0];
       if (!delt)
-	delt = ebitset_elt_calloc ();
+        delt = ebitset_elt_calloc ();
       else
-	delts[j] = 0;
+        delts[j] = 0;
 
       srcp1 = EBITSET_WORDS (selt1);
       srcp2 = EBITSET_WORDS (selt2);
       dstp = EBITSET_WORDS (delt);
       switch (op)
-	{
-	default:
-	  abort ();
-
-	case BITSET_OP_OR:
-	  for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
-	    {
-	      bitset_word tmp = *srcp1++ | *srcp2++;
-
-	      if (*dstp != tmp)
-		{
-		  changed = true;
-		  *dstp = tmp;
-		}
-	    }
-	  break;
-
-	case BITSET_OP_AND:
-	  for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
-	    {
-	      bitset_word tmp = *srcp1++ & *srcp2++;
-
-	      if (*dstp != tmp)
-		{
-		  changed = true;
-		  *dstp = tmp;
-		}
-	    }
-	  break;
-
-	case BITSET_OP_XOR:
-	  for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
-	    {
-	      bitset_word tmp = *srcp1++ ^ *srcp2++;
-
-	      if (*dstp != tmp)
-		{
-		  changed = true;
-		  *dstp = tmp;
-		}
-	    }
-	  break;
-
-	case BITSET_OP_ANDN:
-	  for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
-	    {
-	      bitset_word tmp = *srcp1++ & ~(*srcp2++);
-
-	      if (*dstp != tmp)
-		{
-		  changed = true;
-		  *dstp = tmp;
-		}
-	    }
-	  break;
-	}
+        {
+        default:
+          abort ();
+
+        case BITSET_OP_OR:
+          for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
+            {
+              bitset_word tmp = *srcp1++ | *srcp2++;
+
+              if (*dstp != tmp)
+                {
+                  changed = true;
+                  *dstp = tmp;
+                }
+            }
+          break;
+
+        case BITSET_OP_AND:
+          for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
+            {
+              bitset_word tmp = *srcp1++ & *srcp2++;
+
+              if (*dstp != tmp)
+                {
+                  changed = true;
+                  *dstp = tmp;
+                }
+            }
+          break;
+
+        case BITSET_OP_XOR:
+          for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
+            {
+              bitset_word tmp = *srcp1++ ^ *srcp2++;
+
+              if (*dstp != tmp)
+                {
+                  changed = true;
+                  *dstp = tmp;
+                }
+            }
+          break;
+
+        case BITSET_OP_ANDN:
+          for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
+            {
+              bitset_word tmp = *srcp1++ & ~(*srcp2++);
+
+              if (*dstp != tmp)
+                {
+                  changed = true;
+                  *dstp = tmp;
+                }
+            }
+          break;
+        }
 
       if (!ebitset_elt_zero_p (delt))
-	{
-	  ebitset_elt_add (dst, delt, j);
-	}
+        {
+          ebitset_elt_add (dst, delt, j);
+        }
       else
-	{
-	  ebitset_elt_free (delt);
-	}
+        {
+          ebitset_elt_free (delt);
+        }
     }
 
   /* If we have elements of DST left over, free them all.  */
@@ -1165,7 +1165,7 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
       delt = delts[j];
 
       if (delt)
-	ebitset_elt_remove (dst, j);
+        ebitset_elt_remove (dst, j);
     }
 
   EBITSET_NONZERO_SET (dst);
