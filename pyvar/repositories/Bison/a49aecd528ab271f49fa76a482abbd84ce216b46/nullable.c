@@ -47,11 +47,11 @@ void
 set_nullable (void)
 {
   int ruleno;
-  token_number_t *s1;
-  token_number_t *s2;
+  symbol_number_t *s1;
+  symbol_number_t *s2;
   shorts *p;
 
-  token_number_t *squeue = XCALLOC (token_number_t, nvars);
+  symbol_number_t *squeue = XCALLOC (symbol_number_t, nvars);
   short *rcount = XCALLOC (short, nrules + 1);
   /* RITEM contains all the rules, including useless productions.
      Hence we must allocate room for useless nonterminals too.  */
