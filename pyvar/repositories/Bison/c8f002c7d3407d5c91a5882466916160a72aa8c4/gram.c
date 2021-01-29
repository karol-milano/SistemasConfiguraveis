@@ -47,6 +47,40 @@ int glr_parser = 0;
 int pure_parser = 0;
 
 
+/*--------------------------------------------------------------.
+| Return true IFF the rule has a `number' smaller than NRULES.  |
+`--------------------------------------------------------------*/
+
+bool
+rule_useful_p (rule_t *r)
+{
+  return r->number < nrules;
+}
+
+
+/*-------------------------------------------------------------.
+| Return true IFF the rule has a `number' higher than NRULES.  |
+`-------------------------------------------------------------*/
+
+bool
+rule_useless_p (rule_t *r)
+{
+  return r->number >= nrules;
+}
+
+
+/*--------------------------------------------------------------------.
+| Return true IFF the rule is not flagged as useful *and* is useful.  |
+| In other words, it was discarded because of conflicts.              |
+`--------------------------------------------------------------------*/
+
+bool
+rule_never_reduced_p (rule_t *r)
+{
+  return !r->useful && r->number < nrules;
+}
+
+
 /*----------------------------------------------------------------.
 | Print this RULE's number and lhs on OUT.  If a PREVIOUS_LHS was |
 | already displayed (by a previous call for another rule), avoid  |
@@ -158,29 +192,34 @@ ritem_longest_rhs (void)
 }
 
 
-/*----------------------------------------------------------------.
-| Print the grammar's rules numbers from BEGIN (inclusive) to END |
-| (exclusive) on OUT under TITLE.                                 |
-`----------------------------------------------------------------*/
+/*-----------------------------------------------------------------.
+| Print the grammar's rules that match FILTER on OUT under TITLE.  |
+`-----------------------------------------------------------------*/
 
 void
 grammar_rules_partial_print (FILE *out, const char *title,
-			     rule_number_t begin, rule_number_t end)
+			     rule_filter_t filter)
 {
   int r;
+  bool first = TRUE;
   symbol_t *previous_lhs = NULL;
 
   /* rule # : LHS -> RHS */
-  fprintf (out, "%s\n\n", title);
-  for (r = begin; r < end; r++)
+  for (r = 0; r < nrules + nuseless_productions; r++)
     {
-      if (previous_lhs && previous_lhs != rules[r].lhs)
+      if (filter && !filter (&rules[r]))
+	continue;
+      if (first)
+	fprintf (out, "%s\n\n", title);
+      else if (previous_lhs && previous_lhs != rules[r].lhs)
 	fputc ('\n', out);
+      first = FALSE;
       rule_lhs_print (&rules[r], previous_lhs, out);
       rule_rhs_print (&rules[r], out);
       previous_lhs = rules[r].lhs;
     }
-  fputs ("\n\n", out);
+  if (!first)
+    fputs ("\n\n", out);
 }
 
 
@@ -191,7 +230,7 @@ grammar_rules_partial_print (FILE *out, const char *title,
 void
 grammar_rules_print (FILE *out)
 {
-  grammar_rules_partial_print (out, _("Grammar"), 0, nrules);
+  grammar_rules_partial_print (out, _("Grammar"), rule_useful_p);
 }
 
 
@@ -262,6 +301,27 @@ grammar_dump (FILE *out, const char *title)
 }
 
 
+/*------------------------------------------------------------------.
+| Report on STDERR the rules that are not flagged USEFUL, using the |
+| MESSAGE (which can be `useless rule' when invoked after grammar   |
+| reduction, or `never reduced' after conflicts were taken into     |
+| account).                                                         |
+`------------------------------------------------------------------*/
+
+void
+grammar_rules_never_reduced_report (const char *message)
+{
+  rule_number_t r;
+  for (r = 0; r < nrules ; ++r)
+    if (!rules[r].useful)
+      {
+	LOCATION_PRINT (stderr, rules[r].location);
+	fprintf (stderr, ": %s: %s: ",
+		 _("warning"), message);
+	rule_print (&rules[r], stderr);
+      }
+}
+
 void
 grammar_free (void)
 {
