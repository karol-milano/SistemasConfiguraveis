@@ -207,27 +207,25 @@ symbol_list_n_type_name_get (symbol_list *l, location loc, int n)
 
 
 void
-symbol_list_destructor_set (symbol_list *node, char const *code,
-                            location loc)
+symbol_list_destructor_set (symbol_list *node, char const *code, location loc)
 {
   code_props destructor;
   code_props_symbol_action_init (&destructor, code, loc);
   code_props_translate_code (&destructor);
-  code = destructor.code;
   switch (node->content_type)
     {
       case SYMLIST_SYMBOL:
-        symbol_destructor_set (node->content.sym, code, loc);
+        symbol_destructor_set (node->content.sym, &destructor);
         break;
       case SYMLIST_TYPE:
         semantic_type_destructor_set (
-          semantic_type_get (node->content.type_name), code, loc);
+          semantic_type_get (node->content.type_name), &destructor);
         break;
       case SYMLIST_DEFAULT_TAGGED:
-        default_tagged_destructor_set (code, loc);
+        default_tagged_destructor_set (&destructor);
         break;
       case SYMLIST_DEFAULT_TAGLESS:
-        default_tagless_destructor_set (code, loc);
+        default_tagless_destructor_set (&destructor);
         break;
     }
 }
@@ -238,21 +236,20 @@ symbol_list_printer_set (symbol_list *node, char const *code, location loc)
   code_props printer;
   code_props_symbol_action_init (&printer, code, loc);
   code_props_translate_code (&printer);
-  code = printer.code;
   switch (node->content_type)
     {
       case SYMLIST_SYMBOL:
-        symbol_printer_set (node->content.sym, code, loc);
+        symbol_printer_set (node->content.sym, &printer);
         break;
       case SYMLIST_TYPE:
         semantic_type_printer_set (
-          semantic_type_get (node->content.type_name), code, loc);
+          semantic_type_get (node->content.type_name), &printer);
         break;
       case SYMLIST_DEFAULT_TAGGED:
-        default_tagged_printer_set (code, loc);
+        default_tagged_printer_set (&printer);
         break;
       case SYMLIST_DEFAULT_TAGLESS:
-        default_tagless_printer_set (code, loc);
+        default_tagless_printer_set (&printer);
         break;
     }
 }
