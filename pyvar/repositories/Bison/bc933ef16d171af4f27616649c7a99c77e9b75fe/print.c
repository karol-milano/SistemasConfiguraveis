@@ -165,138 +165,148 @@ print_gotos (FILE *out, state_t *state)
     }
 }
 
+
+/*----------------------------------------------------------.
+| Return the default rule of this STATE if it has one, NULL |
+| otherwise.                                                |
+`----------------------------------------------------------*/
+
+static rule_t *
+state_default_rule_compute (state_t *state)
+{
+  reductions_t *redp = state->reductions;
+  rule_t *default_rule = NULL;
+  int cmax = 0;
+  int i;
+
+  /* No need for a lookahead.  */
+  if (state->consistent)
+    return &rules[redp->rules[0]];
+
+  /* 1. Each reduction is possibly masked by the lookaheads on which
+     we shift (S/R conflicts)...  */
+  bitset_zero (shiftset);
+  {
+    shifts_t *shiftp = state->shifts;
+    for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
+      if (!SHIFT_IS_DISABLED (shiftp, i))
+	{
+	  /* If this state has a shift for the error token, don't use a
+	     default rule.  */
+	  if (SHIFT_IS_ERROR (shiftp, i))
+	    return NULL;
+	  bitset_set (shiftset, SHIFT_SYMBOL (shiftp, i));
+	}
+  }
+
+  /* 2. Each reduction is possibly masked by the lookaheads on which
+     we raise an error (due to %nonassoc).  */
+  {
+    errs_t *errp = state->errs;
+    for (i = 0; i < errp->nerrs; i++)
+      if (errp->errs[i])
+	bitset_set (shiftset, errp->errs[i]);
+  }
+
+  for (i = 0; i < state->nlookaheads; ++i)
+    {
+      int count = 0;
+
+      /* How many non-masked lookaheads are there for this reduction?
+	 */
+      bitset_andn (lookaheadset, state->lookaheads[i], shiftset);
+      count = bitset_count (lookaheadset);
+
+      if (count > cmax)
+	{
+	  cmax = count;
+	  default_rule = state->lookaheads_rule[i];
+	}
+
+      /* 3. And finally, each reduction is possibly masked by previous
+	 reductions (in R/R conflicts, we keep the first reductions).
+	 */
+      bitset_or (shiftset, shiftset, state->lookaheads[i]);
+    }
+
+  return default_rule;
+}
+
+
+/*----------------------------------------------------.
+| Report on OUT the reduction actions of this STATE.  |
+`----------------------------------------------------*/
+
 static void
 print_reductions (FILE *out, state_t *state)
 {
   int i;
   shifts_t *shiftp = state->shifts;
   reductions_t *redp = state->reductions;
-  errs_t *errp = state->errs;
-  int nodefault = 0;
+  rule_t *default_rule = NULL;
 
   if (redp->nreds == 0)
     return;
 
-  if (state->consistent)
-    {
-      int rule = redp->rules[0];
-      symbol_number_t symbol = rules[rule].lhs->number;
-      fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
-	       rule - 1, symbol_tag_get (symbols[symbol]));
-      return;
-    }
+  default_rule = state_default_rule_compute (state);
 
   bitset_zero (shiftset);
