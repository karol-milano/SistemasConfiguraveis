@@ -14,13 +14,14 @@
 
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
-   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
+   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
+*/
 
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
 
-#include "bbitset.h"
+#include "lbitset.h"
 #include "obstack.h"
 #include <stdlib.h>
 
@@ -82,7 +83,7 @@ struct bitset_struct
 enum lbitset_find_mode
   { LBITSET_FIND, LBITSET_CREATE, LBITSET_SUBST };
 
-static lbitset_elt lbitset_zero_elts[3];	/* Elements of all zero bits.  */
+static lbitset_elt lbitset_zero_elts[3]; /* Elements of all zero bits.  */
 
 /* Obstack to allocate bitset elements from.  */
 static struct obstack lbitset_obstack;
@@ -306,7 +307,7 @@ lbitset_elt_link (bset, elt)
      bitset bset;
      lbitset_elt *elt;
 {
-  bitset_windex index = elt->index;
+  bitset_windex windex = elt->index;
   lbitset_elt *ptr;
   lbitset_elt *current;
 
@@ -325,10 +326,10 @@ lbitset_elt_link (bset, elt)
 
   /* If this index is less than that of the current element, it goes
      somewhere before the current element.  */
-  else if (index < bset->b.cindex)
+  else if (windex < bset->b.cindex)
     {
       for (ptr = current;
-	   ptr->prev && ptr->prev->index > index; ptr = ptr->prev)
+	   ptr->prev && ptr->prev->index > windex; ptr = ptr->prev)
 	continue;
 
       if (ptr->prev)
@@ -345,7 +346,7 @@ lbitset_elt_link (bset, elt)
   else
     {
       for (ptr = current;
-	   ptr->next && ptr->next->index < index; ptr = ptr->next)
+	   ptr->next && ptr->next->index < windex; ptr = ptr->next)
 	continue;
 
       if (ptr->next)
@@ -359,16 +360,16 @@ lbitset_elt_link (bset, elt)
     }
 
   /* Set up so this is the first element searched.  */
-  bset->b.cindex = index;
+  bset->b.cindex = windex;
   bset->b.csize = LBITSET_ELT_WORDS;
   bset->b.cdata = elt->words;
 }
 
 
 static lbitset_elt *
-lbitset_elt_find (bset, index, mode)
+lbitset_elt_find (bset, windex, mode)
      bitset bset;
