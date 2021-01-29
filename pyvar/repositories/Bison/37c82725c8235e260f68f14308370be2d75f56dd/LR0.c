@@ -437,9 +437,9 @@ insert_accepting_state (void)
 static void
 augment_automaton (void)
 {
-  if (!first_shift->nshifts)
+  if (!first_state->shifts->nshifts)
     {
-      /* There are no shifts for any state.  Make one shift, from the
+      /* The first state has no shifts.  Make one shift, from the
 	 initial state to the next-to-final state.  */
 
       shifts *sp = shifts_new (1);
@@ -454,7 +454,7 @@ augment_automaton (void)
          what will be the final state.  */
       insert_start_shifting_state ();
     }
-  else if (first_shift->number == 0)
+  else
     {
       state_t *statep = first_state->next;
       shifts *sp = first_shift;
@@ -544,22 +544,6 @@ augment_automaton (void)
 	  insert_start_shifting_state ();
 	}
     }
-  else
-    {
-      /* The initial state didn't even have any shifts.
-	 Give it one shift, to the next-to-final state.  */
-      shifts *sp = shifts_new (1);
-      first_state->shifts = sp;
-      sp->shifts[0] = nstates;
-
-      /* Patch sp into the chain of shifts at the beginning.  */
-      sp->next = first_shift;
-      first_shift = sp;
-
-      /* Create the next-to-final state, with shift to
-	 what will be the final state.  */
-      insert_start_shifting_state ();
-    }
 
   insert_eof_shifting_state ();
   insert_accepting_state ();
