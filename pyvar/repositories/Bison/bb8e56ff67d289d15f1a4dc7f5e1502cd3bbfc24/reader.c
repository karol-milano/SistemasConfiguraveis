@@ -59,7 +59,7 @@ void
 grammar_start_symbol_set (symbol *sym, location loc)
 {
   if (start_flag)
-    complain_at (loc, complaint, _("multiple %s declarations"), "%start");
+    complain (&loc, complaint, _("multiple %s declarations"), "%start");
   else
     {
       start_flag = true;
@@ -202,9 +202,9 @@ assign_named_ref (symbol_list *p, named_ref *name)
 
   if (name->id == sym->tag)
     {
-      complain_at (name->loc, Wother,
-                   _("duplicated symbol name for %s ignored"),
-                   quote (sym->tag));
+      complain (&name->loc, Wother,
+                _("duplicated symbol name for %s ignored"),
+                quote (sym->tag));
       named_ref_free (name);
     }
   else
@@ -247,8 +247,8 @@ grammar_current_rule_begin (symbol *lhs, location loc,
       ++nvars;
     }
   else if (lhs->class == token_sym)
-    complain_at (loc, complaint, _("rule given for %s, which is a token"),
-                 lhs->tag);
+    complain (&loc, complaint, _("rule given for %s, which is a token"),
+              lhs->tag);
 }
 
 
@@ -302,14 +302,14 @@ grammar_rule_check (const symbol_list *r)
           const char *rhs_type =
             first_rhs->type_name ? first_rhs->type_name : "";
           if (!UNIQSTR_EQ (lhs_type, rhs_type))
-            complain_at (r->location, Wother,
-                         _("type clash on default action: <%s> != <%s>"),
-                         lhs_type, rhs_type);
+            complain (&r->location, Wother,
+                      _("type clash on default action: <%s> != <%s>"),
+                      lhs_type, rhs_type);
         }
       /* Warn if there is no default for $$ but we need one.  */
       else
-        complain_at (r->location, Wother,
-                     _("empty rule for typed nonterminal, and no action"));
+        complain (&r->location, Wother,
+                  _("empty rule for typed nonterminal, and no action"));
     }
 
   /* Check that symbol values that should be used are in fact used.  */
@@ -326,9 +326,9 @@ grammar_rule_check (const symbol_list *r)
           {
             warnings warn_flag = midrule_warning ? Wmidrule_values : Wother;
             if (n)
-              complain_at (r->location, warn_flag, _("unused value: $%d"), n);
+              complain (&r->location, warn_flag, _("unused value: $%d"), n);
             else
-              complain_at (r->location, warn_flag, _("unset value: $$"));
+              complain (&r->location, warn_flag, _("unset value: $$"));
           }
       }
   }
@@ -339,8 +339,8 @@ grammar_rule_check (const symbol_list *r)
   if (r->ruleprec
       && r->ruleprec->tag[0] != '\'' && r->ruleprec->tag[0] != '"'
       && r->ruleprec->status != declared && !r->ruleprec->prec)
-    complain_at (r->location, Wother,
-                 _("token for %%prec is not defined: %s"), r->ruleprec->tag);
+    complain (&r->location, Wother,
+              _("token for %%prec is not defined: %s"), r->ruleprec->tag);
 }
 
 
@@ -430,7 +430,7 @@ grammar_current_rule_prec_set (symbol *precsym, location loc)
      token.  */
   symbol_class_set (precsym, token_sym, loc, false);
   if (current_rule->ruleprec)
-    complain_at (loc, complaint, _("only one %s allowed per rule"), "%prec");
+    complain (&loc, complaint, _("only one %s allowed per rule"), "%prec");
   current_rule->ruleprec = precsym;
 }
 
@@ -440,13 +440,13 @@ void
 grammar_current_rule_dprec_set (int dprec, location loc)
 {
   if (! glr_parser)
-    complain_at (loc, Wother, _("%s affects only GLR parsers"),
-                 "%dprec");
+    complain (&loc, Wother, _("%s affects only GLR parsers"),
+              "%dprec");
   if (dprec <= 0)
-    complain_at (loc, complaint, _("%s must be followed by positive number"),
-                 "%dprec");
+    complain (&loc, complaint, _("%s must be followed by positive number"),
+              "%dprec");
   else if (current_rule->dprec != 0)
-    complain_at (loc, complaint, _("only one %s allowed per rule"), "%dprec");
+    complain (&loc, complaint, _("only one %s allowed per rule"), "%dprec");
   current_rule->dprec = dprec;
 }
 
@@ -457,10 +457,10 @@ void
 grammar_current_rule_merge_set (uniqstr name, location loc)
 {
   if (! glr_parser)
-    complain_at (loc, Wother, _("%s affects only GLR parsers"),
-                 "%merge");
+    complain (&loc, Wother, _("%s affects only GLR parsers"),
+              "%merge");
   if (current_rule->merger != 0)
-    complain_at (loc, complaint, _("only one %s allowed per rule"), "%merge");
+    complain (&loc, complaint, _("only one %s allowed per rule"), "%merge");
   current_rule->merger = get_merge_function (name);
   current_rule->merger_declaration_location = loc;
 }
@@ -559,7 +559,7 @@ packgram (void)
           /* Don't allow rule_length == INT_MAX, since that might
              cause confusion with strtol if INT_MAX == LONG_MAX.  */
           if (rule_length == INT_MAX)
-            complain_at (rules[ruleno].location, fatal, _("rule is too long"));
+            complain (&rules[ruleno].location, fatal, _("rule is too long"));
 
           /* item_number = symbol_number.
              But the former needs to contain more: negative rule numbers. */
@@ -677,7 +677,7 @@ check_and_convert_grammar (void)
 {
   /* Grammar has been read.  Do some checking.  */
   if (nrules == 0)
-    complain (fatal, _("no rules in the input grammar"));
+    complain (NULL, fatal, _("no rules in the input grammar"));
 
   /* If the user did not define her ENDTOKEN, do it now. */
   if (!endtoken)
