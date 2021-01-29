@@ -40,7 +40,7 @@ static symbol_list *grammar = NULL;
 static bool start_flag = false;
 merger_list *merge_functions;
 
-/* Has %union been seen?  */
+/* Was %union seen?  */
 bool typed = false;
 
 /* Should rules have a default precedence?  */
@@ -104,7 +104,7 @@ get_merge_function (uniqstr name, uniqstr type, location loc)
     type = uniqstr_new ("");
 
   head.next = merge_functions;
-  for (syms = &head, n = 1; syms->next != NULL; syms = syms->next, n += 1)
+  for (syms = &head, n = 1; syms->next; syms = syms->next, n += 1)
     if (UNIQSTR_EQ (name, syms->next->name))
       break;
   if (syms->next == NULL)
@@ -128,11 +128,8 @@ get_merge_function (uniqstr name, uniqstr type, location loc)
 void
 free_merger_functions (void)
 {
-  merger_list *L0;
-  if (! glr_parser)
-    return;
-  L0 = merge_functions;
-  while (L0 != NULL)
+  merger_list *L0 = merge_functions;
+  while (L0)
     {
       merger_list *L1 = L0->next;
       free (L0);
@@ -150,13 +147,6 @@ free_merger_functions (void)
 |                                                                    |
 | All actions are copied out, labelled by the rule number they apply |
 | to.                                                                |
-|                                                                    |
-| Bison used to allow some %directives in the rules sections, but    |
-| this is no longer consider appropriate: (i) the documented grammar |
-| doesn't claim it, (ii), it would promote bad style, (iii), error   |
-| recovery for %directives consists in skipping the junk until a `%' |
-| is seen and helrp synchronizing.  This scheme is definitely wrong  |
-| in the rules section.                                              |
 `-------------------------------------------------------------------*/
 
 /* The (currently) last symbol of GRAMMAR. */
@@ -206,7 +196,6 @@ grammar_rule_begin (symbol *lhs, location loc)
   current_rule = grammar_end;
 
   /* Mark the rule's lhs as a nonterminal if not already so.  */
-
   if (lhs->class == unknown_sym)
     {
       lhs->class = nterm_sym;
@@ -217,39 +206,55 @@ grammar_rule_begin (symbol *lhs, location loc)
     complain_at (loc, _("rule given for %s, which is a token"), lhs->tag);
 }
 
-/* Check that the last rule (CURRENT_RULE) is properly defined.  For
-   instance, there should be no type clash on the default action.  */
+
+/*------------------------------------------------------------------.
+| Check that the last rule (CURRENT_RULE) is properly defined.  For |
+| instance, there should be no type clash on the default action.    |
+`------------------------------------------------------------------*/
 
 static void
 grammar_current_rule_check (void)
 {
   symbol *lhs = current_rule->sym;
   char const *lhs_type = lhs->type_name;
-  symbol *first_rhs = current_rule->next->sym;
 
-  /* If there is an action, then there is nothing we can do: the user
-     is allowed to shoot herself in the foot.  */
-  if (current_rule->action)
-    return;
+  /* Type check.
 
-  /* Don't worry about the default action if $$ is untyped, since $$'s
-     value can't be used.  */
-  if (! lhs_type)
-    return;
+     If there is an action, then there is nothing we can do: the user
+     is allowed to shoot herself in the foot.
 
-  /* If $$ is being set in default way, report if any type mismatch.  */
-  if (first_rhs)
+     Don't worry about the default action if $$ is untyped, since $$'s
+     value can't be used.  */
+  if (!current_rule->action && lhs_type)
     {
-      const char *rhs_type = first_rhs->type_name ? first_rhs->type_name : "";
-      if (!UNIQSTR_EQ (lhs_type, rhs_type))
+      symbol *first_rhs = current_rule->next->sym;
+      /* If $$ is being set in default way, report if any type mismatch.  */
+      if (first_rhs)
+	{
+	  const char *rhs_type =
+	    first_rhs->type_name ? first_rhs->type_name : "";
+	  if (!UNIQSTR_EQ (lhs_type, rhs_type))
+	    warn_at (current_rule->location,
+		     _("type clash on default action: <%s> != <%s>"),
+		     lhs_type, rhs_type);
+	}
+      /* Warn if there is no default for $$ but we need one.  */
+      else
 	warn_at (current_rule->location,
-		 _("type clash on default action: <%s> != <%s>"),
-		 lhs_type, rhs_type);
+		 _("empty rule for typed nonterminal, and no action"));
+    }
+
+  /* Check that all the symbol values are used. */
+  if (typed)
+    {
+      symbol_list *l = current_rule;
+      int n = 1;
+      for (l = current_rule->next; l && l->sym; l = l->next, ++n)
+	/* The default action `uses' $1. */
+	if (! (!current_rule->action && n == 1)
+	    && l->sym->type_name && !l->used)
+	  warn_at (current_rule->location, _("unused value: $%d"), n);
     }
-  /* Warn if there is no default for $$ but we need one.  */
-  else
-    warn_at (current_rule->location,
-	     _("empty rule for typed nonterminal, and no action"));
 }
 
 
