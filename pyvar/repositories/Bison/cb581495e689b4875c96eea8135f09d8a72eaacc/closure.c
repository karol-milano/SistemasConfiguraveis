@@ -220,7 +220,7 @@ closure (short *core, int n)
 
   nitemset = 0;
   c = 0;
-  for (ruleno = 0; ruleno < rulesetsize * BITS_PER_WORD; ++ruleno)
+  for (ruleno = 0; ruleno < nrules + 1; ++ruleno)
     if (BITISSET (ruleset, ruleno))
       {
 	int itemno = rule_table[ruleno].rhs;
