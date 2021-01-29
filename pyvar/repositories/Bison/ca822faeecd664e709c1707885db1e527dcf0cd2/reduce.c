@@ -52,9 +52,7 @@ static bitset V;
    'useless', but no warning should be issued).  */
 static bitset V1;
 
-static unsigned nuseful_productions;
 unsigned nuseless_productions;
-static unsigned nuseful_nonterminals;
 unsigned nuseless_nonterminals;
 
 #define bitset_swap(Lhs, Rhs)                   \
@@ -73,12 +71,10 @@ unsigned nuseless_nonterminals;
 static bool
 useful_production (rule_number r, bitset N0)
 {
-  item_number *rhsp;
-
   /* A production is useful if all of the nonterminals in its appear
      in the set of useful nonterminals.  */
 
-  for (rhsp = rules[r].rhs; 0 <= *rhsp; ++rhsp)
+  for (item_number *rhsp = rules[r].rhs; 0 <= *rhsp; ++rhsp)
     if (ISVAR (*rhsp) && !bitset_test (N0, *rhsp - ntokens))
       return false;
   return true;
@@ -115,9 +111,8 @@ useless_nonterminals (void)
 
   while (1)
     {
-      rule_number r;
       bitset_copy (Np, N);
-      for (r = 0; r < nrules; ++r)
+      for (rule_number r = 0; r < nrules; ++r)
         if (!bitset_test (P, r)
             && useful_production (r, N))
           {
@@ -169,15 +164,13 @@ inaccessable_symbols (void)
 
       while (1)
         {
-          rule_number r;
           bitset_copy (Vp, V);
-          for (r = 0; r < nrules; ++r)
+          for (rule_number r = 0; r < nrules; ++r)
             if (!bitset_test (Pp, r)
                 && bitset_test (P, r)
                 && bitset_test (V, rules[r].lhs->number))
               {
-                item_number *rhsp;
-                for (rhsp = rules[r].rhs; 0 <= *rhsp; ++rhsp)
+                for (item_number *rhsp = rules[r].rhs; 0 <= *rhsp; ++rhsp)
                   if (ISTOKEN (*rhsp) || bitset_test (N, *rhsp - ntokens))
                     bitset_set (Vp, *rhsp);
                 bitset_set (Pp, r);
@@ -200,24 +193,18 @@ inaccessable_symbols (void)
   bitset_free (P);
   P = Pp;
 
-  nuseful_productions = bitset_count (P);
+  unsigned nuseful_productions = bitset_count (P);
   nuseless_productions = nrules - nuseful_productions;
 
-  nuseful_nonterminals = 0;
-  {
-    symbol_number i;
-    for (i = ntokens; i < nsyms; ++i)
-      nuseful_nonterminals += bitset_test (V, i);
-  }
+  unsigned nuseful_nonterminals = 0;
+  for (symbol_number i = ntokens; i < nsyms; ++i)
+    nuseful_nonterminals += bitset_test (V, i);
   nuseless_nonterminals = nvars - nuseful_nonterminals;
 
   /* A token that was used in %prec should not be warned about.  */
-  {
-    rule_number r;
-    for (r = 0; r < nrules; ++r)
-      if (rules[r].precsym != 0)
-        bitset_set (V1, rules[r].precsym->number);
-  }
+  for (rule_number r = 0; r < nrules; ++r)
+    if (rules[r].precsym != 0)
+      bitset_set (V1, rules[r].precsym->number);
 }
 
 
@@ -231,8 +218,7 @@ reduce_grammar_tables (void)
 {
   /* Report and flag useless productions.  */
   {
-    rule_number r;
-    for (r = 0; r < nrules; ++r)
+    for (rule_number r = 0; r < nrules; ++r)
       rules[r].useful = bitset_test (P, r);
     grammar_rules_useless_report (_("rule useless in grammar"));
   }
@@ -243,14 +229,13 @@ reduce_grammar_tables (void)
     int useful = 0;
     int useless = nrules - nuseless_productions;
     rule *rules_sorted = xnmalloc (nrules, sizeof *rules_sorted);
-    rule_number r;
-    for (r = 0; r < nrules; ++r)
+    for (rule_number r = 0; r < nrules; ++r)
       rules_sorted[rules[r].useful ? useful++ : useless++] = rules[r];
     free (rules);
     rules = rules_sorted;
 
     /* Renumber the rules markers in RITEMS.  */
-    for (r = 0; r < nrules; ++r)
+    for (rule_number r = 0; r < nrules; ++r)
       {
         item_number *rhsp = rules[r].rhs;
         for (/* Nothing. */; 0 <= *rhsp; ++rhsp)
@@ -262,14 +247,10 @@ reduce_grammar_tables (void)
   }
 
   /* Adjust NRITEMS.  */
-  {
-    rule_number r;
-    int length;
-    for (r = nrules; r < nrules + nuseless_productions; ++r)
-      {
-        length = rule_rhs_length (&rules[r]);
-        nritems -= length + 1;
-      }
+  for (rule_number r = nrules; r < nrules + nuseless_productions; ++r)
+    {
+      int length = rule_rhs_length (&rules[r]);
+      nritems -= length + 1;
   }
 }
 
@@ -287,11 +268,10 @@ nonterminals_reduce (void)
   symbol_number *nontermmap = xnmalloc (nvars, sizeof *nontermmap);
   {
     symbol_number n = ntokens;
-    symbol_number i;
-    for (i = ntokens; i < nsyms; ++i)
+    for (symbol_number i = ntokens; i < nsyms; ++i)
       if (bitset_test (V, i))
         nontermmap[i - ntokens] = n++;
-    for (i = ntokens; i < nsyms; ++i)
+    for (symbol_number i = ntokens; i < nsyms; ++i)
       if (!bitset_test (V, i))
         {
           nontermmap[i - ntokens] = n++;
@@ -306,26 +286,21 @@ nonterminals_reduce (void)
   /* Shuffle elements of tables indexed by symbol number.  */
   {
     symbol **symbols_sorted = xnmalloc (nvars, sizeof *symbols_sorted);
-    symbol_number i;
-    for (i = ntokens; i < nsyms; ++i)
+    for (symbol_number i = ntokens; i < nsyms; ++i)
       symbols[i]->content->number = nontermmap[i - ntokens];
-    for (i = ntokens; i < nsyms; ++i)
+    for (symbol_number i = ntokens; i < nsyms; ++i)
       symbols_sorted[nontermmap[i - ntokens] - ntokens] = symbols[i];
-    for (i = ntokens; i < nsyms; ++i)
+    for (symbol_number i = ntokens; i < nsyms; ++i)
       symbols[i] = symbols_sorted[i - ntokens];
     free (symbols_sorted);
   }
 
   {
-    rule_number r;
-    for (r = 0; r < nrules; ++r)
-      {
-        item_number *rhsp;
-        for (rhsp = rules[r].rhs; 0 <= *rhsp; ++rhsp)
-          if (ISVAR (*rhsp))
-            *rhsp =  symbol_number_as_item_number (nontermmap[*rhsp
-                                                              - ntokens]);
-      }
+    for (rule_number r = 0; r < nrules; ++r)
+      for (item_number *rhsp = rules[r].rhs; 0 <= *rhsp; ++rhsp)
+        if (ISVAR (*rhsp))
+          *rhsp =  symbol_number_as_item_number (nontermmap[*rhsp
+                                                            - ntokens]);
     accept->content->number = nontermmap[accept->content->number - ntokens];
   }
 
@@ -345,17 +320,15 @@ reduce_output (FILE *out)
 {
   if (nuseless_nonterminals)
     {
-      int i;
       fprintf (out, "%s\n\n", _("Nonterminals useless in grammar"));
-      for (i = 0; i < nuseless_nonterminals; ++i)
+      for (int i = 0; i < nuseless_nonterminals; ++i)
         fprintf (out, "   %s\n", symbols[nsyms + i]->tag);
       fputs ("\n\n", out);
     }
 
   {
     bool b = false;
-    int i;
-    for (i = 0; i < ntokens; ++i)
+    for (int i = 0; i < ntokens; ++i)
       if (reduce_token_unused_in_grammar (i))
         {
           if (!b)
