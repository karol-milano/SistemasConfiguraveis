@@ -36,19 +36,11 @@ extern short *LAruleno;
 extern short *lookaheads;
 extern int fixed_outfiles;
 
-extern void initialize_conflicts PARAMS((void));
-extern void conflict_log PARAMS((void));
-extern void verbose_conflict_log PARAMS((void));
-extern void print_reductions PARAMS((int));
-extern void finalize_conflicts PARAMS((void));
-
-static void set_conflicts PARAMS((int));
-static void resolve_sr_conflict PARAMS((int, int));
-static void flush_shift PARAMS((int, int));
-static void log_resolution PARAMS((int, int, int, char *));
-static void total_conflicts PARAMS((void));
-static void count_sr_conflicts PARAMS((int));
-static void count_rr_conflicts PARAMS((int));
+extern void initialize_conflicts PARAMS ((void));
+extern void conflict_log PARAMS ((void));
+extern void verbose_conflict_log PARAMS ((void));
+extern void print_reductions PARAMS ((int));
+extern void finalize_conflicts PARAMS ((void));
 
 char any_conflicts;
 errs **err_table;
@@ -62,122 +54,62 @@ static int src_total;
 static int rrc_total;
 static int src_count;
 static int rrc_count;
+
 
-
-void
-initialize_conflicts (void)
+static inline void
+log_resolution (int state, int LAno, int token, char *resolution)
 {
-  register int i;
-/*  register errs *sp; JF unused */
-
-  conflicts = NEW2(nstates, char);
-  shiftset = NEW2(tokensetsize, unsigned);
-  lookaheadset = NEW2(tokensetsize, unsigned);
-
-  err_table = NEW2(nstates, errs *);
-
-  any_conflicts = 0;
-
-  for (i = 0; i < nstates; i++)
-    set_conflicts(i);
+  if (verboseflag)
+    fprintf (foutput,
+	     _("\
+Conflict in state %d between rule %d and token %s resolved as %s.\n"),
+	     state, LAruleno[LAno], tags[token], resolution);
 }
 
 
+/*------------------------------------------------------------------.
+| Turn off the shift recorded for the specified token in the        |
+| specified state.  Used when we resolve a shift-reduce conflict in |
+| favor of the reduction.                                           |
+`------------------------------------------------------------------*/
+
 static void
-set_conflicts (int state)
+flush_shift (int state, int token)
 {
-  register int i;
-  register int k;
-  register shifts *shiftp;
-  register unsigned *fp2;
-  register unsigned *fp3;
-  register unsigned *fp4;
-  register unsigned *fp1;
-  register int symbol;
-
-  if (consistent[state]) return;
-
-  for (i = 0; i < tokensetsize; i++)
-    lookaheadset[i] = 0;
+  shifts *shiftp;
+  int k, i;
 
   shiftp = shift_table[state];
+
   if (shiftp)
     {
       k = shiftp->nshifts;
       for (i = 0; i < k; i++)
 	{
-	  symbol = accessing_symbol[shiftp->shifts[i]];
-	  if (ISVAR(symbol)) break;
-	  SETBIT(lookaheadset, symbol);
-	}
-    }
-
-  k = lookaheads[state + 1];
-  fp4 = lookaheadset + tokensetsize;
-
-  /* loop over all rules which require lookahead in this state */
-  /* first check for shift-reduce conflict, and try to resolve using precedence  */
-
-  for (i = lookaheads[state]; i < k; i++)
-    if (rprec[LAruleno[i]])
-      {
-	fp1 = LA + i * tokensetsize;
-	fp2 = fp1;
-	fp3 = lookaheadset;
-
-	while (fp3 < fp4)
-	  {
-	    if (*fp2++ & *fp3++)
-	      {
-		resolve_sr_conflict(state, i);
-		break;
-	      }
-	  }
-      }
-
-  /* loop over all rules which require lookahead in this state */
-  /* Check for conflicts not resolved above.  */
-
-  for (i = lookaheads[state]; i < k; i++)
-    {
-      fp1 = LA + i * tokensetsize;
-      fp2 = fp1;
-      fp3 = lookaheadset;
-
-      while (fp3 < fp4)
-	{
-	  if (*fp2++ & *fp3++)
-	    {
-	      conflicts[state] = 1;
-	      any_conflicts = 1;
-	    }
+	  if (shiftp->shifts[i]
+	      && token == accessing_symbol[shiftp->shifts[i]])
+	    (shiftp->shifts[i]) = 0;
 	}
-
-      fp2 = fp1;
-      fp3 = lookaheadset;
-
-      while (fp3 < fp4)
-	*fp3++ |= *fp2++;
     }
 }
 
 
