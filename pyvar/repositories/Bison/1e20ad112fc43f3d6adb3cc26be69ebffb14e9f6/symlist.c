@@ -146,7 +146,14 @@ symbol_list_prepend (symbol_list *list, symbol_list *node)
 void
 symbol_list_free (symbol_list *list)
 {
-  LIST_FREE (symbol_list, list);
+  symbol_list *node, *next;
+  for (node = list; node; node = next)
+    {
+      next = node->next;
+      if (node->named_ref)
+        named_ref_free (node->named_ref);
+      free (node);
+    }
 }
 
 
