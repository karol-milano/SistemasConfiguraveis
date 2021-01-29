@@ -30,10 +30,8 @@
 #include "quote.h"
 
 /* Buffer for storing the current token.  */
-char *token_buffer;
-
-/* Allocated size of token_buffer, not including space for terminator.  */
-static int maxtoken;
+struct obstack token_obstack;
+char *token_buffer = NULL;
 
 bucket *symval;
 int numval;
@@ -45,22 +43,11 @@ static bucket *unlexed_symval;	/* by the next call to lex */
 void
 init_lex (void)
 {
-  maxtoken = 100;
-  token_buffer = XCALLOC (char, maxtoken + 1);
+  obstack_init (&token_obstack);
   unlexed = -1;
 }
 
 
-static char *
-grow_token_buffer (char *p)
-{
-  int offset = p - token_buffer;
-  maxtoken *= 2;
-  token_buffer = XREALLOC (token_buffer, char, maxtoken + 1);
-  return token_buffer + offset;
-}
-
-
 int
 skip_white_space (void)
 {
@@ -148,16 +135,22 @@ xgetc (FILE *f)
 
 /*------------------------------------------------------------------.
 | Read one literal character from finput.  Process \ escapes.       |
-| Append the normalized string version of the char to *PP.  Assign  |
+| Append the normalized string version of the char to OUT.  Assign  |
 | the character code to *PCODE. Return 1 unless the character is an |
-| unescaped `term' or \n report error for \n                        |
+| unescaped `term' or \n report error for \n.                       |
 `------------------------------------------------------------------*/
 
+/* FIXME: We could directly work in the obstack, but that would make
+   it more difficult to move to quotearg some day.  So for the time
+   being, I prefer have literalchar behave like quotearg, and change
+   my mind later if I was wrong.  */
+
 static int
-literalchar (char **pp, int *pcode, char term)
+literalchar (struct obstack *out, int *pcode, char term)
 {
   int c;
-  char *p;
+  char buf[4096];
+  char *cp;
   int code;
   int wasquote = 0;
 
@@ -249,68 +242,71 @@ literalchar (char **pp, int *pcode, char term)
 	}
     }				/* has \ */
 
-  /* now fill token_buffer with the canonical name for this character
-     as a literal token.  Do not use what the user typed,
-     so that `\012' and `\n' can be interchangeable.  */
+  /* now fill BUF with the canonical name for this character as a
+     literal token.  Do not use what the user typed, so that `\012'
+     and `\n' can be interchangeable.  */
 
-  p = *pp;
+  cp = buf;
   if (code == term && wasquote)
-    *p++ = code;
+    *cp++ = code;
   else if (code == '\\')
     {
-      *p++ = '\\';
-      *p++ = '\\';
+      *cp++ = '\\';
+      *cp++ = '\\';
     }
   else if (code == '\'')
     {
-      *p++ = '\\';
-      *p++ = '\'';
+      *cp++ = '\\';
+      *cp++ = '\'';
     }
   else if (code == '\"')
     {
-      *p++ = '\\';
-      *p++ = '\"';
+      *cp++ = '\\';
+      *cp++ = '\"';
     }
   else if (code >= 040 && code < 0177)
-    *p++ = code;
+    *cp++ = code;
   else if (code == '\t')
     {
-      *p++ = '\\';
-      *p++ = 't';
+      *cp++ = '\\';
+      *cp++ = 't';
     }
   else if (code == '\n')
     {
-      *p++ = '\\';
-      *p++ = 'n';
+      *cp++ = '\\';
+      *cp++ = 'n';
     }
   else if (code == '\r')
     {
-      *p++ = '\\';
-      *p++ = 'r';
+      *cp++ = '\\';
+      *cp++ = 'r';
     }
   else if (code == '\v')
     {
-      *p++ = '\\';
-      *p++ = 'v';
+      *cp++ = '\\';
+      *cp++ = 'v';
     }
   else if (code == '\b')
     {
-      *p++ = '\\';
-      *p++ = 'b';
+      *cp++ = '\\';
+      *cp++ = 'b';
     }
   else if (code == '\f')
     {
-      *p++ = '\\';
-      *p++ = 'f';
+      *cp++ = '\\';
+      *cp++ = 'f';
     }
   else
     {
-      *p++ = '\\';
-      *p++ = code / 0100 + '0';
-      *p++ = ((code / 010) & 07) + '0';
-      *p++ = (code & 07) + '0';
+      *cp++ = '\\';
+      *cp++ = code / 0100 + '0';
+      *cp++ = ((code / 010) & 07) + '0';
+      *cp++ = (code & 07) + '0';
     }
-  *pp = p;
+  *cp = '\0';
+
+  if (out)
+    obstack_sgrow (out, buf);
   *pcode = code;
   return !wasquote;
 }
@@ -331,7 +327,6 @@ unlex (int token)
 void
 read_type_name (FILE *fin)
 {
-  char *p = token_buffer;
   int c = getc (fin);
 
   while (c != '>')
@@ -345,13 +340,11 @@ read_type_name (FILE *fin)
 	  break;
 	}
 
-      if (p == token_buffer + maxtoken)
-	p = grow_token_buffer (p);
-
-      *p++ = c;
+      obstack_1grow (&token_obstack, c);
       c = getc (fin);
     }
