@@ -49,10 +49,16 @@ location startsymbol_location;
 | Default %destructor's and %printer's.  |
 `---------------------------------------*/
 
-static code_props default_tagged_destructor = CODE_PROPS_NONE_INIT;
-static code_props default_tagless_destructor = CODE_PROPS_NONE_INIT;
-static code_props default_tagged_printer = CODE_PROPS_NONE_INIT;
-static code_props default_tagless_printer = CODE_PROPS_NONE_INIT;
+static code_props default_tagged_code_props[CODE_PROPS_SIZE] =
+  {
+    CODE_PROPS_NONE_INIT,
+    CODE_PROPS_NONE_INIT,
+  };
+static code_props default_tagless_code_props[CODE_PROPS_SIZE] =
+  {
+    CODE_PROPS_NONE_INIT,
+    CODE_PROPS_NONE_INIT,
+  };
 
 /*---------------------------------.
 | Create a new symbol, named TAG.  |
@@ -75,8 +81,8 @@ symbol_new (uniqstr tag, location loc)
   res->location = loc;
 
   res->type_name = NULL;
-  code_props_none_init (&res->destructor);
-  code_props_none_init (&res->printer);
+  for (int i = 0; i < CODE_PROPS_SIZE; ++i)
+    code_props_none_init (&res->props[i]);
 
   res->number = NUMBER_UNDEFINED;
   res->prec = 0;
@@ -94,6 +100,23 @@ symbol_new (uniqstr tag, location loc)
   return res;
 }
 
+/*-------------------------------------------------------.
+| Name of the code_props type: %destructor or %printer.  |
+`-------------------------------------------------------*/
+
+static char const *
+code_props_type_string (code_props_type kind)
+{
+  switch (kind)
+    {
+    case destructor:
+      return "%destructor";
+    case printer:
+      return "%printer";
+    }
+  assert (0);
+}
+
 /*----------------------------------------.
 | Create a new semantic type, named TAG.  |
 `----------------------------------------*/
@@ -105,8 +128,8 @@ semantic_type_new (uniqstr tag)
 
   uniqstr_assert (tag);
   res->tag = tag;
-  code_props_none_init (&res->destructor);
-  code_props_none_init (&res->printer);
+  for (int i = 0; i < CODE_PROPS_SIZE; ++i)
+    code_props_none_init (&res->props[i]);
 
   return res;
 }
