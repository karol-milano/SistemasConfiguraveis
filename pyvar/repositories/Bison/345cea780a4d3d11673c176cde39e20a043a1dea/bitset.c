@@ -345,6 +345,42 @@ bitset_last (src)
 }
 
 
+/* Return non-zero if BITNO in SRC is the only set bit.  */
+int
+bitset_only_set_p (src, bitno)
+     bitset src;
+     bitset_bindex bitno;
+{
+  bitset_bindex val[2];
+  bitset_bindex next = 0;
+
+  if (bitset_list (src, val, 2, &next) != 1)
+    return 0;
+  return val[0] == bitno;
+}
+
+
+/* Toggle bit BITNO in bitset BSET and return non-zero if now set.  */
+int
+bitset_toggle (bset, bitno)
+    bitset bset;
+    bitset_bindex bitno;
+{
+  /* This routine is for completeness.  It could be optimized if
+     required.  */
+  if (bitset_test (bset, bitno))
+    {
+      bitset_reset (bset, bitno);
+      return 0;
+    }
+  else
+    {
+      bitset_set (bset, bitno);
+      return 1;
+    }
+}
+
+
 /* Print contents of bitset BSET to FILE.   */
 static void
 bitset_print (file, bset, verbose)
@@ -545,18 +581,6 @@ bitset_andn (dst, src1, src2)
 }
 
 
-/* DST = SRC1 | ~SRC2.  Return non-zero if DST != SRC1 | ~SRC2.  */
-int
-bitset_orn (dst, src1, src2)
-     bitset dst;
-     bitset src1;
-     bitset src2;
-{
-  BITSET_CHECK3_ (dst, src1, src2);
-  return BITSET_ORN_ (dst, src1, src2);
-}
-
-
 int
 bitset_op4 (dst, src1, src2, src3, op)
      bitset dst;
@@ -569,7 +593,7 @@ bitset_op4 (dst, src1, src2, src3, op)
   bitset tmp;
 
   /* Create temporary bitset.  */
-  tmp = bitset_alloc (BITSET_TYPE_ (dst), 0);
+  tmp = bitset_alloc (0, BITSET_TYPE_ (dst));
 
   switch (op)
     {
