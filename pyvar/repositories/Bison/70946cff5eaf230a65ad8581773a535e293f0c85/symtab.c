@@ -274,9 +274,8 @@ semantic_type_code_props_set (semantic_type *type,
 | Get the computed %destructor or %printer for SYM.  |
 `---------------------------------------------------*/
 
-code_props const *
-symbol_code_props_get (symbol const *sym,
-                       code_props_type kind)
+code_props *
+symbol_code_props_get (symbol *sym, code_props_type kind)
 {
   /* Per-symbol code props.  */
   if (sym->props[kind].code)
@@ -285,7 +284,7 @@ symbol_code_props_get (symbol const *sym,
   /* Per-type code props.  */
   if (sym->type_name)
     {
-      code_props const *code =
+      code_props *code =
         &semantic_type_get (sym->type_name, NULL)->props[kind];
       if (code->code)
         return code;
@@ -421,13 +420,7 @@ symbol_check_defined (symbol *sym)
     }
 
   for (int i = 0; i < 2; ++i)
-    if (sym->props[i].kind == CODE_PROPS_NONE && sym->type_name)
-      {
-        semantic_type *sem_type = semantic_type_get (sym->type_name, NULL);
-        if (sem_type
-            && sem_type->props[i].kind != CODE_PROPS_NONE)
-          sem_type->props[i].is_used = true;
-      }
+    symbol_code_props_get (sym, i)->is_used = true;
 
   /* Set the semantic type status associated to the current symbol to
      'declared' so that we could check semantic types unnecessary uses. */
