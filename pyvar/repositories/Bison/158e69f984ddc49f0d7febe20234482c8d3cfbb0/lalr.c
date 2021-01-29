@@ -403,7 +403,7 @@ lookaheads_print (FILE *out)
 {
   state_number_t i;
   int j, k;
-  fprintf (out, "Lookaheads: BEGIN\n");
+  fprintf (out, _("Lookaheads: BEGIN\n"));
   for (i = 0; i < nstates; ++i)
     {
       reductions_t *reds = states[i]->reductions;
@@ -415,19 +415,19 @@ lookaheads_print (FILE *out)
 	  if (reds->lookaheads[k])
 	    ++nlookaheads;
 
-      fprintf (out, "State %d: %d lookaheads\n",
+      fprintf (out, _("State %d: %d lookaheads\n"),
 	       i, nlookaheads);
 
       if (reds->lookaheads)
 	for (j = 0; j < reds->num; ++j)
 	  BITSET_FOR_EACH (iter, reds->lookaheads[j], k, 0)
 	  {
-	    fprintf (out, "   on %d (%s) -> rule %d\n",
+	    fprintf (out, _("   on %d (%s) -> rule %d\n"),
 		     k, symbols[k]->tag,
 		     reds->rules[j]->number);
 	  };
     }
-  fprintf (out, "Lookaheads: END\n");
+  fprintf (out, _("Lookaheads: END\n"));
 }
 
 void
