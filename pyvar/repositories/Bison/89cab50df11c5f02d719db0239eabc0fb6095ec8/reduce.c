@@ -483,7 +483,7 @@ dump_grammar (void)
 static void
 print_notices (void)
 {
-  if (yaccflag && nuseless_productions)
+  if (yacc_flag && nuseless_productions)
     fprintf (stderr, _("%d rules never reduced\n"), nuseless_productions);
 
   fprintf (stderr, _("%s contains "), infile);
@@ -523,7 +523,7 @@ reduce_grammar (void)
 
   reduced = (bool) (nuseless_nonterminals + nuseless_productions > 0);
 
-  if (verboseflag)
+  if (verbose_flag)
     print_results ();
 
   if (reduced == FALSE)
@@ -537,14 +537,14 @@ reduce_grammar (void)
 
   reduce_grammar_tables ();
 #if 0
-  if (verboseflag)
+  if (verbose_flag)
     {
       fprintf (foutput, "REDUCED GRAMMAR\n\n");
       dump_grammar ();
     }
 #endif
 
-  if (statisticsflag)
+  if (statistics_flag)
     fprintf (stderr, _("reduced %s defines %d terminal%s, %d nonterminal%s\
 , and %d production%s.\n"),
 	     infile,
