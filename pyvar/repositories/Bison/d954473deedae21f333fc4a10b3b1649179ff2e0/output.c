@@ -399,40 +399,33 @@ action_row (int state)
 	}
     }
 
-  shiftp = state_table[state].shift_table;
-
   /* Now see which tokens are allowed for shifts in this state.  For
      them, record the shift as the thing to do.  So shift is preferred
      to reduce.  */
+  shiftp = state_table[state].shift_table;
 
-  if (shiftp)
+  for (i = 0; i < shiftp->nshifts; i++)
     {
-      k = shiftp->nshifts;
-
-      for (i = 0; i < k; i++)
-	{
-	  shift_state = shiftp->shifts[i];
-	  if (!shift_state)
-	    continue;
+      shift_state = shiftp->shifts[i];
+      if (!shift_state)
+	continue;
 
-	  symbol = state_table[shift_state].accessing_symbol;
+      symbol = state_table[shift_state].accessing_symbol;
 
-	  if (ISVAR (symbol))
-	    break;
+      if (ISVAR (symbol))
+	break;
 
-	  actrow[symbol] = shift_state;
+      actrow[symbol] = shift_state;
 
-	  /* Do not use any default reduction if there is a shift for
-	     error */
-	  if (symbol == error_token_number)
-	    nodefault = 1;
-	}
+      /* Do not use any default reduction if there is a shift for
+	 error */
+      if (symbol == error_token_number)
+	nodefault = 1;
     }
 
-  errp = err_table[state];
-
   /* See which tokens are an explicit error in this state (due to
      %nonassoc).  For them, record MINSHORT as the action.  */
+  errp = err_table[state];
 
   if (errp)
     {
