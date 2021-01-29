@@ -59,7 +59,7 @@ state_list_append (symbol_number_t symbol,
   state_list_t *node = XMALLOC (state_list_t, 1);
   state_t *state = state_new (symbol, core_size, core);
 
-  if (trace_flag)
+  if (trace_flag & trace_automaton)
     fprintf (stderr, "state_list_append (state = %d, symbol = %d (%s))\n",
 	     nstates, symbol, symbols[symbol]->tag);
 
@@ -177,7 +177,7 @@ new_itemsets (state_t *state)
 {
   int i;
 
-  if (trace_flag)
+  if (trace_flag & trace_automaton)
     fprintf (stderr, "Entering new_itemsets, state = %d\n",
 	     state->number);
 
@@ -215,7 +215,7 @@ get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 {
   state_t *sp;
 
-  if (trace_flag)
+  if (trace_flag & trace_automaton)
     fprintf (stderr, "Entering get_state, symbol = %d (%s)\n",
 	     symbol, symbols[symbol]->tag);
 
@@ -223,7 +223,7 @@ get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
   if (!sp)
     sp = state_list_append (symbol, core_size, core);
 
-  if (trace_flag)
+  if (trace_flag & trace_automaton)
     fprintf (stderr, "Exiting get_state => %d\n", sp->number);
 
   return sp;
@@ -243,7 +243,7 @@ append_states (state_t *state)
   int j;
   symbol_number_t symbol;
 
-  if (trace_flag)
+  if (trace_flag & trace_automaton)
     fprintf (stderr, "Entering append_states, state = %d\n",
 	     state->number);
 
@@ -351,7 +351,7 @@ generate_states (void)
   while (list)
     {
       state_t *state = list->state;
-      if (trace_flag)
+      if (trace_flag & trace_automaton)
 	fprintf (stderr, "Processing state %d (reached by %s)\n",
 		 state->number,
 		 symbols[state->accessing_symbol]->tag);
