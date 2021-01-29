@@ -196,7 +196,7 @@ static symbol_list *grammar_end = NULL;
 static void
 grammar_symbol_append (symbol *sym, location loc)
 {
-  symbol_list *p = symbol_list_new (sym, loc);
+  symbol_list *p = symbol_list_sym_new (sym, loc);
 
   if (grammar_end)
     grammar_end->next = p;
@@ -252,7 +252,7 @@ grammar_current_rule_begin (symbol *lhs, location loc)
 static bool
 symbol_should_be_used (symbol_list const *s)
 {
-  return (symbol_destructor_get (s->sym)
+  return (symbol_destructor_get (s->content.sym)
 	  || (s->midrule && s->midrule->used));
 }
 
@@ -271,13 +271,13 @@ grammar_rule_check (const symbol_list *r)
 
      Don't worry about the default action if $$ is untyped, since $$'s
      value can't be used.  */
-  if (!r->action && r->sym->type_name)
+  if (!r->action && r->content.sym->type_name)
     {
-      symbol *first_rhs = r->next->sym;
+      symbol *first_rhs = r->next->content.sym;
       /* If $$ is being set in default way, report if any type mismatch.  */
       if (first_rhs)
 	{
-	  char const *lhs_type = r->sym->type_name;
+	  char const *lhs_type = r->content.sym->type_name;
 	  const char *rhs_type =
 	    first_rhs->type_name ? first_rhs->type_name : "";
 	  if (!UNIQSTR_EQ (lhs_type, rhs_type))
@@ -295,7 +295,7 @@ grammar_rule_check (const symbol_list *r)
   {
     symbol_list const *l = r;
     int n = 0;
-    for (; l && l->sym; l = l->next, ++n)
+    for (; l && l->content.sym; l = l->next, ++n)
       if (! (l->used
 	     || !symbol_should_be_used (l)
 	     /* The default action, $$ = $1, `uses' both.  */
@@ -341,7 +341,7 @@ grammar_midrule_action (void)
      action.  Create the MIDRULE.  */
   location dummy_location = current_rule->action_location;
   symbol *dummy = dummy_symbol_get (dummy_location);
-  symbol_list *midrule = symbol_list_new (dummy, dummy_location);
+  symbol_list *midrule = symbol_list_sym_new (dummy, dummy_location);
 
   /* Make a new rule, whose body is empty, before the current one, so
      that the action just read can belong to it.  */
@@ -362,7 +362,7 @@ grammar_midrule_action (void)
     grammar = midrule;
 
   /* End the dummy's rule.  */
-  midrule->next = symbol_list_new (NULL, dummy_location);
+  midrule->next = symbol_list_sym_new (NULL, dummy_location);
   midrule->next->next = current_rule;
 
   previous_rule_end = midrule->next;
@@ -461,11 +461,11 @@ packgram (void)
     {
       int rule_length = 0;
       symbol *ruleprec = p->ruleprec;
-      record_merge_function_type (p->merger, p->sym->type_name,
+      record_merge_function_type (p->merger, p->content.sym->type_name,
 				  p->merger_declaration_location);
       rules[ruleno].user_number = ruleno;
       rules[ruleno].number = ruleno;
-      rules[ruleno].lhs = p->sym;
+      rules[ruleno].lhs = p->content.sym;
       rules[ruleno].rhs = ritem + itemno;
       rules[ruleno].prec = NULL;
       rules[ruleno].dprec = p->dprec;
@@ -487,7 +487,7 @@ packgram (void)
       if (p != grammar)
 	grammar_rule_check (p);
 
-      for (p = p->next; p && p->sym; p = p->next)
+      for (p = p->next; p && p->content.sym; p = p->next)
 	{
 	  ++rule_length;
 
@@ -498,11 +498,12 @@ packgram (void)
 
 	  /* item_number = symbol_number.
 	     But the former needs to contain more: negative rule numbers. */
-	  ritem[itemno++] = symbol_number_as_item_number (p->sym->number);
+	  ritem[itemno++] =
+            symbol_number_as_item_number (p->content.sym->number);
 	  /* A rule gets by default the precedence and associativity
 	     of its last token.  */
-	  if (p->sym->class == token_sym && default_prec)
-	    rules[ruleno].prec = p->sym;
+	  if (p->content.sym->class == token_sym && default_prec)
+	    rules[ruleno].prec = p->content.sym;
 	}
 
       /* If this rule has a %prec,
@@ -605,16 +606,17 @@ check_and_convert_grammar (void)
     {
       symbol_list *node;
       for (node = grammar;
-           node != NULL && symbol_is_dummy (node->sym);
+           node != NULL && symbol_is_dummy (node->content.sym);
            node = node->next)
         {
           for (node = node->next;
-               node != NULL && node->sym != NULL;
+               node != NULL && node->content.sym != NULL;
                node = node->next)
             ;
         }
       assert (node != NULL);
-      grammar_start_symbol_set (node->sym, node->sym->location);
+      grammar_start_symbol_set (node->content.sym,
+                                node->content.sym->location);
     }
 
   /* Insert the initial rule, whose line is that of the first rule
@@ -622,11 +624,11 @@ check_and_convert_grammar (void)
 
      accept: %start EOF.  */
   {
-    symbol_list *p = symbol_list_new (accept, empty_location);
+    symbol_list *p = symbol_list_sym_new (accept, empty_location);
     p->location = grammar->location;
-    p->next = symbol_list_new (startsymbol, empty_location);
-    p->next->next = symbol_list_new (endtoken, empty_location);
-    p->next->next->next = symbol_list_new (NULL, empty_location);
+    p->next = symbol_list_sym_new (startsymbol, empty_location);
+    p->next->next = symbol_list_sym_new (endtoken, empty_location);
+    p->next->next->next = symbol_list_sym_new (NULL, empty_location);
     p->next->next->next->next = grammar;
     nrules += 1;
     nritems += 3;
