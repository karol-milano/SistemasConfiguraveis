@@ -295,7 +295,7 @@ grammar_rule_check_and_complete (symbol_list *r)
           char const *rhs_type =
             first_rhs->content->type_name ? first_rhs->content->type_name : "";
           if (!UNIQSTR_EQ (lhs_type, rhs_type))
-            complain (&r->location, Wother,
+            complain (&r->rhs_loc, Wother,
                       _("type clash on default action: <%s> != <%s>"),
                       lhs_type, rhs_type);
           else
@@ -308,7 +308,7 @@ grammar_rule_check_and_complete (symbol_list *r)
               if (is_cxx)
                 {
                   code_props_rule_action_init (&r->action_props, "{ $$ = $1; }",
-                                               r->location, r,
+                                               r->rhs_loc, r,
                                                /* name */ NULL,
                                                /* type */ NULL,
                                                /* is_predicate */ false);
@@ -318,7 +318,7 @@ grammar_rule_check_and_complete (symbol_list *r)
         }
       /* Warn if there is no default for $$ but we need one.  */
       else
-        complain (&r->location, Wother,
+        complain (&r->rhs_loc, Wother,
                   _("empty rule for typed nonterminal, and no action"));
     }
 
@@ -335,9 +335,9 @@ grammar_rule_check_and_complete (symbol_list *r)
           {
             warnings warn_flag = midrule_warning ? Wmidrule_values : Wother;
             if (n)
-              complain (&l->location, warn_flag, _("unused value: $%d"), n);
+              complain (&l->sym_loc, warn_flag, _("unused value: $%d"), n);
             else
-              complain (&l->location, warn_flag, _("unset value: $$"));
+              complain (&l->rhs_loc, warn_flag, _("unset value: $$"));
           }
       }
   }
@@ -357,9 +357,9 @@ grammar_rule_check_and_complete (symbol_list *r)
       && !r->percent_empty_loc.start.file
       && warning_is_enabled (Wempty_rule))
     {
-      complain (&r->location, Wempty_rule,
+      complain (&r->rhs_loc, Wempty_rule,
                 _("empty rule without %%empty"));
-      fixits_register (&r->location, " %empty ");
+      fixits_register (&r->rhs_loc, " %empty ");
     }
 
   /* See comments in grammar_current_rule_prec_set for how POSIX
@@ -369,12 +369,12 @@ grammar_rule_check_and_complete (symbol_list *r)
       && r->ruleprec->tag[0] != '\'' && r->ruleprec->tag[0] != '"'
       && r->ruleprec->content->status != declared
       && !r->ruleprec->content->prec)
-    complain (&r->location, Wother,
+    complain (&r->rhs_loc, Wother,
               _("token for %%prec is not defined: %s"), r->ruleprec->tag);
 
   /* Check that the (main) action was not typed.  */
   if (r->action_props.type)
-    complain (&r->location, Wother,
+    complain (&r->rhs_loc, Wother,
               _("only midrule actions can be typed: %s"), r->action_props.type);
 }
 
@@ -387,8 +387,8 @@ void
 grammar_current_rule_end (location loc)
 {
   /* Put an empty link in the list to mark the end of this rule  */
-  grammar_symbol_append (NULL, grammar_end->location);
-  current_rule->location = loc;
+  grammar_symbol_append (NULL, grammar_end->rhs_loc);
+  current_rule->rhs_loc = loc;
 }
 
 
@@ -422,7 +422,7 @@ grammar_midrule_action (void)
   ++nrules;
   ++nritems;
   /* Attach its location and actions to that of the DUMMY.  */
-  midrule->location = dummy_location;
+  midrule->rhs_loc = dummy_location;
   code_props_rule_action_init (&midrule->action_props,
                                current_rule->action_props.code,
                                current_rule->action_props.location,
@@ -647,7 +647,7 @@ packgram (void)
       rules[ruleno].dprec = lhs->dprec;
       rules[ruleno].merger = lhs->merger;
       rules[ruleno].precsym = NULL;
-      rules[ruleno].location = lhs->location;
+      rules[ruleno].location = lhs->rhs_loc;
       rules[ruleno].useful = true;
       rules[ruleno].action = lhs->action_props.code;
       rules[ruleno].action_location = lhs->action_props.location;
@@ -824,7 +824,7 @@ check_and_convert_grammar (void)
      $accept: %start $end.  */
   {
     symbol_list *p = symbol_list_sym_new (accept, empty_location);
-    p->location = grammar->location;
+    p->rhs_loc = grammar->rhs_loc;
     p->next = symbol_list_sym_new (startsymbol, empty_location);
     p->next->next = symbol_list_sym_new (endtoken, empty_location);
     p->next->next->next = symbol_list_sym_new (NULL, empty_location);
