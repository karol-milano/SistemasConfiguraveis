@@ -114,7 +114,7 @@ main (int argc, char *argv[])
      declarations.  */
   timevar_push (TV_CONFLICTS);
   conflicts_solve ();
-  if (!muscle_percent_define_flag_if ("lr.keep_unreachable_states"))
+  if (!muscle_percent_define_flag_if ("lr.keep-unreachable-states"))
     {
       state_number *old_to_new = xnmalloc (nstates, sizeof *old_to_new);
       state_number nstates_old = nstates;
