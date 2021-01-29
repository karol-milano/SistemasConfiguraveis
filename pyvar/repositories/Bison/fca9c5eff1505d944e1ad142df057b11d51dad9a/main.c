@@ -97,15 +97,14 @@ main (int argc, char *argv[])
   nullable_compute ();
   timevar_pop (TV_SETS);
 
-  /* Convert to nondeterministic finite state machine.  In file LR0.
-     See state.h for more info.  */
+  /* Compute LR(0) parser states.  See state.h for more info.  */
   timevar_push (TV_LR0);
   generate_states ();
   timevar_pop (TV_LR0);
 
-  /* Make it deterministic by computing lookahead sets.  Except when LALR(1) is
-     requested, split states to eliminate LR(1)-relative inadequacies.  In file
-     lalr and ielr.  */
+  /* Add lookahead sets to parser states.  Except when LALR(1) is
+     requested, split states to eliminate LR(1)-relative
+     inadequacies.  */
   ielr ();
 
   /* Find and record any conflicts: places where one token of
