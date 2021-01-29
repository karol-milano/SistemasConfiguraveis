@@ -190,7 +190,7 @@ symbol_list_n_get (symbol_list *l, int n)
 `--------------------------------------------------------------*/
 
 uniqstr
-symbol_list_n_type_name_get (symbol_list *l, location loc, int n)
+symbol_list_n_type_name_get (symbol_list *l, int n)
 {
   return symbol_list_n_get (l, n)->content.sym->type_name;
 }
