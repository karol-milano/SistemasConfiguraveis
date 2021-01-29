@@ -184,7 +184,6 @@ set_conflicts (int state)
 {
   int i, j;
   shifts *shiftp;
-  int symbol;
 
   if (state_table[state].consistent)
     return;
@@ -194,13 +193,8 @@ set_conflicts (int state)
 
   shiftp = state_table[state].shift_table;
   if (shiftp)
-    for (i = 0; i < shiftp->nshifts; i++)
-      {
-	symbol = state_table[shiftp->shifts[i]].accessing_symbol;
-	if (ISVAR (symbol))
-	  break;
-	SETBIT (lookaheadset, symbol);
-      }
+    for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
+      SETBIT (lookaheadset, SHIFT_SYMBOL (shiftp, i));
 
   /* Loop over all rules which require lookahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
@@ -269,10 +263,7 @@ count_sr_conflicts (int state)
     }
 
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-    {
-      int symbol = state_table[shiftp->shifts[i]].accessing_symbol;
-      SETBIT (shiftset, symbol);
-    }
+    SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
 
   for (i = state_table[state].lookaheads;
        i < state_table[state + 1].lookaheads;
@@ -451,7 +442,6 @@ print_reductions (FILE *out, int state)
 {
   int i;
   int j;
-  int symbol;
   int m;
   int n;
   shifts *shiftp;
@@ -463,18 +453,13 @@ print_reductions (FILE *out, int state)
 
   shiftp = state_table[state].shift_table;
   if (shiftp)
-    for (i = 0; i < shiftp->nshifts; i++)
+    for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
       {
-	if (!shiftp->shifts[i])
-	  continue;
-	symbol = state_table[shiftp->shifts[i]].accessing_symbol;
-	if (ISVAR (symbol))
-	  break;
-	/* if this state has a shift for the error token,
-	   don't use a default rule.  */
-	if (symbol == error_token_number)
+	/* if this state has a shift for the error token, don't use a
+	   default rule.  */
+	if (SHIFT_IS_ERROR (shiftp, i))
 	  nodefault = 1;
-	SETBIT (shiftset, symbol);
+	SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
       }
 
   errp = err_table[state];
@@ -538,15 +523,8 @@ print_reductions (FILE *out, int state)
 	shiftset[i] = 0;
 
       if (shiftp)
-	for (i = 0; i < shiftp->nshifts; i++)
-	  {
-	    if (!shiftp->shifts[i])
-	      continue;
-	    symbol = state_table[shiftp->shifts[i]].accessing_symbol;
-	    if (ISVAR (symbol))
-	      break;
-	    SETBIT (shiftset, symbol);
-	  }
+	for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
+	  SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
 
       for (i = 0; i < ntokens; i++)
 	{
