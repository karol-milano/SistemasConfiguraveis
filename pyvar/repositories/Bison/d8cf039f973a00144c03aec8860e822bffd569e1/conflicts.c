@@ -182,13 +182,8 @@ resolve_sr_conflict (int state, int lookaheadnum)
 static void
 set_conflicts (int state)
 {
-  int i;
-  int k;
+  int i, j;
   shifts *shiftp;
-  unsigned *fp2;
-  unsigned *fp3;
-  unsigned *fp4;
-  unsigned *fp1;
   int symbol;
 
   if (state_table[state].consistent)
@@ -199,58 +194,41 @@ set_conflicts (int state)
 
   shiftp = state_table[state].shift_table;
   if (shiftp)
-    {
-      k = shiftp->nshifts;
-      for (i = 0; i < k; i++)
-	{
-	  symbol = state_table[shiftp->shifts[i]].accessing_symbol;
-	  if (ISVAR (symbol))
-	    break;
-	  SETBIT (lookaheadset, symbol);
-	}
-    }
-
-  k = state_table[state + 1].lookaheads;
-  fp4 = lookaheadset + tokensetsize;
+    for (i = 0; i < shiftp->nshifts; i++)
+      {
+	symbol = state_table[shiftp->shifts[i]].accessing_symbol;
+	if (ISVAR (symbol))
+	  break;
+	SETBIT (lookaheadset, symbol);
+      }
 
   /* Loop over all rules which require lookahead in this state.  First
      check for shift-reduce conflict, and try to resolve using
      precedence */
-  for (i = state_table[state].lookaheads; i < k; i++)
+  for (i = state_table[state].lookaheads;
+       i < state_table[state + 1].lookaheads;
+       ++i)
     if (rule_table[LAruleno[i]].prec)
-      {
-	fp1 = LA (i);
-	fp2 = fp1;
-	fp3 = lookaheadset;
-
-	while (fp3 < fp4)
+      for (j = 0; j < tokensetsize; ++j)
+	if (LA (i)[j] & lookaheadset[j])
 	  {
-	    if (*fp2++ & *fp3++)
-	      {
-		resolve_sr_conflict (state, i);
-		break;
-	      }
+	    resolve_sr_conflict (state, i);
+	    break;
 	  }
-      }
 
 
   /* Loop over all rules which require lookahead in this state.  Check
      for conflicts not resolved above.  */
-  for (i = state_table[state].lookaheads; i < k; i++)
+  for (i = state_table[state].lookaheads;
+       i < state_table[state + 1].lookaheads;
+       ++i)
     {
-      fp1 = LA (i);
-      fp2 = fp1;
-      fp3 = lookaheadset;
-
-      while (fp3 < fp4)
-	if (*fp2++ & *fp3++)
+      for (j = 0; j < tokensetsize; ++j)
+	if (LA (i)[j] & lookaheadset[j])
 	  conflicts[state] = 1;
 
-      fp2 = fp1;
-      fp3 = lookaheadset;
-
-      while (fp3 < fp4)
-	*fp3++ |= *fp2++;
+      for (j = 0; j < tokensetsize; ++j)
+	lookaheadset[j] |= LA (i)[j];
     }
 }
 
