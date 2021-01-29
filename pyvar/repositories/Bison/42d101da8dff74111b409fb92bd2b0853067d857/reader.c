@@ -451,6 +451,10 @@ grammar_current_rule_prec_set (symbol *precsym, location loc)
 void
 grammar_current_rule_empty_set (location loc)
 {
+  /* If %empty is used and -Wno-empty-rule is not, then enable
+     -Wempty-rule.  */
+  if (warning_is_unset (Wempty_rule))
+    warning_argmatch ("empty-rule", 0, 0);
   if (current_rule->percent_empty_loc.start.file)
     complain (&loc, complaint, _("only one %s allowed per rule"), "%empty");
   else
