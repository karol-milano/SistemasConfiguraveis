@@ -145,7 +145,7 @@ main (int argc, char *argv[])
       conflicts_update_state_numbers (old_to_new, nstates_old);
       free (old_to_new);
     }
-  if (warning_is_enabled (Wcounterexample))
+  if (warning_is_enabled (Wcounterexamples))
     counterexample_init ();
   conflicts_print ();
   timevar_pop (tv_conflicts);