-
-/* Attempt to resolve shift-reduce conflict for one rule
-by means of precedence declarations.
-It has already been checked that the rule has a precedence.
-A conflict is resolved by modifying the shift or reduce tables
-so that there is no longer a conflict.  */
+/*------------------------------------------------------------------.
+| Attempt to resolve shift-reduce conflict for one rule by means of |
+| precedence declarations.  It has already been checked that the    |
+| rule has a precedence.  A conflict is resolved by modifying the   |
+| shift or reduce tables so that there is no longer a conflict.     |
+`------------------------------------------------------------------*/
 
 static void
 resolve_sr_conflict (int state, int lookaheadnum)
 {
-  register int i;
-  register int mask;
-  register unsigned *fp1;
-  register unsigned *fp2;
-  register int redprec;
-  errs *errp = (errs *) xmalloc (sizeof(errs) + ntokens * sizeof(short));
+  int i;
+  int mask;
+  unsigned *fp1;
+  unsigned *fp2;
+  int redprec;
+  errs *errp = (errs *) xmalloc (sizeof (errs) + ntokens * sizeof (short));
   short *errtokens = errp->errs;
 
   /* find the rule to reduce by to get precedence of reduction  */
@@ -195,46 +127,45 @@ resolve_sr_conflict (int state, int lookaheadnum)
 	{
 	  if (sprec[i] < redprec)
 	    {
-	      if (verboseflag) log_resolution(state, lookaheadnum, i, _("reduce"));
-	      *fp2 &= ~mask;  /* flush the shift for this token */
-	      flush_shift(state, i);
+	      log_resolution (state, lookaheadnum, i, _("reduce"));
+	      *fp2 &= ~mask;	/* flush the shift for this token */
+	      flush_shift (state, i);
 	    }
 	  else if (sprec[i] > redprec)
 	    {
-	      if (verboseflag) log_resolution(state, lookaheadnum, i, _("shift"));
-	      *fp1 &= ~mask;  /* flush the reduce for this token */
+	      log_resolution (state, lookaheadnum, i, _("shift"));
+	      *fp1 &= ~mask;	/* flush the reduce for this token */
 	    }
 	  else
 	    {
 	      /* Matching precedence levels.
-		 For left association, keep only the reduction.
-		 For right association, keep only the shift.
-		 For nonassociation, keep neither.  */
+	         For left association, keep only the reduction.
+	         For right association, keep only the shift.
+	         For nonassociation, keep neither.  */
 
 	      switch (sassoc[i])
 		{
-
 		case RIGHT_ASSOC:
-	          if (verboseflag) log_resolution(state, lookaheadnum, i, _("shift"));
+		  log_resolution (state, lookaheadnum, i, _("shift"));
 		  break;
 
 		case LEFT_ASSOC:
-	          if (verboseflag) log_resolution(state, lookaheadnum, i, _("reduce"));
+		  log_resolution (state, lookaheadnum, i, _("reduce"));
 		  break;
 
 		case NON_ASSOC:
-	          if (verboseflag) log_resolution(state, lookaheadnum, i, _("an error"));
+		  log_resolution (state, lookaheadnum, i, _("an error"));
 		  break;
 		}
 
 	      if (sassoc[i] != RIGHT_ASSOC)
 		{
-		  *fp2 &= ~mask;  /* flush the shift for this token */
-		  flush_shift(state, i);
+		  *fp2 &= ~mask;	/* flush the shift for this token */
+		  flush_shift (state, i);
 		}
 	      if (sassoc[i] != LEFT_ASSOC)
-	        {
-		  *fp1 &= ~mask;  /* flush the reduce for this token */
+		{
+		  *fp1 &= ~mask;	/* flush the reduce for this token */
 		}
 	      if (sassoc[i] == NON_ASSOC)
 		{
@@ -248,180 +179,152 @@ resolve_sr_conflict (int state, int lookaheadnum)
       if (mask == 0)
 	{
 	  mask = 1;
-	  fp2++;  fp1++;
+	  fp2++;
+	  fp1++;
 	}
     }
   errp->nerrs = errtokens - errp->errs;
   if (errp->nerrs)
     {
       /* Some tokens have been explicitly made errors.  Allocate
-	 a permanent errs structure for this state, to record them.  */
+         a permanent errs structure for this state, to record them.  */
       i = (char *) errtokens - (char *) errp;
-      err_table[state] = (errs *) xmalloc ((unsigned int)i);
+      err_table[state] = (errs *) xmalloc ((unsigned int) i);
       bcopy (errp, err_table[state], i);
     }
   else
     err_table[state] = 0;
-  free(errp);
+  free (errp);
 }
 
 
-
-/* turn off the shift recorded for the specified token in the specified state.
-Used when we resolve a shift-reduce conflict in favor of the reduction.  */
-
 static void
-flush_shift (int state, int token)
+set_conflicts (int state)
 {
-  register shifts *shiftp;
-  register int k, i;
-/*  register unsigned symbol; JF unused */
+  int i;
+  int k;
+  shifts *shiftp;
+  unsigned *fp2;
+  unsigned *fp3;
+  unsigned *fp4;
+  unsigned *fp1;
+  int symbol;
+
+  if (consistent[state])
+    return;
 
-  shiftp = shift_table[state];
+  for (i = 0; i < tokensetsize; i++)
+    lookaheadset[i] = 0;
 
+  shiftp = shift_table[state];
   if (shiftp)
     {
       k = shiftp->nshifts;
       for (i = 0; i < k; i++)
 	{
-	  if (shiftp->shifts[i] && token == accessing_symbol[shiftp->shifts[i]])
-	    (shiftp->shifts[i]) = 0;
+	  symbol = accessing_symbol[shiftp->shifts[i]];
+	  if (ISVAR (symbol))
+	    break;
+	  SETBIT (lookaheadset, symbol);
 	}
     }
-}
-
 
-static void
-log_resolution (int state, int LAno, int token, char *resolution)
-{
-  fprintf(foutput,
-	  _("Conflict in state %d between rule %d and token %s resolved as %s.\n"),
-	  state, LAruleno[LAno], tags[token], resolution);
-}
+  k = lookaheads[state + 1];
+  fp4 = lookaheadset + tokensetsize;
 
+  /* Loop over all rules which require lookahead in this state.  First
+     check for shift-reduce conflict, and try to resolve using
+     precedence */
+  for (i = lookaheads[state]; i < k; i++)
+    if (rprec[LAruleno[i]])
+      {
+	fp1 = LA + i * tokensetsize;
+	fp2 = fp1;
+	fp3 = lookaheadset;
 
-void
-conflict_log (void)
-{
-  register int i;
+	while (fp3 < fp4)
+	  {
+	    if (*fp2++ & *fp3++)
+	      {
+		resolve_sr_conflict (state, i);
+		break;
+	      }
+	  }
+      }
 
-  src_total = 0;
-  rrc_total = 0;
 
-  for (i = 0; i < nstates; i++)
+  /* Loop over all rules which require lookahead in this state.  Check
+     for conflicts not resolved above.  */
+  for (i = lookaheads[state]; i < k; i++)
     {
-      if (conflicts[i])
+      fp1 = LA + i * tokensetsize;
+      fp2 = fp1;
+      fp3 = lookaheadset;
+
+      while (fp3 < fp4)
 	{
-	  count_sr_conflicts(i);
-	  count_rr_conflicts(i);
-	  src_total += src_count;
-	  rrc_total += rrc_count;
+	  if (*fp2++ & *fp3++)
+	    {
+	      conflicts[state] = 1;
+	      any_conflicts = 1;
+	    }
 	}
-    }
 
-  total_conflicts();
-}
+      fp2 = fp1;
+      fp3 = lookaheadset;
 
+      while (fp3 < fp4)
+	*fp3++ |= *fp2++;
+    }
+}
 
 void
-verbose_conflict_log (void)
+initialize_conflicts (void)
 {
-  register int i;
+  int i;
+/*  errs *sp; JF unused */
 
-  src_total = 0;
-  rrc_total = 0;
-
-  for (i = 0; i < nstates; i++)
-    {
-      if (conflicts[i])
-	{
-	  count_sr_conflicts(i);
-	  count_rr_conflicts(i);
-	  src_total += src_count;
-	  rrc_total += rrc_count;
+  conflicts = NEW2 (nstates, char);
+  shiftset = NEW2 (tokensetsize, unsigned);
+  lookaheadset = NEW2 (tokensetsize, unsigned);
 
-	  fprintf(foutput, _("State %d contains"), i);
-
-	  if (src_count == 1)
-	    fprintf(foutput, _(" 1 shift/reduce conflict"));
-	  else if (src_count > 1)
-	    fprintf(foutput, _(" %d shift/reduce conflicts"), src_count);
-
-	  if (src_count > 0 && rrc_count > 0)
-	    fprintf(foutput, _(" and"));
-
-	  if (rrc_count == 1)
-	    fprintf(foutput, _(" 1 reduce/reduce conflict"));
-	  else if (rrc_count > 1)
-	    fprintf(foutput, _(" %d reduce/reduce conflicts"), rrc_count);
+  err_table = NEW2 (nstates, errs *);
 
-	  putc('.', foutput);
-	  putc('\n', foutput);
-	}
-    }
+  any_conflicts = 0;
 
-  total_conflicts();
+  for (i = 0; i < nstates; i++)
+    set_conflicts (i);
 }
 
 
-static void
-total_conflicts (void)
-{
-  if (src_total == expected_conflicts && rrc_total == 0)
-    return;
 
-  if (fixed_outfiles)
-    {
-      /* If invoked under the name `yacc', use the output format
-	 specified by POSIX.  */
-      fprintf(stderr, _("conflicts: "));
-      if (src_total > 0)
-	fprintf(stderr, _(" %d shift/reduce"), src_total);
-      if (src_total > 0 && rrc_total > 0)
-	fprintf(stderr, ",");
-      if (rrc_total > 0)
-	fprintf(stderr, _(" %d reduce/reduce"), rrc_total);
-      putc('\n', stderr);
-    }
-  else
-    {
-      fprintf(stderr, _("%s contains"), infile);
 
-      if (src_total == 1)
-	fprintf(stderr, _(" 1 shift/reduce conflict"));
-      else if (src_total > 1)
-	fprintf(stderr, _(" %d shift/reduce conflicts"), src_total);
 
-      if (src_total > 0 && rrc_total > 0)
-	fprintf(stderr, _(" and"));
 
-      if (rrc_total == 1)
-	fprintf(stderr, _(" 1 reduce/reduce conflict"));
-      else if (rrc_total > 1)
-	fprintf(stderr, _(" %d reduce/reduce conflicts"), rrc_total);
 
-      putc('.', stderr);
-      putc('\n', stderr);
-    }
-}
 
 
+/*---------------------------------------------.
+| Count the number of shift/reduce conflicts.  |
+`---------------------------------------------*/
+
 static void
 count_sr_conflicts (int state)
 {
-  register int i;
-  register int k;
-  register int mask;
-  register shifts *shiftp;
-  register unsigned *fp1;
-  register unsigned *fp2;
-  register unsigned *fp3;
-  register int symbol;
+  int i;
+  int k;
+  int mask;
+  shifts *shiftp;
+  unsigned *fp1;
+  unsigned *fp2;
+  unsigned *fp3;
+  int symbol;
 
   src_count = 0;
 
   shiftp = shift_table[state];
-  if (!shiftp) return;
+  if (!shiftp)
+    return;
 
   for (i = 0; i < tokensetsize; i++)
     {
@@ -432,10 +335,12 @@ count_sr_conflicts (int state)
   k = shiftp->nshifts;
   for (i = 0; i < k; i++)
     {
-      if (! shiftp->shifts[i]) continue;
+      if (!shiftp->shifts[i])
+	continue;
       symbol = accessing_symbol[shiftp->shifts[i]];
-      if (ISVAR(symbol)) break;
-      SETBIT(shiftset, symbol);
+      if (ISVAR (symbol))
+	break;
+      SETBIT (shiftset, symbol);
     }
 
   k = lookaheads[state + 1];
@@ -473,24 +378,29 @@ count_sr_conflicts (int state)
 }
 
 
+/*----------------------------------------------.
+| Count the number of reduce/reduce conflicts.  |
+`----------------------------------------------*/
+
 static void
 count_rr_conflicts (int state)
 {
-  register int i;
-  register int j;
-  register int count;
-  register unsigned mask;
-  register unsigned *baseword;
-  register unsigned *wordp;
-  register int m;
-  register int n;
+  int i;
+  int j;
+  int count;
+  unsigned mask;
+  unsigned *baseword;
+  unsigned *wordp;
+  int m;
+  int n;
 
   rrc_count = 0;
 
   m = lookaheads[state];
   n = lookaheads[state + 1];
 
-  if (n - m < 2) return;
+  if (n - m < 2)
+    return;
 
   mask = 1;
   baseword = LA + m * tokensetsize;
@@ -507,7 +417,8 @@ count_rr_conflicts (int state)
 	  wordp += tokensetsize;
 	}
 
-      if (count >= 2) rrc_count++;
+      if (count >= 2)
+	rrc_count++;
 
       mask <<= 1;
       if (mask == 0)
@@ -518,28 +429,145 @@ count_rr_conflicts (int state)
     }
 }
 
