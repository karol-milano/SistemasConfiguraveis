@@ -60,10 +60,10 @@ typedef bitset_word lbitset_word;
    These are linked together in a doubly-linked list.  */
 typedef struct lbitset_elt_struct
 {
-  struct lbitset_elt_struct *next;	/* Next element.  */
-  struct lbitset_elt_struct *prev;	/* Previous element.  */
-  bitset_windex index;	/* bitno / BITSET_WORD_BITS.  */
-  bitset_word words[LBITSET_ELT_WORDS];	/* Bits that are set.  */
+  struct lbitset_elt_struct *next;      /* Next element.  */
+  struct lbitset_elt_struct *prev;      /* Previous element.  */
+  bitset_windex index;  /* bitno / BITSET_WORD_BITS.  */
+  bitset_word words[LBITSET_ELT_WORDS]; /* Bits that are set.  */
 }
 lbitset_elt;
 
@@ -76,7 +76,7 @@ static lbitset_elt lbitset_zero_elts[3]; /* Elements of all zero bits.  */
 /* Obstack to allocate bitset elements from.  */
 static struct obstack lbitset_obstack;
 static bool lbitset_obstack_init = false;
-static lbitset_elt *lbitset_free_list;	/* Free list of bitset elements.  */
+static lbitset_elt *lbitset_free_list;  /* Free list of bitset elements.  */
 
 extern void debug_lbitset (bitset);
 
@@ -102,16 +102,16 @@ lbitset_elt_alloc (void)
   else
     {
       if (!lbitset_obstack_init)
-	{
-	  lbitset_obstack_init = true;
+        {
+          lbitset_obstack_init = true;
 
-	  /* Let particular systems override the size of a chunk.  */
+          /* Let particular systems override the size of a chunk.  */
 
 #ifndef OBSTACK_CHUNK_SIZE
 #define OBSTACK_CHUNK_SIZE 0
 #endif
 
-	  /* Let them override the alloc and free routines too.  */
+          /* Let them override the alloc and free routines too.  */
 
 #ifndef OBSTACK_CHUNK_ALLOC
 #define OBSTACK_CHUNK_ALLOC xmalloc
@@ -125,16 +125,16 @@ lbitset_elt_alloc (void)
 #define __alignof__(type) 0
 #endif
 
-	  obstack_specify_allocation (&lbitset_obstack, OBSTACK_CHUNK_SIZE,
-				      __alignof__ (lbitset_elt),
-				      OBSTACK_CHUNK_ALLOC,
-				      OBSTACK_CHUNK_FREE);
-	}
+          obstack_specify_allocation (&lbitset_obstack, OBSTACK_CHUNK_SIZE,
+                                      __alignof__ (lbitset_elt),
+                                      OBSTACK_CHUNK_ALLOC,
+                                      OBSTACK_CHUNK_FREE);
+        }
 
       /* Perhaps we should add a number of new elements to the free
-	 list.  */
+         list.  */
       elt = (lbitset_elt *) obstack_alloc (&lbitset_obstack,
-					   sizeof (lbitset_elt));
+                                           sizeof (lbitset_elt));
     }
 
   return elt;
@@ -185,20 +185,20 @@ lbitset_elt_unlink (bitset bset, lbitset_elt *elt)
   if (LBITSET_CURRENT (bset) == elt)
     {
       if (next)
-	{
-	  bset->b.cdata = next->words;
-	  bset->b.cindex = next->index;
-	}
+        {
+          bset->b.cdata = next->words;
+          bset->b.cindex = next->index;
+        }
       else if (prev)
-	{
-	  bset->b.cdata = prev->words;
-	  bset->b.cindex = prev->index;
-	}
+        {
+          bset->b.cdata = prev->words;
+          bset->b.cindex = prev->index;
+        }
       else
-	{
-	  bset->b.csize = 0;
-	  bset->b.cdata = 0;
-	}
+        {
+          bset->b.csize = 0;
+          bset->b.cdata = 0;
+        }
     }
 
   lbitset_elt_free (elt);
