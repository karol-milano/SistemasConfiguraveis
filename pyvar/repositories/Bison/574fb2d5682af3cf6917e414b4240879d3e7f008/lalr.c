@@ -424,11 +424,12 @@ lookaheads_print (FILE *out)
 	       i, states[i]->nlookaheads);
 
       for (j = 0; j < states[i]->nlookaheads; ++j)
-	for (k = 0; k < ntokens; ++k)
-	  if (bitset_test (states[i]->lookaheads[j], k))
-	    fprintf (out, "   on %d (%s) -> rule %d\n",
-		     k, symbol_tag_get (symbols[k]),
-		     states[i]->lookaheads_rule[j]->number - 1);
+	BITSET_EXECUTE (states[i]->lookaheads[j], 0, k,
+	{
+	  fprintf (out, "   on %d (%s) -> rule %d\n",
+		   k, symbol_tag_get (symbols[k]),
+		   states[i]->lookaheads_rule[j]->number - 1);
+	});
     }
   fprintf (out, "Lookaheads: END\n");
 }
