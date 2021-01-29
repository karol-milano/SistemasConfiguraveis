@@ -73,12 +73,7 @@ vbitset_resize (bitset src, bitset_bindex n_bits)
              grow the bitset 25% larger than requested to reduce
              number of reallocations.  */
 
-          bitset_windex size;
-          if (oldsize == 0)
-            size = newsize;
-          else
-            size = newsize + newsize / 4;
-
+          bitset_windex size = oldsize == 0 ? newsize : newsize + newsize / 4;
           VBITSET_WORDS (src)
             = realloc (VBITSET_WORDS (src), size * sizeof (bitset_word));
           VBITSET_ASIZE (src) = size;
@@ -142,7 +137,7 @@ vbitset_test (bitset src ATTRIBUTE_UNUSED,
 {
   /* We must be accessing outside the cache so the bit is
      zero anyway.  */
-  return 0;
+  return false;
 }
 
 
@@ -206,15 +201,15 @@ static bitset_bindex
 vbitset_list (bitset src, bitset_bindex *list,
               bitset_bindex num, bitset_bindex *next)
 {
-  bitset_windex windex;
-  bitset_bindex bitoff;
   bitset_windex size = VBITSET_SIZE (src);
   bitset_word *srcp = VBITSET_WORDS (src);
-  bitset_word word;
-
   bitset_bindex bitno = *next;
-
   bitset_bindex count = 0;
+
+  bitset_windex windex;
+  bitset_bindex bitoff;
+  bitset_word word;
+
   if (!bitno)
     {
       /* Many bitsets are zero, so make this common case fast.  */
@@ -339,9 +334,8 @@ vbitset_empty_p (bitset dst)
 
   for (unsigned i = 0; i < VBITSET_SIZE (dst); i++)
     if (dstp[i])
-      return 0;
-
-  return 1;
+      return false;
+  return true;
 }
 
 
@@ -349,7 +343,7 @@ static void
 vbitset_copy1 (bitset dst, bitset src)
 {
   if (src == dst)
-      return;
+    return;
 
   vbitset_resize (dst, BITSET_SIZE_ (src));
 
@@ -395,22 +389,22 @@ vbitset_equal_p (bitset dst, bitset src)
   unsigned i;
   for (i = 0; i < min (ssize, dsize); i++)
     if (*srcp++ != *dstp++)
-      return 0;
+      return false;
 
   if (ssize > dsize)
     {
       for (; i < ssize; i++)
         if (*srcp++)
-          return 0;
+          return false;
     }
   else
     {
       for (; i < dsize; i++)
         if (*dstp++)
-          return 0;
+          return false;
     }
 
-  return 1;
+  return true;
 }
 
 
@@ -431,10 +425,10 @@ vbitset_subset_p (bitset dst, bitset src)
     {
       for (; i < ssize; i++)
         if (*srcp++)
-          return 0;
+          return false;
     }
 
-  return 1;
+  return true;
 }
 
 
@@ -448,9 +442,9 @@ vbitset_disjoint_p (bitset dst, bitset src)
 
   for (unsigned i = 0; i < min (ssize, dsize); i++)
     if (*srcp++ & *dstp++)
-      return 0;
+      return false;
 
-  return 1;
+  return true;
 }
 
 
@@ -476,7 +470,7 @@ vbitset_and (bitset dst, bitset src1, bitset src2)
 static bool
 vbitset_and_cmp (bitset dst, bitset src1, bitset src2)
 {
-  int changed = 0;
+  bool changed = false;
   vbitset_resize (dst, max (BITSET_SIZE_ (src1), BITSET_SIZE_ (src2)));
 
   bitset_windex dsize = VBITSET_SIZE (dst);
@@ -493,7 +487,7 @@ vbitset_and_cmp (bitset dst, bitset src1, bitset src2)
 
       if (*dstp != tmp)
         {
-          changed = 1;
+          changed = true;
           *dstp = tmp;
         }
     }
@@ -508,7 +502,7 @@ vbitset_and_cmp (bitset dst, bitset src1, bitset src2)
     {
       if (*dstp != 0)
         {
-          changed = 1;
+          changed = true;
           *dstp = 0;
         }
     }
@@ -555,7 +549,7 @@ vbitset_andn (bitset dst, bitset src1, bitset src2)
 static bool
 vbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 {
-  int changed = 0;
+  bool changed = false;
   vbitset_resize (dst, max (BITSET_SIZE_ (src1), BITSET_SIZE_ (src2)));
 
   bitset_windex dsize = VBITSET_SIZE (dst);
@@ -572,7 +566,7 @@ vbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 
       if (*dstp != tmp)
         {
-          changed = 1;
+          changed = true;
           *dstp = tmp;
         }
     }
@@ -583,7 +577,7 @@ vbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
         {
           if (*dstp != 0)
             {
-              changed = 1;
+              changed = true;
               *dstp = 0;
             }
         }
