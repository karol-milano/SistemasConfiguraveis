@@ -37,10 +37,6 @@
 #include "lalr.h"
 #include "reduce.h"
 
-state_number_t nstates = 0;
-/* FINAL_STATE is properly set by new_state when it recognizes its
-   accessing symbol: EOF.  */
-state_t *final_state = NULL;
 static state_t *first_state = NULL;
 
 static state_t *this_state = NULL;
@@ -182,37 +178,26 @@ new_itemsets (void)
 static state_t *
 new_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 {
-  state_t *p;
+  state_t *res;
 
   if (trace_flag)
     fprintf (stderr, "Entering new_state, state = %d, symbol = %d (%s)\n",
 	     nstates, symbol, symbol_tag_get (symbols[symbol]));
 
-  if (nstates >= STATE_NUMBER_MAX)
-    fatal (_("too many states (max %d)"), STATE_NUMBER_MAX);
-
-  p = STATE_ALLOC (core_size);
-  p->accessing_symbol = symbol;
-  p->number = nstates;
-  p->solved_conflicts = NULL;
-
-  p->nitems = core_size;
-  memcpy (p->items, core, core_size * sizeof (core[0]));
+  res = state_new (symbol, core_size, core);
 
   /* If this is the eoftoken, and this is not the initial state, then
      this is the final state.  */
   if (symbol == 0 && first_state)
-    final_state = p;
+    final_state = res;
 
   if (!first_state)
-    first_state = p;
+    first_state = res;
   if (last_state)
-    last_state->next = p;
-  last_state = p;
-
-  nstates++;
+    last_state->next = res;
+  last_state = res;
 
-  return p;
+  return res;
 }
 
 
