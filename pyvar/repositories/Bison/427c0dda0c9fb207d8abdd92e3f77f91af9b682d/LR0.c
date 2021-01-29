@@ -62,7 +62,7 @@ state_list_append (symbol_number_t symbol,
   state_t *state = state_new (symbol, core_size, core);
 
   if (trace_flag & trace_automaton)
-    fprintf (stderr, _("state_list_append (state = %d, symbol = %d (%s))\n"),
+    fprintf (stderr, "state_list_append (state = %d, symbol = %d (%s))\n",
 	     nstates, symbol, symbols[symbol]->tag);
 
   /* If this is the endtoken, and this is not the initial state, then
@@ -180,7 +180,7 @@ new_itemsets (state_t *state)
   int i;
 
   if (trace_flag & trace_automaton)
-    fprintf (stderr, _("Entering new_itemsets, state = %d\n"),
+    fprintf (stderr, "Entering new_itemsets, state = %d\n",
 	     state->number);
 
   for (i = 0; i < nsyms; i++)
@@ -218,7 +218,7 @@ get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
   state_t *sp;
 
   if (trace_flag & trace_automaton)
-    fprintf (stderr, _("Entering get_state, symbol = %d (%s)\n"),
+    fprintf (stderr, "Entering get_state, symbol = %d (%s)\n",
 	     symbol, symbols[symbol]->tag);
 
   sp = state_hash_lookup (core_size, core);
@@ -226,7 +226,7 @@ get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
     sp = state_list_append (symbol, core_size, core);
 
   if (trace_flag & trace_automaton)
-    fprintf (stderr, _("Exiting get_state => %d\n"), sp->number);
+    fprintf (stderr, "Exiting get_state => %d\n", sp->number);
 
   return sp;
 }
@@ -246,7 +246,7 @@ append_states (state_t *state)
   symbol_number_t symbol;
 
   if (trace_flag & trace_automaton)
-    fprintf (stderr, _("Entering append_states, state = %d\n"),
+    fprintf (stderr, "Entering append_states, state = %d\n",
 	     state->number);
 
   /* first sort shift_symbol into increasing order */
@@ -354,7 +354,7 @@ generate_states (void)
     {
       state_t *state = list->state;
       if (trace_flag & trace_automaton)
-	fprintf (stderr, _("Processing state %d (reached by %s)\n"),
+	fprintf (stderr, "Processing state %d (reached by %s)\n",
 		 state->number,
 		 symbols[state->accessing_symbol]->tag);
       /* Set up ruleset and itemset for the transitions out of this
