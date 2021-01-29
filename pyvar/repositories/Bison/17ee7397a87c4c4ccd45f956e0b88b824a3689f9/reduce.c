@@ -26,16 +26,17 @@
    user's parser.  */
 
 #include "system.h"
-#include "quotearg.h"
-#include "getargs.h"
+
+#include <bitset.h>
+#include <quotearg.h>
+
+#include "complain.h"
 #include "files.h"
-#include "symtab.h"
+#include "getargs.h"
 #include "gram.h"
-#include "complain.h"
-#include "reduce.h"
 #include "reader.h"
-#include "getargs.h"
-#include "bitset.h"
+#include "reduce.h"
+#include "symtab.h"
 
 /* Set of all nonterminals which are not useless.  */
 static bitset N;
@@ -50,10 +51,10 @@ static bitset V;
    `useless', but no warning should be issued).  */
 static bitset V1;
 
-static rule_number_t nuseful_productions;
-rule_number_t nuseless_productions;
+static rule_number nuseful_productions;
+rule_number nuseless_productions;
 static int nuseful_nonterminals;
-symbol_number_t nuseless_nonterminals;
+symbol_number nuseless_nonterminals;
 
 /*-------------------------------------------------------------------.
 | Another way to do this would be with a set for each production and |
@@ -62,9 +63,9 @@ symbol_number_t nuseless_nonterminals;
 `-------------------------------------------------------------------*/
 
 static bool
-useful_production (rule_number_t r, bitset N0)
+useful_production (rule_number r, bitset N0)
 {
-  item_number_t *rhsp;
+  item_number *rhsp;
 
   /* A production is useful if all of the nonterminals in its appear
      in the set of useful nonterminals.  */
@@ -84,7 +85,7 @@ static void
 useless_nonterminals (void)
 {
   bitset Np, Ns;
-  rule_number_t r;
+  rule_number r;
 
   /* N is set as built.  Np is set being built this iteration. P is
      set of all productions which have a RHS all in N.  */
@@ -167,7 +168,7 @@ inaccessable_symbols (void)
 
       while (1)
 	{
-	  rule_number_t r;
+	  rule_number r;
 	  bitset_copy (Vp, V);
 	  for (r = 0; r < nrules; r++)
 	    {
@@ -175,7 +176,7 @@ inaccessable_symbols (void)
 		  && bitset_test (P, r)
 		  && bitset_test (V, rules[r].lhs->number))
 		{
-		  item_number_t *rhsp;
+		  item_number *rhsp;
 		  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
 		    if (ISTOKEN (*rhsp) || bitset_test (N, *rhsp - ntokens))
 		      bitset_set (Vp, *rhsp);
@@ -206,7 +207,7 @@ inaccessable_symbols (void)
 
   nuseful_nonterminals = 0;
   {
-    symbol_number_t i;
+    symbol_number i;
     for (i = ntokens; i < nsyms; i++)
       if (bitset_test (V, i))
 	nuseful_nonterminals++;
@@ -215,7 +216,7 @@ inaccessable_symbols (void)
 
   /* A token that was used in %prec should not be warned about.  */
   {
-    rule_number_t r;
+    rule_number r;
     for (r = 0; r < nrules; ++r)
       if (rules[r].precsym != 0)
 	bitset_set (V1, rules[r].precsym->number);
@@ -233,7 +234,7 @@ reduce_grammar_tables (void)
 {
   /* Report and flag useless productions.  */
   {
-    rule_number_t r;
+    rule_number r;
     for (r = 0; r < nrules; r++)
       rules[r].useful = bitset_test (P, r);
     grammar_rules_never_reduced_report (_("useless rule"));
@@ -244,8 +245,8 @@ reduce_grammar_tables (void)
   {
     int useful = 0;
     int useless = nrules - nuseless_productions;
-    rule_t *rules_sorted = XMALLOC (rule_t, nrules);
-    rule_number_t r;
+    rule *rules_sorted = XMALLOC (rule, nrules);
+    rule_number r;
     for (r = 0; r < nrules; ++r)
       rules_sorted[rules[r].useful ? useful++ : useless++] = rules[r];
     free (rules);
@@ -254,7 +255,7 @@ reduce_grammar_tables (void)
     /* Renumber the rules markers in RITEMS.  */
     for (r = 0; r < nrules; ++r)
       {
-	item_number_t *rhsp = rules[r].rhs;
+	item_number *rhsp = rules[r].rhs;
 	for (/* Nothing. */; *rhsp >= 0; ++rhsp)
 	  /* Nothing. */;
 	*rhsp = rule_number_as_item_number (r);
@@ -283,12 +284,12 @@ reduce_grammar_tables (void)
 static void
 nonterminals_reduce (void)
 {
-  symbol_number_t i, n;
+  symbol_number i, n;
 
   /* Map the nonterminals to their new index: useful first, useless
      afterwards.  Kept for later report.  */
 
-  symbol_number_t *nontermmap = XCALLOC (symbol_number_t, nvars) - ntokens;
+  symbol_number *nontermmap = XCALLOC (symbol_number, nvars) - ntokens;
   n = ntokens;
   for (i = ntokens; i < nsyms; i++)
     if (bitset_test (V, i))
@@ -304,7 +305,7 @@ nonterminals_reduce (void)
 
   /* Shuffle elements of tables indexed by symbol number.  */
   {
-    symbol_t **symbols_sorted = XMALLOC (symbol_t *, nvars) - ntokens;
+    symbol **symbols_sorted = XMALLOC (symbol *, nvars) - ntokens;
 
     for (i = ntokens; i < nsyms; i++)
       symbols[i]->number = nontermmap[i];
@@ -316,10 +317,10 @@ nonterminals_reduce (void)
   }
 
   {
-    rule_number_t r;
+    rule_number r;
     for (r = 0; r < nrules; ++r)
       {
-	item_number_t *rhsp;
+	item_number *rhsp;
 	for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
 	  if (ISVAR (*rhsp))
 	    *rhsp =  symbol_number_as_item_number (nontermmap[*rhsp]);
