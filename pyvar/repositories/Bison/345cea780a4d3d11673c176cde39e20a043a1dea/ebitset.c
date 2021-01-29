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
+#include "ebitset.h"
 #include "obstack.h"
 #include <stdlib.h>
 
@@ -311,9 +312,9 @@ ebitset_elt_zero_p (elt)
 
 
 static ebitset_elt *
-ebitset_elt_find (bset, index, mode)
+ebitset_elt_find (bset, windex, mode)
      bitset bset;
-     bitset_windex index;
+     bitset_windex windex;
      enum ebitset_find_mode mode;
 {
   ebitset_elt *elt;
@@ -321,15 +322,13 @@ ebitset_elt_find (bset, index, mode)
   unsigned int eindex;
   ebitset_elts *elts;
 
-  eindex = index / EBITSET_ELT_WORDS;
+  eindex = windex / EBITSET_ELT_WORDS;
 
   elts = EBITSET_ELTS (bset);
   size = EBITSET_SIZE (bset);
 
   if (eindex < size)
     {
-      ebitset_elt *elt;
-
       if ((elt = elts[eindex]))
 	{
 	  if (EBITSET_WORDS (elt) == bset->b.cdata)
@@ -581,11 +580,11 @@ ebitset_set (dst, bitno)
      bitset dst;
      bitset_bindex bitno;
 {
-  bitset_windex index = bitno / BITSET_WORD_BITS;
+  bitset_windex windex = bitno / BITSET_WORD_BITS;
 
-  ebitset_elt_find (dst, index, EBITSET_CREATE);
+  ebitset_elt_find (dst, windex, EBITSET_CREATE);
 
-  dst->b.cdata[index - dst->b.cindex] |= (1 << (bitno % BITSET_WORD_BITS));
+  dst->b.cdata[windex - dst->b.cindex] |= (1 << (bitno % BITSET_WORD_BITS));
 }
 
 
@@ -595,15 +594,15 @@ ebitset_reset (dst, bitno)
      bitset dst;
      bitset_bindex bitno;
 {
-  bitset_windex index = bitno / BITSET_WORD_BITS;
+  bitset_windex windex = bitno / BITSET_WORD_BITS;
 
-  if (!ebitset_elt_find (dst, index, EBITSET_FIND))
+  if (!ebitset_elt_find (dst, windex, EBITSET_FIND))
     return;
 
-  dst->b.cdata[index - dst->b.cindex] &= ~(1 << (bitno % BITSET_WORD_BITS));
+  dst->b.cdata[windex - dst->b.cindex] &= ~(1 << (bitno % BITSET_WORD_BITS));
 
   /* If all the data is zero, perhaps we should remove it now... 
-     However, there could be a good chance that the element will be needed
+     However, there is a good chance that the element will be needed
      again soon.  */
 }
 
@@ -614,13 +613,13 @@ ebitset_test (src, bitno)
      bitset src;
      bitset_bindex bitno;
 {
-  bitset_windex index = bitno / BITSET_WORD_BITS;
+  bitset_windex windex = bitno / BITSET_WORD_BITS;
 
-  if (!ebitset_elt_find (src, index, EBITSET_FIND))
+  if (!ebitset_elt_find (src, windex, EBITSET_FIND))
     return 0;
 
   return (src->b.
-	  cdata[index - src->b.cindex] >> (bitno % BITSET_WORD_BITS)) & 1;
+	  cdata[windex - src->b.cindex] >> (bitno % BITSET_WORD_BITS)) & 1;
 }
 
 
@@ -646,11 +645,11 @@ ebitset_reverse_list (bset, list, num, next)
   bitset_bindex n_bits;
   bitset_bindex bitno;
   bitset_bindex rbitno;
-  unsigned int bitcnt;
-  bitset_bindex bitoff;
-  bitset_windex index;
-  unsigned int eindex;
+  unsigned int bcount;
+  bitset_bindex boffset;
   bitset_windex windex;
+  unsigned int eindex;
+  bitset_windex woffset;
   bitset_bindex count;
   bitset_windex size;
   bitset_word word;
@@ -670,18 +669,19 @@ ebitset_reverse_list (bset, list, num, next)
 
   bitno = n_bits - (rbitno + 1);
 
-  index = bitno / BITSET_WORD_BITS;
+  windex = bitno / BITSET_WORD_BITS;
   eindex = bitno / EBITSET_ELT_BITS;
-  windex = index - eindex * EBITSET_ELT_WORDS;
+  woffset = windex - eindex * EBITSET_ELT_WORDS;
 
   /* If num is 1, we could speed things up with a binary search
      of the word of interest.  */
 
   count = 0;
-  bitcnt = bitno % BITSET_WORD_BITS;
-  bitoff = index * BITSET_WORD_BITS;
+  bcount = bitno % BITSET_WORD_BITS;
+  boffset = windex * BITSET_WORD_BITS;
 
-  for (; eindex != ~0U; eindex--)
+  for (; eindex != ~0U; 
+       boffset = eindex * EBITSET_ELT_BITS - BITSET_WORD_BITS, eindex--) 
     {
       ebitset_elt *elt;
       bitset_word *srcp;
@@ -692,19 +692,19 @@ ebitset_reverse_list (bset, list, num, next)
 
       srcp = EBITSET_WORDS (elt);
 
-      for (; windex != ~0U; windex--, bitoff -= BITSET_WORD_BITS,
-	     bitcnt = BITSET_WORD_BITS - 1)
+      for (; woffset != ~0U; woffset--, boffset -= BITSET_WORD_BITS,
+	     bcount = BITSET_WORD_BITS - 1)
 	{
-	  word = srcp[windex] << (BITSET_WORD_BITS - 1 - bitcnt);
+	  word = srcp[woffset] << (BITSET_WORD_BITS - 1 - bcount);
 
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
@@ -712,10 +712,10 @@ ebitset_reverse_list (bset, list, num, next)
 	    }
 	}
 
-      windex = EBITSET_ELT_WORDS;
+      woffset = EBITSET_ELT_WORDS;
     }
 
-  *next = n_bits - (bitoff + 1);
+  *next = n_bits - (boffset + 1);
   return count;
 }
 
