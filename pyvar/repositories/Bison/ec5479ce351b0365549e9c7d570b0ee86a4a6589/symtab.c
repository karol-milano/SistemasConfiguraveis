@@ -41,6 +41,15 @@ symbol *accept = NULL;
 symbol *startsymbol = NULL;
 location startsymbol_location;
 
+/*-----------------------------------.
+| Default %destructor and %printer.  |
+`-----------------------------------*/
+
+static const char *default_destructor = NULL;
+static location default_destructor_location;
+static const char *default_printer = NULL;
+static location default_printer_location;
+
 /*---------------------------------.
 | Create a new symbol, named TAG.  |
 `---------------------------------*/
@@ -147,6 +156,33 @@ symbol_destructor_set (symbol *sym, const char *destructor, location loc)
     }
 }
 
+/*---------------------------------------.
+| Get the computed %destructor for SYM.  |
+`---------------------------------------*/
+
+const char *
+symbol_destructor_get (symbol *sym)
+{
+  /* Token 0 cannot have a %destructor unless the user renames it.  */
+  if (UNIQSTR_EQ (sym->tag, uniqstr_new ("$end")))
+    return NULL;
+
+  if (sym->destructor != NULL)
+    return sym->destructor;
+  return default_destructor;
+}
+
+/*---------------------------------------------------------------.
+| Get the grammar location of the %destructor computed for SYM.  |
+`---------------------------------------------------------------*/
+
+location
+symbol_destructor_location_get (symbol *sym)
+{
+  if (sym->destructor != NULL)
+    return sym->destructor_location;
+  return default_destructor_location;
+}
 
 /*---------------------------------------------------------------.
 | Set the PRINTER associated with SYM.  Do nothing if passed 0.  |
@@ -164,6 +200,34 @@ symbol_printer_set (symbol *sym, const char *printer, location loc)
     }
 }
 
+/*------------------------------------.
+| Get the computed %printer for SYM.  |
+`------------------------------------*/
+
+const char *
+symbol_printer_get (symbol *sym)
+{
+  /* Token 0 cannot have a %printer unless the user renames it.  */
+  if (UNIQSTR_EQ (sym->tag, uniqstr_new ("$end")))
+    return NULL;
+
+  if (sym->printer != NULL)
+    return sym->printer;
+  return default_printer;
+}
+
+/*------------------------------------------------------------.
+| Get the grammar location of the %printer computed for SYM.  |
+`------------------------------------------------------------*/
+
+location
+symbol_printer_location_get (symbol *sym)
+{
+  if (sym->printer != NULL)
+    return sym->printer_location;
+  return default_printer_location;
+}
+
 
 /*-----------------------------------------------------------------.
 | Set the PRECEDENCE associated with SYM.  Does nothing if invoked |
@@ -666,3 +730,32 @@ symbols_pack (void)
 	      _("the start symbol %s is a token"),
 	      startsymbol->tag);
 }
+
+
+/*-----------------------------------.
+| Set default %destructor/%printer.  |
+`-----------------------------------*/
+
+void
+default_destructor_set (const char *destructor, location loc)
+{
+  if (default_destructor != NULL)
+    {
+      complain_at (loc, _("redeclaration for default %%destructor"));
+      complain_at (default_destructor_location, _("previous declaration"));
+    }
+  default_destructor = destructor;
+  default_destructor_location = loc;
+}
+
+void
+default_printer_set (const char *printer, location loc)
+{
+  if (default_printer != NULL)
+    {
+      complain_at (loc, _("redeclaration for default %%printer"));
+      complain_at (default_printer_location, _("previous declaration"));
+    }
+  default_printer = printer;
+  default_printer_location = loc;
+}
