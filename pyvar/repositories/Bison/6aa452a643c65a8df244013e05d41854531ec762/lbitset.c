@@ -24,6 +24,7 @@
 #include "lbitset.h"
 #include "obstack.h"
 #include <stdlib.h>
+#include <stdio.h>
 
 /* This file implements linked-list bitsets.  These bitsets can be of
    arbitrary length and are more efficient than arrays of bits for
@@ -78,6 +79,9 @@ struct bitset_struct
 };
 
 
+typedef void(*PFV)();
+
+
 enum lbitset_find_mode
   { LBITSET_FIND, LBITSET_CREATE, LBITSET_SUBST };
 
@@ -102,17 +106,15 @@ static void lbitset_weed PARAMS ((bitset));
 static void lbitset_zero PARAMS ((bitset));
 static int lbitset_equal_p PARAMS ((bitset, bitset));
 static void lbitset_copy PARAMS ((bitset, bitset));
-static int lbitset_copy_compare PARAMS ((bitset, bitset));
+static int lbitset_copy_cmp PARAMS ((bitset, bitset));
 static void lbitset_set PARAMS ((bitset, bitset_bindex));
 static void lbitset_reset PARAMS ((bitset, bitset_bindex));
 static int lbitset_test PARAMS ((bitset, bitset_bindex));
 static int lbitset_size PARAMS ((bitset));
-static int lbitset_op1 PARAMS ((bitset, enum bitset_ops));
-static int lbitset_op2 PARAMS ((bitset, bitset, enum bitset_ops));
-static int lbitset_op3 PARAMS ((bitset, bitset, bitset, enum bitset_ops));
+static int lbitset_op3_cmp PARAMS ((bitset, bitset, bitset, enum bitset_ops));
 static int lbitset_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
 				 bitset_bindex *));
-static int lbitset_reverse_list
+static int lbitset_list_reverse
 PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
 static void lbitset_free PARAMS ((bitset));
 
@@ -398,7 +400,7 @@ lbitset_elt_find (bset, windex, mode)
 	    continue;
 	}
 
-      /* `element' is the nearest to the one we want.  If it's not the one
+      /* ELT is the nearest to the one we want.  If it's not the one
 	 we want, the one we want does not exist.  */
       if (elt && (windex - elt->index) < LBITSET_ELT_WORDS)
 	{
@@ -449,7 +451,7 @@ lbitset_weed (bset)
 
 
 /* Set all bits in the bitset to zero.  */
-static inline void
+static void
 lbitset_zero (bset)
      bitset bset;
 {
@@ -464,6 +466,7 @@ lbitset_zero (bset)
 }
 
 
+/* Return 1 if DST == SRC.  */
 static inline int
 lbitset_equal_p (dst, src)
      bitset dst;
@@ -538,7 +541,7 @@ lbitset_copy (dst, src)
 /* Copy bits from bitset SRC to bitset DST.  Return non-zero if
    bitsets different.  */
 static inline int
-lbitset_copy_compare (dst, src)
+lbitset_copy_cmp (dst, src)
      bitset dst;
      bitset src;
 {
@@ -636,7 +639,7 @@ lbitset_free (bset)
  *NEXT and store in array LIST.  Return with actual number of bits
  found and with *NEXT indicating where search stopped.  */
 static int
-lbitset_reverse_list (bset, list, num, next)
+lbitset_list_reverse (bset, list, num, next)
      bitset bset;
      bitset_bindex *list;
      bitset_bindex num;
@@ -673,13 +676,24 @@ lbitset_reverse_list (bset, list, num, next)
   if (!elt)
     return 0;
 
-  /* If num is 1, we could speed things up with a binary search
-     of the word of interest.  */
+  if (windex >= elt->index + LBITSET_ELT_WORDS)
+    {
+      /* We are trying to start in no-mans land so start
+	 at end of current elt.  */
+      bcount = BITSET_WORD_BITS - 1;
+      windex = elt->index + LBITSET_ELT_WORDS - 1;
+    }
+  else
+    {
+      bcount = bitno % BITSET_WORD_BITS;
+    }
 
   count = 0;
-  bcount = bitno % BITSET_WORD_BITS;
   boffset = windex * BITSET_WORD_BITS;
 
+  /* If num is 1, we could speed things up with a binary search
+     of the word of interest.  */
+
   while (elt)
     {
       bitset_word *srcp = elt->words;
@@ -926,56 +940,47 @@ lbitset_list (bset, list, num, next)
 
 
 static int
-lbitset_op1 (dst, op)
+lbitset_empty_p (dst)
+     bitset dst;
+{
+  lbitset_weed (dst);
+  if (LBITSET_HEAD (dst))
+      return 0;
+  return 1;
+}
+
+
+static void
+lbitset_ones (dst)
      bitset dst;
-     enum bitset_ops op;
 {
   unsigned int i;
   bitset_windex windex;
   lbitset_elt *elt;
 
-  switch (op)
+  /* This is a decidedly unfriendly operation for a linked list
+      bitset!  It makes a sparse bitset become dense.  An alternative
+      is to have a flag that indicates that the bitset stores the
+      complement of what it indicates.  */
+  elt = LBITSET_TAIL (dst);
+  /* Ignore empty set.  */
+  if (!elt)
+    return;
+  
+  windex = elt->index;
+  for (i = 0; i < windex; i += LBITSET_ELT_WORDS)
     {
-    case BITSET_OP_ZERO:
-      lbitset_zero (dst);
-      break;
-
-    case BITSET_OP_ONES:
-      /* This is a decidedly unfriendly operation for a linked list
-	 bitset!   */
-      elt = LBITSET_TAIL (dst);
-      /* Ignore empty set.  */
-      if (!elt)
-	return 0;
-
-      windex = elt->index;
-      for (i = 0; i < windex; i += LBITSET_ELT_WORDS)
-	{
-	  /* Create new elements if they cannot be found.  */
-	  elt = lbitset_elt_find (dst, i, LBITSET_CREATE);
-	  memset (elt->words, -1, sizeof (elt->words));
-	}
-      break;
-
-    case BITSET_OP_EMPTY_P:
-      lbitset_weed (dst);
-      if (LBITSET_HEAD (dst))
-	return 0;
-      break;
-
-    default:
-      abort ();
+      /* Create new elements if they cannot be found.  */
+      elt = lbitset_elt_find (dst, i, LBITSET_CREATE);
+      memset (elt->words, -1, sizeof (elt->words));
     }
-
-  return 1;
 }
 
 
-static int
-lbitset_op2 (dst, src, op)
+static void
+lbitset_not (dst, src)
      bitset dst;
      bitset src;
-     enum bitset_ops op;
 {
   lbitset_elt *elt;
   lbitset_elt *selt;
@@ -984,106 +989,108 @@ lbitset_op2 (dst, src, op)
   unsigned int j;
   bitset_windex windex;
 
-  switch (op)
+  /* This is another unfriendly operation for a linked list
+     bitset!  */
+  elt = LBITSET_TAIL (dst);
+  /* Ignore empty set.  */
+  if (!elt)
+    return;
+  
+  windex = elt->index;
+  for (i = 0; i < windex; i += LBITSET_ELT_WORDS)
     {
-    case BITSET_OP_COPY:
-      lbitset_copy (dst, src);
-      break;
-
-    case BITSET_OP_NOT:
-      /* This is another unfriendly operation for a linked list
-	 bitset!  */
-      elt = LBITSET_TAIL (dst);
-      /* Ignore empty set.  */
-      if (!elt)
-	return 0;
-
-      windex = elt->index;
-      for (i = 0; i < windex; i += LBITSET_ELT_WORDS)
-	{
-	  /* Create new elements for dst if they cannot be found
-	     or substitute zero elements if src elements not found.  */
-	  selt = lbitset_elt_find (dst, i, LBITSET_SUBST);
-	  delt = lbitset_elt_find (dst, i, LBITSET_CREATE);
+      /* Create new elements for dst if they cannot be found
+	 or substitute zero elements if src elements not found.  */
+      selt = lbitset_elt_find (src, i, LBITSET_SUBST);
+      delt = lbitset_elt_find (dst, i, LBITSET_CREATE);
+      
+      for (j = 0; j < LBITSET_ELT_WORDS; j++)
+	delt->words[j] = ~selt->words[j];
+    }
+  lbitset_weed (dst);
+  return;
+}
 
-	  for (j = 0; j < LBITSET_ELT_WORDS; j++)
-	    delt->words[j] = ~selt->words[j];
-	}
-      lbitset_weed (dst);
-      break;
 
-      /* Return 1 if DST == SRC.  */
-    case BITSET_OP_EQUAL_P:
-      return lbitset_equal_p (dst, src);
-      break;
+/* Return 1 if DST == DST | SRC.  */
+static int
+lbitset_subset_p (dst, src)
+     bitset dst;
+     bitset src;
+{
+  lbitset_elt *selt;
+  lbitset_elt *delt;
+  unsigned int j;
 
-      /* Return 1 if DST == DST | SRC.  */
-    case BITSET_OP_SUBSET_P:
-      for (selt = LBITSET_HEAD (src), delt = LBITSET_HEAD (dst);
-	   selt || delt; selt = selt->next, delt = delt->next)
+  for (selt = LBITSET_HEAD (src), delt = LBITSET_HEAD (dst);
+       selt || delt; selt = selt->next, delt = delt->next)
+    {
+      if (!selt)
+	selt = &lbitset_zero_elts[0];
+      else if (!delt)
+	delt = &lbitset_zero_elts[0];
+      else if (selt->index != delt->index)
 	{
-	  if (!selt)
-	    selt = &lbitset_zero_elts[0];
-	  else if (!delt)
-	    delt = &lbitset_zero_elts[0];
-	  else if (selt->index != delt->index)
+	  if (selt->index < delt->index)
 	    {
-	      if (selt->index < delt->index)
-		{
-		  lbitset_zero_elts[2].next = delt;
-		  delt = &lbitset_zero_elts[2];
-		}
-	      else
-		{
-		  lbitset_zero_elts[1].next = selt;
-		  selt = &lbitset_zero_elts[1];
-		}
+	      lbitset_zero_elts[2].next = delt;
+	      delt = &lbitset_zero_elts[2];
+	    }
+	  else
+	    {
+	      lbitset_zero_elts[1].next = selt;
+	      selt = &lbitset_zero_elts[1];
 	    }
-
-	  for (j = 0; j < LBITSET_ELT_WORDS; j++)
-	    if (delt->words[j] != (selt->words[j] | delt->words[j]))
-	      return 0;
 	}
-      break;
+      
+      for (j = 0; j < LBITSET_ELT_WORDS; j++)
+	if (delt->words[j] != (selt->words[j] | delt->words[j]))
+	  return 0;
+    }
+  return 1;
+}
+
 
-      /* Return 1 if DST & SRC == 0.  */
-    case BITSET_OP_DISJOINT_P:
-      for (selt = LBITSET_HEAD (src), delt = LBITSET_HEAD (dst);
-	   selt && delt; selt = selt->next, delt = delt->next)
+/* Return 1 if DST & SRC == 0.  */
+static int
+lbitset_disjoint_p (dst, src)
+     bitset dst;
+     bitset src;
+{
+  lbitset_elt *selt;
+  lbitset_elt *delt;
+  unsigned int j;
+
+  for (selt = LBITSET_HEAD (src), delt = LBITSET_HEAD (dst);
+       selt && delt; selt = selt->next, delt = delt->next)
+    {
+      if (selt->index != delt->index)
 	{
-	  if (selt->index != delt->index)
+	  if (selt->index < delt->index)
 	    {
-	      if (selt->index < delt->index)
-		{
-		  lbitset_zero_elts[2].next = delt;
-		  delt = &lbitset_zero_elts[2];
-		}
-	      else
-		{
-		  lbitset_zero_elts[1].next = selt;
-		  selt = &lbitset_zero_elts[1];
-		}
-	      /* Since the elements are different, there is no
-		 intersection of these elements.  */
-	      continue;
+	      lbitset_zero_elts[2].next = delt;
+	      delt = &lbitset_zero_elts[2];
 	    }
-
-	  for (j = 0; j < LBITSET_ELT_WORDS; j++)
-	    if (selt->words[j] & delt->words[j])
-	      return 0;
+	  else
+	    {
+	      lbitset_zero_elts[1].next = selt;
+	      selt = &lbitset_zero_elts[1];
+	    }
+	  /* Since the elements are different, there is no
+	     intersection of these elements.  */
+	  continue;
 	}
-      break;
-
-    default:
-      abort ();
+      
+      for (j = 0; j < LBITSET_ELT_WORDS; j++)
+	if (selt->words[j] & delt->words[j])
+	  return 0;
     }
-
   return 1;
 }
 
 
 static int
-lbitset_op3 (dst, src1, src2, op)
+lbitset_op3_cmp (dst, src1, src2, op)
      bitset dst;
      bitset src1;
      bitset src2;
@@ -1104,37 +1111,6 @@ lbitset_op3 (dst, src1, src2, op)
   int changed = 0;
   unsigned int i;
 
-  /* Fast track common, simple cases.  */
-  if (!selt2)
-    {
-      if (op == BITSET_OP_AND)
-	{
-	  lbitset_weed (dst);
-	  changed = !LBITSET_HEAD (dst);
-	  lbitset_zero (dst);
-	  return changed;
-	}
-      else if (op == BITSET_OP_ANDN || op == BITSET_OP_OR
-	       || op == BITSET_OP_XOR)
-	{
-	  return lbitset_copy_compare (dst, src1);
-	}
-    }
-  else if (!selt1)
-    {
-      if (op == BITSET_OP_AND || op == BITSET_OP_ANDN)
-	{
-	  lbitset_weed (dst);
-	  changed = !LBITSET_HEAD (dst);
-	  lbitset_zero (dst);
-	  return changed;
-	}
-      else if (op == BITSET_OP_OR || op == BITSET_OP_XOR)
-	{
-	  return lbitset_copy_compare (dst, src2);
-	}
-    }
-
   LBITSET_HEAD (dst) = 0;
   dst->b.csize = 0;
 
@@ -1275,18 +1251,134 @@ lbitset_op3 (dst, src1, src2, op)
 }
 
 
+static int
+lbitset_and_cmp (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  lbitset_elt *selt1 = LBITSET_HEAD (src1);
+  lbitset_elt *selt2 = LBITSET_HEAD (src2);
+  int changed;
+
+  if (!selt2)
+    {
+      lbitset_weed (dst);
+      changed = !LBITSET_HEAD (dst);
+      lbitset_zero (dst);
+      return changed;
+    }
+  else if (!selt1)
+    {
+      lbitset_weed (dst);
+      changed = !LBITSET_HEAD (dst);
+      lbitset_zero (dst);
+      return changed;
+    }
+  return lbitset_op3_cmp (dst, src1, src2, BITSET_OP_AND);
+}
+
+
+static int
+lbitset_andn_cmp (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  lbitset_elt *selt1 = LBITSET_HEAD (src1);
+  lbitset_elt *selt2 = LBITSET_HEAD (src2);
+  int changed;
+
+  if (!selt2)
+    {
+      return lbitset_copy_cmp (dst, src1);
+    }
+  else if (!selt1)
+    {
+      lbitset_weed (dst);
+      changed = !LBITSET_HEAD (dst);
+      lbitset_zero (dst);
+      return changed;
+    }
+  return lbitset_op3_cmp (dst, src1, src2, BITSET_OP_ANDN);
+}
+
+
+static int
+lbitset_or_cmp (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  lbitset_elt *selt1 = LBITSET_HEAD (src1);
+  lbitset_elt *selt2 = LBITSET_HEAD (src2);
+
+  if (!selt2)
+    {
+      return lbitset_copy_cmp (dst, src1);
+    }
+  else if (!selt1)
+    {
+      return lbitset_copy_cmp (dst, src2);
+    }
+  return lbitset_op3_cmp (dst, src1, src2, BITSET_OP_OR);
+}
+
+
+static int
+lbitset_xor_cmp (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  lbitset_elt *selt1 = LBITSET_HEAD (src1);
+  lbitset_elt *selt2 = LBITSET_HEAD (src2);
+
+  if (!selt2)
+    {
+      return lbitset_copy_cmp (dst, src1);
+    }
+  else if (!selt1)
+    {
+      return lbitset_copy_cmp (dst, src2);
+    }
+  return lbitset_op3_cmp (dst, src1, src2, BITSET_OP_XOR);
+}
+
+
+
 /* Vector of operations for linked-list bitsets.  */
-struct bitset_ops_struct lbitset_ops = {
+struct bitset_vtable lbitset_vtable = {
   lbitset_set,
   lbitset_reset,
+  bitset_toggle_,
   lbitset_test,
   lbitset_size,
-  lbitset_op1,
-  lbitset_op2,
-  lbitset_op3,
-  bitset_op4,
+  bitset_count_,
+  lbitset_empty_p,
+  lbitset_ones,
+  lbitset_zero,
+  lbitset_copy,
+  lbitset_disjoint_p,
+  lbitset_equal_p,
+  lbitset_not,
+  lbitset_subset_p,
+  (PFV) lbitset_and_cmp,
+  lbitset_and_cmp,
+  (PFV) lbitset_andn_cmp,
+  lbitset_andn_cmp,
+  (PFV) lbitset_or_cmp,
+  lbitset_or_cmp,
+  (PFV) lbitset_xor_cmp,
+  lbitset_xor_cmp,
+  (PFV) bitset_and_or_cmp_,
+  bitset_and_or_cmp_,
+  (PFV) bitset_andn_or_cmp_,
+  bitset_andn_or_cmp_,
+  (PFV) bitset_or_and_cmp_,
+  bitset_or_and_cmp_,
   lbitset_list,
-  lbitset_reverse_list,
+  lbitset_list_reverse,
   lbitset_free,
   BITSET_LIST
 };
@@ -1302,13 +1394,12 @@ lbitset_bytes (n_bits)
 
 
 /* Initialize a bitset.  */
-
 bitset
 lbitset_init (bset, n_bits)
      bitset bset;
      bitset_bindex n_bits ATTRIBUTE_UNUSED;
 {
-  bset->b.ops = &lbitset_ops;
+  bset->b.vtable = &lbitset_vtable;
   return bset;
 }
 
@@ -1323,3 +1414,34 @@ lbitset_release_memory ()
       obstack_free (&lbitset_obstack, NULL);
     }
 }
+
+
+/* Function to be called from debugger to debug lbitset.  */
+void
+debug_lbitset (bset)
+     bitset bset;
+{
+  lbitset_elt *elt;
+  unsigned int i;
+
+  if (!bset)
+    return;
+  
+  for (elt = LBITSET_HEAD (bset); elt; elt = elt->next)
+    {
+      fprintf (stderr, "Elt %d\n", elt->index);
+      for (i = 0; i < LBITSET_ELT_WORDS; i++)
+	{
+	  unsigned int j;
+	  bitset_word word;
+	  
+	  word = elt->words[i];
+	  
+	  fprintf (stderr, "  Word %d:", i);
+	  for (j = 0; j < LBITSET_WORD_BITS; j++)
+	    if ((word & (1 << j)))
+	      fprintf (stderr, " %d", j);
+	  fprintf (stderr, "\n");
+	}
+    }
+}
