@@ -62,7 +62,7 @@ grammar_start_symbol_set (symbol *sym, location loc)
     {
       start_flag = true;
       startsymbol = sym;
-      startsymbol_location = loc;
+      startsymbol_loc = loc;
     }
 }
 
@@ -131,12 +131,12 @@ record_merge_function_type (int merger, uniqstr type, location declaration_loc)
                        quote (merge_function->name), type,
                        merge_function->type);
       indent += SUB_INDENT;
-      complain_indent (&merge_function->type_declaration_location, complaint,
+      complain_indent (&merge_function->type_declaration_loc, complaint,
                        &indent,
                        _("previous declaration"));
     }
   merge_function->type = uniqstr_new (type);
-  merge_function->type_declaration_location = declaration_loc;
+  merge_function->type_declaration_loc = declaration_loc;
 }
 
 /*--------------------------------------.
@@ -408,11 +408,11 @@ grammar_midrule_action (void)
 
   /* Make a DUMMY nonterminal, whose location is that of the midrule
      action.  Create the MIDRULE.  */
-  location dummy_location = current_rule->action_props.location;
-  symbol *dummy = dummy_symbol_get (dummy_location);
+  location dummy_loc = current_rule->action_props.location;
+  symbol *dummy = dummy_symbol_get (dummy_loc);
   symbol_type_set(dummy,
                   current_rule->action_props.type, current_rule->action_props.location);
-  symbol_list *midrule = symbol_list_sym_new (dummy, dummy_location);
+  symbol_list *midrule = symbol_list_sym_new (dummy, dummy_loc);
 
   /* Remember named_ref of previous action. */
   named_ref *action_name = current_rule->action_props.named_ref;
@@ -422,7 +422,7 @@ grammar_midrule_action (void)
   ++nrules;
   ++nritems;
   /* Attach its location and actions to that of the DUMMY.  */
-  midrule->rhs_loc = dummy_location;
+  midrule->rhs_loc = dummy_loc;
   code_props_rule_action_init (&midrule->action_props,
                                current_rule->action_props.code,
                                current_rule->action_props.location,
@@ -443,14 +443,14 @@ grammar_midrule_action (void)
     grammar = midrule;
 
   /* End the dummy's rule.  */
-  midrule->next = symbol_list_sym_new (NULL, dummy_location);
+  midrule->next = symbol_list_sym_new (NULL, dummy_loc);
   midrule->next->next = current_rule;
 
   previous_rule_end = midrule->next;
 
   /* Insert the dummy nonterminal replacing the midrule action into
      the current rule.  Bind it to its dedicated rule.  */
-  grammar_current_rule_symbol_append (dummy, dummy_location,
+  grammar_current_rule_symbol_append (dummy, dummy_loc,
                                       action_name);
   grammar_end->midrule = midrule;
   midrule->midrule_parent_rule = current_rule;
@@ -509,11 +509,11 @@ grammar_current_rule_dprec_set (int dprec, location loc)
               "%dprec");
   else if (current_rule->dprec != 0)
     duplicate_rule_directive ("%dprec",
-                              current_rule->dprec_location, loc);
+                              current_rule->dprec_loc, loc);
   else
     {
       current_rule->dprec = dprec;
-      current_rule->dprec_location = loc;
+      current_rule->dprec_loc = loc;
     }
 }
 
@@ -528,11 +528,11 @@ grammar_current_rule_merge_set (uniqstr name, location loc)
               "%merge");
   if (current_rule->merger != 0)
     duplicate_rule_directive ("%merge",
-                              current_rule->merger_declaration_location, loc);
+                              current_rule->merger_declaration_loc, loc);
   else
     {
       current_rule->merger = get_merge_function (name);
-      current_rule->merger_declaration_location = loc;
+      current_rule->merger_declaration_loc = loc;
     }
 }
 
@@ -622,7 +622,7 @@ packgram (void)
     {
       symbol_list *lhs = p;
       record_merge_function_type (lhs->merger, lhs->content.sym->content->type_name,
-                                  lhs->merger_declaration_location);
+                                  lhs->merger_declaration_loc);
       /* If the midrule's $$ is set or its $n is used, remove the '$' from the
          symbol name so that it's a user-defined symbol so that the default
          %destructor and %printer apply.  */
@@ -650,7 +650,7 @@ packgram (void)
       rules[ruleno].location = lhs->rhs_loc;
       rules[ruleno].useful = true;
       rules[ruleno].action = lhs->action_props.code;
-      rules[ruleno].action_location = lhs->action_props.location;
+      rules[ruleno].action_loc = lhs->action_props.location;
       rules[ruleno].is_predicate = lhs->action_props.is_predicate;
       rules[ruleno].expected_sr_conflicts = lhs->expected_sr_conflicts;
       rules[ruleno].expected_rr_conflicts = lhs->expected_rr_conflicts;
@@ -713,18 +713,18 @@ reader (void)
   symbols_new ();
 
   /* Construct the accept symbol. */
-  accept = symbol_get ("$accept", empty_location);
+  accept = symbol_get ("$accept", empty_loc);
   accept->content->class = nterm_sym;
   accept->content->number = nvars++;
 
   /* Construct the error token */
-  errtoken = symbol_get ("error", empty_location);
+  errtoken = symbol_get ("error", empty_loc);
   errtoken->content->class = token_sym;
   errtoken->content->number = ntokens++;
 
   /* Construct a token that represents all undefined literal tokens.
      It is always token number 2.  */
-  undeftoken = symbol_get ("$undefined", empty_location);
+  undeftoken = symbol_get ("$undefined", empty_loc);
   undeftoken->content->class = token_sym;
   undeftoken->content->number = ntokens++;
 
@@ -801,7 +801,7 @@ check_and_convert_grammar (void)
   /* If the user did not define her ENDTOKEN, do it now. */
   if (!endtoken)
     {
-      endtoken = symbol_get ("$end", empty_location);
+      endtoken = symbol_get ("$end", empty_loc);
       endtoken->content->class = token_sym;
       endtoken->content->number = 0;
       /* Value specified by POSIX.  */
@@ -823,11 +823,11 @@ check_and_convert_grammar (void)
 
      $accept: %start $end.  */
   {
-    symbol_list *p = symbol_list_sym_new (accept, empty_location);
+    symbol_list *p = symbol_list_sym_new (accept, empty_loc);
     p->rhs_loc = grammar->rhs_loc;
-    p->next = symbol_list_sym_new (startsymbol, empty_location);
-    p->next->next = symbol_list_sym_new (endtoken, empty_location);
-    p->next->next->next = symbol_list_sym_new (NULL, empty_location);
+    p->next = symbol_list_sym_new (startsymbol, empty_loc);
+    p->next->next = symbol_list_sym_new (endtoken, empty_loc);
+    p->next->next->next = symbol_list_sym_new (NULL, empty_loc);
     p->next->next->next->next = grammar;
     nrules += 1;
     nritems += 3;
