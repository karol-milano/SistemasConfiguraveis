@@ -34,6 +34,9 @@ static unsigned *ruleset;
 static unsigned *fderives;
 static unsigned *firsts;
 
+#define FDERIVES(Symbol)   (fderives + (Symbol) * rulesetsize)
+#define   FIRSTS(Symbol)   (firsts   + (Symbol) * varsetsize)
+
 /* number of words required to hold a bit for each rule */
 static int rulesetsize;
 
@@ -50,9 +53,10 @@ print_closure (int n)
 {
   short *isp;
 
-  fprintf (stderr, "\n\nn = %d\n\n", n);
+  fprintf (stderr, "n = %d\n", n);
   for (isp = itemset; isp < itemsetend; isp++)
     fprintf (stderr, "   %d\n", *isp);
+  fprintf (stderr, "\n\n");
 }
 
 
@@ -63,18 +67,19 @@ print_firsts (void)
   int j;
   unsigned *rowp;
 
-  fprintf (stderr, "\n\n\nFIRSTS\n\n");
+  fprintf (stderr, "FIRSTS\n");
 
   for (i = ntokens; i < nsyms; i++)
     {
-      fprintf (stderr, "\n\n%s firsts\n\n", tags[i]);
+      fprintf (stderr, "\t%s firsts\n", tags[i]);
 
-      rowp = firsts + ((i - ntokens) * varsetsize);
+      rowp = FIRSTS (i - ntokens);
 
       for (j = 0; j < nvars; j++)
 	if (BITISSET (rowp, j))
-	  fprintf (stderr, "   %s\n", tags[j + ntokens]);
+	  fprintf (stderr, "\t\t%d (%s)\n", j + ntokens, tags[j + ntokens]);
     }
+  fprintf (stderr, "\n\n");
 }
 
 
@@ -85,17 +90,18 @@ print_fderives (void)
   int j;
   unsigned *rp;
 
-  fprintf (stderr, "\n\n\nFDERIVES\n");
+  fprintf (stderr, "FDERIVES\n");
 
   for (i = ntokens; i < nsyms; i++)
     {
-      fprintf (stderr, "\n\n%s derives\n\n", tags[i]);
-      rp = fderives + i * rulesetsize;
+      fprintf (stderr, "\t%s derives\n", tags[i]);
+      rp = FDERIVES (i);
 
       for (j = 0; j <= nrules; j++)
 	if (BITISSET (rp, j))
-	  fprintf (stderr, "   %d\n", j);
+	  fprintf (stderr, "\t\t%d (%s)\n", j, tags[j]);
     }
+  fprintf (stderr, "\n\n");
 }
 
 /*-------------------------------------------------------------------.
@@ -172,11 +178,11 @@ set_fderives (void)
 
   set_firsts ();
 
-  rrow = fderives + ntokens * rulesetsize;
+  rrow = FDERIVES (ntokens);
 
   for (i = ntokens; i < nsyms; i++)
     {
-      vrow = firsts + ((i - ntokens) * varsetsize);
+      vrow = FIRSTS (i - ntokens);
       cword = *vrow++;
       b = 0;
       for (j = ntokens; j < nsyms; j++)
@@ -185,9 +191,7 @@ set_fderives (void)
 	    {
 	      rp = derives[j];
 	      while ((ruleno = *rp++) > 0)
-		{
-		  SETBIT (rrow, ruleno);
-		}
+		SETBIT (rrow, ruleno);
 	    }
 
 	  b++;
@@ -235,13 +239,22 @@ closure (short *core, int n)
   int symbol;
   int itemno;
 
+  if (trace_flag)
+    {
+      int i;
+      fprintf (stderr, "Entering closure (items = {");
+      for (i = 0; i < n; ++i)
+	fprintf (stderr, " %d ", core[i]);
+      fprintf (stderr, "}, nitems = %d)\n", n);
+    }
+
   rsp = ruleset;
   rsend = ruleset + rulesetsize;
   csend = core + n;
 
   if (n == 0)
     {
-      dsp = fderives + start_symbol * rulesetsize;
+      dsp = FDERIVES (start_symbol);
       while (rsp < rsend)
 	*rsp++ = *dsp++;
     }
@@ -256,7 +269,7 @@ closure (short *core, int n)
 	  symbol = ritem[*csp++];
 	  if (ISVAR (symbol))
 	    {
-	      dsp = fderives + symbol * rulesetsize;
+	      dsp = FDERIVES (symbol);
 	      rsp = ruleset;
 	      while (rsp < rsend)
 		*rsp++ |= *dsp++;
