@@ -387,6 +387,7 @@ grammar_midrule_action (void)
 void
 grammar_current_rule_prec_set (symbol *precsym, location loc)
 {
+  symbol_class_set (precsym, token_sym, loc, false);
   if (current_rule->ruleprec)
     complain_at (loc, _("only one %s allowed per rule"), "%prec");
   current_rule->ruleprec = precsym;
