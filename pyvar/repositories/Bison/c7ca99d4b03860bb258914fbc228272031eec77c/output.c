@@ -1132,8 +1132,6 @@ output_check (void)
 static void
 output_actions (void)
 {
-  state_number_t i;
-
   /* That's a poor way to make sure the sizes are properly corelated,
      in particular the signedness is not taking into account, but it's
      not useless.  */
@@ -1165,15 +1163,6 @@ output_actions (void)
   output_conflicts ();
 
   output_check ();
-
-  for (i = 0; i < nstates; ++i)
-    {
-      free (states[i]->shifts);
-      XFREE (states[i]->reductions);
-      free (states[i]->errs);
-      free (states[i]);
-    }
-  XFREE (states);
 }
 
 
