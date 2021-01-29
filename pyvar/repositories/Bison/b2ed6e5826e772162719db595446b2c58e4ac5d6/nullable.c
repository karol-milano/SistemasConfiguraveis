@@ -69,7 +69,7 @@ set_nullable (void)
     {
       if (*r < 0)
 	{
-	  symbol = rlhs[-(*r++)];
+	  symbol = rule_table[-(*r++)].lhs;
 	  if (symbol >= 0 && !nullable[symbol])
 	    {
 	      nullable[symbol] = 1;
@@ -111,7 +111,7 @@ set_nullable (void)
 	  p = p->next;
 	  if (--rcount[ruleno] == 0)
 	    {
-	      symbol = rlhs[ruleno];
+	      symbol = rule_table[ruleno].lhs;
 	      if (symbol >= 0 && !nullable[symbol])
 		{
 		  nullable[symbol] = 1;
