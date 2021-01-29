@@ -333,7 +333,7 @@ grammar_rule_check (const symbol_list *r)
      it for char literals and strings, which are always tokens.  */
   if (r->ruleprec
       && r->ruleprec->tag[0] != '\'' && r->ruleprec->tag[0] != '"'
-      && !r->ruleprec->declared && !r->ruleprec->prec)
+      && r->ruleprec->status != declared && !r->ruleprec->prec)
     warn_at (r->location, _("token for %%prec is not defined: %s"),
              r->ruleprec->tag);
 }
