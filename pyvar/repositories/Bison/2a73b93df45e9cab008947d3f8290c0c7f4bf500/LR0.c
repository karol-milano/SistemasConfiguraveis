@@ -457,67 +457,55 @@ augment_automaton (void)
   else
     {
       state_t *statep = first_state->next;
-      shifts *sp = first_state->shifts;
-      shifts *sp1 = NULL;
       /* The states reached by shifts from FIRST_STATE are numbered
 	 1..(SP->NSHIFTS).  Look for one reached by START_SYMBOL.
 	 This is typical of `start: start ... ;': there is a state
 	 with the item `start: start . ...'.  We want to add a `shift
 	 on EOF to eof-shifting state here.  */
       while (statep->accessing_symbol != start_symbol
-	     && statep->number < sp->nshifts)
+	     && statep->number < first_state->shifts->nshifts)
 	statep = statep->next;
 
       if (statep->accessing_symbol == start_symbol)
 	{
-	  /* We already have a next-to-final state, i.e., for `start:
+	  /* We already have STATEP, a next-to-final state for `start:
 	     start . ...'.  Make sure it has a shift to what will be
 	     the final state.  */
-	  while (sp && sp->number < statep->number)
+	  int i;
+
+	  /* Find the shift that leads to this STATEP. */
+	  shifts *sp = first_state->shifts;
+	  shifts *sp1 = NULL;
+	  shifts *sp2 = NULL;
+	  while (sp->number < statep->number)
 	    {
 	      sp1 = sp;
 	      sp = sp->next;
 	    }
 
-	  if (sp && sp->number == statep->number)
-	    {
-	      int i;
-	      shifts *sp2 = shifts_new (sp->nshifts + 1);
-	      sp2->number = statep->number;
-	      statep->shifts = sp2;
-	      sp2->shifts[0] = nstates;
-	      for (i = sp->nshifts; i > 0; i--)
-		sp2->shifts[i] = sp->shifts[i - 1];
-
-	      /* Patch sp2 into the chain of shifts in place of sp,
-		 following sp1.  */
-	      sp2->next = sp->next;
-	      sp1->next = sp2;
-	      if (sp == last_shift)
-		last_shift = sp2;
-	      XFREE (sp);
-	    }
-	  else
-	    {
-	      shifts *sp2 = shifts_new (1);
-	      sp2->number = statep->number;
-	      statep->shifts = sp2;
-	      sp2->shifts[0] = nstates;
-
-	      /* Patch sp2 into the chain of shifts between sp1 and sp.  */
-	      sp2->next = sp;
-	      sp1->next = sp2;
-	      if (sp == 0)
-		last_shift = sp2;
-	    }
+	  sp2 = shifts_new (sp->nshifts + 1);
+	  sp2->number = statep->number;
+	  statep->shifts = sp2;
+	  sp2->shifts[0] = nstates;
+	  for (i = sp->nshifts; i > 0; i--)
+	    sp2->shifts[i] = sp->shifts[i - 1];
+
+	  /* Patch sp2 into the chain of shifts in place of sp,
+	     following sp1.  */
+	  sp2->next = sp->next;
+	  sp1->next = sp2;
+	  if (sp == last_shift)
+	    last_shift = sp2;
+	  XFREE (sp);
+
 	  insert_eof_shifting_state ();
 	}
       else
 	{
 	  /* There is no state for `start: start . ...'. */
 	  int i, k;
-	  shifts *sp2;
-	  sp = first_shift;
+	  shifts *sp = first_state->shifts;
+	  shifts *sp2 = NULL;
 
 	  /* There is no next-to-final state as yet.  */
 	  /* Add one more shift in first_shift,
