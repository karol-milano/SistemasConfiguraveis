@@ -320,8 +320,8 @@ save_shifts (void)
   shifts *p = shifts_new (nshifts);
 
   p->number = this_state->number;
-
   shortcpy (p->shifts, shiftset, nshifts);
+  this_state->shifts = p;
 
   if (last_shift)
     last_shift->next = p;
@@ -361,6 +361,7 @@ insert_start_shifting_state (void)
 
   /* Make a shift from this state to (what will be) the final state.  */
   sp = shifts_new (1);
+  statep->shifts = sp;
   sp->number = nstates++;
   sp->shifts[0] = nstates;
 
@@ -392,6 +393,7 @@ insert_eof_shifting_state (void)
 
   /* Make the shift from the final state to the termination state.  */
   sp = shifts_new (1);
+  statep->shifts = sp;
   sp->number = nstates++;
   sp->shifts[0] = nstates;
 
@@ -441,6 +443,7 @@ augment_automaton (void)
 	 initial state to the next-to-final state.  */
 
       shifts *sp = shifts_new (1);
+      first_state->shifts = sp;
       sp->shifts[0] = nstates;
 
       /* Initialize the chain of shifts with sp.  */
@@ -477,6 +480,7 @@ augment_automaton (void)
 	      int i;
 	      shifts *sp2 = shifts_new (sp->nshifts + 1);
 	      sp2->number = statep->number;
+	      statep->shifts = sp2;
 	      sp2->shifts[0] = nstates;
 	      for (i = sp->nshifts; i > 0; i--)
 		sp2->shifts[i] = sp->shifts[i - 1];
@@ -493,6 +497,7 @@ augment_automaton (void)
 	    {
 	      shifts *sp2 = shifts_new (1);
 	      sp2->number = statep->number;
+	      statep->shifts = sp2;
 	      sp2->shifts[0] = nstates;
 
 	      /* Patch sp2 into the chain of shifts between sp1 and sp.  */
@@ -512,7 +517,7 @@ augment_automaton (void)
 	  /* Add one more shift in first_shift,
 	     going to the next-to-final state (yet to be made).  */
 	  sp2 = shifts_new (sp->nshifts + 1);
-
+	  first_state->shifts = sp2;
 	  /* Stick this shift into the vector at the proper place.  */
 	  statep = first_state->next;
 	  for (k = 0, i = 0; i < sp->nshifts; k++, i++)
@@ -544,6 +549,7 @@ augment_automaton (void)
       /* The initial state didn't even have any shifts.
 	 Give it one shift, to the next-to-final state.  */
       shifts *sp = shifts_new (1);
+      first_state->shifts = sp;
       sp->shifts[0] = nstates;
 
       /* Patch sp into the chain of shifts at the beginning.  */
