@@ -62,7 +62,7 @@ derives_compute (void)
 {
   /* DSET[NTERM - NTOKENS] -- A linked list of the numbers of the rules
      whose LHS is NTERM.  */
-  rule_list **dset = xcalloc (nvars, sizeof *dset);
+  rule_list **dset = xcalloc (nnterms, sizeof *dset);
 
   /* DELTS[RULE] -- There are NRULES rule number to attach to nterms.
      Instead of performing NRULES allocations for each, have an array
@@ -82,9 +82,9 @@ derives_compute (void)
   /* DSET contains what we need under the form of a linked list.  Make
      it a single array.  */
 
-  derives = xnmalloc (nvars, sizeof *derives);
+  derives = xnmalloc (nnterms, sizeof *derives);
   /* Q is the storage for DERIVES[...] (DERIVES[0] = q).  */
-  rule **q = xnmalloc (nvars + nrules, sizeof *q);
+  rule **q = xnmalloc (nnterms + nrules, sizeof *q);
 
   for (symbol_number i = ntokens; i < nsyms; ++i)
     {