@@ -120,9 +143,9 @@ semantic_type_new (uniqstr tag)
   if (s->Attr)                                          \
     fprintf (f, " %s { %s }", #Attr, s->Attr)
 
-#define SYMBOL_CODE_PRINT(Attr)                         \
-  if (s->Attr.code)                                     \
-    fprintf (f, " %s { %s }", #Attr, s->Attr.code)
+#define SYMBOL_CODE_PRINT(Attr)                                         \
+  if (s->props[Attr].code)                                              \
+    fprintf (f, " %s { %s }", #Attr, s->props[Attr].code)
 
 void
 symbol_print (symbol *s, FILE *f)
@@ -217,115 +240,65 @@ symbol_type_set (symbol *sym, uniqstr type_name, location loc)
     }
 }
 
-/*-----------------------------------------.
-| Set the DESTRUCTOR associated with SYM.  |
-`-----------------------------------------*/
-
-void
-symbol_destructor_set (symbol *sym, code_props const *destructor)
-{
-  if (sym->destructor.code)
-    symbol_redeclaration (sym, "%destructor", sym->destructor.location,
-                          destructor->location);
-  sym->destructor = *destructor;
-}
-
-/*------------------------------------------.
-| Set the DESTRUCTOR associated with TYPE.  |
-`------------------------------------------*/
-
-void
-semantic_type_destructor_set (semantic_type *type,
-                              code_props const *destructor)
-{
-  if (type->destructor.code)
-    semantic_type_redeclaration (type, "%destructor",
-                                 type->destructor.location,
-                                 destructor->location);
-  type->destructor = *destructor;
-}
-
-/*---------------------------------------.
-| Get the computed %destructor for SYM.  |
-`---------------------------------------*/
-
-code_props const *
-symbol_destructor_get (symbol const *sym)
-{
-  /* Per-symbol %destructor.  */
-  if (sym->destructor.code)
-    return &sym->destructor;
-
-  /* Per-type %destructor.  */
-  if (sym->type_name)
-    {
-      code_props const *destructor =
-        &semantic_type_get (sym->type_name)->destructor;
-      if (destructor->code)
-        return destructor;
-    }
-
-  /* Apply default %destructor's only to user-defined symbols.  */
-  if (sym->tag[0] == '$' || sym == errtoken)
-    return &code_props_none;
-
-  if (sym->type_name)
-    return &default_tagged_destructor;
-  return &default_tagless_destructor;
-}
-
-/*--------------------------------------.
-| Set the PRINTER associated with SYM.  |
-`--------------------------------------*/
+/*--------------------------------------------------------.
+| Set the DESTRUCTOR or PRINTER associated with the SYM.  |
+`--------------------------------------------------------*/
 
 void
-symbol_printer_set (symbol *sym, code_props const *printer)
+symbol_code_props_set (symbol *sym, code_props_type kind,
+                       code_props const *code)
 {
-  if (sym->printer.code)
-    symbol_redeclaration (sym, "%printer",
-                          sym->printer.location, printer->location);
-  sym->printer = *printer;
+  if (sym->props[kind].code)
+    symbol_redeclaration (sym, code_props_type_string (kind),
+                          sym->props[kind].location,
+                          code->location);
+  sym->props[kind] = *code;
 }
 
-/*---------------------------------------.
-| Set the PRINTER associated with TYPE.  |
-`---------------------------------------*/
+/*-----------------------------------------------------.
+| Set the DESTRUCTOR or PRINTER associated with TYPE.  |
+`-----------------------------------------------------*/
 
 void
-semantic_type_printer_set (semantic_type *type, code_props const *printer)
+semantic_type_code_props_set (semantic_type *type,
+                              code_props_type kind,
+                              code_props const *code)
 {
-  if (type->printer.code)
-    semantic_type_redeclaration (type, "%printer",
-                                 type->printer.location, printer->location);
-  type->printer = *printer;
+  if (type->props[kind].code)
+    semantic_type_redeclaration (type, code_props_type_string (kind),
+                                 type->props[kind].location,
+                                 code->location);
+  type->props[kind] = *code;
 }
 
-/*------------------------------------.
-| Get the computed %printer for SYM.  |
-`------------------------------------*/
+/*---------------------------------------------------.
+| Get the computed %destructor or %printer for SYM.  |
+`---------------------------------------------------*/
 
 code_props const *
-symbol_printer_get (symbol const *sym)
+symbol_code_props_get (symbol const *sym,
+                       code_props_type kind)
 {
-  /* Per-symbol %printer.  */
-  if (sym->printer.code)
-    return &sym->printer;
+  /* Per-symbol code props.  */
+  if (sym->props[kind].code)
+    return &sym->props[kind];
 
-  /* Per-type %printer.  */
+  /* Per-type code props.  */
   if (sym->type_name)
     {
-      code_props const *printer = &semantic_type_get (sym->type_name)->printer;
-      if (printer->code)
-        return printer;
+      code_props const *code =
+        &semantic_type_get (sym->type_name)->props[kind];
+      if (code->code)
+        return code;
     }
 
-  /* Apply the default %printer only to user-defined symbols.  */
+  /* Apply default code props's only to user-defined symbols.  */
   if (sym->tag[0] == '$' || sym == errtoken)
     return &code_props_none;
 
   if (sym->type_name)
-    return &default_tagged_printer;
-  return &default_tagless_printer;
+    return &default_tagged_code_props[kind];
+  return &default_tagless_code_props[kind];
 }
 
 /*-----------------------------------------------------------------.
@@ -504,21 +477,11 @@ symbol_check_alias_consistency (symbol *this)
     }
 
 
-  if (str->destructor.code || sym->destructor.code)
-    {
-      if (str->destructor.code)
-        symbol_destructor_set (sym, &str->destructor);
-      else
-        symbol_destructor_set (str, &sym->destructor);
-    }
-
-  if (str->printer.code || sym->printer.code)
-    {
-      if (str->printer.code)
-        symbol_printer_set (sym, &str->printer);
-      else
-        symbol_printer_set (str, &sym->printer);
-    }
+  for (int i = 0; i < CODE_PROPS_SIZE; ++i)
+    if (str->props[i].code)
+      symbol_code_props_set (sym, i, &str->props[i]);
+    else if (sym->props[i].code)
+      symbol_code_props_set (str, i, &sym->props[i]);
 
   if (sym->prec || str->prec)
     {
@@ -974,53 +937,30 @@ symbols_pack (void)
 `--------------------------------------------------*/
 
 void
-default_tagged_destructor_set (code_props const *destructor)
-{
-  if (default_tagged_destructor.code)
-    {
-      complain_at (destructor->location,
-                   _("redeclaration for default tagged %%destructor"));
-      complain_at (default_tagged_destructor.location,
-                   _("previous declaration"));
-    }
-  default_tagged_destructor = *destructor;
-}
-
-void
-default_tagless_destructor_set (code_props const *destructor)
+default_tagged_code_props_set (code_props_type kind, code_props const *code)
 {
-  if (default_tagless_destructor.code)
+  if (default_tagged_code_props[kind].code)
     {
-      complain_at (destructor->location,
-                   _("redeclaration for default tagless %%destructor"));
-      complain_at (default_tagless_destructor.location,
+      complain_at (code->location,
+                   _("redeclaration for default tagged %s"),
+                   code_props_type_string (kind));
+      complain_at (default_tagged_code_props[kind].location,
                    _("previous declaration"));
     }
-  default_tagless_destructor = *destructor;
+  default_tagged_code_props[kind] = *code;
 }
 
 void
-default_tagged_printer_set (code_props const *printer)
+default_tagless_code_props_set (code_props_type kind, code_props const *code)
 {
-  if (default_tagged_printer.code)
+  if (default_tagless_code_props[kind].code)
     {
-      complain_at (printer->location,
-                   _("redeclaration for default tagged %%printer"));
-      complain_at (default_tagged_printer.location,
+      complain_at (code->location,
+                   _("redeclaration for default tagless %s"),
+                   code_props_type_string (kind));
+      complain_at (default_tagless_code_props[kind].location,
                    _("previous declaration"));
     }
-  default_tagged_printer = *printer;
+  default_tagless_code_props[kind] = *code;
 }
 
-void
-default_tagless_printer_set (code_props const *printer)
-{
-  if (default_tagless_printer.code)
-    {
-      complain_at (printer->location,
-                   _("redeclaration for default tagless %%printer"));
-      complain_at (default_tagless_printer.location,
-                   _("previous declaration"));
-    }
-  default_tagless_printer = *printer;
-}
