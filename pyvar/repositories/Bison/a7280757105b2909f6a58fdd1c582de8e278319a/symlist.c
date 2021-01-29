@@ -205,7 +205,7 @@ symbol_list_n_type_name_get (symbol_list *l, location loc, int n)
       return NULL;
     }
   aver (l->content_type == SYMLIST_SYMBOL);
-  return l->content.sym->type_name;
+  return l->content.sym->content->type_name;
 }
 
 bool
@@ -223,8 +223,8 @@ symbol_list_code_props_set (symbol_list *node, code_props_type kind,
     {
     case SYMLIST_SYMBOL:
       symbol_code_props_set (node->content.sym, kind, cprops);
-      if (node->content.sym->status == undeclared)
-        node->content.sym->status = used;
+      if (node->content.sym->content->status == undeclared)
+        node->content.sym->content->status = used;
       break;
     case SYMLIST_TYPE:
       semantic_type_code_props_set