@@ -278,13 +278,13 @@ lbitset_elt_link (bitset bset, lbitset_elt *elt)
   else if (windex < bset->b.cindex)
     {
       for (ptr = current;
-	   ptr->prev && ptr->prev->index > windex; ptr = ptr->prev)
-	continue;
+           ptr->prev && ptr->prev->index > windex; ptr = ptr->prev)
+        continue;
 
       if (ptr->prev)
-	ptr->prev->next = elt;
+        ptr->prev->next = elt;
       else
-	LBITSET_HEAD (bset) = elt;
+        LBITSET_HEAD (bset) = elt;
 
       elt->prev = ptr->prev;
       elt->next = ptr;
@@ -295,13 +295,13 @@ lbitset_elt_link (bitset bset, lbitset_elt *elt)
   else
     {
       for (ptr = current;
-	   ptr->next && ptr->next->index < windex; ptr = ptr->next)
-	continue;
+           ptr->next && ptr->next->index < windex; ptr = ptr->next)
+        continue;
 
       if (ptr->next)
-	ptr->next->prev = elt;
+        ptr->next->prev = elt;
       else
-	LBITSET_TAIL (bset) = elt;
+        LBITSET_TAIL (bset) = elt;
 
       elt->next = ptr->next;
       elt->prev = ptr;
@@ -317,7 +317,7 @@ lbitset_elt_link (bitset bset, lbitset_elt *elt)
 
 static lbitset_elt *
 lbitset_elt_find (bitset bset, bitset_windex windex,
-		  enum lbitset_find_mode mode)
+                  enum lbitset_find_mode mode)
 {
   lbitset_elt *elt;
   lbitset_elt *current;
@@ -327,7 +327,7 @@ lbitset_elt_find (bitset bset, bitset_windex windex,
       current = LBITSET_CURRENT (bset);
       /* Check if element is the cached element.  */
       if ((windex - bset->b.cindex) < bset->b.csize)
-	return current;
+        return current;
     }
   else
     {
@@ -337,28 +337,28 @@ lbitset_elt_find (bitset bset, bitset_windex windex,
   if (current)
     {
       if (windex < bset->b.cindex)
-	{
-	  for (elt = current;
-	       elt->prev && elt->index > windex; elt = elt->prev)
-	    continue;
-	}
+        {
+          for (elt = current;
+               elt->prev && elt->index > windex; elt = elt->prev)
+            continue;
+        }
       else
-	{
-	  for (elt = current;
-	       elt->next && (elt->index + LBITSET_ELT_WORDS - 1) < windex;
-	       elt = elt->next)
-	    continue;
-	}
+        {
+          for (elt = current;
+               elt->next && (elt->index + LBITSET_ELT_WORDS - 1) < windex;
+               elt = elt->next)
+            continue;
+        }
 
       /* ELT is the nearest to the one we want.  If it's not the one
-	 we want, the one we want does not exist.  */
+         we want, the one we want does not exist.  */
       if (elt && (windex - elt->index) < LBITSET_ELT_WORDS)
-	{
-	  bset->b.cindex = elt->index;
-	  bset->b.csize = LBITSET_ELT_WORDS;
-	  bset->b.cdata = elt->words;
-	  return elt;
-	}
+        {
+          bset->b.cindex = elt->index;
+          bset->b.csize = LBITSET_ELT_WORDS;
+          bset->b.cdata = elt->words;
+          return elt;
+        }
     }
 
   switch (mode)
@@ -394,7 +394,7 @@ lbitset_weed (bitset bset)
     {
       next = elt->next;
       if (lbitset_elt_zero_p (elt))
-	lbitset_elt_unlink (bset, elt);
+        lbitset_elt_unlink (bset, elt);
     }
 }
 
@@ -431,11 +431,11 @@ lbitset_equal_p (bitset dst, bitset src)
        selt && delt; selt = selt->next, delt = delt->next)
     {
       if (selt->index != delt->index)
-	return false;
+        return false;
 
       for (j = 0; j < LBITSET_ELT_WORDS; j++)
-	if (delt->words[j] != selt->words[j])
-	  return false;
+        if (delt->words[j] != selt->words[j])
+          return false;
     }
   return !selt && !delt;
 }
