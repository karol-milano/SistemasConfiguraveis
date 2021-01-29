@@ -21,6 +21,7 @@
 #include <config.h>
 #include "system.h"
 
+#include <bitset.h>
 #include <bitsetv.h>
 
 #include "complain.h"
@@ -110,7 +111,9 @@ base_number *base = NULL;
    computation equals to BASE_MINIMUM, later mapped to BASE_NINF to
    keep parser tables small.  */
 base_number base_ninf = 0;
-static base_number *pos = NULL;
+/* Bitset representing an integer set in the range
+   -nstates..table_size (as an upper bound) */
+static bitset pos_set = NULL;
 
 static unsigned *conflrow;
 unsigned *conflict_table;
@@ -150,20 +153,23 @@ table_grow (int desired)
     table_size *= 2;
 
   if (trace_flag & trace_resource)
-    fprintf (stderr, "growing table and check from: %d to %d\n",
+    fprintf (stderr, "growing tables from %d to %d\n",
              old_size, table_size);
 
   table = xnrealloc (table, table_size, sizeof *table);
+  memset (table + old_size, 0,
+          sizeof *table * (table_size - old_size));
+
   conflict_table = xnrealloc (conflict_table, table_size,
                               sizeof *conflict_table);
+  memset (conflict_table + old_size, 0,
+          sizeof *conflict_table * (table_size - old_size));
+
   check = xnrealloc (check, table_size, sizeof *check);
+  for (int i = old_size; i < table_size; ++i)
+    check[i] = -1;
 
-  for (/* Nothing. */; old_size < table_size; ++old_size)
-    {
-      table[old_size] = 0;
-      conflict_table[old_size] = 0;
-      check[old_size] = -1;
-    }
+  bitset_resize (pos_set, table_size + nstates);
 }
 
 
@@ -659,10 +665,8 @@ pack_vector (vector_number vector)
               ok = false;
           }
 
-        if (ok)
-          for (int k = 0; k < vector; k++)
-            if (pos[k] == res)
-              ok = false;
+        if (ok && bitset_test (pos_set, nstates + res))
+          ok = false;
       }
 
       if (ok)
@@ -720,7 +724,7 @@ static void
 pack_table (void)
 {
   base = xnmalloc (nvectors, sizeof *base);
-  pos = xnmalloc (nentries, sizeof *pos);
+  pos_set = bitset_create (table_size + nstates, BITSET_FRUGAL);
   table = xcalloc (table_size, sizeof *table);
   conflict_table = xcalloc (table_size, sizeof *conflict_table);
   check = xnmalloc (table_size, sizeof *check);
@@ -746,7 +750,12 @@ pack_table (void)
         /* Action of I were already coded for S.  */
         place = base[s];
 
-      pos[i] = place;
+      /* Store PLACE into POS_SET.  PLACE might not belong to the set
+         of possible values for instance with useless tokens.  It
+         would be more satisfying to eliminate the need for this
+         'if'.  */
+      if (0 <= nstates + place)
+        bitset_set (pos_set, nstates + place);
       base[order[i]] = place;
     }
 
@@ -754,7 +763,7 @@ pack_table (void)
   base_ninf = table_ninf_remap (base, nvectors, BASE_MINIMUM);
   table_ninf = table_ninf_remap (table, high + 1, ACTION_NUMBER_MINIMUM);
 
-  free (pos);
+  bitset_free (pos_set);
 }
 
 
