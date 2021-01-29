@@ -38,9 +38,9 @@ static void vbitset_set (bitset, bitset_bindex);
 static void vbitset_reset (bitset, bitset_bindex);
 static bool vbitset_test (bitset, bitset_bindex);
 static bitset_bindex vbitset_list (bitset, bitset_bindex *,
-				   bitset_bindex, bitset_bindex *);
+                                   bitset_bindex, bitset_bindex *);
 static bitset_bindex vbitset_list_reverse (bitset, bitset_bindex *,
-					   bitset_bindex, bitset_bindex *);
+                                           bitset_bindex, bitset_bindex *);
 
 #define VBITSET_N_WORDS(N) (((N) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS)
 #define VBITSET_WORDS(X) ((X)->b.cdata)
@@ -69,38 +69,38 @@ vbitset_resize (bitset src, bitset_bindex n_bits)
       bitset_windex size;
 
       /* The bitset needs to grow.  If we already have enough memory
-	 allocated, then just zero what we need.  */
+         allocated, then just zero what we need.  */
       if (newsize > VBITSET_ASIZE (src))
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
-	  VBITSET_WORDS (src)
-	    = realloc (VBITSET_WORDS (src), size * sizeof (bitset_word));
-	  VBITSET_ASIZE (src) = size;
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
+          VBITSET_WORDS (src)
+            = realloc (VBITSET_WORDS (src), size * sizeof (bitset_word));
+          VBITSET_ASIZE (src) = size;
+        }
 
       memset (VBITSET_WORDS (src) + oldsize, 0,
-	      (newsize - oldsize) * sizeof (bitset_word));
+              (newsize - oldsize) * sizeof (bitset_word));
       VBITSET_SIZE (src) = newsize;
     }
   else
     {
       /* The bitset needs to shrink.  There's no point deallocating
-	 the memory unless it is shrinking by a reasonable amount.  */
+         the memory unless it is shrinking by a reasonable amount.  */
       if ((oldsize - newsize) >= oldsize / 2)
-	{
-	  VBITSET_WORDS (src)
-	    = realloc (VBITSET_WORDS (src), newsize * sizeof (bitset_word));
-	  VBITSET_ASIZE (src) = newsize;
-	}
+        {
+          VBITSET_WORDS (src)
+            = realloc (VBITSET_WORDS (src), newsize * sizeof (bitset_word));
+          VBITSET_ASIZE (src) = newsize;
+        }
 
       /* Need to prune any excess bits.  FIXME.  */
 
@@ -196,18 +196,18 @@ vbitset_list_reverse (src, list, num, next)
 
       word = srcp[windex] << (BITSET_WORD_BITS - 1 - bitcnt);
       for (; word; bitcnt--)
-	{
-	  if (word & BITSET_MSB)
-	    {
-	      list[count++] = bitoff + bitcnt;
-	      if (count >= num)
-		{
-		  *next = n_bits - (bitoff + bitcnt);
-		  return count;
-		}
-	    }
-	  word <<= 1;
-	}
+        {
+          if (word & BITSET_MSB)
+            {
+              list[count++] = bitoff + bitcnt;
+              if (count >= num)
+                {
+                  *next = n_bits - (bitoff + bitcnt);
+                  return count;
+                }
+            }
+          word <<= 1;
+        }
       bitoff -= BITSET_WORD_BITS;
       bitcnt = BITSET_WORD_BITS - 1;
     }
