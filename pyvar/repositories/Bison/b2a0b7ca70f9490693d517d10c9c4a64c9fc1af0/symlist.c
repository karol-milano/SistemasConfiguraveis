@@ -212,7 +212,8 @@ symbol_list_destructor_set (symbol_list *node, const char *destructor,
         symbol_destructor_set (node->content.sym, destructor, loc);
         break;
       case SYMLIST_TYPE:
-        /* FIXME: */
+        semantic_type_destructor_set (
+          semantic_type_get (node->content.type_name), destructor, loc);
         break;
       case SYMLIST_DEFAULT:
         default_destructor_set (destructor, loc);
@@ -229,7 +230,8 @@ symbol_list_printer_set (symbol_list *node, const char *printer, location loc)
         symbol_printer_set (node->content.sym, printer, loc);
         break;
       case SYMLIST_TYPE:
-        /* FIXME: */
+        semantic_type_printer_set (
+          semantic_type_get (node->content.type_name), printer, loc);
         break;
       case SYMLIST_DEFAULT:
         default_printer_set (printer, loc);
