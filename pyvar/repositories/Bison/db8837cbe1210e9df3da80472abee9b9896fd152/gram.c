@@ -38,7 +38,7 @@ int nritems = 0;
 
 rule_t *rules = NULL;
 
-struct bucket **symbols = NULL;
+symbol_t **symbols = NULL;
 short *token_translations = NULL;
 
 int start_symbol = 0;
