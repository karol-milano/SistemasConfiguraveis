@@ -42,14 +42,14 @@ symbol_list_sym_new (symbol *sym, location loc)
   res->midrule_parent_rhs_index = 0;
 
   /* Members used for LHS only.  */
-  res->rhs_loc = empty_location;
+  res->rhs_loc = empty_loc;
   res->ruleprec = NULL;
-  res->percent_empty_loc = empty_location;
+  res->percent_empty_loc = empty_loc;
   code_props_none_init (&res->action_props);
   res->dprec = 0;
-  res->dprec_location = empty_location;
+  res->dprec_loc = empty_loc;
   res->merger = 0;
-  res->merger_declaration_location = empty_location;
+  res->merger_declaration_loc = empty_loc;
   res->expected_sr_conflicts = -1;
   res->expected_rr_conflicts = -1;
 
