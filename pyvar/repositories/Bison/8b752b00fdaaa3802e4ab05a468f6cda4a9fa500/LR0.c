@@ -46,10 +46,28 @@ typedef struct state_list_s
 static state_list_t *first_state = NULL;
 static state_list_t *last_state = NULL;
 
-static void
-state_list_append (state_t *state)
+
+/*------------------------------------------------------------------.
+| A state was just discovered from another state.  Queue it for     |
+| later examination, in order to find its transitions.  Return it.  |
+`------------------------------------------------------------------*/
+
+static state_t *
+state_list_append (symbol_number_t symbol,
+		   size_t core_size, item_number_t *core)
 {
   state_list_t *node = XMALLOC (state_list_t, 1);
+  state_t *state = state_new (symbol, core_size, core);
+
+  if (trace_flag)
+    fprintf (stderr, "state_list_append (state = %d, symbol = %d (%s))\n",
+	     nstates, symbol, symbols[symbol]->tag);
+
+  /* If this is the eoftoken, and this is not the initial state, then
+     this is the final state.  */
+  if (symbol == 0 && first_state)
+    final_state = state;
+
   node->next = NULL;
   node->state = state;
 
@@ -58,6 +76,8 @@ state_list_append (state_t *state)
   if (last_state)
     last_state->next = node;
   last_state = node;
+
+  return state;
 }
 
 static int nshifts;
@@ -184,33 +204,6 @@ new_itemsets (state_t *state)
 
 
 
-/*-----------------------------------------------------------------.
-| Subroutine of get_state.  Create a new state for those items, if |
-| necessary.                                                       |
-`-----------------------------------------------------------------*/
-
-static state_t *
-new_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
-{
-  state_t *res;
-
-  if (trace_flag)
-    fprintf (stderr, "Entering new_state, state = %d, symbol = %d (%s)\n",
-	     nstates, symbol, symbols[symbol]->tag);
-
-  res = state_new (symbol, core_size, core);
-  state_hash_insert (res);
-
-  /* If this is the eoftoken, and this is not the initial state, then
-     this is the final state.  */
-  if (symbol == 0 && first_state)
-    final_state = res;
-
-  state_list_append (res);
-  return res;
-}
-
-
 /*--------------------------------------------------------------.
 | Find the state number for the state we would get to (from the |
 | current state) by shifting symbol.  Create a new state if no  |
@@ -228,7 +221,7 @@ get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 
   sp = state_hash_lookup (core_size, core);
   if (!sp)
-    sp = new_state (symbol, core_size, core);
+    sp = state_list_append (symbol, core_size, core);
 
   if (trace_flag)
     fprintf (stderr, "Exiting get_state => %d\n", sp->number);
@@ -277,17 +270,6 @@ append_states (state_t *state)
 }
 
 
-static void
-new_states (void)
-{
-  /* The 0 at the lhs is the index of the item of this initial rule.  */
-  kernel_base[0][0] = 0;
-  kernel_size[0] = 1;
-  state_list_append (new_state (0, kernel_size[0], kernel_base[0]));
-}
-
-
-
 /*----------------------------------------------------------------.
 | Find which rules can be used for reduction transitions from the |
 | current state and make a reductions structure for the state to  |
@@ -332,13 +314,12 @@ set_states (void)
       state_list_t *this = first_state;
 
       /* Pessimization, but simplification of the code: make sure all
-	 the states have a shifts, errs, and reductions, even if
-	 reduced to 0.  */
+	 the states have valid transitions and reductions members,
+	 even if reduced to 0.  It is too soon for errs, which are
+	 computed later, but set_conflicts.  */
       state_t *state = this->state;
-      if (!state->shifts)
+      if (!state->transitions)
 	state_transitions_set (state, 0, 0);
-      if (!state->errs)
-	state->errs = errs_new (0);
       if (!state->reductions)
 	state_reductions_set (state, 0, 0);
 
@@ -363,7 +344,13 @@ generate_states (void)
   state_list_t *list = NULL;
   allocate_storage ();
   new_closure (nritems);
-  new_states ();
+
+  /* Create the initial state.  The 0 at the lhs is the index of the
+     item of this initial rule.  */
+  kernel_base[0][0] = 0;
+  kernel_size[0] = 1;
+  state_list_append (0, kernel_size[0], kernel_base[0]);
+
   list = first_state;
 
   while (list)
