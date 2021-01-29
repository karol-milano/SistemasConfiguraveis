@@ -114,7 +114,6 @@ main (int argc, char *argv[])
      declarations.  */
   timevar_push (TV_CONFLICTS);
   conflicts_solve ();
-  muscle_percent_define_default ("lr.keep_unreachable_states", "false");
   if (!muscle_percent_define_flag_if ("lr.keep_unreachable_states"))
     {
       state_number *old_to_new = xnmalloc (nstates, sizeof *old_to_new);
