@@ -39,7 +39,7 @@
 #include "reduce.h"
 #include "symtab.h"
 
-/* Set of all nonterminals which are not useless.  */
+/* Set of all nonterminals whose language is not empty.  */
 static bitset N;
 
 /* Set of all rules which have no useless nonterminals in their RHS.  */
@@ -71,7 +71,7 @@ useful_production (rule_number r, bitset N0)
   /* A production is useful if all of the nonterminals in its appear
      in the set of useful nonterminals.  */
 
-  for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
+  for (rhsp = rules[r].rhs; 0 <= *rhsp; ++rhsp)
     if (ISVAR (*rhsp) && !bitset_test (N0, *rhsp - ntokens))
       return false;
   return true;
@@ -85,14 +85,10 @@ useful_production (rule_number r, bitset N0)
 static void
 useless_nonterminals (void)
 {
-  bitset Np, Ns;
-  rule_number r;
-
   /* N is set as built.  Np is set being built this iteration. P is
      set of all productions which have a RHS all in N.  */
 
-  Np = bitset_create (nvars, BITSET_FIXED);
-
+  bitset Np = bitset_create (nvars, BITSET_FIXED);
 
   /* The set being computed is a set of nonterminals which can derive
      the empty string or strings consisting of all terminals. At each
@@ -112,8 +108,9 @@ useless_nonterminals (void)
 
   while (1)
     {
+      rule_number r;
       bitset_copy (Np, N);
-      for (r = 0; r < nrules; r++)
+      for (r = 0; r < nrules; ++r)
         if (!bitset_test (P, r)
             && useful_production (r, N))
           {
@@ -122,9 +119,11 @@ useless_nonterminals (void)
           }
       if (bitset_equal_p (N, Np))
         break;
-      Ns = Np;
-      Np = N;
-      N = Ns;
+      {
+        bitset Ns = Np;
+        Np = N;
+        N = Ns;
+      }
     }
   bitset_free (N);
   N = Np;
@@ -134,8 +133,6 @@ useless_nonterminals (void)
 static void
 inaccessable_symbols (void)
 {
-  bitset Vp, Vs, Pp;
-
   /* Find out which productions are reachable and which symbols are
      used.  Starting with an empty set of productions and a set of
      symbols which only has the start symbol in it, iterate over all
@@ -159,8 +156,8 @@ inaccessable_symbols (void)
      terminals are printed (if running in verbose mode) so that the
      user can know.  */
 
-  Vp = bitset_create (nsyms, BITSET_FIXED);
-  Pp = bitset_create (nrules, BITSET_FIXED);
+  bitset Vp = bitset_create (nsyms, BITSET_FIXED);
+  bitset Pp = bitset_create (nrules, BITSET_FIXED);
 
   /* If the start symbol isn't useful, then nothing will be useful. */
   if (bitset_test (N, accept->content->number - ntokens))
@@ -171,31 +168,32 @@ inaccessable_symbols (void)
         {
           rule_number r;
           bitset_copy (Vp, V);
-          for (r = 0; r < nrules; r++)
-            {
-              if (!bitset_test (Pp, r)
-                  && bitset_test (P, r)
-                  && bitset_test (V, rules[r].lhs->number))
-                {
-                  item_number *rhsp;
-                  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
-                    if (ISTOKEN (*rhsp) || bitset_test (N, *rhsp - ntokens))
-                      bitset_set (Vp, *rhsp);
-                  bitset_set (Pp, r);
-                }
-            }
+          for (r = 0; r < nrules; ++r)
+            if (!bitset_test (Pp, r)
+                && bitset_test (P, r)
+                && bitset_test (V, rules[r].lhs->number))
+              {
+                item_number *rhsp;
+                for (rhsp = rules[r].rhs; 0 <= *rhsp; ++rhsp)
+                  if (ISTOKEN (*rhsp) || bitset_test (N, *rhsp - ntokens))
+                    bitset_set (Vp, *rhsp);
+                bitset_set (Pp, r);
+              }
           if (bitset_equal_p (V, Vp))
             break;
-          Vs = Vp;
-          Vp = V;
-          V = Vs;
+          {
+            bitset Vs = Vp;
+            Vp = V;
+            V = Vs;
+          }
         }
     }
 
   bitset_free (V);
   V = Vp;
 
-  /* Tokens 0, 1, and 2 are internal to Bison.  Consider them useful. */
+  /* These tokens (numbered 0, 1, and 2) are internal to Bison.
+     Consider them useful. */
   bitset_set (V, endtoken->content->number);   /* end-of-input token */
   bitset_set (V, errtoken->content->number);   /* error token */
   bitset_set (V, undeftoken->content->number); /* some undefined token */
@@ -209,9 +207,8 @@ inaccessable_symbols (void)
   nuseful_nonterminals = 0;
   {
     symbol_number i;
-    for (i = ntokens; i < nsyms; i++)
-      if (bitset_test (V, i))
-        nuseful_nonterminals++;
+    for (i = ntokens; i < nsyms; ++i)
+      nuseful_nonterminals += bitset_test (V, i);
   }
   nuseless_nonterminals = nvars - nuseful_nonterminals;
 
@@ -236,7 +233,7 @@ reduce_grammar_tables (void)
   /* Report and flag useless productions.  */
   {
     rule_number r;
-    for (r = 0; r < nrules; r++)
+    for (r = 0; r < nrules; ++r)
       rules[r].useful = bitset_test (P, r);
     grammar_rules_useless_report (_("rule useless in grammar"));
   }
