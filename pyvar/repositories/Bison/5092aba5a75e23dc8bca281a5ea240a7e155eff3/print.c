@@ -32,6 +32,9 @@
 #include "reduce.h"
 #include "closure.h"
 
+static unsigned *shiftset = NULL;
+static unsigned *lookaheadset = NULL;
+
 #if 0
 static void
 print_token (int extnum, int token)
@@ -93,23 +96,12 @@ print_core (FILE *out, state_t *state)
     }
 }
 
+
 static void
-print_actions (FILE *out, state_t *state)
+print_shifts (FILE *out, state_t *state)
 {
   int i;
-
-  shifts   *shiftp = state->shifts;
-  reductions *redp = state->reductions;
-  errs       *errp = state->errs;
-
-  if (!shiftp->nshifts && !redp)
-    {
-      if (final_state == state->number)
-	fprintf (out, _("    $default\taccept\n"));
-      else
-	fprintf (out, _("    NO ACTIONS\n"));
-      return;
-    }
+  shifts *shiftp = state->shifts;
 
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
@@ -123,34 +115,36 @@ print_actions (FILE *out, state_t *state)
 
   if (i > 0)
     fputc ('\n', out);
+}
 
-  if (errp)
-    {
-      int j;
-      for (j = 0; j < errp->nerrs; j++)
-	{
-	  int symbol = errp->errs[j];
-	  if (!symbol)
-	    continue;
-	  fprintf (out, _("    %-4s\terror (nonassociative)\n"),
-		   tags[symbol]);
-	}
 
-      if (j > 0)
+static void
+print_errs (FILE *out, state_t *state)
+{
+  errs *errp = state->errs;
+  int i;
+
+  if (!errp)
+    return;
+
+  for (i = 0; i < errp->nerrs; ++i)
+    if (errp->errs[i])
+      fprintf (out, _("    %-4s\terror (nonassociative)\n"),
+	       tags[errp->errs[i]]);
+
+  if (i > 0)
 	fputc ('\n', out);
-    }
+}
 
-  if (state->consistent && redp)
-    {
-      int rule = redp->rules[0];
-      int symbol = rule_table[rule].lhs;
-      fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
-	       rule, tags[symbol]);
-    }
-  else if (redp)
-    {
-      print_reductions (out, state);
-    }
+
+static void
+print_gotos (FILE *out, state_t *state)
+{
+  int i;
+  shifts *shiftp = state->shifts;
+
+  for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
+    /* Skip token shifts.  */;
 
   if (i < shiftp->nshifts)
     {
@@ -167,6 +161,167 @@ print_actions (FILE *out, state_t *state)
     }
 }
 
