@@ -46,9 +46,8 @@ print_derives (void)
 
   for (i = ntokens; i < nsyms; i++)
     {
-      rule **rp;
       fprintf (stderr, "  %s derives\n", symbols[i]->tag);
-      for (rp = derives[i - ntokens]; *rp; ++rp)
+      for (rule **rp = derives[i - ntokens]; *rp; ++rp)
         {
           fprintf (stderr, "    %3d ", (*rp)->user_number);
           rule_rhs_print (*rp, stderr);
@@ -63,10 +62,6 @@ print_derives (void)
 void
 derives_compute (void)
 {
-  symbol_number i;
-  rule_number r;
-  rule **q;
-
   /* DSET[NTERM - NTOKENS] -- A linked list of the numbers of the rules
      whose LHS is NTERM.  */
   rule_list **dset = xcalloc (nvars, sizeof *dset);
@@ -76,7 +71,7 @@ derives_compute (void)
      indexed by rule numbers.  */
   rule_list *delts = xnmalloc (nrules, sizeof *delts);
 
-  for (r = nrules - 1; r >= 0; --r)
+  for (rule_number r = nrules - 1; r >= 0; --r)
     {
       symbol_number lhs = rules[r].lhs->number;
       rule_list *p = &delts[r];
@@ -90,9 +85,10 @@ derives_compute (void)
      it a single array.  */
 
   derives = xnmalloc (nvars, sizeof *derives);
-  q = xnmalloc (nvars + nrules, sizeof *q);
+  /* Q is the storage for DERIVES[...] (DERIVES[0] = q).  */
+  rule **q = xnmalloc (nvars + nrules, sizeof *q);
 
-  for (i = ntokens; i < nsyms; i++)
+  for (symbol_number i = ntokens; i < nsyms; i++)
     {
       rule_list *p = dset[i - ntokens];
       derives[i - ntokens] = q;
