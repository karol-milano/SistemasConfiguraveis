@@ -46,20 +46,6 @@ symbol *accept = NULL;
 symbol *startsymbol = NULL;
 location startsymbol_location;
 
-/*---------------------------------------.
-| Default %destructor's and %printer's.  |
-`---------------------------------------*/
-
-static code_props default_tagged_code_props[CODE_PROPS_SIZE] =
-  {
-    CODE_PROPS_NONE_INIT,
-    CODE_PROPS_NONE_INIT,
-  };
-static code_props default_tagless_code_props[CODE_PROPS_SIZE] =
-  {
-    CODE_PROPS_NONE_INIT,
-    CODE_PROPS_NONE_INIT,
-  };
 
 /*---------------------------------.
 | Create a new symbol, named TAG.  |
@@ -291,12 +277,14 @@ symbol_code_props_get (symbol *sym, code_props_type kind)
     }
 
   /* Apply default code props's only to user-defined symbols.  */
-  if (sym->tag[0] == '$' || sym == errtoken)
-    return &code_props_none;
-
-  if (sym->type_name)
-    return &default_tagged_code_props[kind];
-  return &default_tagless_code_props[kind];
+  if (sym->tag[0] != '$' && sym != errtoken)
+    {
+      code_props *code =
+        &semantic_type_get (sym->type_name ? "*" : "", NULL)->props[kind];
+      if (code->code)
+        return code;
+    }
+  return &code_props_none;
 }
 
 /*-----------------------------------------------------------------.
@@ -437,7 +425,10 @@ symbol_check_defined (symbol *sym)
 static inline bool
 semantic_type_check_defined (semantic_type *sem_type)
 {
-  if (sem_type->status == declared)
+  // <*> and <> do not have to be "declared".
+  if (sem_type->status == declared
+      || !*sem_type->tag
+      || STREQ(sem_type->tag, "*"))
     {
       for (int i = 0; i < 2; ++i)
         if (sem_type->props[i].kind != CODE_PROPS_NONE
@@ -970,36 +961,3 @@ symbols_pack (void)
                  _("the start symbol %s is a token"),
                  startsymbol->tag);
 }
-
-
-/*--------------------------------------------------.
-| Set default tagged/tagless %destructor/%printer.  |
-`--------------------------------------------------*/
-
-void
-default_tagged_code_props_set (code_props_type kind, code_props const *code)
-{
-  if (default_tagged_code_props[kind].code)
-    {
-      complain_at (code->location, complaint,
-                   _("redeclaration for default tagged %s"),
-                   code_props_type_string (kind));
-      complain_at (default_tagged_code_props[kind].location, complaint,
-                   _("previous declaration"));
-    }
-  default_tagged_code_props[kind] = *code;
-}
-
-void
-default_tagless_code_props_set (code_props_type kind, code_props const *code)
-{
-  if (default_tagless_code_props[kind].code)
-    {
-      complain_at (code->location, complaint,
-                   _("redeclaration for default tagless %s"),
-                   code_props_type_string (kind));
-      complain_at (default_tagless_code_props[kind].location, complaint,
-                   _("previous declaration"));
-    }
-  default_tagless_code_props[kind] = *code;
-}
