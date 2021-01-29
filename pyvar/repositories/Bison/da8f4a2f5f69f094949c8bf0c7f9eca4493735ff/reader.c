@@ -351,6 +351,11 @@ grammar_rule_check (const symbol_list *r)
       && !r->ruleprec->content->prec)
     complain (&r->location, Wother,
               _("token for %%prec is not defined: %s"), r->ruleprec->tag);
+
+  /* Check that the (main) action was not typed.  */
+  if (r->action_props.type)
+    complain (&r->location, Wother,
+              _("only midrule actions can be typed: %s"), r->action_props.type);
 }
 
 
