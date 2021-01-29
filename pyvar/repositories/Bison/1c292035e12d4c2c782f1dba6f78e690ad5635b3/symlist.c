@@ -223,49 +223,43 @@ symbol_list_null (symbol_list *node)
 }
 
 void
-symbol_list_destructor_set (symbol_list *node, char const *code, location loc)
+symbol_list_destructor_set (symbol_list *node, code_props const *destructor)
 {
-  code_props destructor;
-  code_props_symbol_action_init (&destructor, code, loc);
-  code_props_translate_code (&destructor);
   switch (node->content_type)
     {
       case SYMLIST_SYMBOL:
-        symbol_destructor_set (node->content.sym, &destructor);
+        symbol_destructor_set (node->content.sym, destructor);
         break;
       case SYMLIST_TYPE:
         semantic_type_destructor_set (
-          semantic_type_get (node->content.type_name), &destructor);
+          semantic_type_get (node->content.type_name), destructor);
         break;
       case SYMLIST_DEFAULT_TAGGED:
-        default_tagged_destructor_set (&destructor);
+        default_tagged_destructor_set (destructor);
         break;
       case SYMLIST_DEFAULT_TAGLESS:
-        default_tagless_destructor_set (&destructor);
+        default_tagless_destructor_set (destructor);
         break;
     }
 }
 
 void
-symbol_list_printer_set (symbol_list *node, char const *code, location loc)
+symbol_list_printer_set (symbol_list *node, code_props const *printer)
 {
-  code_props printer;
-  code_props_symbol_action_init (&printer, code, loc);
-  code_props_translate_code (&printer);
   switch (node->content_type)
     {
       case SYMLIST_SYMBOL:
-        symbol_printer_set (node->content.sym, &printer);
+        symbol_printer_set (node->content.sym, printer);
         break;
       case SYMLIST_TYPE:
         semantic_type_printer_set (
-          semantic_type_get (node->content.type_name), &printer);
+          semantic_type_get (node->content.type_name), printer);
         break;
       case SYMLIST_DEFAULT_TAGGED:
-        default_tagged_printer_set (&printer);
+        default_tagged_printer_set (printer);
         break;
       case SYMLIST_DEFAULT_TAGLESS:
-        default_tagless_printer_set (&printer);
+        default_tagless_printer_set (printer);
         break;
     }
 }
