@@ -210,13 +210,13 @@ set_conflicts (int state)
 	}
     }
 
-  k = lookaheads[state + 1];
+  k = state_table[state + 1].lookaheads;
   fp4 = lookaheadset + tokensetsize;
 
   /* Loop over all rules which require lookahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
      precedence */
-  for (i = lookaheads[state]; i < k; i++)
+  for (i = state_table[state].lookaheads; i < k; i++)
     if (rprec[LAruleno[i]])
       {
 	fp1 = LA + i * tokensetsize;
@@ -236,7 +236,7 @@ set_conflicts (int state)
 
   /* Loop over all rules which require lookahead in this state.  Check
      for conflicts not resolved above.  */
-  for (i = lookaheads[state]; i < k; i++)
+  for (i = state_table[state].lookaheads; i < k; i++)
     {
       fp1 = LA + i * tokensetsize;
       fp2 = fp1;
@@ -309,10 +309,10 @@ count_sr_conflicts (int state)
       SETBIT (shiftset, symbol);
     }
 
-  k = lookaheads[state + 1];
+  k = state_table[state + 1].lookaheads;
   fp3 = lookaheadset + tokensetsize;
 
-  for (i = lookaheads[state]; i < k; i++)
+  for (i = state_table[state].lookaheads; i < k; i++)
     {
       fp1 = LA + i * tokensetsize;
       fp2 = lookaheadset;
@@ -359,8 +359,8 @@ count_rr_conflicts (int state)
 
   int rrc_count = 0;
 
-  int m = lookaheads[state];
-  int n = lookaheads[state + 1];
+  int m = state_table[state].lookaheads;
+  int n = state_table[state + 1].lookaheads;
 
   if (n - m < 2)
     return 0;
@@ -565,8 +565,8 @@ print_reductions (FILE *out, int state)
 	}
     }
 
-  m = lookaheads[state];
-  n = lookaheads[state + 1];
+  m = state_table[state].lookaheads;
+  n = state_table[state + 1].lookaheads;
 
   if (n - m == 1 && !nodefault)
     {
