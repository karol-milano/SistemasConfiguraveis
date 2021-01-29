@@ -585,7 +585,8 @@ lbitset_set (dst, bitno)
 
   lbitset_elt_find (dst, windex, LBITSET_CREATE);
 
-  dst->b.cdata[windex - dst->b.cindex] |= (1 << (bitno % BITSET_WORD_BITS));
+  dst->b.cdata[windex - dst->b.cindex] |=
+    (bitset_word) 1 << (bitno % BITSET_WORD_BITS);
 }
 
 
@@ -600,7 +601,8 @@ lbitset_reset (dst, bitno)
   if (!lbitset_elt_find (dst, windex, LBITSET_FIND))
     return;
 
-  dst->b.cdata[windex - dst->b.cindex] &= ~(1 << (bitno % BITSET_WORD_BITS));
+  dst->b.cdata[windex - dst->b.cindex] &=
+    ~((bitset_word) 1 << (bitno % BITSET_WORD_BITS));
 
   /* If all the data is zero, perhaps we should unlink it now...  */
 }
@@ -951,7 +953,7 @@ lbitset_op1 (dst, op)
 	{
 	  /* Create new elements if they cannot be found.  */
 	  elt = lbitset_elt_find (dst, i, LBITSET_CREATE);
-	  memset (elt->words, ~0, sizeof (elt->words));
+	  memset (elt->words, -1, sizeof (elt->words));
 	}
       break;
 
