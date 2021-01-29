@@ -37,10 +37,28 @@
 #include "lalr.h"
 #include "reduce.h"
 
-static state_t *first_state = NULL;
+typedef struct state_list_s
+{
+  struct state_list_s *next;
+  state_t *state;
+} state_list_t;
+
+static state_list_t *first_state = NULL;
+static state_list_t *last_state = NULL;
+
+static void
+state_list_append (state_t *state)
+{
+  state_list_t *node = XMALLOC (state_list_t, 1);
+  node->next = NULL;
+  node->state = state;
 
-static state_t *this_state = NULL;
-static state_t *last_state = NULL;
+  if (!first_state)
+    first_state = node;
+  if (last_state)
+    last_state->next = node;
+  last_state = node;
+}
 
 static int nshifts;
 static symbol_number_t *shift_symbol = NULL;
@@ -122,25 +140,25 @@ free_storage (void)
 
 
 
-/*----------------------------------------------------------------.
-| Find which symbols can be shifted in the current state, and for |
-| each one record which items would be active after that shift.   |
-| Uses the contents of itemset.                                   |
-|                                                                 |
-| shift_symbol is set to a vector of the symbols that can be      |
-| shifted.  For each symbol in the grammar, kernel_base[symbol]   |
-| points to a vector of item numbers activated if that symbol is  |
-| shifted, and kernel_size[symbol] is their numbers.              |
-`----------------------------------------------------------------*/
+/*---------------------------------------------------------------.
+| Find which symbols can be shifted in STATE, and for each one   |
+| record which items would be active after that shift.  Uses the |
+| contents of itemset.                                           |
+|                                                                |
+| shift_symbol is set to a vector of the symbols that can be     |
+| shifted.  For each symbol in the grammar, kernel_base[symbol]  |
+| points to a vector of item numbers activated if that symbol is |
+| shifted, and kernel_size[symbol] is their numbers.             |
+`---------------------------------------------------------------*/
 
 static void
-new_itemsets (void)
+new_itemsets (state_t *state)
 {
   int i;
 
   if (trace_flag)
     fprintf (stderr, "Entering new_itemsets, state = %d\n",
-	     this_state->number);
+	     state->number);
 
   for (i = 0; i < nsyms; i++)
     kernel_size[i] = 0;
@@ -187,12 +205,7 @@ new_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
   if (symbol == 0 && first_state)
     final_state = res;
 
-  if (!first_state)
-    first_state = res;
-  if (last_state)
-    last_state->next = res;
-  last_state = res;
-
+  state_list_append (res);
   return res;
 }
 
@@ -209,9 +222,8 @@ get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
   state_t *sp;
 
   if (trace_flag)
-    fprintf (stderr, "Entering get_state, state = %d, symbol = %d (%s)\n",
-	     this_state->number, symbol,
-	     symbol_tag_get (symbols[symbol]));
+    fprintf (stderr, "Entering get_state, symbol = %d (%s)\n",
+	     symbol, symbol_tag_get (symbols[symbol]));
 
   sp = state_hash_lookup (core_size, core);
   if (!sp)
@@ -225,13 +237,13 @@ get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 
 /*------------------------------------------------------------------.
 | Use the information computed by new_itemsets to find the state    |
-| numbers reached by each shift transition from the current state.  |
+| numbers reached by each shift transition from STATE.              |
 |                                                                   |
-| shiftset is set up as a vector of state numbers of those states.  |
+| SHIFTSET is set up as a vector of state numbers of those states.  |
 `------------------------------------------------------------------*/
 
 static void
-append_states (void)
+append_states (state_t *state)
 {
   int i;
   int j;
@@ -239,7 +251,7 @@ append_states (void)
 
   if (trace_flag)
     fprintf (stderr, "Entering append_states, state = %d\n",
-	     this_state->number);
+	     state->number);
 
   /* first sort shift_symbol into increasing order */
 
@@ -270,22 +282,10 @@ new_states (void)
   /* The 0 at the lhs is the index of the item of this initial rule.  */
   kernel_base[0][0] = 0;
   kernel_size[0] = 1;
-  this_state = new_state (0, kernel_size[0], kernel_base[0]);
+  state_list_append (new_state (0, kernel_size[0], kernel_base[0]));
 }
 
 
