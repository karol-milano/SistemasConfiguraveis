@@ -80,7 +80,7 @@ void
 print_token(extnum, token)
 int extnum, token;
 {
-  fprintf(foutput, " type %d is %s\n", extnum, tags[token]);
+  fprintf(foutput, _(" type %d is %s\n"), extnum, tags[token]);
 }
 
 
@@ -88,7 +88,7 @@ void
 print_state(state)
 int state;
 {
-  fprintf(foutput, "\n\nstate %d\n\n", state);
+  fprintf(foutput, _("\n\nstate %d\n\n"), state);
   print_core(state);
   print_actions(state);
 }
@@ -133,7 +133,7 @@ int state;
 	  sp++;
 	}
 
-      fprintf (foutput, "   (rule %d)", rule);
+      fprintf (foutput, _("   (rule %d)"), rule);
       putc('\n', foutput);
     }
 
@@ -161,9 +161,9 @@ int state;
   if (!shiftp && !redp)
     {
       if (final_state == state)
-	fprintf(foutput, "    $default\taccept\n");
+	fprintf(foutput, _("    $default\taccept\n"));
       else
-	fprintf(foutput, "    NO ACTIONS\n");
+	fprintf(foutput, _("    NO ACTIONS\n"));
       return;
     }
 
@@ -179,9 +179,9 @@ int state;
 	  /* The following line used to be turned off.  */
 	  if (ISVAR(symbol)) break;
           if (symbol==0)      /* I.e. strcmp(tags[symbol],"$")==0 */
-            fprintf(foutput, "    $   \tgo to state %d\n", state1);
+            fprintf(foutput, _("    $   \tgo to state %d\n"), state1);
           else
-            fprintf(foutput, "    %-4s\tshift, and go to state %d\n",
+            fprintf(foutput, _("    %-4s\tshift, and go to state %d\n"),
                     tags[symbol], state1);
 	}
 
@@ -204,7 +204,7 @@ int state;
 	{
 	  if (! errp->errs[j]) continue;
 	  symbol = errp->errs[j];
-	  fprintf(foutput, "    %-4s\terror (nonassociative)\n", tags[symbol]);
+	  fprintf(foutput, _("    %-4s\terror (nonassociative)\n"), tags[symbol]);
 	}
 
       if (j > 0)
@@ -215,7 +215,7 @@ int state;
     {
       rule = redp->rules[0];
       symbol = rlhs[rule];
-      fprintf(foutput, "    $default\treduce using rule %d (%s)\n\n",
+      fprintf(foutput, _("    $default\treduce using rule %d (%s)\n\n"),
      	        rule, tags[symbol]);
     }
   else if (redp)
@@ -230,7 +230,7 @@ int state;
 	  if (! shiftp->shifts[i]) continue;
 	  state1 = shiftp->shifts[i];
 	  symbol = accessing_symbol[state1];
-	  fprintf(foutput, "    %-4s\tgo to state %d\n", tags[symbol], state1);
+	  fprintf(foutput, _("    %-4s\tgo to state %d\n"), tags[symbol], state1);
 	}
 
       putc('\n', foutput);
@@ -251,23 +251,23 @@ print_grammar()
   int column = 0;
 
   /* rule # : LHS -> RHS */
-  fputs("\nGrammar\n", foutput);
+  fputs(_("\nGrammar\n"), foutput);
   for (i = 1; i <= nrules; i++)
     /* Don't print rules disabled in reduce_grammar_tables.  */
     if (rlhs[i] >= 0)
       {
-	fprintf(foutput, "rule %-4d %s ->", i, tags[rlhs[i]]);
+	fprintf(foutput, _("rule %-4d %s ->"), i, tags[rlhs[i]]);
 	rule = &ritem[rrhs[i]];
 	if (*rule > 0)
 	  while (*rule > 0)
 	    fprintf(foutput, " %s", tags[*rule++]);
 	else
-	  fputs ("		/* empty */", foutput);
+	  fputs (_("		/* empty */"), foutput);
 	putc('\n', foutput);
       }
 
   /* TERMINAL (type #) : rule #s terminal is on RHS */
-  fputs("\nTerminals, with rules where they appear\n\n", foutput);
+  fputs(_("\nTerminals, with rules where they appear\n\n"), foutput);
   fprintf(foutput, "%s (-1)\n", tags[0]);
   if (translations)
     {
@@ -315,7 +315,7 @@ print_grammar()
 	fprintf (foutput, "%s\n", buffer);
       }
 
-  fputs("\nNonterminals, with rules where they appear\n\n", foutput);
+  fputs(_("\nNonterminals, with rules where they appear\n\n"), foutput);
   for (i = ntokens; i <= nsyms - 1; i++)
     {
       int left_count = 0, right_count = 0;
@@ -341,7 +341,7 @@ print_grammar()
       if (left_count > 0)
 	{
 	  END_TEST (50);
-	  sprintf (buffer + strlen(buffer), " on left:");
+	  sprintf (buffer + strlen(buffer), _(" on left:"));
 
 	  for (j = 1; j <= nrules; j++)
 	    {
@@ -356,7 +356,7 @@ print_grammar()
 	  if (left_count > 0)
 	    sprintf (buffer + strlen(buffer), ",");
 	  END_TEST (50);
-	  sprintf (buffer + strlen(buffer), " on right:");
+	  sprintf (buffer + strlen(buffer), _(" on right:"));
 	  for (j = 1; j <= nrules; j++)
 	    {
 	      for (rule = &ritem[rrhs[j]]; *rule > 0; rule++)