@@ -257,8 +254,8 @@ reduce_grammar_tables (void)
     for (r = 0; r < nrules; ++r)
       {
         item_number *rhsp = rules[r].rhs;
-        for (/* Nothing. */; *rhsp >= 0; ++rhsp)
-          /* Nothing. */;
+        for (/* Nothing. */; 0 <= *rhsp; ++rhsp)
+          continue;
         *rhsp = rule_number_as_item_number (r);
         rules[r].number = r;
       }
@@ -289,31 +286,33 @@ nonterminals_reduce (void)
      afterwards.  Kept for later report.  */
 
   symbol_number *nontermmap = xnmalloc (nvars, sizeof *nontermmap);
-  symbol_number n = ntokens;
-  symbol_number i;
-  for (i = ntokens; i < nsyms; i++)
-    if (bitset_test (V, i))
-      nontermmap[i - ntokens] = n++;
-  for (i = ntokens; i < nsyms; i++)
-    if (!bitset_test (V, i))
-      {
+  {
+    symbol_number n = ntokens;
+    symbol_number i;
+    for (i = ntokens; i < nsyms; ++i)
+      if (bitset_test (V, i))
         nontermmap[i - ntokens] = n++;
-        if (symbols[i]->content->status != used)
-          complain (&symbols[i]->location, Wother,
-                    _("nonterminal useless in grammar: %s"),
-                    symbols[i]->tag);
-      }
+    for (i = ntokens; i < nsyms; ++i)
+      if (!bitset_test (V, i))
+        {
+          nontermmap[i - ntokens] = n++;
+          if (symbols[i]->content->status != used)
+            complain (&symbols[i]->location, Wother,
+                      _("nonterminal useless in grammar: %s"),
+                      symbols[i]->tag);
+        }
+  }
 
 
   /* Shuffle elements of tables indexed by symbol number.  */
   {
     symbol **symbols_sorted = xnmalloc (nvars, sizeof *symbols_sorted);
-
-    for (i = ntokens; i < nsyms; i++)
+    symbol_number i;
+    for (i = ntokens; i < nsyms; ++i)
       symbols[i]->content->number = nontermmap[i - ntokens];
-    for (i = ntokens; i < nsyms; i++)
+    for (i = ntokens; i < nsyms; ++i)
       symbols_sorted[nontermmap[i - ntokens] - ntokens] = symbols[i];
-    for (i = ntokens; i < nsyms; i++)
+    for (i = ntokens; i < nsyms; ++i)
       symbols[i] = symbols_sorted[i - ntokens];
     free (symbols_sorted);
   }
@@ -323,7 +322,7 @@ nonterminals_reduce (void)
     for (r = 0; r < nrules; ++r)
       {
         item_number *rhsp;
-        for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
+        for (rhsp = rules[r].rhs; 0 <= *rhsp; ++rhsp)
           if (ISVAR (*rhsp))
             *rhsp =  symbol_number_as_item_number (nontermmap[*rhsp
                                                               - ntokens]);
@@ -345,7 +344,7 @@ nonterminals_reduce (void)
 void
 reduce_output (FILE *out)
 {
-  if (nuseless_nonterminals > 0)
+  if (0 < nuseless_nonterminals)
     {
       int i;
       fprintf (out, "%s\n\n", _("Nonterminals useless in grammar"));
@@ -357,7 +356,7 @@ reduce_output (FILE *out)
   {
     bool b = false;
     int i;
-    for (i = 0; i < ntokens; i++)
+    for (i = 0; i < ntokens; ++i)
       if (reduce_token_unused_in_grammar (i))
         {
           if (!b)
@@ -369,7 +368,7 @@ reduce_output (FILE *out)
       fputs ("\n\n", out);
   }
 
-  if (nuseless_productions > 0)
+  if (0 < nuseless_productions)
     grammar_rules_partial_print (out, _("Rules useless in grammar"),
                                  rule_useless_in_grammar_p);
 }
@@ -382,12 +381,12 @@ reduce_output (FILE *out)
 static void
 reduce_print (void)
 {
-  if (nuseless_nonterminals > 0)
+  if (0 < nuseless_nonterminals)
     complain (NULL, Wother, ngettext ("%d nonterminal useless in grammar",
                                       "%d nonterminals useless in grammar",
                                       nuseless_nonterminals),
               nuseless_nonterminals);
-  if (nuseless_productions > 0)
+  if (0 < nuseless_productions)
     complain (NULL, Wother, ngettext ("%d rule useless in grammar",
                                       "%d rules useless in grammar",
                                       nuseless_productions),
@@ -397,8 +396,6 @@ reduce_print (void)
 void
 reduce_grammar (void)
 {
-  bool reduced;
-
   /* Allocate the global sets used to compute the reduced grammar */
 
   N = bitset_create (nvars, BITSET_FIXED);
@@ -409,8 +406,8 @@ reduce_grammar (void)
   useless_nonterminals ();
   inaccessable_symbols ();
 
-  reduced = (nuseless_nonterminals + nuseless_productions > 0);
-  if (!reduced)
+  /* Did we reduce something? */
+  if (!nuseless_nonterminals && !nuseless_productions)
     return;
 
   reduce_print ();
@@ -423,9 +420,9 @@ reduce_grammar (void)
   /* First reduce the nonterminals, as they renumber themselves in the
      whole grammar.  If you change the order, nonterms would be
      renumbered only in the reduced grammar.  */
-  if (nuseless_nonterminals > 0)
+  if (0 < nuseless_nonterminals)
     nonterminals_reduce ();
-  if (nuseless_productions > 0)
+  if (0 < nuseless_productions)
     reduce_grammar_tables ();
 
   if (trace_flag & trace_grammar)
