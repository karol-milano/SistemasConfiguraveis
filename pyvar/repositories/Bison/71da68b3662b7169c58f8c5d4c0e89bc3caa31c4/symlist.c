@@ -223,53 +223,29 @@ symbol_list_null (symbol_list *node)
 }
 
 void
-symbol_list_destructor_set (symbol_list *node, char const *code, location loc)
+symbol_list_code_props_set (symbol_list *node, code_props_type kind,
+                            location loc, char const *code)
 {
-  code_props destructor;
-  code_props_symbol_action_init (&destructor, code, loc);
-  code_props_translate_code (&destructor);
+  code_props cprops;
+  code_props_symbol_action_init (&cprops, code, loc);
+  code_props_translate_code (&cprops);
   switch (node->content_type)
     {
       case SYMLIST_SYMBOL:
-        symbol_destructor_set (node->content.sym, &destructor);
+        symbol_code_props_set (node->content.sym, kind, &cprops);
         if (node->content.sym->status == undeclared)
           node->content.sym->status = used;
         break;
       case SYMLIST_TYPE:
-        semantic_type_destructor_set (
-          semantic_type_get (node->content.type_name), &destructor);
+        semantic_type_code_props_set
+          (semantic_type_get (node->content.type_name),
+           kind, &cprops);
         break;
       case SYMLIST_DEFAULT_TAGGED:
-        default_tagged_destructor_set (&destructor);
+        default_tagged_code_props_set (kind, &cprops);
         break;
       case SYMLIST_DEFAULT_TAGLESS:
-        default_tagless_destructor_set (&destructor);
-        break;
-    }
-}
-
-void
-symbol_list_printer_set (symbol_list *node, char const *code, location loc)
-{
-  code_props printer;
-  code_props_symbol_action_init (&printer, code, loc);
-  code_props_translate_code (&printer);
-  switch (node->content_type)
-    {
-      case SYMLIST_SYMBOL:
-        symbol_printer_set (node->content.sym, &printer);
-        if (node->content.sym->status == undeclared)
-          node->content.sym->status = used;
-        break;
-      case SYMLIST_TYPE:
-        semantic_type_printer_set (
-          semantic_type_get (node->content.type_name), &printer);
-        break;
-      case SYMLIST_DEFAULT_TAGGED:
-        default_tagged_printer_set (&printer);
-        break;
-      case SYMLIST_DEFAULT_TAGLESS:
-        default_tagless_printer_set (&printer);
+        default_tagless_code_props_set (kind, &cprops);
         break;
     }
 }