+/*------------------------------------.
+| Give a report about the conflicts.  |
+`------------------------------------*/
+
+static void
+total_conflicts (void)
+{
+  if (src_total == expected_conflicts && rrc_total == 0)
+    return;
+
+  if (fixed_outfiles)
+    {
+      /* If invoked under the name `yacc', use the output format
+         specified by POSIX.  */
+      fprintf (stderr, _("conflicts: "));
+      if (src_total > 0)
+	fprintf (stderr, _(" %d shift/reduce"), src_total);
+      if (src_total > 0 && rrc_total > 0)
+	fprintf (stderr, ",");
+      if (rrc_total > 0)
+	fprintf (stderr, _(" %d reduce/reduce"), rrc_total);
+      putc ('\n', stderr);
+    }
+  else
+    {
+      fprintf (stderr, _("%s contains"), infile);
+
+      if (src_total == 1)
+	fprintf (stderr, _(" 1 shift/reduce conflict"));
+      else if (src_total > 1)
+	fprintf (stderr, _(" %d shift/reduce conflicts"), src_total);
+
+      if (src_total > 0 && rrc_total > 0)
+	fprintf (stderr, _(" and"));
+
+      if (rrc_total == 1)
+	fprintf (stderr, _(" 1 reduce/reduce conflict"));
+      else if (rrc_total > 1)
+	fprintf (stderr, _(" %d reduce/reduce conflicts"), rrc_total);
+
+      putc ('.', stderr);
+      putc ('\n', stderr);
+    }
+}
+
+
+/*---------------------------------------------.
+| Compute and give a report on the conflicts.  |
+`---------------------------------------------*/
+
+void
+conflict_log (void)
+{
+  int i;
+
+  src_total = 0;
+  rrc_total = 0;
+
+  for (i = 0; i < nstates; i++)
+    {
+      if (conflicts[i])
+	{
+	  count_sr_conflicts (i);
+	  count_rr_conflicts (i);
+	  src_total += src_count;
+	  rrc_total += rrc_count;
+	}
+    }
+
+  total_conflicts ();
+}
+
+
+void
+verbose_conflict_log (void)
+{
+  int i;
+
+  src_total = 0;
+  rrc_total = 0;
+
+  for (i = 0; i < nstates; i++)
+    {
+      if (conflicts[i])
+	{
+	  count_sr_conflicts (i);
+	  count_rr_conflicts (i);
+	  src_total += src_count;
+	  rrc_total += rrc_count;
+
+	  fprintf (foutput, _("State %d contains"), i);
+
+	  if (src_count == 1)
+	    fprintf (foutput, _(" 1 shift/reduce conflict"));
+	  else if (src_count > 1)
+	    fprintf (foutput, _(" %d shift/reduce conflicts"), src_count);
+
+	  if (src_count > 0 && rrc_count > 0)
+	    fprintf (foutput, _(" and"));
+
+	  if (rrc_count == 1)
+	    fprintf (foutput, _(" 1 reduce/reduce conflict"));
+	  else if (rrc_count > 1)
+	    fprintf (foutput, _(" %d reduce/reduce conflicts"), rrc_count);
+
+	  putc ('.', foutput);
+	  putc ('\n', foutput);
+	}
+    }
+
+  total_conflicts ();
+}
+
+
+
+
+
 
 void
 print_reductions (int state)
 {
-  register int i;
-  register int j;
-  register int k;
-  register unsigned *fp1;
-  register unsigned *fp2;
-  register unsigned *fp3;
-  register unsigned *fp4;
-  register int rule;
-  register int symbol;
-  register unsigned mask;
-  register int m;
-  register int n;
-  register int default_LA;
-  register int default_rule = 0;
-  register int cmax;
-  register int count;
-  register shifts *shiftp;
-  register errs *errp;
+  int i;
+  int j;
+  int k;
+  unsigned *fp1;
+  unsigned *fp2;
+  unsigned *fp3;
+  unsigned *fp4;
+  int rule;
+  int symbol;
+  unsigned mask;
+  int m;
+  int n;
+  int default_LA;
+  int default_rule = 0;
+  int cmax;
+  int count;
+  shifts *shiftp;
+  errs *errp;
   int nodefault = 0;
 
   for (i = 0; i < tokensetsize; i++)
@@ -551,13 +579,16 @@ print_reductions (int state)
       k = shiftp->nshifts;
       for (i = 0; i < k; i++)
 	{
-	  if (! shiftp->shifts[i]) continue;
+	  if (!shiftp->shifts[i])
+	    continue;
 	  symbol = accessing_symbol[shiftp->shifts[i]];
-	  if (ISVAR(symbol)) break;
+	  if (ISVAR (symbol))
+	    break;
 	  /* if this state has a shift for the error token,
 	     don't use a default rule.  */
-	  if (symbol == error_token_number) nodefault = 1;
-	  SETBIT(shiftset, symbol);
+	  if (symbol == error_token_number)
+	    nodefault = 1;
+	  SETBIT (shiftset, symbol);
 	}
     }
 
