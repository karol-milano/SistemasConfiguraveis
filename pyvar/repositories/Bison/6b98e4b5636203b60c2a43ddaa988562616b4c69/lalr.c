@@ -565,7 +565,7 @@ lookaheads_print (FILE *out)
 	for (k = 0; k < ntokens; ++k)
 	  if (bitset_test (LA[states[i]->lookaheadsp + j], k))
 	    fprintf (out, "   on %d (%s) -> rule %d\n",
-		     k, quotearg_style (escape_quoting_style, symbols[k]->tag),
+		     k, symbol_tag_get (symbols[k]),
 		     LArule[states[i]->lookaheadsp + j]->number - 1);
     }
   fprintf (out, "Lookaheads: END\n");
