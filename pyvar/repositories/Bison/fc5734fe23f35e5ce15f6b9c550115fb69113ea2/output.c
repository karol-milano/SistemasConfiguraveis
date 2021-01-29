@@ -305,8 +305,9 @@ static void
 prepare_tokens (void)
 {
   muscle_insert_symbol_number_table ("translate",
-				    token_translations,
-				    0, 1, max_user_token_number + 1);
+				     token_translations,
+				     token_translations[0],
+				     1, max_user_token_number + 1);
 
   {
     int i;
