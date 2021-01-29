@@ -887,7 +887,7 @@ lbitset_ones (bitset dst)
      bitset!  It makes a sparse bitset become dense.  An alternative
      is to have a flag that indicates that the bitset stores the
      complement of what it indicates.  */
-  
+
   bitset_windex windex
     = (BITSET_SIZE_ (dst) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS;
 
