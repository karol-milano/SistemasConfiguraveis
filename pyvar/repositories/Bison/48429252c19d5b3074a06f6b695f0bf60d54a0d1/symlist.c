@@ -148,14 +148,13 @@ symbol_list_append (symbol_list *list, symbol_list *node)
 void
 symbol_list_free (symbol_list *list)
 {
-  symbol_list *node, *next;
-  for (node = list; node; node = next)
+  for (symbol_list *next; list; list = next)
     {
-      next = node->next;
-      named_ref_free (node->named_ref);
-      if (node->content_type == SYMLIST_TYPE)
-        free (node->content.sem_type);
-      free (node);
+      next = list->next;
+      named_ref_free (list->named_ref);
+      if (list->content_type == SYMLIST_TYPE)
+        free (list->content.sem_type);
+      free (list);
     }
 }
 
