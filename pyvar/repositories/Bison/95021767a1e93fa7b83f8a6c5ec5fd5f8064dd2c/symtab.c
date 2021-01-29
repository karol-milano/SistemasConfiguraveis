@@ -1,6 +1,6 @@
 /* Symbol table manager for Bison.
 
-   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2004, 2005, 2006 Free
+   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2004, 2005, 2006, 2007 Free
    Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
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
 
+#define SYMBOL_CODE_PRINT(Attr)                         \
+  if (s->Attr.code)                                     \
+    fprintf (f, " %s { %s }", #Attr, s->Attr.code)
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
@@ -171,170 +171,117 @@ symbol_type_set (symbol *sym, uniqstr type_name, location loc)
 }
 
 
-/*------------------------------------------------------------------.
-| Set the DESTRUCTOR associated with SYM.  Do nothing if passed 0.  |
-`------------------------------------------------------------------*/
+/*-----------------------------------------.
+| Set the DESTRUCTOR associated with SYM.  |
+`-----------------------------------------*/
 
 void
-symbol_destructor_set (symbol *sym, const char *destructor, location loc)
+symbol_destructor_set (symbol *sym, code_props const *destructor)
 {
-  if (destructor)
-    {
-      if (sym->destructor)
-	symbol_redeclaration (sym, "%destructor", sym->destructor_location,
-                              loc);
-      sym->destructor = destructor;
-      sym->destructor_location = loc;
-    }
+  if (sym->destructor.code)
+    symbol_redeclaration (sym, "%destructor", sym->destructor.location,
+                          destructor->location);
+  sym->destructor = *destructor;
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
+semantic_type_destructor_set (semantic_type *type,
+                              code_props const *destructor)
 {
-  if (destructor)
-    {
-      if (type->destructor)
-	semantic_type_redeclaration (type, "%destructor",
-                                     type->destructor_location, loc);
-      type->destructor = destructor;
-      type->destructor_location = loc;
-    }
+  if (type->destructor.code)
+    semantic_type_redeclaration (type, "%destructor",
+                                 type->destructor.location,
+                                 destructor->location);
+  type->destructor = *destructor;
 }
 
 /*---------------------------------------.
 | Get the computed %destructor for SYM.  |
 `---------------------------------------*/
 
-const char *
-symbol_destructor_get (symbol *sym)
+code_props const *
+symbol_destructor_get (symbol const *sym)
 {
   /* Per-symbol %destructor.  */
-  if (sym->destructor != NULL)
-    return sym->destructor;
+  if (sym->destructor.code)
+    return &sym->destructor;
 
   /* Per-type %destructor.  */
   if (sym->type_name)
     {
-      semantic_type *type = semantic_type_get (sym->type_name);
-      if (type->destructor)
-        return type->destructor;
+      code_props const *destructor =
+        &semantic_type_get (sym->type_name)->destructor;
+      if (destructor->code)
+        return destructor;
     }
 
   /* Apply default %destructor's only to user-defined symbols.  */
   if (sym->tag[0] == '$' || sym == errtoken)
-    return NULL;
+    return &code_props_none;
 
   if (sym->type_name)
-    return default_tagged_destructor;
-  return default_tagless_destructor;
+    return &default_tagged_destructor;
+  return &default_tagless_destructor;
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
+symbol_printer_set (symbol *sym, code_props const *printer)
 {
-  if (printer)
-    {
-      if (sym->printer)
-	symbol_redeclaration (sym, "%printer", sym->printer_location, loc);
-      sym->printer = printer;
-      sym->printer_location = loc;
-    }
+  if (sym->printer.code)
+    symbol_redeclaration (sym, "%printer",
+                          sym->printer.location, printer->location);
+  sym->printer = *printer;
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
+semantic_type_printer_set (semantic_type *type, code_props const *printer)
 {
-  if (printer)
-    {
-      if (type->printer)
-	semantic_type_redeclaration (type, "%printer", type->printer_location,
-                                     loc);
-      type->printer = printer;
-      type->printer_location = loc;
-    }
+  if (type->printer.code)
+    semantic_type_redeclaration (type, "%printer",
+                                 type->printer.location, printer->location);
+  type->printer = *printer;
 }
 
 /*------------------------------------.
 | Get the computed %printer for SYM.  |
 `------------------------------------*/
 
-const char *
-symbol_printer_get (symbol *sym)
+code_props const *
+symbol_printer_get (symbol const *sym)
 {
   /* Per-symbol %printer.  */
-  if (sym->printer != NULL)
-    return sym->printer;
+  if (sym->printer.code)
+    return &sym->printer;
 
   /* Per-type %printer.  */
   if (sym->type_name)
     {
-      semantic_type *type = semantic_type_get (sym->type_name);
-      if (type->printer)
-        return type->printer;
+      code_props const *printer = &semantic_type_get (sym->type_name)->printer;
+      if (printer->code)
+        return printer;
     }
 
   /* Apply the default %printer only to user-defined symbols.  */
   if (sym->tag[0] == '$' || sym == errtoken)
-    return NULL;
+    return &code_props_none;
 
   if (sym->type_name)
-    return default_tagged_printer;
-  return default_tagless_printer;
+    return &default_tagged_printer;
+  return &default_tagless_printer;
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
@@ -498,22 +445,20 @@ symbol_check_alias_consistency (symbol *this)
     }
 
 
-  if (orig->destructor || alias->destructor)
+  if (orig->destructor.code || alias->destructor.code)
     {
-      if (orig->destructor)
-	symbol_destructor_set (alias, orig->destructor,
-			       orig->destructor_location);
+      if (orig->destructor.code)
+	symbol_destructor_set (alias, &orig->destructor);
       else
-	symbol_destructor_set (orig, alias->destructor,
-			       alias->destructor_location);
+	symbol_destructor_set (orig, &alias->destructor);
     }
 
-  if (orig->printer || alias->printer)
+  if (orig->printer.code || alias->printer.code)
     {
-      if (orig->printer)
-	symbol_printer_set (alias, orig->printer, orig->printer_location);
+      if (orig->printer.code)
+	symbol_printer_set (alias, &orig->printer);
       else
-	symbol_printer_set (orig, alias->printer, alias->printer_location);
+	symbol_printer_set (orig, &alias->printer);
     }
 
   if (alias->prec || orig->prec)
@@ -942,53 +887,54 @@ symbols_pack (void)
 `--------------------------------------------------*/
 
 void
-default_tagged_destructor_set (const char *destructor, location loc)
+default_tagged_destructor_set (code_props const *destructor)
 {
-  if (default_tagged_destructor != NULL)
+  if (default_tagged_destructor.code)
     {
-      complain_at (loc, _("redeclaration for default tagged %%destructor"));
-      complain_at (default_tagged_destructor_location,
+      complain_at (destructor->location,
+                   _("redeclaration for default tagged %%destructor"));
+      complain_at (default_tagged_destructor.location,
 		   _("previous declaration"));
     }
-  default_tagged_destructor = destructor;
-  default_tagged_destructor_location = loc;
+  default_tagged_destructor = *destructor;
 }
 
 void
-default_tagless_destructor_set (const char *destructor, location loc)
+default_tagless_destructor_set (code_props const *destructor)
 {
-  if (default_tagless_destructor != NULL)
+  if (default_tagless_destructor.code)
     {
-      complain_at (loc, _("redeclaration for default tagless %%destructor"));
-      complain_at (default_tagless_destructor_location,
+      complain_at (destructor->location,
+                   _("redeclaration for default tagless %%destructor"));
+      complain_at (default_tagless_destructor.location,
 		   _("previous declaration"));
     }
-  default_tagless_destructor = destructor;
-  default_tagless_destructor_location = loc;
+  default_tagless_destructor = *destructor;
 }
 
 void
-default_tagged_printer_set (const char *printer, location loc)
+default_tagged_printer_set (code_props const *printer)
 {
-  if (default_tagged_printer != NULL)
+  if (default_tagged_printer.code)
     {
-      complain_at (loc, _("redeclaration for default tagged %%printer"));
-      complain_at (default_tagged_printer_location,
+      complain_at (printer->location,
+                   _("redeclaration for default tagged %%printer"));
+      complain_at (default_tagged_printer.location,
 		   _("previous declaration"));
     }
-  default_tagged_printer = printer;
-  default_tagged_printer_location = loc;
+  default_tagged_printer = *printer;
 }
 
 void
-default_tagless_printer_set (const char *printer, location loc)
+default_tagless_printer_set (code_props const *printer)
 {
-  if (default_tagless_printer != NULL)
+  if (default_tagless_printer.code)
     {
-      complain_at (loc, _("redeclaration for default tagless %%printer"));
-      complain_at (default_tagless_printer_location,
+      complain_at (printer->location,
+                   _("redeclaration for default tagless %%printer"));
+      complain_at (default_tagless_printer.location,
 		   _("previous declaration"));
     }
-  default_tagless_printer = printer;
-  default_tagless_printer_location = loc;
+  default_tagless_printer = *printer;
 }
+
