@@ -19,15 +19,16 @@
 
 #include <config.h>
 
-#include <time.h>
-#include <hash.h>
-#include <stdlib.h>
+#include "counterexample.h"
+
 #include <gl_linked_list.h>
 #include <gl_rbtreehash_list.h>
+#include <hash.h>
+#include <stdlib.h>
+#include <time.h>
 
 #include "closure.h"
 #include "complain.h"
-#include "counterexample.h"
 #include "derivation.h"
 #include "getargs.h"
 #include "gram.h"
@@ -1202,11 +1203,15 @@ counterexample_report_reduce_reduce (state_item_number itm1, state_item_number i
   fputs ("Reduce-Reduce Conflict:\n", out);
   print_state_item (&state_items[itm1], out);
   print_state_item (&state_items[itm2], out);
-  fputs ("On Symbols: {", out);
+  fputs ("On Symbols: ", out);
   bitset_iterator biter;
   state_item_number sym;
+  const char *sep = "";
   BITSET_FOR_EACH (biter, conflict_syms, sym, 0)
-    fprintf (out, "%s,", symbols[sym]->tag);
-  fputs ("}\n", out);
+    {
+      fprintf (out, "%s%s", sep, symbols[sym]->tag);
+      sep = ", ";
+    }
+  fputs ("\n", out);
   counterexample_report (itm1, itm2, bitset_first (conflict_syms), false);
 }
