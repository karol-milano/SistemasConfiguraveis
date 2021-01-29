@@ -46,9 +46,9 @@ print_derives (void)
     {
       rule_number_t *rp;
       fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
-      for (rp = derives[i]; *rp > 0; rp++)
+      for (rp = derives[i]; *rp >= 0; rp++)
 	{
-	  fprintf (stderr, "\t\t%3d ", *rp - 1);
+	  fprintf (stderr, "\t\t%3d ", *rp);
 	  rule_rhs_print (&rules[*rp], stderr);
 	}
     }
@@ -61,7 +61,7 @@ void
 set_derives (void)
 {
   symbol_number_t i;
-  rule_number_t r;
+  int r;
   rule_number_t *q;
 
   /* DSET[NTERM] -- A linked list of the numbers of the rules whose
@@ -71,9 +71,9 @@ set_derives (void)
   /* DELTS[RULE] -- There are NRULES rule number to attach to nterms.
      Instead of performing NRULES allocations for each, have an array
      indexed by rule numbers.  */
-  rule_list_t *delts = XCALLOC (rule_list_t, nrules + 1);
+  rule_list_t *delts = XCALLOC (rule_list_t, nrules);
 
-  for (r = nrules; r > 0; r--)
+  for (r = nrules - 1; r >= 0; --r)
     {
       symbol_number_t lhs = rules[r].lhs->number;
       rule_list_t *p = &delts[r];
