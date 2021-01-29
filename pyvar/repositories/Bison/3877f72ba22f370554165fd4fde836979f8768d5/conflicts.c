@@ -172,8 +172,8 @@ set_conflicts (int state)
   /* Loop over all rules which require lookahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
      precedence */
-  for (i = state_table[state]->lookaheads;
-       i < state_table[state + 1]->lookaheads;
+  for (i = state_table[state]->lookaheadsp;
+       i < state_table[state + 1]->lookaheadsp;
        ++i)
     if (rule_table[LAruleno[i]].prec)
       for (j = 0; j < tokensetsize; ++j)
@@ -186,8 +186,8 @@ set_conflicts (int state)
 
   /* Loop over all rules which require lookahead in this state.  Check
      for conflicts not resolved above.  */
-  for (i = state_table[state]->lookaheads;
-       i < state_table[state + 1]->lookaheads;
+  for (i = state_table[state]->lookaheadsp;
+       i < state_table[state + 1]->lookaheadsp;
        ++i)
     {
       for (j = 0; j < tokensetsize; ++j)
@@ -237,8 +237,8 @@ count_sr_conflicts (int state)
     if (!SHIFT_IS_DISABLED (shiftp, i))
       SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
 
-  for (i = state_table[state]->lookaheads;
-       i < state_table[state + 1]->lookaheads;
+  for (i = state_table[state]->lookaheadsp;
+       i < state_table[state + 1]->lookaheadsp;
        ++i)
     for (k = 0; k < tokensetsize; ++k)
       lookaheadset[k] |= LA (i)[k];
@@ -264,8 +264,8 @@ count_rr_conflicts (int state)
   int i;
   int rrc_count = 0;
 
-  int m = state_table[state]->lookaheads;
-  int n = state_table[state + 1]->lookaheads;
+  int m = state_table[state]->lookaheadsp;
+  int n = state_table[state + 1]->lookaheadsp;
 
   if (n - m < 2)
     return 0;
@@ -414,8 +414,8 @@ print_reductions (FILE *out, int state)
 {
   int i;
   int j;
-  int m = state_table[state]->lookaheads;
-  int n = state_table[state + 1]->lookaheads;
+  int m = state_table[state]->lookaheadsp;
+  int n = state_table[state + 1]->lookaheadsp;
   shifts *shiftp = state_table[state]->shifts;
   errs *errp = state_table[state]->errs;
   int nodefault = 0;
