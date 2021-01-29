@@ -49,6 +49,8 @@ symbol_list_sym_new (symbol *sym, location loc)
   res->dprec_location = empty_location;
   res->merger = 0;
   res->merger_declaration_location = empty_location;
+  res->expected_sr_conflicts = -1;
+  res->expected_rr_conflicts = -1;
 
   res->next = NULL;
 
