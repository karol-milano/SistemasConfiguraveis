@@ -42,14 +42,13 @@ static int start_flag = 0;
 int typed = 0;
 
 static symbol_list *
-symbol_list_new (symbol_t *sym)
+symbol_list_new (symbol_t *sym, location_t location)
 {
   symbol_list *res = XMALLOC (symbol_list, 1);
   res->next = NULL;
   res->sym = sym;
-  res->line = lineno;
+  res->location = location;
   res->action = NULL;
-  res->action_line = 0;
   res->ruleprec = NULL;
   return res;
 }
@@ -95,7 +94,7 @@ get_type_name (int n, symbol_list *rule)
 `-----------------------*/
 
 void
-grammar_start_symbol_set (symbol_t *s)
+grammar_start_symbol_set (symbol_t *s, location_t l)
 {
   if (start_flag)
     complain (_("multiple %s declarations"), "%start");
@@ -103,6 +102,7 @@ grammar_start_symbol_set (symbol_t *s)
     {
       start_flag = 1;
       startsymbol = s;
+      startsymbol_location = l;
     }
 }
 
@@ -197,9 +197,9 @@ symbol_list *grammar_end = NULL;
 
 /* Append S to the GRAMMAR. */
 void
-grammar_symbol_append (symbol_t *s)
+grammar_symbol_append (symbol_t *symbol, location_t location)
 {
-  symbol_list *p = symbol_list_new (s);
+  symbol_list *p = symbol_list_new (symbol, location);
 
   if (grammar_end)
     grammar_end->next = p;
@@ -209,20 +209,24 @@ grammar_symbol_append (symbol_t *s)
   grammar_end = p;
 }
 
-/* The rule currently being defined, and the previous rule.  Point to
-   the first symbol of each list: their lhs.  */
+/* The rule currently being defined, and the previous rule.
+   CURRENT_RULE points to the first LHS of the current rule, while
+   PREVIOUS_RULE_END points to the *end* of the previous rule (NULL).  */
 symbol_list *current_rule = NULL;
-symbol_list *previous_rule = NULL;
+symbol_list *previous_rule_end = NULL;
 
 
-/* Create a new rule for LHS in to the GRAMMAR. */
+/*----------------------------------------------.
+| Create a new rule for LHS in to the GRAMMAR.  |
+`----------------------------------------------*/
 
 void
-grammar_rule_begin (symbol_t *lhs)
+grammar_rule_begin (symbol_t *lhs, location_t location)
 {
   if (!start_flag)
     {
       startsymbol = lhs;
+      startsymbol_location = location;
       start_flag = 1;
     }
 
@@ -230,8 +234,8 @@ grammar_rule_begin (symbol_t *lhs)
   ++nrules;
   ++nritems;
 
-  previous_rule = grammar_end;
-  grammar_symbol_append (lhs);
+  previous_rule_end = grammar_end;
+  grammar_symbol_append (lhs, location);
   current_rule = grammar_end;
 
   /* Mark the rule's lhs as a nonterminal if not already so.  */
@@ -279,21 +283,26 @@ grammar_current_rule_check (void)
 }
 
 
-/* End the currently being grown rule. */
+/*-------------------------------------.
+| End the currently being grown rule.  |
+`-------------------------------------*/
 
 void
-grammar_rule_end (void)
+grammar_rule_end (location_t location)
 {
   /* Put an empty link in the list to mark the end of this rule  */
-  grammar_symbol_append (NULL);
+  grammar_symbol_append (NULL, grammar_end->location);
+  current_rule->location = location;
   grammar_current_rule_check ();
 }
 
 
-/* The previous action turns out the be a mid-rule action.  Attach it
-   to the current rule, i.e., create a dummy symbol, attach it this
-   mid-rule action, and append this dummy nonterminal to the current
-   rule.  */
+/*-------------------------------------------------------------------.
+| The previous action turns out the be a mid-rule action.  Attach it |
+| to the current rule, i.e., create a dummy symbol, attach it this   |
+| mid-rule action, and append this dummy nonterminal to the current  |
+| rule.                                                              |
+`-------------------------------------------------------------------*/
 
 void
 grammar_midrule_action (void)
@@ -302,35 +311,36 @@ grammar_midrule_action (void)
      give the new rule this number by inserting the new rule before
      it.  */
 
