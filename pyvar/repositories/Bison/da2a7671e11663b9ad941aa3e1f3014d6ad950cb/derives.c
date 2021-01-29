@@ -37,7 +37,7 @@ typedef struct rule_list
   rule *value;
 } rule_list;
 
-rule ***derives = NULL;
+rule ***derives;
 
 static void
 print_derives (void)
@@ -70,12 +70,12 @@ derives_compute (void)
 
   /* DSET[NTERM - NTOKENS] -- A linked list of the numbers of the rules
      whose LHS is NTERM.  */
-  rule_list **dset = CALLOC (dset, nvars);
+  rule_list **dset = xcalloc (nvars, sizeof *dset);
 
   /* DELTS[RULE] -- There are NRULES rule number to attach to nterms.
      Instead of performing NRULES allocations for each, have an array
      indexed by rule numbers.  */
-  rule_list *delts = CALLOC (delts, nrules);
+  rule_list *delts = xnmalloc (nrules, sizeof *delts);
 
   for (r = nrules - 1; r >= 0; --r)
     {
@@ -90,8 +90,8 @@ derives_compute (void)
   /* DSET contains what we need under the form of a linked list.  Make
      it a single array.  */
 
-  CALLOC (derives, nvars);
-  CALLOC (q, nvars + nrules);
+  derives = xnmalloc (nvars, sizeof *derives);
+  q = xnmalloc (nvars + nrules, sizeof *q);
 
   for (i = ntokens; i < nsyms; i++)
     {