-     bitset_windex index;
+     bitset_windex windex;
      enum lbitset_find_mode mode;
 {
   lbitset_elt *elt;
@@ -378,7 +379,7 @@ lbitset_elt_find (bset, index, mode)
     {
       current = LBITSET_CURRENT (bset);
       /* Check if element is the cached element.  */
-      if ((index - bset->b.cindex) < bset->b.csize)
+      if ((windex - bset->b.cindex) < bset->b.csize)
 	return current;
     }
   else
@@ -388,23 +389,23 @@ lbitset_elt_find (bset, index, mode)
 
   if (current)
     {
-      if (index < bset->b.cindex)
+      if (windex < bset->b.cindex)
 	{
 	  for (elt = current;
-	       elt->prev && elt->index > index; elt = elt->prev)
+	       elt->prev && elt->index > windex; elt = elt->prev)
 	    continue;
 	}
       else
 	{
 	  for (elt = current;
-	       elt->next && (elt->index + LBITSET_ELT_WORDS - 1) < index;
+	       elt->next && (elt->index + LBITSET_ELT_WORDS - 1) < windex;
 	       elt = elt->next)
 	    continue;
 	}
 
       /* `element' is the nearest to the one we want.  If it's not the one
 	 we want, the one we want does not exist.  */
-      if (elt && (index - elt->index) < LBITSET_ELT_WORDS)
+      if (elt && (windex - elt->index) < LBITSET_ELT_WORDS)
 	{
 	  bset->b.cindex = elt->index;
 	  bset->b.csize = LBITSET_ELT_WORDS;
@@ -419,10 +420,10 @@ lbitset_elt_find (bset, index, mode)
       return 0;
 
     case LBITSET_CREATE:
-      index = (index / (unsigned) LBITSET_ELT_WORDS) * LBITSET_ELT_WORDS;
+      windex = (windex / (unsigned) LBITSET_ELT_WORDS) * LBITSET_ELT_WORDS;
 
       elt = lbitset_elt_calloc ();
-      elt->index = index;
+      elt->index = windex;
       lbitset_elt_link (bset, elt);
       return elt;
 
@@ -585,11 +586,11 @@ lbitset_set (dst, bitno)
      bitset dst;
      bitset_bindex bitno;
 {
-  bitset_windex index = bitno / BITSET_WORD_BITS;
+  bitset_windex windex = bitno / BITSET_WORD_BITS;
 
-  lbitset_elt_find (dst, index, LBITSET_CREATE);
+  lbitset_elt_find (dst, windex, LBITSET_CREATE);
 
-  dst->b.cdata[index - dst->b.cindex] |= (1 << (bitno % BITSET_WORD_BITS));
+  dst->b.cdata[windex - dst->b.cindex] |= (1 << (bitno % BITSET_WORD_BITS));
 }
 
 
@@ -599,12 +600,12 @@ lbitset_reset (dst, bitno)
      bitset dst;
      bitset_bindex bitno;
 {
-  bitset_windex index = bitno / BITSET_WORD_BITS;
+  bitset_windex windex = bitno / BITSET_WORD_BITS;
 
-  if (!lbitset_elt_find (dst, index, LBITSET_FIND))
+  if (!lbitset_elt_find (dst, windex, LBITSET_FIND))
     return;
 
-  dst->b.cdata[index - dst->b.cindex] &= ~(1 << (bitno % BITSET_WORD_BITS));
+  dst->b.cdata[windex - dst->b.cindex] &= ~(1 << (bitno % BITSET_WORD_BITS));
 
   /* If all the data is zero, perhaps we should unlink it now...  */
 }
@@ -616,13 +617,13 @@ lbitset_test (src, bitno)
      bitset src;
      bitset_bindex bitno;
 {
-  bitset_windex index = bitno / BITSET_WORD_BITS;
+  bitset_windex windex = bitno / BITSET_WORD_BITS;
 
-  if (!lbitset_elt_find (src, index, LBITSET_FIND))
+  if (!lbitset_elt_find (src, windex, LBITSET_FIND))
     return 0;
 
-  return (src->b.
-	  cdata[index - src->b.cindex] >> (bitno % BITSET_WORD_BITS)) & 1;
+  return (src->b.cdata[windex - src->b.cindex] 
+	  >> (bitno % BITSET_WORD_BITS)) & 1;
 }
 
 
@@ -646,9 +647,9 @@ lbitset_reverse_list (bset, list, num, next)
 {
   bitset_bindex rbitno;
   bitset_bindex bitno;
-  unsigned int bitcnt;
-  bitset_bindex bitoff;
-  bitset_windex index;
+  unsigned int bcount;
+  bitset_bindex boffset;
+  bitset_windex windex;
   bitset_bindex count;
   lbitset_elt *elt;
   bitset_word word;
@@ -666,10 +667,10 @@ lbitset_reverse_list (bset, list, num, next)
 
   bitno = n_bits - (rbitno + 1);
 
-  index = bitno / BITSET_WORD_BITS;
+  windex = bitno / BITSET_WORD_BITS;
 
   /* Skip back to starting element.  */
-  for (; elt && elt->index > index; elt = elt->prev)
+  for (; elt && elt->index > windex; elt = elt->prev)
     continue;
 
   if (!elt)
@@ -679,28 +680,28 @@ lbitset_reverse_list (bset, list, num, next)
      of the word of interest.  */
 
   count = 0;
-  bitcnt = bitno % BITSET_WORD_BITS;
-  bitoff = index * BITSET_WORD_BITS;
+  bcount = bitno % BITSET_WORD_BITS;
+  boffset = windex * BITSET_WORD_BITS;
 
   while (elt)
     {
       bitset_word *srcp = elt->words;
 
-      for (; (index - elt->index) < LBITSET_ELT_WORDS;
-	   index--, bitoff -= BITSET_WORD_BITS,
-	     bitcnt = BITSET_WORD_BITS - 1)
+      for (; (windex - elt->index) < LBITSET_ELT_WORDS;
+	   windex--, boffset -= BITSET_WORD_BITS,
+	     bcount = BITSET_WORD_BITS - 1)
 	{
 	  word =
-	    srcp[index - elt->index] << (BITSET_WORD_BITS - 1 - bitcnt);
+	    srcp[windex - elt->index] << (BITSET_WORD_BITS - 1 - bcount);
 
-	  for (; word; bitcnt--)
+	  for (; word; bcount--)
 	    {
 	      if (word & BITSET_MSB)
 		{
-		  list[count++] = bitoff + bitcnt;
+		  list[count++] = boffset + bcount;
 		  if (count >= num)
 		    {
-		      *next = n_bits - (bitoff + bitcnt);
+		      *next = n_bits - (boffset + bcount);
 		      return count;
 		    }
 		}
@@ -711,12 +712,12 @@ lbitset_reverse_list (bset, list, num, next)
       elt = elt->prev;
       if (elt)
 	{
-	  index = elt->index + LBITSET_ELT_WORDS - 1;
-	  bitoff = index * BITSET_WORD_BITS;
+	  windex = elt->index + LBITSET_ELT_WORDS - 1;
+	  boffset = windex * BITSET_WORD_BITS;
 	}
     }
 
-  *next = n_bits - (bitoff + 1);
+  *next = n_bits - (boffset + 1);
   return count;
 }
 
@@ -732,7 +733,7 @@ lbitset_list (bset, list, num, next)
      bitset_bindex *next;
 {
   bitset_bindex bitno;
-  bitset_windex index;
+  bitset_windex windex;
   bitset_bindex count;
   lbitset_elt *elt;
   lbitset_elt *head;
@@ -751,26 +752,26 @@ lbitset_list (bset, list, num, next)
 
       /* Start with the first element.  */
       elt = head;
-      index = elt->index;
-      bitno = index * BITSET_WORD_BITS;
+      windex = elt->index;
+      bitno = windex * BITSET_WORD_BITS;
     }
   else
     {
-      index = bitno / BITSET_WORD_BITS;
+      windex = bitno / BITSET_WORD_BITS;
 
       /* Skip to starting element.  */
       for (elt = head;
-	   elt && (elt->index + LBITSET_ELT_WORDS - 1) < index;
+	   elt && (elt->index + LBITSET_ELT_WORDS - 1) < windex;
 	   elt = elt->next)
 	continue;
 
       if (!elt)
 	return 0;
 
-      if (index < elt->index)
+      if (windex < elt->index)
 	{
-	  index = elt->index;
-	  bitno = index * BITSET_WORD_BITS;
+	  windex = elt->index;
+	  bitno = windex * BITSET_WORD_BITS;
 	}
       else
 	{
@@ -778,9 +779,9 @@ lbitset_list (bset, list, num, next)
 
 	  /* We are starting within an element.  */
 
-	  for (; (index - elt->index) < LBITSET_ELT_WORDS; index++)
+	  for (; (windex - elt->index) < LBITSET_ELT_WORDS; windex++)
 	    {
-	      word = srcp[index - elt->index] >> (bitno % BITSET_WORD_BITS);
+	      word = srcp[windex - elt->index] >> (bitno % BITSET_WORD_BITS);
 
 	      for (; word; bitno++)
 		{
@@ -795,14 +796,14 @@ lbitset_list (bset, list, num, next)
 		    }
 		  word >>= 1;
 		}
-	      bitno = (index + 1) * BITSET_WORD_BITS;
+	      bitno = (windex + 1) * BITSET_WORD_BITS;
 	    }
 
 	  elt = elt->next;
 	  if (elt)
 	    {
-	      index = elt->index;
-	      bitno = index * BITSET_WORD_BITS;
+	      windex = elt->index;
+	      bitno = windex * BITSET_WORD_BITS;
 	    }
 	}
     }
@@ -841,8 +842,8 @@ lbitset_list (bset, list, num, next)
 		  word >>= 1;
 		}
 	    }
-	  index++;
-	  bitno = index * BITSET_WORD_BITS;
+	  windex++;
+	  bitno = windex * BITSET_WORD_BITS;
 
 	  word = srcp[1];
 	  if (word)
@@ -859,8 +860,8 @@ lbitset_list (bset, list, num, next)
 		  word >>= 1;
 		}
 	    }
