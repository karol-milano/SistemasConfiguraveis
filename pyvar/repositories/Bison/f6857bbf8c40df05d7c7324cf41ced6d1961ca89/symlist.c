@@ -43,8 +43,7 @@ symbol_list_sym_new (symbol *sym, location loc)
   res->midrule_parent_rule = NULL;
   res->midrule_parent_rhs_index = 0;
 
-  res->action = NULL;
-  res->used = false;
+  code_props_none_init (&res->action_props);
 
   res->ruleprec = NULL;
   res->dprec = 0;
@@ -118,7 +117,7 @@ symbol_list_syms_print (const symbol_list *l, FILE *f)
   for (/* Nothing. */; l && l->content.sym; l = l->next)
     {
       symbol_print (l->content.sym, f);
-      fprintf (stderr, l->used ? " used" : " unused");
+      fprintf (stderr, l->action_props.is_value_used ? " used" : " unused");
       if (l && l->content.sym)
 	fprintf (f, ", ");
     }
