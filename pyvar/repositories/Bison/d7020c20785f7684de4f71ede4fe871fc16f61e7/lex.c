@@ -418,7 +418,7 @@ lex (void)
 	*p++ = '\'';
 	*p = 0;
 	symval = getsym (token_buffer);
-	symval->class = STOKEN;
+	symval->class = token_sym;
 	if (!symval->user_token_number)
 	  symval->user_token_number = code;
 	return IDENTIFIER;
@@ -440,7 +440,7 @@ lex (void)
 	*p = 0;
 
 	symval = getsym (token_buffer);
-	symval->class = STOKEN;
+	symval->class = token_sym;
 
 	return IDENTIFIER;
       }
