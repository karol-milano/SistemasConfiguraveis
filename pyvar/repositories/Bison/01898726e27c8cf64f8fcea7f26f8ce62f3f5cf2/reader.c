@@ -275,13 +275,14 @@ symbol_should_be_used (symbol_list const *s, bool *midrule_warning)
   return false;
 }
 
-/*----------------------------------------------------------------.
-| Check that the rule R is properly defined.  For instance, there |
-| should be no type clash on the default action.                  |
-`----------------------------------------------------------------*/
+/*-----------------------------------------------------------------.
+| Check that the rule R is properly defined.  For instance, there  |
+| should be no type clash on the default action.  Possibly install |
+| the default action.                                              |
+`-----------------------------------------------------------------*/
 
 static void
-grammar_rule_check (const symbol_list *r)
+grammar_rule_check_and_complete (symbol_list *r)
 {
   /* Type check.
 
@@ -303,6 +304,16 @@ grammar_rule_check (const symbol_list *r)
             complain (&r->location, Wother,
                       _("type clash on default action: <%s> != <%s>"),
                       lhs_type, rhs_type);
+          else
+            {
+              /* Install the default action.  */
+              code_props_rule_action_init (&r->action_props, "{ $$ = $1; }",
+                                           r->location, r,
+                                           /* name */ NULL,
+                                           /* type */ NULL,
+                                           /* is_predicate */ false);
+              code_props_translate_code (&r->action_props);
+            }
         }
       /* Warn if there is no default for $$ but we need one.  */
       else
@@ -439,14 +450,14 @@ grammar_current_rule_prec_set (symbol *precsym, location loc)
 {
   /* POSIX says that any identifier is a nonterminal if it does not
      appear on the LHS of a grammar rule and is not defined by %token
-     or by one of the directives that assigns precedence to a token.  We
-     ignore this here because the only kind of identifier that POSIX
-     allows to follow a %prec is a token and because assuming it's a
-     token now can produce more logical error messages.  Nevertheless,
-     grammar_rule_check does obey what we believe is the real intent of
-     POSIX here: that an error be reported for any identifier that
-     appears after %prec but that is not defined separately as a
-     token.  */
+     or by one of the directives that assigns precedence to a token.
+     We ignore this here because the only kind of identifier that
+     POSIX allows to follow a %prec is a token and because assuming
+     it's a token now can produce more logical error messages.
+     Nevertheless, grammar_rule_check_and_complete does obey what we
+     believe is the real intent of POSIX here: that an error be
+     reported for any identifier that appears after %prec but that is
+     not defined separately as a token.  */
   symbol_class_set (precsym, token_sym, loc, false);
   if (current_rule->ruleprec)
     duplicate_directive ("%prec",
@@ -593,7 +604,7 @@ packgram (void)
          symbols may appear unused, but the parsing algorithm ensures that
          %destructor's are invoked appropriately.  */
       if (p != grammar)
-        grammar_rule_check (p);
+        grammar_rule_check_and_complete (p);
 
       rules[ruleno].user_number = ruleno;
       rules[ruleno].number = ruleno;
@@ -799,12 +810,13 @@ check_and_convert_grammar (void)
      symbols_pack above) so that token types are set correctly before the rule
      action type checking.
 
-     Before invoking grammar_rule_check (in packgram below) on any rule, make
-     sure all actions have already been scanned in order to set 'used' flags.
-     Otherwise, checking that a midrule's $$ should be set will not always work
-     properly because the check must forward-reference the midrule's parent
-     rule.  For the same reason, all the 'used' flags must be set before
-     checking whether to remove '$' from any midrule symbol name (also in
+     Before invoking grammar_rule_check_and_complete (in packgram
+     below) on any rule, make sure all actions have already been
+     scanned in order to set 'used' flags.  Otherwise, checking that a
+     midrule's $$ should be set will not always work properly because
+     the check must forward-reference the midrule's parent rule.  For
+     the same reason, all the 'used' flags must be set before checking
+     whether to remove '$' from any midrule symbol name (also in
      packgram).  */
   for (symbol_list *sym = grammar; sym; sym = sym->next)
     code_props_translate_code (&sym->action_props);
