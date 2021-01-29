@@ -420,16 +420,18 @@ lookaheads_print (FILE *out)
   fprintf (out, "Lookaheads: BEGIN\n");
   for (i = 0; i < nstates; ++i)
     {
+      bitset_iterator iter;
+
       fprintf (out, "State %d: %d lookaheads\n",
 	       i, states[i]->nlookaheads);
 
       for (j = 0; j < states[i]->nlookaheads; ++j)
-	BITSET_EXECUTE (states[i]->lookaheads[j], 0, k,
+	BITSET_FOR_EACH (iter, states[i]->lookaheads[j], k, 0)
 	{
 	  fprintf (out, "   on %d (%s) -> rule %d\n",
 		   k, symbols[k]->tag,
 		   states[i]->lookaheads_rule[j]->number - 1);
-	});
+	};
     }
   fprintf (out, "Lookaheads: END\n");
 }
