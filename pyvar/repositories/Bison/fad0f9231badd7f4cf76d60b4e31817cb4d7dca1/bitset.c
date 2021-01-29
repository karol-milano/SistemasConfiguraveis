@@ -24,12 +24,14 @@
 
 #include <stdlib.h>
 #include <string.h>
+
+#include "obstack.h"
+
 #include "abitset.h"
 #include "lbitset.h"
 #include "ebitset.h"
 #include "vbitset.h"
 #include "bitset_stats.h"
-#include "obstack.h"
 
 const char * const bitset_type_names[] = BITSET_TYPE_NAMES;
 
@@ -42,30 +44,23 @@ bitset_bytes (enum bitset_type type, bitset_bindex n_bits)
   if (bitset_stats_enabled)
     return bitset_stats_bytes ();
 
-  size_t bytes;
   switch (type)
     {
     default:
       abort ();
 
     case BITSET_ARRAY:
-      bytes = abitset_bytes (n_bits);
-      break;
+      return abitset_bytes (n_bits);
 
     case BITSET_LIST:
-      bytes = lbitset_bytes (n_bits);
-      break;
+      return lbitset_bytes (n_bits);
 
     case BITSET_TABLE:
-      bytes = ebitset_bytes (n_bits);
-      break;
+      return ebitset_bytes (n_bits);
 
     case BITSET_VARRAY:
-      bytes = vbitset_bytes (n_bits);
-      break;
+      return vbitset_bytes (n_bits);
     }
-
-  return bytes;
 }
 
 
@@ -193,7 +188,7 @@ bitset_type_get (bitset bset)
 {
    enum bitset_type type = BITSET_TYPE_ (bset);
    if (type != BITSET_STATS)
-      return type;
+     return type;
 
    return bitset_stats_type_get (bset);
 }
@@ -214,9 +209,8 @@ bitset_type_name_get (bitset bset)
 bitset_bindex
 bitset_next (bitset src, bitset_bindex bitno)
 {
-  bitset_bindex val;
   bitset_bindex next = bitno;
-
+  bitset_bindex val;
   if (!bitset_list (src, &val, 1, &next))
     return BITSET_BINDEX_MAX;
   return val;
@@ -236,9 +230,8 @@ bitset_compatible_p (bitset bset1, bitset bset2)
 bitset_bindex
 bitset_prev (bitset src, bitset_bindex bitno)
 {
-  bitset_bindex val;
   bitset_bindex next = bitno;
-
+  bitset_bindex val;
   if (!bitset_list_reverse (src, &val, 1, &next))
     return BITSET_BINDEX_MAX;
   return val;
@@ -295,7 +288,7 @@ bitset_print (FILE *file, bitset bset, bool verbose)
 
     fprintf (file, "%lu ", (unsigned long) i);
     pos += 1 + (i >= 10) + (i >= 100);
-  };
+  }
 
   if (verbose)
     fprintf (file, "}\n");
@@ -351,17 +344,18 @@ bitset_bindex
 bitset_count_ (bitset src)
 {
   bitset_bindex list[BITSET_LIST_SIZE];
-  bitset_bindex num;
-  bitset_bindex count;
+  bitset_bindex count = 0;
 
   /* This could be greatly sped up by adding a count method for each
      bitset implementation that uses a direct technique (based on
      masks) for counting the number of bits set in a word.  */
 
-  bitset_bindex next = 0;
-  for (count = 0; (num = bitset_list (src, list, BITSET_LIST_SIZE, &next));
-       count += num)
-    continue;
+  {
+    bitset_bindex next = 0;
+    bitset_bindex num;
+    while (num = bitset_list (src, list, BITSET_LIST_SIZE, &next))
+      count += num;
+  }
 
   return count;
 }
@@ -382,7 +376,7 @@ bitset_copy_ (bitset dst, bitset src)
   BITSET_FOR_EACH (iter, src, i, 0)
   {
      bitset_set (dst, i);
-  };
+  }
 
   return true;
 }
