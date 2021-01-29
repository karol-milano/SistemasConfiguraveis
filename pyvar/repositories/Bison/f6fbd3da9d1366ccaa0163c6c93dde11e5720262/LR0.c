@@ -105,9 +105,9 @@ allocate_itemsets (void)
      Note that useless productions (hence useless nonterminals) are
      browsed too, hence we need to allocate room for _all_ the
      symbols.  */
-  int count = 0;
-  short int *symbol_count = xcalloc (nsyms + nuseless_nonterminals,
-				     sizeof *symbol_count);
+  size_t count = 0;
+  size_t *symbol_count = xcalloc (nsyms + nuseless_nonterminals,
+				  sizeof *symbol_count);
 
   for (r = 0; r < nrules; ++r)
     for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
@@ -178,7 +178,7 @@ free_storage (void)
 static void
 new_itemsets (state *s)
 {
-  int i;
+  size_t i;
 
   if (trace_flag & trace_automaton)
     fprintf (stderr, "Entering new_itemsets, state = %d\n", s->number);
@@ -274,7 +274,7 @@ static void
 save_reductions (state *s)
 {
   int count = 0;
-  int i;
+  size_t i;
 
   /* Find and count the active items that represent ends of rules. */
   for (i = 0; i < nritemset; ++i)
