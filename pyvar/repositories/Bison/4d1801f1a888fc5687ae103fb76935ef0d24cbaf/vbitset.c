@@ -1,5 +1,5 @@
 /* Variable array bitsets.
-   Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -14,7 +14,7 @@
 
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
-   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA. 
+   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
 
 #ifdef HAVE_CONFIG_H
@@ -27,7 +27,7 @@
 
 /* This file implements variable size bitsets stored as a variable
    length array of words.  Any unused bits in the last word must be
-   zero.  
+   zero.
 
    Note that binary or ternary operations assume that each bitset operand
    has the same size.
@@ -38,7 +38,7 @@ static void vbitset_unused_clear (bitset);
 static void vbitset_set (bitset, bitset_bindex);
 static void vbitset_reset (bitset, bitset_bindex);
 static bool vbitset_test (bitset, bitset_bindex);
-static bitset_bindex vbitset_list (bitset, bitset_bindex *, 
+static bitset_bindex vbitset_list (bitset, bitset_bindex *,
 				   bitset_bindex, bitset_bindex *);
 static bitset_bindex vbitset_list_reverse (bitset, bitset_bindex *,
 					   bitset_bindex, bitset_bindex *);
@@ -48,7 +48,8 @@ static bitset_bindex vbitset_list_reverse (bitset, bitset_bindex *,
 #define VBITSET_SIZE(X) ((X)->b.csize)
 #define VBITSET_ASIZE(X) ((X)->v.size)
 
-
+#undef min
+#undef max
 #define min(a, b) ((a) > (b) ? (b) : (a))
 #define max(a, b) ((a) > (b) ? (a) : (b))
 
@@ -68,7 +69,7 @@ vbitset_resize (bitset src, bitset_bindex n_bits)
     {
       bitset_windex size;
 
-      /* The bitset needs to grow.  If we already have enough memory 
+      /* The bitset needs to grow.  If we already have enough memory
 	 allocated, then just zero what we need.  */
       if (newsize > VBITSET_ASIZE (src))
 	{
@@ -81,13 +82,13 @@ vbitset_resize (bitset src, bitset_bindex n_bits)
 	    size = newsize;
 	  else
 	    size = newsize + newsize / 4;
-	  
+
 	  VBITSET_WORDS (src)
 	    = realloc (VBITSET_WORDS (src), size * sizeof (bitset_word));
 	  VBITSET_ASIZE (src) = size;
 	}
 
-      memset (VBITSET_WORDS (src) + oldsize, 0, 
+      memset (VBITSET_WORDS (src) + oldsize, 0,
 	      (newsize - oldsize) * sizeof (bitset_word));
       VBITSET_SIZE (src) = newsize;
     }
@@ -426,7 +427,7 @@ vbitset_not (bitset dst, bitset src)
 	  sizeof (bitset_word) * (dsize - ssize));
 }
 
- 
+
 static bool
 vbitset_equal_p (bitset dst, bitset src)
 {
@@ -465,7 +466,7 @@ vbitset_subset_p (bitset dst, bitset src)
   bitset_word *dstp = VBITSET_WORDS (dst);
   bitset_windex ssize = VBITSET_SIZE (src);
   bitset_windex dsize = VBITSET_SIZE (dst);
-  
+
   for (i = 0; i < min (ssize, dsize); i++, dstp++, srcp++)
       if (*dstp != (*srcp | *dstp))
 	  return 0;
@@ -520,7 +521,7 @@ vbitset_and (bitset dst, bitset src1, bitset src2)
 
   for (i = 0; i < min (ssize1, ssize2); i++)
       *dstp++ = *src1p++ & *src2p++;
-  
+
   memset (dstp, 0, sizeof (bitset_word) * (dsize - min (ssize1, ssize2)));
 }
 
@@ -549,14 +550,14 @@ vbitset_and_cmp (bitset dst, bitset src1, bitset src2)
   for (i = 0; i < min (ssize1, ssize2); i++, dstp++)
     {
       bitset_word tmp = *src1p++ & *src2p++;
-      
+
       if (*dstp != tmp)
 	{
 	  changed = 1;
 	  *dstp = tmp;
 	}
     }
