@@ -14,7 +14,7 @@
 
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
-   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. 
+   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
 
 #ifdef HAVE_CONFIG_H
@@ -37,12 +37,12 @@
    Bitsets are commonly empty so we need to ensure that this special
    case is fast.  A zero bitset is indicated when cdata is 0.  This is
    conservative since cdata may be non zero and the bitset may still
-   be zero. 
+   be zero.
 
    The bitset cache can be disabled either by setting cindex to
-   BITSET_WINDEX_MAX or by setting csize to 0.  Here 
+   BITSET_WINDEX_MAX or by setting csize to 0.  Here
    we use the former approach since cindex needs to be updated whenever
-   cdata is changed.   
+   cdata is changed.
 */
 
 
@@ -83,7 +83,6 @@ typedef ebitset_elt *ebitset_elts;
 
 enum ebitset_find_mode
   { EBITSET_FIND, EBITSET_CREATE, EBITSET_SUBST };
-typedef int enum_ebitset_find_mode;
 
 static ebitset_elt ebitset_zero_elts[1]; /* Elements of all zero bits.  */
 
@@ -92,47 +91,6 @@ static struct obstack ebitset_obstack;
 static int ebitset_obstack_init = 0;
 static ebitset_elt *ebitset_free_list;	/* Free list of bitset elements.  */
 
-static void ebitset_elts_grow PARAMS ((bitset, bitset_windex));
-static ebitset_elt *ebitset_elt_alloc PARAMS ((void));
-static ebitset_elt *ebitset_elt_calloc PARAMS ((void));
-static void ebitset_elt_add PARAMS ((bitset, ebitset_elt *, bitset_windex));
-static void ebitset_elt_remove PARAMS ((bitset, bitset_windex));
-static void ebitset_elt_free PARAMS ((ebitset_elt *));
-static ebitset_elt *ebitset_elt_find PARAMS ((bitset, bitset_windex,
-					      enum_ebitset_find_mode));
-static ebitset_elt *ebitset_elt_last PARAMS ((bitset));
-static int ebitset_elt_zero_p PARAMS ((ebitset_elt *));
-
-static bitset_windex ebitset_weed PARAMS ((bitset));
-static void ebitset_zero PARAMS ((bitset));
-static void ebitset_copy_ PARAMS ((bitset, bitset));
-static int ebitset_copy_cmp PARAMS ((bitset, bitset));
-static void ebitset_set PARAMS ((bitset, bitset_bindex));
-static void ebitset_reset PARAMS ((bitset, bitset_bindex));
-static int ebitset_test PARAMS ((bitset, bitset_bindex));
-static bitset_bindex ebitset_size PARAMS ((bitset));
-static int ebitset_disjoint_p PARAMS ((bitset, bitset));
-static int ebitset_equal_p PARAMS ((bitset, bitset));
-static void ebitset_not PARAMS ((bitset, bitset));
-static int ebitset_subset_p PARAMS ((bitset, bitset));
-static int ebitset_op3_cmp PARAMS ((bitset, bitset, bitset, enum_bitset_ops));
-static void ebitset_and PARAMS ((bitset, bitset, bitset));
-static int ebitset_and_cmp PARAMS ((bitset, bitset, bitset));
-static void ebitset_andn PARAMS ((bitset, bitset, bitset));
-static int ebitset_andn_cmp PARAMS ((bitset, bitset, bitset));
-static void ebitset_or PARAMS ((bitset, bitset, bitset));
-static int ebitset_or_cmp PARAMS ((bitset, bitset, bitset));
-static void ebitset_xor PARAMS ((bitset, bitset, bitset));
-static int ebitset_xor_cmp PARAMS ((bitset, bitset, bitset));
-static void ebitset_copy PARAMS ((bitset, bitset));
-static bitset_bindex ebitset_list PARAMS ((bitset, bitset_bindex *,
-					   bitset_bindex, bitset_bindex *));
-static bitset_bindex ebitset_list_reverse
-PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
-static void ebitset_ones PARAMS ((bitset));
-static int ebitset_empty_p PARAMS ((bitset));
-static void ebitset_free PARAMS ((bitset));
-
 #define EBITSET_ELTS(BSET) ((BSET)->e.elts)
 #define EBITSET_SIZE(BSET) ((BSET)->e.size)
 
@@ -141,7 +99,7 @@ static void ebitset_free PARAMS ((bitset));
 
 /* Disable bitset cache and mark BSET as being zero.  */
 #define EBITSET_ZERO_SET(BSET) ((BSET)->b.cindex = BITSET_WINDEX_MAX, \
