@@ -242,7 +242,8 @@ closure (short *core, int n)
   /* Index over RULESET. */
   int r;
 
-  int itemno;
+  /* A bit index over RULESET. */
+  int b;
 
   if (trace_flag)
     {
@@ -271,27 +272,22 @@ closure (short *core, int n)
   ruleno = 0;
   itemsetsize = 0;
   c = 0;
-  for (r = 0; r < rulesetsize; ++r)
+  for (b = 0; b < rulesetsize * BITS_PER_WORD; ++b)
     {
-      int b;
-
-      for (b = 0; b < BITS_PER_WORD; b++)
+      if (BITISSET (ruleset, b))
 	{
-	  if (ruleset[r] & (1 << b))
+	  int itemno = rule_table[ruleno].rhs;
+	  while (c < n && core[c] < itemno)
 	    {
-	      itemno = rule_table[ruleno].rhs;
-	      while (c < n && core[c] < itemno)
-		{
-		  itemset[itemsetsize] = core[c];
-		  itemsetsize++;
-		  c++;
-		}
-	      itemset[itemsetsize] = itemno;
+	      itemset[itemsetsize] = core[c];
 	      itemsetsize++;
+	      c++;
 	    }
-
-	  ruleno++;
+	  itemset[itemsetsize] = itemno;
+	  itemsetsize++;
 	}
+
+      ruleno++;
     }
 
   while (c < n)
