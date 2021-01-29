@@ -240,13 +240,13 @@ grammar_current_rule_begin (symbol *lhs, location loc,
   current_rule = grammar_end;
 
   /* Mark the rule's lhs as a nonterminal if not already so.  */
-  if (lhs->class == unknown_sym)
+  if (lhs->content->class == unknown_sym)
     {
-      lhs->class = nterm_sym;
-      lhs->number = nvars;
+      lhs->content->class = nterm_sym;
+      lhs->content->number = nvars;
       ++nvars;
     }
-  else if (lhs->class == token_sym)
+  else if (lhs->content->class == token_sym)
     complain (&loc, complaint, _("rule given for %s, which is a token"),
               lhs->tag);
 }
@@ -292,15 +292,15 @@ grammar_rule_check (const symbol_list *r)
 
      Don't worry about the default action if $$ is untyped, since $$'s
      value can't be used.  */
-  if (!r->action_props.code && r->content.sym->type_name)
+  if (!r->action_props.code && r->content.sym->content->type_name)
     {
       symbol *first_rhs = r->next->content.sym;
       /* If $$ is being set in default way, report if any type mismatch.  */
       if (first_rhs)
         {
-          char const *lhs_type = r->content.sym->type_name;
+          char const *lhs_type = r->content.sym->content->type_name;
           const char *rhs_type =
-            first_rhs->type_name ? first_rhs->type_name : "";
+            first_rhs->content->type_name ? first_rhs->content->type_name : "";
           if (!UNIQSTR_EQ (lhs_type, rhs_type))
             complain (&r->location, Wother,
                       _("type clash on default action: <%s> != <%s>"),
@@ -350,7 +350,8 @@ grammar_rule_check (const symbol_list *r)
      it for char literals and strings, which are always tokens.  */
   if (r->ruleprec
       && r->ruleprec->tag[0] != '\'' && r->ruleprec->tag[0] != '"'
-      && r->ruleprec->status != declared && !r->ruleprec->prec)
+      && r->ruleprec->content->status != declared
+      && !r->ruleprec->content->prec)
     complain (&r->location, Wother,
               _("token for %%prec is not defined: %s"), r->ruleprec->tag);
 }
@@ -517,8 +518,8 @@ grammar_current_rule_symbol_append (symbol *sym, location loc,
   p = grammar_symbol_append (sym, loc);
   if (name)
     assign_named_ref (p, name);
-  if (sym->status == undeclared || sym->status == used)
-    sym->status = needed;
+  if (sym->content->status == undeclared || sym->content->status == used)
+    sym->content->status = needed;
 }
 
 /* Attach an ACTION to the current rule.  */
@@ -558,11 +559,11 @@ packgram (void)
   for (p = grammar; p; p = p->next)
     {
       symbol *ruleprec = p->ruleprec;
-      record_merge_function_type (p->merger, p->content.sym->type_name,
+      record_merge_function_type (p->merger, p->content.sym->content->type_name,
                                   p->merger_declaration_location);
       rules[ruleno].user_number = ruleno;
       rules[ruleno].number = ruleno;
-      rules[ruleno].lhs = p->content.sym;
+      rules[ruleno].lhs = p->content.sym->content;
       rules[ruleno].rhs = ritem + itemno;
       rules[ruleno].prec = NULL;
       rules[ruleno].dprec = p->dprec;
@@ -604,11 +605,11 @@ packgram (void)
             /* item_number = symbol_number.
                But the former needs to contain more: negative rule numbers. */
             ritem[itemno++] =
-              symbol_number_as_item_number (p->content.sym->number);
+              symbol_number_as_item_number (p->content.sym->content->number);
             /* A rule gets by default the precedence and associativity
                of its last token.  */
-            if (p->content.sym->class == token_sym && default_prec)
-              rules[ruleno].prec = p->content.sym;
+            if (p->content.sym->content->class == token_sym && default_prec)
+              rules[ruleno].prec = p->content.sym->content;
           }
       }
 
@@ -616,8 +617,8 @@ packgram (void)
          the specified symbol's precedence replaces the default.  */
       if (ruleprec)
         {
-          rules[ruleno].precsym = ruleprec;
-          rules[ruleno].prec = ruleprec;
+          rules[ruleno].precsym = ruleprec->content;
+          rules[ruleno].prec = ruleprec->content;
         }
       /* An item ends by the rule number (negated).  */
       ritem[itemno++] = rule_number_as_item_number (ruleno);
@@ -647,19 +648,19 @@ reader (void)
 
   /* Construct the accept symbol. */
   accept = symbol_get ("$accept", empty_location);
-  accept->class = nterm_sym;
-  accept->number = nvars++;
+  accept->content->class = nterm_sym;
+  accept->content->number = nvars++;
 
   /* Construct the error token */
   errtoken = symbol_get ("error", empty_location);
-  errtoken->class = token_sym;
-  errtoken->number = ntokens++;
+  errtoken->content->class = token_sym;
+  errtoken->content->number = ntokens++;
 
   /* Construct a token that represents all undefined literal tokens.
      It is always token number 2.  */
   undeftoken = symbol_get ("$undefined", empty_location);
-  undeftoken->class = token_sym;
-  undeftoken->number = ntokens++;
+  undeftoken->content->class = token_sym;
+  undeftoken->content->number = ntokens++;
 
   gram_in = xfopen (grammar_file, "r");
 
@@ -721,10 +722,10 @@ check_and_convert_grammar (void)
   if (!endtoken)
     {
       endtoken = symbol_get ("$end", empty_location);
-      endtoken->class = token_sym;
-      endtoken->number = 0;
+      endtoken->content->class = token_sym;
+      endtoken->content->number = 0;
       /* Value specified by POSIX.  */
-      endtoken->user_token_number = 0;
+      endtoken->content->user_token_number = 0;
     }
 
   /* Report any undefined symbols and consider them nonterminals.  */
