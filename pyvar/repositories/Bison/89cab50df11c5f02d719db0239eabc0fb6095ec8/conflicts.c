@@ -45,7 +45,7 @@ static int rrc_count;
 static inline void
 log_resolution (int state, int LAno, int token, char *resolution)
 {
-  if (verboseflag)
+  if (verbose_flag)
     fprintf (foutput,
 	     _("\
 Conflict in state %d between rule %d and token %s resolved as %s.\n"),
@@ -456,7 +456,7 @@ print_conflicts (void)
 	  src_total += src_count;
 	  rrc_total += rrc_count;
 
-	  if (verboseflag)
+	  if (verbose_flag)
 	    {
 	      fprintf (foutput, _("State %d contains"), i);
 	      conflict_report (foutput, src_count, rrc_count);
@@ -465,7 +465,7 @@ print_conflicts (void)
     }
 
   /* Report the total number of conflicts on STDERR.  */
-  if (yaccflag)
+  if (yacc_flag)
     {
       /* If invoked with `--yacc', use the output format specified by
 	 POSIX.  */
