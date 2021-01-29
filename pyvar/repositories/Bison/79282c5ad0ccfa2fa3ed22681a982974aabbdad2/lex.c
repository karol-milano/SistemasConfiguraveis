@@ -76,6 +76,7 @@ skip_white_space (void)
       switch (c)
 	{
 	case '/':
+	  /* FIXME: Should probably be merged with copy_comment.  */
 	  c = getc (finput);
 	  if (c != '*' && c != '/')
 	    {
@@ -130,7 +131,11 @@ skip_white_space (void)
     }
 }
 
-/* do a getc, but give error message if EOF encountered */
+
+/*-----------------------------------------------------.
+| Do a getc, but give error message if EOF encountered |
+`-----------------------------------------------------*/
+
 static int
 xgetc (FILE *f)
 {
@@ -334,7 +339,8 @@ lex (void)
     }
 
   c = skip_white_space ();
-  *token_buffer = c;		/* for error messages (token buffer always valid) */
+  /* for error messages (token buffer always valid) */
+  *token_buffer = c;
   token_buffer[1] = 0;
 
   switch (c)
@@ -432,7 +438,8 @@ lex (void)
 	int code;		/* ignored here */
 	p = token_buffer;
 	*p++ = '\"';
-	while (literalchar (&p, &code, '\"'))	/* read up to and including " */
+	/* Read up to and including ".  */
+	while (literalchar (&p, &code, '\"'))
 	  {
 	    if (p >= token_buffer + maxtoken - 4)
 	      p = grow_token_buffer (p);
