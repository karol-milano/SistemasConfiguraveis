@@ -18,14 +18,6 @@
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.  */
 
-
-/*
-   lex is the entry point.  It is called from reader.c.
-   It returns one of the token-type codes defined in lex.h.
-   When an identifier is seen, the code IDENTIFIER is returned
-   and the name is looked up in the symbol table using symtab.c;
-   symval is set to a pointer to the entry found.  */
-
 #include "system.h"
 #include "getargs.h"
 #include "files.h"
@@ -39,18 +31,8 @@
 
 extern int translations;
 
-extern void init_lex PARAMS((void));
-extern char *grow_token_buffer PARAMS((char *));
-extern int skip_white_space PARAMS((void));
-extern void unlex PARAMS((int));
-extern int lex PARAMS((void));
-extern int parse_percent_token PARAMS((void));
-
-static int safegetc PARAMS((FILE *));
-static int literalchar PARAMS((char **, int *, char));
-
 /* functions from main.c */
-extern char *printable_version PARAMS((int));
+extern char *printable_version PARAMS ((int));
 
 /* Buffer for storing the current token.  */
 char *token_buffer;
@@ -79,7 +61,7 @@ grow_token_buffer (char *p)
 {
   int offset = p - token_buffer;
   maxtoken *= 2;
-  token_buffer = (char *) xrealloc(token_buffer, maxtoken + 1);
+  token_buffer = (char *) xrealloc (token_buffer, maxtoken + 1);
   return token_buffer + offset;
 }
 
