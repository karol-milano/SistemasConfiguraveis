@@ -208,6 +208,12 @@ symbol_list_n_type_name_get (symbol_list *l, location loc, int n)
   return l->content.sym->type_name;
 }
 
+bool
+symbol_list_null (symbol_list *node)
+{
+  return !node ||
+    (node->content_type == SYMLIST_SYMBOL && !(node->content.sym));
+}
 
 void
 symbol_list_destructor_set (symbol_list *node, char const *code, location loc)