-	  index++;
-	  bitno = index * BITSET_WORD_BITS;
+	  windex++;
+	  bitno = windex * BITSET_WORD_BITS;
 #else
 	  for (i = 0; i < LBITSET_ELT_WORDS; i++)
 	    {
@@ -884,8 +885,8 @@ lbitset_list (bset, list, num, next)
 		      word >>= 1;
 		    }
 		}
-	      index++;
-	      bitno = index * BITSET_WORD_BITS;
+	      windex++;
+	      bitno = windex * BITSET_WORD_BITS;
 	    }
 #endif
 	}
@@ -909,16 +910,16 @@ lbitset_list (bset, list, num, next)
 		    }
 		  word >>= 1;
 		}
-	      index++;
-	      bitno = index * BITSET_WORD_BITS;
+	      windex++;
+	      bitno = windex * BITSET_WORD_BITS;
 	    }
 	}
 
       elt = elt->next;
       if (elt)
 	{
-	  index = elt->index;
-	  bitno = index * BITSET_WORD_BITS;
+	  windex = elt->index;
+	  bitno = windex * BITSET_WORD_BITS;
 	}
     }
 
@@ -933,7 +934,7 @@ lbitset_op1 (dst, op)
      enum bitset_ops op;
 {
   unsigned int i;
-  bitset_windex index;
+  bitset_windex windex;
   lbitset_elt *elt;
 
   switch (op)
@@ -950,8 +951,8 @@ lbitset_op1 (dst, op)
       if (!elt)
 	return 0;
 
-      index = elt->index;
-      for (i = 0; i < index; i += LBITSET_ELT_WORDS)
+      windex = elt->index;
+      for (i = 0; i < windex; i += LBITSET_ELT_WORDS)
 	{
 	  /* Create new elements if they cannot be found.  */
 	  elt = lbitset_elt_find (dst, i, LBITSET_CREATE);
@@ -984,7 +985,7 @@ lbitset_op2 (dst, src, op)
   lbitset_elt *delt;
   unsigned int i;
   unsigned int j;
-  bitset_windex index;
+  bitset_windex windex;
 
   switch (op)
     {
@@ -1000,8 +1001,8 @@ lbitset_op2 (dst, src, op)
       if (!elt)
 	return 0;
 
-      index = elt->index;
-      for (i = 0; i < index; i += LBITSET_ELT_WORDS)
+      windex = elt->index;
+      for (i = 0; i < windex; i += LBITSET_ELT_WORDS)
 	{
 	  /* Create new elements for dst if they cannot be found
 	     or substitute zero elements if src elements not found.  */
@@ -1065,6 +1066,9 @@ lbitset_op2 (dst, src, op)
 		  lbitset_zero_elts[1].next = selt;
 		  selt = &lbitset_zero_elts[1];
 		}
+	      /* Since the elements are different, there is no
+		 intersection of these elements.  */
+	      continue;
 	    }
 
 	  for (j = 0; j < LBITSET_ELT_WORDS; j++)
@@ -1091,9 +1095,9 @@ lbitset_op3 (dst, src1, src2, op)
   lbitset_elt *selt1 = LBITSET_HEAD (src1);
   lbitset_elt *selt2 = LBITSET_HEAD (src2);
   lbitset_elt *delt = LBITSET_HEAD (dst);
-  bitset_windex index1;
-  bitset_windex index2;
-  bitset_windex index;
+  bitset_windex windex1;
+  bitset_windex windex2;
+  bitset_windex windex;
   lbitset_elt *stmp1;
   lbitset_elt *stmp2;
   lbitset_elt *dtmp;
@@ -1137,50 +1141,50 @@ lbitset_op3 (dst, src1, src2, op)
   LBITSET_HEAD (dst) = 0;
   dst->b.csize = 0;
 
-  index1 = (selt1) ? selt1->index : BITSET_INDEX_MAX;
-  index2 = (selt2) ? selt2->index : BITSET_INDEX_MAX;
+  windex1 = (selt1) ? selt1->index : BITSET_INDEX_MAX;
+  windex2 = (selt2) ? selt2->index : BITSET_INDEX_MAX;
 
   while (selt1 || selt2)
     {
       /* Figure out whether we need to substitute zero elements for
 	 missing links.  */
-      if (index1 == index2)
+      if (windex1 == windex2)
 	{
-	  index = index1;
+	  windex = windex1;
 	  stmp1 = selt1;
 	  stmp2 = selt2;
 	  selt1 = selt1->next;
-	  index1 = (selt1) ? selt1->index : BITSET_INDEX_MAX;
+	  windex1 = (selt1) ? selt1->index : BITSET_INDEX_MAX;
 	  selt2 = selt2->next;
-	  index2 = (selt2) ? selt2->index : BITSET_INDEX_MAX;
+	  windex2 = (selt2) ? selt2->index : BITSET_INDEX_MAX;
 	}
-      else if (index1 < index2)
+      else if (windex1 < windex2)
 	{
-	  index = index1;
+	  windex = windex1;
 	  stmp1 = selt1;
 	  stmp2 = &lbitset_zero_elts[0];
 	  selt1 = selt1->next;
-	  index1 = (selt1) ? selt1->index : BITSET_INDEX_MAX;
+	  windex1 = (selt1) ? selt1->index : BITSET_INDEX_MAX;
 	}
       else
 	{
-	  index = index2;
+	  windex = windex2;
 	  stmp1 = &lbitset_zero_elts[0];
 	  stmp2 = selt2;
 	  selt2 = selt2->next;
-	  index2 = (selt2) ? selt2->index : BITSET_INDEX_MAX;
+	  windex2 = (selt2) ? selt2->index : BITSET_INDEX_MAX;
 	}
 
       /* Find the appropriate element from DST.  Begin by discarding
 	 elements that we've skipped.  */
-      while (delt && delt->index < index)
+      while (delt && delt->index < windex)
 	{
 	  changed = 1;
 	  dtmp = delt;
 	  delt = delt->next;
 	  lbitset_elt_free (dtmp);
 	}
-      if (delt && delt->index == index)
+      if (delt && delt->index == windex)
 	{
 	  dtmp = delt;
 	  delt = delt->next;
@@ -1247,26 +1251,13 @@ lbitset_op3 (dst, src1, src2, op)
 	    }
 	  break;
 
-	case BITSET_OP_ORN:
-	  for (i = 0; i < LBITSET_ELT_WORDS; i++, dstp++)
-	    {
-	      bitset_word tmp = *srcp1++ | ~(*srcp2++);
-
-	      if (*dstp != tmp)
-		{
-		  changed = 1;
-		  *dstp = tmp;
-		}
-	    }
-	  break;
-
 	default:
 	  abort ();
 	}
 
       if (!lbitset_elt_zero_p (dtmp))
 	{
-	  dtmp->index = index;
+	  dtmp->index = windex;
 	  /* Perhaps this could be optimised...  */
 	  lbitset_elt_link (dst, dtmp);
 	}
