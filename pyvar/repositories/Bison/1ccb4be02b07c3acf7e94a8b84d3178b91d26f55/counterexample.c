@@ -21,6 +21,8 @@
 
 #include "counterexample.h"
 
+#include "system.h"
+
 #include <gl_linked_list.h>
 #include <gl_rbtreehash_list.h>
 #include <hash.h>
@@ -1214,10 +1216,9 @@ counterexample_report_shift_reduce (state_item_number itm1, state_item_number it
                                     symbol_number next_sym)
 {
   FILE *out = stderr;
-  fputs ("Shift-Reduce Conflict:\n", out);
+  fprintf (out, _("Shift/reduce conflict on token %s:\n"), symbols[next_sym]->tag);
   print_state_item (&state_items[itm1], out);
   print_state_item (&state_items[itm2], out);
-  fprintf (out, "On Symbol: %s\n", symbols[next_sym]->tag);
   counterexample_report (itm1, itm2, next_sym, true);
 }
 
@@ -1226,18 +1227,21 @@ counterexample_report_reduce_reduce (state_item_number itm1, state_item_number i
                                      bitset conflict_syms)
 {
   FILE *out = stderr;
-  fputs ("Reduce-Reduce Conflict:\n", out);
+  {
+    fputs (ngettext ("Reduce/reduce conflict on token",
+                     "Reduce/reduce conflict on tokens",
+                     bitset_count (conflict_syms)), out);
+    bitset_iterator biter;
+    state_item_number sym;
+    const char *sep = " ";
+    BITSET_FOR_EACH (biter, conflict_syms, sym, 0)
+      {
+        fprintf (out, "%s%s", sep, symbols[sym]->tag);
+        sep = ", ";
+      }
+    fputs (_(":\n"), out);
+  }
   print_state_item (&state_items[itm1], out);
   print_state_item (&state_items[itm2], out);
-  fputs ("On Symbols: ", out);
-  bitset_iterator biter;
-  state_item_number sym;
-  const char *sep = "";
-  BITSET_FOR_EACH (biter, conflict_syms, sym, 0)
-    {
-      fprintf (out, "%s%s", sep, symbols[sym]->tag);
-      sep = ", ";
-    }
-  fputs ("\n", out);
   counterexample_report (itm1, itm2, bitset_first (conflict_syms), false);
 }
