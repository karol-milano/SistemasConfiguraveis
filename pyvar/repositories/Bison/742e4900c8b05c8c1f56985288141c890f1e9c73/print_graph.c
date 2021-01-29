@@ -88,21 +88,21 @@ print_core (struct obstack *oout, state *s)
       for (/* Nothing */; *sp >= 0; ++sp)
 	obstack_fgrow1 (oout, " %s", symbols[*sp]->tag);
 
-      /* Experimental feature: display the look-ahead tokens. */
-      if (report_flag & report_look_ahead_tokens)
+      /* Experimental feature: display the lookahead tokens. */
+      if (report_flag & report_lookahead_tokens)
 	{
 	  /* Find the reduction we are handling.  */
 	  reductions *reds = s->reductions;
 	  int redno = state_reduction_find (s, &rules[r]);
 
 	  /* Print them if there are.  */
-	  if (reds->look_ahead_tokens && redno != -1)
+	  if (reds->lookahead_tokens && redno != -1)
 	    {
 	      bitset_iterator biter;
 	      int k;
 	      char const *sep = "";
 	      obstack_sgrow (oout, "[");
-	      BITSET_FOR_EACH (biter, reds->look_ahead_tokens[redno], k, 0)
+	      BITSET_FOR_EACH (biter, reds->lookahead_tokens[redno], k, 0)
 		{
 		  obstack_fgrow2 (oout, "%s%s", sep, symbols[k]->tag);
 		  sep = ", ";
