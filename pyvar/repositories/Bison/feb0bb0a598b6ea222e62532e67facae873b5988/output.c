@@ -198,9 +198,9 @@ static const char *
 symbol_tag (const symbol *sym)
 {
   const bool eof_is_user_defined
-    = !endtoken->alias || STRNEQ (endtoken->alias->tag, "$end");
+    = !eoftoken->alias || STRNEQ (eoftoken->alias->tag, "$end");
 
-  if (!eof_is_user_defined && sym->content == endtoken->content)
+  if (!eof_is_user_defined && sym->content == eoftoken->content)
     return "\"end of file\"";
   else if (sym->content == undeftoken->content)
     return "\"invalid token\"";
