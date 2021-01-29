@@ -151,7 +151,8 @@ new_itemsets (void)
   int symbol;
 
 #if TRACE
-  fprintf (stderr, "Entering new_itemsets\n");
+  fprintf (stderr, "Entering new_itemsets, state = %d\n",
+	   this_state->number);
 #endif
 
   for (i = 0; i < nsyms; i++)
@@ -211,8 +212,7 @@ new_state (int symbol)
   iend = kernel_end[symbol];
   n = iend - isp1;
 
-  p =
-    (core *) xcalloc ((unsigned) (sizeof (core) + (n - 1) * sizeof (short)), 1);
+  p = CORE_ALLOC (n);
   p->accessing_symbol = symbol;
   p->number = nstates;
   p->nitems = n;
@@ -350,7 +350,7 @@ new_states (void)
 {
   core *p;
 
-  p = (core *) xcalloc ((unsigned) (sizeof (core) - sizeof (short)), 1);
+  p = CORE_ALLOC (0);
   first_state = last_state = this_state = p;
   nstates = 1;
 }
@@ -364,8 +364,7 @@ save_shifts (void)
   short *sp2;
   short *send;
 
-  p = (shifts *) xcalloc ((unsigned) (sizeof (shifts) +
-				      (nshifts - 1) * sizeof (short)), 1);
+  p = SHIFTS_ALLOC (nshifts);
 
   p->number = this_state->number;
   p->nshifts = nshifts;
@@ -401,7 +400,7 @@ insert_start_shift (void)
   core *statep;
   shifts *sp;
 
-  statep = (core *) xcalloc ((unsigned) (sizeof (core) - sizeof (short)), 1);
+  statep = CORE_ALLOC (0);
   statep->number = nstates;
   statep->accessing_symbol = start_symbol;
 
@@ -409,7 +408,7 @@ insert_start_shift (void)
   last_state = statep;
 
   /* Make a shift from this state to (what will be) the final state.  */
-  sp = XCALLOC (shifts, 1);
+  sp = SHIFTS_ALLOC (1);
   sp->number = nstates++;
   sp->nshifts = 1;
   sp->shifts[0] = nstates;
@@ -466,10 +465,7 @@ augment_automaton (void)
 
 	      if (sp && sp->number == k)
 		{
-		  sp2 = (shifts *) xcalloc ((unsigned) (sizeof (shifts)
-							+
-							sp->nshifts *
-							sizeof (short)), 1);
+		  sp2 = SHIFTS_ALLOC (sp->nshifts + 1);
 		  sp2->number = k;
 		  sp2->nshifts = sp->nshifts + 1;
 		  sp2->shifts[0] = nstates;
@@ -486,7 +482,7 @@ augment_automaton (void)
 		}
 	      else
 		{
-		  sp2 = XCALLOC (shifts, 1);
+		  sp2 = SHIFTS_ALLOC (1);
 		  sp2->number = k;
 		  sp2->nshifts = 1;
 		  sp2->shifts[0] = nstates;
@@ -505,8 +501,7 @@ augment_automaton (void)
 	         going to the next-to-final state (yet to be made).  */
 	      sp = first_shift;
 
-	      sp2 = (shifts *) xcalloc (sizeof (shifts)
-					+ sp->nshifts * sizeof (short), 1);
+	      sp2 = SHIFTS_ALLOC (sp->nshifts + 1);
 	      sp2->nshifts = sp->nshifts + 1;
 
 	      /* Stick this shift into the vector at the proper place.  */
@@ -539,7 +534,7 @@ augment_automaton (void)
 	{
 	  /* The initial state didn't even have any shifts.
 	     Give it one shift, to the next-to-final state.  */
-	  sp = XCALLOC (shifts, 1);
+	  sp = SHIFTS_ALLOC (1);
 	  sp->nshifts = 1;
 	  sp->shifts[0] = nstates;
 
@@ -557,7 +552,7 @@ augment_automaton (void)
       /* There are no shifts for any state.
          Make one shift, from the initial state to the next-to-final state.  */
 
-      sp = XCALLOC (shifts, 1);
+      sp = SHIFTS_ALLOC (1);
       sp->nshifts = 1;
       sp->shifts[0] = nstates;
 
@@ -573,13 +568,13 @@ augment_automaton (void)
   /* Make the final state--the one that follows a shift from the
      next-to-final state.
      The symbol for that shift is 0 (end-of-file).  */
-  statep = (core *) xcalloc ((unsigned) (sizeof (core) - sizeof (short)), 1);
+  statep = CORE_ALLOC (0);
   statep->number = nstates;
   last_state->next = statep;
   last_state = statep;
 
   /* Make the shift from the final state to the termination state.  */
-  sp = XCALLOC (shifts, 1);
+  sp = SHIFTS_ALLOC (1);
   sp->number = nstates++;
   sp->nshifts = 1;
   sp->shifts[0] = nstates;
@@ -591,7 +586,7 @@ augment_automaton (void)
   final_state = nstates;
 
   /* Make the termination state.  */
-  statep = (core *) xcalloc ((unsigned) (sizeof (core) - sizeof (short)), 1);
+  statep = CORE_ALLOC (0);
   statep->number = nstates++;
   last_state->next = statep;
   last_state = statep;
@@ -630,8 +625,7 @@ save_reductions (void)
 
   if (count)
     {
-      p = (reductions *) xcalloc ((unsigned) (sizeof (reductions) +
-					      (count - 1) * sizeof (short)), 1);
+      p = REDUCTIONS_ALLOC (count);
 
       p->number = this_state->number;
       p->nreds = count;
