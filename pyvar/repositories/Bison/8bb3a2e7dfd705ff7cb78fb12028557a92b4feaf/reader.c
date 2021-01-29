@@ -320,6 +320,15 @@ grammar_rule_check (const symbol_list *r)
 	    warn_at (r->location, _("unset value: $$"));
 	}
   }
+
+  /* See comments in grammar_current_rule_prec_set for how POSIX
+     mandates this complaint.  It's only for identifiers, so skip
+     it for char literals and strings, which are always tokens.  */
+  if (r->ruleprec
+      && r->ruleprec->tag[0] != '\'' && r->ruleprec->tag[0] != '"'
+      && !r->ruleprec->declared && !r->ruleprec->prec)
+    warn_at (r->location, _("token for %%prec is not defined: %s"),
+             r->ruleprec->tag);
 }
 
 
@@ -396,6 +405,16 @@ grammar_midrule_action (void)
 void
 grammar_current_rule_prec_set (symbol *precsym, location loc)
 {
+  /* POSIX says that any identifier is a nonterminal if it does not
+     appear on the LHS of a grammar rule and is not defined by %token
+     or by one of the directives that assigns precedence to a token.  We
+     ignore this here because the only kind of identifier that POSIX
+     allows to follow a %prec is a token and because assuming it's a
+     token now can produce more logical error messages.  Nevertheless,
+     grammar_rule_check does obey what we believe is the real intent of
+     POSIX here: that an error be reported for any identifier that
+     appears after %prec but that is not defined separately as a
+     token.  */
   symbol_class_set (precsym, token_sym, loc, false);
   if (current_rule->ruleprec)
     complain_at (loc, _("only one %s allowed per rule"), "%prec");
