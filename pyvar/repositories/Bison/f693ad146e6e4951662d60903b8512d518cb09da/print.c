@@ -49,8 +49,8 @@ static void
 print_core (FILE *out, int state)
 {
   int i;
-  short *sitems = state_table[state].state->items;
-  int snitems   = state_table[state].state->nitems;
+  short *sitems = state_table[state]->items;
+  int snitems   = state_table[state]->nitems;
 
   /* New experimental feature: if TRACE_FLAGS output all the items of
      a state, not only its kernel.  */
@@ -98,9 +98,9 @@ print_actions (FILE *out, int state)
 {
   int i;
 
-  shifts   *shiftp = state_table[state].shifts;
-  reductions *redp = state_table[state].reductions;
-  errs       *errp = state_table[state].errs;
+  shifts   *shiftp = state_table[state]->shifts;
+  reductions *redp = state_table[state]->reductions;
+  errs       *errp = state_table[state]->errs;
 
   if (!shiftp->nshifts && !redp)
     {
@@ -115,7 +115,7 @@ print_actions (FILE *out, int state)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       {
 	int state1 = shiftp->shifts[i];
-	int symbol = state_table[state1].accessing_symbol;
+	int symbol = state_table[state1]->accessing_symbol;
 	/* The following line used to be turned off.  */
 	if (ISVAR (symbol))
 	  break;
@@ -147,7 +147,7 @@ print_actions (FILE *out, int state)
 	fputc ('\n', out);
     }
 
-  if (state_table[state].consistent && redp)
+  if (state_table[state]->consistent && redp)
     {
       int rule = redp->rules[0];
       int symbol = rule_table[rule].lhs;
@@ -165,7 +165,7 @@ print_actions (FILE *out, int state)
 	if (!SHIFT_IS_DISABLED (shiftp, i))
 	  {
 	    int state1 = shiftp->shifts[i];
-	    int symbol = state_table[state1].accessing_symbol;
+	    int symbol = state_table[state1]->accessing_symbol;
 	    fprintf (out, _("    %-4s\tgo to state %d\n"),
 		     tags[symbol], state1);
 	  }
