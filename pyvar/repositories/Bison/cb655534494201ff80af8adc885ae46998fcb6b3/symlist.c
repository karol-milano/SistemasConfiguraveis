@@ -83,10 +83,10 @@ symbol_list_type_new (uniqstr type_name, location loc)
 
 
 symbol_list *
-symbol_list_type_set (symbol_list *syms, uniqstr type_name, location loc)
+symbol_list_type_set (symbol_list *syms, uniqstr type_name)
 {
   for (symbol_list *l = syms; l; l = l->next)
-    symbol_type_set (l->content.sym, type_name, loc);
+    symbol_type_set (l->content.sym, type_name, l->sym_loc);
   return syms;
 }
 
