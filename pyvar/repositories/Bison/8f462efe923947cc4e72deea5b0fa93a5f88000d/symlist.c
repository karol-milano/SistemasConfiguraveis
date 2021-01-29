@@ -151,8 +151,7 @@ symbol_list_free (symbol_list *list)
   for (node = list; node; node = next)
     {
       next = node->next;
-      if (node->named_ref)
-        named_ref_free (node->named_ref);
+      named_ref_free (node->named_ref);
       free (node);
     }
 }
