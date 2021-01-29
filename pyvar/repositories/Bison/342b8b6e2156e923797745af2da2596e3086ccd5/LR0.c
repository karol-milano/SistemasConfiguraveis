@@ -23,7 +23,6 @@
    The entry point is generate_states.  */
 
 #include "system.h"
-#include "xalloc.h"
 #include "gram.h"
 #include "state.h"
 #include "complain.h"
@@ -33,39 +32,39 @@
 
 int nstates;
 int final_state;
-core *first_state;
-shifts *first_shift;
-reductions *first_reduction;
+core *first_state = NULL;
+shifts *first_shift = NULL;
+reductions *first_reduction = NULL;
 
-static core *this_state;
-static core *last_state;
-static shifts *last_shift;
-static reductions *last_reduction;
+static core *this_state = NULL;
+static core *last_state = NULL;
+static shifts *last_shift = NULL;
+static reductions *last_reduction = NULL;
 
 static int nshifts;
-static short *shift_symbol;
+static short *shift_symbol = NULL;
 
-static short *redset;
-static short *shiftset;
+static short *redset = NULL;
+static short *shiftset = NULL;
 
-static short **kernel_base;
-static short **kernel_end;
-static short *kernel_items;
+static short **kernel_base = NULL;
+static short **kernel_end = NULL;
+static short *kernel_items = NULL;
 
 /* hash table for states, to recognize equivalent ones.  */
 
 #define	STATE_TABLE_SIZE	1009
-static core **state_table;
+static core **state_table = NULL;
 
 
 static void
 allocate_itemsets (void)
 {
-  short *itemp;
+  short *itemp = NULL;
   int symbol;
   int i;
   int count;
-  short *symbol_count;
+  short *symbol_count = NULL;
 
   count = 0;
   symbol_count = XCALLOC (short, nsyms);
@@ -89,7 +88,8 @@ allocate_itemsets (void)
      We allocate that much space for each symbol.  */
 
   kernel_base = XCALLOC (short *, nsyms);
-  kernel_items = XCALLOC (short, count);
+  if (count)
+    kernel_items = XCALLOC (short, count);
 
   count = 0;
   for (i = 0; i < nsyms; i++)
