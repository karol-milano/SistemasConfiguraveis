@@ -60,10 +60,9 @@ flush_shift (int state, int token)
   shifts *shiftp = state_table[state].shift_table;
   int i;
 
-  if (shiftp)
-    for (i = 0; i < shiftp->nshifts; i++)
-      if (!SHIFT_IS_DISABLED (shiftp, i) && SHIFT_SYMBOL (shiftp, i) == token)
-	SHIFT_DISABLE (shiftp, i);
+  for (i = 0; i < shiftp->nshifts; i++)
+    if (!SHIFT_IS_DISABLED (shiftp, i) && SHIFT_SYMBOL (shiftp, i) == token)
+      SHIFT_DISABLE (shiftp, i);
 }
 
 
@@ -174,10 +173,9 @@ set_conflicts (int state)
     lookaheadset[i] = 0;
 
   shiftp = state_table[state].shift_table;
-  if (shiftp)
-    for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-      if (!SHIFT_IS_DISABLED (shiftp, i))
-	SETBIT (lookaheadset, SHIFT_SYMBOL (shiftp, i));
+  for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
+    if (!SHIFT_IS_DISABLED (shiftp, i))
+      SETBIT (lookaheadset, SHIFT_SYMBOL (shiftp, i));
 
   /* Loop over all rules which require lookahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
@@ -436,16 +434,15 @@ print_reductions (FILE *out, int state)
     shiftset[i] = 0;
 
   shiftp = state_table[state].shift_table;
-  if (shiftp)
-    for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-      if (!SHIFT_IS_DISABLED (shiftp, i))
-	{
-	  /* if this state has a shift for the error token, don't use a
-	     default rule.  */
-	  if (SHIFT_IS_ERROR (shiftp, i))
-	    nodefault = 1;
-	  SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
-	}
+  for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
+    if (!SHIFT_IS_DISABLED (shiftp, i))
+      {
+	/* if this state has a shift for the error token, don't use a
+	   default rule.  */
+	if (SHIFT_IS_ERROR (shiftp, i))
+	  nodefault = 1;
+	SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
+      }
 
   errp = err_table[state];
   if (errp)
@@ -507,10 +504,9 @@ print_reductions (FILE *out, int state)
       for (i = 0; i < tokensetsize; i++)
 	shiftset[i] = 0;
 
-      if (shiftp)
-	for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
-	  if (!SHIFT_IS_DISABLED (shiftp, i))
-	    SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
+      for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
+	if (!SHIFT_IS_DISABLED (shiftp, i))
+	  SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
 
       for (i = 0; i < ntokens; i++)
 	{
