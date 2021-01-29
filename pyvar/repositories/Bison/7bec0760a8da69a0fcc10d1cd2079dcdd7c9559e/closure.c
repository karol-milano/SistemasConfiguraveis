@@ -229,50 +229,37 @@ void
 closure (short *core, int n)
 {
   int ruleno;
-  unsigned word;
   short *csp;
-  unsigned *dsp;
-  unsigned *rsp;
 
-  short *csend;
-  unsigned *rsend;
-  int symbol;
   int itemno;
+  int i;
 
   if (trace_flag)
     {
-      int i;
       fprintf (stderr, "Entering closure (items = {");
       for (i = 0; i < n; ++i)
 	fprintf (stderr, " %d ", core[i]);
       fprintf (stderr, "}, nitems = %d)\n", n);
     }
 
-  rsp = ruleset;
-  rsend = ruleset + rulesetsize;
-  csend = core + n;
-
   if (n == 0)
     {
-      dsp = FDERIVES (start_symbol);
-      while (rsp < rsend)
-	*rsp++ = *dsp++;
+      for (i = 0; i < rulesetsize; ++i)
+	ruleset[i] = FDERIVES (start_symbol)[i];
     }
   else
     {
-      while (rsp < rsend)
-	*rsp++ = 0;
+      for (i = 0; i < rulesetsize; ++i)
+	ruleset[i] = 0;
 
-      csp = core;
-      while (csp < csend)
+      for (i = 0; i < n; ++i)
 	{
-	  symbol = ritem[*csp++];
+	  int symbol = ritem[core[i]];
 	  if (ISVAR (symbol))
 	    {
-	      dsp = FDERIVES (symbol);
-	      rsp = ruleset;
-	      while (rsp < rsend)
-		*rsp++ |= *dsp++;
+	      int j;
+	      for (j = 0; j < rulesetsize; ++j)
+		ruleset[j] |= FDERIVES (symbol)[j];
 	    }
 	}
     }
@@ -280,10 +267,9 @@ closure (short *core, int n)
   ruleno = 0;
   itemsetend = itemset;
   csp = core;
-  rsp = ruleset;
-  while (rsp < rsend)
+  for (i= 0; i < rulesetsize; ++i)
     {
-      word = *rsp++;
+      int word = ruleset[i];
       if (word == 0)
 	{
 	  ruleno += BITS_PER_WORD;
@@ -297,7 +283,7 @@ closure (short *core, int n)
 	      if (word & (1 << b))
 		{
 		  itemno = rule_table[ruleno].rhs;
-		  while (csp < csend && *csp < itemno)
+		  while (csp < (core + n ) && *csp < itemno)
 		    *itemsetend++ = *csp++;
 		  *itemsetend++ = itemno;
 		}
@@ -307,7 +293,7 @@ closure (short *core, int n)
 	}
     }
 
-  while (csp < csend)
+  while (csp < (core + n))
     *itemsetend++ = *csp++;
 
   if (trace_flag)
