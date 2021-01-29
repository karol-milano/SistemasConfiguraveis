@@ -240,7 +240,7 @@ get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 | Use the information computed by new_itemsets to find the state    |
 | numbers reached by each shift transition from STATE.              |
 |                                                                   |
-| SHIFTSET is set up as a vector of state numbers of those states.  |
+| TRANSITIONSET is set up as a vector of state numbers of those states.  |
 `------------------------------------------------------------------*/
 
 static void
@@ -336,7 +336,7 @@ set_states (void)
 	 reduced to 0.  */
       state_t *state = this->state;
       if (!state->shifts)
-	state_shifts_set (state, 0, 0);
+	state_transitions_set (state, 0, 0);
       if (!state->errs)
 	state->errs = errs_new (0);
       if (!state->reductions)
@@ -387,7 +387,7 @@ generate_states (void)
 
       /* Create the shifts structures for the shifts to those states,
 	 now that the state numbers transitioning to are known.  */
-      state_shifts_set (state, nshifts, shiftset);
+      state_transitions_set (state, nshifts, shiftset);
 
       /* States are queued when they are created; process them all.
 	 */
