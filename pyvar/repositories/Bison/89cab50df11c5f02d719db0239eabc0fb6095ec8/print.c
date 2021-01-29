@@ -351,10 +351,10 @@ print_results (void)
   if (any_conflicts)
     print_conflicts ();
 
-  if (verboseflag)
+  if (verbose_flag)
     print_grammar ();
 
-  if (verboseflag)
+  if (verbose_flag)
     for (i = 0; i < nstates; i++)
       print_state (i);
 }