@@ -243,80 +243,80 @@ vbitset_list (src, list, num, next)
     {
       /* Many bitsets are zero, so make this common case fast.  */
       for (windex = 0; windex < size && !srcp[windex]; windex++)
-	continue;
+        continue;
       if (windex >= size)
-	return 0;
+        return 0;
 
       /* If num is 1, we could speed things up with a binary search
-	 of the current word.  */
+         of the current word.  */
 
       bitoff = windex * BITSET_WORD_BITS;
     }
   else
     {
       if (bitno >= BITSET_SIZE_ (src))
-	return 0;
+        return 0;
 
       windex = bitno / BITSET_WORD_BITS;
       bitno = bitno % BITSET_WORD_BITS;
 
       if (bitno)
-	{
-	  /* Handle the case where we start within a word.
-	     Most often, this is executed with large bitsets
-	     with many set bits where we filled the array
-	     on the previous call to this function.  */
-
-	  bitoff = windex * BITSET_WORD_BITS;
-	  word = srcp[windex] >> bitno;
-	  for (bitno = bitoff + bitno; word; bitno++)
-	    {
-	      if (word & 1)
-		{
-		  list[count++] = bitno;
-		  if (count >= num)
-		    {
-		      *next = bitno + 1;
-		      return count;
-		    }
-		}
-	      word >>= 1;
-	    }
-	  windex++;
-	}
+        {
+          /* Handle the case where we start within a word.
+             Most often, this is executed with large bitsets
+             with many set bits where we filled the array
+             on the previous call to this function.  */
+
+          bitoff = windex * BITSET_WORD_BITS;
+          word = srcp[windex] >> bitno;
+          for (bitno = bitoff + bitno; word; bitno++)
+            {
+              if (word & 1)
+                {
+                  list[count++] = bitno;
+                  if (count >= num)
+                    {
+                      *next = bitno + 1;
+                      return count;
+                    }
+                }
+              word >>= 1;
+            }
+          windex++;
+        }
       bitoff = windex * BITSET_WORD_BITS;
     }
 
   for (; windex < size; windex++, bitoff += BITSET_WORD_BITS)
     {
       if (!(word = srcp[windex]))
-	continue;
+        continue;
 
       if ((count + BITSET_WORD_BITS) < num)
-	{
-	  for (bitno = bitoff; word; bitno++)
-	    {
-	      if (word & 1)
-		list[count++] = bitno;
-	      word >>= 1;
-	    }
-	}
+        {
+          for (bitno = bitoff; word; bitno++)
+            {
+              if (word & 1)
+                list[count++] = bitno;
+              word >>= 1;
+            }
+        }
       else
-	{
-	  for (bitno = bitoff; word; bitno++)
-	    {
-	      if (word & 1)
-		{
-		  list[count++] = bitno;
-		  if (count >= num)
-		    {
-		      *next = bitno + 1;
-		      return count;
-		    }
-		}
-	      word >>= 1;
-	    }
-	}
+        {
+          for (bitno = bitoff; word; bitno++)
+            {
+              if (word & 1)
+                {
+                  list[count++] = bitno;
+                  if (count >= num)
+                    {
+                      *next = bitno + 1;
+                      return count;
+                    }
+                }
+              word >>= 1;
+            }
+        }
     }
 
   *next = bitoff;
@@ -398,7 +398,7 @@ vbitset_copy1 (bitset dst, bitset src)
   memcpy (dstp, srcp, sizeof (bitset_word) * ssize);
 
   memset (dstp + sizeof (bitset_word) * ssize, 0,
-	  sizeof (bitset_word) * (dsize - ssize));
+          sizeof (bitset_word) * (dsize - ssize));
 }
 
 
@@ -423,7 +423,7 @@ vbitset_not (bitset dst, bitset src)
 
   vbitset_unused_clear (dst);
   memset (dstp + sizeof (bitset_word) * ssize, 0,
-	  sizeof (bitset_word) * (dsize - ssize));
+          sizeof (bitset_word) * (dsize - ssize));
 }
 
 
@@ -438,19 +438,19 @@ vbitset_equal_p (bitset dst, bitset src)
 
   for (i = 0; i < min (ssize, dsize); i++)
       if (*srcp++ != *dstp++)
-	  return 0;
+          return 0;
 
   if (ssize > dsize)
     {
       for (; i < ssize; i++)
-	if (*srcp++)
-	  return 0;
+        if (*srcp++)
+          return 0;
     }
   else
     {
       for (; i < dsize; i++)
-	if (*dstp++)
-	  return 0;
+        if (*dstp++)
+          return 0;
     }
 
   return 1;
@@ -468,13 +468,13 @@ vbitset_subset_p (bitset dst, bitset src)
 
   for (i = 0; i < min (ssize, dsize); i++, dstp++, srcp++)
       if (*dstp != (*srcp | *dstp))
-	  return 0;
+          return 0;
 
   if (ssize > dsize)
     {
       for (; i < ssize; i++)
-	if (*srcp++)
-	  return 0;
+        if (*srcp++)
+          return 0;
     }
 
   return 1;
@@ -492,7 +492,7 @@ vbitset_disjoint_p (bitset dst, bitset src)
 
   for (i = 0; i < min (ssize, dsize); i++)
       if (*srcp++ & *dstp++)
-	  return 0;
+          return 0;
 
   return 1;
 }
@@ -551,10 +551,10 @@ vbitset_and_cmp (bitset dst, bitset src1, bitset src2)
       bitset_word tmp = *src1p++ & *src2p++;
 
       if (*dstp != tmp)
-	{
-	  changed = 1;
-	  *dstp = tmp;
-	}
+        {
+          changed = 1;
+          *dstp = tmp;
+        }
     }
 
   if (ssize2 > ssize1)
@@ -566,10 +566,10 @@ vbitset_and_cmp (bitset dst, bitset src1, bitset src2)
   for (; i < ssize1; i++, dstp++)
     {
       if (*dstp != 0)
-	{
-	  changed = 1;
-	  *dstp = 0;
-	}
+        {
+          changed = 1;
+          *dstp = 0;
+        }
     }
 
   memset (dstp, 0, sizeof (bitset_word) * (dsize - ssize1));
