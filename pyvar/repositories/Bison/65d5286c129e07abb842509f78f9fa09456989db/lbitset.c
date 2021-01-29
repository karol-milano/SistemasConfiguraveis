@@ -26,6 +26,7 @@
 #include <stddef.h>
 #include <stdlib.h>
 #include <stdio.h>
+#include <string.h>
 
 /* This file implements linked-list bitsets.  These bitsets can be of
    arbitrary length and are more efficient than arrays of bits for
@@ -40,7 +41,10 @@
 /* Number of words to use for each element.  The larger the value the
    greater the size of the cache and the shorter the time to find a given bit
    but the more memory wasted for sparse bitsets and the longer the time
-   to search for set bits.  */
+   to search for set bits. 
+
+   The routines that dominate timing profiles are lbitset_elt_find
+   and lbitset_elt_link, especially when accessing the bits randomly.  */
 
 #define LBITSET_ELT_WORDS 2
 
@@ -502,21 +506,15 @@ lbitset_copy_cmp (bitset dst, bitset src)
 }
 
 
-/* Return size in bits of bitset SRC.  */
 static bitset_bindex
-lbitset_size (bitset src)
+lbitset_resize (bitset src, bitset_bindex size)
 {
-  lbitset_elt *elt;
-
-  elt = LBITSET_TAIL (src);
-  if (!elt)
-    return 0;
+    BITSET_NBITS_ (src) = size;
 
-  /* Return current size of bitset in bits.  */
-  return (elt->index + LBITSET_ELT_WORDS) * BITSET_WORD_BITS;
+    /* Need to prune any excess bits.  FIXME.  */
+    return size;
 }
 
-
 /* Set bit BITNO in bitset DST.  */
 static void
 lbitset_set (bitset dst, bitset_bindex bitno)
@@ -867,8 +865,49 @@ lbitset_list (bitset bset, bitset_bindex *list,
 static bool
 lbitset_empty_p (bitset dst)
 {
-  lbitset_weed (dst);
-  return !LBITSET_HEAD (dst);
+  lbitset_elt *elt;
+  lbitset_elt *next;
+
+  for (elt = LBITSET_HEAD (dst); elt; elt = next)
+    {
+      next = elt->next;
+      if (!lbitset_elt_zero_p (elt))
+	return 0;
+      /* Weed as we go.  */
+      lbitset_elt_unlink (dst, elt);
+    }
+
+  return 1;
+}
+
+
+/* Ensure that any unused bits within the last element are clear.  */
+static inline void
+lbitset_unused_clear (dst)
+     bitset dst;
+{
+  unsigned int last_bit;
+  bitset_bindex n_bits;
+
+  n_bits = BITSET_SIZE_ (dst);
+  last_bit = n_bits % LBITSET_ELT_BITS;
+  
+  if (last_bit)
+    {
+      lbitset_elt *elt;
+      bitset_windex windex;
+      bitset_word *srcp;
+      
+      elt = LBITSET_TAIL (dst);
+      srcp = elt->words;
+      windex = n_bits / BITSET_WORD_BITS;
+  
+      srcp[windex - elt->index] &= ((bitset_word) 1 << last_bit) - 1;	  
+      windex++;
+
+      for (; (windex - elt->index) < LBITSET_ELT_WORDS; windex++)
+	srcp[windex - elt->index] = 0;
+    }
 }
 
 
@@ -883,18 +922,17 @@ lbitset_ones (bitset dst)
       bitset!  It makes a sparse bitset become dense.  An alternative
       is to have a flag that indicates that the bitset stores the
       complement of what it indicates.  */
-  elt = LBITSET_TAIL (dst);
-  /* Ignore empty set.  */
-  if (!elt)
-    return;
 
-  windex = elt->index;
+  windex = (BITSET_SIZE_ (dst) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS;
+
   for (i = 0; i < windex; i += LBITSET_ELT_WORDS)
     {
       /* Create new elements if they cannot be found.  */
       elt = lbitset_elt_find (dst, i, LBITSET_CREATE);
       memset (elt->words, -1, sizeof (elt->words));
     }
+
+  lbitset_unused_clear (dst);
 }
 
 
@@ -911,11 +949,9 @@ lbitset_not (bitset dst, bitset src)
   /* This is another unfriendly operation for a linked list
      bitset!  */
   elt = LBITSET_TAIL (dst);
-  /* Ignore empty set.  */
-  if (!elt)
-    return;
 
-  windex = elt->index;
+  windex = (BITSET_SIZE_ (dst) + BITSET_WORD_BITS - 1) / BITSET_WORD_BITS;
+
   for (i = 0; i < windex; i += LBITSET_ELT_WORDS)
     {
       /* Create new elements for dst if they cannot be found
@@ -926,6 +962,7 @@ lbitset_not (bitset dst, bitset src)
       for (j = 0; j < LBITSET_ELT_WORDS; j++)
 	delt->words[j] = ~selt->words[j];
     }
+  lbitset_unused_clear (dst);
   lbitset_weed (dst);
   return;
 }
@@ -1280,7 +1317,8 @@ struct bitset_vtable lbitset_vtable = {
   lbitset_reset,
   bitset_toggle_,
   lbitset_test,
-  lbitset_size,
+  lbitset_resize,
+  bitset_size_,
   bitset_count_,
   lbitset_empty_p,
   lbitset_ones,
@@ -1323,6 +1361,7 @@ lbitset_bytes (bitset_bindex n_bits ATTRIBUTE_UNUSED)
 bitset
 lbitset_init (bitset bset, bitset_bindex n_bits ATTRIBUTE_UNUSED)
 {
+  BITSET_NBITS_ (bset) = n_bits;
   bset->b.vtable = &lbitset_vtable;
   return bset;
 }
