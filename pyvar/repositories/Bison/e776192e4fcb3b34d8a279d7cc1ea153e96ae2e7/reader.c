@@ -50,7 +50,7 @@ void
 grammar_start_symbol_set (symbol_t *s, location_t l)
 {
   if (start_flag)
-    complain (_("multiple %s declarations"), "%start");
+    complain_at (l, _("multiple %s declarations"), "%start");
   else
     {
       start_flag = 1;
@@ -200,7 +200,7 @@ grammar_rule_begin (symbol_t *lhs, location_t location)
       ++nvars;
     }
   else if (lhs->class == token_sym)
-    complain (_("rule given for %s, which is a token"), lhs->tag);
+    complain_at (location, _("rule given for %s, which is a token"), lhs->tag);
 }
 
 /* Check that the last rule (CURRENT_RULE) is properly defined.  For
@@ -224,14 +224,16 @@ grammar_current_rule_check (void)
       const char *lhs_type = lhs->type_name       ? lhs->type_name       : "";
       const char *rhs_type = first_rhs->type_name ? first_rhs->type_name : "";
       if (strcmp (lhs_type, rhs_type))
-	complain (_("type clash (`%s' `%s') on default action"),
-		  lhs_type, rhs_type);
+	complain_at (current_rule->location,
+		     _("type clash (`%s' `%s') on default action"),
+		     lhs_type, rhs_type);
     }
   /* Warn if there is no default for $$ but we need one.  */
   else
     {
       if (lhs->type_name)
-	complain (_("empty rule for typed nonterminal, and no action"));
+	complain_at (current_rule->location,
+		     _("empty rule for typed nonterminal, and no action"));
     }
 }
 
@@ -299,10 +301,10 @@ grammar_midrule_action (void)
 /* Set the precedence symbol of the current rule to PRECSYM. */
 
 void
-grammar_current_rule_prec_set (symbol_t *precsym)
+grammar_current_rule_prec_set (symbol_t *precsym, location_t location)
 {
   if (current_rule->ruleprec)
-    complain (_("two @prec's in a row"));
+    complain_at (location, _("two @prec's in a row"));
   current_rule->ruleprec = precsym;
 }
 
