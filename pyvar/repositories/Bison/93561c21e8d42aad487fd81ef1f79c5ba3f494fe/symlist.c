@@ -107,6 +107,23 @@ symbol_list_prepend (symbol_list *list, symbol_list *node)
 }
 
 
+/*-------------------------.
+| Append NODE to the LIST. |
+`-------------------------*/
+
+symbol_list *
+symbol_list_append (symbol_list *list, symbol_list *node)
+{
+  if (!list)
+    return node;
+  symbol_list *next = list;
+  while (next->next)
+    next = next->next;
+  next->next = node;
+  return list;
+}
+
+
 /*-----------------------------------------------.
 | Free the LIST, but not the items it contains.  |
 `-----------------------------------------------*/
