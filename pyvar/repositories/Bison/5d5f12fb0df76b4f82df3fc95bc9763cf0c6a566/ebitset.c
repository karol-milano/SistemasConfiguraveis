@@ -22,10 +22,11 @@
 
 #include "ebitset.h"
 
-#include "obstack.h"
 #include <stdlib.h>
 #include <string.h>
 
+#include "obstack.h"
+
 /* This file implements expandable bitsets.  These bitsets can be of
    arbitrary length and are more efficient than arrays of bits for
    large sparse sets.
@@ -73,7 +74,7 @@ typedef ebitset_elt *ebitset_elts;
 /* Number of elements to initially allocate.  */
 
 #ifndef EBITSET_INITIAL_SIZE
-#define EBITSET_INITIAL_SIZE 2
+# define EBITSET_INITIAL_SIZE 2
 #endif
 
 
@@ -131,8 +132,6 @@ ebitset_resize (bitset src, bitset_bindex n_bits)
 
   if (oldsize < newsize)
     {
-      bitset_windex size;
-
       /* The bitset needs to grow.  If we already have enough memory
          allocated, then just zero what we need.  */
       if (newsize > EBITSET_ASIZE (src))
@@ -142,11 +141,7 @@ ebitset_resize (bitset src, bitset_bindex n_bits)
              grow the bitset 25% larger than requested to reduce
              number of reallocations.  */
 
-          if (oldsize == 0)
-            size = newsize;
-          else
-            size = newsize + newsize / 4;
-
+          bitset_windex size = oldsize == 0 ? newsize : newsize + newsize / 4;
           EBITSET_ELTS (src)
             = realloc (EBITSET_ELTS (src), size * sizeof (ebitset_elt *));
           EBITSET_ASIZE (src) = size;
@@ -274,7 +269,6 @@ ebitset_elt_zero_p (ebitset_elt *elt)
   for (int i = 0; i < EBITSET_ELT_WORDS; i++)
     if (EBITSET_WORDS (elt)[i])
       return false;
-
   return true;
 }
 
@@ -378,7 +372,6 @@ ebitset_zero (bitset bset)
   for (bitset_windex j = 0; j < EBITSET_SIZE (bset); j++)
     {
       ebitset_elt *elt = elts[j];
-
       if (elt)
         ebitset_elt_remove (bset, j);
     }
@@ -439,7 +432,6 @@ ebitset_copy_ (bitset dst, bitset src)
   for (bitset_windex j = 0; j < EBITSET_SIZE (src); j++)
     {
       ebitset_elt *selt = selts[j];
-
       if (selt)
         {
           ebitset_elt *tmp = ebitset_elt_alloc ();
