@@ -1,5 +1,5 @@
 /* Functions to support expandable bitsets.
-   Copyright (C) 2002 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -88,7 +88,7 @@ static ebitset_elt ebitset_zero_elts[1]; /* Elements of all zero bits.  */
 
 /* Obstack to allocate bitset elements from.  */
 static struct obstack ebitset_obstack;
-static int ebitset_obstack_init = 0;
+static bool ebitset_obstack_init = false;
 static ebitset_elt *ebitset_free_list;	/* Free list of bitset elements.  */
 
 #define EBITSET_ELTS(BSET) ((BSET)->e.elts)
@@ -154,7 +154,7 @@ ebitset_elt_alloc (void)
     {
       if (!ebitset_obstack_init)
 	{
-	  ebitset_obstack_init = 1;
+	  ebitset_obstack_init = true;
 
 	  /* Let particular systems override the size of a chunk.  */
 
@@ -242,17 +242,17 @@ ebitset_elt_add (bitset bset, ebitset_elt *elt, bitset_windex eindex)
 }
 
 
-/* Return nonzero if all bits in an element are zero.  */
-static inline int
+/* Are all bits in an element zero?  */
+static inline bool
 ebitset_elt_zero_p (ebitset_elt *elt)
 {
   int i;
 
   for (i = 0; i < EBITSET_ELT_WORDS; i++)
     if (EBITSET_WORDS (elt)[i])
-      return 0;
+      return false;
 
-  return 1;
+  return true;
 }
 
 
@@ -402,7 +402,7 @@ ebitset_zero (bitset bset)
 }
 
 
-static inline int
+static inline bool
 ebitset_equal_p (bitset dst, bitset src)
 {
   ebitset_elts *selts;
@@ -410,13 +410,13 @@ ebitset_equal_p (bitset dst, bitset src)
   bitset_windex j;
 
   if (src == dst)
-    return 1;
+    return true;
 
   ebitset_weed (dst);
   ebitset_weed (src);
 
   if (EBITSET_SIZE (src) != EBITSET_SIZE (dst))
-    return 0;
+    return false;
 
   selts = EBITSET_ELTS (src);
   delts = EBITSET_ELTS (dst);
@@ -430,13 +430,13 @@ ebitset_equal_p (bitset dst, bitset src)
       if (!selt && !delt)
 	continue;
       if ((selt && !delt) || (!selt && delt))
-	return 0;
+	return false;
 
       for (i = 0; i < EBITSET_ELT_WORDS; i++)
 	if (EBITSET_WORDS (selt)[i] != EBITSET_WORDS (delt)[i])
-	  return 0;
+	  return false;
     }
-  return 1;
+  return true;
 }
 
 
@@ -476,13 +476,13 @@ ebitset_copy_ (bitset dst, bitset src)
 }
 
 
-/* Copy bits from bitset SRC to bitset DST.  Return non-zero if
+/* Copy bits from bitset SRC to bitset DST.  Return true if
    bitsets different.  */
-static inline int
+static inline bool
 ebitset_copy_cmp (bitset dst, bitset src)
 {
   if (src == dst)
-    return 0;
+    return false;
 
   if (EBITSET_ZERO_P (dst))
     {
@@ -491,10 +491,10 @@ ebitset_copy_cmp (bitset dst, bitset src)
     }
 
   if (ebitset_equal_p (dst, src))
-    return 0;
+    return false;
 
   ebitset_copy_ (dst, src);
-  return 1;
+  return true;
 }
 
 
@@ -539,16 +539,15 @@ ebitset_reset (bitset dst, bitset_bindex bitno)
 
 
 /* Test bit BITNO in bitset SRC.  */
-static int
+static bool
 ebitset_test (bitset src, bitset_bindex bitno)
 {
   bitset_windex windex = bitno / BITSET_WORD_BITS;
 
-  if (!ebitset_elt_find (src, windex, EBITSET_FIND))
-    return 0;
-
-  return (src->b.
-	  cdata[windex - src->b.cindex] >> (bitno % BITSET_WORD_BITS)) & 1;
+  return (ebitset_elt_find (src, windex, EBITSET_FIND)
+	  && ((src->b.cdata[windex - src->b.cindex]
+	       >> (bitno % BITSET_WORD_BITS))
+	      & 1));
 }
 
 
@@ -808,7 +807,7 @@ ebitset_ones (bitset dst)
 }
 
 
