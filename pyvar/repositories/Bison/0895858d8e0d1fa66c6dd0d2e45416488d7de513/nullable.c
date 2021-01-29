@@ -54,17 +54,17 @@ nullable_print (FILE *out)
 void
 nullable_compute (void)
 {
-  nullable = xcalloc (nvars, sizeof *nullable);
+  nullable = xcalloc (nnterms, sizeof *nullable);
 
   size_t *rcount = xcalloc (nrules, sizeof *rcount);
   /* RITEM contains all the rules, including useless productions.
      Hence we must allocate room for useless nonterminals too.  */
-  rule_list **rsets = xcalloc (nvars, sizeof *rsets);
+  rule_list **rsets = xcalloc (nnterms, sizeof *rsets);
   /* This is said to be more elements than we actually use.
      Supposedly NRITEMS - NRULES is enough.  But why take the risk?  */
-  rule_list *relts = xnmalloc (nritems + nvars + 1, sizeof *relts);
+  rule_list *relts = xnmalloc (nritems + nnterms + 1, sizeof *relts);
 
-  symbol_number *squeue = xnmalloc (nvars, sizeof *squeue);
+  symbol_number *squeue = xnmalloc (nnterms, sizeof *squeue);
   symbol_number *s2 = squeue;
   {
     rule_list *p = relts;
