@@ -110,11 +110,11 @@ static int lbitset_copy_cmp PARAMS ((bitset, bitset));
 static void lbitset_set PARAMS ((bitset, bitset_bindex));
 static void lbitset_reset PARAMS ((bitset, bitset_bindex));
 static int lbitset_test PARAMS ((bitset, bitset_bindex));
-static int lbitset_size PARAMS ((bitset));
+static bitset_bindex lbitset_size PARAMS ((bitset));
 static int lbitset_op3_cmp PARAMS ((bitset, bitset, bitset, enum bitset_ops));
-static int lbitset_list PARAMS ((bitset, bitset_bindex *, bitset_bindex,
-				 bitset_bindex *));
-static int lbitset_list_reverse
+static bitset_bindex lbitset_list PARAMS ((bitset, bitset_bindex *,
+					   bitset_bindex, bitset_bindex *));
+static bitset_bindex lbitset_list_reverse
 PARAMS ((bitset, bitset_bindex *, bitset_bindex, bitset_bindex *));
 static void lbitset_free PARAMS ((bitset));
 
@@ -417,7 +417,7 @@ lbitset_elt_find (bset, windex, mode)
       return 0;
 
     case LBITSET_CREATE:
-      windex = (windex / (unsigned) LBITSET_ELT_WORDS) * LBITSET_ELT_WORDS;
+      windex -= windex % LBITSET_ELT_WORDS;
 
       elt = lbitset_elt_calloc ();
       elt->index = windex;
@@ -563,7 +563,7 @@ lbitset_copy_cmp (dst, src)
 
 
 /* Return size in bits of bitset SRC.  */
-static int
+static bitset_bindex
 lbitset_size (src)
      bitset src;
 {
@@ -638,7 +638,7 @@ lbitset_free (bset)
 /* Find list of up to NUM bits set in BSET starting from and including
  *NEXT and store in array LIST.  Return with actual number of bits
  found and with *NEXT indicating where search stopped.  */
-static int
+static bitset_bindex
 lbitset_list_reverse (bset, list, num, next)
      bitset bset;
      bitset_bindex *list;
@@ -736,7 +736,7 @@ lbitset_list_reverse (bset, list, num, next)
 /* Find list of up to NUM bits set in BSET starting from and including
  *NEXT and store in array LIST.  Return with actual number of bits
  found and with *NEXT indicating where search stopped.  */
-static int
+static bitset_bindex
 lbitset_list (bset, list, num, next)
      bitset bset;
      bitset_bindex *list;
@@ -954,7 +954,7 @@ static void
 lbitset_ones (dst)
      bitset dst;
 {
-  unsigned int i;
+  bitset_windex i;
   bitset_windex windex;
   lbitset_elt *elt;
 
@@ -985,7 +985,7 @@ lbitset_not (dst, src)
   lbitset_elt *elt;
   lbitset_elt *selt;
   lbitset_elt *delt;
-  unsigned int i;
+  bitset_windex i;
   unsigned int j;
   bitset_windex windex;
 
@@ -1114,8 +1114,8 @@ lbitset_op3_cmp (dst, src1, src2, op)
   LBITSET_HEAD (dst) = 0;
   dst->b.csize = 0;
 
-  windex1 = (selt1) ? selt1->index : BITSET_INDEX_MAX;
-  windex2 = (selt2) ? selt2->index : BITSET_INDEX_MAX;
+  windex1 = (selt1) ? selt1->index : BITSET_WINDEX_MAX;
+  windex2 = (selt2) ? selt2->index : BITSET_WINDEX_MAX;
 
   while (selt1 || selt2)
     {
@@ -1127,9 +1127,9 @@ lbitset_op3_cmp (dst, src1, src2, op)
 	  stmp1 = selt1;
 	  stmp2 = selt2;
 	  selt1 = selt1->next;
-	  windex1 = (selt1) ? selt1->index : BITSET_INDEX_MAX;
+	  windex1 = (selt1) ? selt1->index : BITSET_WINDEX_MAX;
 	  selt2 = selt2->next;
-	  windex2 = (selt2) ? selt2->index : BITSET_INDEX_MAX;
+	  windex2 = (selt2) ? selt2->index : BITSET_WINDEX_MAX;
 	}
       else if (windex1 < windex2)
 	{
@@ -1137,7 +1137,7 @@ lbitset_op3_cmp (dst, src1, src2, op)
 	  stmp1 = selt1;
 	  stmp2 = &lbitset_zero_elts[0];
 	  selt1 = selt1->next;
-	  windex1 = (selt1) ? selt1->index : BITSET_INDEX_MAX;
+	  windex1 = (selt1) ? selt1->index : BITSET_WINDEX_MAX;
 	}
       else
 	{
@@ -1145,7 +1145,7 @@ lbitset_op3_cmp (dst, src1, src2, op)
 	  stmp1 = &lbitset_zero_elts[0];
 	  stmp2 = selt2;
 	  selt2 = selt2->next;
-	  windex2 = (selt2) ? selt2->index : BITSET_INDEX_MAX;
+	  windex2 = (selt2) ? selt2->index : BITSET_WINDEX_MAX;
 	}
 
       /* Find the appropriate element from DST.  Begin by discarding
@@ -1385,7 +1385,7 @@ struct bitset_vtable lbitset_vtable = {
 
 
 /* Return size of initial structure.  */
-int
+size_t
 lbitset_bytes (n_bits)
      bitset_bindex n_bits ATTRIBUTE_UNUSED;
 {
@@ -1429,7 +1429,7 @@ debug_lbitset (bset)
   
   for (elt = LBITSET_HEAD (bset); elt; elt = elt->next)
     {
-      fprintf (stderr, "Elt %d\n", elt->index);
+      fprintf (stderr, "Elt %lu\n", (unsigned long) elt->index);
       for (i = 0; i < LBITSET_ELT_WORDS; i++)
 	{
 	  unsigned int j;
@@ -1437,10 +1437,10 @@ debug_lbitset (bset)
 	  
 	  word = elt->words[i];
 	  
-	  fprintf (stderr, "  Word %d:", i);
+	  fprintf (stderr, "  Word %u:", i);
 	  for (j = 0; j < LBITSET_WORD_BITS; j++)
 	    if ((word & (1 << j)))
-	      fprintf (stderr, " %d", j);
+	      fprintf (stderr, " %u", j);
 	  fprintf (stderr, "\n");
 	}
     }