@@ -598,7 +592,7 @@ vbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 
           if (*dstp != tmp)
             {
-              changed = 1;
+              changed = true;
               *dstp = tmp;
             }
         }
@@ -642,7 +636,7 @@ vbitset_or (bitset dst, bitset src1, bitset src2)
 static bool
 vbitset_or_cmp (bitset dst, bitset src1, bitset src2)
 {
-  int changed = 0;
+  bool changed = false;
 
   vbitset_resize (dst, max (BITSET_SIZE_ (src1), BITSET_SIZE_ (src2)));
 
@@ -660,7 +654,7 @@ vbitset_or_cmp (bitset dst, bitset src1, bitset src2)
 
       if (*dstp != tmp)
         {
-          changed = 1;
+          changed = true;
           *dstp = tmp;
         }
     }
@@ -677,7 +671,7 @@ vbitset_or_cmp (bitset dst, bitset src1, bitset src2)
 
       if (*dstp != tmp)
         {
-          changed = 1;
+          changed = true;
           *dstp = tmp;
         }
     }
@@ -720,7 +714,7 @@ vbitset_xor (bitset dst, bitset src1, bitset src2)
 static bool
 vbitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 {
-  int changed = 0;
+  bool changed = false;
   vbitset_resize (dst, max (BITSET_SIZE_ (src1), BITSET_SIZE_ (src2)));
 
   bitset_windex dsize = VBITSET_SIZE (dst);
@@ -737,7 +731,7 @@ vbitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 
       if (*dstp != tmp)
         {
-          changed = 1;
+          changed = true;
           *dstp = tmp;
         }
     }
@@ -754,7 +748,7 @@ vbitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 
       if (*dstp != tmp)
         {
-          changed = 1;
+          changed = true;
           *dstp = tmp;
         }
     }
