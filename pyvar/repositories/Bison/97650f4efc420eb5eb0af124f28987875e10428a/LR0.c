@@ -196,7 +196,7 @@ new_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 
   if (trace_flag)
     fprintf (stderr, "Entering new_state, state = %d, symbol = %d (%s)\n",
-	     nstates, symbol, symbol_tag_get (symbols[symbol]));
+	     nstates, symbol, symbols[symbol]->tag);
 
   res = state_new (symbol, core_size, core);
   state_hash_insert (res);
@@ -224,7 +224,7 @@ get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 
   if (trace_flag)
     fprintf (stderr, "Entering get_state, symbol = %d (%s)\n",
-	     symbol, symbol_tag_get (symbols[symbol]));
+	     symbol, symbols[symbol]->tag);
 
   sp = state_hash_lookup (core_size, core);
   if (!sp)
@@ -372,7 +372,7 @@ generate_states (void)
       if (trace_flag)
 	fprintf (stderr, "Processing state %d (reached by %s)\n",
 		 state->number,
-		 symbol_tag_get (symbols[state->accessing_symbol]));
+		 symbols[state->accessing_symbol]->tag);
       /* Set up ruleset and itemset for the transitions out of this
          state.  ruleset gets a 1 bit for each rule that could reduce
          now.  itemset gets a vector of all the items that could be
