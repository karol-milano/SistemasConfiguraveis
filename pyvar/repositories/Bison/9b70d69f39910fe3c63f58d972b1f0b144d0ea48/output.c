@@ -254,7 +254,6 @@ prepare_symbols (void)
   MUSCLE_INSERT_INT ("tokens_number", ntokens);
   MUSCLE_INSERT_INT ("nterms_number", nvars);
   MUSCLE_INSERT_INT ("symbols_number", nsyms);
-  MUSCLE_INSERT_INT ("undef_token_number", undeftoken->content->number);
   MUSCLE_INSERT_INT ("user_token_number_max", max_user_token_number);
 
   muscle_insert_symbol_number_table ("translate",
