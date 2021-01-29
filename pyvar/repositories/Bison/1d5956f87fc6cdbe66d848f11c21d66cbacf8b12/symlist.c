@@ -81,6 +81,15 @@ symbol_list_type_new (uniqstr type_name, location loc)
 }
 
 
+symbol_list *
+symbol_list_type_set (symbol_list *syms, uniqstr type_name, location loc)
+{
+  for (symbol_list *l = syms; l; l = l->next)
+    symbol_type_set (l->content.sym, type_name, loc);
+  return syms;
+}
+
+
 /*-----------------------------------------------------------------------.
 | Print this list, for which every content_type must be SYMLIST_SYMBOL.  |
 `-----------------------------------------------------------------------*/
