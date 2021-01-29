@@ -427,7 +427,7 @@ lookaheads_print (FILE *out)
 	BITSET_EXECUTE (states[i]->lookaheads[j], 0, k,
 	{
 	  fprintf (out, "   on %d (%s) -> rule %d\n",
-		   k, symbol_tag_get (symbols[k]),
+		   k, symbols[k]->tag,
 		   states[i]->lookaheads_rule[j]->number - 1);
 	});
     }
