@@ -311,13 +311,29 @@ new_states (void)
 }
 
 
+/*---------------------------------.
+| Create a new array of N shitfs.  |
+`---------------------------------*/
+
+static shifts *
+shifts_new (int n)
+{
+  shifts *res = SHIFTS_ALLOC (n);
+  res->nshifts = n;
+  return res;
+}
+
+
+/*------------------------------------------------------------.
+| Save the NSHIFTS of SHIFTSET into the current linked list.  |
+`------------------------------------------------------------*/
+
 static void
 save_shifts (void)
 {
-  shifts *p = SHIFTS_ALLOC (nshifts);
+  shifts *p = shifts_new (nshifts);
 
   p->number = this_state->number;
-  p->nshifts = nshifts;
 
   shortcpy (p->shifts, shiftset, nshifts);
 
@@ -348,9 +364,8 @@ insert_start_shift (void)
   last_state = statep;
 
   /* Make a shift from this state to (what will be) the final state.  */
-  sp = SHIFTS_ALLOC (1);
+  sp = shifts_new (1);
   sp->number = nstates++;
-  sp->nshifts = 1;
   sp->shifts[0] = nstates;
 
   last_shift->next = sp;
@@ -405,9 +420,8 @@ augment_automaton (void)
 
 	      if (sp && sp->number == k)
 		{
-		  sp2 = SHIFTS_ALLOC (sp->nshifts + 1);
+		  sp2 = shifts_new (sp->nshifts + 1);
 		  sp2->number = k;
-		  sp2->nshifts = sp->nshifts + 1;
 		  sp2->shifts[0] = nstates;
 		  for (i = sp->nshifts; i > 0; i--)
 		    sp2->shifts[i] = sp->shifts[i - 1];
@@ -422,9 +436,8 @@ augment_automaton (void)
 		}
 	      else
 		{
-		  sp2 = SHIFTS_ALLOC (1);
+		  sp2 = shifts_new (1);
 		  sp2->number = k;
-		  sp2->nshifts = 1;
 		  sp2->shifts[0] = nstates;
 
 		  /* Patch sp2 into the chain of shifts between sp1 and sp.  */
@@ -441,8 +454,7 @@ augment_automaton (void)
 	         going to the next-to-final state (yet to be made).  */
 	      sp = first_shift;
 
-	      sp2 = SHIFTS_ALLOC (sp->nshifts + 1);
-	      sp2->nshifts = sp->nshifts + 1;
+	      sp2 = shifts_new (sp->nshifts + 1);
 
 	      /* Stick this shift into the vector at the proper place.  */
 	      statep = first_state->next;
@@ -474,8 +486,7 @@ augment_automaton (void)
 	{
 	  /* The initial state didn't even have any shifts.
 	     Give it one shift, to the next-to-final state.  */
-	  sp = SHIFTS_ALLOC (1);
-	  sp->nshifts = 1;
+	  sp = shifts_new (1);
 	  sp->shifts[0] = nstates;
 
 	  /* Patch sp into the chain of shifts at the beginning.  */
@@ -492,8 +503,7 @@ augment_automaton (void)
       /* There are no shifts for any state.
          Make one shift, from the initial state to the next-to-final state.  */
 
-      sp = SHIFTS_ALLOC (1);
-      sp->nshifts = 1;
+      sp = shifts_new (1);
       sp->shifts[0] = nstates;
 
       /* Initialize the chain of shifts with sp.  */
@@ -514,9 +524,8 @@ augment_automaton (void)
   last_state = statep;
 
   /* Make the shift from the final state to the termination state.  */
-  sp = SHIFTS_ALLOC (1);
+  sp = shifts_new (1);
   sp->number = nstates++;
-  sp->nshifts = 1;
   sp->shifts[0] = nstates;
   last_shift->next = sp;
   last_shift = sp;
