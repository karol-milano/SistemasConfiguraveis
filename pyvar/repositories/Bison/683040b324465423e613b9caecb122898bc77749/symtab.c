@@ -305,9 +305,14 @@ is_identifier (uniqstr s)
 uniqstr
 symbol_id_get (symbol const *sym)
 {
-  if (sym->alias)
-    sym = sym->alias;
-  return is_identifier (sym->tag) ? sym->tag : 0;
+  // There's one weird case: YYerror is the alias, and error is the
+  // base symbol.  Return YYerror in that case.
+  if (sym->alias && is_identifier (sym->alias->tag))
+    return sym->alias->tag;
+  else if (is_identifier (sym->tag))
+    return sym->tag;
+  else
+    return NULL;
 }
 
 
