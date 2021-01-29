@@ -68,7 +68,7 @@ flush_shift (int state, int token)
       for (i = 0; i < k; i++)
 	{
 	  if (shiftp->shifts[i]
-	      && token == accessing_symbol[shiftp->shifts[i]])
+	      && token == state_table[shiftp->shifts[i]].accessing_symbol)
 	    (shiftp->shifts[i]) = 0;
 	}
     }
@@ -203,7 +203,7 @@ set_conflicts (int state)
       k = shiftp->nshifts;
       for (i = 0; i < k; i++)
 	{
-	  symbol = accessing_symbol[shiftp->shifts[i]];
+	  symbol = state_table[shiftp->shifts[i]].accessing_symbol;
 	  if (ISVAR (symbol))
 	    break;
 	  SETBIT (lookaheadset, symbol);
@@ -303,7 +303,7 @@ count_sr_conflicts (int state)
     {
       if (!shiftp->shifts[i])
 	continue;
-      symbol = accessing_symbol[shiftp->shifts[i]];
+      symbol = state_table[shiftp->shifts[i]].accessing_symbol;
       if (ISVAR (symbol))
 	break;
       SETBIT (shiftset, symbol);
@@ -541,7 +541,7 @@ print_reductions (FILE *out, int state)
 	{
 	  if (!shiftp->shifts[i])
 	    continue;
-	  symbol = accessing_symbol[shiftp->shifts[i]];
+	  symbol = state_table[shiftp->shifts[i]].accessing_symbol;
 	  if (ISVAR (symbol))
 	    break;
 	  /* if this state has a shift for the error token,
@@ -656,7 +656,7 @@ print_reductions (FILE *out, int state)
 	    {
 	      if (!shiftp->shifts[i])
 		continue;
-	      symbol = accessing_symbol[shiftp->shifts[i]];
+	      symbol = state_table[shiftp->shifts[i]].accessing_symbol;
 	      if (ISVAR (symbol))
 		break;
 	      SETBIT (shiftset, symbol);
