@@ -255,18 +255,10 @@ solve_conflicts (void)
 static int
 count_sr_conflicts (int state)
 {
-  int i;
-  int k;
-  int mask;
-  shifts *shiftp;
-  unsigned *fp1;
-  unsigned *fp2;
-  unsigned *fp3;
-  int symbol;
-
+  int i, k;
   int src_count = 0;
+  shifts *shiftp = state_table[state].shift_table;
 
-  shiftp = state_table[state].shift_table;
   if (!shiftp)
     return 0;
 
@@ -276,49 +268,24 @@ count_sr_conflicts (int state)
       lookaheadset[i] = 0;
     }
 
-  k = shiftp->nshifts;
-  for (i = 0; i < k; i++)
+  for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     {
-      if (!shiftp->shifts[i])
-	continue;
-      symbol = state_table[shiftp->shifts[i]].accessing_symbol;
-      if (ISVAR (symbol))
-	break;
+      int symbol = state_table[shiftp->shifts[i]].accessing_symbol;
       SETBIT (shiftset, symbol);
     }
 
-  k = state_table[state + 1].lookaheads;
-  fp3 = lookaheadset + tokensetsize;
-
-  for (i = state_table[state].lookaheads; i < k; i++)
-    {
-      fp1 = LA (i);
-      fp2 = lookaheadset;
-
-      while (fp2 < fp3)
-	*fp2++ |= *fp1++;
-    }
-
-  fp1 = shiftset;
-  fp2 = lookaheadset;
+  for (i = state_table[state].lookaheads;
+       i < state_table[state + 1].lookaheads;
+       ++i)
+    for (k = 0; k < tokensetsize; ++k)
+      lookaheadset[k] |= LA (i)[k];
 
-  while (fp2 < fp3)
-    *fp2++ &= *fp1++;
+  for (k = 0; k < tokensetsize; ++k)
+    lookaheadset[k] &= shiftset[k];
 
-  mask = 1;
-  fp2 = lookaheadset;
   for (i = 0; i < ntokens; i++)
-    {
-      if (mask & *fp2)
-	src_count++;
-
-      mask <<= 1;
-      if (mask == 0)
-	{
-	  mask = 1;
-	  fp2++;
-	}
-    }
+    if (BITISSET (lookaheadset, i))
+      src_count++;
 
   return src_count;
 }
@@ -332,9 +299,6 @@ static int
 count_rr_conflicts (int state)
 {
   int i;
-  unsigned mask;
-  unsigned *baseword;
-
   int rrc_count = 0;
 
   int m = state_table[state].lookaheads;
@@ -343,31 +307,16 @@ count_rr_conflicts (int state)
   if (n - m < 2)
     return 0;
 
-  mask = 1;
-  baseword = LA (m);
   for (i = 0; i < ntokens; i++)
     {
-      unsigned *wordp = baseword;
-
       int count = 0;
       int j;
       for (j = m; j < n; j++)
-	{
-	  if (mask & *wordp)
-	    count++;
-
-	  wordp += tokensetsize;
-	}
+	if (BITISSET (LA (m), j))
+	  count++;
 
       if (count >= 2)
 	rrc_count++;
-
-      mask <<= 1;
-      if (mask == 0)
-	{
-	  mask = 1;
-	  baseword++;
-	}
     }
 
   return rrc_count;
@@ -505,9 +454,6 @@ print_reductions (FILE *out, int state)
   int symbol;
   int m;
   int n;
-  int default_LA;
-  int default_rule = 0;
-  int cmax;
   shifts *shiftp;
   errs *errp;
   int nodefault = 0;
@@ -543,7 +489,7 @@ print_reductions (FILE *out, int state)
   if (n - m == 1 && !nodefault)
     {
       int k;
-      default_rule = LAruleno[m];
+      int default_rule = LAruleno[m];
 
       for (k = 0; k < tokensetsize; ++k)
 	lookaheadset[k] = LA (m)[k] & shiftset[k];
@@ -561,8 +507,9 @@ print_reductions (FILE *out, int state)
     {
       int k;
 
-      cmax = 0;
-      default_LA = -1;
+      int cmax = 0;
+      int default_LA = -1;
+      int default_rule = 0;
 
       if (!nodefault)
 	for (i = m; i < n; i++)
