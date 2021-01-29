@@ -58,7 +58,7 @@ set_nullable (void)
   rule_list_t *p;
 
   symbol_number_t *squeue = XCALLOC (symbol_number_t, nvars);
-  short *rcount = XCALLOC (short, nrules + 1);
+  short *rcount = XCALLOC (short, nrules);
   /* RITEM contains all the rules, including useless productions.
      Hence we must allocate room for useless nonterminals too.  */
   rule_list_t **rsets = XCALLOC (rule_list_t *, nvars) - ntokens;
@@ -74,7 +74,7 @@ set_nullable (void)
   s1 = s2 = squeue;
   p = relts;
 
-  for (ruleno = 1; ruleno < nrules + 1; ++ruleno)
+  for (ruleno = 0; ruleno < nrules; ++ruleno)
     if (rules[ruleno].useful)
       {
 	rule_t *rule = &rules[ruleno];
