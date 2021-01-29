@@ -74,7 +74,7 @@ set_derives (void)
   p = delts;
   for (i = nrules; i > 0; i--)
     {
-      lhs = rlhs[i];
+      lhs = rule_table[i].lhs;
       if (lhs >= 0)
 	{
 	  p->next = dset[lhs];
