@@ -47,11 +47,11 @@ void
 set_nullable (void)
 {
   int ruleno;
-  short *s1;
-  short *s2;
+  token_number_t *s1;
+  token_number_t *s2;
   shorts *p;
 
-  short *squeue = XCALLOC (short, nvars);
+  token_number_t *squeue = XCALLOC (token_number_t, nvars);
   short *rcount = XCALLOC (short, nrules + 1);
   /* RITEM contains all the rules, including useless productions.
      Hence we must allocate room for useless nonterminals too.  */
