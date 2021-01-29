@@ -48,7 +48,7 @@ location startsymbol_location;
 static symbol *
 symbol_new (uniqstr tag, location loc)
 {
-  symbol *res = MALLOC (res, 1);
+  symbol *res = xmalloc (sizeof *res);
 
   uniqstr_assert (tag);
   res->tag = tag;
@@ -587,7 +587,8 @@ symbols_token_translations_init (void)
 	max_user_token_number = this->user_token_number;
     }
 
-  CALLOC (token_translations, max_user_token_number + 1);
+  token_translations = xnmalloc (max_user_token_number + 1,
+				 sizeof *token_translations);
 
   /* Initialize all entries for literal tokens to 2, the internal
      token number for $undefined, which represents all invalid inputs.
@@ -606,7 +607,7 @@ symbols_token_translations_init (void)
 void
 symbols_pack (void)
 {
-  CALLOC (symbols, nsyms);
+  symbols = xcalloc (nsyms, sizeof *symbols);
 
   symbols_do (symbol_check_alias_consistency_processor, NULL);
   symbols_do (symbol_pack_processor, NULL);
