@@ -314,19 +314,6 @@ new_states (void)
 }
 
 
-/*---------------------------------.
-| Create a new array of N shitfs.  |
-`---------------------------------*/
-
-static shifts *
-shifts_new (int n)
-{
-  shifts *res = SHIFTS_ALLOC (n);
-  res->nshifts = n;
-  return res;
-}
-
-
 /*------------------------------------------------------------.
 | Save the NSHIFTS of SHIFTSET into the current linked list.  |
 `------------------------------------------------------------*/
@@ -393,7 +380,7 @@ augment_automaton (void)
 
   sp = first_shift;
 
-  if (!sp)
+  if (!sp->nshifts)
     {
       /* There are no shifts for any state.  Make one shift, from the
 	 initial state to the next-to-final state.  */
@@ -610,8 +597,7 @@ generate_states (void)
 
       /* create the shifts structures for the shifts to those states,
          now that the state numbers transitioning to are known */
-      if (nshifts > 0)
-	save_shifts ();
+      save_shifts ();
 
       /* states are queued when they are created; process them all */
       this_state = this_state->next;
