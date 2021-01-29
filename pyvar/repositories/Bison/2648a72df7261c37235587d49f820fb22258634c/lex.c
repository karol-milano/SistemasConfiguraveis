@@ -140,67 +140,62 @@ xgetc (FILE *f)
 }
 
 
-/*-----------------------------------------------------------------.
-| Read one literal character from FINPUT.  Process \-escapes.      |
-| Append the char to OUT and assign it *PCODE. Return 1 unless the |
-| character is an unescaped `term' or \n report error for \n.      |
-`-----------------------------------------------------------------*/
+/*---------------------------------------------------------------.
+| Read one literal character from FINPUT, process \-escapes, and |
+| return the character.                                          |
+`---------------------------------------------------------------*/
 
-int
-literalchar (struct obstack *out, int *pcode, char term)
+char
+literalchar (void)
 {
   int c;
-  int code;
-  int wasquote = 0;
+  int res;
 
   c = xgetc (finput);
   if (c == '\n')
     {
       complain (_("unescaped newline in constant"));
       ungetc (c, finput);
-      code = '?';
-      wasquote = 1;
+      res = '?';
     }
   else if (c != '\\')
     {
-      code = c;
-      if (c == term)
-	wasquote = 1;
+      res = c;
     }
   else
     {
       c = xgetc (finput);
       if (c == 't')
-	code = '\t';
+	res = '\t';
       else if (c == 'n')
-	code = '\n';
+	res = '\n';
       else if (c == 'a')
-	code = '\007';
+	res = '\007';
       else if (c == 'r')
-	code = '\r';
+	res = '\r';
       else if (c == 'f')
-	code = '\f';
+	res = '\f';
       else if (c == 'b')
-	code = '\b';
+	res = '\b';
       else if (c == 'v')
-	code = '\013';
+	res = '\013';
       else if (c == '\\')
-	code = '\\';
+	res = '\\';
       else if (c == '\'')
-	code = '\'';
+	res = '\'';
       else if (c == '\"')
-	code = '\"';
+	res = '\"';
       else if (c <= '7' && c >= '0')
 	{
-	  code = 0;
+	  res = 0;
 	  while (c <= '7' && c >= '0')
 	    {
-	      code = (code * 8) + (c - '0');
-	      if (code >= 256 || code < 0)
+	      res = (res * 8) + (c - '0');
+	      if (res >= 256 || res < 0)
 		{
 		  complain (_("octal value outside range 0...255: `\\%o'"),
-			    code);
-		  code &= 0xFF;
+			    res);
+		  res &= 0xFF;
 		  break;
 		}
 	      c = xgetc (finput);
@@ -210,21 +205,21 @@ literalchar (struct obstack *out, int *pcode, char term)
       else if (c == 'x')
 	{
 	  c = xgetc (finput);
-	  code = 0;
+	  res = 0;
 	  while (1)
 	    {
 	      if (c >= '0' && c <= '9')
-		code *= 16, code += c - '0';
+		res *= 16, res += c - '0';
 	      else if (c >= 'a' && c <= 'f')
-		code *= 16, code += c - 'a' + 10;
+		res *= 16, res += c - 'a' + 10;
 	      else if (c >= 'A' && c <= 'F')
-		code *= 16, code += c - 'A' + 10;
+		res *= 16, res += c - 'A' + 10;
 	      else
 		break;
-	      if (code >= 256 || code < 0)
+	      if (res >= 256 || res < 0)
 		{
-		  complain (_("hexadecimal value above 255: `\\x%x'"), code);
-		  code &= 0xFF;
+		  complain (_("hexadecimal value above 255: `\\x%x'"), res);
+		  res &= 0xFF;
 		  break;
 		}
 	      c = xgetc (finput);
@@ -237,14 +232,11 @@ literalchar (struct obstack *out, int *pcode, char term)
 	  badchar[0] = c;
 	  complain (_("unknown escape sequence: `\\' followed by `%s'"),
 		    quote (badchar));
-	  code = '?';
+	  res = '?';
 	}
     }				/* has \ */
 
-  if (out)
-    obstack_1grow (out, code);
-  *pcode = code;
-  return !wasquote;
+  return res;
 }
 
 
@@ -356,19 +348,17 @@ lex (void)
       /* parse the literal token and compute character code in  code  */
 
       {
-	int code;
+	int code = literalchar ();
 
 	obstack_1grow (&token_obstack, '\'');
-	literalchar (&token_obstack, &code, '\'');
+	obstack_1grow (&token_obstack, code);
 
 	c = getc (finput);
 	if (c != '\'')
 	  {
-	    int discode;
 	    complain (_("use \"...\" for multi-character literal tokens"));
-	    while (1)
-	      if (!literalchar (0, &discode, '\''))
-		break;
+	    while (literalchar () != '\'')
+	      /* Skip. */;
 	  }
 	obstack_1grow (&token_obstack, '\'');
 	obstack_1grow (&token_obstack, '\0');
@@ -388,8 +378,12 @@ lex (void)
 
 	obstack_1grow (&token_obstack, '\"');
 	/* Read up to and including ".  */
-	while (literalchar (&token_obstack, &code, '\"'))
-	  /* nothing */;
+	do
+	  {
+	    code = literalchar ();
+	    obstack_1grow (&token_obstack, code);
+	  }
+	while (code != '\"');
 	obstack_1grow (&token_obstack, '\0');
 	token_buffer = obstack_finish (&token_obstack);
 
@@ -543,7 +537,7 @@ parse_percent_token (void)
 	  arg_offset = obstack_object_size (&token_obstack);
 	  /* Read up to and including `"'.  Do not append the closing
 	     `"' in the output: it's not part of the ARG.  */
-	  while (literalchar (NULL, &code, '"'))
+	  while ((code = literalchar ()) != '"')
 	    obstack_1grow (&token_obstack, code);
 	}
       /* else: should be an error. */