@@ -87,10 +69,10 @@ grow_token_buffer (char *p)
 int
 skip_white_space (void)
 {
-  register int c;
-  register int inside;
+  int c;
+  int inside;
 
-  c = getc(finput);
+  c = getc (finput);
 
   for (;;)
     {
@@ -99,7 +81,7 @@ skip_white_space (void)
       switch (c)
 	{
 	case '/':
-	  c = getc(finput);
+	  c = getc (finput);
 	  if (c != '*' && c != '/')
 	    {
 	      complain (_("unexpected `/' found and ignored"));
@@ -107,7 +89,7 @@ skip_white_space (void)
 	    }
 	  cplus_comment = (c == '/');
 
-	  c = getc(finput);
+	  c = getc (finput);
 
 	  inside = 1;
 	  while (inside)
@@ -115,12 +97,12 @@ skip_white_space (void)
 	      if (!cplus_comment && c == '*')
 		{
 		  while (c == '*')
-		    c = getc(finput);
+		    c = getc (finput);
 
 		  if (c == '/')
 		    {
 		      inside = 0;
-		      c = getc(finput);
+		      c = getc (finput);
 		    }
 		}
 	      else if (c == '\n')
@@ -128,12 +110,12 @@ skip_white_space (void)
 		  lineno++;
 		  if (cplus_comment)
 		    inside = 0;
-		  c = getc(finput);
+		  c = getc (finput);
 		}
 	      else if (c == EOF)
 		fatal (_("unterminated comment"));
 	      else
-		c = getc(finput);
+		c = getc (finput);
 	    }
 
 	  break;
@@ -144,7 +126,7 @@ skip_white_space (void)
 	case ' ':
 	case '\t':
 	case '\f':
-	  c = getc(finput);
+	  c = getc (finput);
 	  break;
 
 	default:
@@ -155,33 +137,35 @@ skip_white_space (void)
 
 /* do a getc, but give error message if EOF encountered */
 static int
-safegetc (FILE *f)
+xgetc (FILE *f)
 {
-  register int c = getc(f);
+  int c = getc (f);
   if (c == EOF)
     fatal (_("unexpected end of file"));
   return c;
 }
 
-/* read one literal character from finput.  process \ escapes.
-   append the normalized string version of the char to *pp.
-   assign the character code to *pcode
-   return 1 unless the character is an unescaped `term' or \n
-	report error for \n
-*/
+
+/*------------------------------------------------------------------.
+| Read one literal character from finput.  Process \ escapes.       |
+| Append the normalized string version of the char to *PP.  Assign  |
+| the character code to *PCODE. Return 1 unless the character is an |
+| unescaped `term' or \n report error for \n                        |
+`------------------------------------------------------------------*/
+
 static int
 literalchar (char **pp, int *pcode, char term)
 {
-  register int c;
-  register char *p;
-  register int code;
+  int c;
+  char *p;
+  int code;
   int wasquote = 0;
 
-  c = safegetc(finput);
+  c = xgetc (finput);
   if (c == '\n')
     {
       complain (_("unescaped newline in constant"));
-      ungetc(c, finput);
+      ungetc (c, finput);
       code = '?';
       wasquote = 1;
     }
@@ -193,17 +177,27 @@ literalchar (char **pp, int *pcode, char term)
     }
   else
     {
-      c = safegetc(finput);
-      if (c == 't')  code = '\t';
-      else if (c == 'n')  code = '\n';
-      else if (c == 'a')  code = '\007';
-      else if (c == 'r')  code = '\r';
-      else if (c == 'f')  code = '\f';
-      else if (c == 'b')  code = '\b';
-      else if (c == 'v')  code = '\013';
-      else if (c == '\\')  code = '\\';
-      else if (c == '\'')  code = '\'';
-      else if (c == '\"')  code = '\"';
+      c = xgetc (finput);
+      if (c == 't')
+	code = '\t';
+      else if (c == 'n')
+	code = '\n';
+      else if (c == 'a')
+	code = '\007';
+      else if (c == 'r')
+	code = '\r';
+      else if (c == 'f')
+	code = '\f';
+      else if (c == 'b')
+	code = '\b';
+      else if (c == 'v')
+	code = '\013';
+      else if (c == '\\')
+	code = '\\';
+      else if (c == '\'')
+	code = '\'';
+      else if (c == '\"')
+	code = '\"';
       else if (c <= '7' && c >= '0')
 	{
 	  code = 0;
@@ -217,42 +211,41 @@ literalchar (char **pp, int *pcode, char term)
 		  code &= 0xFF;
 		  break;
 		}
-	      c = safegetc(finput);
+	      c = xgetc (finput);
 	    }
-	  ungetc(c, finput);
+	  ungetc (c, finput);
 	}
       else if (c == 'x')
 	{
-	  c = safegetc(finput);
+	  c = xgetc (finput);
 	  code = 0;
 	  while (1)
 	    {
 	      if (c >= '0' && c <= '9')
-		code *= 16,  code += c - '0';
+		code *= 16, code += c - '0';
 	      else if (c >= 'a' && c <= 'f')
-		code *= 16,  code += c - 'a' + 10;
+		code *= 16, code += c - 'a' + 10;
 	      else if (c >= 'A' && c <= 'F')
-		code *= 16,  code += c - 'A' + 10;
+		code *= 16, code += c - 'A' + 10;
 	      else
 		break;
-	      if (code >= 256 || code<0)
+	      if (code >= 256 || code < 0)
 		{
-		  complain (_("hexadecimal value above 255: `\\x%x'"),
-			    code);
+		  complain (_("hexadecimal value above 255: `\\x%x'"), code);
 		  code &= 0xFF;
 		  break;
 		}
-	      c = safegetc(finput);
+	      c = xgetc (finput);
 	    }
-	  ungetc(c, finput);
+	  ungetc (c, finput);
 	}
       else
 	{
 	  complain (_("unknown escape sequence: `\\' followed by `%s'"),
-		    printable_version(c));
+		    printable_version (c));
 	  code = '?';
 	}
