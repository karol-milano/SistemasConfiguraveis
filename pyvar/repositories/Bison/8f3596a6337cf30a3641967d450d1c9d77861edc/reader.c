@@ -36,6 +36,9 @@
 #include "symlist.h"
 #include "symtab.h"
 
+static void grammar_midrule_action (void);
+static void grammar_symbol_append (symbol *sym, location loc);
+
 static symbol_list *grammar = NULL;
 static bool start_flag = false;
 merger_list *merge_functions;
@@ -153,7 +156,7 @@ free_merger_functions (void)
 static symbol_list *grammar_end = NULL;
 
 /* Append SYM to the grammar.  */
-void
+static void
 grammar_symbol_append (symbol *sym, location loc)
 {
   symbol_list *p = symbol_list_new (sym, loc);
@@ -164,6 +167,11 @@ grammar_symbol_append (symbol *sym, location loc)
     grammar = p;
 
   grammar_end = p;
+
+  /* SYM = 0 stands for an end of rule, it is not an actual
+     part of it.  */
+  if (sym)
+    ++nritems;
 }
 
 /* The rule currently being defined, and the previous rule.
@@ -178,7 +186,7 @@ static symbol_list *previous_rule_end = NULL;
 `----------------------------------------------*/
 
 void
-grammar_rule_begin (symbol *lhs, location loc)
+grammar_current_rule_begin (symbol *lhs, location loc)
 {
   if (!start_flag)
     {
@@ -189,8 +197,6 @@ grammar_rule_begin (symbol *lhs, location loc)
 
   /* Start a new rule and record its lhs.  */
   ++nrules;
-  ++nritems;
-
   previous_rule_end = grammar_end;
   grammar_symbol_append (lhs, loc);
   current_rule = grammar_end;
@@ -207,17 +213,14 @@ grammar_rule_begin (symbol *lhs, location loc)
 }
 
 
-/*------------------------------------------------------------------.
-| Check that the last rule (CURRENT_RULE) is properly defined.  For |
-| instance, there should be no type clash on the default action.    |
-`------------------------------------------------------------------*/
+/*----------------------------------------------------------------.
+| Check that the rule R is properly defined.  For instance, there |
+| should be no type clash on the default action.                  |
+`----------------------------------------------------------------*/
 
 static void
-grammar_current_rule_check (void)
+grammar_rule_check (const symbol_list *r)
 {
-  symbol *lhs = current_rule->sym;
-  char const *lhs_type = lhs->type_name;
-
   /* Type check.
 
      If there is an action, then there is nothing we can do: the user
@@ -225,36 +228,40 @@ grammar_current_rule_check (void)
 
      Don't worry about the default action if $$ is untyped, since $$'s
      value can't be used.  */
-  if (!current_rule->action && lhs_type)
+  if (!r->action && r->sym->type_name)
     {
-      symbol *first_rhs = current_rule->next->sym;
+      symbol *first_rhs = r->next->sym;
       /* If $$ is being set in default way, report if any type mismatch.  */
       if (first_rhs)
 	{
+	  char const *lhs_type = r->sym->type_name;
 	  const char *rhs_type =
 	    first_rhs->type_name ? first_rhs->type_name : "";
 	  if (!UNIQSTR_EQ (lhs_type, rhs_type))
-	    warn_at (current_rule->location,
+	    warn_at (r->location,
 		     _("type clash on default action: <%s> != <%s>"),
 		     lhs_type, rhs_type);
 	}
       /* Warn if there is no default for $$ but we need one.  */
       else
-	warn_at (current_rule->location,
+	warn_at (r->location,
 		 _("empty rule for typed nonterminal, and no action"));
     }
-
-  /* Check that all the symbol values are used. */
-  if (typed)
-    {
-      symbol_list *l = current_rule;
-      int n = 1;
-      for (l = current_rule->next; l && l->sym; l = l->next, ++n)
-	/* The default action `uses' $1. */
-	if (! (!current_rule->action && n == 1)
-	    && l->sym->type_name && !l->used)
-	  warn_at (current_rule->location, _("unused value: $%d"), n);
-    }
+  
+  /* Check that typed symbol values are used.  */
+  {
+    symbol_list *l = r;
+    int n = 0;
+    for (; l && l->sym; l = l->next, ++n)
+      if (! (l->used
+	     || !l->sym->type_name
+	     /* The default action, $$ = $1, `uses' both.  */
+	     || !r->action && (n == 0 || n == 1)))
+	if (n)
+	  warn_at (r->location, _("unused value: $%d"), n);
+	else
+	  warn_at (r->location, _("unset value: $$"));
+  }
 }
 
 
@@ -263,12 +270,12 @@ grammar_current_rule_check (void)
 `-------------------------------------*/
 
 void
-grammar_rule_end (location loc)
+grammar_current_rule_end (location loc)
 {
   /* Put an empty link in the list to mark the end of this rule  */
   grammar_symbol_append (NULL, grammar_end->location);
   current_rule->location = loc;
-  grammar_current_rule_check ();
+  grammar_rule_check (current_rule);
 }
 
 
@@ -279,7 +286,7 @@ grammar_rule_end (location loc)
 | rule.                                                              |
 `-------------------------------------------------------------------*/
 
-void
+static void
 grammar_midrule_action (void)
 {
   /* Since the action was written out with this rule's number, we must
@@ -364,7 +371,6 @@ grammar_current_rule_symbol_append (symbol *sym, location loc)
 {
   if (current_rule->action)
     grammar_midrule_action ();
-  ++nritems;
   grammar_symbol_append (sym, loc);
 }
 
