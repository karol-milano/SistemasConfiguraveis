@@ -29,18 +29,19 @@
 
 #include "bitset_stats.h"
 
-#include "bbitset.h"
-#include "abitset.h"
-#include "ebitset.h"
-#include "lbitset.h"
-#include "vbitset.h"
+#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <stdio.h>
 
 #include "gettext.h"
 #define _(Msgid)  gettext (Msgid)
 
+#include "abitset.h"
+#include "bbitset.h"
+#include "ebitset.h"
+#include "lbitset.h"
+#include "vbitset.h"
+
 /* Configuration macros.  */
 #define BITSET_STATS_FILE "bitset.dat"
 #define BITSET_LOG_COUNT_BINS 10
@@ -371,7 +372,7 @@ bitset_stats_test (bitset src, bitset_bindex bitno)
 static bitset_bindex
 bitset_stats_resize (bitset src, bitset_bindex size)
 {
-    return BITSET_RESIZE_ (src->s.bset, size);
+  return BITSET_RESIZE_ (src->s.bset, size);
 }
 
 
@@ -570,30 +571,36 @@ bitset_stats_list (bitset bset, bitset_bindex *list,
 
   BITSET_STATS_LISTS_INC (bset->s.bset);
 
-  bitset_bindex tmp;
-  bitset_bindex size;
-  bitset_bindex i;
-
   /* Log histogram of number of set bits.  */
-  for (i = 0, tmp = count; tmp; tmp >>= 1, i++)
-     continue;
-  if (i >= BITSET_LOG_COUNT_BINS)
-     i = BITSET_LOG_COUNT_BINS - 1;
-  BITSET_STATS_LIST_COUNTS_INC (bset->s.bset, i);
+  {
+    bitset_bindex i;
+    bitset_bindex tmp;
+    for (i = 0, tmp = count; tmp; tmp >>= 1, i++)
+      continue;
+    if (i >= BITSET_LOG_COUNT_BINS)
+      i = BITSET_LOG_COUNT_BINS - 1;
+    BITSET_STATS_LIST_COUNTS_INC (bset->s.bset, i);
+  }
 
   /* Log histogram of number of bits in set.  */
-  size = BITSET_SIZE_ (bset->s.bset);
-  for (i = 0, tmp = size; tmp; tmp >>= 1, i++)
-     continue;
-  if (i >= BITSET_LOG_SIZE_BINS)
-     i = BITSET_LOG_SIZE_BINS - 1;
-  BITSET_STATS_LIST_SIZES_INC (bset->s.bset, i);
+  bitset_bindex size = BITSET_SIZE_ (bset->s.bset);
+  {
+    bitset_bindex i;
+    bitset_bindex tmp;
+    for (i = 0, tmp = size; tmp; tmp >>= 1, i++)
+      continue;
+    if (i >= BITSET_LOG_SIZE_BINS)
+      i = BITSET_LOG_SIZE_BINS - 1;
+    BITSET_STATS_LIST_SIZES_INC (bset->s.bset, i);
+  }
 
   /* Histogram of fraction of bits set.  */
-  i = size ? (count * BITSET_DENSITY_BINS) / size : 0;
-  if (i >= BITSET_DENSITY_BINS)
-     i = BITSET_DENSITY_BINS - 1;
-  BITSET_STATS_LIST_DENSITY_INC (bset->s.bset, i);
+  {
+    bitset_bindex i = size ? (count * BITSET_DENSITY_BINS) / size : 0;
+    if (i >= BITSET_DENSITY_BINS)
+      i = BITSET_DENSITY_BINS - 1;
+    BITSET_STATS_LIST_DENSITY_INC (bset->s.bset, i);
+  }
   return count;
 }
 
@@ -680,40 +687,44 @@ bitset_stats_init (bitset bset, bitset_bindex n_bits, enum bitset_type type)
 
   /* Set up the actual bitset implementation that
      we are a wrapper over.  */
-  size_t bytes;
-  bitset sbset;
   switch (type)
     {
     default:
       abort ();
 
     case BITSET_ARRAY:
-      bytes = abitset_bytes (n_bits);
-      sbset = xcalloc (1, bytes);
-      abitset_init (sbset, n_bits);
+      {
+        size_t bytes = abitset_bytes (n_bits);
+        bset->s.bset = xcalloc (1, bytes);
+        abitset_init (bset->s.bset, n_bits);
+      }
       break;
 
     case BITSET_LIST:
-      bytes = lbitset_bytes (n_bits);
-      sbset = xcalloc (1, bytes);
-      lbitset_init (sbset, n_bits);
+      {
+        size_t bytes = lbitset_bytes (n_bits);
+        bset->s.bset = xcalloc (1, bytes);
+        lbitset_init (bset->s.bset, n_bits);
+      }
       break;
 
     case BITSET_TABLE:
-      bytes = ebitset_bytes (n_bits);
-      sbset = xcalloc (1, bytes);
-      ebitset_init (sbset, n_bits);
+      {
+        size_t bytes = ebitset_bytes (n_bits);
+        bset->s.bset = xcalloc (1, bytes);
+        ebitset_init (bset->s.bset, n_bits);
+      }
       break;
 
     case BITSET_VARRAY:
-      bytes = vbitset_bytes (n_bits);
-      sbset = xcalloc (1, bytes);
-      vbitset_init (sbset, n_bits);
+      {
+        size_t bytes = vbitset_bytes (n_bits);
+        bset->s.bset = xcalloc (1, bytes);
+        vbitset_init (bset->s.bset, n_bits);
+      }
       break;
     }
 
-  bset->s.bset = sbset;
-
   BITSET_STATS_ALLOCS_INC (type);
 
   return bset;
