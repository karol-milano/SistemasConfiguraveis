@@ -414,16 +414,15 @@ print_reductions (FILE *out, int state)
 {
   int i;
   int j;
-  int m;
-  int n;
-  shifts *shiftp;
-  errs *errp;
+  int m = state_table[state]->lookaheads;
+  int n = state_table[state + 1]->lookaheads;
+  shifts *shiftp = state_table[state]->shifts;
+  errs *errp = state_table[state]->errs;
   int nodefault = 0;
 
   for (i = 0; i < tokensetsize; i++)
     shiftset[i] = 0;
 
-  shiftp = state_table[state]->shifts;
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       {
@@ -434,15 +433,11 @@ print_reductions (FILE *out, int state)
 	SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
       }
 
-  errp = state_table[state]->errs;
   if (errp)
     for (i = 0; i < errp->nerrs; i++)
       if (errp->errs[i])
 	SETBIT (shiftset, errp->errs[i]);
 
-  m = state_table[state]->lookaheads;
-  n = state_table[state + 1]->lookaheads;
-
   if (n - m == 1 && !nodefault)
     {
       int k;
