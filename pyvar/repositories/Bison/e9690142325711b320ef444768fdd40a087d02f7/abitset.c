@@ -47,7 +47,7 @@ abitset_resize (bitset src, bitset_bindex size)
  found and with *NEXT indicating where search stopped.  */
 static bitset_bindex
 abitset_small_list (bitset src, bitset_bindex *list,
-		    bitset_bindex num, bitset_bindex *next)
+                    bitset_bindex num, bitset_bindex *next)
 {
   bitset_bindex bitno;
   bitset_bindex count;
@@ -73,27 +73,27 @@ abitset_small_list (bitset src, bitset_bindex *list,
   if (num >= BITSET_WORD_BITS)
     {
       for (count = 0; word; bitno++)
-	{
-	  if (word & 1)
-	    list[count++] = bitno;
-	  word >>= 1;
-	}
+        {
+          if (word & 1)
+            list[count++] = bitno;
+          word >>= 1;
+        }
     }
   else
     {
       for (count = 0; word; bitno++)
-	{
-	  if (word & 1)
-	    {
-	      list[count++] = bitno;
-	      if (count >= num)
-		{
-		  bitno++;
-		  break;
-		}
-	    }
-	  word >>= 1;
-	}
+        {
+          if (word & 1)
+            {
+              list[count++] = bitno;
+              if (count >= num)
+                {
+                  bitno++;
+                  break;
+                }
+            }
+          word >>= 1;
+        }
     }
 
   *next = bitno;
@@ -115,7 +115,7 @@ abitset_set (bitset dst ATTRIBUTE_UNUSED, bitset_bindex bitno ATTRIBUTE_UNUSED)
 /* Reset bit BITNO in bitset DST.  */
 static void
 abitset_reset (bitset dst ATTRIBUTE_UNUSED,
-	       bitset_bindex bitno ATTRIBUTE_UNUSED)
+               bitset_bindex bitno ATTRIBUTE_UNUSED)
 {
   /* This should never occur for abitsets since we should always hit
      the cache.  It is likely someone is trying to access outside the
@@ -126,7 +126,7 @@ abitset_reset (bitset dst ATTRIBUTE_UNUSED,
 /* Test bit BITNO in bitset SRC.  */
 static bool
 abitset_test (bitset src ATTRIBUTE_UNUSED,
-	      bitset_bindex bitno ATTRIBUTE_UNUSED)
+              bitset_bindex bitno ATTRIBUTE_UNUSED)
 {
   /* This should never occur for abitsets since we should always
      hit the cache.  */
@@ -140,7 +140,7 @@ abitset_test (bitset src ATTRIBUTE_UNUSED,
    stopped.  */
 static bitset_bindex
 abitset_list_reverse (bitset src, bitset_bindex *list,
-		      bitset_bindex num, bitset_bindex *next)
+                      bitset_bindex num, bitset_bindex *next)
 {
   bitset_bindex bitno;
   bitset_bindex rbitno;
@@ -173,18 +173,18 @@ abitset_list_reverse (bitset src, bitset_bindex *list,
 
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
@@ -200,7 +200,7 @@ abitset_list_reverse (bitset src, bitset_bindex *list,
  found and with *NEXT indicating where search stopped.  */
 static bitset_bindex
 abitset_list (bitset src, bitset_bindex *list,
-	      bitset_bindex num, bitset_bindex *next)
+              bitset_bindex num, bitset_bindex *next)
 {
   bitset_bindex bitno;
   bitset_bindex count;
@@ -217,80 +217,80 @@ abitset_list (bitset src, bitset_bindex *list,
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
@@ -387,7 +387,7 @@ abitset_equal_p (bitset dst, bitset src)
 
   for (i = 0; i < size; i++)
       if (*srcp++ != *dstp++)
-	  return false;
+          return false;
   return true;
 }
 
@@ -402,7 +402,7 @@ abitset_subset_p (bitset dst, bitset src)
 
   for (i = 0; i < size; i++, dstp++, srcp++)
       if (*dstp != (*srcp | *dstp))
-	  return false;
+          return false;
   return true;
 }
 
@@ -417,7 +417,7 @@ abitset_disjoint_p (bitset dst, bitset src)
 
   for (i = 0; i < size; i++)
       if (*srcp++ & *dstp++)
-	  return false;
+          return false;
 
   return true;
 }
@@ -452,10 +452,10 @@ abitset_and_cmp (bitset dst, bitset src1, bitset src2)
       bitset_word tmp = *src1p++ & *src2p++;
 
       if (*dstp != tmp)
-	{
-	  changed = true;
-	  *dstp = tmp;
-	}
+        {
+          changed = true;
+          *dstp = tmp;
+        }
     }
   return changed;
 }
@@ -490,10 +490,10 @@ abitset_andn_cmp (bitset dst, bitset src1, bitset src2)
       bitset_word tmp = *src1p++ & ~(*src2p++);
 
       if (*dstp != tmp)
-	{
-	  changed = true;
-	  *dstp = tmp;
-	}
+        {
+          changed = true;
+          *dstp = tmp;
+        }
     }
   return changed;
 }
@@ -528,10 +528,10 @@ abitset_or_cmp (bitset dst, bitset src1, bitset src2)
       bitset_word tmp = *src1p++ | *src2p++;
 
       if (*dstp != tmp)
-	{
-	  changed = true;
-	  *dstp = tmp;
-	}
+        {
+          changed = true;
+          *dstp = tmp;
+        }
     }
   return changed;
 }
@@ -566,10 +566,10 @@ abitset_xor_cmp (bitset dst, bitset src1, bitset src2)
       bitset_word tmp = *src1p++ ^ *src2p++;
 
       if (*dstp != tmp)
-	{
-	  changed = true;
-	  *dstp = tmp;
-	}
+        {
+          changed = true;
+          *dstp = tmp;
+        }
     }
   return changed;
 }
@@ -606,10 +606,10 @@ abitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
       bitset_word tmp = (*src1p++ & *src2p++) | *src3p++;
 
       if (*dstp != tmp)
-	{
-	  changed = true;
-	  *dstp = tmp;
-	}
+        {
+          changed = true;
+          *dstp = tmp;
+        }
     }
   return changed;
 }
@@ -646,10 +646,10 @@ abitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
       bitset_word tmp = (*src1p++ & ~(*src2p++)) | *src3p++;
 
       if (*dstp != tmp)
-	{
-	  changed = true;
-	  *dstp = tmp;
-	}
+        {
+          changed = true;
+          *dstp = tmp;
+        }
     }
   return changed;
 }
@@ -686,10 +686,10 @@ abitset_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
       bitset_word tmp = (*src1p++ | *src2p++) & *src3p++;
 
       if (*dstp != tmp)
-	{
-	  changed = true;
-	  *dstp = tmp;
-	}
+        {
+          changed = true;
+          *dstp = tmp;
+        }
     }
   return changed;
 }
