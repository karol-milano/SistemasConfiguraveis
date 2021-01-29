@@ -70,9 +70,12 @@ bool tag_seen = false;
 static bool
 symbol_is_user_defined (symbol *sym)
 {
+  const bool eof_is_user_defined
+    = !endtoken->alias || STRNEQ (endtoken->alias->tag, "$end");
   return sym->tag[0] != '$'
+    && (eof_is_user_defined || (sym != endtoken && sym->alias != errtoken))
     && sym != errtoken && sym->alias != errtoken
-    && sym != undeftoken  && sym->alias != undeftoken;
+    && sym != undeftoken && sym->alias != undeftoken;
 }
 
 
