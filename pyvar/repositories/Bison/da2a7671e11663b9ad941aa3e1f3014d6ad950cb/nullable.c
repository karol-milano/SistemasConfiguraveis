@@ -61,16 +61,16 @@ nullable_compute (void)
   symbol_number *s2;
   rule_list *p;
 
-  symbol_number *squeue = CALLOC (squeue, nvars);
-  short int *rcount = CALLOC (rcount, nrules);
+  symbol_number *squeue = xnmalloc (nvars, sizeof *squeue);
+  short int *rcount = xcalloc (nrules, sizeof *rcount);
   /* RITEM contains all the rules, including useless productions.
      Hence we must allocate room for useless nonterminals too.  */
-  rule_list **rsets = CALLOC (rsets, nvars);
+  rule_list **rsets = xcalloc (nvars, sizeof *rsets);
   /* This is said to be more elements than we actually use.
      Supposedly NRITEMS - NRULES is enough.  But why take the risk?  */
-  rule_list *relts = CALLOC (relts, nritems + nvars + 1);
+  rule_list *relts = xnmalloc (nritems + nvars + 1, sizeof *relts);
 
-  CALLOC (nullable, nvars);
+  nullable = xcalloc (nvars, sizeof *nullable);
 
   s1 = s2 = squeue;
   p = relts;
