@@ -567,6 +567,7 @@ print_reductions (FILE *out, int state)
   else if (n - m >= 1)
     {
       unsigned *fp1, *fp2, *fp3, *fp4;
+      int k;
 
       cmax = 0;
       default_LA = -1;
@@ -575,28 +576,13 @@ print_reductions (FILE *out, int state)
       if (!nodefault)
 	for (i = m; i < n; i++)
 	  {
-	    fp1 = LA (i);
-	    fp2 = shiftset;
-	    fp3 = lookaheadset;
-
-	    while (fp3 < fp4)
-	      *fp3++ = *fp1++ & (~(*fp2++));
+	    for (k = 0; k < tokensetsize; ++k)
+	      lookaheadset[k] = LA (i)[k] & ~shiftset[k];
 
 	    count = 0;
-	    mask = 1;
-	    fp3 = lookaheadset;
 	    for (j = 0; j < ntokens; j++)
-	      {
-		if (mask & *fp3)
-		  count++;
-
-		mask <<= 1;
-		if (mask == 0)
-		  {
-		    mask = 1;
-		    fp3++;
-		  }
-	      }
+	      if (BITISSET (lookaheadset, j))
+		count++;
 
 	    if (count > cmax)
 	      {
@@ -616,17 +602,15 @@ print_reductions (FILE *out, int state)
 	shiftset[i] = 0;
 
       if (shiftp)
-	{
-	  for (i = 0; i < shiftp->nshifts; i++)
-	    {
-	      if (!shiftp->shifts[i])
-		continue;
-	      symbol = state_table[shiftp->shifts[i]].accessing_symbol;
-	      if (ISVAR (symbol))
-		break;
-	      SETBIT (shiftset, symbol);
-	    }
-	}
+	for (i = 0; i < shiftp->nshifts; i++)
+	  {
+	    if (!shiftp->shifts[i])
+	      continue;
+	    symbol = state_table[shiftp->shifts[i]].accessing_symbol;
+	    if (ISVAR (symbol))
+	      break;
+	    SETBIT (shiftset, symbol);
+	  }
 
       mask = 1;
       fp1 = LA (m);
