@@ -316,8 +316,6 @@ static void
 save_shifts (void)
 {
   shifts *p = shifts_new (nshifts);
-
-  p->number = this_state->number;
   shortcpy (p->shifts, shiftset, nshifts);
   this_state->shifts = p;
 }
@@ -339,7 +337,7 @@ insert_start_shifting_state (void)
   shifts *sp;
 
   statep = STATE_ALLOC (0);
-  statep->number = nstates;
+  statep->number = nstates++;
 
   /* The distinctive feature of this state from the
      eof_shifting_state, is that it is labeled as post-start-symbol
@@ -354,7 +352,6 @@ insert_start_shifting_state (void)
   /* Make a shift from this state to (what will be) the final state.  */
   sp = shifts_new (1);
   statep->shifts = sp;
-  sp->number = nstates++;
   sp->shifts[0] = nstates;
 }
 
@@ -375,7 +372,7 @@ insert_eof_shifting_state (void)
      next-to-final state.
      The symbol for that shift is 0 (end-of-file).  */
   statep = STATE_ALLOC (0);
-  statep->number = nstates;
+  statep->number = nstates++;
 
   last_state->next = statep;
   last_state = statep;
@@ -383,7 +380,6 @@ insert_eof_shifting_state (void)
   /* Make the shift from the final state to the termination state.  */
   sp = shifts_new (1);
   statep->shifts = sp;
-  sp->number = nstates++;
   sp->shifts[0] = nstates;
 }
 
@@ -459,7 +455,6 @@ augment_automaton (void)
 	  shifts *sp = statep->shifts;
 
 	  shifts *sp1 = shifts_new (sp->nshifts + 1);
-	  sp1->number = statep->number;
 	  statep->shifts = sp1;
 	  sp1->shifts[0] = nstates;
 	  for (i = sp->nshifts; i > 0; i--)