+static void
+print_reductions (FILE *out, state_t *state)
+{
+  int i;
+  shifts *shiftp = state->shifts;
+  reductions *redp = state->reductions;
+  errs *errp = state->errs;
+  int nodefault = 0;
+
+  if (state->consistent)
+    {
+      int rule = redp->rules[0];
+      int symbol = rule_table[rule].lhs;
+      fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
+	       rule, tags[symbol]);
+      return;
+    }
+
+  for (i = 0; i < tokensetsize; i++)
+    shiftset[i] = 0;
+
+  for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
+    if (!SHIFT_IS_DISABLED (shiftp, i))
+      {
+	/* if this state has a shift for the error token, don't use a
+	   default rule.  */
+	if (SHIFT_IS_ERROR (shiftp, i))
+	  nodefault = 1;
+	SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
+      }
+
+  if (errp)
+    for (i = 0; i < errp->nerrs; i++)
+      if (errp->errs[i])
+	SETBIT (shiftset, errp->errs[i]);
+
+  if (state->nlookaheads == 1 && !nodefault)
+    {
+      int k;
+      int default_rule = LAruleno[state->lookaheadsp];
+
+      for (k = 0; k < tokensetsize; ++k)
+	lookaheadset[k] = LA (state->lookaheadsp)[k] & shiftset[k];
+
+      for (i = 0; i < ntokens; i++)
+	if (BITISSET (lookaheadset, i))
+	  fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
+		   tags[i], default_rule,
+		   tags[rule_table[default_rule].lhs]);
+
+      fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
+	       default_rule, tags[rule_table[default_rule].lhs]);
+    }
+  else if (state->nlookaheads >= 1)
+    {
+      int cmax = 0;
+      int default_LA = -1;
+      int default_rule = 0;
+
+      if (!nodefault)
+	for (i = 0; i < state->nlookaheads; ++i)
+	  {
+	    int count = 0;
+	    int j, k;
+
+	    for (k = 0; k < tokensetsize; ++k)
+	      lookaheadset[k] = LA (state->lookaheadsp + i)[k] & ~shiftset[k];
+
+	    for (j = 0; j < ntokens; j++)
+	      if (BITISSET (lookaheadset, j))
+		count++;
+
+	    if (count > cmax)
+	      {
+		cmax = count;
+		default_LA = state->lookaheadsp + i;
+		default_rule = LAruleno[state->lookaheadsp + i];
+	      }
+
+	    for (k = 0; k < tokensetsize; ++k)
+	      shiftset[k] |= lookaheadset[k];
+	  }
+
+      for (i = 0; i < tokensetsize; i++)
+	shiftset[i] = 0;
+
+      for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
+	if (!SHIFT_IS_DISABLED (shiftp, i))
+	  SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
+
+      for (i = 0; i < ntokens; i++)
+	{
+	  int j;
+	  int defaulted = 0;
+	  int count = BITISSET (shiftset, i);
+
+	  for (j = 0; j < state->nlookaheads; ++j)
+	    {
+	      if (BITISSET (LA (state->lookaheadsp + j), i))
+		{
+		  if (count == 0)
+		    {
+		      if (state->lookaheadsp + j != default_LA)
+			fprintf (out,
+				 _("    %-4s\treduce using rule %d (%s)\n"),
+				 tags[i],
+				 LAruleno[state->lookaheadsp + j],
+				 tags[rule_table[LAruleno[state->lookaheadsp + j]].lhs]);
+		      else
+			defaulted = 1;
+
+		      count++;
+		    }
+		  else
+		    {
+		      if (defaulted)
+			fprintf (out,
+				 _("    %-4s\treduce using rule %d (%s)\n"),
+				 tags[i],
+				 LAruleno[default_LA],
+				 tags[rule_table[LAruleno[default_LA]].lhs]);
+		      defaulted = 0;
+		      fprintf (out,
+			       _("    %-4s\t[reduce using rule %d (%s)]\n"),
+			       tags[i],
+			       LAruleno[state->lookaheadsp + j],
+			       tags[rule_table[LAruleno[state->lookaheadsp + j]].lhs]);
+		    }
+		}
+	    }
+	}
+
+      if (default_LA >= 0)
+	fprintf (out, _("    $default\treduce using rule %d (%s)\n"),
+		 default_rule, tags[rule_table[default_rule].lhs]);
+    }
+}
+
+
+static void
+print_actions (FILE *out, state_t *state)
+{
+  reductions *redp = state->reductions;
+  shifts *shiftp = state->shifts;
+
+  if (!shiftp->nshifts && !redp)
+    {
+      if (final_state == state->number)
+	fprintf (out, _("    $default\taccept\n"));
+      else
+	fprintf (out, _("    NO ACTIONS\n"));
+      return;
+    }
+
+  print_shifts (out, state);
+  print_errs (out, state);
+  if (redp)
+    print_reductions (out, state);
+  print_gotos (out, state);
+}
+
 static void
 print_state (FILE *out, state_t *state)
 {
@@ -325,13 +480,18 @@ print_results (void)
 
   print_grammar (out);
 
-  /* New experimental feature: output all the items of a state,
-     not only its kernel.  Requires to run closure, which need
-     memory allocation/deallocation.  */
+  /* New experimental feature: output all the items of a state, not
+     only its kernel.  Requires to run closure, which need memory
+     allocation/deallocation.  */
   if (trace_flag)
     new_closure (nitems);
+  /* Storage for print_reductions.  */
+  shiftset = XCALLOC (unsigned, tokensetsize);
+  lookaheadset = XCALLOC (unsigned, tokensetsize);
   for (i = 0; i < nstates; i++)
     print_state (out, state_table[i]);
+  free (shiftset);
+  free (lookaheadset);
   if (trace_flag)
     free_closure ();
 
