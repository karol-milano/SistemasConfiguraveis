@@ -118,8 +118,7 @@ symbol_type_set (symbol_t *symbol, location_t location, char *type_name)
 
 
 /*-------------------------------------------------------------------.
-| Set the DESTRUCTOR associated to SYMBOL.  Does nothing if passed 0 |
-| as DESTRUCTOR.                                                      |
+| Set the DESTRUCTOR associated to SYMBOL.  Do nothing if passed 0.  |
 `-------------------------------------------------------------------*/
 
 void
@@ -129,14 +128,33 @@ symbol_destructor_set (symbol_t *symbol, location_t location, char *destructor)
     {
       if (symbol->destructor)
 	complain_at (location,
-		     _("destructor redeclaration for %s"),
-		     symbol_tag_get (symbol));
+		     _("%s redeclaration for %s"),
+		     "%destructor", symbol_tag_get (symbol));
       symbol->destructor = destructor;
       symbol->destructor_location = location;
     }
 }
 
 
+/*----------------------------------------------------------------.
+| Set the PRITNER associated to SYMBOL.  Do nothing if passed 0.  |
+`----------------------------------------------------------------*/
+
+void
+symbol_printer_set (symbol_t *symbol, char *printer, location_t location)
+{
+  if (printer)
+    {
+      if (symbol->printer)
+	complain_at (location,
+		     _("%s redeclaration for %s"),
+		     "%printer", symbol_tag_get (symbol));
+      symbol->printer = printer;
+      symbol->printer_location = location;
+    }
+}
+
+
 /*------------------------------------------------------------------.
 | Set the PRECEDENCE associated to SYMBOL.  Does nothing if invoked |
 | with UNDEF_ASSOC as ASSOC.                                        |
