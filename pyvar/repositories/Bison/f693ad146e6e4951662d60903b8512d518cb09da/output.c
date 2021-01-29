@@ -212,7 +212,7 @@ output_stos (void)
   int i;
   short *values = (short *) alloca (sizeof (short) * nstates);
   for (i = 0; i < nstates; ++i)
-    values[i] = state_table[i].accessing_symbol;
+    values[i] = state_table[i]->accessing_symbol;
   output_table_data (&output_obstack, values,
 		     0, 1, nstates);
   muscle_insert ("stos", obstack_finish (&output_obstack));
@@ -355,7 +355,7 @@ action_row (int state)
 
   default_rule = 0;
   nreds = 0;
-  redp = state_table[state].reductions;
+  redp = state_table[state]->reductions;
 
   if (redp)
     {
@@ -365,8 +365,8 @@ action_row (int state)
 	{
 	  /* loop over all the rules available here which require
 	     lookahead */
-	  m = state_table[state].lookaheads;
-	  n = state_table[state + 1].lookaheads;
+	  m = state_table[state]->lookaheads;
+	  n = state_table[state + 1]->lookaheads;
 
 	  for (i = n - 1; i >= m; i--)
 	    /* and find each token which the rule finds acceptable
@@ -382,14 +382,14 @@ action_row (int state)
   /* Now see which tokens are allowed for shifts in this state.  For
      them, record the shift as the thing to do.  So shift is preferred
      to reduce.  */
-  shiftp = state_table[state].shifts;
+  shiftp = state_table[state]->shifts;
   for (i = 0; i < shiftp->nshifts; i++)
     {
       shift_state = shiftp->shifts[i];
       if (!shift_state)
 	continue;
 
-      symbol = state_table[shift_state].accessing_symbol;
+      symbol = state_table[shift_state]->accessing_symbol;
 
       if (ISVAR (symbol))
 	break;
@@ -404,7 +404,7 @@ action_row (int state)
 
   /* See which tokens are an explicit error in this state (due to
      %nonassoc).  For them, record MINSHORT as the action.  */
-  errp = state_table[state].errs;
+  errp = state_table[state]->errs;
 
   if (errp)
     {
@@ -422,7 +422,7 @@ action_row (int state)
 
   if (nreds >= 1 && !nodefault)
     {
-      if (state_table[state].consistent)
+      if (state_table[state]->consistent)
 	default_rule = redp->rules[0];
       else
 	{
@@ -910,6 +910,7 @@ output_actions (void)
   output_table ();
 
   output_check ();
+  LIST_FREE (state_t, first_state);
   XFREE (state_table);
 }
 
@@ -1051,8 +1052,6 @@ output (void)
 {
   obstack_init (&output_obstack);
 
-  LIST_FREE (core, first_state);
-
   output_token_translations ();
   output_gram ();
 
