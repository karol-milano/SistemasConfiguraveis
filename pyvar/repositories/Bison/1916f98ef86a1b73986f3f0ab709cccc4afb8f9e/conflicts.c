@@ -465,7 +465,7 @@ print_conflicts (void)
     }
 
   /* Report the total number of conflicts on STDERR.  */
-  if (fixed_outfiles)
+  if (yaccflag)
     {
       /* If invoked with `--yacc', use the output format specified by
 	 POSIX.  */
