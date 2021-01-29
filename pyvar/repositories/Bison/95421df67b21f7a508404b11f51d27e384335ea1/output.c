@@ -549,8 +549,7 @@ prepare_symbol_definitions (void)
       MUSCLE_INSERT_INT (key, sym->content->user_token_number);
 
       SET_KEY ("is_token");
-      MUSCLE_INSERT_INT (key,
-                         i < ntokens && sym != undeftoken);
+      MUSCLE_INSERT_INT (key, i < ntokens);
 
       SET_KEY ("number");
       MUSCLE_INSERT_INT (key, sym->content->number);
