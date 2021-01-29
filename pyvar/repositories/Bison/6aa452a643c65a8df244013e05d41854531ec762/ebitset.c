@@ -77,6 +77,9 @@ typedef struct ebitset_struct
 *ebitset;
 
 
+typedef void(*PFV)();
+
+
 /* Number of elements to initially allocate.  */
 
 #ifndef EBITSET_INITIAL_SIZE
@@ -118,19 +121,24 @@ static int ebitset_elt_zero_p PARAMS ((ebitset_elt *));
 
 static int ebitset_weed PARAMS ((bitset));
 static void ebitset_zero PARAMS ((bitset));
-static int ebitset_equal_p PARAMS ((bitset, bitset));
-static void ebitset_copy PARAMS ((bitset, bitset));
-static int ebitset_copy_compare PARAMS ((bitset, bitset));
+static void ebitset_copy_ PARAMS ((bitset, bitset));
+static int ebitset_copy_cmp PARAMS ((bitset, bitset));
 static void ebitset_set PARAMS ((bitset, bitset_bindex));
 static void ebitset_reset PARAMS ((bitset, bitset_bindex));
 static int ebitset_test PARAMS ((bitset, bitset_bindex));
 static int ebitset_size PARAMS ((bitset));
-static int ebitset_op1 PARAMS ((bitset, enum bitset_ops));
-static int ebitset_op2 PARAMS ((bitset, bitset, enum bitset_ops));
-static int ebitset_op3 PARAMS ((bitset, bitset, bitset, enum bitset_ops));
+static int ebitset_disjoint_p PARAMS ((bitset, bitset));
+static int ebitset_equal_p PARAMS ((bitset, bitset));
+static void ebitset_not PARAMS ((bitset, bitset));
+static int ebitset_subset_p PARAMS ((bitset, bitset));
+static int ebitset_op3_cmp PARAMS ((bitset, bitset, bitset, enum bitset_ops));
+static int ebitset_and_cmp PARAMS ((bitset, bitset, bitset));
+static int ebitset_andn_cmp PARAMS ((bitset, bitset, bitset));
+static int ebitset_or_cmp PARAMS ((bitset, bitset, bitset));
+static int ebitset_xor_cmp PARAMS ((bitset, bitset, bitset));
 static int ebitset_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
 				 bitset_bindex *));
-static int ebitset_reverse_list
+static int ebitset_list_reverse
 PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
 static void ebitset_free PARAMS ((bitset));
 
@@ -141,7 +149,7 @@ static void ebitset_free PARAMS ((bitset));
 #define EBITSET_WORDS(ELT) ((ELT)->u.words)
 
 /* Disable bitset cache and mark BSET as being zero.  */
-#define EBITSET_OP_ZERO_SET(BSET) ((BSET)->b.cindex = BITSET_INDEX_MAX, \
+#define EBITSET_ZERO_SET(BSET) ((BSET)->b.cindex = BITSET_INDEX_MAX, \
         (BSET)->b.cdata = 0)
 
 #define EBITSET_CACHE_DISABLE(BSET)  ((BSET)->b.cindex = BITSET_INDEX_MAX)
@@ -152,7 +160,7 @@ static void ebitset_free PARAMS ((bitset));
 
 /* A conservative estimate of whether the bitset is zero.
    This is non-zero only if we know for sure that the bitset is zero.  */
-#define EBITSET_OP_ZERO_P(BSET) ((BSET)->b.cdata == 0)
+#define EBITSET_ZERO_P(BSET) ((BSET)->b.cdata == 0)
 
 /* Enable cache to point to element with table index EINDEX. 
    The element must exist.  */
@@ -395,7 +403,7 @@ ebitset_weed (bset)
   bitset_windex j;
   int count;
 
-  if (EBITSET_OP_ZERO_P (bset))
+  if (EBITSET_ZERO_P (bset))
     return 0;
 
   elts = EBITSET_ELTS (bset);
@@ -421,7 +429,7 @@ ebitset_weed (bset)
     {
       /* All the bits are zero.  We could shrink the elts. 
 	 For now just mark BSET as known to be zero.  */
-      EBITSET_OP_ZERO_SET (bset);
+      EBITSET_ZERO_SET (bset);
     }
   else
     EBITSET_NONZERO_SET (bset);
@@ -438,7 +446,7 @@ ebitset_zero (bset)
   ebitset_elts *elts;
   bitset_windex j;
 
