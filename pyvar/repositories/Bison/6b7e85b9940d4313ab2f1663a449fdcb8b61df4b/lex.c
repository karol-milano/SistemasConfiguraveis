@@ -446,7 +446,7 @@ lex (void)
 	token_buffer = obstack_finish (&token_obstack);
 	symval = getsym (token_buffer);
 	symval->class = token_sym;
-	if (!symval->user_token_number)
+	if (symval->user_token_number == SUNDEF)
 	  symval->user_token_number = code;
 	return tok_identifier;
       }
