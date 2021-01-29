@@ -114,14 +114,16 @@ main (int argc, char *argv[])
      declarations.  */
   timevar_push (TV_CONFLICTS);
   conflicts_solve ();
-  {
-    state_number *old_to_new = xnmalloc (nstates, sizeof *old_to_new);
-    state_number nstates_old = nstates;
-    state_remove_unreachable_states (old_to_new);
-    lalr_update_state_numbers (old_to_new, nstates_old);
-    conflicts_update_state_numbers (old_to_new, nstates_old);
-    free (old_to_new);
-  }
+  muscle_percent_define_default ("lr.keep_unreachable_states", "false");
+  if (!muscle_percent_define_flag_if ("lr.keep_unreachable_states"))
+    {
+      state_number *old_to_new = xnmalloc (nstates, sizeof *old_to_new);
+      state_number nstates_old = nstates;
+      state_remove_unreachable_states (old_to_new);
+      lalr_update_state_numbers (old_to_new, nstates_old);
+      conflicts_update_state_numbers (old_to_new, nstates_old);
+      free (old_to_new);
+    }
   conflicts_print ();
   timevar_pop (TV_CONFLICTS);
 
