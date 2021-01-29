@@ -48,6 +48,7 @@ symbol_new (const char *tag, location_t location)
 
   res->tag = xstrdup (tag);
   res->type_name = NULL;
+  res->destructor = NULL;
   res->location = location;
   res->number = NUMBER_UNDEFINED;
   res->prec = 0;
@@ -114,6 +115,25 @@ symbol_type_set (symbol_t *symbol, location_t location, char *type_name)
 }
 
 
+/*-------------------------------------------------------------------.
+| Set the DESTRUCTOR associated to SYMBOL.  Does nothing if passed 0 |
+| as DESTRUCTOR.                                                      |
+`-------------------------------------------------------------------*/
+
+void
+symbol_destructor_set (symbol_t *symbol, location_t location, char *destructor)
+{
+  if (destructor)
+    {
+      if (symbol->destructor)
+	complain_at (location,
+		     _("destructor redeclaration for %s"),
+		     symbol_tag_get (symbol));
+      symbol->destructor = destructor;
+    }
+}
+
+
 /*------------------------------------------------------------------.
 | Set the PRECEDENCE associated to SYMBOL.  Does nothing if invoked |
 | with UNDEF_ASSOC as ASSOC.                                        |
