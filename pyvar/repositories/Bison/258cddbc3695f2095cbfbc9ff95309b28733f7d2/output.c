@@ -142,7 +142,6 @@ escaped_output (FILE *out, char const *string)
 static void
 prepare_symbols (void)
 {
-  MUSCLE_INSERT_BOOL ("token_table", token_table_flag);
   MUSCLE_INSERT_INT ("tokens_number", ntokens);
   MUSCLE_INSERT_INT ("nterms_number", nvars);
   MUSCLE_INSERT_INT ("undef_token_number", undeftoken->number);
@@ -624,6 +623,7 @@ prepare (void)
   MUSCLE_INSERT_BOOL ("nondeterministic_flag", nondeterministic_parser);
   MUSCLE_INSERT_BOOL ("synclines_flag", !no_lines_flag);
   MUSCLE_INSERT_BOOL ("tag_seen_flag", tag_seen);
+  MUSCLE_INSERT_BOOL ("token_table_flag", token_table_flag);
   MUSCLE_INSERT_BOOL ("use_push_for_pull_flag", use_push_for_pull_flag);
   MUSCLE_INSERT_BOOL ("yacc_flag", yacc_flag);
 
