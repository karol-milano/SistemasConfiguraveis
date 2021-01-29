@@ -163,12 +163,14 @@ symbol_destructor_set (symbol *sym, const char *destructor, location loc)
 const char *
 symbol_destructor_get (symbol *sym)
 {
-  /* Token 0 cannot have a %destructor unless the user renames it.  */
-  if (UNIQSTR_EQ (sym->tag, uniqstr_new ("$end")))
-    return NULL;
-
+  /* Per-symbol %destructor.  */
   if (sym->destructor != NULL)
     return sym->destructor;
+
+  /* Apply the default %destructor only to user-defined symbols.  */
+  if (sym == errtoken || sym == undeftoken || sym == accept
+      || UNIQSTR_EQ (sym->tag, uniqstr_new ("$end")))
+    return NULL;
   return default_destructor;
 }
 
@@ -207,12 +209,14 @@ symbol_printer_set (symbol *sym, const char *printer, location loc)
 const char *
 symbol_printer_get (symbol *sym)
 {
-  /* Token 0 cannot have a %printer unless the user renames it.  */
-  if (UNIQSTR_EQ (sym->tag, uniqstr_new ("$end")))
-    return NULL;
-
+  /* Per-symbol %printer.  */
   if (sym->printer != NULL)
     return sym->printer;
+
+  /* Apply the default %printer only to user-defined symbols.  */
+  if (sym == errtoken || sym == undeftoken || sym == accept
+      || UNIQSTR_EQ (sym->tag, uniqstr_new ("$end")))
+    return NULL;
   return default_printer;
 }
 
