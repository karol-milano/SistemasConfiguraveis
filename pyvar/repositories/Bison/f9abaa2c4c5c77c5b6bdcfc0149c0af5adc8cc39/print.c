@@ -215,12 +215,7 @@ print_reductions (FILE *out, state_t *state)
     {
       int default_rule = LAruleno[state->lookaheadsp];
 
-      for (i = 0; i < ntokens; ++i)
-	if (bitset_test (LA[state->lookaheadsp], i)
-	    && bitset_test (shiftset, i))
-	  bitset_set (lookaheadset, i);
-	else
-	  bitset_reset (lookaheadset, i);
+      bitset_and (lookaheadset, LA[state->lookaheadsp], shiftset);
 
       for (i = 0; i < ntokens; i++)
 	if (bitset_test (lookaheadset, i))
@@ -241,14 +236,9 @@ print_reductions (FILE *out, state_t *state)
 	for (i = 0; i < state->nlookaheads; ++i)
 	  {
 	    int count = 0;
-	    int j, k;
+	    int j;
 
-	    for (k = 0; k < ntokens; ++k)
-	      if (bitset_test (LA[state->lookaheadsp + i], k)
-		  && ! bitset_test (shiftset, k))
-		bitset_set (lookaheadset, k);
-	      else
-		bitset_reset (lookaheadset, k);
+	    bitset_andn (lookaheadset, LA[state->lookaheadsp + i], shiftset);
 
 	    for (j = 0; j < ntokens; j++)
 	      if (bitset_test (lookaheadset, j))
@@ -277,39 +267,37 @@ print_reductions (FILE *out, state_t *state)
 	  int count = bitset_test (shiftset, i);
 
 	  for (j = 0; j < state->nlookaheads; ++j)
-	    {
-	      if (bitset_test (LA[state->lookaheadsp + j], i))
-		{
-		  if (count == 0)
-		    {
-		      if (state->lookaheadsp + j != default_LA)
-			fprintf (out,
-				 _("    %-4s\treduce using rule %d (%s)\n"),
-				 escape (symbols[i]->tag),
-				 LAruleno[state->lookaheadsp + j] - 1,
-				 escape2 (symbols[rules[LAruleno[state->lookaheadsp + j]].lhs]->tag));
-		      else
-			defaulted = 1;
-
-		      count++;
-		    }
-		  else
-		    {
-		      if (defaulted)
-			fprintf (out,
-				 _("    %-4s\treduce using rule %d (%s)\n"),
-				 escape (symbols[i]->tag),
-				 LAruleno[default_LA] - 1,
-				 escape2 (symbols[rules[LAruleno[default_LA]].lhs]->tag));
-		      defaulted = 0;
+	    if (bitset_test (LA[state->lookaheadsp + j], i))
+	      {
+		if (count == 0)
+		  {
+		    if (state->lookaheadsp + j != default_LA)
 		      fprintf (out,
-			       _("    %-4s\t[reduce using rule %d (%s)]\n"),
+			       _("    %-4s\treduce using rule %d (%s)\n"),
 			       escape (symbols[i]->tag),
 			       LAruleno[state->lookaheadsp + j] - 1,
 			       escape2 (symbols[rules[LAruleno[state->lookaheadsp + j]].lhs]->tag));
-		    }
-		}
-	    }
+		    else
+		      defaulted = 1;
+
+		    count++;
+		  }
+		else
+		  {
+		    if (defaulted)
+		      fprintf (out,
+			       _("    %-4s\treduce using rule %d (%s)\n"),
+			       escape (symbols[i]->tag),
+			       LAruleno[default_LA] - 1,
+			       escape2 (symbols[rules[LAruleno[default_LA]].lhs]->tag));
+		    defaulted = 0;
+		    fprintf (out,
+			     _("    %-4s\t[reduce using rule %d (%s)]\n"),
+			     escape (symbols[i]->tag),
+			     LAruleno[state->lookaheadsp + j] - 1,
+			     escape2 (symbols[rules[LAruleno[state->lookaheadsp + j]].lhs]->tag));
+		  }
+	      }
 	}
 
       if (default_LA >= 0)
