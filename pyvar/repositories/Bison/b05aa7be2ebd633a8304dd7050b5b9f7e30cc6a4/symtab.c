@@ -277,8 +277,8 @@ symbol_id_get (symbol const *sym)
 `------------------------------------------------------------------*/
 
 static void
-symbol_redeclaration (symbol *s, const char *what, location first,
-                      location second)
+complain_symbol_redeclared (symbol *s, const char *what, location first,
+                            location second)
 {
   unsigned i = 0;
   locations_sort (&first, &second);
@@ -290,8 +290,8 @@ symbol_redeclaration (symbol *s, const char *what, location first,
 }
 
 static void
-semantic_type_redeclaration (semantic_type *s, const char *what, location first,
-                             location second)
+complain_semantic_type_redeclared (semantic_type *s, const char *what, location first,
+                                   location second)
 {
   unsigned i = 0;
   locations_sort (&first, &second);
@@ -335,7 +335,8 @@ symbol_type_set (symbol *sym, uniqstr type_name, location loc)
   if (type_name)
     {
       if (sym->content->type_name)
-        symbol_redeclaration (sym, "%type", sym->content->type_location, loc);
+        complain_symbol_redeclared (sym, "%type",
+                                    sym->content->type_location, loc);
       else
         {
           uniqstr_assert (type_name);
@@ -354,9 +355,9 @@ symbol_code_props_set (symbol *sym, code_props_type kind,
                        code_props const *code)
 {
   if (sym->content->props[kind].code)
-    symbol_redeclaration (sym, code_props_type_string (kind),
-                          sym->content->props[kind].location,
-                          code->location);
+    complain_symbol_redeclared (sym, code_props_type_string (kind),
+                                sym->content->props[kind].location,
+                                code->location);
   else
     sym->content->props[kind] = *code;
 }
@@ -371,9 +372,9 @@ semantic_type_code_props_set (semantic_type *type,
                               code_props const *code)
 {
   if (type->props[kind].code)
-    semantic_type_redeclaration (type, code_props_type_string (kind),
-                                 type->props[kind].location,
-                                 code->location);
+    complain_semantic_type_redeclared (type, code_props_type_string (kind),
+                                       type->props[kind].location,
+                                       code->location);
   else
     type->props[kind] = *code;
 }
@@ -421,8 +422,8 @@ symbol_precedence_set (symbol *sym, int prec, assoc a, location loc)
     {
       sym_content *s = sym->content;
       if (s->prec)
-        symbol_redeclaration (sym, assoc_to_string (a),
-                              s->prec_location, loc);
+        complain_symbol_redeclared (sym, assoc_to_string (a),
+                                    s->prec_location, loc);
       else
         {
           s->prec = prec;
@@ -656,7 +657,7 @@ symbol_pack_processor (void *this, void *null ATTRIBUTE_UNUSED)
 }
 
 static void
-user_token_number_redeclaration (int num, symbol *first, symbol *second)
+complain_user_token_number_redeclared (int num, symbol *first, symbol *second)
 {
   unsigned i = 0;
   symbols_sort (&first, &second);
@@ -683,7 +684,7 @@ symbol_translation (symbol *this)
       /* A token which translation has already been set?*/
       if (token_translations[this->content->user_token_number]
           != undeftoken->content->number)
-        user_token_number_redeclaration
+        complain_user_token_number_redeclared
           (this->content->user_token_number,
            symbols[token_translations[this->content->user_token_number]], this);
       else
