@@ -51,14 +51,9 @@ static void abitset_set PARAMS ((bitset, bitset_bindex));
 static void abitset_reset PARAMS ((bitset, bitset_bindex));
 static int abitset_test PARAMS ((bitset, bitset_bindex));
 static int abitset_size PARAMS ((bitset));
-static int abitset_op1 PARAMS ((bitset, enum bitset_ops));
-static int abitset_op2 PARAMS ((bitset, bitset, enum bitset_ops));
-static int abitset_op3 PARAMS ((bitset, bitset, bitset, enum bitset_ops));
-static int abitset_op4 PARAMS ((bitset, bitset, bitset, bitset,
-				enum bitset_ops));
 static int abitset_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
 				 bitset_bindex *));
-static int abitset_reverse_list
+static int abitset_list_reverse
 PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
 
 #define ABITSET_N_WORDS(N) (((N) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS)
@@ -143,7 +138,8 @@ abitset_set (dst, bitno)
      bitset dst ATTRIBUTE_UNUSED;
      bitset_bindex bitno ATTRIBUTE_UNUSED;
 {
-  /* This should never occur for abitsets.  */
+  /* This should never occur for abitsets since we should always
+     hit the cache.  */
   abort ();
 }
 
@@ -154,7 +150,8 @@ abitset_reset (dst, bitno)
      bitset dst ATTRIBUTE_UNUSED;
      bitset_bindex bitno ATTRIBUTE_UNUSED;
 {
-  /* This should never occur for abitsets.  */
+  /* This should never occur for abitsets since we should always
+     hit the cache.  */
   abort ();
 }
 
@@ -165,7 +162,8 @@ abitset_test (src, bitno)
      bitset src ATTRIBUTE_UNUSED;
      bitset_bindex bitno ATTRIBUTE_UNUSED;
 {
-  /* This should never occur for abitsets.  */
+  /* This should never occur for abitsets since we should always
+     hit the cache.  */
   abort ();
   return 0;
 }
@@ -176,7 +174,7 @@ abitset_test (src, bitno)
    actual number of bits found and with *NEXT indicating where search
    stopped.  */
 static int
-abitset_reverse_list (src, list, num, next)
+abitset_list_reverse (src, list, num, next)
      bitset src;
      bitset_bindex *list;
      bitset_bindex num;
@@ -188,7 +186,6 @@ abitset_reverse_list (src, list, num, next)
   bitset_windex windex;
   unsigned int bitcnt;
   bitset_bindex bitoff;
-  bitset_word word;
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_bindex n_bits = ABITSET_N_BITS (src);
 
