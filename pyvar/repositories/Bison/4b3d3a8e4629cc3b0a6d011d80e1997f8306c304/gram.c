@@ -56,7 +56,7 @@ int pure_parser = 0;
 void
 rule_lhs_print (rule_t *rule, symbol_t *previous_lhs, FILE *out)
 {
-  fprintf (out, "  %3d ", rule->number - 1);
+  fprintf (out, "  %3d ", rule->number);
   if (previous_lhs != rule->lhs)
     {
       fprintf (out, "%s:", rule->lhs->tag);
@@ -132,7 +132,7 @@ ritem_print (FILE *out)
     if (ritem[i] >= 0)
       fprintf (out, "  %s", symbols[ritem[i]]->tag);
     else
-      fprintf (out, "  (rule %d)\n", -ritem[i] - 1);
+      fprintf (out, "  (rule %d)\n", item_number_as_rule_number (ritem[i]));
   fputs ("\n\n", out);
 }
 
@@ -147,7 +147,7 @@ ritem_longest_rhs (void)
   int max = 0;
   rule_number_t r;
 
-  for (r = 1; r < nrules + 1; ++r)
+  for (r = 0; r < nrules; ++r)
     {
       int length = rule_rhs_length (&rules[r]);
       if (length > max)
@@ -191,7 +191,7 @@ grammar_rules_partial_print (FILE *out, const char *title,
 void
 grammar_rules_print (FILE *out)
 {
-  grammar_rules_partial_print (out, _("Grammar"), 1, nrules + 1);
+  grammar_rules_partial_print (out, _("Grammar"), 0, nrules);
 }
 
 
@@ -225,7 +225,7 @@ grammar_dump (FILE *out, const char *title)
   {
     rule_number_t i;
     fprintf (out, "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n");
-    for (i = 1; i < nrules + nuseless_productions + 1; i++)
+    for (i = 0; i < nrules + nuseless_productions; i++)
       {
 	rule_t *rule = &rules[i];
 	item_number_t *r = NULL;
@@ -234,7 +234,7 @@ grammar_dump (FILE *out, const char *title)
 	for (r = rule->rhs; *r >= 0; ++r)
 	  ++rhs_count;
 	fprintf (out, "%3d (%2d, %2d, %2d, %2d-%2d)   %2d ->",
-		 i - 1,
+		 i,
 		 rule->prec ? rule->prec->prec : 0,
 		 rule->prec ? rule->prec->assoc : 0,
 		 rule->useful,
@@ -244,7 +244,7 @@ grammar_dump (FILE *out, const char *title)
 	/* Dumped the RHS. */
 	for (r = rule->rhs; *r >= 0; r++)
 	  fprintf (out, " %3d", *r);
-	fprintf (out, "  [%d]\n", -(*r) - 1);
+	fprintf (out, "  [%d]\n", item_number_as_rule_number (*r));
       }
   }
   fprintf (out, "\n\n");
@@ -252,7 +252,7 @@ grammar_dump (FILE *out, const char *title)
   fprintf (out, "Rules interpreted\n-----------------\n\n");
   {
     rule_number_t r;
-    for (r = 1; r < nrules + nuseless_productions + 1; r++)
+    for (r = 0; r < nrules + nuseless_productions; r++)
       {
 	fprintf (out, "%-5d  ", r);
 	rule_print (&rules[r], out);
@@ -266,7 +266,7 @@ void
 grammar_free (void)
 {
   XFREE (ritem);
-  free (rules + 1);
+  free (rules);
   XFREE (token_translations);
   /* Free the symbol table data structure.  */
   symbols_free ();
