@@ -232,7 +232,7 @@ symbol_list_destructor_set (symbol_list *node, char const *code, location loc)
     {
       case SYMLIST_SYMBOL:
         symbol_destructor_set (node->content.sym, &destructor);
-        if (node->content.sym->status == needed)
+        if (node->content.sym->status == undeclared)
           node->content.sym->status = used;
         break;
       case SYMLIST_TYPE:
@@ -258,7 +258,7 @@ symbol_list_printer_set (symbol_list *node, char const *code, location loc)
     {
       case SYMLIST_SYMBOL:
         symbol_printer_set (node->content.sym, &printer);
-        if (node->content.sym->status == needed)
+        if (node->content.sym->status == undeclared)
           node->content.sym->status = used;
         break;
       case SYMLIST_TYPE:
