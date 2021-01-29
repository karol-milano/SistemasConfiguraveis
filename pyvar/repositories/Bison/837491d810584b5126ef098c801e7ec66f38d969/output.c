@@ -326,55 +326,44 @@ static int
 action_row (int state)
 {
   int i;
-  int j;
   int m = 0;
   int n = 0;
-  int default_rule;
-  int nreds;
-  int rule;
-  int shift_state;
-  int symbol;
-  reductions *redp;
-  shifts *shiftp;
-  errs *errp;
-  int nodefault = 0;		/* set nonzero to inhibit having any default reduction */
+  int default_rule = 0;
+  reductions *redp = state_table[state]->reductions;
+  int nreds = redp ? redp->nreds : 0;
+  shifts *shiftp = state_table[state]->shifts;
+  errs *errp = state_table[state]->errs;
+  /* set nonzero to inhibit having any default reduction */
+  int nodefault = 0;
 
   for (i = 0; i < ntokens; i++)
     actrow[i] = 0;
 
-  default_rule = 0;
-  nreds = 0;
-  redp = state_table[state]->reductions;
-
-  if (redp)
+  if (nreds >= 1)
     {
-      nreds = redp->nreds;
-
-      if (nreds >= 1)
-	{
-	  /* loop over all the rules available here which require
-	     lookahead */
-	  m = state_table[state]->lookaheads;
-	  n = state_table[state + 1]->lookaheads;
-
-	  for (i = n - 1; i >= m; i--)
-	    /* and find each token which the rule finds acceptable
-	       to come next */
-	    for (j = 0; j < ntokens; j++)
-	      /* and record this rule as the rule to use if that
-		 token follows.  */
-	      if (BITISSET (LA (i), j))
-		actrow[j] = -LAruleno[i];
-	}
+      int j;
+      /* loop over all the rules available here which require
+	 lookahead */
+      m = state_table[state]->lookaheads;
+      n = state_table[state + 1]->lookaheads;
+
+      for (i = n - 1; i >= m; i--)
+	/* and find each token which the rule finds acceptable
+	   to come next */
+	for (j = 0; j < ntokens; j++)
+	  /* and record this rule as the rule to use if that
+	     token follows.  */
+	  if (BITISSET (LA (i), j))
+	    actrow[j] = -LAruleno[i];
     }
 
   /* Now see which tokens are allowed for shifts in this state.  For
      them, record the shift as the thing to do.  So shift is preferred
      to reduce.  */
-  shiftp = state_table[state]->shifts;
   for (i = 0; i < shiftp->nshifts; i++)
     {
-      shift_state = shiftp->shifts[i];
+      int symbol;
+      int shift_state = shiftp->shifts[i];
       if (!shift_state)
 	continue;
 
@@ -393,12 +382,10 @@ action_row (int state)
 
   /* See which tokens are an explicit error in this state (due to
      %nonassoc).  For them, record MINSHORT as the action.  */
-  errp = state_table[state]->errs;
-
   if (errp)
     for (i = 0; i < errp->nerrs; i++)
       {
-	symbol = errp->errs[i];
+	int symbol = errp->errs[i];
 	actrow[symbol] = MINSHORT;
       }
 
@@ -415,13 +402,12 @@ action_row (int state)
 	  for (i = m; i < n; i++)
 	    {
 	      int count = 0;
-	      rule = -LAruleno[i];
+	      int rule = -LAruleno[i];
+	      int j;
 
 	      for (j = 0; j < ntokens; j++)
-		{
-		  if (actrow[j] == rule)
-		    count++;
-		}
+		if (actrow[j] == rule)
+		  count++;
 
 	      if (count > max)
 		{
@@ -435,11 +421,10 @@ action_row (int state)
 
 	  if (max > 0)
 	    {
+	      int j;
 	      for (j = 0; j < ntokens; j++)
-		{
-		  if (actrow[j] == default_rule)
-		    actrow[j] = 0;
-		}
+		if (actrow[j] == default_rule)
+		  actrow[j] = 0;
 
 	      default_rule = -default_rule;
 	    }
@@ -450,11 +435,9 @@ action_row (int state)
      So replace any action which says "error" with "use default".  */
 
   if (default_rule == 0)
-    for (j = 0; j < ntokens; j++)
-      {
-	if (actrow[j] == MINSHORT)
-	  actrow[j] = 0;
-      }
+    for (i = 0; i < ntokens; i++)
+      if (actrow[i] == MINSHORT)
+	actrow[i] = 0;
 
   return default_rule;
 }
@@ -566,7 +549,7 @@ save_column (int symbol, int default_state)
   short *sp1;
   short *sp2;
   int count;
-  int symno;
+  int symno = symbol - ntokens + nstates;
 
   short begin = goto_map[symbol];
   short end = goto_map[symbol + 1];
@@ -579,8 +562,6 @@ save_column (int symbol, int default_state)
   if (count == 0)
     return;
 
-  symno = symbol - ntokens + nstates;
-
   froms[symno] = sp1 = sp = XCALLOC (short, count);
   tos[symno] = sp2 = XCALLOC (short, count);
 
@@ -599,13 +580,10 @@ static int
 default_goto (int symbol)
 {
   int i;
-  int m;
-  int n;
-  int default_state;
-  int max;
-
-  m = goto_map[symbol];
-  n = goto_map[symbol + 1];
+  int m = goto_map[symbol];
+  int n = goto_map[symbol + 1];
+  int default_state = -1;
+  int max = 0;
 
   if (m == n)
     return -1;
@@ -616,9 +594,6 @@ default_goto (int symbol)
   for (i = m; i < n; i++)
     state_count[to_state[i]]++;
 
-  max = 0;
-  default_state = -1;
-
   for (i = 0; i < nstates; i++)
     if (state_count[i] > max)
       {
@@ -669,10 +644,6 @@ static void
 sort_actions (void)
 {
   int i;
-  int j;
-  int k;
-  int t;
-  int w;
 
   order = XCALLOC (short, nvectors);
   nentries = 0;
@@ -680,9 +651,10 @@ sort_actions (void)
   for (i = 0; i < nvectors; i++)
     if (tally[i] > 0)
       {
-	t = tally[i];
-	w = width[i];
-	j = nentries - 1;
+	int k;
+	int t = tally[i];
+	int w = width[i];
+	int j = nentries - 1;
 
 	while (j >= 0 && (width[order[j]] < w))
 	  j--;
@@ -702,15 +674,11 @@ sort_actions (void)
 static int
 matching_state (int vector)
 {
-  int i;
-  int j;
-  int k;
+  int i = order[vector];
   int t;
   int w;
-  int match;
   int prev;
 
-  i = order[vector];
   if (i >= nstates)
     return -1;
 
@@ -719,11 +687,13 @@ matching_state (int vector)
 
   for (prev = vector - 1; prev >= 0; prev--)
     {
-      j = order[prev];
+      int j = order[prev];
+      int k;
+      int match = 1;
+
       if (width[j] != w || tally[j] != t)
 	return -1;
 
-      match = 1;
       for (k = 0; match && k < t; k++)
 	if (tos[j][k] != tos[i][k] || froms[j][k] != froms[i][k])
 	  match = 0;
@@ -739,26 +709,19 @@ matching_state (int vector)
 static int
 pack_vector (int vector)
 {
-  int i;
+  int i = order[vector];
   int j;
-  int k;
-  int t;
+  int t = tally[i];
   int loc = 0;
-  int ok;
-  short *from;
-  short *to;
-
-  i = order[vector];
-  t = tally[i];
+  short *from = froms[i];
+  short *to = tos[i];
 
   assert (t);
 
-  from = froms[i];
-  to = tos[i];
-
   for (j = lowzero - from[0]; j < MAXTABLE; j++)
     {
-      ok = 1;
+      int k;
+      int ok = 1;
 
       for (k = 0; ok && k < t; k++)
 	{
