@@ -341,15 +341,11 @@ action_row (int state)
   int k;
   int m = 0;
   int n = 0;
-  int count;
   int default_rule;
   int nreds;
-  int max;
   int rule;
   int shift_state;
   int symbol;
-  unsigned mask;
-  unsigned *wordp;
   reductions *redp;
   shifts *shiftp;
   errs *errp;
@@ -374,28 +370,13 @@ action_row (int state)
 	  n = state_table[state + 1].lookaheads;
 
 	  for (i = n - 1; i >= m; i--)
-	    {
-	      rule = -LAruleno[i];
-	      wordp = LA (i);
-	      mask = 1;
-
-	      /* and find each token which the rule finds acceptable
-	         to come next */
-	      for (j = 0; j < ntokens; j++)
-		{
-		  /* and record this rule as the rule to use if that
-		     token follows.  */
-		  if (mask & *wordp)
-		    actrow[j] = rule;
-
-		  mask <<= 1;
-		  if (mask == 0)
-		    {
-		      mask = 1;
-		      wordp++;
-		    }
-		}
-	    }
+	    /* and find each token which the rule finds acceptable
+	       to come next */
+	    for (j = 0; j < ntokens; j++)
+	      /* and record this rule as the rule to use if that
+		 token follows.  */
+	      if (BITISSET (LA (i), j))
+		actrow[j] = -LAruleno[i];
 	}
     }
 
@@ -403,7 +384,6 @@ action_row (int state)
      them, record the shift as the thing to do.  So shift is preferred
      to reduce.  */
   shiftp = state_table[state].shift_table;
-
   for (i = 0; i < shiftp->nshifts; i++)
     {
       shift_state = shiftp->shifts[i];
@@ -447,10 +427,10 @@ action_row (int state)
 	default_rule = redp->rules[0];
       else
 	{
-	  max = 0;
+	  int max = 0;
 	  for (i = m; i < n; i++)
 	    {
-	      count = 0;
+	      int count = 0;
 	      rule = -LAruleno[i];
 
 	      for (j = 0; j < ntokens; j++)
