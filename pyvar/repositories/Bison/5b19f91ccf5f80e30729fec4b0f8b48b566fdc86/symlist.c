@@ -91,6 +91,16 @@ symbol_list_type_set (symbol_list *syms, uniqstr type_name)
 }
 
 
+symbol_list *
+symbol_list_find_symbol (symbol_list *l, const symbol *sym)
+{
+  for (/* Nothing. */; l && l->content.sym; l = l->next)
+    if (l->content.sym == sym)
+      return l;
+  return NULL;
+}
+
+
 /*-----------------------------------------------------------------------.
 | Print this list, for which every content_type must be SYMLIST_SYMBOL.  |
 `-----------------------------------------------------------------------*/
@@ -129,23 +139,29 @@ symbol_list_prepend (symbol_list *list, symbol_list *node)
 }
 
 
-/*-------------------------.
-| Append NODE to the LIST. |
-`-------------------------*/
-
 symbol_list *
-symbol_list_append (symbol_list *list, symbol_list *node)
+symbol_list_last (symbol_list *list)
 {
   if (!list)
-    return node;
+    return NULL;
   symbol_list *next = list;
   while (next->next)
     next = next->next;
-  next->next = node;
+  return next;
+}
+
+symbol_list *
+symbol_list_append (symbol_list *list, symbol_list *node)
+{
+  if (list)
+    symbol_list_last (list)->next = node;
+  else
+    list = node;
   return list;
 }
 
 
+
 /*-----------------------------------------------.
 | Free the LIST, but not the items it contains.  |
 `-----------------------------------------------*/
