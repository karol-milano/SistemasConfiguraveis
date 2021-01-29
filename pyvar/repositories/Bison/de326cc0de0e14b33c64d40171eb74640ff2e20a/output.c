@@ -428,7 +428,7 @@ action_row (int state)
 
   if (nreds >= 1 && !nodefault)
     {
-      if (consistent[state])
+      if (state_table[state].consistent)
 	default_rule = redp->rules[0];
       else
 	{
