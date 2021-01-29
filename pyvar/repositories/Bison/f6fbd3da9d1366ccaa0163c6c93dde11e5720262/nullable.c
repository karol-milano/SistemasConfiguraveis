@@ -62,7 +62,7 @@ nullable_compute (void)
   rule_list *p;
 
   symbol_number *squeue = xnmalloc (nvars, sizeof *squeue);
-  short int *rcount = xcalloc (nrules, sizeof *rcount);
+  size_t *rcount = xcalloc (nrules, sizeof *rcount);
   /* RITEM contains all the rules, including useless productions.
      Hence we must allocate room for useless nonterminals too.  */
   rule_list **rsets = xcalloc (nvars, sizeof *rsets);