-  if (EBITSET_OP_ZERO_P (bset))
+  if (EBITSET_ZERO_P (bset))
     return;
 
   elts = EBITSET_ELTS (bset);
@@ -452,7 +460,7 @@ ebitset_zero (bset)
 
   /* All the bits are zero.  We could shrink the elts. 
      For now just mark BSET as known to be zero.  */
-  EBITSET_OP_ZERO_SET (bset);
+  EBITSET_ZERO_SET (bset);
 }
 
 
@@ -498,7 +506,7 @@ ebitset_equal_p (dst, src)
 
 /* Copy bits from bitset SRC to bitset DST.  */
 static inline void
-ebitset_copy (dst, src)
+ebitset_copy_ (dst, src)
      bitset dst;
      bitset src;
 {
@@ -537,23 +545,23 @@ ebitset_copy (dst, src)
 /* Copy bits from bitset SRC to bitset DST.  Return non-zero if
    bitsets different.  */
 static inline int
-ebitset_copy_compare (dst, src)
+ebitset_copy_cmp (dst, src)
      bitset dst;
      bitset src;
 {
   if (src == dst)
     return 0;
 
-  if (EBITSET_OP_ZERO_P (dst))
+  if (EBITSET_ZERO_P (dst))
     {
-      ebitset_copy (dst, src);
-      return !EBITSET_OP_ZERO_P (src);
+      ebitset_copy_ (dst, src);
+      return !EBITSET_ZERO_P (src);
     }
 
   if (ebitset_equal_p (dst, src))
     return 0;
 
-  ebitset_copy (dst, src);
+  ebitset_copy_ (dst, src);
   return 1;
 }
 
@@ -632,7 +640,7 @@ ebitset_free (bset)
  *NEXT and store in array LIST.  Return with actual number of bits
  found and with *NEXT indicating where search stopped.  */
 static int
-ebitset_reverse_list (bset, list, num, next)
+ebitset_list_reverse (bset, list, num, next)
      bitset bset;
      bitset_bindex *list;
      bitset_bindex num;
@@ -650,7 +658,7 @@ ebitset_reverse_list (bset, list, num, next)
   bitset_windex size;
   ebitset_elts *elts;
 
-  if (EBITSET_OP_ZERO_P (bset))
+  if (EBITSET_ZERO_P (bset))
     return 0;
 
   size = EBITSET_SIZE (bset);
@@ -678,20 +686,19 @@ ebitset_reverse_list (bset, list, num, next)
   do
     {
       ebitset_elt *elt;
-
+      bitset_word *srcp;
+      
       elt = elts[eindex];
       if (elt)
-	{
-	  bitset_word *srcp;
-
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
@@ -705,15 +712,13 @@ ebitset_reverse_list (bset, list, num, next)
 		    }
 		  word <<= 1;
 		}
-
 	      boffset -= BITSET_WORD_BITS;
-	      bcount = BITSET_WORD_BITS - 1;
+	      bcount = BITSET_WORD_BITS - 1;	  
 	    }
 	  while (woffset--);
-
-	  woffset = EBITSET_ELT_WORDS;
 	}
 
+      woffset = EBITSET_ELT_WORDS - 1;
       boffset = eindex * EBITSET_ELT_BITS - BITSET_WORD_BITS;
     }
   while (eindex--);
@@ -742,7 +747,7 @@ ebitset_list (bset, list, num, next)
   bitset_word word;
   ebitset_elts *elts;
 
-  if (EBITSET_OP_ZERO_P (bset))
+  if (EBITSET_ZERO_P (bset))
     return 0;
 
   bitno = *next;
@@ -866,156 +871,145 @@ ebitset_list (bset, list, num, next)
 }
 
 
-static int
-ebitset_op1 (dst, op)
+static void
+ebitset_ones (dst)
      bitset dst;
