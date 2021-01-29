@@ -130,7 +130,7 @@ set_firsts (void)
       sp = derives[i];
       while (*sp >= 0)
 	{
-	  symbol = ritem[rrhs[*sp++]];
+	  symbol = ritem[rule_table[*sp++].rhs];
 	  if (ISVAR (symbol))
 	    {
 	      symbol -= ntokens;
@@ -287,7 +287,7 @@ closure (short *core, int n)
 	    {
 	      if (word & (1 << b))
 		{
-		  itemno = rrhs[ruleno];
+		  itemno = rule_table[ruleno].rhs;
 		  while (csp < csend && *csp < itemno)
 		    *itemsetend++ = *csp++;
 		  *itemsetend++ = itemno;
