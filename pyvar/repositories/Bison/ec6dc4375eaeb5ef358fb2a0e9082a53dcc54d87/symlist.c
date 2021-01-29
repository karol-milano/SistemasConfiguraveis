@@ -36,19 +36,18 @@ symbol_list_sym_new (symbol *sym, location loc)
   res->content_type = SYMLIST_SYMBOL;
   res->content.sym = sym;
   res->location = res->sym_loc = loc;
+  res->named_ref = NULL;
 
   res->midrule = NULL;
   res->midrule_parent_rule = NULL;
   res->midrule_parent_rhs_index = 0;
 
-  code_props_none_init (&res->action_props);
-
+  /* Members used for LHS only.  */
   res->ruleprec = NULL;
+  code_props_none_init (&res->action_props);
   res->dprec = 0;
   res->merger = 0;
 
-  res->named_ref = NULL;
-
   res->next = NULL;
 
   return res;
