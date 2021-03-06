@@ -400,135 +400,6 @@ conflicts_print (void)
 }
 
 
-void
-print_reductions (FILE *out, state_t *state)
-{
-  int i;
-  shifts *shiftp = state->shifts;
-  errs *errp = state->errs;
-  int nodefault = 0;
-
-  for (i = 0; i < tokensetsize; i++)
-    shiftset[i] = 0;
-
-  for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-    if (!SHIFT_IS_DISABLED (shiftp, i))
-      {
-	/* if this state has a shift for the error token, don't use a
-	   default rule.  */
-	if (SHIFT_IS_ERROR (shiftp, i))
-	  nodefault = 1;
-	SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
-      }
-
-  if (errp)
-    for (i = 0; i < errp->nerrs; i++)
-      if (errp->errs[i])
-	SETBIT (shiftset, errp->errs[i]);
-
-  if (state->nlookaheads == 1 && !nodefault)
-    {
-      int k;
-      int default_rule = LAruleno[state->lookaheadsp];
-
-      for (k = 0; k < tokensetsize; ++k)
-	lookaheadset[k] = LA (state->lookaheadsp)[k] & shiftset[k];
-
-      for (i = 0; i < ntokens; i++)
-	if (BITISSET (lookaheadset, i))
-	  fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
-		   tags[i], default_rule,
-		   tags[rule_table[default_rule].lhs]);
-
-      fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
-	       default_rule, tags[rule_table[default_rule].lhs]);
-    }
-  else if (state->nlookaheads >= 1)
-    {
-      int cmax = 0;
-      int default_LA = -1;
-      int default_rule = 0;
-
-      if (!nodefault)
-	for (i = 0; i < state->nlookaheads; ++i)
-	  {
-	    int count = 0;
-	    int j, k;
-
-	    for (k = 0; k < tokensetsize; ++k)
-	      lookaheadset[k] = LA (state->lookaheadsp + i)[k] & ~shiftset[k];
-
-	    for (j = 0; j < ntokens; j++)
-	      if (BITISSET (lookaheadset, j))
-		count++;
-
-	    if (count > cmax)
-	      {
-		cmax = count;
-		default_LA = state->lookaheadsp + i;
-		default_rule = LAruleno[state->lookaheadsp + i];
-	      }
-
-	    for (k = 0; k < tokensetsize; ++k)
-	      shiftset[k] |= lookaheadset[k];
-	  }
-
-      for (i = 0; i < tokensetsize; i++)
-	shiftset[i] = 0;
-
-      for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-	if (!SHIFT_IS_DISABLED (shiftp, i))
-	  SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
-
-      for (i = 0; i < ntokens; i++)
-	{
-	  int j;
-	  int defaulted = 0;
-	  int count = BITISSET (shiftset, i);
-
-	  for (j = 0; j < state->nlookaheads; ++j)
-	    {
-	      if (BITISSET (LA (state->lookaheadsp + j), i))
-		{
-		  if (count == 0)
-		    {
-		      if (state->lookaheadsp + j != default_LA)
-			fprintf (out,
-				 _("    %-4s\treduce using rule %d (%s)\n"),
-				 tags[i],
-				 LAruleno[state->lookaheadsp + j],
-				 tags[rule_table[LAruleno[state->lookaheadsp + j]].lhs]);
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
-				 tags[i],
-				 LAruleno[default_LA],
-				 tags[rule_table[LAruleno[default_LA]].lhs]);
-		      defaulted = 0;
-		      fprintf (out,
-			       _("    %-4s\t[reduce using rule %d (%s)]\n"),
-			       tags[i],
-			       LAruleno[state->lookaheadsp + j],
-			       tags[rule_table[LAruleno[state->lookaheadsp + j]].lhs]);
-		    }
-		}
-	    }
-	}
-
-      if (default_LA >= 0)
-	fprintf (out, _("    $default\treduce using rule %d (%s)\n"),
-		 default_rule, tags[rule_table[default_rule].lhs]);
-    }
-}
-
-
 void
 free_conflicts (void)
 {
