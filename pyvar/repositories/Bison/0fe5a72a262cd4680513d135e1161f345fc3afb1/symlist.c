@@ -47,7 +47,9 @@ symbol_list_sym_new (symbol *sym, location loc)
   res->percent_empty_loc = empty_location;
   code_props_none_init (&res->action_props);
   res->dprec = 0;
+  res->dprec_location = empty_location;
   res->merger = 0;
+  res->merger_declaration_location = empty_location;
 
   res->next = NULL;
 