-    } /* has \ */
+    }				/* has \ */
 
   /* now fill token_buffer with the canonical name for this character
      as a literal token.  Do not use what the user typed,
@@ -261,17 +254,53 @@ literalchar (char **pp, int *pcode, char term)
   p = *pp;
   if (code == term && wasquote)
     *p++ = code;
-  else if (code == '\\')  {*p++ = '\\'; *p++ = '\\';}
-  else if (code == '\'')  {*p++ = '\\'; *p++ = '\'';}
-  else if (code == '\"')  {*p++ = '\\'; *p++ = '\"';}
+  else if (code == '\\')
+    {
+      *p++ = '\\';
+      *p++ = '\\';
+    }
+  else if (code == '\'')
+    {
+      *p++ = '\\';
+      *p++ = '\'';
+    }
+  else if (code == '\"')
+    {
+      *p++ = '\\';
+      *p++ = '\"';
+    }
   else if (code >= 040 && code < 0177)
     *p++ = code;
-  else if (code == '\t')  {*p++ = '\\'; *p++ = 't';}
-  else if (code == '\n')  {*p++ = '\\'; *p++ = 'n';}
-  else if (code == '\r')  {*p++ = '\\'; *p++ = 'r';}
-  else if (code == '\v')  {*p++ = '\\'; *p++ = 'v';}
-  else if (code == '\b')  {*p++ = '\\'; *p++ = 'b';}
-  else if (code == '\f')  {*p++ = '\\'; *p++ = 'f';}
+  else if (code == '\t')
+    {
+      *p++ = '\\';
+      *p++ = 't';
+    }
+  else if (code == '\n')
+    {
+      *p++ = '\\';
+      *p++ = 'n';
+    }
+  else if (code == '\r')
+    {
+      *p++ = '\\';
+      *p++ = 'r';
+    }
+  else if (code == '\v')
+    {
+      *p++ = '\\';
+      *p++ = 'v';
+    }
+  else if (code == '\b')
+    {
+      *p++ = '\\';
+      *p++ = 'b';
+    }
+  else if (code == '\f')
+    {
+      *p++ = '\\';
+      *p++ = 'f';
+    }
   else
     {
       *p++ = '\\';
@@ -281,7 +310,7 @@ literalchar (char **pp, int *pcode, char term)
     }
   *pp = p;
   *pcode = code;
-  return  ! wasquote;
+  return !wasquote;
 }
 
 
@@ -296,7 +325,7 @@ unlex (int token)
 int
 lex (void)
 {
-  register int c;
+  int c;
   char *p;
 
   if (unlexed >= 0)
@@ -307,66 +336,66 @@ lex (void)
       return c;
     }
 
-  c = skip_white_space();
-  *token_buffer = c;	/* for error messages (token buffer always valid) */
+  c = skip_white_space ();
+  *token_buffer = c;		/* for error messages (token buffer always valid) */
   token_buffer[1] = 0;
 
   switch (c)
     {
     case EOF:
-      strcpy(token_buffer, "EOF");
+      strcpy (token_buffer, "EOF");
       return ENDFILE;
 
-    case 'A':  case 'B':  case 'C':  case 'D':  case 'E':
-    case 'F':  case 'G':  case 'H':  case 'I':  case 'J':
-    case 'K':  case 'L':  case 'M':  case 'N':  case 'O':
-    case 'P':  case 'Q':  case 'R':  case 'S':  case 'T':
-    case 'U':  case 'V':  case 'W':  case 'X':  case 'Y':
+    case 'A':    case 'B':    case 'C':    case 'D':    case 'E':
+    case 'F':    case 'G':    case 'H':    case 'I':    case 'J':
+    case 'K':    case 'L':    case 'M':    case 'N':    case 'O':
+    case 'P':    case 'Q':    case 'R':    case 'S':    case 'T':
+    case 'U':    case 'V':    case 'W':    case 'X':    case 'Y':
     case 'Z':
-    case 'a':  case 'b':  case 'c':  case 'd':  case 'e':
-    case 'f':  case 'g':  case 'h':  case 'i':  case 'j':
-    case 'k':  case 'l':  case 'm':  case 'n':  case 'o':
-    case 'p':  case 'q':  case 'r':  case 's':  case 't':
-    case 'u':  case 'v':  case 'w':  case 'x':  case 'y':
+    case 'a':    case 'b':    case 'c':    case 'd':    case 'e':
+    case 'f':    case 'g':    case 'h':    case 'i':    case 'j':
+    case 'k':    case 'l':    case 'm':    case 'n':    case 'o':
+    case 'p':    case 'q':    case 'r':    case 's':    case 't':
+    case 'u':    case 'v':    case 'w':    case 'x':    case 'y':
     case 'z':
-    case '.':  case '_':
+    case '.':    case '_':
+
       p = token_buffer;
-      while (isalnum(c) || c == '_' || c == '.')
+      while (isalnum (c) || c == '_' || c == '.')
 	{
 	  if (p == token_buffer + maxtoken)
-	    p = grow_token_buffer(p);
+	    p = grow_token_buffer (p);
 
 	  *p++ = c;
-	  c = getc(finput);
+	  c = getc (finput);
 	}
 
       *p = 0;
-      ungetc(c, finput);
-      symval = getsym(token_buffer);
+      ungetc (c, finput);
+      symval = getsym (token_buffer);
       return IDENTIFIER;
 
-    case '0':  case '1':  case '2':  case '3':  case '4':
-    case '5':  case '6':  case '7':  case '8':  case '9':
+    case '0':    case '1':    case '2':    case '3':    case '4':
+    case '5':    case '6':    case '7':    case '8':    case '9':
       {
 	numval = 0;
 
 	p = token_buffer;
-	while (isdigit(c))
+	while (isdigit (c))
 	  {
 	    if (p == token_buffer + maxtoken)
-	      p = grow_token_buffer(p);
+	      p = grow_token_buffer (p);
 
 	    *p++ = c;
-	    numval = numval*10 + c - '0';
-	    c = getc(finput);
+	    numval = numval * 10 + c - '0';
+	    c = getc (finput);
 	  }
 	*p = 0;
-	ungetc(c, finput);
+	ungetc (c, finput);
 	return NUMBER;
       }
 
     case '\'':
-
       /* parse the literal token and compute character code in  code  */
 
       translations = -1;
@@ -376,45 +405,44 @@ lex (void)
 
 	p = token_buffer;
 	*p++ = '\'';
-	literalchar(&p, &code, '\'');
+	literalchar (&p, &code, '\'');
 
-	c = getc(finput);
+	c = getc (finput);
 	if (c != '\'')
 	  {
 	    complain (_("use \"...\" for multi-character literal tokens"));
 	    while (1)
 	      {
 		dp = discard;
-		if (! literalchar(&dp, &discode, '\''))
+		if (!literalchar (&dp, &discode, '\''))
 		  break;
 	      }
 	  }
 	*p++ = '\'';
 	*p = 0;
-	symval = getsym(token_buffer);
+	symval = getsym (token_buffer);
 	symval->class = STOKEN;
-	if (! symval->user_token_number)
+	if (!symval->user_token_number)
 	  symval->user_token_number = code;
 	return IDENTIFIER;
       }
 
     case '\"':