@@ -210,6 +207,8 @@ abitset_reverse_list (src, list, num, next)
 
   do
     {
+      bitset_word word;
+
       word = srcp[windex] << (BITSET_WORD_BITS - 1 - bitcnt);
       for (; word; bitcnt--)
 	{
@@ -354,99 +353,153 @@ abitset_unused_clear (dst)
 }
 
 
-static int
-abitset_op1 (dst, op)
+static void
+abitset_ones (dst)
      bitset dst;
-     enum bitset_ops op;
 {
-  unsigned int i;
   bitset_word *dstp = ABITSET_WORDS (dst);
   unsigned int bytes;
 
   bytes = sizeof (bitset_word) * dst->b.csize;
 
-  switch (op)
-    {
-    case BITSET_OP_ZERO:
-      memset (dstp, 0, bytes);
-      break;
-
-    case BITSET_OP_ONES:
-      memset (dstp, -1, bytes);
-      abitset_unused_clear (dst);
-      break;
-
-    case BITSET_OP_EMPTY_P:
-      for (i = 0; i < dst->b.csize; i++)
-	if (dstp[i])
-	  return 0;
-      break;
+  memset (dstp, -1, bytes);
+  abitset_unused_clear (dst);
+}
+
+
+static void
+abitset_zero (dst)
+     bitset dst;
+{
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  unsigned int bytes;
+
+  bytes = sizeof (bitset_word) * dst->b.csize;
+
+  memset (dstp, 0, bytes);
+}
 
-    default:
-      abort ();
-    }
+
+static int
+abitset_empty_p (dst)
+     bitset dst;
+{
+  unsigned int i;
+  bitset_word *dstp = ABITSET_WORDS (dst);
+
+  for (i = 0; i < dst->b.csize; i++)
+    if (dstp[i])
+      return 0;
 
   return 1;
 }
 
 
+static void
+abitset_copy1 (dst, src)
+     bitset dst;
+     bitset src;
+{
+  bitset_word *srcp = ABITSET_WORDS (src);
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  bitset_windex size = dst->b.csize;
+
+  if (srcp == dstp)
+      return;
+  memcpy (dstp, srcp, sizeof (bitset_word) * size);
+}
+
+
+static void
+abitset_not (dst, src)
+     bitset dst;
+     bitset src;
+{
+  unsigned int i;
+  bitset_word *srcp = ABITSET_WORDS (src);
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  bitset_windex size = dst->b.csize;
+
+  for (i = 0; i < size; i++)
+      *dstp++ = ~(*srcp++);
+  abitset_unused_clear (dst);
+}
+
+ 
 static int
-abitset_op2 (dst, src, op)
+abitset_equal_p (dst, src)
      bitset dst;
      bitset src;
-     enum bitset_ops op;
 {
   unsigned int i;
   bitset_word *srcp = ABITSET_WORDS (src);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  switch (op)
-    {
-    case BITSET_OP_COPY:
-      if (srcp == dstp)
-	break;
-      memcpy (dstp, srcp, sizeof (bitset_word) * size);
-      break;
-
-    case BITSET_OP_NOT:
-      for (i = 0; i < size; i++)
-	*dstp++ = ~(*srcp++);
-      abitset_unused_clear (dst);
-      break;
-
-    case BITSET_OP_EQUAL_P:
-      for (i = 0; i < size; i++)
-	if (*srcp++ != *dstp++)
+  for (i = 0; i < size; i++)
+      if (*srcp++ != *dstp++)
 	  return 0;
-      break;
-      
-    case BITSET_OP_SUBSET_P:
-      for (i = 0; i < size; i++, dstp++, srcp++)
-	if (*dstp != (*srcp | *dstp))
+  return 1;
+}
+
+
+static int
+abitset_subset_p (dst, src)
+     bitset dst;
+     bitset src;
+{
+  unsigned int i;
+  bitset_word *srcp = ABITSET_WORDS (src);
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  bitset_windex size = dst->b.csize;
+  
+  for (i = 0; i < size; i++, dstp++, srcp++)
+      if (*dstp != (*srcp | *dstp))
 	  return 0;
-      break;
-      
-    case BITSET_OP_DISJOINT_P:
-      for (i = 0; i < size; i++)
-	if (*srcp++ & *dstp++)
+  return 1;
+}
+
+
+static int
+abitset_disjoint_p (dst, src)
+     bitset dst;
+     bitset src;
+{
+  unsigned int i;
+  bitset_word *srcp = ABITSET_WORDS (src);
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  bitset_windex size = dst->b.csize;
+
+  for (i = 0; i < size; i++)
+      if (*srcp++ & *dstp++)
 	  return 0;
-      break;
-      
-    default:
-      abort ();
-    }
 
   return 1;
 }
 
 
+static void
+abitset_and (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  unsigned int i;
+  bitset_word *src1p = ABITSET_WORDS (src1);
+  bitset_word *src2p = ABITSET_WORDS (src2);
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  bitset_windex size = dst->b.csize;
+
+  for (i = 0; i < size; i++)
+      *dstp++ = *src1p++ & *src2p++;
+}
+
+
 static int
-abitset_op3 (dst, src1, src2, op)
+abitset_and_cmp (dst, src1, src2)
      bitset dst;
      bitset src1;
      bitset src2;
-     enum bitset_ops op;
 {
   unsigned int i;
   int changed = 0;
@@ -455,75 +508,177 @@ abitset_op3 (dst, src1, src2, op)
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
 
-  switch (op)
+  for (i = 0; i < size; i++, dstp++)
     {
-    case BITSET_OP_OR:
-      for (i = 0; i < size; i++, dstp++)
+      bitset_word tmp = *src1p++ & *src2p++;
+      
+      if (*dstp != tmp)
 	{
-	  bitset_word tmp = *src1p++ | *src2p++;
-
-	  if (*dstp != tmp)
-	    {
-	      changed = 1;
-	      *dstp = tmp;
-	    }
+	  changed = 1;
+	  *dstp = tmp;
 	}
-      break;
+    }
+  return changed;
+}
 
-    case BITSET_OP_AND:
-      for (i = 0; i < size; i++, dstp++)
-	{
-	  bitset_word tmp = *src1p++ & *src2p++;
 
-	  if (*dstp != tmp)
-	    {
-	      changed = 1;
-	      *dstp = tmp;
-	    }
-	}
-      break;
+static void
+abitset_andn (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  unsigned int i;
+  bitset_word *src1p = ABITSET_WORDS (src1);
+  bitset_word *src2p = ABITSET_WORDS (src2);
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  bitset_windex size = dst->b.csize;
 
-    case BITSET_OP_XOR:
-      for (i = 0; i < size; i++, dstp++)
-	{
-	  bitset_word tmp = *src1p++ ^ *src2p++;
+  for (i = 0; i < size; i++)
+      *dstp++ = *src1p++ & ~(*src2p++);
+}
 
-	  if (*dstp != tmp)
-	    {
-	      changed = 1;
-	      *dstp = tmp;
-	    }
-	}
-      break;
 
-    case BITSET_OP_ANDN:
-      for (i = 0; i < size; i++, dstp++)
+static int
+abitset_andn_cmp (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  unsigned int i;
+  int changed = 0;
+  bitset_word *src1p = ABITSET_WORDS (src1);
+  bitset_word *src2p = ABITSET_WORDS (src2);
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  bitset_windex size = dst->b.csize;
+  
+  for (i = 0; i < size; i++, dstp++)
+    {
+      bitset_word tmp = *src1p++ & ~(*src2p++);
+      
+      if (*dstp != tmp)
 	{
-	  bitset_word tmp = *src1p++ & ~(*src2p++);
-
-	  if (*dstp != tmp)
-	    {
-	      changed = 1;
-	      *dstp = tmp;
-	    }
+	  changed = 1;
+	  *dstp = tmp;
 	}
-      break;
+    }
+  return changed;
+}
+
+
+static void
+abitset_or (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  unsigned int i;
+  bitset_word *src1p = ABITSET_WORDS (src1);
+  bitset_word *src2p = ABITSET_WORDS (src2);
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  bitset_windex size = dst->b.csize;
+
+  for (i = 0; i < size; i++)
+      *dstp++ = *src1p++ | *src2p++;
+}
+
 
-    default:
-      abort ();
+static int
+abitset_or_cmp (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  unsigned int i;
+  int changed = 0;
+  bitset_word *src1p = ABITSET_WORDS (src1);
+  bitset_word *src2p = ABITSET_WORDS (src2);
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  bitset_windex size = dst->b.csize;
+
+  for (i = 0; i < size; i++, dstp++)
+    {
+      bitset_word tmp = *src1p++ | *src2p++;
+      
+      if (*dstp != tmp)
+	{
+	  changed = 1;
+	  *dstp = tmp;
+	}
     }
+  return changed;
+}
 
+
+static void
+abitset_xor (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  unsigned int i;
+  bitset_word *src1p = ABITSET_WORDS (src1);
+  bitset_word *src2p = ABITSET_WORDS (src2);
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  bitset_windex size = dst->b.csize;
+
+  for (i = 0; i < size; i++)
+      *dstp++ = *src1p++ ^ *src2p++;
+}
+
+
+static int
+abitset_xor_cmp (dst, src1, src2)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+{
+  unsigned int i;
+  int changed = 0;
+  bitset_word *src1p = ABITSET_WORDS (src1);
+  bitset_word *src2p = ABITSET_WORDS (src2);
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  bitset_windex size = dst->b.csize;
+
+  for (i = 0; i < size; i++, dstp++)
+    {
+      bitset_word tmp = *src1p++ ^ *src2p++;
+      
+      if (*dstp != tmp)
+	{
+	  changed = 1;
+	  *dstp = tmp;
+	}
+    }
   return changed;
 }
 
 
+static void
+abitset_and_or (dst, src1, src2, src3)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+{
+  unsigned int i;
+  bitset_word *src1p = ABITSET_WORDS (src1);
+  bitset_word *src2p = ABITSET_WORDS (src2);
+  bitset_word *src3p = ABITSET_WORDS (src3);
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  bitset_windex size = dst->b.csize;
+  
+  for (i = 0; i < size; i++)
+      *dstp++ = (*src1p++ & *src2p++) | *src3p++;
+}
+
+
 static int
-abitset_op4 (dst, src1, src2, src3, op)
+abitset_and_or_cmp (dst, src1, src2, src3)
      bitset dst;
      bitset src1;
      bitset src2;
      bitset src3;
-     enum bitset_ops op;
 {
   unsigned int i;
   int changed = 0;
@@ -532,85 +687,198 @@ abitset_op4 (dst, src1, src2, src3, op)
   bitset_word *src3p = ABITSET_WORDS (src3);
   bitset_word *dstp = ABITSET_WORDS (dst);
   bitset_windex size = dst->b.csize;
-
-  switch (op)
+  
+  for (i = 0; i < size; i++, dstp++)
     {
-    case BITSET_OP_OR_AND:
-      for (i = 0; i < size; i++, dstp++)
+      bitset_word tmp = (*src1p++ & *src2p++) | *src3p++;
+      
+      if (*dstp != tmp)
 	{
-	  bitset_word tmp = (*src1p++ | *src2p++) & *src3p++;
-
-	  if (*dstp != tmp)
-	    {
-	      changed = 1;
-	      *dstp = tmp;
-	    }
+	  changed = 1;
+	  *dstp = tmp;
 	}
-      break;
+    }
+  return changed;
+}
 
-    case BITSET_OP_AND_OR:
-      for (i = 0; i < size; i++, dstp++)
-	{
-	  bitset_word tmp = (*src1p++ & *src2p++) | *src3p++;
 
-	  if (*dstp != tmp)
-	    {
-	      changed = 1;
-	      *dstp = tmp;
-	    }
-	}
-      break;
+static void
+abitset_andn_or (dst, src1, src2, src3)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+{
+  unsigned int i;
+  bitset_word *src1p = ABITSET_WORDS (src1);
+  bitset_word *src2p = ABITSET_WORDS (src2);
+  bitset_word *src3p = ABITSET_WORDS (src3);
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  bitset_windex size = dst->b.csize;
+  
+  for (i = 0; i < size; i++)
+      *dstp++ = (*src1p++ & ~(*src2p++)) | *src3p++;
+}
 
-    case BITSET_OP_ANDN_OR:
-      for (i = 0; i < size; i++, dstp++)
-	{
-	  bitset_word tmp = (*src1p++ & ~(*src2p++)) | *src3p++;
 
-	  if (*dstp != tmp)
-	    {
-	      changed = 1;
-	      *dstp = tmp;
-	    }
+static int
+abitset_andn_or_cmp (dst, src1, src2, src3)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+{
+  unsigned int i;
+  int changed = 0;
+  bitset_word *src1p = ABITSET_WORDS (src1);
+  bitset_word *src2p = ABITSET_WORDS (src2);
+  bitset_word *src3p = ABITSET_WORDS (src3);
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  bitset_windex size = dst->b.csize;
+  
+  for (i = 0; i < size; i++, dstp++)
+    {
+      bitset_word tmp = (*src1p++ & ~(*src2p++)) | *src3p++;
+      
+      if (*dstp != tmp)
+	{
+	  changed = 1;
+	  *dstp = tmp;
 	}
-      break;
-
-    default:
-      abort ();
     }
+  return changed;
+}
+
+
+static void
+abitset_or_and (dst, src1, src2, src3)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+{
+  unsigned int i;
+  bitset_word *src1p = ABITSET_WORDS (src1);
+  bitset_word *src2p = ABITSET_WORDS (src2);
+  bitset_word *src3p = ABITSET_WORDS (src3);
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  bitset_windex size = dst->b.csize;
+  
+  for (i = 0; i < size; i++)
+      *dstp++ = (*src1p++ | *src2p++) & *src3p++;
+}
+
 
+static int
+abitset_or_and_cmp (dst, src1, src2, src3)
+     bitset dst;
+     bitset src1;
+     bitset src2;
+     bitset src3;
+{
+  unsigned int i;
+  int changed = 0;
+  bitset_word *src1p = ABITSET_WORDS (src1);
+  bitset_word *src2p = ABITSET_WORDS (src2);
+  bitset_word *src3p = ABITSET_WORDS (src3);
+  bitset_word *dstp = ABITSET_WORDS (dst);
+  bitset_windex size = dst->b.csize;
+  
+  for (i = 0; i < size; i++, dstp++)
+    {
+      bitset_word tmp = (*src1p++ | *src2p++) & *src3p++;
+      
+      if (*dstp != tmp)
+	{
+	  changed = 1;
+	  *dstp = tmp;
+	}
+    }
   return changed;
 }
 
 
+void
+abitset_copy (dst, src)
+     bitset dst;
+     bitset src;
+{
+  if (BITSET_COMPATIBLE_ (dst, src))
+      abitset_copy1 (dst, src);
+  else
+      bitset_copy_ (dst, src);
+}
+
+
 /* Vector of operations for single word bitsets.  */
-struct bitset_ops_struct abitset_small_ops = {
+struct bitset_vtable abitset_small_vtable = {
   abitset_set,
   abitset_reset,
+  bitset_toggle_,
   abitset_test,
   abitset_size,
-  abitset_op1,
-  abitset_op2,
-  abitset_op3,
-  abitset_op4,
+  bitset_count_,
+  abitset_empty_p,
+  abitset_ones,
+  abitset_zero,
+  abitset_copy,
+  abitset_disjoint_p,
+  abitset_equal_p,
+  abitset_not,
+  abitset_subset_p,
+  abitset_and,
+  abitset_and_cmp,
+  abitset_andn,
+  abitset_andn_cmp,
+  abitset_or,
+  abitset_or_cmp,
+  abitset_xor,
+  abitset_xor_cmp,
+  abitset_and_or,
+  abitset_and_or_cmp,
+  abitset_andn_or,
+  abitset_andn_or_cmp,
+  abitset_or_and,
+  abitset_or_and_cmp,
   abitset_small_list,
-  abitset_reverse_list,
+  abitset_list_reverse,
   NULL,
   BITSET_ARRAY
 };
 
 
 /* Vector of operations for multiple word bitsets.  */
-struct bitset_ops_struct abitset_ops = {
+struct bitset_vtable abitset_vtable = {
   abitset_set,
   abitset_reset,
+  bitset_toggle_,
   abitset_test,
   abitset_size,
-  abitset_op1,
-  abitset_op2,
-  abitset_op3,
-  abitset_op4,
+  bitset_count_,
+  abitset_empty_p,
+  abitset_ones,
+  abitset_zero,
+  abitset_copy,
+  abitset_disjoint_p,
+  abitset_equal_p,
+  abitset_not,
+  abitset_subset_p,
+  abitset_and,
+  abitset_and_cmp,
+  abitset_andn,
+  abitset_andn_cmp,
+  abitset_or,
+  abitset_or_cmp,
+  abitset_xor,
+  abitset_xor_cmp,
+  abitset_and_or,
+  abitset_and_or_cmp,
+  abitset_andn_or,
+  abitset_andn_or_cmp,
+  abitset_or_and,
+  abitset_or_and_cmp,
   abitset_list,
-  abitset_reverse_list,
+  abitset_list_reverse,
   NULL,
   BITSET_ARRAY
 };
@@ -642,9 +910,9 @@ abitset_init (bset, n_bits)
      There is probably little merit if using caching since
      the small bitset will always fit in the cache.  */
   if (size == 1)
-    bset->b.ops = &abitset_small_ops;
+    bset->b.vtable = &abitset_small_vtable;
   else
-    bset->b.ops = &abitset_ops;
+    bset->b.vtable = &abitset_vtable;
 
   bset->b.cindex = 0;
   bset->b.csize = size;
