@@ -50,10 +50,10 @@ static bitset V;
    `useless', but no warning should be issued).  */
 static bitset V1;
 
-static int nuseful_productions;
-int nuseless_productions;
+static rule_number_t nuseful_productions;
+rule_number_t nuseless_productions;
 static int nuseful_nonterminals;
-int nuseless_nonterminals;
+symbol_number_t nuseless_nonterminals;
 
 /*-------------------------------------------------------------------.
 | Another way to do this would be with a set for each production and |
@@ -62,16 +62,15 @@ int nuseless_nonterminals;
 `-------------------------------------------------------------------*/
 
 static bool
-useful_production (int i, bitset N0)
+useful_production (rule_number_t r, bitset N0)
 {
-  item_number_t *r;
-  short n;
+  item_number_t *rhsp;
 
   /* A production is useful if all of the nonterminals in its appear
      in the set of useful nonterminals.  */
 
-  for (r = rules[i].rhs; *r >= 0; r++)
-    if (ISVAR (n = *r) && !bitset_test (N0, n - ntokens))
+  for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
+    if (ISVAR (*rhsp) && !bitset_test (N0, *rhsp - ntokens))
       return FALSE;
   return TRUE;
 }
@@ -85,7 +84,7 @@ static void
 useless_nonterminals (void)
 {
   bitset Np, Ns;
-  int i;
+  rule_number_t r;
 
   /* N is set as built.  Np is set being built this iteration. P is
      set of all productions which have a RHS all in N.  */
@@ -112,12 +111,12 @@ useless_nonterminals (void)
   while (1)
     {
       bitset_copy (Np, N);
-      for (i = 1; i < nrules + 1; i++)
-	if (!bitset_test (P, i)
-	    && useful_production (i, N))
+      for (r = 1; r < nrules + 1; r++)
+	if (!bitset_test (P, r)
+	    && useful_production (r, N))
 	  {
-	    bitset_set (Np, rules[i].lhs->number - ntokens);
-	    bitset_set (P, i);
+	    bitset_set (Np, rules[r].lhs->number - ntokens);
+	    bitset_set (P, r);
 	  }
       if (bitset_equal_p (N, Np))
 	break;
@@ -134,9 +133,6 @@ static void
 inaccessable_symbols (void)
 {
   bitset Vp, Vs, Pp;
-  int i;
-  short t;
-  item_number_t *r;
 
   /* Find out which productions are reachable and which symbols are
      used.  Starting with an empty set of productions and a set of
@@ -171,17 +167,19 @@ inaccessable_symbols (void)
 
       while (1)
 	{
+	  rule_number_t r;
 	  bitset_copy (Vp, V);
-	  for (i = 1; i < nrules + 1; i++)
+	  for (r = 1; r < nrules + 1; r++)
 	    {
-	      if (!bitset_test (Pp, i)
-		  && bitset_test (P, i)
-		  && bitset_test (V, rules[i].lhs->number))
+	      if (!bitset_test (Pp, r)
+		  && bitset_test (P, r)
+		  && bitset_test (V, rules[r].lhs->number))
 		{
-		  for (r = rules[i].rhs; *r >= 0; r++)
-		    if (ISTOKEN (t = *r) || bitset_test (N, t - ntokens))
-		      bitset_set (Vp, t);
-		  bitset_set (Pp, i);
+		  item_number_t *rhsp;
+		  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
+		    if (ISTOKEN (*rhsp) || bitset_test (N, *rhsp - ntokens))
+		      bitset_set (Vp, *rhsp);
+		  bitset_set (Pp, r);
 		}
 	    }
 	  if (bitset_equal_p (V, Vp))
@@ -207,15 +205,21 @@ inaccessable_symbols (void)
   nuseless_productions = nrules - nuseful_productions;
 
   nuseful_nonterminals = 0;
-  for (i = ntokens; i < nsyms; i++)
-    if (bitset_test (V, i))
-      nuseful_nonterminals++;
+  {
+    symbol_number_t i;
+    for (i = ntokens; i < nsyms; i++)
+      if (bitset_test (V, i))
+	nuseful_nonterminals++;
+  }
   nuseless_nonterminals = nvars - nuseful_nonterminals;
 
   /* A token that was used in %prec should not be warned about.  */
-  for (i = 1; i < nrules + 1; i++)
-    if (rules[i].precsym != 0)
-      bitset_set (V1, rules[i].precsym->number);
+  {
+    rule_number_t i;
+    for (i = 1; i < nrules + 1; i++)
+      if (rules[i].precsym != 0)
+	bitset_set (V1, rules[i].precsym->number);
+  }
 }
 
 
@@ -229,7 +233,7 @@ reduce_grammar_tables (void)
 {
   /* Report and flag useless productions.  */
   {
-    int r;
+    rule_number_t r;
     for (r = 1; r < nrules + 1; r++)
       {
 	rules[r].useful = bitset_test (P, r);
@@ -248,20 +252,20 @@ reduce_grammar_tables (void)
     int useful = 1;
     int useless = nrules + 1 - nuseless_productions;
     rule_t *rules_sorted = XMALLOC (rule_t, nrules + 1) - 1;
-    int i;
-    for (i = 1; i < nrules + 1; ++i)
-      rules_sorted[rules[i].useful ? useful++ : useless++] = rules[i];
+    rule_number_t r;
+    for (r = 1; r < nrules + 1; ++r)
+      rules_sorted[rules[r].useful ? useful++ : useless++] = rules[r];
     free (rules + 1);
     rules = rules_sorted;
 
     /* Renumber the rules markers in RITEMS.  */
-    for (i = 1; i < nrules + 1; ++i)
+    for (r = 1; r < nrules + 1; ++r)
       {
-	item_number_t *rhsp = rules[i].rhs;
+	item_number_t *rhsp = rules[r].rhs;
 	for (/* Nothing. */; *rhsp >= 0; ++rhsp)
 	  /* Nothing. */;
-	*rhsp = -i;
-	rules[i].number = i;
+	*rhsp = item_number_of_rule_number (r);
+	rules[r].number = r;
       }
     nrules -= nuseless_productions;
   }
@@ -321,7 +325,7 @@ nonterminals_reduce (void)
   }
 
   {
-    int r;
+    rule_number_t r;
     for (r = 1; r < nrules + 1; ++r)
       {
 	item_number_t *rhsp;
