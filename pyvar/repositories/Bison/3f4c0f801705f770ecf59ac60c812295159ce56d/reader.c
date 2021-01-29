@@ -246,18 +246,22 @@ static void
 grammar_current_rule_check (void)
 {
   symbol_t *lhs = current_rule->sym;
+  char const *lhs_type = lhs->type_name;
   symbol_t *first_rhs = current_rule->next->sym;
 
   /* If there is an action, then there is nothing we can do: the user
-     is allowed to shoot in her foot.  */
+     is allowed to shoot herself in the foot.  */
   if (current_rule->action)
     return;
 
-  /* If $$ is being set in default way, report if any type mismatch.
-     */
+  /* Don't worry about the default action if $$ is untyped, since $$'s
+     value can't be used.  */
+  if (! lhs_type)
+    return;
+
+  /* If $$ is being set in default way, report if any type mismatch.  */
   if (first_rhs)
     {
-      const char *lhs_type = lhs->type_name       ? lhs->type_name       : "";
       const char *rhs_type = first_rhs->type_name ? first_rhs->type_name : "";
       if (strcmp (lhs_type, rhs_type))
 	complain_at (current_rule->location,
@@ -266,11 +270,8 @@ grammar_current_rule_check (void)
     }
   /* Warn if there is no default for $$ but we need one.  */
   else
-    {
-      if (lhs->type_name)
-	complain_at (current_rule->location,
-		     _("empty rule for typed nonterminal, and no action"));
-    }
+    complain_at (current_rule->location,
+		 _("empty rule for typed nonterminal, and no action"));
 }
 
 
