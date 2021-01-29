@@ -22,12 +22,13 @@
 
 #include "lbitset.h"
 
-#include "obstack.h"
 #include <stddef.h>
-#include <stdlib.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 
+#include "obstack.h"
+
 /* This file implements linked-list bitsets.  These bitsets can be of
    arbitrary length and are more efficient than arrays of bits for
    large sparse sets.
@@ -108,21 +109,21 @@ lbitset_elt_alloc (void)
           /* Let particular systems override the size of a chunk.  */
 
 #ifndef OBSTACK_CHUNK_SIZE
-#define OBSTACK_CHUNK_SIZE 0
+# define OBSTACK_CHUNK_SIZE 0
 #endif
 
           /* Let them override the alloc and free routines too.  */
 
 #ifndef OBSTACK_CHUNK_ALLOC
-#define OBSTACK_CHUNK_ALLOC xmalloc
+# define OBSTACK_CHUNK_ALLOC xmalloc
 #endif
 
 #ifndef OBSTACK_CHUNK_FREE
-#define OBSTACK_CHUNK_FREE free
+# define OBSTACK_CHUNK_FREE free
 #endif
 
 #if ! defined __GNUC__ || __GNUC__ < 2
-#define __alignof__(type) 0
+# define __alignof__(type) 0
 #endif
 
           obstack_specify_allocation (&lbitset_obstack, OBSTACK_CHUNK_SIZE,
@@ -242,7 +243,6 @@ lbitset_elt_zero_p (lbitset_elt *elt)
   for (int i = 0; i < LBITSET_ELT_WORDS; i++)
     if (elt->words[i])
       return false;
-
   return true;
 }
 
@@ -253,11 +253,7 @@ lbitset_elt_link (bitset bset, lbitset_elt *elt)
 {
   bitset_windex windex = elt->index;
 
-  lbitset_elt *current;
-  if (bset->b.csize)
-    current = LBITSET_CURRENT (bset);
-  else
-    current = LBITSET_HEAD (bset);
+  lbitset_elt *current = bset->b.csize ? LBITSET_CURRENT (bset) : LBITSET_HEAD (bset);
 
   /* If this is the first and only element, add it in.  */
   if (LBITSET_HEAD (bset) == 0)
@@ -634,8 +630,8 @@ lbitset_list_reverse (bitset bset, bitset_bindex *list,
 
 
 /* Find list of up to NUM bits set in BSET starting from and including
- *NEXT and store in array LIST.  Return with actual number of bits
- found and with *NEXT indicating where search stopped.  */
+   *NEXT and store in array LIST.  Return with actual number of bits
+   found and with *NEXT indicating where search stopped.  */
 static bitset_bindex
 lbitset_list (bitset bset, bitset_bindex *list,
               bitset_bindex num, bitset_bindex *next)
@@ -646,7 +642,6 @@ lbitset_list (bitset bset, bitset_bindex *list,
 
   bitset_windex windex;
   lbitset_elt *elt;
-  bitset_word word;
 
   bitset_bindex bitno = *next;
   bitset_bindex count = 0;
@@ -686,7 +681,7 @@ lbitset_list (bitset bset, bitset_bindex *list,
 
           for (; (windex - elt->index) < LBITSET_ELT_WORDS; windex++)
             {
-              word = srcp[windex - elt->index] >> (bitno % BITSET_WORD_BITS);
+              bitset_word word = srcp[windex - elt->index] >> (bitno % BITSET_WORD_BITS);
 
               for (; word; bitno++)
                 {
@@ -726,7 +721,7 @@ lbitset_list (bitset bset, bitset_bindex *list,
           /* The coast is clear, plant boot!  */
 
 #if LBITSET_ELT_WORDS == 2
-          word = srcp[0];
+          bitset_word word = srcp[0];
           if (word)
             {
               if (!(word & 0xffff))
@@ -769,7 +764,7 @@ lbitset_list (bitset bset, bitset_bindex *list,
 #else
           for (int i = 0; i < LBITSET_ELT_WORDS; i++)
             {
-              word = srcp[i];
+              bitset_word word = srcp[i];
               if (word)
                 {
                   if (!(word & 0xffff))
@@ -801,7 +796,7 @@ lbitset_list (bitset bset, bitset_bindex *list,
 
           for (int i = 0; i < LBITSET_ELT_WORDS; i++)
             {
-              for (word = srcp[i]; word; bitno++)
+              for (bitset_word word = srcp[i]; word; bitno++)
                 {
                   if (word & 1)
                     {
@@ -842,12 +837,12 @@ lbitset_empty_p (bitset dst)
     {
       next = elt->next;
       if (!lbitset_elt_zero_p (elt))
-        return 0;
+        return false;
       /* Weed as we go.  */
       lbitset_elt_unlink (dst, elt);
     }
 
-  return 1;
+  return true;
 }
 
 
@@ -855,21 +850,14 @@ lbitset_empty_p (bitset dst)
 static inline void
 lbitset_unused_clear (bitset dst)
 {
-  unsigned last_bit;
-  bitset_bindex n_bits;
-
-  n_bits = BITSET_SIZE_ (dst);
-  last_bit = n_bits % LBITSET_ELT_BITS;
+  bitset_bindex n_bits = BITSET_SIZE_ (dst);
+  unsigned last_bit = n_bits % LBITSET_ELT_BITS;
 
   if (last_bit)
     {
-      lbitset_elt *elt;
-      bitset_windex windex;
-      bitset_word *srcp;
-
-      elt = LBITSET_TAIL (dst);
-      srcp = elt->words;
-      windex = n_bits / BITSET_WORD_BITS;
+      lbitset_elt *elt = LBITSET_TAIL (dst);
+      bitset_word *srcp = elt->words;
+      bitset_windex windex = n_bits / BITSET_WORD_BITS;
 
       srcp[windex - elt->index] &= ((bitset_word) 1 << last_bit) - 1;
       windex++;
@@ -920,7 +908,6 @@ lbitset_not (bitset dst, bitset src)
     }
   lbitset_unused_clear (dst);
   lbitset_weed (dst);
-  return;
 }
 
 
@@ -995,13 +982,6 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
   lbitset_elt *selt1 = LBITSET_HEAD (src1);
   lbitset_elt *selt2 = LBITSET_HEAD (src2);
   lbitset_elt *delt = LBITSET_HEAD (dst);
-  bitset_windex windex;
-  lbitset_elt *stmp1;
-  lbitset_elt *stmp2;
-  lbitset_elt *dtmp;
-  bitset_word *srcp1;
-  bitset_word *srcp2;
-  bitset_word *dstp;
   bool changed = false;
 
   LBITSET_HEAD (dst) = 0;
@@ -1012,6 +992,10 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 
   while (selt1 || selt2)
     {
+      bitset_windex windex;
+      lbitset_elt *stmp1;
+      lbitset_elt *stmp2;
+
       /* Figure out whether we need to substitute zero elements for
          missing links.  */
       if (windex1 == windex2)
@@ -1043,6 +1027,7 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 
       /* Find the appropriate element from DST.  Begin by discarding
          elements that we've skipped.  */
+      lbitset_elt *dtmp;
       while (delt && delt->index < windex)
         {
           changed = true;
@@ -1060,9 +1045,9 @@ lbitset_op3_cmp (bitset dst, bitset src1, bitset src2, enum bitset_ops op)
 
       /* Do the operation, and if any bits are set, link it into the
          linked list.  */
-      srcp1 = stmp1->words;
-      srcp2 = stmp2->words;
-      dstp = dtmp->words;
+      bitset_word *srcp1 = stmp1->words;
+      bitset_word *srcp2 = stmp2->words;
+      bitset_word *dstp = dtmp->words;
       switch (op)
         {
         default:
@@ -1164,7 +1149,8 @@ lbitset_and_cmp (bitset dst, bitset src1, bitset src2)
       lbitset_zero (dst);
       return changed;
     }
-  return lbitset_op3_cmp (dst, src1, src2, BITSET_OP_AND);
+  else
+    return lbitset_op3_cmp (dst, src1, src2, BITSET_OP_AND);
 }
 
 
@@ -1192,7 +1178,8 @@ lbitset_andn_cmp (bitset dst, bitset src1, bitset src2)
       lbitset_zero (dst);
       return changed;
     }
-  return lbitset_op3_cmp (dst, src1, src2, BITSET_OP_ANDN);
+  else
+    return lbitset_op3_cmp (dst, src1, src2, BITSET_OP_ANDN);
 }
 
 
@@ -1210,14 +1197,11 @@ lbitset_or_cmp (bitset dst, bitset src1, bitset src2)
   lbitset_elt *selt2 = LBITSET_HEAD (src2);
 
   if (!selt2)
-    {
-      return lbitset_copy_cmp (dst, src1);
-    }
+    return lbitset_copy_cmp (dst, src1);
   else if (!selt1)
-    {
-      return lbitset_copy_cmp (dst, src2);
-    }
-  return lbitset_op3_cmp (dst, src1, src2, BITSET_OP_OR);
+    return lbitset_copy_cmp (dst, src2);
+  else
+    return lbitset_op3_cmp (dst, src1, src2, BITSET_OP_OR);
 }
 
 
@@ -1235,14 +1219,11 @@ lbitset_xor_cmp (bitset dst, bitset src1, bitset src2)
   lbitset_elt *selt2 = LBITSET_HEAD (src2);
 
   if (!selt2)
-    {
-      return lbitset_copy_cmp (dst, src1);
-    }
+    return lbitset_copy_cmp (dst, src1);
   else if (!selt1)
-    {
-      return lbitset_copy_cmp (dst, src2);
-    }
-  return lbitset_op3_cmp (dst, src1, src2, BITSET_OP_XOR);
+    return lbitset_copy_cmp (dst, src2);
+  else
+    return lbitset_op3_cmp (dst, src1, src2, BITSET_OP_XOR);
 }
 
 
