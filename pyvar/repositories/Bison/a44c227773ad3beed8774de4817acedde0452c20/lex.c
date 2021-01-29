@@ -1,5 +1,5 @@
 /* Token-reader for Bison's input parser,
-   Copyright (C) 1984, 1986, 1989 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 1992 Free Software Foundation, Inc.
 
 This file is part of Bison, the GNU Compiler Compiler.
 
@@ -19,7 +19,7 @@ the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 
 
 /* 
-   lex() is the entry point.  It is called from reader.c.
+   lex is the entry point.  It is called from reader.c.
    It returns one of the token-type codes defined in lex.h.
    When an identifier is seen, the code IDENTIFIER is returned
    and the name is looked up in the symbol table using symtab.c;
@@ -29,18 +29,34 @@ the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 #include <ctype.h>
 #include "system.h"
 #include "files.h"
+#include "getopt.h"		/* for optarg */
 #include "symtab.h"
 #include "lex.h"
 #include "new.h"
 
+/* flags set by % directives */
+extern int definesflag;    	/* for -d */
+extern int toknumflag;   	/* for -k */
+extern int noparserflag;	/* for -n */
+extern int fixed_outfiles;  	/* for -y */
+extern int nolinesflag;    	/* for -l */
+extern int rawtoknumflag;	/* for -r */
+extern int verboseflag;	/* for -v */
+extern int debugflag;  		/* for -t */
+extern char *spec_name_prefix; 	/* for -p */
+extern char *spec_file_prefix;	/* for -b */
+/*spec_outfile is declared in files.h, for -o */
 
 extern int lineno;
 extern int translations;
 
 int parse_percent_token();
 
-extern void fatals();
+/* functions from main.c */
+extern char *printable_version();
 extern void fatal();
+extern void warni();
+extern void warn();
 
 /* Buffer for storing the current token.  */
 char *token_buffer;
@@ -91,8 +107,11 @@ skip_white_space()
 	{
 	case '/':
 	  c = getc(finput);
-	  if (c != '*' && c != '/')
-	    fatals("unexpected `/%c' found",c);
+	  if (c != '*' && c != '/') 
+	    {
+	      warn("unexpected `/' found and ignored");
+	      break;
+	    }
 	  cplus_comment = (c == '/');
 
 	  c = getc(finput);
@@ -141,22 +160,152 @@ skip_white_space()
     }
 }
 
+/* do a getc, but give error message if EOF encountered */
+int
+safegetc(f)
+  FILE *f;
+{
+  register int c = getc(f);
+  if (c == EOF)
+    fatal("Unexpected end of file");
+  return c;
+}
+
+/* read one literal character from finput.  process \ escapes.
+   append the normalized string version of the char to *pp.
+   assign the character code to *pcode
+   return 1 unless the character is an unescaped `term' or \n
+	report error for \n
+*/
+int
+literalchar(pp, pcode, term)
+  char **pp;
+  int *pcode;
+  char term;
+{
+  register int c;
+  register char *p;
+  register int code;
+  int wasquote = 0;
+
+  c = safegetc(finput);
+  if (c == '\n') 
+    {
+      warn("unescaped newline in constant");
+      ungetc(c, finput);
+      code = '?';
+      wasquote = 1;
+    }
+  else if (c != '\\')
+    {
+      code = c;
+      if (c == term) 
+	wasquote = 1;
+    }
+  else
+    {
+      c = safegetc(finput);
+      if (c == 't')  code = '\t';
+      else if (c == 'n')  code = '\n';
+      else if (c == 'a')  code = '\007';
+      else if (c == 'r')  code = '\r';
+      else if (c == 'f')  code = '\f';
+      else if (c == 'b')  code = '\b';
+      else if (c == 'v')  code = 013;
+      else if (c == '\\')  code = '\\';
+      else if (c == '\'')  code = '\'';
+      else if (c == '\"')  code = '\"';
+      else if (c <= '7' && c >= '0')
+	{
+	  code = 0;
+	  while (c <= '7' && c >= '0')
+	    {
+	      code = (code * 8) + (c - '0');
+	      if (code >= 256 || code < 0)
+		{
+		  warni("octal value outside range 0...255: `\\%o'", code);
+		  code &= 0xFF;
+		  break;
+		}
+	      c = safegetc(finput);
+	    }
+	  ungetc(c, finput);
+	}
+      else if (c == 'x')
+	{
+	  c = safegetc(finput);
+	  code = 0;
+	  while (1)
+	    {
+	      if (c >= '0' && c <= '9')
+		code *= 16,  code += c - '0';
+	      else if (c >= 'a' && c <= 'f')
+		code *= 16,  code += c - 'a' + 10;
+	      else if (c >= 'A' && c <= 'F')
+		code *= 16,  code += c - 'A' + 10;
+	      else 
+		break;
+	      if (code >= 256 || code<0)
+		{
+		  warni("hexadecimal value above 255: `\\x%x'", code);
+		  code &= 0xFF;
+		  break;
+		}
+	      c = safegetc(finput);
+	    }
+	  ungetc(c, finput);
+	}
+      else
+	{
+	  warni ("unknown escape sequence: `\\' followed by `%s'", 
+		 printable_version(c));
+	  code = '?';
+	}
+    } /* has \ */
+
+  /* now fill token_buffer with the canonical name for this character
+     as a literal token.  Do not use what the user typed,
+     so that `\012' and `\n' can be interchangeable.  */
+
+  p = *pp;
+  if (code >= 040 && code < 0177)
+    *p++ = code;
+  else if (code == '\\')  {*p++ = '\\'; *p++ = '\\';}
+  else if (code == '\'')  {*p++ = '\\'; *p++ = '\'';}
+  else if (code == '\"')  {*p++ = '\\'; *p++ = '\"';}
+  else if (code == '\t')  {*p++ = '\\'; *p++ = 't';}
+  else if (code == '\n')  {*p++ = '\\'; *p++ = 'n';}
+  else if (code == '\r')  {*p++ = '\\'; *p++ = 'r';}
+  else if (code == '\v')  {*p++ = '\\'; *p++ = 'v';}
+  else if (code == '\b')  {*p++ = '\\'; *p++ = 'b';}
+  else if (code == '\f')  {*p++ = '\\'; *p++ = 'f';}
+  else
+    {
+      *p++ = '\\';
+      *p++ = code / 0100 + '0';
+      *p++ = ((code / 010) & 07) + '0';
+      *p++ = (code & 07) + '0';
+    }
+  *pp = p;
+  *pcode = code;
+  return  ! wasquote;
+}
+
 
 void
 unlex(token)