@@ -604,14 +604,14 @@ vbitset_andn (bitset dst, bitset src1, bitset src2)
   if (ssize2 > ssize1)
     {
       for (; i < ssize2; i++)
-	*dstp++ = 0;
+        *dstp++ = 0;
 
       memset (dstp, 0, sizeof (bitset_word) * (dsize - ssize2));
     }
   else
     {
       for (; i < ssize1; i++)
-	*dstp++ = *src1p++;
+        *dstp++ = *src1p++;
 
       memset (dstp, 0, sizeof (bitset_word) * (dsize - ssize1));
     }
@@ -644,37 +644,37 @@ vbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
       bitset_word tmp = *src1p++ & ~(*src2p++);
 
       if (*dstp != tmp)
-	{
-	  changed = 1;
-	  *dstp = tmp;
-	}
+        {
+          changed = 1;
+          *dstp = tmp;
+        }
     }
 
   if (ssize2 > ssize1)
     {
       for (; i < ssize2; i++, dstp++)
-	{
-	  if (*dstp != 0)
-	    {
-	      changed = 1;
-	      *dstp = 0;
-	    }
-	}
+        {
+          if (*dstp != 0)
+            {
+              changed = 1;
+              *dstp = 0;
+            }
+        }
 
       memset (dstp, 0, sizeof (bitset_word) * (dsize - ssize2));
     }
   else
     {
       for (; i < ssize1; i++, dstp++)
-	{
-	  bitset_word tmp = *src1p++;
+        {
+          bitset_word tmp = *src1p++;
 
-	  if (*dstp != tmp)
-	    {
-	      changed = 1;
-	      *dstp = tmp;
-	    }
-	}
+          if (*dstp != tmp)
+            {
+              changed = 1;
+              *dstp = tmp;
+            }
+        }
 
       memset (dstp, 0, sizeof (bitset_word) * (dsize - ssize1));
     }
@@ -745,10 +745,10 @@ vbitset_or_cmp (bitset dst, bitset src1, bitset src2)
       bitset_word tmp = *src1p++ | *src2p++;
 
       if (*dstp != tmp)
-	{
-	  changed = 1;
-	  *dstp = tmp;
-	}
+        {
+          changed = 1;
+          *dstp = tmp;
+        }
     }
 
   if (ssize2 > ssize1)
@@ -762,10 +762,10 @@ vbitset_or_cmp (bitset dst, bitset src1, bitset src2)
       bitset_word tmp = *src1p++;
 
       if (*dstp != tmp)
-	{
-	  changed = 1;
-	  *dstp = tmp;
-	}
+        {
+          changed = 1;
+          *dstp = tmp;
+        }
     }
 
   memset (dstp, 0, sizeof (bitset_word) * (dsize - ssize1));
@@ -836,10 +836,10 @@ vbitset_xor_cmp (bitset dst, bitset src1, bitset src2)
       bitset_word tmp = *src1p++ ^ *src2p++;
 
       if (*dstp != tmp)
-	{
-	  changed = 1;
-	  *dstp = tmp;
-	}
+        {
+          changed = 1;
+          *dstp = tmp;
+        }
     }
 
   if (ssize2 > ssize1)
@@ -853,10 +853,10 @@ vbitset_xor_cmp (bitset dst, bitset src1, bitset src2)
       bitset_word tmp = *src1p++;
 
       if (*dstp != tmp)
-	{
-	  changed = 1;
-	  *dstp = tmp;
-	}
+        {
+          changed = 1;
+          *dstp = tmp;
+        }
     }
 
   memset (dstp, 0, sizeof (bitset_word) * (dsize - ssize1));
@@ -926,10 +926,10 @@ vbitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
       bitset_word tmp = (*src1p++ & *src2p++) | *src3p++;
 
       if (*dstp != tmp)
-	{
-	  changed = 1;
-	  *dstp = tmp;
-	}
+        {
+          changed = 1;
+          *dstp = tmp;
+        }
     }
   return changed;
 }
@@ -993,10 +993,10 @@ vbitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
       bitset_word tmp = (*src1p++ & ~(*src2p++)) | *src3p++;
 
       if (*dstp != tmp)
-	{
-	  changed = 1;
-	  *dstp = tmp;
-	}
+        {
+          changed = 1;
+          *dstp = tmp;
+        }
     }
   return changed;
 }
@@ -1060,10 +1060,10 @@ vbitset_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
       bitset_word tmp = (*src1p++ | *src2p++) & *src3p++;
 
       if (*dstp != tmp)
-	{
-	  changed = 1;
-	  *dstp = tmp;
-	}
+        {
+          changed = 1;
+          *dstp = tmp;
+        }
     }
   return changed;
 }
