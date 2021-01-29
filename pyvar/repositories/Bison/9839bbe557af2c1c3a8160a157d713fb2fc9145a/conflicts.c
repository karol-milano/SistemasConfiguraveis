@@ -62,8 +62,8 @@ flush_shift (int state, int token)
 
   if (shiftp)
     for (i = 0; i < shiftp->nshifts; i++)
-      if (shiftp->shifts[i] && SHIFT_SYMBOL (shiftp, i) == token)
-	shiftp->shifts[i] = 0;
+      if (!SHIFT_IS_DISABLED (shiftp, i) && SHIFT_SYMBOL (shiftp, i) == token)
+	SHIFT_DISABLE (shiftp, i);
 }
 
 
@@ -176,7 +176,8 @@ set_conflicts (int state)
   shiftp = state_table[state].shift_table;
   if (shiftp)
     for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-      SETBIT (lookaheadset, SHIFT_SYMBOL (shiftp, i));
+      if (!SHIFT_IS_DISABLED (shiftp, i))
+	SETBIT (lookaheadset, SHIFT_SYMBOL (shiftp, i));
 
   /* Loop over all rules which require lookahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
@@ -245,7 +246,8 @@ count_sr_conflicts (int state)
     }
 
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-    SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
+    if (!SHIFT_IS_DISABLED (shiftp, i))
+      SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
 
   for (i = state_table[state].lookaheads;
        i < state_table[state + 1].lookaheads;
@@ -436,13 +438,14 @@ print_reductions (FILE *out, int state)
   shiftp = state_table[state].shift_table;
   if (shiftp)
     for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-      {
-	/* if this state has a shift for the error token, don't use a
-	   default rule.  */
-	if (SHIFT_IS_ERROR (shiftp, i))
-	  nodefault = 1;
-	SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
-      }
+      if (!SHIFT_IS_DISABLED (shiftp, i))
+	{
+	  /* if this state has a shift for the error token, don't use a
+	     default rule.  */
+	  if (SHIFT_IS_ERROR (shiftp, i))
+	    nodefault = 1;
+	  SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
+	}
 
   errp = err_table[state];
   if (errp)
@@ -506,7 +509,8 @@ print_reductions (FILE *out, int state)
 
       if (shiftp)
 	for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-	  SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
+	  if (!SHIFT_IS_DISABLED (shiftp, i))
+	    SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
 
       for (i = 0; i < ntokens; i++)
 	{
