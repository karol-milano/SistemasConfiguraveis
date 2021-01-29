@@ -111,7 +111,7 @@ useless_nonterminals (void)
   while (1)
     {
       bitset_copy (Np, N);
-      for (r = 1; r < nrules + 1; r++)
+      for (r = 0; r < nrules; r++)
 	if (!bitset_test (P, r)
 	    && useful_production (r, N))
 	  {
@@ -158,7 +158,7 @@ inaccessable_symbols (void)
      user can know.  */
 
   Vp = bitset_create (nsyms, BITSET_FIXED);
-  Pp = bitset_create (nrules + 1, BITSET_FIXED);
+  Pp = bitset_create (nrules, BITSET_FIXED);
 
   /* If the start symbol isn't useful, then nothing will be useful. */
   if (bitset_test (N, axiom->number - ntokens))
@@ -169,7 +169,7 @@ inaccessable_symbols (void)
 	{
 	  rule_number_t r;
 	  bitset_copy (Vp, V);
-	  for (r = 1; r < nrules + 1; r++)
+	  for (r = 0; r < nrules; r++)
 	    {
 	      if (!bitset_test (Pp, r)
 		  && bitset_test (P, r)
@@ -215,10 +215,10 @@ inaccessable_symbols (void)
 
   /* A token that was used in %prec should not be warned about.  */
   {
-    rule_number_t i;
-    for (i = 1; i < nrules + 1; i++)
-      if (rules[i].precsym != 0)
-	bitset_set (V1, rules[i].precsym->number);
+    rule_number_t r;
+    for (r = 0; r < nrules; ++r)
+      if (rules[r].precsym != 0)
+	bitset_set (V1, rules[r].precsym->number);
   }
 }
 
@@ -234,7 +234,7 @@ reduce_grammar_tables (void)
   /* Report and flag useless productions.  */
   {
     rule_number_t r;
-    for (r = 1; r < nrules + 1; r++)
+    for (r = 0; r < nrules; r++)
       {
 	rules[r].useful = bitset_test (P, r);
 	if (!rules[r].useful)
@@ -249,17 +249,17 @@ reduce_grammar_tables (void)
   /* Map the nonterminals to their new index: useful first, useless
      afterwards.  Kept for later report.  */
   {
-    int useful = 1;
-    int useless = nrules + 1 - nuseless_productions;
-    rule_t *rules_sorted = XMALLOC (rule_t, nrules + 1) - 1;
+    int useful = 0;
+    int useless = nrules - nuseless_productions;
+    rule_t *rules_sorted = XMALLOC (rule_t, nrules);
     rule_number_t r;
-    for (r = 1; r < nrules + 1; ++r)
+    for (r = 0; r < nrules; ++r)
       rules_sorted[rules[r].useful ? useful++ : useless++] = rules[r];
-    free (rules + 1);
+    free (rules);
     rules = rules_sorted;
 
     /* Renumber the rules markers in RITEMS.  */
-    for (r = 1; r < nrules + 1; ++r)
+    for (r = 0; r < nrules; ++r)
       {
 	item_number_t *rhsp = rules[r].rhs;
 	for (/* Nothing. */; *rhsp >= 0; ++rhsp)
@@ -274,7 +274,7 @@ reduce_grammar_tables (void)
   {
     int r;
     int length;
-    for (r = nrules + 1; r < nrules + 1 + nuseless_productions; ++r)
+    for (r = nrules; r < nrules + nuseless_productions; ++r)
       {
 	length = rule_rhs_length (&rules[r]);
 	nritems -= length + 1;
@@ -326,7 +326,7 @@ nonterminals_reduce (void)
 
   {
     rule_number_t r;
-    for (r = 1; r < nrules + 1; ++r)
+    for (r = 0; r < nrules; ++r)
       {
 	item_number_t *rhsp;
 	for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
@@ -376,8 +376,8 @@ reduce_output (FILE *out)
 
   if (nuseless_productions > 0)
     grammar_rules_partial_print (out, _("Useless rules"),
-				 nrules + 1,
-				 nuseless_productions + nrules + 1);
+				 nrules,
+				 nrules + nuseless_productions);
 }
 
 
@@ -425,7 +425,7 @@ reduce_grammar (void)
   /* Allocate the global sets used to compute the reduced grammar */
 
   N = bitset_create (nvars, BITSET_FIXED);
-  P =  bitset_create (nrules + 1, BITSET_FIXED);
+  P =  bitset_create (nrules, BITSET_FIXED);
   V = bitset_create (nsyms, BITSET_FIXED);
   V1 = bitset_create (nsyms, BITSET_FIXED);
 
