@@ -63,7 +63,7 @@ state_list_append (symbol_number_t symbol,
     fprintf (stderr, "state_list_append (state = %d, symbol = %d (%s))\n",
 	     nstates, symbol, symbols[symbol]->tag);
 
-  /* If this is the eoftoken, and this is not the initial state, then
+  /* If this is the endtoken, and this is not the initial state, then
      this is the final state.  */
   if (symbol == 0 && first_state)
     final_state = state;
@@ -283,7 +283,7 @@ save_reductions (state_t *state)
   int i;
 
   /* If this is the final state, we want it to have no reductions at
-     all, although it has one for `START_SYMBOL EOF .'.  */
+     all, although it has one for `START_SYMBOL $end .'.  */
   if (final_state && state->number == final_state->number)
     return;
 
