@@ -235,7 +235,6 @@ new_closure (int n)
 void
 closure (short *core, int n)
 {
-  int ruleno;
   /* Index over CORE. */
   int c;
 
@@ -243,7 +242,7 @@ closure (short *core, int n)
   int r;
 
   /* A bit index over RULESET. */
-  int b;
+  int ruleno;
 
   if (trace_flag)
     {
@@ -269,26 +268,21 @@ closure (short *core, int n)
 	    ruleset[r] |= FDERIVES (ritem[core[c]])[r];
     }
 
-  ruleno = 0;
   itemsetsize = 0;
   c = 0;
-  for (b = 0; b < rulesetsize * BITS_PER_WORD; ++b)
-    {
-      if (BITISSET (ruleset, b))
-	{
-	  int itemno = rule_table[ruleno].rhs;
-	  while (c < n && core[c] < itemno)
-	    {
-	      itemset[itemsetsize] = core[c];
-	      itemsetsize++;
-	      c++;
-	    }
-	  itemset[itemsetsize] = itemno;
-	  itemsetsize++;
-	}
-
-      ruleno++;
-    }
+  for (ruleno = 0; ruleno < rulesetsize * BITS_PER_WORD; ++ruleno)
+    if (BITISSET (ruleset, ruleno))
+      {
+	int itemno = rule_table[ruleno].rhs;
+	while (c < n && core[c] < itemno)
+	  {
+	    itemset[itemsetsize] = core[c];
+	    itemsetsize++;
+	    c++;
+	  }
+	itemset[itemsetsize] = itemno;
+	itemsetsize++;
+      }
 
   while (c < n)
     {
