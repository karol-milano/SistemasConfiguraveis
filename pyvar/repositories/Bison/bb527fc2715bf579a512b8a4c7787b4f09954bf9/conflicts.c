@@ -97,7 +97,7 @@ resolve_sr_conflict (int state, int lookaheadnum)
   redprec = rprec[LAruleno[lookaheadnum]];
 
   mask = 1;
-  fp1 = LA + lookaheadnum * tokensetsize;
+  fp1 = LA (lookaheadnum);
   fp2 = lookaheadset;
   for (i = 0; i < ntokens; i++)
     {
@@ -219,7 +219,7 @@ set_conflicts (int state)
   for (i = state_table[state].lookaheads; i < k; i++)
     if (rprec[LAruleno[i]])
       {
-	fp1 = LA + i * tokensetsize;
+	fp1 = LA (i);
 	fp2 = fp1;
 	fp3 = lookaheadset;
 
@@ -238,7 +238,7 @@ set_conflicts (int state)
      for conflicts not resolved above.  */
   for (i = state_table[state].lookaheads; i < k; i++)
     {
-      fp1 = LA + i * tokensetsize;
+      fp1 = LA (i);
       fp2 = fp1;
       fp3 = lookaheadset;
 
@@ -314,7 +314,7 @@ count_sr_conflicts (int state)
 
   for (i = state_table[state].lookaheads; i < k; i++)
     {
-      fp1 = LA + i * tokensetsize;
+      fp1 = LA (i);
       fp2 = lookaheadset;
 
       while (fp2 < fp3)
@@ -366,7 +366,7 @@ count_rr_conflicts (int state)
     return 0;
 
   mask = 1;
-  baseword = LA + m * tokensetsize;
+  baseword = LA (m);
   for (i = 0; i < ntokens; i++)
     {
       unsigned *wordp = baseword;
@@ -572,7 +572,7 @@ print_reductions (FILE *out, int state)
     {
       default_rule = LAruleno[m];
 
-      fp1 = LA + m * tokensetsize;
+      fp1 = LA (m);
       fp2 = shiftset;
       fp3 = lookaheadset;
       fp4 = lookaheadset + tokensetsize;
@@ -609,7 +609,7 @@ print_reductions (FILE *out, int state)
       if (!nodefault)
 	for (i = m; i < n; i++)
 	  {
-	    fp1 = LA + i * tokensetsize;
+	    fp1 = LA (i);
 	    fp2 = shiftset;
 	    fp3 = lookaheadset;
 
@@ -664,7 +664,7 @@ print_reductions (FILE *out, int state)
 	}
 
       mask = 1;
-      fp1 = LA + m * tokensetsize;
+      fp1 = LA (m);
       fp2 = shiftset;
       for (i = 0; i < ntokens; i++)
 	{
