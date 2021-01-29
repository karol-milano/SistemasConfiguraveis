@@ -34,7 +34,7 @@ symbol_list_sym_new (symbol *sym, location loc)
 
   res->content_type = SYMLIST_SYMBOL;
   res->content.sym = sym;
-  res->location = res->sym_loc = loc;
+  res->sym_loc = loc;
   res->named_ref = NULL;
 
   res->midrule = NULL;
@@ -42,6 +42,7 @@ symbol_list_sym_new (symbol *sym, location loc)
   res->midrule_parent_rhs_index = 0;
 
   /* Members used for LHS only.  */
+  res->rhs_loc = empty_location;
   res->ruleprec = NULL;
   res->percent_empty_loc = empty_location;
   code_props_none_init (&res->action_props);
@@ -73,7 +74,7 @@ symbol_list_type_new (uniqstr type_name, location loc)
   res->content.sem_type->location = loc;
   res->content.sem_type->status = undeclared;
 
-  res->location = res->sym_loc = loc;
+  res->sym_loc = loc;
   res->named_ref = NULL;
   res->next = NULL;
 
