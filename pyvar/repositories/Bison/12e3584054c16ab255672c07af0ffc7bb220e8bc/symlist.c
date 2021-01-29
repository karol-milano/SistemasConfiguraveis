@@ -74,16 +74,33 @@ symbol_list_type_new (uniqstr type_name, location loc)
 }
 
 
-/*----------------------------------------------------.
-| Create a list containing a %symbol-default at LOC.  |
-`----------------------------------------------------*/
+/*----------------------------------------.
+| Create a list containing a <*> at LOC.  |
+`----------------------------------------*/
 
 symbol_list *
-symbol_list_default_new (location loc)
+symbol_list_default_tagged_new (location loc)
 {
   symbol_list *res = xmalloc (sizeof *res);
 
-  res->content_type = SYMLIST_DEFAULT;
+  res->content_type = SYMLIST_DEFAULT_TAGGED;
+  res->location = loc;
+  res->next = NULL;
+
+  return res;
+}
+
+
+/*----------------------------------------.
+| Create a list containing a <!> at LOC.  |
+`----------------------------------------*/
+
+symbol_list *
+symbol_list_default_tagless_new (location loc)
+{
+  symbol_list *res = xmalloc (sizeof *res);
+
+  res->content_type = SYMLIST_DEFAULT_TAGLESS;
   res->location = loc;
   res->next = NULL;
 
@@ -215,8 +232,11 @@ symbol_list_destructor_set (symbol_list *node, const char *destructor,
         semantic_type_destructor_set (
           semantic_type_get (node->content.type_name), destructor, loc);
         break;
-      case SYMLIST_DEFAULT:
-        default_destructor_set (destructor, loc);
+      case SYMLIST_DEFAULT_TAGGED:
+        default_tagged_destructor_set (destructor, loc);
+        break;
+      case SYMLIST_DEFAULT_TAGLESS:
+        default_tagless_destructor_set (destructor, loc);
         break;
     }
 }
@@ -233,8 +253,11 @@ symbol_list_printer_set (symbol_list *node, const char *printer, location loc)
         semantic_type_printer_set (
           semantic_type_get (node->content.type_name), printer, loc);
         break;
-      case SYMLIST_DEFAULT:
-        default_printer_set (printer, loc);
+      case SYMLIST_DEFAULT_TAGGED:
+        default_tagged_printer_set (printer, loc);
+        break;
+      case SYMLIST_DEFAULT_TAGLESS:
+        default_tagless_printer_set (printer, loc);
         break;
     }
 }
