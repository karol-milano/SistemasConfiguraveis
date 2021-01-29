@@ -47,9 +47,11 @@ symbol_new (const char *tag, location_t location)
   symbol_t *res = XMALLOC (symbol_t, 1);
 
   res->tag = xstrdup (tag);
+  res->location = location;
+
   res->type_name = NULL;
   res->destructor = NULL;
-  res->location = location;
+
   res->number = NUMBER_UNDEFINED;
   res->prec = 0;
   res->assoc = right_assoc;
@@ -130,6 +132,7 @@ symbol_destructor_set (symbol_t *symbol, location_t location, char *destructor)
 		     _("destructor redeclaration for %s"),
 		     symbol_tag_get (symbol));
       symbol->destructor = destructor;
+      symbol->destructor_location = location;
     }
 }
 
