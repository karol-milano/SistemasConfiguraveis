@@ -334,16 +334,26 @@ save_shifts (void)
 /*------------------------------------------------------------------.
 | Subroutine of augment_automaton.  Create the next-to-final state, |
 | to which a shift has already been made in the initial state.      |
+|                                                                   |
+| The task of this state consists in shifting (actually, it's a     |
+| goto, but shifts and gotos are both stored in SHIFTS) the start   |
+| symbols, hence the name.                                          |
 `------------------------------------------------------------------*/
 
 static void
-insert_start_shift (void)
+insert_start_shifting_state (void)
 {
   state_t *statep;
   shifts *sp;
 
   statep = STATE_ALLOC (0);
   statep->number = nstates;
+
+  /* The distinctive feature of this state from the
+     eof_shifting_state, is that it is labeled as post-start-symbol
+     shifting.  I fail to understand why this state, and the
+     post-start-start can't be merged into one.  But it does fail if
+     you try. --akim */
   statep->accessing_symbol = start_symbol;
 
   last_state->next = statep;
@@ -359,6 +369,61 @@ insert_start_shift (void)
 }
 
 
+/*-----------------------------------------------------------------.
+| Subroutine of augment_automaton.  Create the final state, which  |
+| shifts `0', the end of file.  The initial state shifts the start |
+| symbol, and goes to here.                                        |
+`-----------------------------------------------------------------*/
+
+static void
+insert_eof_shifting_state (void)
+{
+  state_t *statep;
+  shifts *sp;
+
+  /* Make the final state--the one that follows a shift from the
+     next-to-final state.
+     The symbol for that shift is 0 (end-of-file).  */
+  statep = STATE_ALLOC (0);
+  statep->number = nstates;
+
+  last_state->next = statep;
+  last_state = statep;
+
+  /* Make the shift from the final state to the termination state.  */
+  sp = shifts_new (1);
+  sp->number = nstates++;
+  sp->shifts[0] = nstates;
+
+  last_shift->next = sp;
+  last_shift = sp;
+}
+
+
+/*---------------------------------------------------------------.
+| Subroutine of augment_automaton.  Create the accepting state.  |
+`---------------------------------------------------------------*/
+
+static void
+insert_accepting_state (void)
+{
+  state_t *statep;
+
+   /* Note that the variable `final_state' refers to what we sometimes
+      call the termination state.  */
+  final_state = nstates;
+
+  /* Make the termination state.  */
+  statep = STATE_ALLOC (0);
+  statep->number = nstates++;
+  last_state->next = statep;
+  last_state = statep;
+}
+
+
+
+
+
 /*------------------------------------------------------------------.
 | Make sure that the initial state has a shift that accepts the     |
 | grammar's start symbol and goes to the next-to-final state, which |
@@ -370,18 +435,12 @@ insert_start_shift (void)
 static void
 augment_automaton (void)
 {
-  state_t *statep;
-  shifts *sp;
-  shifts *sp1 = NULL;
-
-  sp = first_shift;
-
-  if (!sp->nshifts)
+  if (!first_shift->nshifts)
     {
       /* There are no shifts for any state.  Make one shift, from the
 	 initial state to the next-to-final state.  */
 
-      sp = shifts_new (1);
+      shifts *sp = shifts_new (1);
       sp->shifts[0] = nstates;
 
       /* Initialize the chain of shifts with sp.  */
@@ -390,15 +449,16 @@ augment_automaton (void)
 
       /* Create the next-to-final state, with shift to
          what will be the final state.  */
-      insert_start_shift ();
+      insert_start_shifting_state ();
     }
-  else if (sp->number == 0)
+  else if (first_shift->number == 0)
     {
-      statep = first_state->next;
-
+      state_t *statep = first_state->next;
+      shifts *sp = first_shift;
+      shifts *sp1 = NULL;
       /* The states reached by shifts from FIRST_STATE are numbered
 	 1..(SP->NSHIFTS).  Look for one reached by START_SYMBOL.  */
-      while (statep->accessing_symbol < start_symbol
+      while (statep->accessing_symbol != start_symbol
 	     && statep->number < sp->nshifts)
 	statep = statep->next;
 
@@ -446,12 +506,11 @@ augment_automaton (void)
 	{
 	  int i, k;
 	  shifts *sp2;
+	  sp = first_shift;
 
 	  /* There is no next-to-final state as yet.  */
 	  /* Add one more shift in first_shift,
 	     going to the next-to-final state (yet to be made).  */
-	  sp = first_shift;
-
 	  sp2 = shifts_new (sp->nshifts + 1);
 
 	  /* Stick this shift into the vector at the proper place.  */
@@ -477,14 +536,14 @@ augment_automaton (void)
 
 	  /* Create the next-to-final state, with shift to
 	     what will be the final state.  */
-	  insert_start_shift ();
+	  insert_start_shifting_state ();
 	}
     }
   else
     {
       /* The initial state didn't even have any shifts.
 	 Give it one shift, to the next-to-final state.  */
-      sp = shifts_new (1);
+      shifts *sp = shifts_new (1);
       sp->shifts[0] = nstates;
 
       /* Patch sp into the chain of shifts at the beginning.  */
@@ -493,33 +552,11 @@ augment_automaton (void)
 
       /* Create the next-to-final state, with shift to
 	 what will be the final state.  */
-      insert_start_shift ();
+      insert_start_shifting_state ();
     }
 
-  /* Make the final state--the one that follows a shift from the
-     next-to-final state.
-     The symbol for that shift is 0 (end-of-file).  */
-  statep = STATE_ALLOC (0);
-  statep->number = nstates;
-  last_state->next = statep;
-  last_state = statep;
-
-  /* Make the shift from the final state to the termination state.  */
-  sp = shifts_new (1);
-  sp->number = nstates++;
-  sp->shifts[0] = nstates;
-  last_shift->next = sp;
-  last_shift = sp;
-
-  /* Note that the variable `final_state' refers to what we sometimes call
-     the termination state.  */
-  final_state = nstates;
-
-  /* Make the termination state.  */
-  statep = STATE_ALLOC (0);
-  statep->number = nstates++;
-  last_state->next = statep;
-  last_state = statep;
+  insert_eof_shifting_state ();
+  insert_accepting_state ();
 }
 
 
