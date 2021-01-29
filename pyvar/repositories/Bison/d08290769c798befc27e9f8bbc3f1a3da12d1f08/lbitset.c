@@ -1,5 +1,5 @@
 /* Functions to support link list bitsets.
-   Copyright (C) 2002 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003 Free Software Foundation, Inc.
    Contributed by Michael Hayes (m.hayes@elec.canterbury.ac.nz).
 
    This program is free software; you can redistribute it and/or modify
@@ -71,7 +71,7 @@ static lbitset_elt lbitset_zero_elts[3]; /* Elements of all zero bits.  */
 
 /* Obstack to allocate bitset elements from.  */
 static struct obstack lbitset_obstack;
-static int lbitset_obstack_init = 0;
+static bool lbitset_obstack_init = false;
 static lbitset_elt *lbitset_free_list;	/* Free list of bitset elements.  */
 
 extern void debug_lbitset PARAMS ((bitset));
@@ -99,7 +99,7 @@ lbitset_elt_alloc (void)
     {
       if (!lbitset_obstack_init)
 	{
-	  lbitset_obstack_init = 1;
+	  lbitset_obstack_init = true;
 
 	  /* Let particular systems override the size of a chunk.  */
 
@@ -236,17 +236,17 @@ lbitset_prune (bitset bset, lbitset_elt *elt)
 }
 
 
-/* Return nonzero if all bits in an element are zero.  */
-static inline int
+/* Are all bits in an element zero?  */
+static inline bool
 lbitset_elt_zero_p (lbitset_elt *elt)
 {
   int i;
 
   for (i = 0; i < LBITSET_ELT_WORDS; i++)
     if (elt->words[i])
-      return 0;
+      return false;
 
-  return 1;
+  return true;
 }
 
 
@@ -412,8 +412,8 @@ lbitset_zero (bitset bset)
 }
 
 
-/* Return 1 if DST == SRC.  */
-static inline int
+/* Is DST == SRC?  */
+static inline bool
 lbitset_equal_p (bitset dst, bitset src)
 {
   lbitset_elt *selt;
@@ -421,7 +421,7 @@ lbitset_equal_p (bitset dst, bitset src)
   int j;
 
   if (src == dst)
-    return 1;
+    return true;
 
   lbitset_weed (src);
   lbitset_weed (dst);
@@ -429,11 +429,11 @@ lbitset_equal_p (bitset dst, bitset src)
        selt && delt; selt = selt->next, delt = delt->next)
     {
       if (selt->index != delt->index)
-	return 0;
+	return false;
 
       for (j = 0; j < LBITSET_ELT_WORDS; j++)
 	if (delt->words[j] != selt->words[j])
-	  return 0;
+	  return false;
     }
   return !selt && !delt;
 }
@@ -480,13 +480,13 @@ lbitset_copy (bitset dst, bitset src)
 }
 
 
-/* Copy bits from bitset SRC to bitset DST.  Return non-zero if
+/* Copy bits from bitset SRC to bitset DST.  Return true if
    bitsets different.  */
-static inline int
+static inline bool
 lbitset_copy_cmp (bitset dst, bitset src)
 {
   if (src == dst)
-    return 0;
+    return false;
 
   if (!LBITSET_HEAD (dst))
     {
@@ -495,10 +495,10 @@ lbitset_copy_cmp (bitset dst, bitset src)
     }
 
   if (lbitset_equal_p (dst, src))
-    return 0;
+    return false;
 
   lbitset_copy (dst, src);
-  return 1;
+  return true;
 }
 
 
@@ -547,16 +547,15 @@ lbitset_reset (bitset dst, bitset_bindex bitno)
 
 
 /* Test bit BITNO in bitset SRC.  */
-static int
+static bool
 lbitset_test (bitset src, bitset_bindex bitno)
 {
   bitset_windex windex = bitno / BITSET_WORD_BITS;
 
-  if (!lbitset_elt_find (src, windex, LBITSET_FIND))
-    return 0;
-
-  return (src->b.cdata[windex - src->b.cindex]
-	  >> (bitno % BITSET_WORD_BITS)) & 1;
+  return (lbitset_elt_find (src, windex, LBITSET_FIND)
+	  && ((src->b.cdata[windex - src->b.cindex]
+	       >> (bitno % BITSET_WORD_BITS))
+	      & 1));
 }
 
 
@@ -865,13 +864,11 @@ lbitset_list (bitset bset, bitset_bindex *list,
 }
 
 
