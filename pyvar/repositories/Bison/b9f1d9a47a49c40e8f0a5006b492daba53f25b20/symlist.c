@@ -35,7 +35,7 @@ symbol_list_sym_new (symbol *sym, location loc)
 
   res->content_type = SYMLIST_SYMBOL;
   res->content.sym = sym;
-  res->location = loc;
+  res->location = res->sym_loc = loc;
 
   res->midrule = NULL;
   res->midrule_parent_rule = NULL;
@@ -47,6 +47,8 @@ symbol_list_sym_new (symbol *sym, location loc)
   res->dprec = 0;
   res->merger = 0;
 
+  res->named_ref = NULL;
+
   res->next = NULL;
 
   return res;
@@ -64,7 +66,8 @@ symbol_list_type_new (uniqstr type_name, location loc)
 
   res->content_type = SYMLIST_TYPE;
   res->content.type_name = type_name;
-  res->location = loc;
+  res->location = res->sym_loc = loc;
+  res->named_ref = NULL;
   res->next = NULL;
 
   return res;
@@ -81,7 +84,8 @@ symbol_list_default_tagged_new (location loc)
   symbol_list *res = xmalloc (sizeof *res);
 
   res->content_type = SYMLIST_DEFAULT_TAGGED;
-  res->location = loc;
+  res->location = res->sym_loc = loc;
+  res->named_ref = NULL;
   res->next = NULL;
 
   return res;
@@ -98,7 +102,8 @@ symbol_list_default_tagless_new (location loc)
   symbol_list *res = xmalloc (sizeof *res);
 
   res->content_type = SYMLIST_DEFAULT_TAGLESS;
-  res->location = loc;
+  res->location = res->sym_loc = loc;
+  res->named_ref = NULL;
   res->next = NULL;
 
   return res;
