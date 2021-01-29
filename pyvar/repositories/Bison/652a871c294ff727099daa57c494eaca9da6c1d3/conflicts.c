@@ -94,7 +94,7 @@ resolve_sr_conflict (int state, int lookaheadnum)
   short *errtokens = errp->errs;
 
   /* find the rule to reduce by to get precedence of reduction  */
-  redprec = rprec[LAruleno[lookaheadnum]];
+  redprec = rule_table[LAruleno[lookaheadnum]].prec;
 
   mask = 1;
   fp1 = LA (lookaheadnum);
@@ -217,7 +217,7 @@ set_conflicts (int state)
      check for shift-reduce conflict, and try to resolve using
      precedence */
   for (i = state_table[state].lookaheads; i < k; i++)
-    if (rprec[LAruleno[i]])
+    if (rule_table[LAruleno[i]].prec)
       {
 	fp1 = LA (i);
 	fp2 = fp1;
