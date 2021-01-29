@@ -99,16 +99,16 @@ print_core (FILE *out, state_t *state)
 	      /* Look for lookaheads corresponding to this rule. */
 	      for (j = 0; j < state->nlookaheads; ++j)
 		for (k = 0; k < ntokens; ++k)
-		  if (bitset_test (LA[state->lookaheadsp + j], k)
-		      && LArule[state->lookaheadsp + j]->number == rule)
+		  if (bitset_test (state->lookaheads[j], k)
+		      && state->lookaheads_rule[j]->number == rule)
 		    nlookaheads++;
 	      if (nlookaheads)
 		{
 		  fprintf (out, "  [");
 		  for (j = 0; j < state->nlookaheads; ++j)
 		    for (k = 0; k < ntokens; ++k)
-		      if (bitset_test (LA[state->lookaheadsp + j], k)
-			  && LArule[state->lookaheadsp + j]->number == rule)
+		      if (bitset_test (state->lookaheads[j], k)
+			  && state->lookaheads_rule[j]->number == rule)
 			fprintf (out, "%s%s",
 				 symbol_tag_get (symbols[k]),
 				 --nlookaheads ? ", " : "");
@@ -225,9 +225,9 @@ print_reductions (FILE *out, state_t *state)
 
   if (state->nlookaheads == 1 && !nodefault)
     {
-      rule_t *default_rule = LArule[state->lookaheadsp];
+      rule_t *default_rule = state->lookaheads_rule[0];
 
-      bitset_and (lookaheadset, LA[state->lookaheadsp], shiftset);
+      bitset_and (lookaheadset, state->lookaheads[0], shiftset);
 
       for (i = 0; i < ntokens; i++)
 	if (bitset_test (lookaheadset, i))
@@ -252,7 +252,7 @@ print_reductions (FILE *out, state_t *state)
 	    int count = 0;
 	    int j;
 
-	    bitset_andn (lookaheadset, LA[state->lookaheadsp + i], shiftset);
+	    bitset_andn (lookaheadset, state->lookaheads[i], shiftset);
 
 	    for (j = 0; j < ntokens; j++)
 	      if (bitset_test (lookaheadset, j))
@@ -261,8 +261,8 @@ print_reductions (FILE *out, state_t *state)
 	    if (count > cmax)
 	      {
 		cmax = count;
-		default_LA = state->lookaheadsp + i;
-		default_rule = LArule[state->lookaheadsp + i];
+		default_LA = i;
+		default_rule = state->lookaheads_rule[i];
 	      }
 
 	    bitset_or (shiftset, shiftset, lookaheadset);
@@ -281,16 +281,16 @@ print_reductions (FILE *out, state_t *state)
 	  int count = bitset_test (shiftset, i);
 
 	  for (j = 0; j < state->nlookaheads; ++j)
-	    if (bitset_test (LA[state->lookaheadsp + j], i))
+	    if (bitset_test (state->lookaheads[j], i))
 	      {
 		if (count == 0)
 		  {
-		    if (state->lookaheadsp + j != default_LA)
+		    if (j != default_LA)
 		      fprintf (out,
 			       _("    %-4s\treduce using rule %d (%s)\n"),
 			       symbol_tag_get (symbols[i]),
-			       LArule[state->lookaheadsp + j]->number - 1,
-			       symbol_tag_get_n (LArule[state->lookaheadsp + j]->lhs, 1));
+			       state->lookaheads_rule[j]->number - 1,
+			       symbol_tag_get_n (state->lookaheads_rule[j]->lhs, 1));
 		    else
 		      defaulted = 1;
 
@@ -302,14 +302,14 @@ print_reductions (FILE *out, state_t *state)
 		      fprintf (out,
 			       _("    %-4s\treduce using rule %d (%s)\n"),
 			       symbol_tag_get (symbols[i]),
-			       LArule[default_LA]->number - 1,
-			       symbol_tag_get_n (LArule[default_LA]->lhs, 1));
+			       state->lookaheads_rule[default_LA]->number - 1,
+			       symbol_tag_get_n (state->lookaheads_rule[default_LA]->lhs, 1));
 		    defaulted = 0;
 		    fprintf (out,
 			     _("    %-4s\t[reduce using rule %d (%s)]\n"),
 			     symbol_tag_get (symbols[i]),
-			     LArule[state->lookaheadsp + j]->number - 1,
-			     symbol_tag_get_n (LArule[state->lookaheadsp + j]->lhs, 1));
+			     state->lookaheads_rule[j]->number - 1,
+			     symbol_tag_get_n (state->lookaheads_rule[j]->lhs, 1));
 		  }
 	      }
 	}
