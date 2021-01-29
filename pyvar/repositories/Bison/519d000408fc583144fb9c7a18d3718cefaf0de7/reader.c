@@ -252,7 +252,10 @@ static bool
 symbol_should_be_used (symbol_list const *s)
 {
   return (symbol_destructor_get (s->content.sym)
-	  || (s->midrule && s->midrule->used));
+	  || (s->midrule && s->midrule->used)
+	  || (s->midrule_parent_rule
+	      && symbol_list_n_get (s->midrule_parent_rule,
+                                    s->midrule_parent_rhs_index)->used));
 }
 
 /*----------------------------------------------------------------.
@@ -456,6 +459,20 @@ packgram (void)
 
   rules = xnmalloc (nrules, sizeof *rules);
 
+  /* Before invoking grammar_rule_check on any rule, make sure
+     all actions have already been scanned in order to set `used' flags.
+     Otherwise, checking that a midrule's $$ is set will not always work
+     properly because the midrule check must forward-reference the midrule's
+     parent rule.  */
+  while (p)
+    {
+      if (p->action)
+        p->action = translate_rule_action (p);
+      if (p)
+	p = p->next;
+    }
+
+  p = grammar;
   while (p)
     {
       int rule_length = 0;
@@ -472,14 +489,9 @@ packgram (void)
       rules[ruleno].precsym = NULL;
       rules[ruleno].location = p->location;
       rules[ruleno].useful = true;
-      rules[ruleno].action = p->action ? translate_rule_action (p) : NULL;
+      rules[ruleno].action = p->action;
       rules[ruleno].action_location = p->action_location;
 
-      /* If this rule contains midrules, rest assured that
-	 grammar_midrule_action inserted the midrules into grammar before this
-	 rule.  Thus, the midrule actions have already been scanned in order to
-	 set `used' flags for this rule's rhs, so grammar_rule_check will work
-	 properly.  */
       /* Don't check the generated rule 0.  It has no action, so some rhs
 	 symbols may appear unused, but the parsing algorithm ensures that
 	 %destructor's are invoked appropriately.  */