-        (BSET)->b.cdata = 0)
+	(BSET)->b.cdata = 0)
 
 #define EBITSET_CACHE_DISABLE(BSET)  ((BSET)->b.cindex = BITSET_WINDEX_MAX)
 
@@ -153,7 +111,7 @@ static void ebitset_free PARAMS ((bitset));
    This is non-zero only if we know for sure that the bitset is zero.  */
 #define EBITSET_ZERO_P(BSET) ((BSET)->b.cdata == 0)
 
-/* Enable cache to point to element with table index EINDEX. 
+/* Enable cache to point to element with table index EINDEX.
    The element must exist.  */
 #define EBITSET_CACHE_SET(BSET, EINDEX) \
  ((BSET)->b.cindex = (EINDEX) * EBITSET_ELT_WORDS, \
@@ -162,9 +120,7 @@ static void ebitset_free PARAMS ((bitset));
 
 /* Grow the expandable table for BSET by SIZE elements.  */
 static void
-ebitset_elts_grow (bset, size)
-     bitset bset;
-     bitset_windex size;
+ebitset_elts_grow (bitset bset, bitset_windex size)
 {
   bitset_windex oldsize;
   bitset_windex newsize;
@@ -185,7 +141,7 @@ ebitset_elts_grow (bset, size)
 
 /* Allocate a ebitset element.  The bits are not cleared.  */
 static inline ebitset_elt *
-ebitset_elt_alloc ()
+ebitset_elt_alloc (void)
 {
   ebitset_elt *elt;
 
@@ -240,7 +196,7 @@ ebitset_elt_alloc ()
 
 /* Allocate a ebitset element.  The bits are cleared.  */
 static inline ebitset_elt *
-ebitset_elt_calloc ()
+ebitset_elt_calloc (void)
 {
   ebitset_elt *elt;
 
@@ -251,8 +207,7 @@ ebitset_elt_calloc ()
 
 
 static inline void
-ebitset_elt_free (elt)
-     ebitset_elt *elt;
+ebitset_elt_free (ebitset_elt *elt)
 {
   EBITSET_NEXT (elt) = ebitset_free_list;
   ebitset_free_list = elt;
@@ -261,9 +216,7 @@ ebitset_elt_free (elt)
 
 /* Remove element with index EINDEX from bitset BSET.  */
 static inline void
-ebitset_elt_remove (bset, eindex)
-     bitset bset;
-     bitset_windex eindex;
+ebitset_elt_remove (bitset bset, bitset_windex eindex)
 {
   ebitset_elts *elts;
   ebitset_elt *elt;
@@ -279,10 +232,7 @@ ebitset_elt_remove (bset, eindex)
 
 /* Add ELT into elts at index EINDEX of bitset BSET.  */
 static inline void
-ebitset_elt_add (bset, elt, eindex)
-     bitset bset;
-     ebitset_elt *elt;
-     bitset_windex eindex;
+ebitset_elt_add (bitset bset, ebitset_elt *elt, bitset_windex eindex)
 {
   ebitset_elts *elts;
 
@@ -294,8 +244,7 @@ ebitset_elt_add (bset, elt, eindex)
 
 /* Return nonzero if all bits in an element are zero.  */
 static inline int
-ebitset_elt_zero_p (elt)
-     ebitset_elt *elt;
+ebitset_elt_zero_p (ebitset_elt *elt)
 {
   int i;
 
@@ -308,10 +257,8 @@ ebitset_elt_zero_p (elt)
 
 
 static ebitset_elt *
-ebitset_elt_find (bset, windex, mode)
-     bitset bset;
-     bitset_windex windex;
-     enum_ebitset_find_mode mode;
+ebitset_elt_find (bitset bset, bitset_windex windex,
+		  enum ebitset_find_mode mode)
 {
   ebitset_elt *elt;
   bitset_windex size;
@@ -376,8 +323,7 @@ ebitset_elt_find (bset, windex, mode)
 
 
 static inline ebitset_elt *
-ebitset_elt_last (bset)
-     bitset bset;
+ebitset_elt_last (bitset bset)
 {
   ebitset_elts *elts;
 
@@ -390,8 +336,7 @@ ebitset_elt_last (bset)
 
 /* Weed out the zero elements from the elts.  */
 static inline bitset_windex
-ebitset_weed (bset)
-     bitset bset;
+ebitset_weed (bitset bset)
 {
   ebitset_elts *elts;
   bitset_windex j;
@@ -421,7 +366,7 @@ ebitset_weed (bset)
   count = j - count;
   if (!count)
     {
-      /* All the bits are zero.  We could shrink the elts. 
+      /* All the bits are zero.  We could shrink the elts.
 	 For now just mark BSET as known to be zero.  */
       EBITSET_ZERO_SET (bset);
     }
@@ -434,8 +379,7 @@ ebitset_weed (bset)
 
 /* Set all bits in the bitset to zero.  */
 static inline void
-ebitset_zero (bset)
-     bitset bset;
+ebitset_zero (bitset bset)
 {
   ebitset_elts *elts;
   bitset_windex j;
@@ -452,16 +396,14 @@ ebitset_zero (bset)
 	ebitset_elt_remove (bset, j);
     }
 
-  /* All the bits are zero.  We could shrink the elts. 
+  /* All the bits are zero.  We could shrink the elts.
      For now just mark BSET as known to be zero.  */
   EBITSET_ZERO_SET (bset);
 }
 
 
 static inline int
-ebitset_equal_p (dst, src)
-     bitset dst;
-     bitset src;
+ebitset_equal_p (bitset dst, bitset src)
 {
   ebitset_elts *selts;
   ebitset_elts *delts;
@@ -500,9 +442,7 @@ ebitset_equal_p (dst, src)
 
 /* Copy bits from bitset SRC to bitset DST.  */
 static inline void
-ebitset_copy_ (dst, src)
-     bitset dst;
-     bitset src;
+ebitset_copy_ (bitset dst, bitset src)
 {
   ebitset_elts *selts;
   ebitset_elts *delts;
@@ -539,9 +479,7 @@ ebitset_copy_ (dst, src)
 /* Copy bits from bitset SRC to bitset DST.  Return non-zero if
    bitsets different.  */
 static inline int
-ebitset_copy_cmp (dst, src)
-     bitset dst;
-     bitset src;
+ebitset_copy_cmp (bitset dst, bitset src)
 {
   if (src == dst)
     return 0;
@@ -562,8 +500,7 @@ ebitset_copy_cmp (dst, src)
 
 /* Return size in bits of bitset SRC.  */
 static bitset_bindex
-ebitset_size (src)
-     bitset src;
+ebitset_size (bitset src)
 {
   /* Return current size of bitset in bits.  */
   return EBITSET_SIZE (src) * EBITSET_ELT_BITS;
@@ -572,9 +509,7 @@ ebitset_size (src)
 
 /* Set bit BITNO in bitset DST.  */
 static void
-ebitset_set (dst, bitno)
-     bitset dst;
-     bitset_bindex bitno;
+ebitset_set (bitset dst, bitset_bindex bitno)
 {
   bitset_windex windex = bitno / BITSET_WORD_BITS;
 
@@ -587,9 +522,7 @@ ebitset_set (dst, bitno)
 
 /* Reset bit BITNO in bitset DST.  */
 static void
-ebitset_reset (dst, bitno)
-     bitset dst;
-     bitset_bindex bitno;
+ebitset_reset (bitset dst, bitset_bindex bitno)
 {
   bitset_windex windex = bitno / BITSET_WORD_BITS;
 
@@ -599,7 +532,7 @@ ebitset_reset (dst, bitno)
   dst->b.cdata[windex - dst->b.cindex] &=
     ~((bitset_word) 1 << (bitno % BITSET_WORD_BITS));
 
-  /* If all the data is zero, perhaps we should remove it now... 
+  /* If all the data is zero, perhaps we should remove it now...
      However, there is a good chance that the element will be needed
      again soon.  */
 }
@@ -607,9 +540,7 @@ ebitset_reset (dst, bitno)
 
 /* Test bit BITNO in bitset SRC.  */
 static int
-ebitset_test (src, bitno)
-     bitset src;
-     bitset_bindex bitno;
+ebitset_test (bitset src, bitset_bindex bitno)
 {
   bitset_windex windex = bitno / BITSET_WORD_BITS;
 
@@ -622,8 +553,7 @@ ebitset_test (src, bitno)
 
 
 static void
-ebitset_free (bset)
-     bitset bset;
+ebitset_free (bitset bset)
 {
   ebitset_zero (bset);
   free (EBITSET_ELTS (bset));
@@ -634,11 +564,8 @@ ebitset_free (bset)
  *NEXT and store in array LIST.  Return with actual number of bits
  found and with *NEXT indicating where search stopped.  */
 static bitset_bindex
-ebitset_list_reverse (bset, list, num, next)
-     bitset bset;
-     bitset_bindex *list;
-     bitset_bindex num;
-     bitset_bindex *next;
+ebitset_list_reverse (bitset bset, bitset_bindex *list,
+		      bitset_bindex num, bitset_bindex *next)
 {
   bitset_bindex n_bits;
   bitset_bindex bitno;
@@ -681,18 +608,18 @@ ebitset_list_reverse (bset, list, num, next)
     {
       ebitset_elt *elt;
       bitset_word *srcp;
-      
+
       elt = elts[eindex];
       if (elt)
-	{      
+	{
 	  srcp = EBITSET_WORDS (elt);
-	  
+
 	  do
 	    {
 	      bitset_word word;
-	      
+
 	      word = srcp[woffset] << (BITSET_WORD_BITS - 1 - bcount);
-	      
+
 	      for (; word; bcount--)
 		{
 		  if (word & BITSET_MSB)
@@ -707,7 +634,7 @@ ebitset_list_reverse (bset, list, num, next)
 		  word <<= 1;
 		}
 	      boffset -= BITSET_WORD_BITS;
-	      bcount = BITSET_WORD_BITS - 1;	  
+	      bcount = BITSET_WORD_BITS - 1;
 	    }
 	  while (woffset--);
 	}
@@ -726,11 +653,8 @@ ebitset_list_reverse (bset, list, num, next)
  *NEXT and store in array LIST.  Return with actual number of bits
  found and with *NEXT indicating where search stopped.  */
 static bitset_bindex
-ebitset_list (bset, list, num, next)
-     bitset bset;
-     bitset_bindex *list;
-     bitset_bindex num;
-     bitset_bindex *next;
+ebitset_list (bitset bset, bitset_bindex *list,
+	      bitset_bindex num, bitset_bindex *next)
 {
   bitset_bindex bitno;
   bitset_windex windex;
@@ -866,8 +790,7 @@ ebitset_list (bset, list, num, next)
 
 
 static void
-ebitset_ones (dst)
-     bitset dst;
+ebitset_ones (bitset dst)
 {
   bitset_windex j;
   ebitset_elt *elt;
@@ -886,17 +809,14 @@ ebitset_ones (dst)
 
 
 static int
-ebitset_empty_p (dst)
-     bitset dst;
+ebitset_empty_p (bitset dst)
 {
   return !ebitset_weed (dst);
 }
 
 
 static void
-ebitset_not (dst, src)
-     bitset dst;
-     bitset src;
+ebitset_not (bitset dst, bitset src)
 {
   unsigned int i;
   ebitset_elt *selt;
@@ -916,27 +836,25 @@ ebitset_not (dst, src)
 	EBITSET_WORDS (delt)[i] = ~EBITSET_WORDS (selt)[i];
     }
   EBITSET_NONZERO_SET (dst);
-}  
+}
 
 
 /* Return 1 if DST == DST | SRC.  */
 static int
-ebitset_subset_p (dst, src)
-     bitset dst;
-     bitset src;
+ebitset_subset_p (bitset dst, bitset src)
 {
   bitset_windex j;
   ebitset_elts *selts;
   ebitset_elts *delts;
   bitset_windex ssize;
   bitset_windex dsize;
-  
+
   selts = EBITSET_ELTS (src);
   delts = EBITSET_ELTS (dst);
-  
+
   ssize = EBITSET_SIZE (src);
   dsize = EBITSET_SIZE (dst);
-  
+
   for (j = 0; j < ssize; j++)
     {
       unsigned int i;
@@ -945,15 +863,15 @@ ebitset_subset_p (dst, src)
 
       selt = j < ssize ? selts[j] : 0;
       delt = j < dsize ? delts[j] : 0;
-      
+
       if (!selt && !delt)
 	continue;
-      
+
       if (!selt)
 	selt = &ebitset_zero_elts[0];
       if (!delt)
 	delt = &ebitset_zero_elts[0];
-      
+
       for (i = 0; i < EBITSET_ELT_WORDS; i++)
 	if (EBITSET_WORDS (delt)[i]
 	    != (EBITSET_WORDS (selt)[i] | EBITSET_WORDS (delt)[i]))
@@ -965,22 +883,20 @@ ebitset_subset_p (dst, src)
 
 /* Return 1 if DST & SRC == 0.  */
 static int
-ebitset_disjoint_p (dst, src)
-     bitset dst;
-     bitset src;
+ebitset_disjoint_p (bitset dst, bitset src)
 {
   bitset_windex j;
   ebitset_elts *selts;
   ebitset_elts *delts;
   bitset_windex ssize;
   bitset_windex dsize;
-  
+
   selts = EBITSET_ELTS (src);
   delts = EBITSET_ELTS (dst);
-  
+
   ssize = EBITSET_SIZE (src);
   dsize = EBITSET_SIZE (dst);
-  
+
   for (j = 0; j < ssize; j++)
     {
       unsigned int i;
@@ -989,10 +905,10 @@ ebitset_disjoint_p (dst, src)
 
       selt = j < ssize ? selts[j] : 0;
       delt = j < dsize ? delts[j] : 0;
-      
+
       if (!selt || !delt)
 	continue;
-      
+
       for (i = 0; i < EBITSET_ELT_WORDS; i++)
 	if ((EBITSET_WORDS (selt)[i] & EBITSET_WORDS (delt)[i]))
 	  return 0;
@@ -1003,11 +919,7 @@ ebitset_disjoint_p (dst, src)
 
 
 static int
-ebitset_op3_cmp (dst, src1, src2, op)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-     enum_bitset_ops op;
+ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 {
   bitset_windex ssize1;
   bitset_windex ssize2;
@@ -1155,21 +1067,8 @@ ebitset_op3_cmp (dst, src1, src2, op)
 }
 
 
-static void
-ebitset_and (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-{
-  ebitset_and_cmp (dst, src1, src2);
-}
-
-
 static int
-ebitset_and_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+ebitset_and_cmp (bitset dst, bitset src1, bitset src2)
 {
   int changed;
 
@@ -1192,20 +1091,14 @@ ebitset_and_cmp (dst, src1, src2)
 
 
 static void
-ebitset_andn (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+ebitset_and (bitset dst, bitset src1, bitset src2)
 {
-  ebitset_andn_cmp (dst, src1, src2);
+  ebitset_and_cmp (dst, src1, src2);
 }
 
 
 static int
-ebitset_andn_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+ebitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 {
   int changed;
 
@@ -1225,20 +1118,14 @@ ebitset_andn_cmp (dst, src1, src2)
 
 
 static void
-ebitset_or (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+ebitset_andn (bitset dst, bitset src1, bitset src2)
 {
-  ebitset_or_cmp (dst, src1, src2);
+  ebitset_andn_cmp (dst, src1, src2);
 }
 
 
 static int
-ebitset_or_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+ebitset_or_cmp (bitset dst, bitset src1, bitset src2)
 {
   if (EBITSET_ZERO_P (src2))
     {
@@ -1253,20 +1140,14 @@ ebitset_or_cmp (dst, src1, src2)
 
 
 static void
-ebitset_xor (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+ebitset_or (bitset dst, bitset src1, bitset src2)
 {
-  ebitset_xor_cmp (dst, src1, src2);
+  ebitset_or_cmp (dst, src1, src2);
 }
 
 
 static int
-ebitset_xor_cmp (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
+ebitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 {
   if (EBITSET_ZERO_P (src2))
     {
@@ -1281,9 +1162,14 @@ ebitset_xor_cmp (dst, src1, src2)
 
 
 static void
-ebitset_copy (dst, src)
-     bitset dst;
-     bitset src;
+ebitset_xor (bitset dst, bitset src1, bitset src2)
+{
+  ebitset_xor_cmp (dst, src1, src2);
+}
+
+
+static void
+ebitset_copy (bitset dst, bitset src)
 {
   if (BITSET_COMPATIBLE_ (dst, src))
       ebitset_copy_ (dst, src);
@@ -1331,8 +1217,7 @@ struct bitset_vtable ebitset_vtable = {
 
 /* Return size of initial structure.  */
 size_t
-ebitset_bytes (n_bits)
-     bitset_bindex n_bits ATTRIBUTE_UNUSED;
+ebitset_bytes (bitset_bindex n_bits ATTRIBUTE_UNUSED)
 {
   return sizeof (struct ebitset_struct);
 }
@@ -1341,9 +1226,7 @@ ebitset_bytes (n_bits)
 /* Initialize a bitset.  */
 
 bitset
-ebitset_init (bset, n_bits)
-     bitset bset;
-     bitset_bindex n_bits;
+ebitset_init (bitset bset, bitset_bindex n_bits)
 {
   bitset_windex size;
 
@@ -1365,7 +1248,7 @@ ebitset_init (bset, n_bits)
 
 
 void
-ebitset_release_memory ()
+ebitset_release_memory (void)
 {
   ebitset_free_list = 0;
   if (ebitset_obstack_init)