-static int
+static bool
 ebitset_empty_p (bitset dst)
 {
   return !ebitset_weed (dst);
@@ -839,8 +838,8 @@ ebitset_not (bitset dst, bitset src)
 }
 
 
-/* Return 1 if DST == DST | SRC.  */
-static int
+/* Is DST == DST | SRC?  */
+static bool
 ebitset_subset_p (bitset dst, bitset src)
 {
   bitset_windex j;
@@ -875,14 +874,14 @@ ebitset_subset_p (bitset dst, bitset src)
       for (i = 0; i < EBITSET_ELT_WORDS; i++)
 	if (EBITSET_WORDS (delt)[i]
 	    != (EBITSET_WORDS (selt)[i] | EBITSET_WORDS (delt)[i]))
-	  return 0;
+	  return false;
     }
-  return 1;
+  return true;
 }
 
 
-/* Return 1 if DST & SRC == 0.  */
-static int
+/* Is DST & SRC == 0?  */
+static bool
 ebitset_disjoint_p (bitset dst, bitset src)
 {
   bitset_windex j;
@@ -911,14 +910,14 @@ ebitset_disjoint_p (bitset dst, bitset src)
 
       for (i = 0; i < EBITSET_ELT_WORDS; i++)
 	if ((EBITSET_WORDS (selt)[i] & EBITSET_WORDS (delt)[i]))
-	  return 0;
+	  return false;
     }
-  return 1;
+  return true;
 }
 
 
 
-static int
+static bool
 ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 {
   bitset_windex ssize1;
@@ -931,7 +930,7 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
   bitset_word *srcp1;
   bitset_word *srcp2;
   bitset_word *dstp;
-  int changed = 0;
+  bool changed = false;
   unsigned int i;
   bitset_windex j;
 
@@ -963,7 +962,7 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 	{
 	  if (delt)
 	    {
-	      changed = 1;
+	      changed = true;
 	      ebitset_elt_remove (dst, j);
 	    }
 	  continue;
@@ -990,7 +989,7 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 
 	      if (*dstp != tmp)
 		{
-		  changed = 1;
+		  changed = true;
 		  *dstp = tmp;
 		}
 	    }
@@ -1003,7 +1002,7 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 
 	      if (*dstp != tmp)
 		{
-		  changed = 1;
+		  changed = true;
 		  *dstp = tmp;
 		}
 	    }
@@ -1016,7 +1015,7 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 
 	      if (*dstp != tmp)
 		{
-		  changed = 1;
+		  changed = true;
 		  *dstp = tmp;
 		}
 	    }
@@ -1029,7 +1028,7 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 
 	      if (*dstp != tmp)
 		{
-		  changed = 1;
+		  changed = true;
 		  *dstp = tmp;
 		}
 	    }
@@ -1054,7 +1053,7 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
     {
       ebitset_elt *delt;
 
-      changed = 1;
+      changed = true;
 
       delt = delts[j];
 
@@ -1067,10 +1066,10 @@ ebitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 }
 
 
-static int
+static bool
 ebitset_and_cmp (bitset dst, bitset src1, bitset src2)
 {
-  int changed;
+  bool changed;
 
   if (EBITSET_ZERO_P (src2))
     {
@@ -1097,10 +1096,10 @@ ebitset_and (bitset dst, bitset src1, bitset src2)
 }
 
 
-static int
+static bool
 ebitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 {
-  int changed;
+  bool changed;
 
   if (EBITSET_ZERO_P (src2))
     {
@@ -1124,7 +1123,7 @@ ebitset_andn (bitset dst, bitset src1, bitset src2)
 }
 
 
-static int
+static bool
 ebitset_or_cmp (bitset dst, bitset src1, bitset src2)
 {
   if (EBITSET_ZERO_P (src2))
@@ -1146,7 +1145,7 @@ ebitset_or (bitset dst, bitset src1, bitset src2)
 }
 
 
-static int
+static bool
 ebitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 {
   if (EBITSET_ZERO_P (src2))
@@ -1253,7 +1252,7 @@ ebitset_release_memory (void)
   ebitset_free_list = 0;
   if (ebitset_obstack_init)
     {
-      ebitset_obstack_init = 0;
+      ebitset_obstack_init = false;
       obstack_free (&ebitset_obstack, NULL);
     }
 }