@@ -567,16 +598,17 @@ print_reductions (int state)
       k = errp->nerrs;
       for (i = 0; i < k; i++)
 	{
-	  if (! errp->errs[i]) continue;
+	  if (!errp->errs[i])
+	    continue;
 	  symbol = errp->errs[i];
-	  SETBIT(shiftset, symbol);
+	  SETBIT (shiftset, symbol);
 	}
     }
 
   m = lookaheads[state];
   n = lookaheads[state + 1];
 
-  if (n - m == 1 && ! nodefault)
+  if (n - m == 1 && !nodefault)
     {
       default_rule = LAruleno[m];
 
@@ -594,8 +626,8 @@ print_reductions (int state)
       for (i = 0; i < ntokens; i++)
 	{
 	  if (mask & *fp3)
-	    fprintf(foutput, _("    %-4s\t[reduce using rule %d (%s)]\n"),
-		    tags[i], default_rule, tags[rlhs[default_rule]]);
+	    fprintf (foutput, _("    %-4s\t[reduce using rule %d (%s)]\n"),
+		     tags[i], default_rule, tags[rlhs[default_rule]]);
 
 	  mask <<= 1;
 	  if (mask == 0)
@@ -605,8 +637,8 @@ print_reductions (int state)
 	    }
 	}
 
