@@ -195,18 +195,18 @@ symbol_list_code_props_set (symbol_list *node, code_props_type kind,
 {
   switch (node->content_type)
     {
-      case SYMLIST_SYMBOL:
-        symbol_code_props_set (node->content.sym, kind, cprops);
-        if (node->content.sym->status == undeclared)
-          node->content.sym->status = used;
-        break;
-      case SYMLIST_TYPE:
-        semantic_type_code_props_set
-          (semantic_type_get (node->content.sem_type->tag,
-                              &node->content.sem_type->location),
-           kind, cprops);
-        if (node->content.sem_type->status == undeclared)
-          node->content.sem_type->status = used;
-        break;
+    case SYMLIST_SYMBOL:
+      symbol_code_props_set (node->content.sym, kind, cprops);
+      if (node->content.sym->status == undeclared)
+        node->content.sym->status = used;
+      break;
+    case SYMLIST_TYPE:
+      semantic_type_code_props_set
+        (semantic_type_get (node->content.sem_type->tag,
+                            &node->content.sem_type->location),
+         kind, cprops);
+      if (node->content.sem_type->status == undeclared)
+        node->content.sem_type->status = used;
+      break;
     }
 }