-     enum bitset_ops op;
 {
   bitset_windex j;
   ebitset_elt *elt;
 
-  switch (op)
-    {
-    case BITSET_OP_ZERO:
-      ebitset_zero (dst);
-      return 1;
-
-    case BITSET_OP_ONES:
-      for (j = 0; j < EBITSET_SIZE (dst); j++)
-	{
-	  /* Create new elements if they cannot be found.  Perhaps
-	     we should just add pointers to a ones element.  */
-	  elt =
-	    ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_CREATE);
-	  memset (EBITSET_WORDS (elt), -1, sizeof (EBITSET_WORDS (elt)));
-	}
-      break;
-
-    case BITSET_OP_EMPTY_P:
-      return !ebitset_weed (dst);
 
-    default:
-      abort ();
+  for (j = 0; j < EBITSET_SIZE (dst); j++)
+    {
+      /* Create new elements if they cannot be found.  Perhaps
+	 we should just add pointers to a ones element.  */
+      elt =
+	ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_CREATE);
+      memset (EBITSET_WORDS (elt), -1, sizeof (EBITSET_WORDS (elt)));
     }
-
   EBITSET_NONZERO_SET (dst);
-  return 1;
 }
 
 
 static int
-ebitset_op2 (dst, src, op)
+ebitset_empty_p (dst)
+     bitset dst;
+{
+  return !ebitset_weed (dst);
+}
+
+
+static void
+ebitset_not (dst, src)
      bitset dst;
      bitset src;
-     enum bitset_ops op;
 {
+  unsigned int i;
   ebitset_elt *selt;
   ebitset_elt *delt;
-  unsigned int i;
   bitset_windex j;
 
-  switch (op)
+  for (j = 0; j < EBITSET_SIZE (src); j++)
     {
-    case BITSET_OP_COPY:
-      ebitset_copy (dst, src);
-      break;
-
-    case BITSET_OP_NOT:
-      for (j = 0; j < EBITSET_SIZE (src); j++)
-	{
-	  /* Create new elements for dst if they cannot be found
+      /* Create new elements for dst if they cannot be found
 	     or substitute zero elements if src elements not found.  */
-	  selt =
-	    ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_SUBST);
-	  delt =
-	    ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_CREATE);
+      selt =
+	ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_SUBST);
+      delt =
+	ebitset_elt_find (dst, j * EBITSET_ELT_WORDS, EBITSET_CREATE);
 
-	  for (i = 0; i < EBITSET_ELT_WORDS; i++)
-	    EBITSET_WORDS (delt)[i] = ~EBITSET_WORDS (selt)[i];
-	}
-      break;
-
-      /* Return 1 if DST == SRC.  */
-    case BITSET_OP_EQUAL_P:
-      return ebitset_equal_p (dst, src);
-
-      /* Return 1 if DST == DST | SRC.  */
-    case BITSET_OP_SUBSET_P:
-      {
-	ebitset_elts *selts;
-	ebitset_elts *delts;
-	bitset_windex ssize;
-	bitset_windex dsize;
-
-	selts = EBITSET_ELTS (src);
-	delts = EBITSET_ELTS (dst);
-
-	ssize = EBITSET_SIZE (src);
-	dsize = EBITSET_SIZE (dst);
-
-	for (j = 0; j < ssize; j++)
-	  {
-	    selt = j < ssize ? selts[j] : 0;
-	    delt = j < dsize ? delts[j] : 0;
-
-	    if (!selt && !delt)
-	      continue;
-
-	    if (!selt)
-	      selt = &ebitset_zero_elts[0];
-	    if (!delt)
-	      delt = &ebitset_zero_elts[0];
-
-	    for (i = 0; i < EBITSET_ELT_WORDS; i++)
-	      if (EBITSET_WORDS (delt)[i]
-		  != (EBITSET_WORDS (selt)[i] | EBITSET_WORDS (delt)[i]))
-		return 0;
-	  }
-	return 1;
-      }
-      break;
-
-      /* Return 1 if DST & SRC == 0.  */
-    case BITSET_OP_DISJOINT_P:
-      {
-	ebitset_elts *selts;
-	ebitset_elts *delts;
-	bitset_windex ssize;
-	bitset_windex dsize;
-
-	selts = EBITSET_ELTS (src);
-	delts = EBITSET_ELTS (dst);
-
-	ssize = EBITSET_SIZE (src);
-	dsize = EBITSET_SIZE (dst);
-
-	for (j = 0; j < ssize; j++)
-	  {
-	    selt = j < ssize ? selts[j] : 0;
-	    delt = j < dsize ? delts[j] : 0;
-
-	    if (!selt || !delt)
-	      continue;
-
-	    for (i = 0; i < EBITSET_ELT_WORDS; i++)
-	      if ((EBITSET_WORDS (selt)[i] & EBITSET_WORDS (delt)[i]))
-		return 0;
-	  }
-	return 1;
-      }
-      break;
+      for (i = 0; i < EBITSET_ELT_WORDS; i++)
+	EBITSET_WORDS (delt)[i] = ~EBITSET_WORDS (selt)[i];
+    }
+  EBITSET_NONZERO_SET (dst);
+}  
 
