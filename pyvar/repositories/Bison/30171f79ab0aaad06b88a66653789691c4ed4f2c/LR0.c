@@ -196,6 +196,10 @@ new_state (int symbol)
   last_state = p;
   nstates++;
 
+  /* If this is the eoftoken, then this is the final state. */
+  if (symbol == 0)
+    final_state = p->number;
+
   return p;
 }
 
@@ -321,184 +325,6 @@ save_shifts (void)
 }
 
 
-/*------------------------------------------------------------------.
-| Subroutine of augment_automaton.  Create the next-to-final state, |
-| to which a shift has already been made in the initial state.      |
-|                                                                   |
-| The task of this state consists in shifting (actually, it's a     |
-| goto, but shifts and gotos are both stored in SHIFTS) the start   |
-| symbols, hence the name.                                          |
-`------------------------------------------------------------------*/
-
-static void
-insert_start_shifting_state (void)
-{
-  state_t *statep;
-  shifts *sp;
-
-  statep = STATE_ALLOC (0);
-  statep->number = nstates++;
-
-  /* The distinctive feature of this state from the
-     eof_shifting_state, is that it is labeled as post-start-symbol
-     shifting.  I fail to understand why this state, and the
-     post-start-start can't be merged into one.  But it does fail if
-     you try. --akim */
-  statep->accessing_symbol = start_symbol;
-
-  last_state->next = statep;
-  last_state = statep;
-
-  /* Make a shift from this state to (what will be) the final state.  */
-  sp = shifts_new (1);
-  statep->shifts = sp;
-  sp->shifts[0] = nstates;
-}
-
-
-/*-----------------------------------------------------------------.
-| Subroutine of augment_automaton.  Create the final state, which  |
-| shifts `0', the end of file.  The initial state shifts the start |
-| symbol, and goes to here.                                        |
-`-----------------------------------------------------------------*/
-
-static void
-insert_eof_shifting_state (void)
-{
-  state_t *statep;
-  shifts *sp;
-
-  /* Make the final state--the one that follows a shift from the
-     next-to-final state.
-     The symbol for that shift is 0 (end-of-file).  */
-  statep = STATE_ALLOC (0);
-  statep->number = nstates++;
-
-  last_state->next = statep;
-  last_state = statep;
-
-  /* Make the shift from the final state to the termination state.  */
-  sp = shifts_new (1);
-  statep->shifts = sp;
-  sp->shifts[0] = nstates;
-}
-
-
-/*---------------------------------------------------------------.
-| Subroutine of augment_automaton.  Create the accepting state.  |
-`---------------------------------------------------------------*/
-
-static void
-insert_accepting_state (void)
-{
-  state_t *statep;
-
-   /* Note that the variable `final_state' refers to what we sometimes
-      call the termination state.  */
-  final_state = nstates;
-
-  /* Make the termination state.  */
-  statep = STATE_ALLOC (0);
-  statep->number = nstates++;
-  last_state->next = statep;
-  last_state = statep;
-}
-
-
-
-
-
-/*------------------------------------------------------------------.
-| Make sure that the initial state has a shift that accepts the     |
-| grammar's start symbol and goes to the next-to-final state, which |
-| has a shift going to the final state, which has a shift to the    |
-| termination state.  Create such states and shifts if they don't   |
-| happen to exist already.                                          |
-`------------------------------------------------------------------*/
-
-static void
-augment_automaton (void)
-{
-  if (!first_state->shifts->nshifts)
-    {
-      /* The first state has no shifts.  Make one shift, from the
-	 initial state to the next-to-final state.  */
-
-      shifts *sp = shifts_new (1);
-      first_state->shifts = sp;
-      sp->shifts[0] = nstates;
-
-      /* Create the next-to-final state, with shift to
-         what will be the final state.  */
-      insert_start_shifting_state ();
-    }
-  else
-    {
-      state_t *statep = first_state->next;
-      /* The states reached by shifts from FIRST_STATE are numbered
-	 1..(SP->NSHIFTS).  Look for one reached by START_SYMBOL.
-	 This is typical of `start: start ... ;': there is a state
-	 with the item `start: start . ...'.  We want to add a `shift
-	 on EOF to eof-shifting state here.  */
-      while (statep->accessing_symbol != start_symbol
-	     && statep->number < first_state->shifts->nshifts)
-	statep = statep->next;
-
-      if (statep->accessing_symbol == start_symbol)
-	{
-	  /* We already have STATEP, a next-to-final state for `start:
-	     start . ...'.  Make sure it has a shift to what will be
-	     the final state.  */
-	  int i;
-
-	  /* Find the shift of the inital state that leads to STATEP.  */
-	  shifts *sp = statep->shifts;
-
-	  shifts *sp1 = shifts_new (sp->nshifts + 1);
-	  statep->shifts = sp1;
-	  sp1->shifts[0] = nstates;
-	  for (i = sp->nshifts; i > 0; i--)
-	    sp1->shifts[i] = sp->shifts[i - 1];
-
-	  XFREE (sp);
-
-	  insert_eof_shifting_state ();
-	}
-      else
-	{
-	  /* There is no state for `start: start . ...'. */
-	  int i, k;
-	  shifts *sp = first_state->shifts;
-	  shifts *sp1 = NULL;
-
-	  /* Add one more shift to the initial state, going to the
-	     next-to-final state (yet to be made).  */
-	  sp1 = shifts_new (sp->nshifts + 1);
-	  first_state->shifts = sp1;
-	  /* Stick this shift into the vector at the proper place.  */
-	  statep = first_state->next;
-	  for (k = 0, i = 0; i < sp->nshifts; k++, i++)
-	    {
-	      if (statep->accessing_symbol > start_symbol && i == k)
-		sp1->shifts[k++] = nstates;
-	      sp1->shifts[k] = sp->shifts[i];
-	      statep = statep->next;
-	    }
-	  if (i == k)
-	    sp1->shifts[k++] = nstates;
-
-	  XFREE (sp);
-
-	  /* Create the next-to-final state, with shift to what will
-	     be the final state.  Corresponds to `start: start . ...'.  */
-	  insert_start_shifting_state ();
-	}
-    }
-
-  insert_accepting_state ();
-}
-
-
 /*----------------------------------------------------------------.
 | Find which rules can be used for reduction transitions from the |
 | current state and make a reductions structure for the state to  |
@@ -508,12 +334,15 @@ augment_automaton (void)
 static void
 save_reductions (void)
 {
-  int count;
+  int count = 0;
   int i;
 
-  /* Find and count the active items that represent ends of rules. */
+  /* If this is the final state, we want it to have no reductions at
+     all, although it has one for `START_SYMBOL EOF .'.  */
+  if (this_state->number == final_state)
+    return;
 
-  count = 0;
+  /* Find and count the active items that represent ends of rules. */
   for (i = 0; i < nitemset; ++i)
     {
       int item = ritem[itemset[i]];
@@ -594,9 +423,6 @@ generate_states (void)
   free_closure ();
   free_storage ();
 
-  /* set up initial and final states as parser wants them */
-  augment_automaton ();
-
   /* Set up STATE_TABLE. */
   set_state_table ();
 }
