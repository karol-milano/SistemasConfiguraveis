@@ -95,7 +95,7 @@ get_merge_function (uniqstr name)
       syms->next = xmalloc (sizeof syms->next[0]);
       syms->next->name = uniqstr_new (name);
       /* After all symbol type declarations have been parsed, packgram invokes
-	 record_merge_function_type to set the type.  */
+         record_merge_function_type to set the type.  */
       syms->next->type = NULL;
       syms->next->next = NULL;
       merge_functions = head.next;
@@ -130,17 +130,17 @@ record_merge_function_type (int merger, uniqstr type, location declaration_loc)
   if (merge_function->type != NULL && !UNIQSTR_EQ (merge_function->type, type))
     {
       complain_at (declaration_loc,
-		   _("result type clash on merge function `%s': <%s> != <%s>"),
-		   merge_function->name, type, merge_function->type);
+                   _("result type clash on merge function `%s': <%s> != <%s>"),
+                   merge_function->name, type, merge_function->type);
       complain_at (merge_function->type_declaration_location,
-		   _("previous declaration"));
+                   _("previous declaration"));
     }
   merge_function->type = uniqstr_new (type);
   merge_function->type_declaration_location = declaration_loc;
 }
 
 /*--------------------------------------.
-| Free all merge-function definitions.	|
+| Free all merge-function definitions.  |
 `--------------------------------------*/
 
 void
@@ -199,8 +199,8 @@ assign_named_ref (symbol_list *p, named_ref *name)
   if (name->id == sym->tag)
     {
       warn_at (name->loc,
-	       _("duplicated symbol name for %s ignored"),
-	       quote (sym->tag));
+               _("duplicated symbol name for %s ignored"),
+               quote (sym->tag));
       named_ref_free (name);
     }
   else
@@ -221,7 +221,7 @@ static symbol_list *previous_rule_end = NULL;
 
 void
 grammar_current_rule_begin (symbol *lhs, location loc,
-			    named_ref *lhs_name)
+                            named_ref *lhs_name)
 {
   symbol_list* p;
 
@@ -292,19 +292,19 @@ grammar_rule_check (const symbol_list *r)
       symbol *first_rhs = r->next->content.sym;
       /* If $$ is being set in default way, report if any type mismatch.  */
       if (first_rhs)
-	{
-	  char const *lhs_type = r->content.sym->type_name;
-	  const char *rhs_type =
-	    first_rhs->type_name ? first_rhs->type_name : "";
-	  if (!UNIQSTR_EQ (lhs_type, rhs_type))
-	    warn_at (r->location,
-		     _("type clash on default action: <%s> != <%s>"),
-		     lhs_type, rhs_type);
-	}
+        {
+          char const *lhs_type = r->content.sym->type_name;
+          const char *rhs_type =
+            first_rhs->type_name ? first_rhs->type_name : "";
+          if (!UNIQSTR_EQ (lhs_type, rhs_type))
+            warn_at (r->location,
+                     _("type clash on default action: <%s> != <%s>"),
+                     lhs_type, rhs_type);
+        }
       /* Warn if there is no default for $$ but we need one.  */
       else
-	warn_at (r->location,
-		 _("empty rule for typed nonterminal, and no action"));
+        warn_at (r->location,
+                 _("empty rule for typed nonterminal, and no action"));
     }
 
   /* Check that symbol values that should be used are in fact used.  */
@@ -386,7 +386,7 @@ grammar_midrule_action (void)
                                current_rule->action_props.code,
                                current_rule->action_props.location,
                                midrule, 0,
-			       current_rule->action_props.is_predicate);
+                               current_rule->action_props.is_predicate);
   code_props_none_init (&current_rule->action_props);
 
   if (previous_rule_end)