-    default:
-      abort ();
+
+/* Return 1 if DST == DST | SRC.  */
+static int
+ebitset_subset_p (dst, src)
+     bitset dst;
+     bitset src;
+{
+  bitset_windex j;
+  ebitset_elts *selts;
+  ebitset_elts *delts;
+  bitset_windex ssize;
+  bitset_windex dsize;
+  
+  selts = EBITSET_ELTS (src);
+  delts = EBITSET_ELTS (dst);
+  
+  ssize = EBITSET_SIZE (src);
+  dsize = EBITSET_SIZE (dst);
+  
+  for (j = 0; j < ssize; j++)
+    {
+      unsigned int i;
+      ebitset_elt *selt;
+      ebitset_elt *delt;
+
+      selt = j < ssize ? selts[j] : 0;
+      delt = j < dsize ? delts[j] : 0;
+      
+      if (!selt && !delt)
+	continue;
+      
+      if (!selt)
+	selt = &ebitset_zero_elts[0];
+      if (!delt)
+	delt = &ebitset_zero_elts[0];
+      
+      for (i = 0; i < EBITSET_ELT_WORDS; i++)
+	if (EBITSET_WORDS (delt)[i]
+	    != (EBITSET_WORDS (selt)[i] | EBITSET_WORDS (delt)[i]))
+	  return 0;
     }
+  return 1;
+}
 
-  EBITSET_NONZERO_SET (dst);
+
+/* Return 1 if DST & SRC == 0.  */
+static int
+ebitset_disjoint_p (dst, src)
+     bitset dst;
+     bitset src;
+{
+  bitset_windex j;
+  ebitset_elts *selts;
+  ebitset_elts *delts;
+  bitset_windex ssize;
+  bitset_windex dsize;
+  
+  selts = EBITSET_ELTS (src);
+  delts = EBITSET_ELTS (dst);
+  
+  ssize = EBITSET_SIZE (src);
+  dsize = EBITSET_SIZE (dst);
+  
+  for (j = 0; j < ssize; j++)
+    {
+      unsigned int i;
+      ebitset_elt *selt;
+      ebitset_elt *delt;
+
+      selt = j < ssize ? selts[j] : 0;
+      delt = j < dsize ? delts[j] : 0;
+      
+      if (!selt || !delt)
+	continue;
+      
+      for (i = 0; i < EBITSET_ELT_WORDS; i++)
+	if ((EBITSET_WORDS (selt)[i] & EBITSET_WORDS (delt)[i]))
+	  return 0;
+    }
   return 1;
 }
 
 
+
 static int
-ebitset_op3 (dst, src1, src2, op)
+ebitset_op3_cmp (dst, src1, src2, op)
      bitset dst;
      bitset src1;
      bitset src2;
@@ -1035,37 +1029,6 @@ ebitset_op3 (dst, src1, src2, op)
   unsigned int i;
   bitset_windex j;
 
-  /* Fast track common, simple cases.  */
-  if (EBITSET_OP_ZERO_P (src2))
-    {
-      if (op == BITSET_OP_AND)
-	{
-	  ebitset_weed (dst);
-	  changed = EBITSET_OP_ZERO_P (dst);
-	  ebitset_zero (dst);
-	  return changed;
-	}
-      else if (op == BITSET_OP_ANDN || op == BITSET_OP_OR
-	       || op == BITSET_OP_XOR)
-	{
-	  return ebitset_copy_compare (dst, src1);
-	}
-    }
-  else if (EBITSET_OP_ZERO_P (src1))
-    {
-      if (op == BITSET_OP_AND || op == BITSET_OP_ANDN)
-	{
-	  ebitset_weed (dst);
-	  changed = EBITSET_OP_ZERO_P (dst);
-	  ebitset_zero (dst);
-	  return changed;
-	}
-      else if (op == BITSET_OP_OR || op == BITSET_OP_XOR)
-	{
-	  return ebitset_copy_compare (dst, src2);
-	}
-    }
-
   ssize1 = EBITSET_SIZE (src1);
   ssize2 = EBITSET_SIZE (src2);
   dsize = EBITSET_SIZE (dst);
