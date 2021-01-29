@@ -155,6 +155,13 @@ rule_rhs_print_xml (rule const *r, FILE *out, int level)
     }
 }
 
+void
+rule_print (rule const *r, rule const *prev_rule, FILE *out)
+{
+  rule_lhs_print (r, prev_rule ? prev_rule->lhs : NULL, out);
+  rule_rhs_print (r, out);
+}
+
 void
 ritem_print (FILE *out)
 {
@@ -186,7 +193,7 @@ grammar_rules_partial_print (FILE *out, const char *title,
                              rule_filter filter)
 {
   bool first = true;
-  sym_content *previous_lhs = NULL;
+  rule *previous_rule = NULL;
 
   /* rule # : LHS -> RHS */
   for (rule_number r = 0; r < nrules + nuseless_productions; r++)
@@ -195,13 +202,12 @@ grammar_rules_partial_print (FILE *out, const char *title,
         continue;
       if (first)
         fprintf (out, "%s\n\n", title);
-      else if (previous_lhs && previous_lhs != rules[r].lhs)
+      else if (previous_rule && previous_rule->lhs != rules[r].lhs)
         fputc ('\n', out);
       first = false;
-      rule_lhs_print (&rules[r], previous_lhs, out);
-      rule_rhs_print (&rules[r], out);
+      rule_print (&rules[r], previous_rule, out);
       fputc ('\n', out);
-      previous_lhs = rules[r].lhs;
+      previous_rule = &rules[r];
     }
   if (!first)
     fputs ("\n\n", out);
