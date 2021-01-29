@@ -236,48 +236,44 @@ void
 closure (short *core, int n)
 {
   int ruleno;
-  short *csp;
+  /* Index over CORE. */
+  int c;
+
+  /* Index over RULESET. */
+  int r;
 
   int itemno;
-  int i;
 
   if (trace_flag)
     {
       fprintf (stderr, "Entering closure (items = {");
-      for (i = 0; i < n; ++i)
-	fprintf (stderr, " %d ", core[i]);
-      fprintf (stderr, "}, nitems = %d)\n", n);
+      for (c = 0; c < n; ++c)
+	fprintf (stderr, " %d ", core[c]);
+      fprintf (stderr, "})\n");
     }
 
   if (n == 0)
     {
-      for (i = 0; i < rulesetsize; ++i)
-	ruleset[i] = FDERIVES (start_symbol)[i];
+      for (r = 0; r < rulesetsize; ++r)
+	ruleset[r] = FDERIVES (start_symbol)[r];
     }
   else
     {
-      for (i = 0; i < rulesetsize; ++i)
-	ruleset[i] = 0;
+      for (r = 0; r < rulesetsize; ++r)
+	ruleset[r] = 0;
 
-      for (i = 0; i < n; ++i)
-	{
-	  int symbol = ritem[core[i]];
-	  if (ISVAR (symbol))
-	    {
-	      int j;
-	      for (j = 0; j < rulesetsize; ++j)
-		ruleset[j] |= FDERIVES (symbol)[j];
-	    }
-	}
+      for (c = 0; c < n; ++c)
+	if (ISVAR (ritem[core[c]]))
+	  for (r = 0; r < rulesetsize; ++r)
+	    ruleset[r] |= FDERIVES (ritem[core[c]])[r];
     }
 
   ruleno = 0;
   itemsetsize = 0;
-  csp = core;
-  for (i = 0; i < rulesetsize; ++i)
+  c = 0;
+  for (r = 0; r < rulesetsize; ++r)
     {
-      int word = ruleset[i];
-      if (word == 0)
+      if (ruleset[r] == 0)
 	{
 	  ruleno += BITS_PER_WORD;
 	}
@@ -287,12 +283,17 @@ closure (short *core, int n)
 
 	  for (b = 0; b < BITS_PER_WORD; b++)
 	    {
-	      if (word & (1 << b))
+	      if (ruleset[r] & (1 << b))
 		{
 		  itemno = rule_table[ruleno].rhs;
-		  while (csp < (core + n) && *csp < itemno)
-		    itemset[itemsetsize++] = *csp++;
-		  itemset[itemsetsize++] = itemno;
+		  while (c < n && core[c] < itemno)
+		    {
+		      itemset[itemsetsize] = core[c];
+		      itemsetsize++;
+		      c++;
+		    }
+		  itemset[itemsetsize] = itemno;
+		  itemsetsize++;
 		}
 
 	      ruleno++;
@@ -300,8 +301,12 @@ closure (short *core, int n)
 	}
     }
 
-  while (csp < (core + n))
-    itemset[itemsetsize++] = *csp++;
+  while (c < n)
+    {
+      itemset[itemsetsize] = core[c];
+      itemsetsize++;
+      c++;
+    }
 
   if (trace_flag)
     print_closure (n);
