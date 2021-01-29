@@ -44,6 +44,7 @@ symbol_list_sym_new (symbol *sym, location loc)
 
   /* Members used for LHS only.  */
   res->ruleprec = NULL;
+  res->percent_empty_loc = empty_location;
   code_props_none_init (&res->action_props);
   res->dprec = 0;
   res->merger = 0;
