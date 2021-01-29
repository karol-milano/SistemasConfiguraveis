@@ -59,7 +59,7 @@ void
 grammar_start_symbol_set (symbol *sym, location loc)
 {
   if (start_flag)
-    complain_at (loc, _("multiple %s declarations"), "%start");
+    complain_at (loc, complaint, _("multiple %s declarations"), "%start");
   else
     {
       start_flag = true;
@@ -128,11 +128,11 @@ record_merge_function_type (int merger, uniqstr type, location declaration_loc)
   aver (merge_function != NULL && merger_find == merger);
   if (merge_function->type != NULL && !UNIQSTR_EQ (merge_function->type, type))
     {
-      complain_at (declaration_loc,
-                   _("result type clash on merge function %s: <%s> != <%s>"),
-                   quote (merge_function->name), type, merge_function->type);
-      complain_at (merge_function->type_declaration_location,
-                   _("previous declaration"));
+      complain_at (declaration_loc, complaint,
+                _("result type clash on merge function %s: <%s> != <%s>"),
+                quote (merge_function->name), type, merge_function->type);
+      complain_at (merge_function->type_declaration_location, complaint,
+                _("previous declaration"));
     }
   merge_function->type = uniqstr_new (type);
   merge_function->type_declaration_location = declaration_loc;
@@ -197,9 +197,9 @@ assign_named_ref (symbol_list *p, named_ref *name)
 
   if (name->id == sym->tag)
     {
-      warn_at (name->loc,
-               _("duplicated symbol name for %s ignored"),
-               quote (sym->tag));
+      complain_at (name->loc, Wother,
+                   _("duplicated symbol name for %s ignored"),
+                   quote (sym->tag));
       named_ref_free (name);
     }
   else
@@ -242,7 +242,8 @@ grammar_current_rule_begin (symbol *lhs, location loc,
       ++nvars;
     }
   else if (lhs->class == token_sym)
-    complain_at (loc, _("rule given for %s, which is a token"), lhs->tag);
+    complain_at (loc, complaint, _("rule given for %s, which is a token"),
+                 lhs->tag);
 }
 
 
@@ -296,14 +297,14 @@ grammar_rule_check (const symbol_list *r)
           const char *rhs_type =
             first_rhs->type_name ? first_rhs->type_name : "";
           if (!UNIQSTR_EQ (lhs_type, rhs_type))
-            warn_at (r->location,
-                     _("type clash on default action: <%s> != <%s>"),
-                     lhs_type, rhs_type);
+            complain_at (r->location, Wother,
+                         _("type clash on default action: <%s> != <%s>"),
+                         lhs_type, rhs_type);
         }
       /* Warn if there is no default for $$ but we need one.  */
       else
-        warn_at (r->location,
-                 _("empty rule for typed nonterminal, and no action"));
+        complain_at (r->location, Wother,
+                     _("empty rule for typed nonterminal, and no action"));
     }
 
   /* Check that symbol values that should be used are in fact used.  */
@@ -318,12 +319,12 @@ grammar_rule_check (const symbol_list *r)
             /* The default action, $$ = $1, `uses' both.  */
             && (r->action_props.code || (n != 0 && n != 1)))
           {
-            void (*warn_at_ptr)(location, char const*, ...) =
-              midrule_warning ? midrule_value_at : warn_at;
+            int warn_flag =
+              midrule_warning ? Wmidrule_values : Wother;
             if (n)
-              warn_at_ptr (r->location, _("unused value: $%d"), n);
+              complain_at (r->location, warn_flag, _("unused value: $%d"), n);
             else
-              warn_at_ptr (r->location, _("unset value: $$"));
+              complain_at (r->location, warn_flag, _("unset value: $$"));
           }
       }
   }
@@ -334,8 +335,8 @@ grammar_rule_check (const symbol_list *r)
   if (r->ruleprec
       && r->ruleprec->tag[0] != '\'' && r->ruleprec->tag[0] != '"'
       && r->ruleprec->status != declared && !r->ruleprec->prec)
-    warn_at (r->location, _("token for %%prec is not defined: %s"),
-             r->ruleprec->tag);
+    complain_at (r->location, Wother,
+                 _("token for %%prec is not defined: %s"), r->ruleprec->tag);
 }
 
 
@@ -425,7 +426,7 @@ grammar_current_rule_prec_set (symbol *precsym, location loc)
      token.  */
   symbol_class_set (precsym, token_sym, loc, false);
   if (current_rule->ruleprec)
-    complain_at (loc, _("only one %s allowed per rule"), "%prec");
+    complain_at (loc, complaint, _("only one %s allowed per rule"), "%prec");
   current_rule->ruleprec = precsym;
 }
 
@@ -435,11 +436,13 @@ void
 grammar_current_rule_dprec_set (int dprec, location loc)
 {
   if (! glr_parser)
-    warn_at (loc, _("%s affects only GLR parsers"), "%dprec");
+    complain_at (loc, Wother, _("%s affects only GLR parsers"),
+                 "%dprec");
   if (dprec <= 0)
-    complain_at (loc, _("%s must be followed by positive number"), "%dprec");
+    complain_at (loc, complaint, _("%s must be followed by positive number"),
+                 "%dprec");
   else if (current_rule->dprec != 0)
-    complain_at (loc, _("only one %s allowed per rule"), "%dprec");
+    complain_at (loc, complaint, _("only one %s allowed per rule"), "%dprec");
   current_rule->dprec = dprec;
 }
 
@@ -450,9 +453,10 @@ void
 grammar_current_rule_merge_set (uniqstr name, location loc)
 {
   if (! glr_parser)
-    warn_at (loc, _("%s affects only GLR parsers"), "%merge");
+    complain_at (loc, Wother, _("%s affects only GLR parsers"),
+                 "%merge");
   if (current_rule->merger != 0)
-    complain_at (loc, _("only one %s allowed per rule"), "%merge");
+    complain_at (loc, complaint, _("only one %s allowed per rule"), "%merge");
   current_rule->merger = get_merge_function (name);
   current_rule->merger_declaration_location = loc;
 }
@@ -551,7 +555,7 @@ packgram (void)
           /* Don't allow rule_length == INT_MAX, since that might
              cause confusion with strtol if INT_MAX == LONG_MAX.  */
           if (rule_length == INT_MAX)
-              fatal_at (rules[ruleno].location, _("rule is too long"));
+            complain_at (rules[ruleno].location, fatal, _("rule is too long"));
 
           /* item_number = symbol_number.
              But the former needs to contain more: negative rule numbers. */
@@ -669,7 +673,7 @@ check_and_convert_grammar (void)
 {
   /* Grammar has been read.  Do some checking.  */
   if (nrules == 0)
-    fatal (_("no rules in the input grammar"));
+    complain (fatal, _("no rules in the input grammar"));
 
   /* If the user did not define her ENDTOKEN, do it now. */
   if (!endtoken)