-
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
-      {
-	/* if this state has a shift for the error token, don't use a
-	   default rule.  */
-	if (SHIFT_IS_ERROR (shiftp, i))
-	  nodefault = 1;
-	bitset_set (shiftset, SHIFT_SYMBOL (shiftp, i));
-      }
-
-  for (i = 0; i < errp->nerrs; i++)
-    if (errp->errs[i])
-      bitset_set (shiftset, errp->errs[i]);
-
-  if (state->nlookaheads == 1 && !nodefault)
-    {
-      rule_t *default_rule = state->lookaheads_rule[0];
-
-      bitset_and (lookaheadset, state->lookaheads[0], shiftset);
+      bitset_set (shiftset, SHIFT_SYMBOL (shiftp, i));
 
-      BITSET_EXECUTE (lookaheadset, 0, i,
-      {
-	fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
-		 symbol_tag_get (symbols[i]),
-		 default_rule->number - 1,
-		 symbol_tag_get_n (default_rule->lhs, 1));
-      });
-      fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
-	       default_rule->number - 1,
-	       symbol_tag_get (default_rule->lhs));
-    }
-  else if (state->nlookaheads >= 1)
+  for (i = 0; i < ntokens; i++)
     {
-      int cmax = 0;
-      int default_LA = -1;
-      rule_t *default_rule = NULL;
+      int j;
+      int defaulted = 0;
+      int count = bitset_test (shiftset, i);
 
-      if (!nodefault)
-	for (i = 0; i < state->nlookaheads; ++i)
+      for (j = 0; j < state->nlookaheads; ++j)
+	if (bitset_test (state->lookaheads[j], i))
 	  {
-	    int count = 0;
-
-	    bitset_andn (lookaheadset, state->lookaheads[i], shiftset);
-	    count = bitset_count (lookaheadset);
-
-	    if (count > cmax)
+	    if (count == 0)
 	      {
-		cmax = count;
-		default_LA = i;
-		default_rule = state->lookaheads_rule[i];
+		if (state->lookaheads_rule[j] != default_rule)
+		  fprintf (out,
+			   _("    %-4s\treduce using rule %d (%s)\n"),
+			   symbol_tag_get (symbols[i]),
+			   state->lookaheads_rule[j]->number - 1,
+			   symbol_tag_get_n (state->lookaheads_rule[j]->lhs, 1));
+		else
+		  defaulted = 1;
+		count++;
 	      }
-
-	    bitset_or (shiftset, shiftset, lookaheadset);
-	  }
-
-      bitset_zero (shiftset);
-
-      for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-	if (!SHIFT_IS_DISABLED (shiftp, i))
-	  bitset_set (shiftset, SHIFT_SYMBOL (shiftp, i));
-
-      for (i = 0; i < ntokens; i++)
-	{
-	  int j;
-	  int defaulted = 0;
-	  int count = bitset_test (shiftset, i);
-
-	  for (j = 0; j < state->nlookaheads; ++j)
-	    if (bitset_test (state->lookaheads[j], i))
+	    else
 	      {
-		if (count == 0)
-		  {
-		    if (j != default_LA)
-		      fprintf (out,
-			       _("    %-4s\treduce using rule %d (%s)\n"),
-			       symbol_tag_get (symbols[i]),
-			       state->lookaheads_rule[j]->number - 1,
-			       symbol_tag_get_n (state->lookaheads_rule[j]->lhs, 1));
-		    else
-		      defaulted = 1;
-
-		    count++;
-		  }
-		else
-		  {
-		    if (defaulted)
-		      fprintf (out,
-			       _("    %-4s\treduce using rule %d (%s)\n"),
-			       symbol_tag_get (symbols[i]),
-			       state->lookaheads_rule[default_LA]->number - 1,
-			       symbol_tag_get_n (state->lookaheads_rule[default_LA]->lhs, 1));
-		    defaulted = 0;
-		    fprintf (out,
-			     _("    %-4s\t[reduce using rule %d (%s)]\n"),
-			     symbol_tag_get (symbols[i]),
-			     state->lookaheads_rule[j]->number - 1,
-			     symbol_tag_get_n (state->lookaheads_rule[j]->lhs, 1));
-		  }
+		if (defaulted)
+		  fprintf (out,
+			   _("    %-4s\treduce using rule %d (%s)\n"),
+			   symbol_tag_get (symbols[i]),
+			   default_rule->number - 1,
+			   symbol_tag_get_n (default_rule->lhs, 1));
+		defaulted = 0;
+		fprintf (out,
+			 _("    %-4s\t[reduce using rule %d (%s)]\n"),
+			 symbol_tag_get (symbols[i]),
+			 state->lookaheads_rule[j]->number - 1,
+			 symbol_tag_get_n (state->lookaheads_rule[j]->lhs, 1));
 	      }
-	}
-
-      if (default_LA >= 0)
-	fprintf (out, _("    $default\treduce using rule %d (%s)\n"),
-		 default_rule->number - 1,
-		 symbol_tag_get (default_rule->lhs));
+	  }
     }
+
+  if (default_rule)
+    fprintf (out, _("    $default\treduce using rule %d (%s)\n"),
+	     default_rule->number - 1,
+	     symbol_tag_get (default_rule->lhs));
+  fputc ('\n', out);
 }
 
 
+/*--------------------------------------------------------------.
+| Report on OUT all the actions (shifts, gotos, reductions, and |
+| explicit erros from %nonassoc) of STATE.                      |
+`--------------------------------------------------------------*/
+
 static void
 print_actions (FILE *out, state_t *state)
 {
@@ -306,9 +316,9 @@ print_actions (FILE *out, state_t *state)
   if (shiftp->nshifts == 0 && redp->nreds == 0)
     {
       if (state->number == final_state->number)
-       fprintf (out, _("    $default\taccept\n"));
+	fprintf (out, _("    $default\taccept\n"));
       else
-       fprintf (out, _("    NO ACTIONS\n"));
+	fprintf (out, _("    NO ACTIONS\n"));
       return;
     }
 
@@ -318,6 +328,7 @@ print_actions (FILE *out, state_t *state)
   print_gotos (out, state);
 }
 
+
 static void
 print_state (FILE *out, state_t *state)
 {
