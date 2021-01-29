@@ -125,7 +125,7 @@ main (int argc, char *argv[])
      declarations.  */
   timevar_push (TV_CONFLICTS);
   conflicts_solve ();
-  if (!muscle_percent_define_flag_if ("lr.keep-unreachable-states"))
+  if (!muscle_percent_define_flag_if ("lr.keep-unreachable-state"))
     {
       state_number *old_to_new = xnmalloc (nstates, sizeof *old_to_new);
       state_number nstates_old = nstates;
