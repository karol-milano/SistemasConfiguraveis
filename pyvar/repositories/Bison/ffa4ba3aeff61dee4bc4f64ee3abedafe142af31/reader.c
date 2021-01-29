@@ -293,7 +293,6 @@ grammar_current_rule_end (location loc)
   /* Put an empty link in the list to mark the end of this rule  */
   grammar_symbol_append (NULL, grammar_end->location);
   current_rule->location = loc;
-  grammar_rule_check (current_rule);
 }
 
 
@@ -326,10 +325,9 @@ grammar_midrule_action (void)
   midrule->action = current_rule->action;
   midrule->action_location = dummy_location;
   current_rule->action = NULL;
-  /* If $$ was used in the action, the LHS of the enclosing rule was
-     incorrectly flagged as used.  */
-  midrule->used = current_rule->used;
-  current_rule->used = false;
+  /* The action has not been translated yet, so $$ use hasn't been
+     detected yet.  */
+  midrule->used = false;
 
   if (previous_rule_end)
     previous_rule_end->next = midrule;
@@ -338,7 +336,6 @@ grammar_midrule_action (void)
 
   /* End the dummy's rule.  */
   midrule->next = symbol_list_new (NULL, dummy_location);
-  grammar_rule_check (midrule);
   midrule->next->next = current_rule;
 
   previous_rule_end = midrule->next;
@@ -347,6 +344,8 @@ grammar_midrule_action (void)
      the current rule.  Bind it to its dedicated rule.  */
   grammar_current_rule_symbol_append (dummy, dummy_location);
   grammar_end->midrule = midrule;
+  midrule->midrule_parent_rule = current_rule;
+  midrule->midrule_parent_rhs_index = symbol_list_length (current_rule->next);
 }
 
 /* Set the precedence symbol of the current rule to PRECSYM. */
@@ -405,9 +404,10 @@ grammar_current_rule_action_append (const char *action, location loc)
 {
   if (current_rule->action)
     grammar_midrule_action ();
+  /* After all symbol declarations have been parsed, packgram invokes
+     translate_rule_action.  */
   current_rule->action = action;
   current_rule->action_location = loc;
-  current_rule->action = translate_rule_action (current_rule);
 }
 
 
@@ -444,9 +444,16 @@ packgram (void)
       rules[ruleno].precsym = NULL;
       rules[ruleno].location = p->location;
       rules[ruleno].useful = true;
-      rules[ruleno].action = p->action;
+      rules[ruleno].action = p->action ? translate_rule_action (p) : NULL;
       rules[ruleno].action_location = p->action_location;
 
+      /* If this rule contains midrules, rest assured that
+        grammar_midrule_action inserted the midrules into grammar before this
+        rule.  Thus, the midrule actions have already been scanned in order to
+        set `used' flags for this rule's rhs, so grammar_rule_check will work
+        properly.  */
+      grammar_rule_check (p);
+
       for (p = p->next; p && p->sym; p = p->next)
 	{
 	  ++rule_length;
