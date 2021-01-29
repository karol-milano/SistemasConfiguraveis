@@ -327,8 +327,8 @@ grammar_rule_check (const symbol_list *r)
   if (r->ruleprec
       && r->ruleprec->tag[0] != '\'' && r->ruleprec->tag[0] != '"'
       && !r->ruleprec->declared && !r->ruleprec->prec)
-    complain_at (r->location, _("token for %%prec is not defined: %s"),
-                 r->ruleprec->tag);
+    warn_at (r->location, _("token for %%prec is not defined: %s"),
+             r->ruleprec->tag);
 }
 
 