@@ -467,9 +467,9 @@ lbitset_copy (bitset dst, bitset src)
       tmp->prev = prev;
       tmp->next = 0;
       if (prev)
-	prev->next = tmp;
+        prev->next = tmp;
       else
-	LBITSET_HEAD (dst) = tmp;
+        LBITSET_HEAD (dst) = tmp;
       prev = tmp;
 
       memcpy (tmp->words, elt->words, sizeof (elt->words));
@@ -549,9 +549,9 @@ lbitset_test (bitset src, bitset_bindex bitno)
   bitset_windex windex = bitno / BITSET_WORD_BITS;
 
   return (lbitset_elt_find (src, windex, LBITSET_FIND)
-	  && ((src->b.cdata[windex - src->b.cindex]
-	       >> (bitno % BITSET_WORD_BITS))
-	      & 1));
+          && ((src->b.cdata[windex - src->b.cindex]
+               >> (bitno % BITSET_WORD_BITS))
+              & 1));
 }
 
 
@@ -567,7 +567,7 @@ lbitset_free (bitset bset)
  found and with *NEXT indicating where search stopped.  */
 static bitset_bindex
 lbitset_list_reverse (bitset bset, bitset_bindex *list,
-		      bitset_bindex num, bitset_bindex *next)
+                      bitset_bindex num, bitset_bindex *next)
 {
   bitset_bindex rbitno;
   bitset_bindex bitno;
@@ -603,7 +603,7 @@ lbitset_list_reverse (bitset bset, bitset_bindex *list,
   if (windex >= elt->index + LBITSET_ELT_WORDS)
     {
       /* We are trying to start in no-mans land so start
-	 at end of current elt.  */
+         at end of current elt.  */
       bcount = BITSET_WORD_BITS - 1;
       windex = elt->index + LBITSET_ELT_WORDS - 1;
     }
@@ -623,33 +623,33 @@ lbitset_list_reverse (bitset bset, bitset_bindex *list,
       bitset_word *srcp = elt->words;
 
       for (; (windex - elt->index) < LBITSET_ELT_WORDS;
-	   windex--, boffset -= BITSET_WORD_BITS,
-	     bcount = BITSET_WORD_BITS - 1)
-	{
-	  word =
-	    srcp[windex - elt->index] << (BITSET_WORD_BITS - 1 - bcount);
-
-	  for (; word; bcount--)
-	    {
-	      if (word & BITSET_MSB)
-		{
-		  list[count++] = boffset + bcount;
-		  if (count >= num)
-		    {
-		      *next = n_bits - (boffset + bcount);
-		      return count;
-		    }
-		}
-	      word <<= 1;
-	    }
-	}
+           windex--, boffset -= BITSET_WORD_BITS,
+             bcount = BITSET_WORD_BITS - 1)
+        {
+          word =
+            srcp[windex - elt->index] << (BITSET_WORD_BITS - 1 - bcount);
+
+          for (; word; bcount--)
+            {
+              if (word & BITSET_MSB)
+                {
+                  list[count++] = boffset + bcount;
+                  if (count >= num)
+                    {
+                      *next = n_bits - (boffset + bcount);
+                      return count;
+                    }
+                }
+              word <<= 1;
+            }
+        }
 
       elt = elt->prev;
       if (elt)
-	{
-	  windex = elt->index + LBITSET_ELT_WORDS - 1;
-	  boffset = windex * BITSET_WORD_BITS;
-	}
+        {
+          windex = elt->index + LBITSET_ELT_WORDS - 1;
+          boffset = windex * BITSET_WORD_BITS;
+        }
     }
 
   *next = n_bits - (boffset + 1);
@@ -662,7 +662,7 @@ lbitset_list_reverse (bitset bset, bitset_bindex *list,
  found and with *NEXT indicating where search stopped.  */
 static bitset_bindex
 lbitset_list (bitset bset, bitset_bindex *list,
-	      bitset_bindex num, bitset_bindex *next)
+              bitset_bindex num, bitset_bindex *next)
 {
   bitset_bindex bitno;
   bitset_windex windex;
@@ -693,51 +693,51 @@ lbitset_list (bitset bset, bitset_bindex *list,
 
       /* Skip to starting element.  */
       for (elt = head;
-	   elt && (elt->index + LBITSET_ELT_WORDS - 1) < windex;
-	   elt = elt->next)
-	continue;
+           elt && (elt->index + LBITSET_ELT_WORDS - 1) < windex;
+           elt = elt->next)
+        continue;
 
       if (!elt)
-	return 0;
+        return 0;
 
       if (windex < elt->index)
-	{
-	  windex = elt->index;
-	  bitno = windex * BITSET_WORD_BITS;
-	}
+        {
+          windex = elt->index;
+          bitno = windex * BITSET_WORD_BITS;
+        }
       else
-	{
-	  bitset_word *srcp = elt->words;
-
-	  /* We are starting within an element.  */
-
-	  for (; (windex - elt->index) < LBITSET_ELT_WORDS; windex++)
-	    {
-	      word = srcp[windex - elt->index] >> (bitno % BITSET_WORD_BITS);
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
-
-	  elt = elt->next;
-	  if (elt)
-	    {
-	      windex = elt->index;
-	      bitno = windex * BITSET_WORD_BITS;
-	    }
-	}
+        {
+          bitset_word *srcp = elt->words;
+
+          /* We are starting within an element.  */
+
+          for (; (windex - elt->index) < LBITSET_ELT_WORDS; windex++)
+            {
+              word = srcp[windex - elt->index] >> (bitno % BITSET_WORD_BITS);
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
+
+          elt = elt->next;
+          if (elt)
+            {
+              windex = elt->index;
+              bitno = windex * BITSET_WORD_BITS;
+            }
+        }
     }
 
 
@@ -750,109 +750,109 @@ lbitset_list (bitset bset, bitset_bindex *list,
       bitset_word *srcp = elt->words;
 
       if ((count + LBITSET_ELT_BITS) < num)
-	{
-	  /* The coast is clear, plant boot!  */
+        {
+          /* The coast is clear, plant boot!  */
 
 #if LBITSET_ELT_WORDS == 2
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
-	  for (i = 0; i < LBITSET_ELT_WORDS; i++)
-	    {
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
-	      windex++;
-	      bitno = windex * BITSET_WORD_BITS;
-	    }
+          for (i = 0; i < LBITSET_ELT_WORDS; i++)
+            {
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
+              windex++;
+              bitno = windex * BITSET_WORD_BITS;
+            }
 #endif
-	}
+        }
       else
-	{
-	  /* Tread more carefully since we need to check
-	     if array overflows.  */
-
-	  for (i = 0; i < LBITSET_ELT_WORDS; i++)
-	    {
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
-	      windex++;
-	      bitno = windex * BITSET_WORD_BITS;
-	    }
-	}
+        {
+          /* Tread more carefully since we need to check
+             if array overflows.  */
+
+          for (i = 0; i < LBITSET_ELT_WORDS; i++)
+            {
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
+              windex++;
+              bitno = windex * BITSET_WORD_BITS;
+            }
+        }
 
       elt = elt->next;
       if (elt)
-	{
-	  windex = elt->index;
-	  bitno = windex * BITSET_WORD_BITS;
-	}
+        {
+          windex = elt->index;
+          bitno = windex * BITSET_WORD_BITS;
+        }
     }
 
   *next = bitno;
@@ -870,7 +870,7 @@ lbitset_empty_p (bitset dst)
     {
       next = elt->next;
       if (!lbitset_elt_zero_p (elt))
-	return 0;
+        return 0;
       /* Weed as we go.  */
       lbitset_elt_unlink (dst, elt);
     }
@@ -903,7 +903,7 @@ lbitset_unused_clear (bitset dst)
       windex++;
 
       for (; (windex - elt->index) < LBITSET_ELT_WORDS; windex++)
-	srcp[windex - elt->index] = 0;
+        srcp[windex - elt->index] = 0;
     }
 }
 
@@ -952,12 +952,12 @@ lbitset_not (bitset dst, bitset src)
   for (i = 0; i < windex; i += LBITSET_ELT_WORDS)
     {
       /* Create new elements for dst if they cannot be found
-	 or substitute zero elements if src elements not found.  */
+         or substitute zero elements if src elements not found.  */
       selt = lbitset_elt_find (src, i, LBITSET_SUBST);
       delt = lbitset_elt_find (dst, i, LBITSET_CREATE);
 
       for (j = 0; j < LBITSET_ELT_WORDS; j++)
-	delt->words[j] = ~selt->words[j];
+        delt->words[j] = ~selt->words[j];
     }
   lbitset_unused_clear (dst);
   lbitset_weed (dst);
@@ -977,26 +977,26 @@ lbitset_subset_p (bitset dst, bitset src)
        selt || delt; selt = selt->next, delt = delt->next)
     {
       if (!selt)
-	selt = &lbitset_zero_elts[0];
+        selt = &lbitset_zero_elts[0];
       else if (!delt)
-	delt = &lbitset_zero_elts[0];
+        delt = &lbitset_zero_elts[0];
       else if (selt->index != delt->index)
-	{
-	  if (selt->index < delt->index)
-	    {
-	      lbitset_zero_elts[2].next = delt;
-	      delt = &lbitset_zero_elts[2];
-	    }
-	  else
-	    {
-	      lbitset_zero_elts[1].next = selt;
-	      selt = &lbitset_zero_elts[1];
-	    }
-	}
+        {
+          if (selt->index < delt->index)
+            {
+              lbitset_zero_elts[2].next = delt;
+              delt = &lbitset_zero_elts[2];
+            }
+          else
+            {
+              lbitset_zero_elts[1].next = selt;
+              selt = &lbitset_zero_elts[1];
+            }
+        }
 
       for (j = 0; j < LBITSET_ELT_WORDS; j++)
-	if (delt->words[j] != (selt->words[j] | delt->words[j]))
-	  return false;
+        if (delt->words[j] != (selt->words[j] | delt->words[j]))
+          return false;
     }
   return true;
 }