-  /* Make a dummy nonterminal, a gensym.  */
-  symbol_t *sdummy = gensym ();
-  symbol_list *midrule_action = symbol_list_new (sdummy);
+  /* Make a DUMMY nonterminal, whose location is that of the midrule
+     action.  Create the MIDRULE.  */
+  symbol_t *dummy = gensym ();
+  location_t dummy_location = current_rule->action_location;
+  symbol_list *midrule = symbol_list_new (dummy, dummy_location);
 
   /* Make a new rule, whose body is empty, before the current one, so
      that the action just read can belong to it.  */
   ++nrules;
   ++nritems;
-  /* Attach its lineno to that of the host rule.  */
-  midrule_action->line = current_rule->line;
-  /* Move the action from the host rule to this one.  */
-  midrule_action->action = current_rule->action;
-  midrule_action->action_line = current_rule->action_line;
+  /* Attach its location and actions to that of the DUMMY.  */
+  midrule->location = dummy_location;
+  midrule->action = current_rule->action;
+  midrule->action_location = dummy_location;
   current_rule->action = NULL;
 
-  if (previous_rule)
-    previous_rule->next = midrule_action;
+  if (previous_rule_end)
+    previous_rule_end->next = midrule;
   else
-    grammar = midrule_action;
+    grammar = midrule;
 
-  /* End of the rule. */
-  previous_rule = symbol_list_new (NULL);
-  previous_rule->next = current_rule;
+  /* End the dummy's rule.  */
+  previous_rule_end = symbol_list_new (NULL, dummy_location);
+  previous_rule_end->next = current_rule;
 
-  midrule_action->next = previous_rule;
+  midrule->next = previous_rule_end;
 
-  /* Insert the dummy generated by that rule into this rule.  */
-  ++nritems;
-  grammar_symbol_append (sdummy);
+  /* Insert the dummy nonterminal replacing the midrule action into
+     the current rule.  */
+  grammar_current_rule_symbol_append (dummy, dummy_location);
 }
 
 /* Set the precedence symbol of the current rule to PRECSYM. */
@@ -347,12 +357,12 @@ grammar_current_rule_prec_set (symbol_t *precsym)
    action as a mid-rule action.  */
 
 void
-grammar_current_rule_symbol_append (symbol_t *symbol)
+grammar_current_rule_symbol_append (symbol_t *symbol, location_t location)
 {
   if (current_rule->action)
     grammar_midrule_action ();
   ++nritems;
-  grammar_symbol_append (symbol);
+  grammar_symbol_append (symbol, location);
 }
 
 
@@ -360,12 +370,12 @@ grammar_current_rule_symbol_append (symbol_t *symbol)
    action as a mid-rule action.  */
 
 void
-grammar_current_rule_action_append (const char *action, int action_line)
+grammar_current_rule_action_append (const char *action, location_t location)
 {
   if (current_rule->action)
     grammar_midrule_action ();
   current_rule->action = action;
-  current_rule->action_line = action_line;
+  current_rule->action_location = location;
 }
 
 
@@ -395,10 +405,10 @@ packgram (void)
       rules[ruleno].number = ruleno;
       rules[ruleno].lhs = p->sym;
       rules[ruleno].rhs = ritem + itemno;
-      rules[ruleno].line = p->line;
+      rules[ruleno].location = p->location;
       rules[ruleno].useful = TRUE;
       rules[ruleno].action = p->action;
-      rules[ruleno].action_line = p->action_line;
+      rules[ruleno].action_location = p->action_location;
 
       p = p->next;
       while (p && p->sym)
@@ -500,11 +510,11 @@ reader (void)
 
      axiom: %start EOF.  */
   {
-    symbol_list *p = symbol_list_new (axiom);
-    p->line = grammar->line;
-    p->next = symbol_list_new (startsymbol);
-    p->next->next = symbol_list_new (eoftoken);
-    p->next->next->next = symbol_list_new (NULL);
+    symbol_list *p = symbol_list_new (axiom, empty_location);
+    p->location = grammar->location;
+    p->next = symbol_list_new (startsymbol, empty_location);
+    p->next->next = symbol_list_new (eoftoken, empty_location);
+    p->next->next->next = symbol_list_new (NULL, empty_location);
     p->next->next->next->next = grammar;
     nrules += 1;
     nritems += 3;
