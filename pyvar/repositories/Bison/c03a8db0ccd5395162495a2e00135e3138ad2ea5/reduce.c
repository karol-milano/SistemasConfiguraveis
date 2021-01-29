@@ -52,10 +52,10 @@ static bitset V;
    'useless', but no warning should be issued).  */
 static bitset V1;
 
-static rule_number nuseful_productions;
-rule_number nuseless_productions;
-static int nuseful_nonterminals;
-symbol_number nuseless_nonterminals;
+static unsigned nuseful_productions;
+unsigned nuseless_productions;
+static unsigned nuseful_nonterminals;
+unsigned nuseless_nonterminals;
 
 #define bitset_swap(Lhs, Rhs)                   \
   do {                                          \
@@ -343,7 +343,7 @@ nonterminals_reduce (void)
 void
 reduce_output (FILE *out)
 {
-  if (0 < nuseless_nonterminals)
+  if (nuseless_nonterminals)
     {
       int i;
       fprintf (out, "%s\n\n", _("Nonterminals useless in grammar"));
@@ -367,7 +367,7 @@ reduce_output (FILE *out)
       fputs ("\n\n", out);
   }
 
-  if (0 < nuseless_productions)
+  if (nuseless_productions)
     grammar_rules_partial_print (out, _("Rules useless in grammar"),
                                  rule_useless_in_grammar_p);
 }
@@ -380,12 +380,12 @@ reduce_output (FILE *out)
 static void
 reduce_print (void)
 {
-  if (0 < nuseless_nonterminals)
+  if (nuseless_nonterminals)
     complain (NULL, Wother, ngettext ("%d nonterminal useless in grammar",
                                       "%d nonterminals useless in grammar",
                                       nuseless_nonterminals),
               nuseless_nonterminals);
-  if (0 < nuseless_productions)
+  if (nuseless_productions)
     complain (NULL, Wother, ngettext ("%d rule useless in grammar",
                                       "%d rules useless in grammar",
                                       nuseless_productions),
@@ -419,9 +419,9 @@ reduce_grammar (void)
   /* First reduce the nonterminals, as they renumber themselves in the
      whole grammar.  If you change the order, nonterms would be
      renumbered only in the reduced grammar.  */
-  if (0 < nuseless_nonterminals)
+  if (nuseless_nonterminals)
     nonterminals_reduce ();
-  if (0 < nuseless_productions)
+  if (nuseless_productions)
     reduce_grammar_tables ();
 
   if (trace_flag & trace_grammar)
