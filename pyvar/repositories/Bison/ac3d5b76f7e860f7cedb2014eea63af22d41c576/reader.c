@@ -42,7 +42,7 @@ static void check_and_convert_grammar (void);
 
 static symbol_list *grammar = NULL;
 symbol_list *start_symbols = NULL;
-merger_list *merge_functions;
+merger_list *merge_functions = NULL;
 
 /* Was %union seen?  */
 bool union_seen = false;
@@ -114,27 +114,27 @@ get_merge_function (uniqstr name)
       syms->next->name = uniqstr_new (name);
       /* After all symbol type declarations have been parsed, packgram invokes
          record_merge_function_type to set the type.  */
-      syms->next->type = NULL;
+      syms->next->sym = NULL;
       syms->next->next = NULL;
       merge_functions = head.next;
     }
   return n;
 }
 
-/*-------------------------------------------------------------------------.
-| For the existing merging function with index MERGER, record the result   |
-| type as TYPE as required by the lhs of the rule whose %merge declaration |
-| is at DECLARATION_LOC.                                                   |
-`-------------------------------------------------------------------------*/
+/*-------------------------------------------------------------------.
+| For the existing merging function with index MERGER, record that   |
+| the result type is that of SYM, as required by the lhs (i.e., SYM) |
+| of the rule whose %merge declaration is at DECLARATION_LOC.        |
+`-------------------------------------------------------------------*/
 
 static void
-record_merge_function_type (int merger, uniqstr type, location declaration_loc)
+record_merge_function_type (int merger, symbol *sym, location declaration_loc)
 {
   if (merger <= 0)
     return;
 
-  if (type == NULL)
-    type = uniqstr_new ("");
+  uniqstr type
+    = sym->content->type_name ? sym->content->type_name : uniqstr_new ("");
 
   merger_list *merge_function;
   int merger_find = 1;
@@ -143,17 +143,18 @@ record_merge_function_type (int merger, uniqstr type, location declaration_loc)
        merge_function = merge_function->next)
     merger_find += 1;
   aver (merge_function != NULL && merger_find == merger);
-  if (merge_function->type != NULL && !UNIQSTR_EQ (merge_function->type, type))
+  if (merge_function->sym && merge_function->sym->content->type_name
+      && !UNIQSTR_EQ (merge_function->sym->content->type_name, type))
     {
       complain (&declaration_loc, complaint,
                 _("result type clash on merge function %s: "
                 "<%s> != <%s>"),
                 quote (merge_function->name), type,
-                merge_function->type);
+                merge_function->sym->content->type_name);
       subcomplain (&merge_function->type_declaration_loc, complaint,
                    _("previous declaration"));
     }
-  merge_function->type = uniqstr_new (type);
+  merge_function->sym = sym;
   merge_function->type_declaration_loc = declaration_loc;
 }
 
@@ -668,7 +669,7 @@ packgram (void)
   for (symbol_list *p = grammar; p; p = p->next)
     {
       symbol_list *lhs = p;
-      record_merge_function_type (lhs->merger, lhs->content.sym->content->type_name,
+      record_merge_function_type (lhs->merger, lhs->content.sym,
                                   lhs->merger_declaration_loc);
       /* If the midrule's $$ is set or its $n is used, remove the '$' from the
          symbol name so that it's a user-defined symbol so that the default
