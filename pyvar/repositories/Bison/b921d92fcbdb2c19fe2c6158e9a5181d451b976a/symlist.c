@@ -232,6 +232,8 @@ symbol_list_destructor_set (symbol_list *node, char const *code, location loc)
     {
       case SYMLIST_SYMBOL:
         symbol_destructor_set (node->content.sym, &destructor);
+        if (node->content.sym->status == needed)
+          node->content.sym->status = used;
         break;
       case SYMLIST_TYPE:
         semantic_type_destructor_set (
@@ -256,6 +258,8 @@ symbol_list_printer_set (symbol_list *node, char const *code, location loc)
     {
       case SYMLIST_SYMBOL:
         symbol_printer_set (node->content.sym, &printer);
+        if (node->content.sym->status == needed)
+          node->content.sym->status = used;
         break;
       case SYMLIST_TYPE:
         semantic_type_printer_set (
