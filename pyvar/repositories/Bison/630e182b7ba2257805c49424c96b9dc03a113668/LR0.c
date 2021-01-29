@@ -30,7 +30,7 @@
 #include "complain.h"
 #include "closure.h"
 #include "LR0.h"
-
+#include "reduce.h"
 
 int nstates;
 int final_state;
@@ -63,11 +63,13 @@ static void
 allocate_itemsets (void)
 {
   int i;
-  int count;
-  short *symbol_count = NULL;
 
-  count = 0;
-  symbol_count = XCALLOC (short, nsyms);
+  /* Count the number of occurrences of all the symbols in RITEMS.
+     Note that useless productions (hence useless nonterminals) are
+     browsed too, hence we need to allocate room for _all_ the
+     symbols.  */
+  int count = 0;
+  short *symbol_count = XCALLOC (short, nsyms + nuseless_nonterminals);
 
   for (i = 0; ritem[i]; ++i)
     if (ritem[i] > 0)
@@ -93,7 +95,7 @@ allocate_itemsets (void)
       count += symbol_count[i];
     }
 
-  shift_symbol = symbol_count;
+  free (symbol_count);
   kernel_size = XCALLOC (int, nsyms);
 }
 
@@ -112,13 +114,13 @@ allocate_storage (void)
 static void
 free_storage (void)
 {
-  XFREE (shift_symbol);
-  XFREE (redset);
-  XFREE (shiftset);
-  XFREE (kernel_base);
-  XFREE (kernel_size);
+  free (shift_symbol);
+  free (redset);
+  free (shiftset);
+  free (kernel_base);
+  free (kernel_size);
   XFREE (kernel_items);
-  XFREE (state_table);
+  free (state_table);
 }
 
 
@@ -148,6 +150,7 @@ new_itemsets (void)
   for (i = 0; i < nsyms; i++)
     kernel_size[i] = 0;
 
+  shift_symbol = XCALLOC (short, nsyms);
   shiftcount = 0;
 
   for (i = 0; i < itemsetsize; ++i)
