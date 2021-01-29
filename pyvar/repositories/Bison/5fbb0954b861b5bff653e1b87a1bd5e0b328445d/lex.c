@@ -364,7 +364,7 @@ lex (void)
 	obstack_1grow (&token_obstack, '\0');
 	token_buffer = obstack_finish (&token_obstack);
 	symval = getsym (token_buffer);
-	if (symval->number == -1)
+	if (symval->number == NUMBER_UNDEFINED)
 	  {
 	    symval->number = ntokens++;
 	    symval->class = token_sym;
@@ -392,7 +392,7 @@ lex (void)
 	token_buffer = obstack_finish (&token_obstack);
 
 	symval = getsym (token_buffer);
-	if (symval->number == -1)
+	if (symval->number == NUMBER_UNDEFINED)
 	  {
 	    symval->number = ntokens++;
 	    symval->class = token_sym;