-/*------------------------------------------------------------.
-| Save the NSHIFTS of SHIFTSET into the current linked list.  |
-`------------------------------------------------------------*/
-
-static void
-save_shifts (void)
-{
-  shifts *p = shifts_new (nshifts);
-  memcpy (p->shifts, shiftset, nshifts * sizeof (shiftset[0]));
-  this_state->shifts = p;
-}
-
 
 /*----------------------------------------------------------------.
 | Find which rules can be used for reduction transitions from the |
@@ -294,14 +294,14 @@ save_shifts (void)
 `----------------------------------------------------------------*/
 
 static void
-save_reductions (void)
+save_reductions (state_t *state)
 {
   int count = 0;
   int i;
 
   /* If this is the final state, we want it to have no reductions at
      all, although it has one for `START_SYMBOL EOF .'.  */
-  if (final_state && this_state->number == final_state->number)
+  if (final_state && state->number == final_state->number)
     return;
 
   /* Find and count the active items that represent ends of rules. */
@@ -313,8 +313,8 @@ save_reductions (void)
     }
 
   /* Make a reductions structure and copy the data into it.  */
-  this_state->reductions = reductions_new (count);
-  memcpy (this_state->reductions->rules, redset, count * sizeof (redset[0]));
+  state->reductions = reductions_new (count);
+  memcpy (state->reductions->rules, redset, count * sizeof (redset[0]));
 }
 
 
@@ -325,23 +325,30 @@ save_reductions (void)
 static void
 set_states (void)
 {
-  state_t *sp;
   states = XCALLOC (state_t *, nstates);
 
-  for (sp = first_state; sp; sp = sp->next)
+  while (first_state)
     {
+      state_list_t *this = first_state;
+
       /* Pessimization, but simplification of the code: make sure all
 	 the states have a shifts, errs, and reductions, even if
 	 reduced to 0.  */
-      if (!sp->shifts)
-	sp->shifts = shifts_new (0);
-      if (!sp->errs)
-	sp->errs = errs_new (0);
-      if (!sp->reductions)
-	sp->reductions = reductions_new (0);
-
-      states[sp->number] = sp;
+      state_t *state = this->state;
+      if (!state->shifts)
+	state_shifts_set (state, 0, 0);
+      if (!state->errs)
+	state->errs = errs_new (0);
+      if (!state->reductions)
+	state->reductions = reductions_new (0);
+
+      states[state->number] = state;
+
+      first_state = this->next;
+      free (this);
     }
+  first_state = NULL;
+  last_state = NULL;
 }
 
 
@@ -353,34 +360,38 @@ set_states (void)
 void
 generate_states (void)
 {
+  state_list_t *list = NULL;
   allocate_storage ();
   new_closure (nritems);
   new_states ();
+  list = first_state;
 
-  while (this_state)
+  while (list)
     {
+      state_t *state = list->state;
       if (trace_flag)
 	fprintf (stderr, "Processing state %d (reached by %s)\n",
-		 this_state->number,
-		 symbol_tag_get (symbols[this_state->accessing_symbol]));
+		 state->number,
+		 symbol_tag_get (symbols[state->accessing_symbol]));
       /* Set up ruleset and itemset for the transitions out of this
          state.  ruleset gets a 1 bit for each rule that could reduce
          now.  itemset gets a vector of all the items that could be
          accepted next.  */
-      closure (this_state->items, this_state->nitems);
-      /* record the reductions allowed out of this state */
-      save_reductions ();
-      /* find the itemsets of the states that shifts can reach */
-      new_itemsets ();
-      /* find or create the core structures for those states */
-      append_states ();
-
-      /* create the shifts structures for the shifts to those states,
-         now that the state numbers transitioning to are known */
-      save_shifts ();
-
-      /* states are queued when they are created; process them all */
-      this_state = this_state->next;
+      closure (state->items, state->nitems);
+      /* Record the reductions allowed out of this state.  */
+      save_reductions (state);
+      /* Find the itemsets of the states that shifts can reach.  */
+      new_itemsets (state);
+      /* Find or create the core structures for those states.  */
+      append_states (state);
+
+      /* Create the shifts structures for the shifts to those states,
+	 now that the state numbers transitioning to are known.  */
+      state_shifts_set (state, nshifts, shiftset);
+
+      /* States are queued when they are created; process them all.
+	 */
+      list = list->next;
     }
 
   /* discard various storage */
