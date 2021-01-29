@@ -45,15 +45,10 @@ location startsymbol_location;
 | Default %destructor's and %printer's.  |
 `---------------------------------------*/
 
-static const char *default_tagged_destructor = NULL;
-static location default_tagged_destructor_location;
-static const char *default_tagless_destructor = NULL;
-static location default_tagless_destructor_location;
-
-static const char *default_tagged_printer = NULL;
-static location default_tagged_printer_location;
-static const char *default_tagless_printer = NULL;
-static location default_tagless_printer_location;
+static code_props default_tagged_destructor = CODE_PROPS_NONE_INIT;
+static code_props default_tagless_destructor = CODE_PROPS_NONE_INIT;
+static code_props default_tagged_printer = CODE_PROPS_NONE_INIT;
+static code_props default_tagless_printer = CODE_PROPS_NONE_INIT;
 
 /*---------------------------------.
 | Create a new symbol, named TAG.  |
@@ -69,8 +64,8 @@ symbol_new (uniqstr tag, location loc)
   res->location = loc;
 
   res->type_name = NULL;
-  res->destructor = NULL;
-  res->printer = NULL;
+  code_props_none_init (&res->destructor);
+  code_props_none_init (&res->printer);
 
   res->number = NUMBER_UNDEFINED;
   res->prec = 0;
@@ -99,8 +94,8 @@ semantic_type_new (uniqstr tag)
 
   uniqstr_assert (tag);
   res->tag = tag;
-  res->destructor = NULL;
-  res->printer = NULL;
+  code_props_none_init (&res->destructor);
+  code_props_none_init (&res->printer);
 
   return res;
 }
@@ -114,6 +109,10 @@ semantic_type_new (uniqstr tag)
   if (s->Attr)						\
     fprintf (f, " %s { %s }", #Attr, s->Attr)
 
+#define SYMBOL_CODE_PRINT(Attr)				\
+  if (code_props_code_get (s->Attr))			\
+    fprintf (f, " %s { %s }", #Attr, code_props_code_get(s->Attr))
+
 void
 symbol_print (symbol *s, FILE *f)
 {
@@ -121,14 +120,15 @@ symbol_print (symbol *s, FILE *f)
     {
       fprintf (f, "\"%s\"", s->tag);
       SYMBOL_ATTR_PRINT (type_name);
-      SYMBOL_ATTR_PRINT (destructor);
-      SYMBOL_ATTR_PRINT (printer);
+      SYMBOL_CODE_PRINT (destructor);
+      SYMBOL_CODE_PRINT (printer);
     }
   else
     fprintf (f, "<NULL>");
 }
 
 #undef SYMBOL_ATTR_PRINT
+#undef SYMBOL_CODE_PRINT
 
 /*------------------------------------------------------------------.
 | Complain that S's WHAT is redeclared at SECOND, and was first set |
@@ -171,170 +171,118 @@ symbol_type_set (symbol *sym, uniqstr type_name, location loc)
 }
 
 
-/*------------------------------------------------------------------.
-| Set the DESTRUCTOR associated with SYM.  Do nothing if passed 0.  |
-`------------------------------------------------------------------*/
+/*-----------------------------------------.
+| Set the DESTRUCTOR associated with SYM.  |
+`-----------------------------------------*/
 
 void
-symbol_destructor_set (symbol *sym, const char *destructor, location loc)
+symbol_destructor_set (symbol *sym, code_props destructor)
 {
-  if (destructor)
-    {
-      if (sym->destructor)
-	symbol_redeclaration (sym, "%destructor", sym->destructor_location,
-                              loc);
-      sym->destructor = destructor;
-      sym->destructor_location = loc;
-    }
+  if (code_props_code_get (sym->destructor))
+    symbol_redeclaration (sym, "%destructor",
+                          code_props_location_get (sym->destructor),
+                          code_props_location_get (destructor));
+  sym->destructor = destructor;
 }
 
-/*-------------------------------------------------------------------.
-| Set the DESTRUCTOR associated with TYPE.  Do nothing if passed 0.  |
-`-------------------------------------------------------------------*/
+/*------------------------------------------.
+| Set the DESTRUCTOR associated with TYPE.  |
+`------------------------------------------*/
 
 void