-
       /* parse the literal string token and treat as an identifier */
 
       translations = -1;
       {
-	int code;	/* ignored here */
+	int code;		/* ignored here */
 	p = token_buffer;
 	*p++ = '\"';
-	while (literalchar(&p, &code, '\"'))  /* read up to and including " */
+	while (literalchar (&p, &code, '\"'))	/* read up to and including " */
 	  {
 	    if (p >= token_buffer + maxtoken - 4)
-	      p = grow_token_buffer(p);
+	      p = grow_token_buffer (p);
 	  }
 	*p = 0;
 
-	symval = getsym(token_buffer);
+	symval = getsym (token_buffer);
 	symval->class = STOKEN;
 
 	return IDENTIFIER;
@@ -438,25 +466,26 @@ lex (void)
     case '=':
       do
 	{
-	  c = getc(finput);
-	  if (c == '\n') lineno++;
+	  c = getc (finput);
+	  if (c == '\n')
+	    lineno++;
 	}
-      while(c==' ' || c=='\n' || c=='\t');
+      while (c == ' ' || c == '\n' || c == '\t');
 
       if (c == '{')
 	{
-	  strcpy(token_buffer, "={");
+	  strcpy (token_buffer, "={");
 	  return LEFT_CURLY;
 	}
       else
 	{
-	  ungetc(c, finput);
+	  ungetc (c, finput);
 	  return ILLEGAL;
 	}
 
     case '<':
       p = token_buffer;
-      c = getc(finput);
+      c = getc (finput);
       while (c != '>')
 	{
 	  if (c == EOF)
@@ -464,81 +493,78 @@ lex (void)
 	  if (c == '\n')
 	    {
 	      complain (_("unterminated type name"));
-	      ungetc(c, finput);
+	      ungetc (c, finput);
 	      break;
 	    }
 
 	  if (p == token_buffer + maxtoken)
-	    p = grow_token_buffer(p);
+	    p = grow_token_buffer (p);
 
 	  *p++ = c;
-	  c = getc(finput);
+	  c = getc (finput);
 	}
       *p = 0;
       return TYPENAME;
 
 
     case '%':
-      return parse_percent_token();
+      return parse_percent_token ();
 
     default:
       return ILLEGAL;
     }
 }
 
