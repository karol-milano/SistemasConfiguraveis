@@ -145,6 +145,7 @@ escaped_output (FILE *out, char const *string)
 static void
 prepare_symbols (void)
 {
+  MUSCLE_INSERT_BOOL ("token_table", token_table_flag);
   MUSCLE_INSERT_INT ("tokens_number", ntokens);
   MUSCLE_INSERT_INT ("nterms_number", nvars);
   MUSCLE_INSERT_INT ("undef_token_number", undeftoken->number);