-      fprintf(foutput, _("    $default\treduce using rule %d (%s)\n\n"),
-	      default_rule, tags[rlhs[default_rule]]);
+      fprintf (foutput, _("    $default\treduce using rule %d (%s)\n\n"),
+	       default_rule, tags[rlhs[default_rule]]);
     }
   else if (n - m >= 1)
     {
@@ -614,7 +646,7 @@ print_reductions (int state)
       default_LA = -1;
       fp4 = lookaheadset + tokensetsize;
 
-      if (! nodefault)
+      if (!nodefault)
 	for (i = m; i < n; i++)
 	  {
 	    fp1 = LA + i * tokensetsize;
@@ -655,19 +687,21 @@ print_reductions (int state)
 	  }
 
       for (i = 0; i < tokensetsize; i++)
-        shiftset[i] = 0;
+	shiftset[i] = 0;
 
       if (shiftp)
-        {
-          k = shiftp->nshifts;
-          for (i = 0; i < k; i++)
+	{
+	  k = shiftp->nshifts;
+	  for (i = 0; i < k; i++)
 	    {
-	      if (! shiftp->shifts[i]) continue;
+	      if (!shiftp->shifts[i])
+		continue;
 	      symbol = accessing_symbol[shiftp->shifts[i]];
-	      if (ISVAR(symbol)) break;
-	      SETBIT(shiftset, symbol);
+	      if (ISVAR (symbol))
+		break;
+	      SETBIT (shiftset, symbol);
 	    }
-        }
+	}
 
       mask = 1;
       fp1 = LA + m * tokensetsize;
@@ -691,10 +725,12 @@ print_reductions (int state)
 		      if (j != default_LA)
 			{
 			  rule = LAruleno[j];
-			  fprintf(foutput, _("    %-4s\treduce using rule %d (%s)\n"),
-				  tags[i], rule, tags[rlhs[rule]]);
+			  fprintf (foutput,
+				   _("    %-4s\treduce using rule %d (%s)\n"),
+				   tags[i], rule, tags[rlhs[rule]]);
 			}
-		      else defaulted = 1;
+		      else
+			defaulted = 1;
 
 		      count++;
 		    }