@@ -463,7 +463,7 @@ grammar_current_rule_merge_set (uniqstr name, location loc)
 
 void
 grammar_current_rule_symbol_append (symbol *sym, location loc,
-				    named_ref *name)
+                                    named_ref *name)
 {
   symbol_list *p;
   if (current_rule->action_props.code)
@@ -477,7 +477,7 @@ grammar_current_rule_symbol_append (symbol *sym, location loc,
 
 void
 grammar_current_rule_action_append (const char *action, location loc,
-				    named_ref *name, bool is_predicate)
+                                    named_ref *name, bool is_predicate)
 {
   if (current_rule->action_props.code)
     grammar_midrule_action ();
@@ -512,7 +512,7 @@ packgram (void)
       int rule_length = 0;
       symbol *ruleprec = p->ruleprec;
       record_merge_function_type (p->merger, p->content.sym->type_name,
-				  p->merger_declaration_location);
+                                  p->merger_declaration_location);
       rules[ruleno].user_number = ruleno;
       rules[ruleno].number = ruleno;
       rules[ruleno].lhs = p->content.sym;
@@ -528,47 +528,47 @@ packgram (void)
       rules[ruleno].is_predicate = p->action_props.is_predicate;
 
       /* If the midrule's $$ is set or its $n is used, remove the `$' from the
-	 symbol name so that it's a user-defined symbol so that the default
-	 %destructor and %printer apply.  */
+         symbol name so that it's a user-defined symbol so that the default
+         %destructor and %printer apply.  */
       if (p->midrule_parent_rule
           && (p->action_props.is_value_used
-	      || symbol_list_n_get (p->midrule_parent_rule,
-				    p->midrule_parent_rhs_index)
+              || symbol_list_n_get (p->midrule_parent_rule,
+                                    p->midrule_parent_rhs_index)
                    ->action_props.is_value_used))
-	p->content.sym->tag += 1;
+        p->content.sym->tag += 1;
 
       /* Don't check the generated rule 0.  It has no action, so some rhs
-	 symbols may appear unused, but the parsing algorithm ensures that
-	 %destructor's are invoked appropriately.  */
+         symbols may appear unused, but the parsing algorithm ensures that
+         %destructor's are invoked appropriately.  */
       if (p != grammar)
-	grammar_rule_check (p);
+        grammar_rule_check (p);
 
       for (p = p->next; p && p->content.sym; p = p->next)
-	{
-	  ++rule_length;
+        {
+          ++rule_length;
 
-	  /* Don't allow rule_length == INT_MAX, since that might
-	     cause confusion with strtol if INT_MAX == LONG_MAX.  */
-	  if (rule_length == INT_MAX)
-	      fatal_at (rules[ruleno].location, _("rule is too long"));
+          /* Don't allow rule_length == INT_MAX, since that might
+             cause confusion with strtol if INT_MAX == LONG_MAX.  */
+          if (rule_length == INT_MAX)
+              fatal_at (rules[ruleno].location, _("rule is too long"));
 
-	  /* item_number = symbol_number.
-	     But the former needs to contain more: negative rule numbers. */
-	  ritem[itemno++] =
+          /* item_number = symbol_number.
+             But the former needs to contain more: negative rule numbers. */
+          ritem[itemno++] =
             symbol_number_as_item_number (p->content.sym->number);
-	  /* A rule gets by default the precedence and associativity
-	     of its last token.  */
-	  if (p->content.sym->class == token_sym && default_prec)
-	    rules[ruleno].prec = p->content.sym;
-	}
+          /* A rule gets by default the precedence and associativity
+             of its last token.  */
+          if (p->content.sym->class == token_sym && default_prec)
+            rules[ruleno].prec = p->content.sym;
+        }
 
       /* If this rule has a %prec,
          the specified symbol's precedence replaces the default.  */
       if (ruleprec)
-	{
-	  rules[ruleno].precsym = ruleprec;
-	  rules[ruleno].prec = ruleprec;
-	}
+        {
+          rules[ruleno].precsym = ruleprec;
+          rules[ruleno].prec = ruleprec;
+        }
       /* An item ends by the rule number (negated).  */
       ritem[itemno++] = rule_number_as_item_number (ruleno);
       aver (itemno < ITEM_NUMBER_MAX);
@@ -576,7 +576,7 @@ packgram (void)
       aver (ruleno < RULE_NUMBER_MAX);
 
       if (p)
-	p = p->next;
+        p = p->next;
     }
 
   aver (itemno == nritems);
@@ -660,7 +660,7 @@ prepare_percent_define_front_end_variables (void)
 
 /*-------------------------------------------------------------.
 | Check the grammar that has just been read, and convert it to |
-| internal form.					       |
+| internal form.                                               |
 `-------------------------------------------------------------*/
 
 static void
