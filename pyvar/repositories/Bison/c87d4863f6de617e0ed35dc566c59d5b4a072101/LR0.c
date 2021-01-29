@@ -24,6 +24,7 @@
 
 #include "system.h"
 #include "getargs.h"
+#include "reader.h"
 #include "gram.h"
 #include "state.h"
 #include "complain.h"
@@ -61,8 +62,6 @@ static core **state_table = NULL;
 static void
 allocate_itemsets (void)
 {
-  short *itemp = NULL;
-  int symbol;
   int i;
   int count;
   short *symbol_count = NULL;
@@ -70,17 +69,12 @@ allocate_itemsets (void)
   count = 0;
   symbol_count = XCALLOC (short, nsyms);
 
-  itemp = ritem;
-  symbol = *itemp++;
-  while (symbol)
-    {
-      if (symbol > 0)
-	{
-	  count++;
-	  symbol_count[symbol]++;
-	}
-      symbol = *itemp++;
-    }
+  for (i = 0; ritem[i]; ++i)
+    if (ritem[i] > 0)
+      {
+	count++;
+	symbol_count[ritem[i]]++;
+      }
 
   /* See comments before new_itemsets.  All the vectors of items
      live inside KERNEL_ITEMS.  The number of active items after
@@ -149,7 +143,8 @@ new_itemsets (void)
   int shiftcount;
 
   if (trace_flag)
-    fprintf (stderr, "Entering new_itemsets, state = %d\n", nstates);
+    fprintf (stderr, "Entering new_itemsets, state = %d\n",
+	     this_state->number);
 
   for (i = 0; i < nsyms; i++)
     kernel_end[i] = NULL;
@@ -192,8 +187,8 @@ new_state (int symbol)
   core *p;
 
   if (trace_flag)
-    fprintf (stderr, "Entering new_state, state = %d, symbol = %d\n",
-	     nstates, symbol);
+    fprintf (stderr, "Entering new_state, state = %d, symbol = %d (%s)\n",
+	     this_state->number, symbol, tags[symbol]);
 
   if (nstates >= MAXSHORT)
     fatal (_("too many states (max %d)"), MAXSHORT);
@@ -232,8 +227,8 @@ get_state (int symbol)
   int n = kernel_end[symbol] - kernel_base[symbol];
 
   if (trace_flag)
-    fprintf (stderr, "Entering get_state, state = %d, symbol = %d\n",
-	     nstates, symbol);
+    fprintf (stderr, "Entering get_state, state = %d, symbol = %d (%s)\n",
+	     this_state->number, symbol, tags[symbol]);
 
   /* Add up the target state's active item numbers to get a hash key.
      */
@@ -276,6 +271,9 @@ get_state (int symbol)
       state_table[key] = sp = new_state (symbol);
     }
 
+  if (trace_flag)
+    fprintf (stderr, "Exiting get_state => %d\n", sp->number);
+
   return sp->number;
 }
 
@@ -294,8 +292,8 @@ append_states (void)
   int symbol;
 
   if (trace_flag)
-    fprintf (stderr, "Entering append_states\n");
-
+    fprintf (stderr, "Entering append_states, state = %d\n",
+	     this_state->number);
 
   /* first sort shift_symbol into increasing order */
 