@@ -703,13 +739,15 @@ print_reductions (int state)
 		      if (defaulted)
 			{
 			  rule = LAruleno[default_LA];
-			  fprintf(foutput, _("    %-4s\treduce using rule %d (%s)\n"),
-				  tags[i], rule, tags[rlhs[rule]]);
+			  fprintf (foutput,
+				   _("    %-4s\treduce using rule %d (%s)\n"),
+				   tags[i], rule, tags[rlhs[rule]]);
 			  defaulted = 0;
 			}
 		      rule = LAruleno[j];
-		      fprintf(foutput, _("    %-4s\t[reduce using rule %d (%s)]\n"),
-			      tags[i], rule, tags[rlhs[rule]]);
+		      fprintf (foutput,
+			       _("    %-4s\t[reduce using rule %d (%s)]\n"),
+			       tags[i], rule, tags[rlhs[rule]]);
 		    }
 		}
 
@@ -721,7 +759,7 @@ print_reductions (int state)
 	    {
 	      mask = 1;
 	      /* We tried incrementing just fp1, and just fp2; both seem wrong.
-		 It seems necessary to increment both in sync.  */
+	         It seems necessary to increment both in sync.  */
 	      fp1++;
 	      fp2++;
 	    }
@@ -729,11 +767,11 @@ print_reductions (int state)
 
       if (default_LA >= 0)
 	{
-	  fprintf(foutput, _("    $default\treduce using rule %d (%s)\n"),
-		  default_rule, tags[rlhs[default_rule]]);
+	  fprintf (foutput, _("    $default\treduce using rule %d (%s)\n"),
+		   default_rule, tags[rlhs[default_rule]]);
 	}
 
-      putc('\n', foutput);
+      putc ('\n', foutput);
     }
 }
 
@@ -741,7 +779,7 @@ print_reductions (int state)
 void
 finalize_conflicts (void)
 {
-  FREE(conflicts);
-  FREE(shiftset);
-  FREE(lookaheadset);
+  FREE (conflicts);
+  FREE (shiftset);
+  FREE (lookaheadset);
 }
