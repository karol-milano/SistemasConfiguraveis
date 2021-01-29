@@ -459,11 +459,12 @@ packgram (void)
 
   rules = xnmalloc (nrules, sizeof *rules);
 
-  /* Before invoking grammar_rule_check on any rule, make sure
-     all actions have already been scanned in order to set `used' flags.
-     Otherwise, checking that a midrule's $$ is set will not always work
-     properly because the midrule check must forward-reference the midrule's
-     parent rule.  */
+  /* Before invoking grammar_rule_check on any rule, make sure all actions have
+     already been scanned in order to set `used' flags.  Otherwise, checking
+     that a midrule's $$ should be set will not always work properly because
+     the check must forward-reference the midrule's parent rule.  For the same
+     reason, all the `used' flags must be set before checking whether to remove
+     `$' from any midrule symbol name.  */
   while (p)
     {
       if (p->action)
@@ -492,6 +493,15 @@ packgram (void)
       rules[ruleno].action = p->action;
       rules[ruleno].action_location = p->action_location;
 
+      /* If the midrule's $$ is set or its $n is used, remove the `$' from the
+	 symbol name so that it's a user-defined symbol so that the default
+	 %destructor and %printer apply.  */
+      if (p->midrule_parent_rule
+          && (p->used
+	      || symbol_list_n_get (p->midrule_parent_rule,
+				    p->midrule_parent_rhs_index)->used))
+	p->content.sym->tag += 1;
+
       /* Don't check the generated rule 0.  It has no action, so some rhs
 	 symbols may appear unused, but the parsing algorithm ensures that
 	 %destructor's are invoked appropriately.  */