-/* the following table dictates the action taken for the various
-	% directives.  A setflag value causes the named flag to be
-	set.  A retval action returns the code.
-*/
-struct percent_table_struct {
-	const char *name;
-	void *setflag;
-	int retval;
-} percent_table[] =
+/* the following table dictates the action taken for the various %
+   directives.  A setflag value causes the named flag to be set.  A
+   retval action returns the code.  */
+struct percent_table_struct
 {
-  {"token", NULL, TOKEN},
-  {"term", NULL, TOKEN},
-  {"nterm", NULL, NTERM},
-  {"type", NULL, TYPE},
-  {"guard", NULL, GUARD},
-  {"union", NULL, UNION},
-  {"expect", NULL, EXPECT},
-  {"thong", NULL, THONG},
-  {"start", NULL, START},
-  {"left", NULL, LEFT},
-  {"right", NULL, RIGHT},
-  {"nonassoc", NULL, NONASSOC},
-  {"binary", NULL, NONASSOC},
-  {"semantic_parser", NULL, SEMANTIC_PARSER},
-  {"pure_parser", NULL, PURE_PARSER},
-  {"prec", NULL, PREC},
-
-  {"no_lines", &nolinesflag, NOOP}, /* -l */
-  {"raw", &rawtoknumflag, NOOP}, /* -r */
-  {"token_table", &toknumflag, NOOP}, /* -k */
-
+  const char *name;
+  void *setflag;
+  int retval;
+}
+percent_table[] =
+{
+  { "token", NULL, TOKEN },
+  { "term", NULL, TOKEN },
+  { "nterm", NULL, NTERM },
+  { "type", NULL, TYPE },
+  { "guard", NULL, GUARD },
+  { "union", NULL, UNION },
+  { "expect", NULL, EXPECT },
+  { "thong", NULL, THONG },
+  { "start", NULL, START },
+  { "left", NULL, LEFT },
+  { "right", NULL, RIGHT },
+  { "nonassoc", NULL, NONASSOC },
+  { "binary", NULL, NONASSOC },
+  { "semantic_parser", NULL, SEMANTIC_PARSER },
+  { "pure_parser", NULL, PURE_PARSER },
+  { "prec", NULL, PREC },
+  { "no_lines", &nolinesflag, NOOP},	/* -l */
+  { "raw", &rawtoknumflag, NOOP },	/* -r */
+  { "token_table", &toknumflag, NOOP},	/* -k */
 #if 0
-  /* These can be utilized after main is reoganized so
-     open_files() is deferred 'til after read_declarations().
-     But %{ and %union both put information into files
-     that have to be opened before read_declarations().
+    /* These can be utilized after main is reoganized so
+       open_files() is deferred 'til after read_declarations().
+       But %{ and %union both put information into files
+       that have to be opened before read_declarations().
      */
-  {"yacc", &fixed_outfiles, NOOP}, /* -y */
-  {"fixed_output_files", &fixed_outfiles, NOOP}, /* -y */
-  {"defines", &definesflag, NOOP}, /* -d */
-  {"no_parser", &noparserflag, NOOP}, /* -n */
-  {"output_file", &spec_outfile, SETOPT}, /* -o */
-  {"file_prefix", &spec_file_prefix, SETOPT}, /* -b */
-  {"name_prefix", &spec_name_prefix, SETOPT}, /* -p */
-
-  /* These would be acceptable, but they do not affect processing */
-  {"verbose", &verboseflag, NOOP}, /* -v */
-  {"debug", &debugflag, NOOP},	/* -t */
-  /*	{"help", <print usage stmt>, NOOP},*/	/* -h */
-  /*	{"version", <print version number> ,  NOOP},*/	/* -V */
+  { "yacc", &fixed_outfiles, NOOP},			/* -y */
+  { "fixed_output_files", &fixed_outfiles, NOOP},	/* -y */
+  { "defines", &definesflag, NOOP},			/* -d */
+  { "no_parser", &noparserflag, NOOP},			/* -n */
+  { "output_file", &spec_outfile, SETOPT},		/* -o */
+  { "file_prefix", &spec_file_prefix, SETOPT},		/* -b */
+  { "name_prefix", &spec_name_prefix, SETOPT},		/* -p */
+    /* These would be acceptable, but they do not affect processing */
+  { "verbose", &verboseflag, NOOP},			/* -v */
+  { "debug", &debugflag, NOOP},				/* -t */
+/*    {"help", <print usage stmt>, NOOP}, *//* -h */
+/*    {"version", <print version number> ,  NOOP}, *//* -V */
 #endif
-
-  {NULL, NULL, ILLEGAL}
+  { NULL, NULL, ILLEGAL}
 };
 
 /* Parse a token which starts with %.
@@ -547,14 +573,14 @@ struct percent_table_struct {
 int
 parse_percent_token (void)
 {
-  register int c;
-  register char *p;
-  register struct percent_table_struct *tx;
+  int c;
+  char *p;
+  struct percent_table_struct *tx;
 
   p = token_buffer;
-  c = getc(finput);
+  c = getc (finput);
   *p++ = '%';
-  *p++ = c;	/* for error msg */
+  *p++ = c;			/* for error msg */
   *p = 0;
 
   switch (c)
