@@ -87,16 +87,10 @@ print_actions (FILE *out, int state)
 {
   int i;
   int k;
-  int state1;
-  int symbol;
-  shifts *shiftp;
-  errs *errp;
-  reductions *redp;
-  int rule;
 
-  shiftp = state_table[state].shift_table;
-  redp = state_table[state].reduction_table;
-  errp = err_table[state];
+  shifts   *shiftp = state_table[state].shift_table;
+  reductions *redp = state_table[state].reduction_table;
+  errs       *errp = err_table[state];
 
   if (!shiftp && !redp)
     {
@@ -113,9 +107,10 @@ print_actions (FILE *out, int state)
 
       for (i = 0; i < k; i++)
 	{
-	  if (!shiftp->shifts[i])
+	  int symbol;
+	  int state1 = shiftp->shifts[i];
+	  if (!state1)
 	    continue;
-	  state1 = shiftp->shifts[i];
 	  symbol = state_table[state1].accessing_symbol;
 	  /* The following line used to be turned off.  */
 	  if (ISVAR (symbol))
@@ -140,15 +135,12 @@ print_actions (FILE *out, int state)
 
   if (errp)
     {
-      int j, nerrs;
-
-      nerrs = errp->nerrs;
-
-      for (j = 0; j < nerrs; j++)
+      int j;
+      for (j = 0; j < errp->nerrs; j++)
 	{
-	  if (!errp->errs[j])
+	  int symbol = errp->errs[j];
+	  if (!symbol)
 	    continue;
-	  symbol = errp->errs[j];
 	  fprintf (out, _("    %-4s\terror (nonassociative)\n"),
 		   tags[symbol]);
 	}
@@ -159,8 +151,8 @@ print_actions (FILE *out, int state)
 
   if (state_table[state].consistent && redp)
     {
-      rule = redp->rules[0];
-      symbol = rule_table[rule].lhs;
+      int rule = redp->rules[0];
+      int symbol = rule_table[rule].lhs;
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
 	       rule, tags[symbol]);
     }
@@ -173,9 +165,10 @@ print_actions (FILE *out, int state)
     {
       for (; i < k; i++)
 	{
-	  if (!shiftp->shifts[i])
+	  int symbol;
+	  int state1 = shiftp->shifts[i];
+	  if (!state1)
 	    continue;
-	  state1 = shiftp->shifts[i];
 	  symbol = state_table[state1].accessing_symbol;
 	  fprintf (out, _("    %-4s\tgo to state %d\n"),
 		   tags[symbol], state1);
