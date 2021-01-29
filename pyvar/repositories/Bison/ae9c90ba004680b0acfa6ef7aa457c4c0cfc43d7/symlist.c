@@ -119,6 +119,8 @@ symbol_list_free (symbol_list *list)
     {
       next = node->next;
       named_ref_free (node->named_ref);
+      if (node->content_type == SYMLIST_TYPE)
+        free (node->content.sem_type);
       free (node);
     }
 }