@@ -580,37 +606,38 @@ parse_percent_token (void)
     case '=':
       return PREC;
     }
-  if (!isalpha(c))
+  if (!isalpha (c))
     return ILLEGAL;
 
   p = token_buffer;
   *p++ = '%';
-  while (isalpha(c) || c == '_' || c == '-')
+  while (isalpha (c) || c == '_' || c == '-')
     {
       if (p == token_buffer + maxtoken)
-	p = grow_token_buffer(p);
+	p = grow_token_buffer (p);
 
-      if (c == '-') c = '_';
+      if (c == '-')
+	c = '_';
       *p++ = c;
-      c = getc(finput);
+      c = getc (finput);
     }
 
-  ungetc(c, finput);
+  ungetc (c, finput);
 
   *p = 0;
 
   /* table lookup % directive */
   for (tx = percent_table; tx->name; tx++)
-    if (strcmp(token_buffer+1, tx->name) == 0)
+    if (strcmp (token_buffer + 1, tx->name) == 0)
       break;
   if (tx->retval == SETOPT)
     {
-      *((char **)(tx->setflag)) = optarg;
+      *((char **) (tx->setflag)) = optarg;
       return NOOP;
     }
   if (tx->setflag)
     {
-      *((int *)(tx->setflag)) = 1;
+      *((int *) (tx->setflag)) = 1;
       return NOOP;
     }
   return tx->retval;