-static int
+static bool
 lbitset_empty_p (bitset dst)
 {
   lbitset_weed (dst);
-  if (LBITSET_HEAD (dst))
-      return 0;
-  return 1;
+  return !LBITSET_HEAD (dst);
 }
 
 
@@ -934,8 +931,8 @@ lbitset_not (bitset dst, bitset src)
 }
 
 
-/* Return 1 if DST == DST | SRC.  */
-static int
+/* Is DST == DST | SRC?  */
+static bool
 lbitset_subset_p (bitset dst, bitset src)
 {
   lbitset_elt *selt;
@@ -965,14 +962,14 @@ lbitset_subset_p (bitset dst, bitset src)
 
       for (j = 0; j < LBITSET_ELT_WORDS; j++)
 	if (delt->words[j] != (selt->words[j] | delt->words[j]))
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
 lbitset_disjoint_p (bitset dst, bitset src)
 {
   lbitset_elt *selt;
@@ -1001,13 +998,13 @@ lbitset_disjoint_p (bitset dst, bitset src)
 
       for (j = 0; j < LBITSET_ELT_WORDS; j++)
 	if (selt->words[j] & delt->words[j])
-	  return 0;
+	  return false;
     }
-  return 1;
+  return true;
 }
 
 
-static int
+static bool
 lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 {
   lbitset_elt *selt1 = LBITSET_HEAD (src1);
@@ -1022,7 +1019,7 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
   bitset_word *srcp1;
   bitset_word *srcp2;
   bitset_word *dstp;
-  int changed = 0;
+  bool changed = false;
   unsigned int i;
 
   LBITSET_HEAD (dst) = 0;
@@ -1066,7 +1063,7 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 	 elements that we've skipped.  */
       while (delt && delt->index < windex)
 	{
-	  changed = 1;
+	  changed = true;
 	  dtmp = delt;
 	  delt = delt->next;
 	  lbitset_elt_free (dtmp);
@@ -1093,7 +1090,7 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 
 	      if (*dstp != tmp)
 		{
-		  changed = 1;
+		  changed = true;
 		  *dstp = tmp;
 		}
 	    }
@@ -1106,7 +1103,7 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 
 	      if (*dstp != tmp)
 		{
-		  changed = 1;
+		  changed = true;
 		  *dstp = tmp;
 		}
 	    }
@@ -1119,7 +1116,7 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 
 	      if (*dstp != tmp)
 		{
-		  changed = 1;
+		  changed = true;
 		  *dstp = tmp;
 		}
 	    }
@@ -1132,7 +1129,7 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 
 	      if (*dstp != tmp)
 		{
-		  changed = 1;
+		  changed = true;
 		  *dstp = tmp;
 		}
 	    }
@@ -1157,7 +1154,7 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
   /* If we have elements of DST left over, free them all.  */
   if (delt)
     {
-      changed = 1;
+      changed = true;
       lbitset_prune (dst, delt);
     }
 
@@ -1165,12 +1162,12 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 }
 
 
-static int
+static bool
 lbitset_and_cmp (bitset dst, bitset src1, bitset src2)
 {
   lbitset_elt *selt1 = LBITSET_HEAD (src1);
   lbitset_elt *selt2 = LBITSET_HEAD (src2);
-  int changed;
+  bool changed;
 
   if (!selt2)
     {
@@ -1197,12 +1194,12 @@ lbitset_and (bitset dst, bitset src1, bitset src2)
 }
 
 
-static int
+static bool
 lbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
 {
   lbitset_elt *selt1 = LBITSET_HEAD (src1);
   lbitset_elt *selt2 = LBITSET_HEAD (src2);
-  int changed;
+  bool changed;
 
   if (!selt2)
     {
@@ -1226,7 +1223,7 @@ lbitset_andn (bitset dst, bitset src1, bitset src2)
 }
 
 
-static int
+static bool
 lbitset_or_cmp (bitset dst, bitset src1, bitset src2)
 {
   lbitset_elt *selt1 = LBITSET_HEAD (src1);
@@ -1251,7 +1248,7 @@ lbitset_or (bitset dst, bitset src1, bitset src2)
 }
 
 
-static int
+static bool
 lbitset_xor_cmp (bitset dst, bitset src1, bitset src2)
 {
   lbitset_elt *selt1 = LBITSET_HEAD (src1);
@@ -1337,7 +1334,7 @@ lbitset_release_memory (void)
   lbitset_free_list = 0;
   if (lbitset_obstack_init)
     {
-      lbitset_obstack_init = 0;
+      lbitset_obstack_init = false;
       obstack_free (&lbitset_obstack, NULL);
     }
 }
