@@ -502,11 +502,6 @@ print_reductions (FILE *out, int state)
 {
   int i;
   int j;
-  int k;
-  unsigned *fp1;
-  unsigned *fp2;
-  unsigned *fp3;
-  unsigned *fp4;
   int rule;
   int symbol;
   unsigned mask;
@@ -525,28 +520,24 @@ print_reductions (FILE *out, int state)
 
   shiftp = state_table[state].shift_table;
   if (shiftp)
-    {
-      k = shiftp->nshifts;
-      for (i = 0; i < k; i++)
-	{
-	  if (!shiftp->shifts[i])
-	    continue;
-	  symbol = state_table[shiftp->shifts[i]].accessing_symbol;
-	  if (ISVAR (symbol))
-	    break;
-	  /* if this state has a shift for the error token,
-	     don't use a default rule.  */
-	  if (symbol == error_token_number)
-	    nodefault = 1;
-	  SETBIT (shiftset, symbol);
-	}
-    }
+    for (i = 0; i < shiftp->nshifts; i++)
+      {
+	if (!shiftp->shifts[i])
+	  continue;
+	symbol = state_table[shiftp->shifts[i]].accessing_symbol;
+	if (ISVAR (symbol))
+	  break;
+	/* if this state has a shift for the error token,
+	   don't use a default rule.  */
+	if (symbol == error_token_number)
+	  nodefault = 1;
+	SETBIT (shiftset, symbol);
+      }
 
   errp = err_table[state];
   if (errp)
     {
-      k = errp->nerrs;
-      for (i = 0; i < k; i++)
+      for (i = 0; i < errp->nerrs; i++)
 	{
 	  if (!errp->errs[i])
 	    continue;
@@ -560,12 +551,12 @@ print_reductions (FILE *out, int state)
 
   if (n - m == 1 && !nodefault)
     {
-      default_rule = LAruleno[m];
+      unsigned *fp1 = LA (m);
+      unsigned *fp2 = shiftset;
+      unsigned *fp3 = lookaheadset;
+      unsigned *fp4 = lookaheadset + tokensetsize;
 
-      fp1 = LA (m);
-      fp2 = shiftset;
-      fp3 = lookaheadset;
-      fp4 = lookaheadset + tokensetsize;
+      default_rule = LAruleno[m];
 
       while (fp3 < fp4)
 	*fp3++ = *fp1++ & *fp2++;
@@ -593,6 +584,8 @@ print_reductions (FILE *out, int state)
     }
   else if (n - m >= 1)
     {
+      unsigned *fp1, *fp2, *fp3, *fp4;
+
       cmax = 0;
       default_LA = -1;
       fp4 = lookaheadset + tokensetsize;
@@ -642,8 +635,7 @@ print_reductions (FILE *out, int state)
 
       if (shiftp)
 	{
-	  k = shiftp->nshifts;
-	  for (i = 0; i < k; i++)
+	  for (i = 0; i < shiftp->nshifts; i++)
 	    {
 	      if (!shiftp->shifts[i])
 		continue;