@@ -1014,25 +1014,25 @@ lbitset_disjoint_p (bitset dst, bitset src)
        selt && delt; selt = selt->next, delt = delt->next)
     {
       if (selt->index != delt->index)
-	{
-	  if (selt->index < delt->index)
-	    {
-	      lbitset_zero_elts[2].next = delt;
-	      delt = &lbitset_zero_elts[2];
-	    }
-	  else
-	    {
-	      lbitset_zero_elts[1].next = selt;
-	      selt = &lbitset_zero_elts[1];
-	    }
-	  /* Since the elements are different, there is no
-	     intersection of these elements.  */
-	  continue;
-	}
+        {
+          if (selt->index < delt->index)
+            {
+              lbitset_zero_elts[2].next = delt;
+              delt = &lbitset_zero_elts[2];
+            }
+          else
+            {
+              lbitset_zero_elts[1].next = selt;
+              selt = &lbitset_zero_elts[1];
+            }
+          /* Since the elements are different, there is no
+             intersection of these elements.  */
+          continue;
+        }
 
       for (j = 0; j < LBITSET_ELT_WORDS; j++)
-	if (selt->words[j] & delt->words[j])
-	  return false;
+        if (selt->words[j] & delt->words[j])
+          return false;
     }
   return true;
 }
@@ -1065,124 +1065,124 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
   while (selt1 || selt2)
     {
       /* Figure out whether we need to substitute zero elements for
-	 missing links.  */
+         missing links.  */
       if (windex1 == windex2)
-	{
-	  windex = windex1;
-	  stmp1 = selt1;
-	  stmp2 = selt2;
-	  selt1 = selt1->next;
-	  windex1 = (selt1) ? selt1->index : BITSET_WINDEX_MAX;
-	  selt2 = selt2->next;
-	  windex2 = (selt2) ? selt2->index : BITSET_WINDEX_MAX;
-	}
+        {
+          windex = windex1;
+          stmp1 = selt1;
+          stmp2 = selt2;
+          selt1 = selt1->next;
+          windex1 = (selt1) ? selt1->index : BITSET_WINDEX_MAX;
+          selt2 = selt2->next;
+          windex2 = (selt2) ? selt2->index : BITSET_WINDEX_MAX;
+        }
       else if (windex1 < windex2)
-	{
-	  windex = windex1;
-	  stmp1 = selt1;
-	  stmp2 = &lbitset_zero_elts[0];
-	  selt1 = selt1->next;
-	  windex1 = (selt1) ? selt1->index : BITSET_WINDEX_MAX;
-	}
+        {
+          windex = windex1;
+          stmp1 = selt1;
+          stmp2 = &lbitset_zero_elts[0];
+          selt1 = selt1->next;
+          windex1 = (selt1) ? selt1->index : BITSET_WINDEX_MAX;
+        }
       else
-	{
-	  windex = windex2;
-	  stmp1 = &lbitset_zero_elts[0];
-	  stmp2 = selt2;
-	  selt2 = selt2->next;
-	  windex2 = (selt2) ? selt2->index : BITSET_WINDEX_MAX;
-	}
+        {
+          windex = windex2;
+          stmp1 = &lbitset_zero_elts[0];
+          stmp2 = selt2;
+          selt2 = selt2->next;
+          windex2 = (selt2) ? selt2->index : BITSET_WINDEX_MAX;
+        }
 
       /* Find the appropriate element from DST.  Begin by discarding
-	 elements that we've skipped.  */
+         elements that we've skipped.  */
       while (delt && delt->index < windex)
-	{
-	  changed = true;
-	  dtmp = delt;
-	  delt = delt->next;
-	  lbitset_elt_free (dtmp);
-	}
+        {
+          changed = true;
+          dtmp = delt;
+          delt = delt->next;
+          lbitset_elt_free (dtmp);
+        }
       if (delt && delt->index == windex)
-	{
-	  dtmp = delt;
-	  delt = delt->next;
-	}
+        {
+          dtmp = delt;
+          delt = delt->next;
+        }
       else
-	dtmp = lbitset_elt_calloc ();
+        dtmp = lbitset_elt_calloc ();
 
       /* Do the operation, and if any bits are set, link it into the
-	 linked list.  */
+         linked list.  */
       srcp1 = stmp1->words;
       srcp2 = stmp2->words;
       dstp = dtmp->words;
       switch (op)
-	{
-	default:
-	  abort ();
-
-	case BITSET_OP_OR:
-	  for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
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
-	  for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
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
-	  for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
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
-	  for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
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
+          for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
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
+          for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
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
+          for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
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
+          for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
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
 
       if (!lbitset_elt_zero_p (dtmp))
-	{
-	  dtmp->index = windex;
-	  /* Perhaps this could be optimised...  */
-	  lbitset_elt_link (dst, dtmp);
-	}
+        {
+          dtmp->index = windex;
+          /* Perhaps this could be optimised...  */
+          lbitset_elt_link (dst, dtmp);
+        }
       else
-	{
-	  lbitset_elt_free (dtmp);
-	}
+        {
+          lbitset_elt_free (dtmp);
+        }
     }
 
   /* If we have elements of DST left over, free them all.  */
@@ -1390,17 +1390,17 @@ debug_lbitset (bitset bset)
     {
       fprintf (stderr, "Elt %lu\n", (unsigned long int) elt->index);
       for (i = 0; i < LBITSET_ELT_WORDS; i++)
-	{
-	  unsigned int j;
-	  bitset_word word;
-
-	  word = elt->words[i];
-
-	  fprintf (stderr, "  Word %u:", i);
-	  for (j = 0; j < LBITSET_WORD_BITS; j++)
-	    if ((word & ((bitset_word) 1 << j)))
-	      fprintf (stderr, " %u", j);
-	  fprintf (stderr, "\n");
-	}
+        {
+          unsigned int j;
+          bitset_word word;
+
+          word = elt->words[i];
+
+          fprintf (stderr, "  Word %u:", i);
+          for (j = 0; j < LBITSET_WORD_BITS; j++)
+            if ((word & ((bitset_word) 1 << j)))
+              fprintf (stderr, " %u", j);
+          fprintf (stderr, "\n");
+        }
     }
 }
