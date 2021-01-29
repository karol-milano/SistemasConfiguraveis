@@ -66,7 +66,11 @@ symbol_list_type_new (uniqstr type_name, location loc)
   symbol_list *res = xmalloc (sizeof *res);
 
   res->content_type = SYMLIST_TYPE;
-  res->content.type_name = type_name;
+  res->content.sem_type = xmalloc (sizeof (semantic_type));
+  res->content.sem_type->tag = type_name;
+  res->content.sem_type->location = loc;
+  res->content.sem_type->status = undeclared;
+
   res->location = res->sym_loc = loc;
   res->named_ref = NULL;
   res->next = NULL;
@@ -238,8 +242,11 @@ symbol_list_code_props_set (symbol_list *node, code_props_type kind,
         break;
       case SYMLIST_TYPE:
         semantic_type_code_props_set
-          (semantic_type_get (node->content.type_name),
+          (semantic_type_get (node->content.sem_type->tag,
+                              &node->content.sem_type->location),
            kind, &cprops);
+        if (node->content.sem_type->status == undeclared)
+          node->content.sem_type->status = used;
         break;
       case SYMLIST_DEFAULT_TAGGED:
         default_tagged_code_props_set (kind, &cprops);
