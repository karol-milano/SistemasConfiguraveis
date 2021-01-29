@@ -59,6 +59,34 @@ symbol_new (const char *tag)
 }
 
 
+/*-----------------------------------------.
+| Set the TYPE_NAME associated to SYMBOL.  |
+`-----------------------------------------*/
+
+void
+symbol_type_set (symbol_t *symbol, char *type_name)
+{
+  if (symbol->type_name)
+    complain (_("type redeclaration for %s"), symbol->tag);
+  symbol->type_name = type_name;
+}
+
+
+/*------------------------------------------.
+| Set the PRECEDENCE associated to SYMBOL.  |
+`------------------------------------------*/
+
+void
+symbol_precedence_set (symbol_t *symbol,
+		       int prec, associativity assoc)
+{
+  if (symbol->prec != 0)
+    complain (_("redefining precedence of %s"), symbol->tag);
+  symbol->prec = prec;
+  symbol->assoc = assoc;
+}
+
+
 /*------------.
 | Free THIS.  |
 `------------*/