-  
+
   if (ssize2 > ssize1)
     {
       src1p = src2p;
@@ -600,7 +601,7 @@ vbitset_andn (bitset dst, bitset src1, bitset src2)
 
   for (i = 0; i < min (ssize1, ssize2); i++)
       *dstp++ = *src1p++ & ~(*src2p++);
-  
+
   if (ssize2 > ssize1)
     {
       for (; i < ssize2; i++)
@@ -642,14 +643,14 @@ vbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
   for (i = 0; i < min (ssize1, ssize2); i++, dstp++)
     {
       bitset_word tmp = *src1p++ & ~(*src2p++);
-      
+
       if (*dstp != tmp)
 	{
 	  changed = 1;
 	  *dstp = tmp;
 	}
     }
-  
+
   if (ssize2 > ssize1)
     {
       for (; i < ssize2; i++, dstp++)
@@ -668,7 +669,7 @@ vbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
       for (; i < ssize1; i++, dstp++)
 	{
 	  bitset_word tmp = *src1p++;
-	  
+
 	  if (*dstp != tmp)
 	    {
 	      changed = 1;
@@ -705,7 +706,7 @@ vbitset_or (bitset dst, bitset src1, bitset src2)
 
   for (i = 0; i < min (ssize1, ssize2); i++)
       *dstp++ = *src1p++ | *src2p++;
-  
+
   if (ssize2 > ssize1)
     {
       src1p = src2p;
@@ -743,14 +744,14 @@ vbitset_or_cmp (bitset dst, bitset src1, bitset src2)
   for (i = 0; i < min (ssize1, ssize2); i++, dstp++)
     {
       bitset_word tmp = *src1p++ | *src2p++;
-      
+
       if (*dstp != tmp)
 	{
 	  changed = 1;
 	  *dstp = tmp;
 	}
     }
-  
+
   if (ssize2 > ssize1)
     {
       src1p = src2p;
@@ -760,7 +761,7 @@ vbitset_or_cmp (bitset dst, bitset src1, bitset src2)
   for (; i < ssize1; i++, dstp++)
     {
       bitset_word tmp = *src1p++;
-      
+
       if (*dstp != tmp)
 	{
 	  changed = 1;
@@ -796,7 +797,7 @@ vbitset_xor (bitset dst, bitset src1, bitset src2)
 
   for (i = 0; i < min (ssize1, ssize2); i++)
       *dstp++ = *src1p++ ^ *src2p++;
-  
+
   if (ssize2 > ssize1)
     {
       src1p = src2p;
@@ -834,14 +835,14 @@ vbitset_xor_cmp (bitset dst, bitset src1, bitset src2)
   for (i = 0; i < min (ssize1, ssize2); i++, dstp++)
     {
       bitset_word tmp = *src1p++ ^ *src2p++;
-      
+
       if (*dstp != tmp)
 	{
 	  changed = 1;
 	  *dstp = tmp;
 	}
     }
-  
+
   if (ssize2 > ssize1)
     {
       src1p = src2p;
@@ -851,7 +852,7 @@ vbitset_xor_cmp (bitset dst, bitset src1, bitset src2)
   for (; i < ssize1; i++, dstp++)
     {
       bitset_word tmp = *src1p++;
-      
+
       if (*dstp != tmp)
 	{
 	  changed = 1;
@@ -877,7 +878,7 @@ vbitset_and_or (bitset dst, bitset src1, bitset src2, bitset src3)
   bitset_word *src3p;
   bitset_word *dstp;
   bitset_windex size;
-  
+
   if (BITSET_NBITS_ (src1) != BITSET_NBITS_ (src2)
       || BITSET_NBITS_ (src1) != BITSET_NBITS_ (src3))
     {
@@ -908,7 +909,7 @@ vbitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
   bitset_word *src3p;
   bitset_word *dstp;
   bitset_windex size;
-  
+
   if (BITSET_NBITS_ (src1) != BITSET_NBITS_ (src2)
       || BITSET_NBITS_ (src1) != BITSET_NBITS_ (src3))
     return bitset_and_or_cmp_ (dst, src1, src2, src3);
@@ -920,11 +921,11 @@ vbitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
   src3p = VBITSET_WORDS (src3);
   dstp = VBITSET_WORDS (dst);
   size = VBITSET_SIZE (dst);
-  
+
   for (i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ & *src2p++) | *src3p++;
-      
+
       if (*dstp != tmp)
 	{
 	  changed = 1;
@@ -944,7 +945,7 @@ vbitset_andn_or (bitset dst, bitset src1, bitset src2, bitset src3)
   bitset_word *src3p;
   bitset_word *dstp;
   bitset_windex size;
-  
+
   if (BITSET_NBITS_ (src1) != BITSET_NBITS_ (src2)
       || BITSET_NBITS_ (src1) != BITSET_NBITS_ (src3))
     {
@@ -975,7 +976,7 @@ vbitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
   bitset_word *src3p;
   bitset_word *dstp;
   bitset_windex size;
-  
+
   if (BITSET_NBITS_ (src1) != BITSET_NBITS_ (src2)
       || BITSET_NBITS_ (src1) != BITSET_NBITS_ (src3))
     return bitset_andn_or_cmp_ (dst, src1, src2, src3);
@@ -987,11 +988,11 @@ vbitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
   src3p = VBITSET_WORDS (src3);
   dstp = VBITSET_WORDS (dst);
   size = VBITSET_SIZE (dst);
-  
+
   for (i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ & ~(*src2p++)) | *src3p++;
-      
+
       if (*dstp != tmp)
 	{
 	  changed = 1;
@@ -1011,7 +1012,7 @@ vbitset_or_and (bitset dst, bitset src1, bitset src2, bitset src3)
   bitset_word *src3p;
   bitset_word *dstp;
   bitset_windex size;
-  
+
   if (BITSET_NBITS_ (src1) != BITSET_NBITS_ (src2)
       || BITSET_NBITS_ (src1) != BITSET_NBITS_ (src3))
     {
@@ -1026,7 +1027,7 @@ vbitset_or_and (bitset dst, bitset src1, bitset src2, bitset src3)
   src3p = VBITSET_WORDS (src3);
   dstp = VBITSET_WORDS (dst);
   size = VBITSET_SIZE (dst);
-  
+
   for (i = 0; i < size; i++)
       *dstp++ = (*src1p++ | *src2p++) & *src3p++;
 }
@@ -1042,7 +1043,7 @@ vbitset_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
   bitset_word *src3p;
   bitset_word *dstp;
   bitset_windex size;
-  
+
   if (BITSET_NBITS_ (src1) != BITSET_NBITS_ (src2)
       || BITSET_NBITS_ (src1) != BITSET_NBITS_ (src3))
     return bitset_or_and_cmp_ (dst, src1, src2, src3);
@@ -1054,11 +1055,11 @@ vbitset_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
   src3p = VBITSET_WORDS (src3);
   dstp = VBITSET_WORDS (dst);
   size = VBITSET_SIZE (dst);
-  
+
   for (i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ | *src2p++) & *src3p++;
-      
+
       if (*dstp != tmp)
 	{
 	  changed = 1;
