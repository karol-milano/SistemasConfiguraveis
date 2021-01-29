@@ -21,10 +21,12 @@
 #endif
 
 #include <stdlib.h>
+#include <string.h>
 #include "bitset.h"
 #include "abitset.h"
 #include "lbitset.h"
 #include "ebitset.h"
+#include "vbitset.h"
 #include "bitset_stats.h"
 #include "obstack.h"
 
@@ -55,6 +57,10 @@ bitset_bytes (enum bitset_type type, bitset_bindex n_bits)
       bytes = ebitset_bytes (n_bits);
       break;
 
+    case BITSET_VARRAY:
+      bytes = vbitset_bytes (n_bits);
+      break;
+
     default:
       abort ();
     }
@@ -81,6 +87,9 @@ bitset_init (bitset bset, bitset_bindex n_bits, enum bitset_type type)
     case BITSET_TABLE:
       return ebitset_init (bset, n_bits);
 
+    case BITSET_VARRAY:
+      return vbitset_init (bset, n_bits);
+
     default:
       abort ();
     }
@@ -93,27 +102,30 @@ bitset_init (bitset bset, bitset_bindex n_bits, enum bitset_type type)
 enum bitset_type
 bitset_type_choose (bitset_bindex n_bits ATTRIBUTE_UNUSED, unsigned int attr)
 {
-  enum bitset_type type;
-
   /* Check attributes.  */
   if (attr & BITSET_FIXED && attr & BITSET_VARIABLE)
     abort ();
   if (attr & BITSET_SPARSE && attr & BITSET_DENSE)
     abort ();
 
-  /* Choose the type of bitset. Note that sometimes we will be asked
+  /* Choose the type of bitset.  Note that sometimes we will be asked
   for a zero length fixed size bitset.  */
 
-  type = BITSET_ARRAY;
-  /* Currently, the simple bitsets do not support a variable size.  */
-  if (attr & BITSET_VARIABLE || attr & BITSET_SPARSE)
-    {
-      type = BITSET_LIST;
-      if (attr & BITSET_DENSE || attr & BITSET_GREEDY)
-	type = BITSET_TABLE;
-    }
+  
+  /* If no attributes selected, choose a good compromise.  */
+  if (!attr)
+    return BITSET_VARRAY;
+
+  if (attr & BITSET_SPARSE)
+    return BITSET_LIST;
+
+  if (attr & BITSET_FIXED)
+    return BITSET_ARRAY;
 
-  return type;
+  if (attr & BITSET_GREEDY)
+    return BITSET_TABLE;
+
+  return BITSET_VARRAY;
 }
 
 
@@ -223,6 +235,14 @@ bitset_next (bitset src, bitset_bindex bitno)
 }
 
 
+/* Return true if both bitsets are of the same type and size.  */
+extern bool
+bitset_compatible_p (bitset bset1, bitset bset2)
+{
+    return BITSET_COMPATIBLE_ (bset1, bset2);
+}
+
+
 /* Find previous bit set in SRC starting from and including BITNO.
    Return BITSET_BINDEX_MAX if SRC empty.  */
 bitset_bindex
@@ -304,7 +324,6 @@ bitset_dump (FILE *file, bitset bset)
 }
 
 
-
 /* Release memory associated with bitsets.  */
 void
 bitset_release_memory (void)
@@ -314,7 +333,6 @@ bitset_release_memory (void)
 }
 
 
-
 /* Toggle bit BITNO in bitset BSET and the new value of the bit.  */
 bool
 bitset_toggle_ (bitset bset, bitset_bindex bitno)
@@ -334,6 +352,14 @@ bitset_toggle_ (bitset bset, bitset_bindex bitno)
 }
 
 
+/* Return number of bits in bitset SRC.  */
+bitset_bindex
+bitset_size_ (bitset src)
+{
+    return BITSET_NBITS_ (src);
+}
+
+
 /* Return number of bits set in bitset SRC.  */
 bitset_bindex
 bitset_count_ (bitset src)