-int token;
+     int token;
 {
   unlexed = token;
   unlexed_symval = symval;
 }
 
 
-
 int
 lex()
 {
   register int c;
-  register char *p;
+  char *p;
 
   if (unlexed >= 0)
     {
@@ -167,10 +316,13 @@ lex()
     }
 
   c = skip_white_space();
+  *token_buffer = c;	/* for error messages (token buffer always valid) */
+  token_buffer[1] = 0;
 
   switch (c)
     {
     case EOF:
+      strcpy(token_buffer, "EOF");
       return (ENDFILE);
 
     case 'A':  case 'B':  case 'C':  case 'D':  case 'E':
@@ -206,159 +358,68 @@ lex()
       {
 	numval = 0;
 
+	p = token_buffer;
 	while (isdigit(c))
 	  {
+	    if (p == token_buffer + maxtoken)
+	      p = grow_token_buffer(p);
+
+	    *p++ = c;
 	    numval = numval*10 + c - '0';
 	    c = getc(finput);
 	  }
+	*p = 0;
 	ungetc(c, finput);
 	return (NUMBER);
       }
 
     case '\'':
-      translations = -1;
 
       /* parse the literal token and compute character code in  code  */
 
-      c = getc(finput);
+      translations = -1;
       {
-	register int code = 0;
-
-	if (c == '\\')
-	  {
-	    c = getc(finput);
-
-	    if (c <= '7' && c >= '0')
-	      {
-		while (c <= '7' && c >= '0')
-		  {
-		    code = (code * 8) + (c - '0');
-		    c = getc(finput);
-		    if (code >= 256 || code < 0)
-		      fatals("malformatted literal token `\\%03o'", code);
-		  }
-	      }
-	    else
-	      {
-		if (c == 't')
-		  code = '\t';
-		else if (c == 'n')
-		  code = '\n';
-		else if (c == 'a')
-		  code = '\007';
-		else if (c == 'r')
-		  code = '\r';
-		else if (c == 'f')
-		  code = '\f';
-		else if (c == 'b')
-		  code = '\b';
-		else if (c == 'v')
-		  code = 013;
-		else if (c == 'x')
-		  {
-		    c = getc(finput);
-		    while ((c <= '9' && c >= '0')
-			   || (c >= 'a' && c <= 'z')
-			   || (c >= 'A' && c <= 'Z'))
-		      {
-			code *= 16;
-			if (c <= '9' && c >= '0')
-			  code += c - '0';
-			else if (c >= 'a' && c <= 'z')
-			  code += c - 'a' + 10;
-			else if (c >= 'A' && c <= 'Z')
-			  code += c - 'A' + 10;
-			if (code >= 256 || code<0)/* JF this said if(c>=128) */
-			  fatals("malformatted literal token `\\x%x'",code);
-			c = getc(finput);
-		      }
-		    ungetc(c, finput);
-		  }
-		else if (c == '\\')
-		  code = '\\';
-		else if (c == '\'')
-		  code = '\'';
-		else if (c == '\"')	/* JF this is a good idea */
-		  code = '\"';
-		else
-		  {
-		    if (c >= 040 && c <= 0177)
-		      fatals ("unknown escape sequence `\\%c'", c);
-		    else
-		      fatals ("unknown escape sequence: `\\' followed by char code 0x%x", c);
-		  }
+	int code, discode;
+	char discard[10], *dp;
+	p = token_buffer;
+	*p++ = '\'';
+	literalchar(&p, &code, '\'');
 
-		c = getc(finput);
-	      }
-	  }
-	else
+	c = getc(finput);
+	if (c != '\'')
 	  {
-	    code = c;
-	    c = getc(finput);
+	    warn("use \"...\" for multi-character literal tokens");
+	    dp = discard;
+	    while (literalchar(&dp, &discode, '\'')) {}
 	  }
-	if (c != '\'')
-	  fatal("multicharacter literal tokens not supported");
+	*p++ = '\'';
+	*p = 0;
+	symval = getsym(token_buffer);
+	symval->class = STOKEN;
+	if (! symval->user_token_number)
+	  symval->user_token_number = code;
+	return (IDENTIFIER);
+      }
 
-	/* now fill token_buffer with the canonical name for this character
-	   as a literal token.  Do not use what the user typed,
-	   so that '\012' and '\n' can be interchangeable.  */
+    case '\"':
 
+      /* parse the literal string token and treat as an identifier */
+
+      translations = -1;
+      {
+	int code;	/* ignored here */
 	p = token_buffer;
-	*p++ = '\'';
-	if (code == '\\')
-	  {
-	    *p++ = '\\';
-	    *p++ = '\\';
-	  }
-	else if (code == '\'')
-	  {
-	    *p++ = '\\';
-	    *p++ = '\'';
-	  }
-	else if (code >= 040 && code != 0177)
-	  *p++ = code;
-	else if (code == '\t')
-	  {
-	    *p++ = '\\';
-	    *p++ = 't';
-	  }
-	else if (code == '\n')
-	  {
-	    *p++ = '\\';
-	    *p++ = 'n';
-	  }
-	else if (code == '\r')
-	  {
-	    *p++ = '\\';
-	    *p++ = 'r';
-	  }
-	else if (code == '\v')
-	  {
-	    *p++ = '\\';
-	    *p++ = 'v';
-	  }
-	else if (code == '\b')
-	  {
-	    *p++ = '\\';
-	    *p++ = 'b';
-	  }
-	else if (code == '\f')
+	*p++ = '\"';
+	while (literalchar(&p, &code, '\"'))  /* read up to and including " */
 	  {
-	    *p++ = '\\';
-	    *p++ = 'f';
+	    if (p >= token_buffer + maxtoken - 4)
+	      p = grow_token_buffer(p);
 	  }
-        else
-	  {
-	    *p++ = code / 0100 + '0';
-	    *p++ = ((code / 010) & 07) + '0';
-	    *p++ = (code & 07) + '0';
-	  }
-	*p++ = '\'';
 	*p = 0;
+
 	symval = getsym(token_buffer);
 	symval->class = STOKEN;
-	if (! symval->user_token_number)
-	  symval->user_token_number = code;
+
 	return (IDENTIFIER);
       }
 
@@ -386,7 +447,10 @@ lex()
       while(c==' ' || c=='\n' || c=='\t');
 
       if (c == '{')
-      	return(LEFT_CURLY);
+	{
+	  strcpy(token_buffer, "={");
+	  return(LEFT_CURLY);
+	}
       else
 	{
 	  ungetc(c, finput);
@@ -398,8 +462,14 @@ lex()
       c = getc(finput);
       while (c != '>')
 	{
-	  if (c == '\n' || c == EOF)
-	    fatal("unterminated type name");
+	  if (c == EOF)
+	    fatal("unterminated type name at end of file");
+	  if (c == '\n') 
+	    {
+	      warn("unterminated type name");
+	      ungetc(c, finput);
+	      break;
+	    }
 
 	  if (p == token_buffer + maxtoken)
 	    p = grow_token_buffer(p);
@@ -419,17 +489,76 @@ lex()
     }
 }
 
-
-/* parse a token which starts with %.  Assumes the % has already been read and discarded.  */
+/* the following table dictates the action taken for the various 
+	% directives.  A setflag value causes the named flag to be
+	set.  A retval action returns the code.
+*/
+struct percent_table_struct {
+	char *name;
+	void *setflag; 
+	int retval;
+} percent_table[] =
+{
+  {"token", NULL, TOKEN},
+  {"term", NULL, TOKEN},
+  {"nterm", NULL, NTERM},
+  {"type", NULL, TYPE},
+  {"guard", NULL, GUARD},
+  {"union", NULL, UNION},
+  {"expect", NULL, EXPECT},
+  {"thong", NULL, THONG},
+  {"start", NULL, START},
+  {"left", NULL, LEFT},
+  {"right", NULL, RIGHT},
+  {"nonassoc", NULL, NONASSOC},
+  {"binary", NULL, NONASSOC},
+  {"semantic_parser", NULL, SEMANTIC_PARSER},
+  {"pure_parser", NULL, PURE_PARSER},
+  {"prec", NULL, PREC},
+
+  {"no_lines", &nolinesflag, NOOP}, /* -l */
+  {"raw", &rawtoknumflag, NOOP}, /* -r */
+  {"token_table", &toknumflag, NOOP}, /* -k */
+
+#if 0
+  /* These can be utilized after main is reoganized so
+     open_files() is deferred 'til after read_declarations().
+     But %{ and %union both put information into files
+     that have to be opened before read_declarations().
+     */
+  {"yacc", &fixed_outfiles, NOOP}, /* -y */
+  {"fixed_output_files", &fixed_outfiles, NOOP}, /* -y */
+  {"defines", &definesflag, NOOP}, /* -d */
+  {"no_parser", &noparserflag, NOOP}, /* -n */
+  {"output_file", &spec_outfile, SETOPT}, /* -o */
+  {"file_prefix", &spec_file_prefix, SETOPT}, /* -b */
+  {"name_prefix", &spec_name_prefix, SETOPT}, /* -p */
+
+  /* These would be acceptable, but they do not affect processing */
+  {"verbose", &verboseflag, NOOP}, /* -v */
+  {"debug", &debugflag, NOOP},	/* -t */
+  /*	{"help", <print usage stmt>, NOOP},	/* -h */
+  /*	{"version", <print version number> ,  NOOP},	/* -V */
+#endif
+
+  {NULL, NULL, ILLEGAL}
+};
+
+/* Parse a token which starts with %.
+   Assumes the % has already been read and discarded.  */
 
 int
 parse_percent_token ()
 {
   register int c;
   register char *p;
+  register struct percent_table_struct *tx;
 
   p = token_buffer;
   c = getc(finput);
+  *p++ = '%';
+  *p++ = c;	/* for error msg */
+  *p = 0;
 
   switch (c)
     {
@@ -454,14 +583,17 @@ parse_percent_token ()
     case '=':
       return (PREC);
     }
-  if (!isalpha(c))
+  if (!isalpha(c)) 
     return (ILLEGAL);
 
-  while (isalpha(c) || c == '_')
+  p = token_buffer;
+  *p++ = '%';
+  while (isalpha(c) || c == '_' || c == '-')
     {
       if (p == token_buffer + maxtoken)
 	p = grow_token_buffer(p);
 
+      if (c == '-') c = '_';
       *p++ = c;
       c = getc(finput);
     }
@@ -470,35 +602,19 @@ parse_percent_token ()
 
   *p = 0;
 
-  if (strcmp(token_buffer, "token") == 0
-      ||
-      strcmp(token_buffer, "term") == 0)
-    return (TOKEN);
-  else if (strcmp(token_buffer, "nterm") == 0)
-    return (NTERM);
-  else if (strcmp(token_buffer, "type") == 0)
-    return (TYPE);
-  else if (strcmp(token_buffer, "guard") == 0)
-    return (GUARD);
-  else if (strcmp(token_buffer, "union") == 0)
-    return (UNION);
-  else if (strcmp(token_buffer, "expect") == 0)
-    return (EXPECT);
-  else if (strcmp(token_buffer, "start") == 0)
-    return (START);
-  else if (strcmp(token_buffer, "left") == 0)
-    return (LEFT);
-  else if (strcmp(token_buffer, "right") == 0)
-    return (RIGHT);
-  else if (strcmp(token_buffer, "nonassoc") == 0
-	   ||
-	   strcmp(token_buffer, "binary") == 0)
-    return (NONASSOC);
-  else if (strcmp(token_buffer, "semantic_parser") == 0)
-    return (SEMANTIC_PARSER);
-  else if (strcmp(token_buffer, "pure_parser") == 0)
-    return (PURE_PARSER);
-  else if (strcmp(token_buffer, "prec") == 0)
-    return (PREC);
-  else return (ILLEGAL);
+  /* table lookup % directive */
+  for (tx = percent_table; tx->name; tx++)
+    if (strcmp(token_buffer+1, tx->name) == 0)
+      break;
+  if (tx->retval == SETOPT)
+    {
+      *((char **)(tx->setflag)) = optarg;
+      return NOOP;
+    }
+  if (tx->setflag)
+    {
+      *((int *)(tx->setflag)) = 1;
+      return NOOP;
+    }
+  return tx->retval;
 }
