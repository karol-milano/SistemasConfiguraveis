@@ -37,6 +37,7 @@
 int lineno;
 static symbol_list_t *grammar = NULL;
 static int start_flag = 0;
+merger_list *merge_functions;
 
 /* Nonzero if %union has been seen.  */
 int typed = 0;
@@ -105,6 +106,60 @@ epilogue_set (const char *epilogue, location_t location)
 
 
 
+ /*-------------------------------------------------------------------.
+| Return the merger index for a merging function named NAME, whose   |
+| arguments have type TYPE.  Records the function, if new, in        |
+| merger_list.							     |
+`-------------------------------------------------------------------*/
+
+static int
+get_merge_function (const char* name, const char* type)
+{
+  merger_list *syms;
+  merger_list head;
+  int n;
+
+  if (! glr_parser)
+    return 0;
+
+  if (type == NULL)
+    type = "";
+
+  head.next = merge_functions;
+  for (syms = &head, n = 1; syms->next != NULL; syms = syms->next, n += 1) 
+    if (strcmp (name, syms->next->name) == 0)
+      break;
+  if (syms->next == NULL) {
+    syms->next = XMALLOC (merger_list, 1);
+    syms->next->name = strdup (name);
+    syms->next->type = strdup (type);
+    syms->next->next = NULL;
+    merge_functions = head.next;
+  } else if (strcmp (type, syms->next->type) != 0)
+    warn (_("result type clash on merge function %s: `%s' vs. `%s'"), 
+	  name, type, syms->next->type);
+  return n;
+}
+
+/*--------------------------------------.
+| Free all merge-function definitions.	|
+`--------------------------------------*/
+
+void
+free_merger_functions (void)
+{
+  merger_list *L0;
+  if (! glr_parser)
+    return;
+  L0 = merge_functions;
+  while (L0 != NULL)
+    {
+      merger_list *L1 = L0->next;
+      free (L0);
+      L0 = L1;
+    }
+}
+
 /*-------------------------------------------------------------------.
 | Generate a dummy symbol, a nonterminal, whose name cannot conflict |
 | with the user's names.                                             |
@@ -307,6 +362,34 @@ grammar_current_rule_prec_set (symbol_t *precsym, location_t location)
   current_rule->ruleprec = precsym;
 }
 
+/* Attach dynamic precedence DPREC to the current rule. */
+
+void
+grammar_current_rule_dprec_set (int dprec, location_t location)
+{
+  if (! glr_parser)
+    warn_at (location, _("%%dprec affects only GLR parsers"));
+  if (dprec <= 0)
+    complain_at (location, _("%%dprec must be followed by positive number"));
+  else if (current_rule->dprec != 0) 
+    complain_at (location, _("only one %%dprec allowed per rule"));
+  current_rule->dprec = dprec;
+}
+
+/* Attach a merge function NAME with argument type TYPE to current
+   rule. */
+
+void
+grammar_current_rule_merge_set (const char* name, location_t location)
+{
+  if (! glr_parser)
+    warn_at (location, _("%%merge affects only GLR parsers"));
+  if (current_rule->merger != 0) 
+    complain_at (location, _("only one %%merge allowed per rule"));
+  current_rule->merger = 
+    get_merge_function (name, current_rule->sym->type_name);
+}
+
 /* Attach a SYMBOL to the current rule.  If needed, move the previous
    action as a mid-rule action.  */
 
@@ -319,7 +402,6 @@ grammar_current_rule_symbol_append (symbol_t *symbol, location_t location)
   grammar_symbol_append (symbol, location);
 }
 
-
 /* Attach an ACTION to the current rule.  If needed, move the previous
    action as a mid-rule action.  */
 
@@ -363,6 +445,8 @@ packgram (void)
       rules[ruleno].useful = TRUE;
       rules[ruleno].action = p->action;
       rules[ruleno].action_location = p->action_location;
+      rules[ruleno].dprec = p->dprec;
+      rules[ruleno].merger = p->merger;
 
       p = p->next;
       while (p && p->sym)
