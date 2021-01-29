@@ -255,6 +255,7 @@ reduce_grammar_tables (void)
 	for (/* Nothing. */; *rhsp >= 0; ++rhsp)
 	  /* Nothing. */;
 	*rhsp = -i;
+	rules[i].number = i;
       }
     nrules -= nuseless_productions;
   }
@@ -368,7 +369,7 @@ reduce_output (FILE *out)
       for (i = nrules + 1; i < nuseless_productions + nrules + 1; i++)
 	{
 	  rule r;
-	  fprintf (out, "#%-4d  ", rules[i].number - 1);
+	  fprintf (out, "#%-4d  ", rules[i].user_number - 1);
 	  fprintf (out, "%s:", rules[i].lhs->tag);
 	  for (r = rules[i].rhs; *r >= 0; r++)
 	    fprintf (out, " %s", symbols[*r]->tag);
