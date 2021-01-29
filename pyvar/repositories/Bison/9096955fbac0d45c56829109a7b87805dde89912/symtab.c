@@ -109,6 +109,7 @@ symbol_new (uniqstr tag, location loc)
 
   res->tag = tag;
   res->location = loc;
+  res->translatable = false;
   res->location_of_lhs = false;
   res->alias = NULL;
   res->content = sym_content_new (res);
@@ -954,7 +955,7 @@ dummy_symbol_get (location loc)
 }
 
 bool
-symbol_is_dummy (const symbol *sym)
+symbol_is_dummy (symbol const *sym)
 {
   return sym->tag[0] == '@' || (sym->tag[0] == '$' && sym->tag[1] == '@');
 }
