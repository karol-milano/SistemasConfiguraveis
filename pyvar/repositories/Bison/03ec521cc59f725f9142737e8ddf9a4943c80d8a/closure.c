@@ -36,8 +36,9 @@ static unsigned *ruleset;
 static unsigned *fderives;
 static unsigned *firsts;
 
-#define FDERIVES(Symbol)   (fderives + (Symbol) * rulesetsize)
-#define   FIRSTS(Symbol)   (firsts   + (Symbol) * varsetsize)
+/* Retrieve the FDERIVES/FIRSTS sets of the nonterminals numbered Var.  */
+#define FDERIVES(Var)   (fderives + ((Var) - ntokens) * rulesetsize)
+#define   FIRSTS(Var)   (firsts   + ((Var) - ntokens) * varsetsize)
 
 /* number of words required to hold a bit for each rule */
 static int rulesetsize;
@@ -71,7 +72,7 @@ print_firsts (void)
     {
       fprintf (stderr, "\t%s firsts\n", tags[i]);
       for (j = 0; j < nvars; j++)
-	if (BITISSET (FIRSTS (i - ntokens), j))
+	if (BITISSET (FIRSTS (i), j))
 	  fprintf (stderr, "\t\t%d (%s)\n", j + ntokens, tags[j + ntokens]);
     }
   fprintf (stderr, "\n\n");
@@ -115,20 +116,18 @@ print_fderives (void)
 static void
 set_firsts (void)
 {
-  int rowsize;
-
   int i, j;
 
-  varsetsize = rowsize = WORDSIZE (nvars);
+  varsetsize = WORDSIZE (nvars);
 
-  firsts = XCALLOC (unsigned, nvars * rowsize);
+  firsts = XCALLOC (unsigned, nvars * varsetsize);
 
   for (i = ntokens; i < nsyms; i++)
     for (j = 0; derives[i][j] >= 0; ++j)
       {
 	int symbol = ritem[rule_table[derives[i][j]].rhs];
 	if (ISVAR (symbol))
-	  SETBIT (FIRSTS (i - ntokens), symbol - ntokens);
+	  SETBIT (FIRSTS (i), symbol - ntokens);
       }
 
   RTC (firsts, nvars);
@@ -152,13 +151,13 @@ set_fderives (void)
 {
   int i, j, k;
 
-  fderives = XCALLOC (unsigned, nvars * rulesetsize) - ntokens * rulesetsize;
+  fderives = XCALLOC (unsigned, nvars * rulesetsize);
 
   set_firsts ();
 
   for (i = ntokens; i < nsyms; ++i)
     for (j = ntokens; j < nsyms; ++j)
-      if (BITISSET (FIRSTS (i - ntokens), j - ntokens))
+      if (BITISSET (FIRSTS (i), j - ntokens))
 	for (k = 0; derives[j][k] > 0; ++k)
 	  SETBIT (FDERIVES (i), derives[j][k]);
 
@@ -251,5 +250,5 @@ free_closure (void)
 {
   XFREE (itemset);
   XFREE (ruleset);
-  XFREE (fderives + ntokens * rulesetsize);
+  XFREE (fderives);
 }
