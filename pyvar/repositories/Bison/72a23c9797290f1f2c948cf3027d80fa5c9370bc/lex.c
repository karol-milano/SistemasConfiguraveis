@@ -364,9 +364,13 @@ lex (void)
 	obstack_1grow (&token_obstack, '\0');
 	token_buffer = obstack_finish (&token_obstack);
 	symval = getsym (token_buffer);
-	symval->class = token_sym;
-	if (symval->user_token_number == SUNDEF)
-	  symval->user_token_number = code;
+	if (symval->number == -1)
+	  {
+	    symval->number = ntokens++;
+	    symval->class = token_sym;
+	    if (symval->user_token_number == SUNDEF)
+	      symval->user_token_number = code;
+	  }
 	return tok_identifier;
       }
 
@@ -388,7 +392,11 @@ lex (void)
 	token_buffer = obstack_finish (&token_obstack);
 
 	symval = getsym (token_buffer);
-	symval->class = token_sym;
+	if (symval->number == -1)
+	  {
+	    symval->number = ntokens++;
+	    symval->class = token_sym;
+	  }
 
 	return tok_identifier;
       }
