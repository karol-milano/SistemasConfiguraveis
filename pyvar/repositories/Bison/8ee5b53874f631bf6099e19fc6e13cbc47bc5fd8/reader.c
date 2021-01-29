@@ -90,14 +90,13 @@ prologue_augment (const char *prologue, location loc, bool post)
 
 
 
-/*-------------------------------------------------------------------.
-| Return the merger index for a merging function named NAME, whose   |
-| arguments have type TYPE.  Records the function, if new, in        |
-| MERGER_LIST.							     |
-`-------------------------------------------------------------------*/
+/*------------------------------------------------------------------------.
+| Return the merger index for a merging function named NAME.  Records the |
+| function, if new, in MERGER_LIST.                                       |
+`------------------------------------------------------------------------*/
 
 static int
-get_merge_function (uniqstr name, uniqstr type, location loc)
+get_merge_function (uniqstr name)
 {
   merger_list *syms;
   merger_list head;
@@ -106,9 +105,6 @@ get_merge_function (uniqstr name, uniqstr type, location loc)
   if (! glr_parser)
     return 0;
 
-  if (type == NULL)
-    type = uniqstr_new ("");
-
   head.next = merge_functions;
   for (syms = &head, n = 1; syms->next; syms = syms->next, n += 1)
     if (UNIQSTR_EQ (name, syms->next->name))
@@ -117,16 +113,54 @@ get_merge_function (uniqstr name, uniqstr type, location loc)
     {
       syms->next = xmalloc (sizeof syms->next[0]);
       syms->next->name = uniqstr_new (name);
-      syms->next->type = uniqstr_new (type);
+      /* After all symbol type declarations have been parsed, packgram invokes
+	 record_merge_function_type to set the type.  */
+      syms->next->type = NULL;
       syms->next->next = NULL;
       merge_functions = head.next;
     }
-  else if (!UNIQSTR_EQ (type, syms->next->type))
-    warn_at (loc, _("result type clash on merge function %s: <%s> != <%s>"),
-	     name, type, syms->next->type);
   return n;
 }
 
+/*-------------------------------------------------------------------------.
+| For the existing merging function with index MERGER, record the result   |
+| type as TYPE as required by the lhs of the rule whose %merge declaration |
+| is at DECLARATION_LOC.                                                   |
+`-------------------------------------------------------------------------*/
+
+static void
+record_merge_function_type (int merger, uniqstr type, location declaration_loc)
+{
+  int merger_find;
+  merger_list *merge_function;
+
+  if (merger <= 0)
+    return;
+
+  if (type == NULL)
+    type = uniqstr_new ("");
+
+  merger_find = 1;
+  for (merge_function = merge_functions;
+       merge_function != NULL && merger_find != merger;
+       merge_function = merge_function->next)
+    merger_find += 1;
+  assert (merge_function != NULL && merger_find == merger);
+  if (merge_function->type == NULL)
+    {
+      merge_function->type = uniqstr_new (type);
+      merge_function->type_declaration_location = declaration_loc;
+    }
+  else if (!UNIQSTR_EQ (merge_function->type, type))
+    {
+      warn_at (declaration_loc,
+	       _("result type clash on merge function `%s': <%s> != <%s>"),
+	       merge_function->name, type, merge_function->type);
+      warn_at (merge_function->type_declaration_location,
+	       _("first declaration"));
+    }
+}
+
 /*--------------------------------------.
 | Free all merge-function definitions.	|
 `--------------------------------------*/
@@ -382,8 +416,8 @@ grammar_current_rule_merge_set (uniqstr name, location loc)
     warn_at (loc, _("%s affects only GLR parsers"), "%merge");
   if (current_rule->merger != 0)
     complain_at (loc, _("only one %s allowed per rule"), "%merge");
-  current_rule->merger =
-    get_merge_function (name, current_rule->sym->type_name, loc);
+  current_rule->merger = get_merge_function (name);
+  current_rule->merger_declaration_location = loc;
 }
 
 /* Attach SYM to the current rule.  If needed, move the previous
@@ -434,6 +468,8 @@ packgram (void)
     {
       int rule_length = 0;
       symbol *ruleprec = p->ruleprec;
+      record_merge_function_type (p->merger, p->sym->type_name,
+				  p->merger_declaration_location);
       rules[ruleno].user_number = ruleno;
       rules[ruleno].number = ruleno;
       rules[ruleno].lhs = p->sym;