-  *p = 0;
+  obstack_1grow (&token_obstack, '\0');
+  token_buffer = obstack_finish (&token_obstack);
 }
 
 
@@ -359,7 +352,9 @@ token_t
 lex (void)
 {
   int c;
-  char *p;
+
+  /* Just to make sure. */
+  token_buffer = NULL;
 
   if (unlexed >= 0)
     {
@@ -370,14 +365,11 @@ lex (void)
     }
 
   c = skip_white_space ();
-  /* for error messages (token buffer always valid) */
-  *token_buffer = c;
-  token_buffer[1] = 0;
 
   switch (c)
     {
     case EOF:
-      strcpy (token_buffer, "EOF");
+      token_buffer = "EOF";
       return tok_eof;
 
     case 'A':    case 'B':    case 'C':    case 'D':    case 'E':
@@ -394,17 +386,13 @@ lex (void)
     case 'z':
     case '.':    case '_':
 
-      p = token_buffer;
       while (isalnum (c) || c == '_' || c == '.')
 	{
-	  if (p == token_buffer + maxtoken)
-	    p = grow_token_buffer (p);
-
-	  *p++ = c;
+	  obstack_1grow (&token_obstack, c);
 	  c = getc (finput);
 	}
-
-      *p = 0;
+      obstack_1grow (&token_obstack, '\0');
+      token_buffer = obstack_finish (&token_obstack);
       ungetc (c, finput);
       symval = getsym (token_buffer);
       return tok_identifier;
@@ -414,17 +402,14 @@ lex (void)
       {
 	numval = 0;
 
-	p = token_buffer;
 	while (isdigit (c))
 	  {
-	    if (p == token_buffer + maxtoken)
-	      p = grow_token_buffer (p);
-
-	    *p++ = c;
+	    obstack_1grow (&token_obstack, c);
 	    numval = numval * 10 + c - '0';
 	    c = getc (finput);
 	  }
-	*p = 0;
+	obstack_1grow (&token_obstack, '\0');
+	token_buffer = obstack_finish (&token_obstack);
 	ungetc (c, finput);
 	return tok_number;
       }
@@ -435,25 +420,21 @@ lex (void)
       translations = -1;
       {
 	int code, discode;
-	char discard[10], *dp;
 
-	p = token_buffer;
-	*p++ = '\'';
-	literalchar (&p, &code, '\'');
+	obstack_1grow (&token_obstack, '\'');
+	literalchar (&token_obstack, &code, '\'');
 
 	c = getc (finput);
 	if (c != '\'')
 	  {
 	    complain (_("use \"...\" for multi-character literal tokens"));
 	    while (1)
-	      {
-		dp = discard;
-		if (!literalchar (&dp, &discode, '\''))
-		  break;
-	      }
+	      if (!literalchar (0, &discode, '\''))
+		break;
 	  }
-	*p++ = '\'';
-	*p = 0;
+	obstack_1grow (&token_obstack, '\'');
+	obstack_1grow (&token_obstack, '\0');
+	token_buffer = obstack_finish (&token_obstack);
 	symval = getsym (token_buffer);
 	symval->class = token_sym;
 	if (!symval->user_token_number)
@@ -467,15 +448,13 @@ lex (void)
       translations = -1;
       {
 	int code;		/* ignored here */
-	p = token_buffer;
-	*p++ = '\"';
+
+	obstack_1grow (&token_obstack, '\"');
 	/* Read up to and including ".  */
-	while (literalchar (&p, &code, '\"'))
-	  {
-	    if (p >= token_buffer + maxtoken - 4)
-	      p = grow_token_buffer (p);
-	  }
-	*p = 0;
+	while (literalchar (&token_obstack, &code, '\"'))
+	  /* nothing */;
+	obstack_1grow (&token_obstack, '\0');
+	token_buffer = obstack_finish (&token_obstack);
 
 	symval = getsym (token_buffer);
 	symval->class = token_sym;
@@ -509,7 +488,7 @@ lex (void)
 
       if (c == '{')
 	{
-	  strcpy (token_buffer, "={");
+	  token_buffer = "={";
 	  return tok_left_curly;
 	}
       else
@@ -589,14 +568,9 @@ int
 parse_percent_token (void)
 {
   int c;
-  char *p;
   struct percent_table_struct *tx;
 
-  p = token_buffer;
   c = getc (finput);
-  *p++ = '%';
-  *p++ = c;			/* for error msg */
-  *p = 0;
 
   switch (c)
     {
@@ -621,25 +595,22 @@ parse_percent_token (void)
     case '=':
       return tok_prec;
     }
+
   if (!isalpha (c))
     return tok_illegal;
 
-  p = token_buffer;
-  *p++ = '%';
+  obstack_1grow (&token_obstack, '%');
   while (isalpha (c) || c == '_' || c == '-')
     {
-      if (p == token_buffer + maxtoken)
-	p = grow_token_buffer (p);
-
       if (c == '-')
 	c = '_';
-      *p++ = c;
+      obstack_1grow (&token_obstack, c);
       c = getc (finput);
     }
 
   ungetc (c, finput);
-
-  *p = 0;
+  obstack_1grow (&token_obstack, '\0');
+  token_buffer = obstack_finish (&token_obstack);
 
   /* table lookup % directive */
   for (tx = percent_table; tx->name; tx++)
