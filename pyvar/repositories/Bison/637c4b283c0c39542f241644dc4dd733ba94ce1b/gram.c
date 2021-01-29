@@ -201,7 +201,7 @@ grammar_rules_partial_print (FILE *out, const char *title,
 			     rule_filter_t filter)
 {
   int r;
-  bool first = TRUE;
+  bool first = true;
   symbol_t *previous_lhs = NULL;
 
   /* rule # : LHS -> RHS */
@@ -213,7 +213,7 @@ grammar_rules_partial_print (FILE *out, const char *title,
 	fprintf (out, "%s\n\n", title);
       else if (previous_lhs && previous_lhs != rules[r].lhs)
 	fputc ('\n', out);
-      first = FALSE;
+      first = false;
       rule_lhs_print (&rules[r], previous_lhs, out);
       rule_rhs_print (&rules[r], out);
       previous_lhs = rules[r].lhs;
