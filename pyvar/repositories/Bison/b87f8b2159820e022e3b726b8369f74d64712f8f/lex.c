@@ -368,7 +368,7 @@ lex (void)
 	  {
 	    symval->number = ntokens++;
 	    symval->class = token_sym;
-	    if (symval->user_token_number == SUNDEF)
+	    if (symval->user_token_number == USER_NUMBER_UNDEFINED)
 	      symval->user_token_number = code;
 	  }
 	return tok_identifier;
