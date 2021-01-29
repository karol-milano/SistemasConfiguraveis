@@ -41,14 +41,19 @@ symbol *accept = NULL;
 symbol *startsymbol = NULL;
 location startsymbol_location;
 
-/*-----------------------------------.
-| Default %destructor and %printer.  |
-`-----------------------------------*/
+/*---------------------------------------.
+| Default %destructor's and %printer's.  |
+`---------------------------------------*/
+
+static const char *default_tagged_destructor = NULL;
+static location default_tagged_destructor_location;
+static const char *default_tagless_destructor = NULL;
+static location default_tagless_destructor_location;
 
-static const char *default_destructor = NULL;
-static location default_destructor_location;
-static const char *default_printer = NULL;
-static location default_printer_location;
+static const char *default_tagged_printer = NULL;
+static location default_tagged_printer_location;
+static const char *default_tagless_printer = NULL;
+static location default_tagless_printer_location;
 
 /*---------------------------------.
 | Create a new symbol, named TAG.  |
@@ -220,10 +225,13 @@ symbol_destructor_get (symbol *sym)
         return type->destructor;
     }
 
-  /* Apply the default %destructor only to user-defined symbols.  */
+  /* Apply default %destructor's only to user-defined symbols.  */
   if (sym->tag[0] == '$' || sym == errtoken)
     return NULL;
-  return default_destructor;
+
+  if (sym->type_name)
+    return default_tagged_destructor;
+  return default_tagless_destructor;
 }
 
 /*---------------------------------------------------------------.
@@ -240,8 +248,9 @@ symbol_destructor_location_get (symbol *sym)
       semantic_type *type = semantic_type_get (sym->type_name);
       if (type->destructor)
         return type->destructor_location;
+      return default_tagged_destructor_location;
     }
-  return default_destructor_location;
+  return default_tagless_destructor_location;
 }
 
 /*---------------------------------------------------------------.
@@ -300,7 +309,10 @@ symbol_printer_get (symbol *sym)
   /* Apply the default %printer only to user-defined symbols.  */
   if (sym->tag[0] == '$' || sym == errtoken)
     return NULL;
-  return default_printer;
+
+  if (sym->type_name)
+    return default_tagged_printer;
+  return default_tagless_printer;
 }
 
 /*------------------------------------------------------------.
@@ -317,8 +329,9 @@ symbol_printer_location_get (symbol *sym)
       semantic_type *type = semantic_type_get (sym->type_name);
       if (type->printer)
         return type->printer_location;
+      return default_tagged_printer_location;
     }
-  return default_printer_location;
+  return default_tagless_printer_location;
 }
 
 
@@ -924,30 +937,58 @@ symbols_pack (void)
 }
 
 
-/*-----------------------------------.
-| Set default %destructor/%printer.  |
-`-----------------------------------*/
+/*--------------------------------------------------.
+| Set default tagged/tagless %destructor/%printer.  |
+`--------------------------------------------------*/
+
+void
+default_tagged_destructor_set (const char *destructor, location loc)
+{
+  if (default_tagged_destructor != NULL)
+    {
+      complain_at (loc, _("redeclaration for default tagged %%destructor"));
+      complain_at (default_tagged_destructor_location,
+		   _("previous declaration"));
+    }
+  default_tagged_destructor = destructor;
+  default_tagged_destructor_location = loc;
+}
+
+void
+default_tagless_destructor_set (const char *destructor, location loc)
+{
+  if (default_tagless_destructor != NULL)
+    {
+      complain_at (loc, _("redeclaration for default tagless %%destructor"));
+      complain_at (default_tagless_destructor_location,
+		   _("previous declaration"));
+    }
+  default_tagless_destructor = destructor;
+  default_tagless_destructor_location = loc;
+}
 
 void
-default_destructor_set (const char *destructor, location loc)
+default_tagged_printer_set (const char *printer, location loc)
 {
-  if (default_destructor != NULL)
+  if (default_tagged_printer != NULL)
     {
-      complain_at (loc, _("redeclaration for default %%destructor"));
-      complain_at (default_destructor_location, _("previous declaration"));
+      complain_at (loc, _("redeclaration for default tagged %%printer"));
+      complain_at (default_tagged_printer_location,
+		   _("previous declaration"));
     }
-  default_destructor = destructor;
-  default_destructor_location = loc;
+  default_tagged_printer = printer;
+  default_tagged_printer_location = loc;
 }
 
 void
-default_printer_set (const char *printer, location loc)
+default_tagless_printer_set (const char *printer, location loc)
 {
-  if (default_printer != NULL)
+  if (default_tagless_printer != NULL)
     {
-      complain_at (loc, _("redeclaration for default %%printer"));
-      complain_at (default_printer_location, _("previous declaration"));
+      complain_at (loc, _("redeclaration for default tagless %%printer"));
+      complain_at (default_tagless_printer_location,
+		   _("previous declaration"));
     }
-  default_printer = printer;
-  default_printer_location = loc;
+  default_tagless_printer = printer;
+  default_tagless_printer_location = loc;
 }
