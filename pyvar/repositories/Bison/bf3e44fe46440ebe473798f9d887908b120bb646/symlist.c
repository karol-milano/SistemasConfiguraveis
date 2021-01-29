@@ -217,7 +217,7 @@ symbol_list_n_type_name_get (symbol_list *l, location loc, int n)
 }
 
 bool
-symbol_list_null (symbol_list *node)
+symbol_list_null (symbol_list const *node)
 {
   return !node ||
     (node->content_type == SYMLIST_SYMBOL && !(node->content.sym));
