@@ -550,7 +550,7 @@ prepare_symbol_definitions (void)
 
       SET_KEY ("is_token");
       MUSCLE_INSERT_INT (key,
-                         i < ntokens && sym != errtoken && sym != undeftoken);
+                         i < ntokens && sym != undeftoken);
 
       SET_KEY ("number");
       MUSCLE_INSERT_INT (key, sym->content->number);
