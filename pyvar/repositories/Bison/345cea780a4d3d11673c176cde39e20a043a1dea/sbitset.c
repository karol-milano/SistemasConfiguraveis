@@ -14,7 +14,8 @@
 
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
-   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
+   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. 
+*/
 
 #ifdef HAVE_CONFIG_H
 #include "config.h"
@@ -184,7 +185,7 @@ sbitset_reverse_list (src, list, num, next)
   bitset_bindex bitno;
   bitset_bindex rbitno;
   bitset_bindex count;
-  bitset_windex index;
+  bitset_windex windex;
   unsigned int bitcnt;
   bitset_bindex bitoff;
   bitset_word word;
@@ -203,14 +204,14 @@ sbitset_reverse_list (src, list, num, next)
 
   bitno = n_bits - (rbitno + 1);
 
-  index = bitno / BITSET_WORD_BITS;
+  windex = bitno / BITSET_WORD_BITS;
   bitcnt = bitno % BITSET_WORD_BITS;
-  bitoff = index * BITSET_WORD_BITS;
+  bitoff = windex * BITSET_WORD_BITS;
 
-  for (; index != ~0U; index--, bitoff -= BITSET_WORD_BITS,
+  for (; windex != ~0U; windex--, bitoff -= BITSET_WORD_BITS,
 	 bitcnt = BITSET_WORD_BITS - 1)
     {
-      word = srcp[index] << (BITSET_WORD_BITS - 1 - bitcnt);
+      word = srcp[windex] << (BITSET_WORD_BITS - 1 - bitcnt);
       for (; word; bitcnt--)
 	{
 	  if (word & BITSET_MSB)
@@ -243,7 +244,7 @@ sbitset_list (src, list, num, next)
 {
   bitset_bindex bitno;
   bitset_bindex count;
-  bitset_windex index;
+  bitset_windex windex;
   bitset_bindex bitoff;
   bitset_windex size = src->b.csize;
   bitset_word *srcp = SBITSET_WORDS (src);
@@ -255,22 +256,22 @@ sbitset_list (src, list, num, next)
   if (!bitno)
     {
       /* Many bitsets are zero, so make this common case fast.  */
-      for (index = 0; index < size && !srcp[index]; index++)
+      for (windex = 0; windex < size && !srcp[windex]; windex++)
 	continue;
-      if (index >= size)
+      if (windex >= size)
 	return 0;
 
       /* If num is 1, we could speed things up with a binary search
 	 of the current word.  */
 
-      bitoff = index * BITSET_WORD_BITS;
+      bitoff = windex * BITSET_WORD_BITS;
     }
   else
     {
       if (bitno >= SBITSET_N_BITS (src))
 	return 0;
 
-      index = bitno / BITSET_WORD_BITS;
+      windex = bitno / BITSET_WORD_BITS;
       bitno = bitno % BITSET_WORD_BITS;
 
       if (bitno)
@@ -280,8 +281,8 @@ sbitset_list (src, list, num, next)
 	     with many set bits where we filled the array
 	     on the previous call to this function.  */
 
-	  bitoff = index * BITSET_WORD_BITS;
-	  word = srcp[index] >> bitno;
+	  bitoff = windex * BITSET_WORD_BITS;
+	  word = srcp[windex] >> bitno;
 	  for (bitno = bitoff + bitno; word; bitno++)
 	    {
 	      if (word & 1)
@@ -295,14 +296,14 @@ sbitset_list (src, list, num, next)
 		}
 	      word >>= 1;
 	    }
-	  index++;
+	  windex++;
 	}
-      bitoff = index * BITSET_WORD_BITS;
+      bitoff = windex * BITSET_WORD_BITS;
     }
 
-  for (; index < size; index++, bitoff += BITSET_WORD_BITS)
+  for (; windex < size; windex++, bitoff += BITSET_WORD_BITS)
     {
-      if (!(word = srcp[index]))
+      if (!(word = srcp[windex]))
 	continue;
 
       if ((count + BITSET_WORD_BITS) < num)
@@ -519,20 +520,6 @@ sbitset_op3 (dst, src1, src2, op)
 	}
       break;
 
-    case BITSET_OP_ORN:
-      for (i = 0; i < size; i++, dstp++)
-	{
-	  bitset_word tmp = *src1p++ | ~(*src2p++);
-
-	  if (*dstp != tmp)
-	    {
-	      changed = 1;
-	      *dstp = tmp;
-	    }
-	}
-      sbitset_unused_clear (dst);
-      break;
-
     default:
       abort ();
     }
