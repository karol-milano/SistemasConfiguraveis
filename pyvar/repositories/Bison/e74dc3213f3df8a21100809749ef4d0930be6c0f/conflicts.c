@@ -503,13 +503,11 @@ print_reductions (FILE *out, int state)
   int i;
   int j;
   int symbol;
-  unsigned mask;
   int m;
   int n;
   int default_LA;
   int default_rule = 0;
   int cmax;
-  int count;
   shifts *shiftp;
   errs *errp;
   int nodefault = 0;
@@ -535,14 +533,9 @@ print_reductions (FILE *out, int state)
 
   errp = err_table[state];
   if (errp)
-    {
-      for (i = 0; i < errp->nerrs; i++)
-	{
-	  if (!errp->errs[i])
-	    continue;
-	  SETBIT (shiftset, errp->errs[i]);
-	}
-    }
+    for (i = 0; i < errp->nerrs; i++)
+      if (errp->errs[i])
+	SETBIT (shiftset, errp->errs[i]);
 
   m = state_table[state].lookaheads;
   n = state_table[state + 1].lookaheads;
@@ -566,20 +559,19 @@ print_reductions (FILE *out, int state)
     }
   else if (n - m >= 1)
     {
-      unsigned *fp1, *fp2, *fp3, *fp4;
       int k;
 
       cmax = 0;
       default_LA = -1;
-      fp4 = lookaheadset + tokensetsize;
 
       if (!nodefault)
 	for (i = m; i < n; i++)
 	  {
+	    int count = 0;
+
 	    for (k = 0; k < tokensetsize; ++k)
 	      lookaheadset[k] = LA (i)[k] & ~shiftset[k];
 
-	    count = 0;
 	    for (j = 0; j < ntokens; j++)
 	      if (BITISSET (lookaheadset, j))
 		count++;
@@ -591,11 +583,8 @@ print_reductions (FILE *out, int state)
 		default_rule = LAruleno[i];
 	      }
 
-	    fp2 = shiftset;
-	    fp3 = lookaheadset;
-
-	    while (fp3 < fp4)
-	      *fp2++ |= *fp3++;
+	    for (k = 0; k < tokensetsize; ++k)
+	      shiftset[k] |= lookaheadset[k];
 	  }
 
       for (i = 0; i < tokensetsize; i++)
@@ -612,22 +601,14 @@ print_reductions (FILE *out, int state)
 	    SETBIT (shiftset, symbol);
 	  }
 
-      mask = 1;
-      fp1 = LA (m);
-      fp2 = shiftset;
       for (i = 0; i < ntokens; i++)
 	{
 	  int defaulted = 0;
+	  int count = BITISSET (shiftset, i);
 
-	  if (mask & *fp2)
-	    count = 1;
-	  else
-	    count = 0;
-
-	  fp3 = fp1;
 	  for (j = m; j < n; j++)
 	    {
-	      if (mask & *fp3)
+	      if (BITISSET (LA (m), j))
 		{
 		  if (count == 0)
 		    {
@@ -658,18 +639,6 @@ print_reductions (FILE *out, int state)
 			       tags[rule_table[LAruleno[j]].lhs]);
 		    }
 		}
-
-	      fp3 += tokensetsize;
-	    }
-
-	  mask <<= 1;
-	  if (mask == 0)
-	    {
-	      mask = 1;
-	      /* We tried incrementing just fp1, and just fp2; both seem wrong.
-	         It seems necessary to increment both in sync.  */
-	      fp1++;
-	      fp2++;
 	    }
 	}
 