-semantic_type_destructor_set (semantic_type *type, const char *destructor,
-                              location loc)
+semantic_type_destructor_set (semantic_type *type, code_props destructor)
 {
-  if (destructor)
-    {
-      if (type->destructor)
-	semantic_type_redeclaration (type, "%destructor",
-                                     type->destructor_location, loc);
-      type->destructor = destructor;
-      type->destructor_location = loc;
-    }
+  if (code_props_code_get (type->destructor))
+    semantic_type_redeclaration (type, "%destructor",
+                                 code_props_location_get (type->destructor),
+                                 code_props_location_get (destructor));
+  type->destructor = destructor;
 }
 
 /*---------------------------------------.
 | Get the computed %destructor for SYM.  |
 `---------------------------------------*/
 
-const char *
+code_props
 symbol_destructor_get (symbol *sym)
 {
   /* Per-symbol %destructor.  */
-  if (sym->destructor != NULL)
+  if (code_props_code_get (sym->destructor))
     return sym->destructor;
 
   /* Per-type %destructor.  */
   if (sym->type_name)
     {
-      semantic_type *type = semantic_type_get (sym->type_name);
-      if (type->destructor)
-        return type->destructor;
+      code_props destructor = semantic_type_get (sym->type_name)->destructor;
+      if (code_props_code_get (destructor))
+        return destructor;
     }
 
   /* Apply default %destructor's only to user-defined symbols.  */
   if (sym->tag[0] == '$' || sym == errtoken)
-    return NULL;
+    return code_props_none;
 
   if (sym->type_name)
     return default_tagged_destructor;
   return default_tagless_destructor;
 }
 
-/*---------------------------------------------------------------.
-| Get the grammar location of the %destructor computed for SYM.  |
-`---------------------------------------------------------------*/
-
-location
-symbol_destructor_location_get (symbol *sym)
-{
-  if (sym->destructor != NULL)
-    return sym->destructor_location;
-  if (sym->type_name)
-    {
-      semantic_type *type = semantic_type_get (sym->type_name);
-      if (type->destructor)
-        return type->destructor_location;
-      return default_tagged_destructor_location;
-    }
-  return default_tagless_destructor_location;
-}
-
-/*---------------------------------------------------------------.
-| Set the PRINTER associated with SYM.  Do nothing if passed 0.  |
-`---------------------------------------------------------------*/
+/*--------------------------------------.
+| Set the PRINTER associated with SYM.  |
+`--------------------------------------*/
 
 void
-symbol_printer_set (symbol *sym, const char *printer, location loc)
+symbol_printer_set (symbol *sym, code_props printer)
 {
-  if (printer)
-    {
-      if (sym->printer)
-	symbol_redeclaration (sym, "%printer", sym->printer_location, loc);
-      sym->printer = printer;
-      sym->printer_location = loc;
-    }
+  if (code_props_code_get (sym->printer))
+    symbol_redeclaration (sym, "%printer",
+                          code_props_location_get (sym->printer),
+                          code_props_location_get (printer));
+  sym->printer = printer;
 }
 
-/*----------------------------------------------------------------.
-| Set the PRINTER associated with TYPE.  Do nothing if passed 0.  |
-`----------------------------------------------------------------*/
+/*---------------------------------------.
+| Set the PRINTER associated with TYPE.  |
+`---------------------------------------*/
 
 void
-semantic_type_printer_set (semantic_type *type, const char *printer,
-                           location loc)
+semantic_type_printer_set (semantic_type *type, code_props printer)
 {
-  if (printer)
-    {
-      if (type->printer)
-	semantic_type_redeclaration (type, "%printer", type->printer_location,
-                                     loc);
-      type->printer = printer;
-      type->printer_location = loc;
-    }
+  if (code_props_code_get (type->printer))
+    semantic_type_redeclaration (type, "%printer",
+                                 code_props_location_get (type->printer),
+                                 code_props_location_get (printer));
+  type->printer = printer;
 }
 
 /*------------------------------------.
 | Get the computed %printer for SYM.  |
 `------------------------------------*/
 
-const char *
+code_props
 symbol_printer_get (symbol *sym)
 {
   /* Per-symbol %printer.  */
-  if (sym->printer != NULL)
+  if (code_props_code_get (sym->printer))
     return sym->printer;
 
   /* Per-type %printer.  */
   if (sym->type_name)
     {
-      semantic_type *type = semantic_type_get (sym->type_name);
-      if (type->printer)
-        return type->printer;
+      code_props printer = semantic_type_get (sym->type_name)->printer;
+      if (code_props_code_get (printer))
+        return printer;
     }
 
   /* Apply the default %printer only to user-defined symbols.  */
   if (sym->tag[0] == '$' || sym == errtoken)
-    return NULL;
+    return code_props_none;
 
   if (sym->type_name)
     return default_tagged_printer;
   return default_tagless_printer;
 }
 
