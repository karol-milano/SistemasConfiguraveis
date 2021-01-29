@@ -194,7 +194,9 @@ print_actions (int state)
 static void
 print_state (int state)
 {
-  fprintf (foutput, _("\n\nstate %d\n\n"), state);
+  fputs ("\n\n", foutput);
+  fprintf (foutput, _("state %d"), state);
+  fputs ("\n\n", foutput);
   print_core (state);
   print_actions (state);
 }
@@ -222,7 +224,9 @@ print_grammar (void)
   int column = 0;
 
   /* rule # : LHS -> RHS */
-  fputs (_("\nGrammar\n"), foutput);
+  putc ('\n', foutput);
+  fputs (_("Grammar"), foutput);
+  putc ('\n', foutput);
   for (i = 1; i <= nrules; i++)
     /* Don't print rules disabled in reduce_grammar_tables.  */
     if (rlhs[i] >= 0)
@@ -238,7 +242,9 @@ print_grammar (void)
       }
 
   /* TERMINAL (type #) : rule #s terminal is on RHS */
-  fputs (_("\nTerminals, with rules where they appear\n\n"), foutput);
+  fputs ("\n", foutput);
+  fputs (_("Terminals, with rules where they appear"), foutput);
+  fputs ("\n\n", foutput);
   fprintf (foutput, "%s (-1)\n", tags[0]);
   if (translations)
     {
@@ -286,7 +292,9 @@ print_grammar (void)
 	fprintf (foutput, "%s\n", buffer);
       }
 
-  fputs (_("\nNonterminals, with rules where they appear\n\n"), foutput);
+  fputs ("\n", foutput);
+  fputs (_("Nonterminals, with rules where they appear"), foutput);
+  fputs ("\n\n", foutput);
   for (i = ntokens; i <= nsyms - 1; i++)
     {
       int left_count = 0, right_count = 0;
