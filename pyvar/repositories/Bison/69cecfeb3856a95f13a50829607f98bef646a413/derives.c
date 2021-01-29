@@ -50,7 +50,7 @@ print_derives (void)
     {
       rule **rp;
       fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
-      for (rp = derives[i]; *rp; ++rp)
+      for (rp = derives[i - ntokens]; *rp; ++rp)
 	{
 	  fprintf (stderr, "\t\t%3d ", (*rp)->user_number);
 	  rule_rhs_print (*rp, stderr);
@@ -68,35 +68,35 @@ derives_compute (void)
   int r;
   rule **q;
 
-  /* DSET[NTERM] -- A linked list of the numbers of the rules whose
-     LHS is NTERM.  */
-  rule_list **dset = XCALLOC (rule_list *, nvars) - ntokens;
+  /* DSET[NTERM - NTOKENS] -- A linked list of the numbers of the rules
+     whose LHS is NTERM.  */
+  rule_list **dset = CALLOC (dset, nvars);
 
   /* DELTS[RULE] -- There are NRULES rule number to attach to nterms.
      Instead of performing NRULES allocations for each, have an array
      indexed by rule numbers.  */
-  rule_list *delts = XCALLOC (rule_list, nrules);
+  rule_list *delts = CALLOC (delts, nrules);
 
   for (r = nrules - 1; r >= 0; --r)
     {
       symbol_number lhs = rules[r].lhs->number;
       rule_list *p = &delts[r];
       /* A new LHS is found.  */
-      p->next = dset[lhs];
+      p->next = dset[lhs - ntokens];
       p->value = &rules[r];
-      dset[lhs] = p;
+      dset[lhs - ntokens] = p;
     }
 
   /* DSET contains what we need under the form of a linked list.  Make
      it a single array.  */
 
-  derives = XCALLOC (rule **, nvars) - ntokens;
-  q = XCALLOC (rule *, nvars + int_of_rule_number (nrules));
+  CALLOC (derives, nvars);
+  CALLOC (q, nvars + nrules);
 
   for (i = ntokens; i < nsyms; i++)
     {
-      rule_list *p = dset[i];
-      derives[i] = q;
+      rule_list *p = dset[i - ntokens];
+      derives[i - ntokens] = q;
       while (p)
 	{
 	  *q++ = p->value;
@@ -108,7 +108,7 @@ derives_compute (void)
   if (trace_flag & trace_sets)
     print_derives ();
 
-  free (dset + ntokens);
+  free (dset);
   free (delts);
 }
 
@@ -116,6 +116,6 @@ derives_compute (void)
 void
 derives_free (void)
 {
-  XFREE (derives[ntokens]);
-  XFREE (derives + ntokens);
+  free (derives[0]);
+  free (derives);
 }