-/*------------------------------------------------------------.
-| Get the grammar location of the %printer computed for SYM.  |
-`------------------------------------------------------------*/
-
-location
-symbol_printer_location_get (symbol *sym)
-{
-  if (sym->printer != NULL)
-    return sym->printer_location;
-  if (sym->type_name)
-    {
-      semantic_type *type = semantic_type_get (sym->type_name);
-      if (type->printer)
-        return type->printer_location;
-      return default_tagged_printer_location;
-    }
-  return default_tagless_printer_location;
-}
-
-
 /*-----------------------------------------------------------------.
 | Set the PRECEDENCE associated with SYM.  Does nothing if invoked |
 | with UNDEF_ASSOC as ASSOC.                                       |
@@ -498,22 +446,22 @@ symbol_check_alias_consistency (symbol *this)
     }
 
 
-  if (orig->destructor || alias->destructor)
+  if (code_props_code_get (orig->destructor)
+      || code_props_code_get (alias->destructor))
     {
-      if (orig->destructor)
-	symbol_destructor_set (alias, orig->destructor,
-			       orig->destructor_location);
+      if (code_props_code_get (orig->destructor))
+	symbol_destructor_set (alias, orig->destructor);
       else
-	symbol_destructor_set (orig, alias->destructor,
-			       alias->destructor_location);
+	symbol_destructor_set (orig, alias->destructor);
     }
 
-  if (orig->printer || alias->printer)
+  if (code_props_code_get (orig->printer)
+      || code_props_code_get (alias->printer))
     {
-      if (orig->printer)
-	symbol_printer_set (alias, orig->printer, orig->printer_location);
+      if (code_props_code_get (orig->printer))
+	symbol_printer_set (alias, orig->printer);
       else
-	symbol_printer_set (orig, alias->printer, alias->printer_location);
+	symbol_printer_set (orig, alias->printer);
     }
 
   if (alias->prec || orig->prec)
@@ -942,53 +890,54 @@ symbols_pack (void)
 `--------------------------------------------------*/
 
 void
-default_tagged_destructor_set (const char *destructor, location loc)
+default_tagged_destructor_set (code_props destructor)
 {
-  if (default_tagged_destructor != NULL)
+  if (code_props_code_get (default_tagged_destructor))
     {
-      complain_at (loc, _("redeclaration for default tagged %%destructor"));
-      complain_at (default_tagged_destructor_location,
+      complain_at (code_props_location_get (destructor),
+                   _("redeclaration for default tagged %%destructor"));
+      complain_at (code_props_location_get (default_tagged_destructor),
 		   _("previous declaration"));
     }
   default_tagged_destructor = destructor;
-  default_tagged_destructor_location = loc;
 }
 
 void
-default_tagless_destructor_set (const char *destructor, location loc)
+default_tagless_destructor_set (code_props destructor)
 {
-  if (default_tagless_destructor != NULL)
+  if (code_props_code_get (default_tagless_destructor))
     {
-      complain_at (loc, _("redeclaration for default tagless %%destructor"));
-      complain_at (default_tagless_destructor_location,
+      complain_at (code_props_location_get (destructor),
+                   _("redeclaration for default tagless %%destructor"));
+      complain_at (code_props_location_get (default_tagless_destructor),
 		   _("previous declaration"));
     }
   default_tagless_destructor = destructor;
-  default_tagless_destructor_location = loc;
 }
 
 void
-default_tagged_printer_set (const char *printer, location loc)
+default_tagged_printer_set (code_props printer)
 {
-  if (default_tagged_printer != NULL)
+  if (code_props_code_get (default_tagged_printer))
     {
-      complain_at (loc, _("redeclaration for default tagged %%printer"));
-      complain_at (default_tagged_printer_location,
+      complain_at (code_props_location_get (printer),
+                   _("redeclaration for default tagged %%printer"));
+      complain_at (code_props_location_get (default_tagged_printer),
 		   _("previous declaration"));
     }
   default_tagged_printer = printer;
-  default_tagged_printer_location = loc;
 }
 
 void
-default_tagless_printer_set (const char *printer, location loc)
+default_tagless_printer_set (code_props printer)
 {
-  if (default_tagless_printer != NULL)
+  if (code_props_code_get (default_tagless_printer))
     {
-      complain_at (loc, _("redeclaration for default tagless %%printer"));
-      complain_at (default_tagless_printer_location,
+      complain_at (code_props_location_get (printer),
+                   _("redeclaration for default tagless %%printer"));
+      complain_at (code_props_location_get (default_tagless_printer),
 		   _("previous declaration"));
     }
   default_tagless_printer = printer;
-  default_tagless_printer_location = loc;
 }
+