@@ -731,7 +731,7 @@ ebitset_list (bset, list, num, next)
      bitset_bindex *next;
 {
   bitset_bindex bitno;
-  bitset_windex index;
+  bitset_windex windex;
   unsigned int eindex;
   bitset_bindex count;
   bitset_windex size;
@@ -756,15 +756,15 @@ ebitset_list (bset, list, num, next)
       elt = elts[eindex];
       if (elt)
 	{
-	  bitset_windex windex;
+	  bitset_windex woffset;
 	  bitset_word *srcp = EBITSET_WORDS (elt);
 
-	  index = bitno / BITSET_WORD_BITS;
-	  windex = eindex / EBITSET_ELT_WORDS;
+	  windex = bitno / BITSET_WORD_BITS;
+	  woffset = eindex / EBITSET_ELT_WORDS;
 
-	  for (; (index - windex) < EBITSET_ELT_WORDS; index++)
+	  for (; (windex - woffset) < EBITSET_ELT_WORDS; windex++)
 	    {
-	      word = srcp[index - windex] >> (bitno % BITSET_WORD_BITS);
+	      word = srcp[windex - woffset] >> (bitno % BITSET_WORD_BITS);
 
 	      for (; word; bitno++)
 		{
@@ -779,7 +779,7 @@ ebitset_list (bset, list, num, next)
 		    }
 		  word >>= 1;
 		}
-	      bitno = (index + 1) * BITSET_WORD_BITS;
+	      bitno = (windex + 1) * BITSET_WORD_BITS;
 	    }
 	}
 
@@ -793,7 +793,6 @@ ebitset_list (bset, list, num, next)
   for (; eindex < size; eindex++)
     {
       int i;
-      ebitset_elt *elt;
       bitset_word *srcp;
 
       elt = elts[eindex];
@@ -801,15 +800,15 @@ ebitset_list (bset, list, num, next)
 	continue;
 
       srcp = EBITSET_WORDS (elt);
-      index = eindex * EBITSET_ELT_WORDS;
+      windex = eindex * EBITSET_ELT_WORDS;
 
       if ((count + EBITSET_ELT_BITS) < num)
 	{
 	  /* The coast is clear, plant boot!  */
 
-	  for (i = 0; i < EBITSET_ELT_WORDS; i++, index++)
+	  for (i = 0; i < EBITSET_ELT_WORDS; i++, windex++)
 	    {
-	      bitno = index * BITSET_WORD_BITS;
+	      bitno = windex * BITSET_WORD_BITS;
 
 	      word = srcp[i];
 	      if (word)
@@ -838,9 +837,9 @@ ebitset_list (bset, list, num, next)
 	  /* Tread more carefully since we need to check
 	     if array overflows.  */
 
-	  for (i = 0; i < EBITSET_ELT_WORDS; i++, index++)
+	  for (i = 0; i < EBITSET_ELT_WORDS; i++, windex++)
 	    {
-	      bitno = index * BITSET_WORD_BITS;
+	      bitno = windex * BITSET_WORD_BITS;
 
 	      for (word = srcp[i]; word; bitno++)
 		{
@@ -953,9 +952,6 @@ ebitset_op2 (dst, src, op)
 
 	for (j = 0; j < ssize; j++)
 	  {
-	    ebitset_elt *selt;
-	    ebitset_elt *delt;
-
 	    selt = j < ssize ? selts[j] : 0;
 	    delt = j < dsize ? delts[j] : 0;
 
@@ -992,20 +988,12 @@ ebitset_op2 (dst, src, op)
 
 	for (j = 0; j < ssize; j++)
 	  {
-	    ebitset_elt *selt;
-	    ebitset_elt *delt;
-
 	    selt = j < ssize ? selts[j] : 0;
 	    delt = j < dsize ? delts[j] : 0;
 
-	    if (!selt && !delt)
+	    if (!selt || !delt)
 	      continue;
 
-	    if (!selt)
-	      selt = &ebitset_zero_elts[0];
-	    if (!delt)
-	      delt = &ebitset_zero_elts[0];
-
 	    for (i = 0; i < EBITSET_ELT_WORDS; i++)
 	      if ((EBITSET_WORDS (selt)[i] & EBITSET_WORDS (delt)[i]))
 		return 0;
@@ -1175,19 +1163,6 @@ ebitset_op3 (dst, src1, src2, op)
 	    }
 	  break;
 
-	case BITSET_OP_ORN:
-	  for (i = 0; i < EBITSET_ELT_WORDS; i++, dstp++)
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