@@ -1198,18 +1161,135 @@ ebitset_op3 (dst, src1, src2, op)
 }
 
 
+static int
+ebitset_and_cmp (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  int changed;
+
+  if (EBITSET_ZERO_P (src2))
+    {
+      ebitset_weed (dst);
+      changed = EBITSET_ZERO_P (dst);
+      ebitset_zero (dst);
+      return changed;
+    }
+  else if (EBITSET_ZERO_P (src1))
+    {
+      ebitset_weed (dst);
+      changed = EBITSET_ZERO_P (dst);
+      ebitset_zero (dst);
+      return changed;
+    }
+  return ebitset_op3_cmp (dst, src1, src2, BITSET_OP_AND);
+}
+
+
+static int
+ebitset_andn_cmp (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  int changed;
+
+  if (EBITSET_ZERO_P (src2))
+    {
+      return ebitset_copy_cmp (dst, src1);
+    }
+  else if (EBITSET_ZERO_P (src1))
+    {
+      ebitset_weed (dst);
+      changed = EBITSET_ZERO_P (dst);
+      ebitset_zero (dst);
+      return changed;
+    }
+  return ebitset_op3_cmp (dst, src1, src2, BITSET_OP_ANDN);
+}
+
+
+static int
+ebitset_or_cmp (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  if (EBITSET_ZERO_P (src2))
+    {
+      return ebitset_copy_cmp (dst, src1);
+    }
+  else if (EBITSET_ZERO_P (src1))
+    {
+      return ebitset_copy_cmp (dst, src2);
+    }
+  return ebitset_op3_cmp (dst, src1, src2, BITSET_OP_OR);
+}
+
+
+static int
+ebitset_xor_cmp (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  if (EBITSET_ZERO_P (src2))
+    {
+      return ebitset_copy_cmp (dst, src1);
+    }
+  else if (EBITSET_ZERO_P (src1))
+    {
+      return ebitset_copy_cmp (dst, src2);
+    }
+  return ebitset_op3_cmp (dst, src1, src2, BITSET_OP_XOR);
+}
+
+
+static void
+ebitset_copy (dst, src)
+     bitset dst;
+     bitset src;
+{
+  if (BITSET_COMPATIBLE_ (dst, src))
+      ebitset_copy_ (dst, src);
+  else
+      bitset_copy_ (dst, src);
+}
+
+
 /* Vector of operations for linked-list bitsets.  */
-struct bitset_ops_struct ebitset_ops = {
+struct bitset_vtable ebitset_vtable = {
   ebitset_set,
   ebitset_reset,
+  bitset_toggle_,
   ebitset_test,
   ebitset_size,
-  ebitset_op1,
-  ebitset_op2,
-  ebitset_op3,
-  bitset_op4,
+  bitset_count_,
+  ebitset_empty_p,
+  ebitset_ones,
+  ebitset_zero,
+  ebitset_copy,
+  ebitset_disjoint_p,
+  ebitset_equal_p,
+  ebitset_not,
+  ebitset_subset_p,
+  (PFV) ebitset_and_cmp,
+  ebitset_and_cmp,
+  (PFV) ebitset_andn_cmp,
+  ebitset_andn_cmp,
+  (PFV) ebitset_or_cmp,
+  ebitset_or_cmp,
+  (PFV) ebitset_xor_cmp,
+  ebitset_xor_cmp,
+  (PFV) bitset_and_or_cmp_,
+  bitset_and_or_cmp_,
+  (PFV) bitset_andn_or_cmp_,
+  bitset_andn_or_cmp_,
+  (PFV) bitset_or_and_cmp_,
+  bitset_or_and_cmp_,
   ebitset_list,
-  ebitset_reverse_list,
+  ebitset_list_reverse,
   ebitset_free,
   BITSET_TABLE
 };
@@ -1233,11 +1313,11 @@ ebitset_init (bset, n_bits)
 {
   unsigned int size;
 
-  bset->b.ops = &ebitset_ops;
+  bset->b.vtable = &ebitset_vtable;
 
   bset->b.csize = EBITSET_ELT_WORDS;
 
-  EBITSET_OP_ZERO_SET (bset);
+  EBITSET_ZERO_SET (bset);
 
   size = n_bits ? (n_bits + EBITSET_ELT_BITS - 1) / EBITSET_ELT_BITS
     : EBITSET_INITIAL_SIZE;
