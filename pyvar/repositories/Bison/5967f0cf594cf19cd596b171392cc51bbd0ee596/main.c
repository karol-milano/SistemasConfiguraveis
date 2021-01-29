@@ -115,6 +115,13 @@ main (int argc, char *argv[])
      declarations.  */
   timevar_push (TV_CONFLICTS);
   conflicts_solve ();
+  {
+    state_number old_to_new[nstates];
+    state_number nstates_old = nstates;
+    state_remove_unreachable_states (old_to_new);
+    lalr_update_state_numbers (old_to_new, nstates_old);
+    conflicts_update_state_numbers (old_to_new, nstates_old);
+  }
   conflicts_print ();
   timevar_pop (TV_CONFLICTS);
 
