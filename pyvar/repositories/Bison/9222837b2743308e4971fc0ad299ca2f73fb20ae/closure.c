@@ -87,18 +87,19 @@ print_firsts (void)
 static void
 print_fderives (void)
 {
-  int i, j;
+  int i;
+  rule_number_t r;
 
   fprintf (stderr, "FDERIVES\n");
   for (i = ntokens; i < nsyms; i++)
     {
       fprintf (stderr, "\t%s derives\n", symbol_tag_get (symbols[i]));
-      for (j = 0; j < nrules + 1; j++)
-	if (bitset_test (FDERIVES (i), j))
+      for (r = 0; r < nrules + 1; r++)
+	if (bitset_test (FDERIVES (i), r))
 	  {
-	    item_number_t *rhsp;
-	    fprintf (stderr, "\t\t%d:", j - 1);
-	    for (rhsp = rules[j].rhs; *rhsp >= 0; ++rhsp)
+	    item_number_t *rhsp = NULL;
+	    fprintf (stderr, "\t\t%d:", r - 1);
+	    for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
 	      fprintf (stderr, " %s", symbol_tag_get (symbols[*rhsp]));
 	    fputc ('\n', stderr);
 	  }
@@ -120,7 +121,7 @@ print_fderives (void)
 static void
 set_firsts (void)
 {
-  int i, j;
+  symbol_number_t i, j;
 
   firsts = bitsetv_create (nvars, nvars, BITSET_FIXED);
 
@@ -155,7 +156,8 @@ set_firsts (void)
 static void
 set_fderives (void)
 {
-  int i, j, k;
+  symbol_number_t i, j;
+  rule_number_t k;
 
   fderives = bitsetv_create (nvars, nrules + 1, BITSET_FIXED);
 
@@ -194,7 +196,7 @@ closure (item_number_t *core, int n)
   int c;
 
   /* A bit index over RULESET. */
-  int ruleno;
+  rule_number_t ruleno;
 
   if (trace_flag)
     print_closure ("input", core, n);
