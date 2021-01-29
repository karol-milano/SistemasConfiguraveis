@@ -457,18 +457,22 @@ augment_automaton (void)
   else
     {
       state_t *statep = first_state->next;
-      shifts *sp = first_shift;
+      shifts *sp = first_state->shifts;
       shifts *sp1 = NULL;
       /* The states reached by shifts from FIRST_STATE are numbered
-	 1..(SP->NSHIFTS).  Look for one reached by START_SYMBOL.  */
+	 1..(SP->NSHIFTS).  Look for one reached by START_SYMBOL.
+	 This is typical of `start: start ... ;': there is a state
+	 with the item `start: start . ...'.  We want to add a `shift
+	 on EOF to eof-shifting state here.  */
       while (statep->accessing_symbol != start_symbol
 	     && statep->number < sp->nshifts)
 	statep = statep->next;
 
       if (statep->accessing_symbol == start_symbol)
 	{
-	  /* We already have a next-to-final state.
-	     Make sure it has a shift to what will be the final state.  */
+	  /* We already have a next-to-final state, i.e., for `start:
+	     start . ...'.  Make sure it has a shift to what will be
+	     the final state.  */
 	  while (sp && sp->number < statep->number)
 	    {
 	      sp1 = sp;
@@ -506,9 +510,11 @@ augment_automaton (void)
 	      if (sp == 0)
 		last_shift = sp2;
 	    }
+	  insert_eof_shifting_state ();
 	}
       else
 	{
+	  /* There is no state for `start: start . ...'. */
 	  int i, k;
 	  shifts *sp2;
 	  sp = first_shift;
@@ -539,13 +545,12 @@ augment_automaton (void)
 
 	  XFREE (sp);
 
-	  /* Create the next-to-final state, with shift to
-	     what will be the final state.  */
+	  /* Create the next-to-final state, with shift to what will
+	     be the final state.  Corresponds to `start: start . ...'.  */
 	  insert_start_shifting_state ();
 	}
     }
 
-  insert_eof_shifting_state ();
   insert_accepting_state ();
 }
 
