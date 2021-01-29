@@ -264,7 +264,7 @@ build_relations (void)
       symbol_number_t symbol1 = states[to_state[i]]->accessing_symbol;
       rule_number_t *rulep;
 
-      for (rulep = derives[symbol1]; *rulep > 0; rulep++)
+      for (rulep = derives[symbol1]; *rulep >= 0; rulep++)
 	{
 	  int done;
 	  int length = 1;
@@ -438,7 +438,7 @@ lookaheads_print (FILE *out)
 	{
 	  fprintf (out, "   on %d (%s) -> rule %d\n",
 		   k, symbols[k]->tag,
-		   states[i]->lookaheads_rule[j]->number - 1);
+		   states[i]->lookaheads_rule[j]->number);
 	};
     }
   fprintf (out, "Lookaheads: END\n");
