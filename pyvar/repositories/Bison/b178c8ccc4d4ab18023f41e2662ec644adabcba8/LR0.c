@@ -387,114 +387,110 @@ insert_start_shift (void)
 static void
 augment_automaton (void)
 {
-  int i;
-  int k;
   core *statep;
   shifts *sp;
-  shifts *sp2;
   shifts *sp1 = NULL;
 
   sp = first_shift;
 
-  if (sp)
+  if (!sp)
     {
-      if (sp->number == 0)
-	{
-	  k = sp->nshifts;
-	  statep = first_state->next;
+      /* There are no shifts for any state.  Make one shift, from the
+	 initial state to the next-to-final state.  */
 
-	  /* The states reached by shifts from first_state are numbered 1...K.
-	     Look for one reached by start_symbol.  */
-	  while (statep->accessing_symbol < start_symbol
-		 && statep->number < k)
-	    statep = statep->next;
-
-	  if (statep->accessing_symbol == start_symbol)
-	    {
-	      /* We already have a next-to-final state.
-	         Make sure it has a shift to what will be the final state.  */
-	      k = statep->number;
+      sp = shifts_new (1);
+      sp->shifts[0] = nstates;
 
-	      while (sp && sp->number < k)
-		{
-		  sp1 = sp;
-		  sp = sp->next;
-		}
+      /* Initialize the chain of shifts with sp.  */
+      first_shift = sp;
+      last_shift = sp;
 
-	      if (sp && sp->number == k)
-		{
-		  sp2 = shifts_new (sp->nshifts + 1);
-		  sp2->number = k;
-		  sp2->shifts[0] = nstates;
-		  for (i = sp->nshifts; i > 0; i--)
-		    sp2->shifts[i] = sp->shifts[i - 1];
-
-		  /* Patch sp2 into the chain of shifts in place of sp,
-		     following sp1.  */
-		  sp2->next = sp->next;
-		  sp1->next = sp2;
-		  if (sp == last_shift)
-		    last_shift = sp2;
-		  XFREE (sp);
-		}
-	      else
-		{
-		  sp2 = shifts_new (1);
-		  sp2->number = k;
-		  sp2->shifts[0] = nstates;
-
-		  /* Patch sp2 into the chain of shifts between sp1 and sp.  */
-		  sp2->next = sp;
-		  sp1->next = sp2;
-		  if (sp == 0)
-		    last_shift = sp2;
-		}
-	    }
-	  else
-	    {
-	      /* There is no next-to-final state as yet.  */
-	      /* Add one more shift in first_shift,
-	         going to the next-to-final state (yet to be made).  */
-	      sp = first_shift;
+      /* Create the next-to-final state, with shift to
+         what will be the final state.  */
+      insert_start_shift ();
+    }
+  else if (sp->number == 0)
+    {
+      statep = first_state->next;
 
-	      sp2 = shifts_new (sp->nshifts + 1);
+      /* The states reached by shifts from FIRST_STATE are numbered
+	 1..(SP->NSHIFTS).  Look for one reached by START_SYMBOL.  */
+      while (statep->accessing_symbol < start_symbol
+	     && statep->number < sp->nshifts)
+	statep = statep->next;
 
-	      /* Stick this shift into the vector at the proper place.  */
-	      statep = first_state->next;
-	      for (k = 0, i = 0; i < sp->nshifts; k++, i++)
-		{
-		  if (statep->accessing_symbol > start_symbol && i == k)
-		    sp2->shifts[k++] = nstates;
-		  sp2->shifts[k] = sp->shifts[i];
-		  statep = statep->next;
-		}
-	      if (i == k)
-		sp2->shifts[k++] = nstates;
+      if (statep->accessing_symbol == start_symbol)
+	{
+	  /* We already have a next-to-final state.
+	     Make sure it has a shift to what will be the final state.  */
+	  while (sp && sp->number < statep->number)
+	    {
+	      sp1 = sp;
+	      sp = sp->next;
+	    }
 
-	      /* Patch sp2 into the chain of shifts
-	         in place of sp, at the beginning.  */
+	  if (sp && sp->number == statep->number)
+	    {
+	      int i;
+	      shifts *sp2 = shifts_new (sp->nshifts + 1);
+	      sp2->number = statep->number;
+	      sp2->shifts[0] = nstates;
+	      for (i = sp->nshifts; i > 0; i--)
+		sp2->shifts[i] = sp->shifts[i - 1];
+
+	      /* Patch sp2 into the chain of shifts in place of sp,
+		 following sp1.  */
 	      sp2->next = sp->next;
-	      first_shift = sp2;
-	      if (last_shift == sp)
+	      sp1->next = sp2;
+	      if (sp == last_shift)
 		last_shift = sp2;
-
 	      XFREE (sp);
-
-	      /* Create the next-to-final state, with shift to
-	         what will be the final state.  */
-	      insert_start_shift ();
+	    }
+	  else
+	    {
+	      shifts *sp2 = shifts_new (1);
+	      sp2->number = statep->number;
+	      sp2->shifts[0] = nstates;
+
+	      /* Patch sp2 into the chain of shifts between sp1 and sp.  */
+	      sp2->next = sp;
+	      sp1->next = sp2;
+	      if (sp == 0)
+		last_shift = sp2;
 	    }
 	}
       else
 	{
-	  /* The initial state didn't even have any shifts.
-	     Give it one shift, to the next-to-final state.  */
-	  sp = shifts_new (1);
-	  sp->shifts[0] = nstates;
+	  int i, k;
+	  shifts *sp2;
 
-	  /* Patch sp into the chain of shifts at the beginning.  */
-	  sp->next = first_shift;
-	  first_shift = sp;
+	  /* There is no next-to-final state as yet.  */
+	  /* Add one more shift in first_shift,
+	     going to the next-to-final state (yet to be made).  */
+	  sp = first_shift;
+
+	  sp2 = shifts_new (sp->nshifts + 1);
+
+	  /* Stick this shift into the vector at the proper place.  */
+	  statep = first_state->next;
+	  for (k = 0, i = 0; i < sp->nshifts; k++, i++)
+	    {
+	      if (statep->accessing_symbol > start_symbol && i == k)
+		sp2->shifts[k++] = nstates;
+	      sp2->shifts[k] = sp->shifts[i];
+	      statep = statep->next;
+	    }
+	  if (i == k)
+	    sp2->shifts[k++] = nstates;
+
+	  /* Patch sp2 into the chain of shifts
+	     in place of sp, at the beginning.  */
+	  sp2->next = sp->next;
+	  first_shift = sp2;
+	  if (last_shift == sp)
+	    last_shift = sp2;
+
+	  XFREE (sp);
 
 	  /* Create the next-to-final state, with shift to
 	     what will be the final state.  */
@@ -503,18 +499,17 @@ augment_automaton (void)
     }
   else
     {
-      /* There are no shifts for any state.
-         Make one shift, from the initial state to the next-to-final state.  */
-
+      /* The initial state didn't even have any shifts.
+	 Give it one shift, to the next-to-final state.  */
       sp = shifts_new (1);
       sp->shifts[0] = nstates;
 
-      /* Initialize the chain of shifts with sp.  */
+      /* Patch sp into the chain of shifts at the beginning.  */
+      sp->next = first_shift;
       first_shift = sp;
-      last_shift = sp;
 
       /* Create the next-to-final state, with shift to
-         what will be the final state.  */
+	 what will be the final state.  */
       insert_start_shift ();
     }
 
