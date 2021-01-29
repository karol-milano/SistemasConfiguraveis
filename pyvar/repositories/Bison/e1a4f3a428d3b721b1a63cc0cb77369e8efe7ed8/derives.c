@@ -27,6 +27,13 @@
 #include "gram.h"
 #include "derives.h"
 
+/* Linked list of rule numbers.  */
+typedef struct rule_list_s
+{
+  struct rule_list_s *next;
+  rule_number_t value;
+} rule_list_t;
+
 rule_number_t **derives = NULL;
 
 static void
@@ -42,12 +49,8 @@ print_derives (void)
       fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
       for (rp = derives[i]; *rp > 0; rp++)
 	{
-	  item_number_t *rhsp;
-	  fprintf (stderr, "\t\t%d:", *rp);
-	  for (rhsp = rules[*rp].rhs; *rhsp >= 0; ++rhsp)
-	    fprintf (stderr, " %s", symbols[*rhsp]->tag);
-	  fprintf (stderr, " (rule %d)\n",
-		   rule_number_of_item_number (*rhsp) - 1);
+	  fprintf (stderr, "\t\t%3d ", *rp - 1);
+	  rule_rhs_print (&rules[*rp], stderr);
 	}
     }
 
@@ -60,31 +63,37 @@ set_derives (void)
 {
   symbol_number_t i;
   rule_number_t r;
-  shorts *p;
   rule_number_t *q;
-  shorts **dset;
-  shorts *delts;
 
-  dset = XCALLOC (shorts *, nvars) - ntokens;
-  delts = XCALLOC (shorts, nrules + 1);
+  /* DSET[NTERM] -- A linked list of the numbers of the rules whose
+     LHS is NTERM.  */
+  rule_list_t **dset = XCALLOC (rule_list_t *, nvars) - ntokens;
+
+  /* DELTS[RULE] -- There are NRULES rule number to attach to nterms.
+     Instead of performing NRULES allocations for each, have an array
+     indexed by rule numbers.  */
+  rule_list_t *delts = XCALLOC (rule_list_t, nrules + 1);
 
-  p = delts;
   for (r = nrules; r > 0; r--)
     {
       symbol_number_t lhs = rules[r].lhs->number;
+      rule_list_t *p = &delts[r];
+      /* A new LHS is found.  */
       p->next = dset[lhs];
       p->value = r;
       dset[lhs] = p;
-      p++;
     }
 
+  /* DSET contains what we need under the form of a linked list.  Make
+     it a single array.  */
+
   derives = XCALLOC (rule_number_t *, nvars) - ntokens;
-  q = XCALLOC (short, nvars + int_of_rule_number (nrules));
+  q = XCALLOC (rule_number_t, nvars + int_of_rule_number (nrules));
 
   for (i = ntokens; i < nsyms; i++)
     {
+      rule_list_t *p = dset[i];
       derives[i] = q;
-      p = dset[i];
       while (p)
 	{
 	  *q++ = p->value;
@@ -96,10 +105,11 @@ set_derives (void)
   if (trace_flag)
     print_derives ();
 
-  XFREE (dset + ntokens);
-  XFREE (delts);
+  free (dset + ntokens);
+  free (delts);
 }
 
+
 void
 free_derives (void)
 {
