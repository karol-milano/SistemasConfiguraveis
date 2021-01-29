@@ -23,6 +23,7 @@
    The entry point is generate_states.  */
 
 #include "system.h"
+#include "getargs.h"
 #include "gram.h"
 #include "state.h"
 #include "complain.h"
@@ -147,10 +148,8 @@ new_itemsets (void)
   int i;
   int shiftcount;
 
-#if TRACE
-  fprintf (stderr, "Entering new_itemsets, state = %d\n",
-	   this_state->number);
-#endif
+  if (trace_flag)
+    fprintf (stderr, "Entering new_itemsets, state = %d\n", nstates);
 
   for (i = 0; i < nsyms; i++)
     kernel_end[i] = NULL;
@@ -192,10 +191,9 @@ new_state (int symbol)
   int n;
   core *p;
 
-#if TRACE
-  fprintf (stderr, "Entering new_state, state = %d, symbol = %d\n",
-	   nstates, symbol);
-#endif
+  if (trace_flag)
+    fprintf (stderr, "Entering new_state, state = %d, symbol = %d\n",
+	     nstates, symbol);
 
   if (nstates >= MAXSHORT)
     fatal (_("too many states (max %d)"), MAXSHORT);
@@ -233,10 +231,9 @@ get_state (int symbol)
 
   int n = kernel_end[symbol] - kernel_base[symbol];
 
-#if TRACE
-  fprintf (stderr, "Entering get_state, state = %d, symbol = %d\n",
-	   nstates, symbol);
-#endif
+  if (trace_flag)
+    fprintf (stderr, "Entering get_state, state = %d, symbol = %d\n",
+	     nstates, symbol);
 
   /* Add up the target state's active item numbers to get a hash key.
      */
@@ -296,9 +293,9 @@ append_states (void)
   int j;
   int symbol;
 
-#if TRACE
-  fprintf (stderr, "Entering append_states\n");
-#endif
+  if (trace_flag)
+    fprintf (stderr, "Entering append_states\n");
+
 
   /* first sort shift_symbol into increasing order */
 
