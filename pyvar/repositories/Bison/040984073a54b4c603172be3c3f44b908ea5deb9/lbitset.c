@@ -41,7 +41,7 @@
 /* Number of words to use for each element.  The larger the value the
    greater the size of the cache and the shorter the time to find a given bit
    but the more memory wasted for sparse bitsets and the longer the time
-   to search for set bits. 
+   to search for set bits.
 
    The routines that dominate timing profiles are lbitset_elt_find
    and lbitset_elt_link, especially when accessing the bits randomly.  */
@@ -888,18 +888,18 @@ lbitset_unused_clear (bitset dst)
 
   n_bits = BITSET_SIZE_ (dst);
   last_bit = n_bits % LBITSET_ELT_BITS;
-  
+
   if (last_bit)
     {
       lbitset_elt *elt;
       bitset_windex windex;
       bitset_word *srcp;
-      
+
       elt = LBITSET_TAIL (dst);
       srcp = elt->words;
       windex = n_bits / BITSET_WORD_BITS;
-  
-      srcp[windex - elt->index] &= ((bitset_word) 1 << last_bit) - 1;	  
+
+      srcp[windex - elt->index] &= ((bitset_word) 1 << last_bit) - 1;
       windex++;
 
       for (; (windex - elt->index) < LBITSET_ELT_WORDS; windex++)