@@ -771,12 +765,6 @@ vbitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 static void
 vbitset_and_or (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  bitset_word *src1p;
-  bitset_word *src2p;
-  bitset_word *src3p;
-  bitset_word *dstp;
-  bitset_windex size;
-
   if (BITSET_NBITS_ (src1) != BITSET_NBITS_ (src2)
       || BITSET_NBITS_ (src1) != BITSET_NBITS_ (src3))
     {
@@ -786,11 +774,11 @@ vbitset_and_or (bitset dst, bitset src1, bitset src2, bitset src3)
 
   vbitset_resize (dst, BITSET_NBITS_ (src1));
 
-  src1p = VBITSET_WORDS (src1);
-  src2p = VBITSET_WORDS (src2);
-  src3p = VBITSET_WORDS (src3);
-  dstp = VBITSET_WORDS (dst);
-  size = VBITSET_SIZE (dst);
+  bitset_word *src1p = VBITSET_WORDS (src1);
+  bitset_word *src2p = VBITSET_WORDS (src2);
+  bitset_word *src3p = VBITSET_WORDS (src3);
+  bitset_word *dstp = VBITSET_WORDS (dst);
+  bitset_windex size = VBITSET_SIZE (dst);
 
   for (unsigned i = 0; i < size; i++)
     *dstp++ = (*src1p++ & *src2p++) | *src3p++;
@@ -800,32 +788,26 @@ vbitset_and_or (bitset dst, bitset src1, bitset src2, bitset src3)
 static bool
 vbitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  int changed = 0;
-  bitset_word *src1p;
-  bitset_word *src2p;
-  bitset_word *src3p;
-  bitset_word *dstp;
-  bitset_windex size;
-
   if (BITSET_NBITS_ (src1) != BITSET_NBITS_ (src2)
       || BITSET_NBITS_ (src1) != BITSET_NBITS_ (src3))
     return bitset_and_or_cmp_ (dst, src1, src2, src3);
 
   vbitset_resize (dst, BITSET_NBITS_ (src1));
 
-  src1p = VBITSET_WORDS (src1);
-  src2p = VBITSET_WORDS (src2);
-  src3p = VBITSET_WORDS (src3);
-  dstp = VBITSET_WORDS (dst);
-  size = VBITSET_SIZE (dst);
+  bitset_word *src1p = VBITSET_WORDS (src1);
+  bitset_word *src2p = VBITSET_WORDS (src2);
+  bitset_word *src3p = VBITSET_WORDS (src3);
+  bitset_word *dstp = VBITSET_WORDS (dst);
+  bitset_windex size = VBITSET_SIZE (dst);
 
+  bool changed = false;
   for (unsigned i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ & *src2p++) | *src3p++;
 
       if (*dstp != tmp)
         {
-          changed = 1;
+          changed = true;
           *dstp = tmp;
         }
     }
@@ -836,12 +818,6 @@ vbitset_and_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 static void
 vbitset_andn_or (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  bitset_word *src1p;
-  bitset_word *src2p;
-  bitset_word *src3p;
-  bitset_word *dstp;
-  bitset_windex size;
-
   if (BITSET_NBITS_ (src1) != BITSET_NBITS_ (src2)
       || BITSET_NBITS_ (src1) != BITSET_NBITS_ (src3))
     {
@@ -851,11 +827,11 @@ vbitset_andn_or (bitset dst, bitset src1, bitset src2, bitset src3)
 
   vbitset_resize (dst, BITSET_NBITS_ (src1));
 
-  src1p = VBITSET_WORDS (src1);
-  src2p = VBITSET_WORDS (src2);
-  src3p = VBITSET_WORDS (src3);
-  dstp = VBITSET_WORDS (dst);
-  size = VBITSET_SIZE (dst);
+  bitset_word *src1p = VBITSET_WORDS (src1);
+  bitset_word *src2p = VBITSET_WORDS (src2);
+  bitset_word *src3p = VBITSET_WORDS (src3);
+  bitset_word *dstp = VBITSET_WORDS (dst);
+  bitset_windex size = VBITSET_SIZE (dst);
 
   for (unsigned i = 0; i < size; i++)
     *dstp++ = (*src1p++ & ~(*src2p++)) | *src3p++;
@@ -865,32 +841,26 @@ vbitset_andn_or (bitset dst, bitset src1, bitset src2, bitset src3)
 static bool
 vbitset_andn_or_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  int changed = 0;
-  bitset_word *src1p;
-  bitset_word *src2p;
-  bitset_word *src3p;
-  bitset_word *dstp;
-  bitset_windex size;
-
   if (BITSET_NBITS_ (src1) != BITSET_NBITS_ (src2)
       || BITSET_NBITS_ (src1) != BITSET_NBITS_ (src3))
     return bitset_andn_or_cmp_ (dst, src1, src2, src3);
 
   vbitset_resize (dst, BITSET_NBITS_ (src1));
 
-  src1p = VBITSET_WORDS (src1);
-  src2p = VBITSET_WORDS (src2);
-  src3p = VBITSET_WORDS (src3);
-  dstp = VBITSET_WORDS (dst);
-  size = VBITSET_SIZE (dst);
+  bitset_word *src1p = VBITSET_WORDS (src1);
+  bitset_word *src2p = VBITSET_WORDS (src2);
+  bitset_word *src3p = VBITSET_WORDS (src3);
+  bitset_word *dstp = VBITSET_WORDS (dst);
+  bitset_windex size = VBITSET_SIZE (dst);
 
+  bool changed = false;
   for (unsigned i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ & ~(*src2p++)) | *src3p++;
 
       if (*dstp != tmp)
         {
-          changed = 1;
+          changed = true;
           *dstp = tmp;
         }
     }
@@ -924,33 +894,27 @@ vbitset_or_and (bitset dst, bitset src1, bitset src2, bitset src3)
 static bool
 vbitset_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 {
-  unsigned i;
-  int changed = 0;
-  bitset_word *src1p;
-  bitset_word *src2p;
-  bitset_word *src3p;
-  bitset_word *dstp;
-  bitset_windex size;
-
   if (BITSET_NBITS_ (src1) != BITSET_NBITS_ (src2)
       || BITSET_NBITS_ (src1) != BITSET_NBITS_ (src3))
     return bitset_or_and_cmp_ (dst, src1, src2, src3);
 
   vbitset_resize (dst, BITSET_NBITS_ (src1));
 
-  src1p = VBITSET_WORDS (src1);
-  src2p = VBITSET_WORDS (src2);
-  src3p = VBITSET_WORDS (src3);
-  dstp = VBITSET_WORDS (dst);
-  size = VBITSET_SIZE (dst);
+  bitset_word *src1p = VBITSET_WORDS (src1);
+  bitset_word *src2p = VBITSET_WORDS (src2);
+  bitset_word *src3p = VBITSET_WORDS (src3);
+  bitset_word *dstp = VBITSET_WORDS (dst);
+  bitset_windex size = VBITSET_SIZE (dst);
 
+  unsigned i;
+  bool changed = false;
   for (i = 0; i < size; i++, dstp++)
     {
       bitset_word tmp = (*src1p++ | *src2p++) & *src3p++;
 
       if (*dstp != tmp)
         {
-          changed = 1;
+          changed = true;
           *dstp = tmp;
         }
     }
@@ -962,9 +926,9 @@ static void
 vbitset_copy (bitset dst, bitset src)
 {
   if (BITSET_COMPATIBLE_ (dst, src))
-      vbitset_copy1 (dst, src);
+    vbitset_copy1 (dst, src);
   else
-      bitset_copy_ (dst, src);
+    bitset_copy_ (dst, src);
 }
 
 
@@ -1017,9 +981,7 @@ bitset
 vbitset_init (bitset bset, bitset_bindex n_bits)
 {
   bset->b.vtable = &vbitset_vtable;
-
   bset->b.cindex = 0;
-
   VBITSET_SIZE (bset) = 0;
   vbitset_resize (bset, n_bits);
   return bset;
