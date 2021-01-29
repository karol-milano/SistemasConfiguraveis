@@ -273,31 +273,24 @@ closure (short *core, int n)
   c = 0;
   for (r = 0; r < rulesetsize; ++r)
     {
-      if (ruleset[r] == 0)
-	{
-	  ruleno += BITS_PER_WORD;
-	}
-      else
-	{
-	  int b;
+      int b;
 
-	  for (b = 0; b < BITS_PER_WORD; b++)
+      for (b = 0; b < BITS_PER_WORD; b++)
+	{
+	  if (ruleset[r] & (1 << b))
 	    {
-	      if (ruleset[r] & (1 << b))
+	      itemno = rule_table[ruleno].rhs;
+	      while (c < n && core[c] < itemno)
 		{
-		  itemno = rule_table[ruleno].rhs;
-		  while (c < n && core[c] < itemno)
-		    {
-		      itemset[itemsetsize] = core[c];
-		      itemsetsize++;
-		      c++;
-		    }
-		  itemset[itemsetsize] = itemno;
+		  itemset[itemsetsize] = core[c];
 		  itemsetsize++;
+		  c++;
 		}
-
-	      ruleno++;
+	      itemset[itemsetsize] = itemno;
+	      itemsetsize++;
 	    }
+
+	  ruleno++;
 	}
     }
 
