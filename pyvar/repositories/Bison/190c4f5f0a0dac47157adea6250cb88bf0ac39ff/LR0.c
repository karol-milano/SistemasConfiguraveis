@@ -36,11 +36,9 @@
 int nstates;
 int final_state;
 static state_t *first_state = NULL;
-static shifts *first_shift = NULL;
 
 static state_t *this_state = NULL;
 static state_t *last_state = NULL;
-static shifts *last_shift = NULL;
 
 static int nshifts;
 static short *shift_symbol = NULL;
@@ -322,12 +320,6 @@ save_shifts (void)
   p->number = this_state->number;
   shortcpy (p->shifts, shiftset, nshifts);
   this_state->shifts = p;
-
-  if (last_shift)
-    last_shift->next = p;
-  else
-    first_shift = p;
-  last_shift = p;
 }
 
 
@@ -364,9 +356,6 @@ insert_start_shifting_state (void)
   statep->shifts = sp;
   sp->number = nstates++;
   sp->shifts[0] = nstates;
-
-  last_shift->next = sp;
-  last_shift = sp;
 }
 
 
@@ -396,9 +385,6 @@ insert_eof_shifting_state (void)
   statep->shifts = sp;
   sp->number = nstates++;
   sp->shifts[0] = nstates;
-
-  last_shift->next = sp;
-  last_shift = sp;
 }
 
 
@@ -446,10 +432,6 @@ augment_automaton (void)
       first_state->shifts = sp;
       sp->shifts[0] = nstates;
 
-      /* Initialize the chain of shifts with sp.  */
-      first_shift = sp;
-      last_shift = sp;
-
       /* Create the next-to-final state, with shift to
          what will be the final state.  */
       insert_start_shifting_state ();
@@ -473,29 +455,16 @@ augment_automaton (void)
 	     the final state.  */
 	  int i;
 
-	  /* Find the shift that leads to this STATEP. */
-	  shifts *sp = first_state->shifts;
-	  shifts *sp1 = NULL;
-	  shifts *sp2 = NULL;
-	  while (sp->number < statep->number)
-	    {
-	      sp1 = sp;
-	      sp = sp->next;
-	    }
+	  /* Find the shift of the inital state that leads to STATEP.  */
+	  shifts *sp = statep->shifts;
 
-	  sp2 = shifts_new (sp->nshifts + 1);
-	  sp2->number = statep->number;
-	  statep->shifts = sp2;
-	  sp2->shifts[0] = nstates;
+	  shifts *sp1 = shifts_new (sp->nshifts + 1);
+	  sp1->number = statep->number;
+	  statep->shifts = sp1;
+	  sp1->shifts[0] = nstates;
 	  for (i = sp->nshifts; i > 0; i--)
-	    sp2->shifts[i] = sp->shifts[i - 1];
-
-	  /* Patch sp2 into the chain of shifts in place of sp,
-	     following sp1.  */
-	  sp2->next = sp->next;
-	  sp1->next = sp2;
-	  if (sp == last_shift)
-	    last_shift = sp2;
+	    sp1->shifts[i] = sp->shifts[i - 1];
+
 	  XFREE (sp);
 
 	  insert_eof_shifting_state ();
@@ -505,31 +474,23 @@ augment_automaton (void)
 	  /* There is no state for `start: start . ...'. */
 	  int i, k;
 	  shifts *sp = first_state->shifts;
-	  shifts *sp2 = NULL;
+	  shifts *sp1 = NULL;
 
-	  /* There is no next-to-final state as yet.  */
-	  /* Add one more shift in first_shift,
-	     going to the next-to-final state (yet to be made).  */
-	  sp2 = shifts_new (sp->nshifts + 1);
-	  first_state->shifts = sp2;
+	  /* Add one more shift to the initial state, going to the
+	     next-to-final state (yet to be made).  */
+	  sp1 = shifts_new (sp->nshifts + 1);
+	  first_state->shifts = sp1;
 	  /* Stick this shift into the vector at the proper place.  */
 	  statep = first_state->next;
 	  for (k = 0, i = 0; i < sp->nshifts; k++, i++)
 	    {
 	      if (statep->accessing_symbol > start_symbol && i == k)
-		sp2->shifts[k++] = nstates;
-	      sp2->shifts[k] = sp->shifts[i];
+		sp1->shifts[k++] = nstates;
+	      sp1->shifts[k] = sp->shifts[i];
 	      statep = statep->next;
 	    }
 	  if (i == k)
-	    sp2->shifts[k++] = nstates;
-
-	  /* Patch sp2 into the chain of shifts
-	     in place of sp, at the beginning.  */
-	  sp2->next = sp->next;
-	  first_shift = sp2;
-	  if (last_shift == sp)
-	    last_shift = sp2;
+	    sp1->shifts[k++] = nstates;
 
 	  XFREE (sp);
 
