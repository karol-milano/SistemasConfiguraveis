@@ -1,5 +1,6 @@
 /* Input parser for bison
-   Copyright (C) 1984, 86, 89, 92, 98, 2000 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 1992, 1998, 2000
+   Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -19,14 +20,6 @@
    Boston, MA 02111-1307, USA.  */
 
 
-/* Read in the grammar specification and record it in the format
-   described in gram.h.  All guards are copied into the fguard file
-   and all actions into faction, in each case forming the body of a C
-   function (yyguard or yyaction) which contains a switch statement to
-   decide which guard or action to execute.
-
-   The entry point is reader ().  */
-
 #include "system.h"
 #include "getargs.h"
 #include "files.h"
@@ -68,46 +61,22 @@ extern int expected_conflicts;
 extern char *token_buffer;
 extern int maxtoken;
 
-extern void tabinit PARAMS((void));
-extern void free_symtab PARAMS((void));
-extern void open_extra_files PARAMS((void));
-extern char *printable_version PARAMS((int));
+extern void tabinit PARAMS ((void));
+extern void free_symtab PARAMS ((void));
+extern void open_extra_files PARAMS ((void));
+extern char *printable_version PARAMS ((int));
 
-typedef
-  struct symbol_list
-    {
-      struct symbol_list *next;
-      bucket *sym;
-      bucket *ruleprec;
-    }
-  symbol_list;
-
-
-extern void reader PARAMS((void));
-extern void reader_output_yylsp PARAMS((FILE *));
-
-static void read_declarations PARAMS((void));
-static void copy_definition PARAMS((void));
-static void parse_token_decl PARAMS((int, int));
-static void parse_start_decl PARAMS((void));
-static void parse_type_decl PARAMS((void));
-static void parse_assoc_decl PARAMS((int));
-static void parse_union_decl PARAMS((void));
-static void parse_expect_decl PARAMS((void));
-static char *get_type_name PARAMS((int, symbol_list *));
-static void copy_guard PARAMS((symbol_list *, int));
-static void parse_thong_decl PARAMS((void));
-static void copy_action PARAMS((symbol_list *, int));
-static bucket *gensym PARAMS((void));
-static void readgram PARAMS((void));
-static void record_rule_line PARAMS((void));
-static void packsymbols PARAMS((void));
-static void output_token_defines PARAMS((FILE *));
-static void packgram PARAMS((void));
+typedef struct symbol_list
+{
+  struct symbol_list *next;
+  bucket *sym;
+  bucket *ruleprec;
+}
+symbol_list;
 
-#if 0
-static int get_type PARAMS((void));
-#endif
+
+extern void reader PARAMS ((void));
+extern void reader_output_yylsp PARAMS ((FILE *));
 
 int lineno;
 char **tags;
@@ -120,19 +89,19 @@ static bucket *startval;
    they must be unions.  */
 static int value_components_used;
 
-static int typed;  /* nonzero if %union has been seen.  */
+static int typed;		/* nonzero if %union has been seen.  */
 
-static int lastprec;  /* incremented for each %left, %right or %nonassoc seen */
+static int lastprec;		/* incremented for each %left, %right or %nonassoc seen */
 
-static int gensym_count;  /* incremented for each generated symbol */
+static int gensym_count;	/* incremented for each generated symbol */
 
 static bucket *errtoken;
 static bucket *undeftoken;
 
 /* Nonzero if any action or guard uses the @n construct.  */
 static int yylsp_needed;
-
 
+
 /*===================\
 | Low level lexing.  |
 \===================*/
@@ -161,9 +130,9 @@ skip_to_char (int target)
 static inline int
 read_signed_integer (FILE *stream)
 {
-  register int c = getc (stream);
-  register int sign = 1;
-  register int n = 0;
+  int c = getc (stream);
+  int sign = 1;
+  int n = 0;
 
   if (c == '-')
     {
@@ -207,7 +176,7 @@ copy_string (FILE *fin, FILE *fout, int match)
 	  continue;
 	}
 
-      putc(c, fout);
+      putc (c, fout);
 
       if (c == '\\')
 	{
@@ -219,10 +188,10 @@ copy_string (FILE *fin, FILE *fout, int match)
 	    lineno++;
 	}
 
-      c = getc(fin);
+      c = getc (fin);
     }
 
-  putc(c, fout);
+  putc (c, fout);
 }
 
 
@@ -233,10 +202,10 @@ copy_string (FILE *fin, FILE *fout, int match)
 `---------------------------------------------------------------*/
 
 static inline void
-copy_comment2 (FILE *in, FILE *out1, FILE* out2, int c)
+copy_comment2 (FILE *in, FILE *out1, FILE *out2, int c)
 {
   int cplus_comment;
-  register int ended;
+  int ended;
 
   cplus_comment = (c == '/');
   putc (c, out1);
@@ -259,9 +228,9 @@ copy_comment2 (FILE *in, FILE *out1, FILE* out2, int c)
 
 	  if (c == '/')
 	    {
-	      putc(c, out1);
+	      putc (c, out1);
 	      if (out2)
-		putc(c, out2);
+		putc (c, out2);
 	      ended = 1;
 	    }
 	}
@@ -301,206 +270,52 @@ copy_comment (FILE *fin, FILE *fout, int c)
 }
 
 
-void
-reader (void)
-{
-  start_flag = 0;
-  startval = NULL;  /* start symbol not specified yet. */
-
-#if 0
-  /* initially assume token number translation not needed.  */
-  translations = 0;
-#endif
-  /* Nowadays translations is always set to 1, since we give `error' a
-     user-token-number to satisfy the Posix demand for YYERRCODE==256.
-     */
-  translations = 1;
-
-  nsyms = 1;
-  nvars = 0;
-  nrules = 0;
-  nitems = 0;
-  rline_allocated = 10;
-  rline = NEW2 (rline_allocated, short);
-
-  typed = 0;
-  lastprec = 0;
-
-  gensym_count = 0;
-
-  semantic_parser = 0;
-  pure_parser = 0;
-  yylsp_needed = 0;
-
-  grammar = NULL;
-
-  init_lex ();
-  lineno = 1;
-
-  /* Initialize the symbol table.  */
-  tabinit ();
-  /* Construct the error token */
-  errtoken = getsym ("error");
-  errtoken->class = STOKEN;
-  errtoken->user_token_number = 256; /* Value specified by POSIX.  */
-  /* Construct a token that represents all undefined literal tokens.
-     It is always token number 2.  */
-  undeftoken = getsym ("$undefined.");
-  undeftoken->class = STOKEN;
-  undeftoken->user_token_number = 2;
-
-  /* Read the declaration section.  Copy %{ ... %} groups to FTABLE
-     and FDEFINES file.  Also notice any %token, %left, etc. found
-     there.  */
-  putc ('\n', ftable);
-  fprintf (ftable, "\
-/* %s, made from %s\n\
-   by GNU bison %s.  */\n\
-\n",
-	   noparserflag ? "Bison-generated parse tables" : "A Bison parser",
-	   infile,
-	   VERSION);
-
-  fputs ("#define YYBISON 1  /* Identify Bison output.  */\n\n", ftable);
-  read_declarations ();
-  /* Start writing the guard and action files, if they are needed.  */
-  output_headers ();
-  /* Read in the grammar, build grammar in list form.  Write out
-     guards and actions.  */
-  readgram ();
-  /* Now we know whether we need the line-number stack.  If we do,
-     write its type into the .tab.h file.  */
-  if (fdefines)
-    reader_output_yylsp (fdefines);
-  /* Write closing delimiters for actions and guards.  */
-  output_trailers ();
-  if (yylsp_needed)
-    fputs ("#define YYLSP_NEEDED\n\n", ftable);
-  /* Assign the symbols their symbol numbers.  Write #defines for the
-     token symbols into FDEFINES if requested.  */
-  packsymbols ();
-  /* Convert the grammar into the format described in gram.h.  */
-  packgram ();
-  /* Free the symbol table data structure since symbols are now all
-     referred to by symbol number.  */
-  free_symtab ();
-}
-
-void
-reader_output_yylsp (FILE *f)
-{
-  if (yylsp_needed)
-    fprintf(f, LTYPESTR);
-}
-
-/* Read from finput until `%%' is seen.  Discard the `%%'.  Handle any
-   `%' declarations, and copy the contents of any `%{ ... %}' groups
-   to fattrs.  */
+/*-----------------------------------------------------------------.
+| FIN is pointing to a location (i.e., a `@').  Output to FOUT a   |
+| reference to this location. STACK_OFFSET is the number of values |
+| in the current rule so far, which says where to find `$0' with   |
+| respect to the top of the stack.                                 |
+`-----------------------------------------------------------------*/
 
-static void
-read_declarations (void)
+static inline void
+copy_at (FILE *fin, FILE *fout, int stack_offset)
 {
-  register int c;
-  register int tok;
+  int c;
 
-  for (;;)
+  c = getc (fin);
+  if (c == '$')
     {
-      c = skip_white_space();
-
-      if (c == '%')
-	{
-	  tok = parse_percent_token();
-
-	  switch (tok)
-	    {
-	    case TWO_PERCENTS:
-	      return;
-
-	    case PERCENT_LEFT_CURLY:
-	      copy_definition();
-	      break;
-
-	    case TOKEN:
-	      parse_token_decl (STOKEN, SNTERM);
-	      break;
-
-	    case NTERM:
-	      parse_token_decl (SNTERM, STOKEN);
-	      break;
-
-	    case TYPE:
-	      parse_type_decl();
-	      break;
-
-	    case START:
-	      parse_start_decl();
-	      break;
-
-	    case UNION:
-	      parse_union_decl ();
-	      break;
-
-	    case EXPECT:
-	      parse_expect_decl();
-	      break;
-	    case THONG:
-	      parse_thong_decl();
-	      break;
-	    case LEFT:
-	      parse_assoc_decl(LEFT_ASSOC);
-	      break;
-
-	    case RIGHT:
-	      parse_assoc_decl(RIGHT_ASSOC);
-	      break;
-
-	    case NONASSOC:
-	      parse_assoc_decl(NON_ASSOC);
-	      break;
-
-	    case SEMANTIC_PARSER:
-	      if (semantic_parser == 0)
-		{
-		  semantic_parser = 1;
-		  open_extra_files();
-		}
-	      break;
-
-	    case PURE_PARSER:
-	      pure_parser = 1;
-	      break;
+      fprintf (fout, "yyloc");
+      yylsp_needed = 1;
+    }
+  else if (isdigit (c) || c == '-')
+    {
+      int n;
 
-	    case NOOP:
-	      break;
+      ungetc (c, fin);
+      n = read_signed_integer (fin);
 
-	    default:
-	      complain (_("unrecognized: %s"), token_buffer);
-	      skip_to_char('%');
-	  }
-	}
-      else if (c == EOF)
-        fatal (_("no input grammar"));
-      else
-	{
-	  complain (_("unknown character: %s"), printable_version(c));
-	  skip_to_char('%');
-	}
+      fprintf (fout, "yylsp[%d]", n - stack_offset);
+      yylsp_needed = 1;
     }
+  else
+    complain (_("@%s is invalid"), printable_version (c));
 }
-
-
-/* Copy the contents of a `%{ ... %}' into the definitions file.  The
-   `%{' has already been read.  Return after reading the `%}'.  */
+
+/*-------------------------------------------------------------------.
+| Copy the contents of a `%{ ... %}' into the definitions file.  The |
+| `%{' has already been read.  Return after reading the `%}'.        |
+`-------------------------------------------------------------------*/
 
 static void
 copy_definition (void)
 {
-  register int c;
+  int c;
   /* -1 while reading a character if prev char was %. */
-  register int after_percent;
+  int after_percent;
 
   if (!nolinesflag)
-    fprintf(fattrs, "#line %d \"%s\"\n", lineno, infile);
+    fprintf (fattrs, "#line %d \"%s\"\n", lineno, infile);
 
   after_percent = 0;
 
@@ -511,12 +326,12 @@ copy_definition (void)
       switch (c)
 	{
 	case '\n':
-	  putc(c, fattrs);
+	  putc (c, fattrs);
 	  lineno++;
 	  break;
 
 	case '%':
-          after_percent = -1;
+	  after_percent = -1;
 	  break;
 
 	case '\'':
@@ -533,20 +348,19 @@ copy_definition (void)
 	  break;
 
 	case EOF:
-	  fatal ("%s",
-		 _("unterminated `%{' definition"));
+	  fatal ("%s", _("unterminated `%{' definition"));
 
 	default:
-	  putc(c, fattrs);
+	  putc (c, fattrs);
 	}
 
-      c = getc(finput);
+      c = getc (finput);
 
       if (after_percent)
 	{
 	  if (c == '}')
 	    return;
-	  putc('%', fattrs);
+	  putc ('%', fattrs);
 	}
       after_percent = 0;
 
@@ -555,17 +369,18 @@ copy_definition (void)
 }
 
 
-
-/* parse what comes after %token or %nterm.
-For %token, what_is is STOKEN and what_is_not is SNTERM.
-For %nterm, the arguments are reversed.  */
+/*-----------------------------------------------------------------.
+| Parse what comes after %token or %nterm.  For %token, what_is is |
+| STOKEN and what_is_not is SNTERM.  For %nterm, the arguments are |
+| reversed.                                                        |
+`-----------------------------------------------------------------*/
 
 static void
 parse_token_decl (int what_is, int what_is_not)
 {
-  register int token = 0;
-  register char *typename = 0;
-  register struct bucket *symbol = NULL;  /* pts to symbol being defined */
+  int token = 0;
+  char *typename = 0;
+  struct bucket *symbol = NULL;	/* pts to symbol being defined */
   int k;
 
   for (;;)
@@ -577,7 +392,7 @@ parse_token_decl (int what_is, int what_is_not)
       if (tmp_char == EOF)
 	fatal (_("Premature EOF after %s"), token_buffer);
 
-      token = lex();
+      token = lex ();
       if (token == COMMA)
 	{
 	  symbol = NULL;
@@ -585,14 +400,13 @@ parse_token_decl (int what_is, int what_is_not)
 	}
       if (token == TYPENAME)
 	{
-	  k = strlen(token_buffer);
-	  typename = NEW2(k + 1, char);
-	  strcpy(typename, token_buffer);
+	  k = strlen (token_buffer);
+	  typename = NEW2 (k + 1, char);
+	  strcpy (typename, token_buffer);
 	  value_components_used = 1;
 	  symbol = NULL;
 	}
-      else if (token == IDENTIFIER && *symval->tag == '\"'
-		&& symbol)
+      else if (token == IDENTIFIER && *symval->tag == '\"' && symbol)
 	{
 	  translations = 1;
 	  symval->class = STOKEN;
@@ -604,7 +418,7 @@ parse_token_decl (int what_is, int what_is_not)
 	  symbol->alias = symval;
 	  symbol = NULL;
 
- 	  nsyms--;   /* symbol and symval combined are only one symbol */
+	  nsyms--;		/* symbol and symval combined are only one symbol */
 	}
       else if (token == IDENTIFIER)
 	{
@@ -621,102 +435,25 @@ parse_token_decl (int what_is, int what_is_not)
 	    {
 	      if (symbol->type_name == NULL)
 		symbol->type_name = typename;
-	      else if (strcmp(typename, symbol->type_name) != 0)
+	      else if (strcmp (typename, symbol->type_name) != 0)
 		complain (_("type redeclaration for %s"), symbol->tag);
 	    }
 	}
       else if (symbol && token == NUMBER)
-        {
+	{
 	  symbol->user_token_number = numval;
 	  translations = 1;
-        }
+	}
       else
 	{
 	  complain (_("`%s' is invalid in %s"),
-		    token_buffer,
-		(what_is == STOKEN) ? "%token" : "%nterm");
-	  skip_to_char('%');
+		    token_buffer, (what_is == STOKEN) ? "%token" : "%nterm");
+	  skip_to_char ('%');
 	}
     }
 
 }
 
-/* parse what comes after %thong
-	the full syntax is
-		%thong <type> token number literal
- the <type> or number may be omitted.  The number specifies the
- user_token_number.
-
- Two symbols are entered in the table, one for the token symbol and
- one for the literal.  Both are given the <type>, if any, from the declaration.
- The ->user_token_number of the first is SALIAS and the ->user_token_number
- of the second is set to the number, if any, from the declaration.
- The two symbols are linked via pointers in their ->alias fields.
-
- during output_defines_table, the symbol is reported
- thereafter, only the literal string is retained
- it is the literal string that is output to yytname
-*/
-
-static void
-parse_thong_decl (void)
-{
-  register int token;
-  register struct bucket *symbol;
-  register char *typename = 0;
-  int k, usrtoknum;
-
-  translations = 1;
-  token = lex();		/* fetch typename or first token */
-  if (token == TYPENAME) {
-    k = strlen(token_buffer);
-    typename = NEW2(k + 1, char);
-    strcpy(typename, token_buffer);
-    value_components_used = 1;
-    token = lex();		/* fetch first token */
-  }
-
-  /* process first token */
-
-  if (token != IDENTIFIER)
-    {
-      complain (_("unrecognized item %s, expected an identifier"),
-		token_buffer);
-      skip_to_char('%');
-      return;
-    }
-  symval->class = STOKEN;
-  symval->type_name = typename;
-  symval->user_token_number = SALIAS;
-  symbol = symval;
-
-  token = lex();		/* get number or literal string */
-
-  if (token == NUMBER) {
-    usrtoknum = numval;
-    token = lex();		/* okay, did number, now get literal */
-  }
-  else usrtoknum = 0;
-
-  /* process literal string token */
-
-  if (token != IDENTIFIER || *symval->tag != '\"')
-    {
-      complain (_("expected string constant instead of %s"),
-		token_buffer);
-      skip_to_char('%');
-      return;
-    }
-  symval->class = STOKEN;
-  symval->type_name = typename;
-  symval->user_token_number = usrtoknum;
-
-  symval->alias = symbol;
-  symbol->alias = symval;
-
-  nsyms--;			/* symbol and symval combined are only one symbol */
-}
-
 
 /* Parse what comes after %start */
 
@@ -736,38 +473,76 @@ parse_start_decl (void)
 
 
 
-/* read in a %type declaration and record its information for get_type_name to access */
+/*--------------------------------------------------------------.
+| Get the data type (alternative in the union) of the value for |
+| symbol n in rule rule.                                        |
+`--------------------------------------------------------------*/
 
-static void
-parse_type_decl (void)
+static char *
+get_type_name (int n, symbol_list * rule)
 {
-  register int k;
-  register char *name;
+  int i;
+  symbol_list *rp;
 
-  if (lex() != TYPENAME)
+  if (n < 0)
     {
-      complain ("%s", _("%type declaration has no <typename>"));
-      skip_to_char('%');
-      return;
+      complain (_("invalid $ value"));
+      return NULL;
     }
 
-  k = strlen(token_buffer);
-  name = NEW2(k + 1, char);
-  strcpy(name, token_buffer);
+  rp = rule;
+  i = 0;
 
-  for (;;)
+  while (i < n)
     {
-      register int t;
-      int tmp_char = ungetc (skip_white_space (), finput);
-
-      if (tmp_char == '%')
-	return;
-      if (tmp_char == EOF)
-	fatal (_("Premature EOF after %s"), token_buffer);
-
-      t = lex();
-
-      switch (t)
+      rp = rp->next;
+      if (rp == NULL || rp->sym == NULL)
+	{
+	  complain (_("invalid $ value"));
+	  return NULL;
+	}
+      i++;
+    }
+
+  return rp->sym->type_name;
+}
+
+
+/*-----------------------------------------------------------.
+| read in a %type declaration and record its information for |
+| get_type_name to access                                    |
+`-----------------------------------------------------------*/
+
+static void
+parse_type_decl (void)
+{
+  int k;
+  char *name;
+
+  if (lex () != TYPENAME)
+    {
+      complain ("%s", _("%type declaration has no <typename>"));
+      skip_to_char ('%');
+      return;
+    }
+
+  k = strlen (token_buffer);
+  name = NEW2 (k + 1, char);
+  strcpy (name, token_buffer);
+
+  for (;;)
+    {
+      int t;
+      int tmp_char = ungetc (skip_white_space (), finput);
+
+      if (tmp_char == '%')
+	return;
+      if (tmp_char == EOF)
+	fatal (_("Premature EOF after %s"), token_buffer);
+
+      t = lex ();
+
+      switch (t)
 	{
 
 	case COMMA:
@@ -777,7 +552,7 @@ parse_type_decl (void)
 	case IDENTIFIER:
 	  if (symval->type_name == NULL)
 	    symval->type_name = name;
-	  else if (strcmp(name, symval->type_name) != 0)
+	  else if (strcmp (name, symval->type_name) != 0)
 	    complain (_("type redeclaration for %s"), symval->tag);
 
 	  break;
@@ -785,7 +560,7 @@ parse_type_decl (void)
 	default:
 	  complain (_("invalid %%type declaration due to item: %s"),
 		    token_buffer);
-	  skip_to_char('%');
+	  skip_to_char ('%');
 	}
     }
 }
@@ -798,15 +573,15 @@ parse_type_decl (void)
 static void
 parse_assoc_decl (int assoc)
 {
-  register int k;
-  register char *name = NULL;
-  register int prev = 0;
+  int k;
+  char *name = NULL;
+  int prev = 0;
 
-  lastprec++;  /* Assign a new precedence level, never 0.  */
+  lastprec++;			/* Assign a new precedence level, never 0.  */
 
   for (;;)
     {
-      register int t;
+      int t;
       int tmp_char = ungetc (skip_white_space (), finput);
 
       if (tmp_char == '%')
@@ -814,15 +589,15 @@ parse_assoc_decl (int assoc)
       if (tmp_char == EOF)
 	fatal (_("Premature EOF after %s"), token_buffer);
 
-      t = lex();
+      t = lex ();
 
       switch (t)
 	{
 
 	case TYPENAME:
-	  k = strlen(token_buffer);
-	  name = NEW2(k + 1, char);
-	  strcpy(name, token_buffer);
+	  k = strlen (token_buffer);
+	  name = NEW2 (k + 1, char);
+	  strcpy (name, token_buffer);
 	  break;
 
 	case COMMA:
@@ -837,26 +612,27 @@ parse_assoc_decl (int assoc)
 	    complain (_("symbol %s redefined"), symval->tag);
 	  symval->class = STOKEN;
 	  if (name)
-	    { /* record the type, if one is specified */
+	    {			/* record the type, if one is specified */
 	      if (symval->type_name == NULL)
 		symval->type_name = name;
-	      else if (strcmp(name, symval->type_name) != 0)
+	      else if (strcmp (name, symval->type_name) != 0)
 		complain (_("type redeclaration for %s"), symval->tag);
 	    }
 	  break;
 
 	case NUMBER:
 	  if (prev == IDENTIFIER)
-            {
+	    {
 	      symval->user_token_number = numval;
 	      translations = 1;
-            }
-          else
-            {
-	      complain (_("invalid text (%s) - number should be after identifier"),
-			token_buffer);
-	      skip_to_char('%');
-            }
+	    }
+	  else
+	    {
+	      complain (_
+			("invalid text (%s) - number should be after identifier"),
+token_buffer);
+	      skip_to_char ('%');
+	    }
 	  break;
 
 	case SEMICOLON:
@@ -864,7 +640,7 @@ parse_assoc_decl (int assoc)
 
 	default:
 	  complain (_("unexpected item: %s"), token_buffer);
-	  skip_to_char('%');
+	  skip_to_char ('%');
 	}
 
       prev = t;
@@ -881,8 +657,8 @@ parse_assoc_decl (int assoc)
 static void
 parse_union_decl (void)
 {
-  register int c;
-  register int count = 0;
+  int c;
+  int count = 0;
 
   if (typed)
     complain (_("multiple %s declarations"), "%union");
@@ -936,7 +712,7 @@ parse_union_decl (void)
 	      /* JF don't choke on trailing semi */
 	      c = skip_white_space ();
 	      if (c != ';')
-		ungetc (c,finput);
+		ungetc (c, finput);
 	      return;
 	    }
 	}
@@ -951,20 +727,20 @@ parse_union_decl (void)
 static void
 parse_expect_decl (void)
 {
-  register int c;
-  register int count;
+  int c;
+  int count;
   char buffer[20];
 
-  c = getc(finput);
+  c = getc (finput);
   while (c == ' ' || c == '\t')
-    c = getc(finput);
+    c = getc (finput);
 
   count = 0;
   while (c >= '0' && c <= '9')
     {
       if (count < 20)
 	buffer[count++] = c;
-      c = getc(finput);
+      c = getc (finput);
     }
   buffer[count] = 0;
 
@@ -975,236 +751,199 @@ parse_expect_decl (void)
   expected_conflicts = atoi (buffer);
 }
 
-/* that's all of parsing the declaration section */
-
-/* FIN is pointing to a location (i.e., a `@').  Output to FOUT
-   a reference to this location. STACK_OFFSET is the number of values
-   in the current rule so far, which says where to find `$0' with
-   respect to the top of the stack.  */
-static inline void
-copy_at (FILE *fin, FILE *fout, int stack_offset)
+
+/*-------------------------------------------------------------------.
+| Parse what comes after %thong.  the full syntax is                 |
+|                                                                    |
+|                %thong <type> token number literal                  |
+|                                                                    |
+| the <type> or number may be omitted.  The number specifies the     |
+| user_token_number.                                                 |
+|                                                                    |
+| Two symbols are entered in the table, one for the token symbol and |
+| one for the literal.  Both are given the <type>, if any, from the  |
+| declaration.  The ->user_token_number of the first is SALIAS and   |
+| the ->user_token_number of the second is set to the number, if     |
+| any, from the declaration.  The two symbols are linked via         |
+| pointers in their ->alias fields.                                  |
+|                                                                    |
+| During OUTPUT_DEFINES_TABLE, the symbol is reported thereafter,    |
+| only the literal string is retained it is the literal string that  |
+| is output to yytname                                               |
+`-------------------------------------------------------------------*/
+
+static void
+parse_thong_decl (void)
 {
-  int c;
+  int token;
+  struct bucket *symbol;
+  char *typename = 0;
+  int k, usrtoknum;
 
-  c = getc (fin);
-  if (c == '$')
+  translations = 1;
+  token = lex ();		/* fetch typename or first token */
+  if (token == TYPENAME)
     {
-      fprintf (fout, "yyloc");
-      yylsp_needed = 1;
+      k = strlen (token_buffer);
+      typename = NEW2 (k + 1, char);
+      strcpy (typename, token_buffer);
+      value_components_used = 1;
+      token = lex ();		/* fetch first token */
     }
-  else if (isdigit(c) || c == '-')
-    {
-      int n;
 
-      ungetc (c, fin);
-      n = read_signed_integer (fin);
+  /* process first token */
 
-      fprintf (fout, "yylsp[%d]", n - stack_offset);
-      yylsp_needed = 1;
+  if (token != IDENTIFIER)
+    {
+      complain (_("unrecognized item %s, expected an identifier"),
+		token_buffer);
+      skip_to_char ('%');
+      return;
     }
-  else
-    complain (_("@%s is invalid"), printable_version (c));
-}
-
+  symval->class = STOKEN;
+  symval->type_name = typename;
+  symval->user_token_number = SALIAS;
+  symbol = symval;
 
-/* Get the data type (alternative in the union) of the value for
-   symbol n in rule rule.  */
+  token = lex ();		/* get number or literal string */
 
-static char *
-get_type_name (int n, symbol_list *rule)
-{
-  register int i;
-  register symbol_list *rp;
-
-  if (n < 0)
+  if (token == NUMBER)
     {
-      complain (_("invalid $ value"));
-      return NULL;
+      usrtoknum = numval;
+      token = lex ();		/* okay, did number, now get literal */
     }
+  else
+    usrtoknum = 0;
 
-  rp = rule;
-  i = 0;
+  /* process literal string token */
 
-  while (i < n)
+  if (token != IDENTIFIER || *symval->tag != '\"')
     {
-      rp = rp->next;
-      if (rp == NULL || rp->sym == NULL)
-	{
-	  complain (_("invalid $ value"));
-	  return NULL;
-	}
-      i++;
+      complain (_("expected string constant instead of %s"), token_buffer);
+      skip_to_char ('%');
+      return;
     }
+  symval->class = STOKEN;
+  symval->type_name = typename;
+  symval->user_token_number = usrtoknum;
 
-  return rp->sym->type_name;
-}
-
+  symval->alias = symbol;
+  symbol->alias = symval;
 
+  nsyms--;			/* symbol and symval combined are only one symbol */
+}
 
-/* After `%guard' is seen in the input file, copy the actual guard
-   into the guards file.  If the guard is followed by an action, copy
-   that into the actions file.  STACK_OFFSET is the number of values
-   in the current rule so far, which says where to find `$0' with
-   respect to the top of the stack, for the simple parser in which the
-   stack is not popped until after the guard is run.  */
+/*----------------------------------------------------------------.
+| Read from finput until `%%' is seen.  Discard the `%%'.  Handle |
+| any `%' declarations, and copy the contents of any `%{ ... %}'  |
+| groups to fattrs.                                               |
+`----------------------------------------------------------------*/
 
 static void
-copy_guard (symbol_list *rule, int stack_offset)
+read_declarations (void)
 {
-  register int c;
-  register int n;
-  register int count;
-  register char *type_name;
-  int brace_flag = 0;
-
-  /* offset is always 0 if parser has already popped the stack pointer */
-  if (semantic_parser) stack_offset = 0;
-
-  fprintf(fguard, "\ncase %d:\n", nrules);
-  if (!nolinesflag)
-    fprintf (fguard, "#line %d \"%s\"\n", lineno, infile);
-  putc('{', fguard);
-
-  count = 0;
-  c = getc(finput);
+  int c;
+  int tok;
 
-  while (brace_flag ? (count > 0) : (c != ';'))
+  for (;;)
     {
-      switch (c)
-	{
-	case '\n':
-	  putc(c, fguard);
-	  lineno++;
-	  break;
+      c = skip_white_space ();
 
-	case '{':
-	  putc(c, fguard);
-	  brace_flag = 1;
-	  count++;
-	  break;
+      if (c == '%')
+	{
+	  tok = parse_percent_token ();
 
-	case '}':
-	  putc(c, fguard);
-	  if (count > 0)
-	    count--;
-	  else
+	  switch (tok)
 	    {
-	      complain (_("unmatched %s"), "`}'");
-	      c = getc(finput);	/* skip it */
-	    }
-          break;
+	    case TWO_PERCENTS:
+	      return;
 
-	case '\'':
-	case '"':
-	  copy_string (finput, fguard, c);
-	  break;
+	    case PERCENT_LEFT_CURLY:
+	      copy_definition ();
+	      break;
 
-	case '/':
-	  putc (c, fguard);
-	  c = getc (finput);
-	  if (c != '*' && c != '/')
-	    continue;
-	  copy_comment (finput, fguard, c);
-	  break;
+	    case TOKEN:
+	      parse_token_decl (STOKEN, SNTERM);
+	      break;
 
-	case '$':
-	  c = getc(finput);
-	  type_name = NULL;
+	    case NTERM:
+	      parse_token_decl (SNTERM, STOKEN);
+	      break;
 
-	  if (c == '<')
-	    {
-	      register char *cp = token_buffer;
+	    case TYPE:
+	      parse_type_decl ();
+	      break;
 
-	      while ((c = getc(finput)) != '>' && c > 0)
-		{
-		  if (cp == token_buffer + maxtoken)
-		    cp = grow_token_buffer(cp);
+	    case START:
+	      parse_start_decl ();
+	      break;
 
-		  *cp++ = c;
-		}
-	      *cp = 0;
-	      type_name = token_buffer;
+	    case UNION:
+	      parse_union_decl ();
+	      break;
 
-	      c = getc(finput);
-	    }
+	    case EXPECT:
+	      parse_expect_decl ();
+	      break;
+	    case THONG:
+	      parse_thong_decl ();
+	      break;
+	    case LEFT:
+	      parse_assoc_decl (LEFT_ASSOC);
+	      break;
 
-	  if (c == '$')
-	    {
-	      fprintf(fguard, "yyval");
-	      if (!type_name)
-		type_name = rule->sym->type_name;
-	      if (type_name)
-		fprintf(fguard, ".%s", type_name);
-	      if(!type_name && typed)
-		complain (_("$$ of `%s' has no declared type"),
-			  rule->sym->tag);
-	    }
-	  else if (isdigit(c) || c == '-')
-	    {
-	      ungetc (c, finput);
-	      n = read_signed_integer (finput);
-	      c = getc (finput);
+	    case RIGHT:
+	      parse_assoc_decl (RIGHT_ASSOC);
+	      break;
 
-	      if (!type_name && n > 0)
-		type_name = get_type_name(n, rule);
+	    case NONASSOC:
+	      parse_assoc_decl (NON_ASSOC);
+	      break;
 
-	      fprintf(fguard, "yyvsp[%d]", n - stack_offset);
-	      if (type_name)
-		fprintf(fguard, ".%s", type_name);
-	      if (!type_name && typed)
-		complain (_("$%d of `%s' has no declared type"),
-			  n, rule->sym->tag);
-	      continue;
-	    }
-	  else
-	    complain (_("$%s is invalid"), printable_version (c));
-	  break;
+	    case SEMANTIC_PARSER:
+	      if (semantic_parser == 0)
+		{
+		  semantic_parser = 1;
+		  open_extra_files ();
+		}
+	      break;
 
-	case '@':
-	  copy_at (finput, fguard, stack_offset);
-	  break;
+	    case PURE_PARSER:
+	      pure_parser = 1;
+	      break;
 
-	case EOF:
-	  fatal ("%s",
-		 _("unterminated %guard clause"));
+	    case NOOP:
+	      break;
 
-	default:
-	  putc (c, fguard);
+	    default:
+	      complain (_("unrecognized: %s"), token_buffer);
+	      skip_to_char ('%');
+	    }
+	}
+      else if (c == EOF)
+	fatal (_("no input grammar"));
+      else
+	{
+	  complain (_("unknown character: %s"), printable_version (c));
+	  skip_to_char ('%');
 	}
-
-      if (c != '}' || count != 0)
-	c = getc(finput);
-    }
-
-  c = skip_white_space();
-
-  fprintf(fguard, ";\n    break;}");
-  if (c == '{')
-    copy_action (rule, stack_offset);
-  else if (c == '=')
-    {
-      c = getc(finput);	/* why not skip_white_space -wjh */
-      if (c == '{')
-	copy_action (rule, stack_offset);
     }
-  else
-    ungetc(c, finput);
 }
-
-
-
-/* Assuming that a `{' has just been seen, copy everything up to the
-   matching `}' into the actions file.  STACK_OFFSET is the number of
-   values in the current rule so far, which says where to find `$0'
-   with respect to the top of the stack.  */
+
+/*-------------------------------------------------------------------.
+| Assuming that a `{' has just been seen, copy everything up to the  |
+| matching `}' into the actions file.  STACK_OFFSET is the number of |
+| values in the current rule so far, which says where to find `$0'   |
+| with respect to the top of the stack.                              |
+`-------------------------------------------------------------------*/
 
 static void
-copy_action (symbol_list *rule, int stack_offset)
+copy_action (symbol_list * rule, int stack_offset)
 {
-  register int c;
-  register int n;
-  register int count;
-  register char *type_name;
+  int c;
+  int n;
+  int count;
+  char *type_name;
 
   /* offset is always 0 if parser has already popped the stack pointer */
   if (semantic_parser)
@@ -1216,21 +955,21 @@ copy_action (symbol_list *rule, int stack_offset)
   putc ('{', faction);
 
   count = 1;
-  c = getc(finput);
+  c = getc (finput);
 
   while (count > 0)
     {
       while (c != '}')
-        {
-          switch (c)
+	{
+	  switch (c)
 	    {
 	    case '\n':
-	      putc(c, faction);
+	      putc (c, faction);
 	      lineno++;
 	      break;
 
 	    case '{':
-	      putc(c, faction);
+	      putc (c, faction);
 	      count++;
 	      break;
 
@@ -1248,17 +987,17 @@ copy_action (symbol_list *rule, int stack_offset)
 	      break;
 
 	    case '$':
-	      c = getc(finput);
+	      c = getc (finput);
 	      type_name = NULL;
 
 	      if (c == '<')
 		{
-		  register char *cp = token_buffer;
+		  char *cp = token_buffer;
 
-		  while ((c = getc(finput)) != '>' && c > 0)
+		  while ((c = getc (finput)) != '>' && c > 0)
 		    {
 		      if (cp == token_buffer + maxtoken)
-			cp = grow_token_buffer(cp);
+			cp = grow_token_buffer (cp);
 
 		      *cp++ = c;
 		    }
@@ -1266,32 +1005,32 @@ copy_action (symbol_list *rule, int stack_offset)
 		  type_name = token_buffer;
 		  value_components_used = 1;
 
-		  c = getc(finput);
+		  c = getc (finput);
 		}
 	      if (c == '$')
 		{
-		  fprintf(faction, "yyval");
+		  fprintf (faction, "yyval");
 		  if (!type_name)
-		    type_name = get_type_name(0, rule);
+		    type_name = get_type_name (0, rule);
 		  if (type_name)
-		    fprintf(faction, ".%s", type_name);
-		  if(!type_name && typed)
+		    fprintf (faction, ".%s", type_name);
+		  if (!type_name && typed)
 		    complain (_("$$ of `%s' has no declared type"),
 			      rule->sym->tag);
 		}
-	      else if (isdigit(c) || c == '-')
+	      else if (isdigit (c) || c == '-')
 		{
 		  ungetc (c, finput);
-		  n = read_signed_integer(finput);
-		  c = getc(finput);
+		  n = read_signed_integer (finput);
+		  c = getc (finput);
 
 		  if (!type_name && n > 0)
-		    type_name = get_type_name(n, rule);
+		    type_name = get_type_name (n, rule);
 
-		  fprintf(faction, "yyvsp[%d]", n - stack_offset);
+		  fprintf (faction, "yyvsp[%d]", n - stack_offset);
 		  if (type_name)
-		    fprintf(faction, ".%s", type_name);
-		  if(!type_name && typed)
+		    fprintf (faction, ".%s", type_name);
+		  if (!type_name && typed)
 		    complain (_("$%d of `%s' has no declared type"),
 			      n, rule->sym->tag);
 		  continue;
@@ -1309,73 +1048,297 @@ copy_action (symbol_list *rule, int stack_offset)
 	      fatal (_("unmatched %s"), "`{'");
 
 	    default:
-	      putc(c, faction);
+	      putc (c, faction);
+	    }
+
+	  c = getc (finput);
+	}
+
+      /* above loop exits when c is '}' */
+
+      if (--count)
+	{
+	  putc (c, faction);
+	  c = getc (finput);
+	}
+    }
+
+  fprintf (faction, ";\n    break;}");
+}
+
+/*-------------------------------------------------------------------.
+| After `%guard' is seen in the input file, copy the actual guard    |
+| into the guards file.  If the guard is followed by an action, copy |
+| that into the actions file.  STACK_OFFSET is the number of values  |
+| in the current rule so far, which says where to find `$0' with     |
+| respect to the top of the stack, for the simple parser in which    |
+| the stack is not popped until after the guard is run.              |
+`-------------------------------------------------------------------*/
+
+static void
+copy_guard (symbol_list * rule, int stack_offset)
+{
+  int c;
+  int n;
+  int count;
+  char *type_name;
+  int brace_flag = 0;
+
+  /* offset is always 0 if parser has already popped the stack pointer */
+  if (semantic_parser)
+    stack_offset = 0;
+
+  fprintf (fguard, "\ncase %d:\n", nrules);
+  if (!nolinesflag)
+    fprintf (fguard, "#line %d \"%s\"\n", lineno, infile);
+  putc ('{', fguard);
+
+  count = 0;
+  c = getc (finput);
+
+  while (brace_flag ? (count > 0) : (c != ';'))
+    {
+      switch (c)
+	{
+	case '\n':
+	  putc (c, fguard);
+	  lineno++;
+	  break;
+
+	case '{':
+	  putc (c, fguard);
+	  brace_flag = 1;
+	  count++;
+	  break;
+
+	case '}':
+	  putc (c, fguard);
+	  if (count > 0)
+	    count--;
+	  else
+	    {
+	      complain (_("unmatched %s"), "`}'");
+	      c = getc (finput);	/* skip it */
+	    }
+	  break;
+
+	case '\'':
+	case '"':
+	  copy_string (finput, fguard, c);
+	  break;
+
+	case '/':
+	  putc (c, fguard);
+	  c = getc (finput);
+	  if (c != '*' && c != '/')
+	    continue;
+	  copy_comment (finput, fguard, c);
+	  break;
+
+	case '$':
+	  c = getc (finput);
+	  type_name = NULL;
+
+	  if (c == '<')
+	    {
+	      char *cp = token_buffer;
+
+	      while ((c = getc (finput)) != '>' && c > 0)
+		{
+		  if (cp == token_buffer + maxtoken)
+		    cp = grow_token_buffer (cp);
+
+		  *cp++ = c;
+		}
+	      *cp = 0;
+	      type_name = token_buffer;
+
+	      c = getc (finput);
+	    }
+
+	  if (c == '$')
+	    {
+	      fprintf (fguard, "yyval");
+	      if (!type_name)
+		type_name = rule->sym->type_name;
+	      if (type_name)
+		fprintf (fguard, ".%s", type_name);
+	      if (!type_name && typed)
+		complain (_("$$ of `%s' has no declared type"),
+			  rule->sym->tag);
+	    }
+	  else if (isdigit (c) || c == '-')
+	    {
+	      ungetc (c, finput);
+	      n = read_signed_integer (finput);
+	      c = getc (finput);
+
+	      if (!type_name && n > 0)
+		type_name = get_type_name (n, rule);
+
+	      fprintf (fguard, "yyvsp[%d]", n - stack_offset);
+	      if (type_name)
+		fprintf (fguard, ".%s", type_name);
+	      if (!type_name && typed)
+		complain (_("$%d of `%s' has no declared type"),
+			  n, rule->sym->tag);
+	      continue;
 	    }
+	  else
+	    complain (_("$%s is invalid"), printable_version (c));
+	  break;
 
-          c = getc(finput);
-        }
+	case '@':
+	  copy_at (finput, fguard, stack_offset);
+	  break;
 
-      /* above loop exits when c is '}' */
+	case EOF:
+	  fatal ("%s", _("unterminated %guard clause"));
 
-      if (--count)
-        {
-	  putc(c, faction);
-	  c = getc(finput);
+	default:
+	  putc (c, fguard);
 	}
+
+      if (c != '}' || count != 0)
+	c = getc (finput);
     }
 
-  fprintf(faction, ";\n    break;}");
+  c = skip_white_space ();
+
+  fprintf (fguard, ";\n    break;}");
+  if (c == '{')
+    copy_action (rule, stack_offset);
+  else if (c == '=')
+    {
+      c = getc (finput);	/* why not skip_white_space -wjh */
+      if (c == '{')
+	copy_action (rule, stack_offset);
+    }
+  else
+    ungetc (c, finput);
 }
+
+
+static void
+record_rule_line (void)
+{
+  /* Record each rule's source line number in rline table.  */
 
+  if (nrules >= rline_allocated)
+    {
+      rline_allocated = nrules * 2;
+      rline = (short *) xrealloc ((char *) rline,
+				  rline_allocated * sizeof (short));
+    }
+  rline[nrules] = lineno;
+}
 
 
-/* generate a dummy symbol, a nonterminal,
-whose name cannot conflict with the user's names. */
+/*-------------------------------------------------------------------.
+| Generate a dummy symbol, a nonterminal, whose name cannot conflict |
+| with the user's names.                                             |
+`-------------------------------------------------------------------*/
 
 static bucket *
 gensym (void)
 {
-  register bucket *sym;
+  bucket *sym;
 
   sprintf (token_buffer, "@%d", ++gensym_count);
-  sym = getsym(token_buffer);
+  sym = getsym (token_buffer);
   sym->class = SNTERM;
   sym->value = nvars++;
   return sym;
 }
 
-/* Parse the input grammar into a one symbol_list structure.
-Each rule is represented by a sequence of symbols: the left hand side
-followed by the contents of the right hand side, followed by a null pointer
-instead of a symbol to terminate the rule.
-The next symbol is the lhs of the following rule.
+#if 0
+/*------------------------------------------------------------------.
+| read in a %type declaration and record its information for        |
+| get_type_name to access.  This is unused.  It is only called from |
+| the #if 0 part of readgram                                        |
+`------------------------------------------------------------------*/
+
+static int
+get_type (void)
+{
+  int k;
+  int t;
+  char *name;
+
+  t = lex ();
+
+  if (t != TYPENAME)
+    {
+      complain (_("invalid %s declaration"), "%type");
+      return t;
+    }
+
+  k = strlen (token_buffer);
+  name = NEW2 (k + 1, char);
+  strcpy (name, token_buffer);
+
+  for (;;)
+    {
+      t = lex ();
+
+      switch (t)
+	{
+	case SEMICOLON:
+	  return lex ();
+
+	case COMMA:
+	  break;
+
+	case IDENTIFIER:
+	  if (symval->type_name == NULL)
+	    symval->type_name = name;
+	  else if (strcmp (name, symval->type_name) != 0)
+	    complain (_("type redeclaration for %s"), symval->tag);
+
+	  break;
+
+	default:
+	  return t;
+	}
+    }
+}
 
-All guards and actions are copied out to the appropriate files,
-labelled by the rule number they apply to.  */
+#endif
+
+/*------------------------------------------------------------------.
+| Parse the input grammar into a one symbol_list structure.  Each   |
+| rule is represented by a sequence of symbols: the left hand side  |
+| followed by the contents of the right hand side, followed by a    |
+| null pointer instead of a symbol to terminate the rule.  The next |
+| symbol is the lhs of the following rule.                          |
+|                                                                   |
+| All guards and actions are copied out to the appropriate files,   |
+| labelled by the rule number they apply to.                        |
+`------------------------------------------------------------------*/
 
 static void
 readgram (void)
 {
-  register int t;
-  register bucket *lhs = NULL;
-  register symbol_list *p;
-  register symbol_list *p1;
-  register bucket *bp;
+  int t;
+  bucket *lhs = NULL;
+  symbol_list *p;
+  symbol_list *p1;
+  bucket *bp;
 
-  symbol_list *crule;	/* points to first symbol_list of current rule.  */
-			/* its symbol is the lhs of the rule.   */
-  symbol_list *crule1;  /* points to the symbol_list preceding crule.  */
+  symbol_list *crule;		/* points to first symbol_list of current rule.  */
+  /* its symbol is the lhs of the rule.   */
+  symbol_list *crule1;		/* points to the symbol_list preceding crule.  */
 
   p1 = NULL;
 
-  t = lex();
+  t = lex ();
 
   while (t != TWO_PERCENTS && t != ENDFILE)
     {
       if (t == IDENTIFIER || t == BAR)
 	{
-	  register int actionflag = 0;
-	  int rulelength = 0;  /* number of symbols in rhs of this rule so far  */
+	  int actionflag = 0;
+	  int rulelength = 0;	/* number of symbols in rhs of this rule so far  */
 	  int xactions = 0;	/* JF for error checking */
 	  bucket *first_rhs = 0;
 
@@ -1389,11 +1352,11 @@ readgram (void)
 		  start_flag = 1;
 		}
 
-	      t = lex();
+	      t = lex ();
 	      if (t != COLON)
 		{
 		  complain (_("ill-formed rule: initial symbol not followed by colon"));
-		  unlex(t);
+		  unlex (t);
 		}
 	    }
 
@@ -1409,7 +1372,7 @@ readgram (void)
 
 	  record_rule_line ();
 
-	  p = NEW(symbol_list);
+	  p = NEW (symbol_list);
 	  p->sym = lhs;
 
 	  crule1 = p1;
@@ -1436,48 +1399,50 @@ readgram (void)
 
 	  for (;;)
 	    {
-	      t = lex();
+	      t = lex ();
 	      if (t == PREC)
 		{
-		  t = lex();
+		  t = lex ();
 		  crule->ruleprec = symval;
-		  t = lex();
+		  t = lex ();
 		}
 
-	      if (! (t == IDENTIFIER || t == LEFT_CURLY)) break;
+	      if (!(t == IDENTIFIER || t == LEFT_CURLY))
+		break;
 
 	      /* If next token is an identifier, see if a colon follows it.
-		 If one does, exit this rule now.  */
+	         If one does, exit this rule now.  */
 	      if (t == IDENTIFIER)
 		{
-		  register bucket *ssave;
-		  register int t1;
+		  bucket *ssave;
+		  int t1;
 
 		  ssave = symval;
-		  t1 = lex();
-		  unlex(t1);
+		  t1 = lex ();
+		  unlex (t1);
 		  symval = ssave;
-		  if (t1 == COLON) break;
+		  if (t1 == COLON)
+		    break;
 
-		  if(!first_rhs)	/* JF */
+		  if (!first_rhs)	/* JF */
 		    first_rhs = symval;
 		  /* Not followed by colon =>
 		     process as part of this rule's rhs.  */
 		}
 
 	      /* If we just passed an action, that action was in the middle
-		 of a rule, so make a dummy rule to reduce it to a
-		 non-terminal.  */
+	         of a rule, so make a dummy rule to reduce it to a
+	         non-terminal.  */
 	      if (actionflag)
 		{
-		  register bucket *sdummy;
+		  bucket *sdummy;
 
 		  /* Since the action was written out with this rule's */
 		  /* number, we must give the new rule this number */
 		  /* by inserting the new rule before it.  */
 
 		  /* Make a dummy nonterminal, a gensym.  */
-		  sdummy = gensym();
+		  sdummy = gensym ();
 
 		  /* Make a new rule, whose body is empty,
 		     before the current one, so that the action
@@ -1485,18 +1450,19 @@ readgram (void)
 		  nrules++;
 		  nitems++;
 		  record_rule_line ();
-		  p = NEW(symbol_list);
+		  p = NEW (symbol_list);
 		  if (crule1)
 		    crule1->next = p;
-		  else grammar = p;
+		  else
+		    grammar = p;
 		  p->sym = sdummy;
-		  crule1 = NEW(symbol_list);
+		  crule1 = NEW (symbol_list);
 		  p->next = crule1;
 		  crule1->next = crule;
 
 		  /* insert the dummy generated by that rule into this rule.  */
 		  nitems++;
-		  p = NEW(symbol_list);
+		  p = NEW (symbol_list);
 		  p->sym = sdummy;
 		  p1->next = p;
 		  p1 = p;
@@ -1507,72 +1473,72 @@ readgram (void)
 	      if (t == IDENTIFIER)
 		{
 		  nitems++;
-		  p = NEW(symbol_list);
+		  p = NEW (symbol_list);
 		  p->sym = symval;
 		  p1->next = p;
 		  p1 = p;
 		}
-	      else /* handle an action.  */
+	      else		/* handle an action.  */
 		{
-		  copy_action(crule, rulelength);
+		  copy_action (crule, rulelength);
 		  actionflag = 1;
 		  xactions++;	/* JF */
 		}
 	      rulelength++;
-	    }	/* end of  read rhs of rule */
+	    }			/* end of  read rhs of rule */
 
 	  /* Put an empty link in the list to mark the end of this rule  */
-	  p = NEW(symbol_list);
+	  p = NEW (symbol_list);
 	  p1->next = p;
 	  p1 = p;
 
 	  if (t == PREC)
 	    {
 	      complain (_("two @prec's in a row"));
-	      t = lex();
+	      t = lex ();
 	      crule->ruleprec = symval;
-	      t = lex();
+	      t = lex ();
 	    }
 	  if (t == GUARD)
 	    {
-	      if (! semantic_parser)
+	      if (!semantic_parser)
 		complain ("%s",
-			  _("%guard present but %semantic_parser not specified"));
+			  _
+			  ("%guard present but %semantic_parser not specified"));
 
-	      copy_guard(crule, rulelength);
-	      t = lex();
+	      copy_guard (crule, rulelength);
+	      t = lex ();
 	    }
 	  else if (t == LEFT_CURLY)
 	    {
-		/* This case never occurs -wjh */
+	      /* This case never occurs -wjh */
 	      if (actionflag)
 		complain (_("two actions at end of one rule"));
-	      copy_action(crule, rulelength);
+	      copy_action (crule, rulelength);
 	      actionflag = 1;
 	      xactions++;	/* -wjh */
-	      t = lex();
+	      t = lex ();
 	    }
 	  /* If $$ is being set in default way, report if any type
 	     mismatch.  */
 	  else if (!xactions
-		   && first_rhs
-		   && lhs->type_name != first_rhs->type_name)
+		   && first_rhs && lhs->type_name != first_rhs->type_name)
 	    {
 	      if (lhs->type_name == 0
 		  || first_rhs->type_name == 0
-		  || strcmp(lhs->type_name,first_rhs->type_name))
+		  || strcmp (lhs->type_name, first_rhs->type_name))
 		complain (_("type clash (`%s' `%s') on default action"),
 			  lhs->type_name ? lhs->type_name : "",
-			     first_rhs->type_name ? first_rhs->type_name : "");
+			  first_rhs->type_name ? first_rhs->type_name : "");
 	    }
 	  /* Warn if there is no default for $$ but we need one.  */
 	  else if (!xactions && !first_rhs && lhs->type_name != 0)
 	    complain (_("empty rule for typed nonterminal, and no action"));
 	  if (t == SEMICOLON)
-	    t = lex();
+	    t = lex ();
 	}
 #if 0
-  /* these things can appear as alternatives to rules.  */
+      /* these things can appear as alternatives to rules.  */
 /* NO, they cannot.
 	a) none of the documentation allows them
 	b) most of them scan forward until finding a next %
@@ -1580,39 +1546,39 @@ readgram (void)
 */
       else if (t == TOKEN)
 	{
-	  parse_token_decl(STOKEN, SNTERM);
-	  t = lex();
+	  parse_token_decl (STOKEN, SNTERM);
+	  t = lex ();
 	}
       else if (t == NTERM)
 	{
-	  parse_token_decl(SNTERM, STOKEN);
-	  t = lex();
+	  parse_token_decl (SNTERM, STOKEN);
+	  t = lex ();
 	}
       else if (t == TYPE)
 	{
-	  t = get_type();
+	  t = get_type ();
 	}
       else if (t == UNION)
 	{
-	  parse_union_decl();
-	  t = lex();
+	  parse_union_decl ();
+	  t = lex ();
 	}
       else if (t == EXPECT)
 	{
-	  parse_expect_decl();
-	  t = lex();
+	  parse_expect_decl ();
+	  t = lex ();
 	}
       else if (t == START)
 	{
-	  parse_start_decl();
-	  t = lex();
+	  parse_start_decl ();
+	  t = lex ();
 	}
 #endif
 
       else
 	{
 	  complain (_("invalid input: %s"), token_buffer);
-	  t = lex();
+	  t = lex ();
 	}
     }
 
@@ -1624,15 +1590,15 @@ readgram (void)
   if (nrules == 0)
     fatal (_("no rules in the input grammar"));
 
-  if (typed == 0	/* JF put out same default YYSTYPE as YACC does */
+  if (typed == 0		/* JF put out same default YYSTYPE as YACC does */
       && !value_components_used)
     {
       /* We used to use `unsigned long' as YYSTYPE on MSDOS,
-	 but it seems better to be consistent.
-	 Most programs should declare their own type anyway.  */
-      fprintf(fattrs, "#ifndef YYSTYPE\n#define YYSTYPE int\n#endif\n");
+         but it seems better to be consistent.
+         Most programs should declare their own type anyway.  */
+      fprintf (fattrs, "#ifndef YYSTYPE\n#define YYSTYPE int\n#endif\n");
       if (fdefines)
-	fprintf(fdefines, "#ifndef YYSTYPE\n#define YYSTYPE int\n#endif\n");
+	fprintf (fdefines, "#ifndef YYSTYPE\n#define YYSTYPE int\n#endif\n");
     }
 
   /* Report any undefined symbols and consider them nonterminals.  */
@@ -1640,103 +1606,90 @@ readgram (void)
   for (bp = firstsymbol; bp; bp = bp->next)
     if (bp->class == SUNKNOWN)
       {
-	complain (_("symbol %s is used, but is not defined as a token and has no rules"),
-		  bp->tag);
+	complain (_
+		  ("symbol %s is used, but is not defined as a token and has no rules"),
+bp->tag);
 	bp->class = SNTERM;
 	bp->value = nvars++;
       }
 
   ntokens = nsyms - nvars;
 }
-
+
+/*--------------------------------------------------------------.
+| For named tokens, but not literal ones, define the name.  The |
+| value is the user token number.                               |
+`--------------------------------------------------------------*/
 
 static void
-record_rule_line (void)
-{
-  /* Record each rule's source line number in rline table.  */
-
-  if (nrules >= rline_allocated)
-    {
-      rline_allocated = nrules * 2;
-      rline = (short *) xrealloc ((char *) rline,
-				  rline_allocated * sizeof (short));
-    }
-  rline[nrules] = lineno;
-}
-
-
-#if 0
-/* read in a %type declaration and record its information for get_type_name to access */
-/* this is unused.  it is only called from the #if 0 part of readgram */
-static int
-get_type (void)
+output_token_defines (FILE *file)
 {
-  register int k;
-  register int t;
-  register char *name;
-
-  t = lex();
-
-  if (t != TYPENAME)
-    {
-      complain (_("invalid %s declaration"), "%type");
-      return t;
-    }
-
-  k = strlen(token_buffer);
-  name = NEW2(k + 1, char);
-  strcpy(name, token_buffer);
+  bucket *bp;
+  char *cp, *symbol;
+  char c;
 
-  for (;;)
+  for (bp = firstsymbol; bp; bp = bp->next)
     {
-      t = lex();
-
-      switch (t)
+      symbol = bp->tag;		/* get symbol */
+
+      if (bp->value >= ntokens)
+	continue;
+      if (bp->user_token_number == SALIAS)
+	continue;
+      if ('\'' == *symbol)
+	continue;		/* skip literal character */
+      if (bp == errtoken)
+	continue;		/* skip error token */
+      if ('\"' == *symbol)
 	{
-	case SEMICOLON:
-	  return lex();
-
-	case COMMA:
-	  break;
-
-	case IDENTIFIER:
-	  if (symval->type_name == NULL)
-	    symval->type_name = name;
-	  else if (strcmp(name, symval->type_name) != 0)
-	    complain (_("type redeclaration for %s"), symval->tag);
+	  /* use literal string only if given a symbol with an alias */
+	  if (bp->alias)
+	    symbol = bp->alias->tag;
+	  else
+	    continue;
+	}
 
-	  break;
+      /* Don't #define nonliteral tokens whose names contain periods.  */
+      cp = symbol;
+      while ((c = *cp++) && c != '.');
+      if (c != '\0')
+	continue;
 
-	default:
-	  return t;
-	}
+      fprintf (file, "#define\t%s\t%d\n", symbol,
+	       ((translations && !rawtoknumflag)
+		? bp->user_token_number : bp->value));
+      if (semantic_parser)
+	fprintf (file, "#define\tT%s\t%d\n", symbol, bp->value);
     }
+
+  putc ('\n', file);
 }
-#endif
 
 
-/* Assign symbol numbers, and write definition of token names into
-   fdefines.  Set up vectors tags and sprec of names and precedences
-   of symbols.  */
+/*------------------------------------------------------------------.
+| Assign symbol numbers, and write definition of token names into   |
+| fdefines.  Set up vectors tags and sprec of names and precedences |
+| of symbols.                                                       |
+`------------------------------------------------------------------*/
 
 static void
 packsymbols (void)
 {
-  register bucket *bp;
-  register int tokno = 1;
-  register int i;
-  register int last_user_token_number;
+  bucket *bp;
+  int tokno = 1;
+  int i;
+  int last_user_token_number;
   static char DOLLAR[] = "$";
 
   /* int lossage = 0; JF set but not used */
 
-  tags = NEW2(nsyms + 1, char *);
+  tags = NEW2 (nsyms + 1, char *);
   tags[0] = DOLLAR;
-  user_toknums = NEW2(nsyms + 1, short);
+  user_toknums = NEW2 (nsyms + 1, short);
   user_toknums[0] = 0;
 
-  sprec = NEW2(nsyms, short);
-  sassoc = NEW2(nsyms, short);
+  sprec = NEW2 (nsyms, short);
+  sassoc = NEW2 (nsyms, short);
 
   max_user_token_number = 256;
   last_user_token_number = 256;
@@ -1780,10 +1733,10 @@ packsymbols (void)
 	    }
 
 	  if (bp->user_token_number == SALIAS)
-	    continue;  /* do not do processing below for SALIASs */
+	    continue;		/* do not do processing below for SALIASs */
 
- 	}
-      else  /* bp->class == STOKEN */
+	}
+      else			/* bp->class == STOKEN */
 	{
 	  bp->value = tokno++;
 	}
@@ -1805,35 +1758,34 @@ packsymbols (void)
 
   if (translations)
     {
-      register int j;
+      int j;
 
-      token_translations = NEW2(max_user_token_number+1, short);
+      token_translations = NEW2 (max_user_token_number + 1, short);
 
       /* initialize all entries for literal tokens to 2, the internal
-	 token number for $undefined., which represents all invalid
-	 inputs.  */
+         token number for $undefined., which represents all invalid
+         inputs.  */
       for (j = 0; j <= max_user_token_number; j++)
-        token_translations[j] = 2;
+	token_translations[j] = 2;
 
       for (bp = firstsymbol; bp; bp = bp->next)
-        {
-          if (bp->value >= ntokens)
-	    continue;		  /* non-terminal */
-          if (bp->user_token_number == SALIAS)
+	{
+	  if (bp->value >= ntokens)
+	    continue;		/* non-terminal */
+	  if (bp->user_token_number == SALIAS)
 	    continue;
-          if (token_translations[bp->user_token_number] != 2)
+	  if (token_translations[bp->user_token_number] != 2)
 	    complain (_("tokens %s and %s both assigned number %d"),
 		      tags[token_translations[bp->user_token_number]],
-		  bp->tag,
-		  bp->user_token_number);
-          token_translations[bp->user_token_number] = bp->value;
-        }
+		      bp->tag, bp->user_token_number);
+	  token_translations[bp->user_token_number] = bp->value;
+	}
     }
 
   error_token_number = errtoken->value;
 
-  if (! noparserflag)
-    output_token_defines(ftable);
+  if (!noparserflag)
+    output_token_defines (ftable);
 
   if (startval->class == SUNKNOWN)
     fatal (_("the start symbol %s is undefined"), startval->tag);
@@ -1844,14 +1796,15 @@ packsymbols (void)
 
   if (definesflag)
     {
-      output_token_defines(fdefines);
+      output_token_defines (fdefines);
 
       if (!pure_parser)
 	{
 	  if (spec_name_prefix)
-	    fprintf(fdefines, "\nextern YYSTYPE %slval;\n", spec_name_prefix);
+	    fprintf (fdefines, "\nextern YYSTYPE %slval;\n",
+		     spec_name_prefix);
 	  else
-	    fprintf(fdefines, "\nextern YYSTYPE yylval;\n");
+	    fprintf (fdefines, "\nextern YYSTYPE yylval;\n");
 	}
 
       if (semantic_parser)
@@ -1859,80 +1812,38 @@ packsymbols (void)
 	  {
 	    /* don't make these for dummy nonterminals made by gensym.  */
 	    if (*tags[i] != '@')
-	      fprintf(fdefines, "#define\tNT%s\t%d\n", tags[i], i);
+	      fprintf (fdefines, "#define\tNT%s\t%d\n", tags[i], i);
 	  }
 #if 0
       /* `fdefines' is now a temporary file, so we need to copy its
          contents in `done', so we can't close it here.  */
-      fclose(fdefines);
+      fclose (fdefines);
       fdefines = NULL;
 #endif
     }
 }
 
-/* For named tokens, but not literal ones, define the name.  The value
-   is the user token number.  */
-
-static void
-output_token_defines (FILE *file)
-{
-  bucket *bp;
-  register char *cp, *symbol;
-  register char c;
-
-  for (bp = firstsymbol; bp; bp = bp->next)
-    {
-      symbol = bp->tag;				/* get symbol */
-
-      if (bp->value >= ntokens) continue;
-      if (bp->user_token_number == SALIAS) continue;
-      if ('\'' == *symbol) continue;	/* skip literal character */
-      if (bp == errtoken) continue; 	/* skip error token */
-      if ('\"' == *symbol)
-	{
-		/* use literal string only if given a symbol with an alias */
-		if (bp->alias)
-			symbol = bp->alias->tag;
-		else
-			continue;
-	}
-
-      /* Don't #define nonliteral tokens whose names contain periods.  */
-      cp = symbol;
-      while ((c = *cp++) && c != '.');
-      if (c != '\0')  continue;
-
-      fprintf (file, "#define\t%s\t%d\n", symbol,
-	       ((translations && ! rawtoknumflag)
-		? bp->user_token_number
-		: bp->value));
-      if (semantic_parser)
-        fprintf (file, "#define\tT%s\t%d\n", symbol, bp->value);
-    }
-
-  putc('\n', file);
-}
-
 
-
-/* convert the rules into the representation using rrhs, rlhs and ritems.  */
+/*---------------------------------------------------------------.
+| Convert the rules into the representation using RRHS, RLHS and |
+| RITEMS.                                                        |
+`---------------------------------------------------------------*/
 
 static void
 packgram (void)
 {
-  register int itemno;
-  register int ruleno;
-  register symbol_list *p;
-/*  register bucket *bp; JF unused */
+  int itemno;
+  int ruleno;
+  symbol_list *p;
 
   bucket *ruleprec;
 
-  ritem = NEW2(nitems + 1, short);
-  rlhs = NEW2(nrules, short) - 1;
-  rrhs = NEW2(nrules, short) - 1;
-  rprec = NEW2(nrules, short) - 1;
-  rprecsym = NEW2(nrules, short) - 1;
-  rassoc = NEW2(nrules, short) - 1;
+  ritem = NEW2 (nitems + 1, short);
+  rlhs = NEW2 (nrules, short) - 1;
+  rrhs = NEW2 (nrules, short) - 1;
+  rprec = NEW2 (nrules, short) - 1;
+  rprecsym = NEW2 (nrules, short) - 1;
+  rassoc = NEW2 (nrules, short) - 1;
 
   itemno = 0;
   ruleno = 1;
@@ -1950,28 +1861,127 @@ packgram (void)
 	  ritem[itemno++] = p->sym->value;
 	  /* A rule gets by default the precedence and associativity
 	     of the last token in it.  */
-          if (p->sym->class == STOKEN)
+	  if (p->sym->class == STOKEN)
 	    {
 	      rprec[ruleno] = p->sym->prec;
 	      rassoc[ruleno] = p->sym->assoc;
 	    }
-	  if (p) p = p->next;
+	  if (p)
+	    p = p->next;
 	}
 
       /* If this rule has a %prec,
-	 the specified symbol's precedence replaces the default.  */
+         the specified symbol's precedence replaces the default.  */
       if (ruleprec)
 	{
-          rprec[ruleno] = ruleprec->prec;
-          rassoc[ruleno] = ruleprec->assoc;
+	  rprec[ruleno] = ruleprec->prec;
+	  rassoc[ruleno] = ruleprec->assoc;
 	  rprecsym[ruleno] = ruleprec->value;
 	}
 
       ritem[itemno++] = -ruleno;
       ruleno++;
 
-      if (p) p = p->next;
+      if (p)
+	p = p->next;
     }
 
   ritem[itemno] = 0;
 }
+
+/*-------------------------------------------------------------------.
+| Read in the grammar specification and record it in the format      |
+| described in gram.h.  All guards are copied into the FGUARD file   |
+| and all actions into FACTION, in each case forming the body of a C |
+| function (YYGUARD or YYACTION) which contains a switch statement   |
+| to decide which guard or action to execute.                        |
+`-------------------------------------------------------------------*/
+
+void
+reader (void)
+{
+  start_flag = 0;
+  startval = NULL;		/* start symbol not specified yet. */
+
+#if 0
+  /* initially assume token number translation not needed.  */
+  translations = 0;
+#endif
+  /* Nowadays translations is always set to 1, since we give `error' a
+     user-token-number to satisfy the Posix demand for YYERRCODE==256.
+   */
+  translations = 1;
+
+  nsyms = 1;
+  nvars = 0;
+  nrules = 0;
+  nitems = 0;
+  rline_allocated = 10;
+  rline = NEW2 (rline_allocated, short);
+
+  typed = 0;
+  lastprec = 0;
+
+  gensym_count = 0;
+
+  semantic_parser = 0;
+  pure_parser = 0;
+  yylsp_needed = 0;
+
+  grammar = NULL;
+
+  init_lex ();
+  lineno = 1;
+
+  /* Initialize the symbol table.  */
+  tabinit ();
+  /* Construct the error token */
+  errtoken = getsym ("error");
+  errtoken->class = STOKEN;
+  errtoken->user_token_number = 256;	/* Value specified by POSIX.  */
+  /* Construct a token that represents all undefined literal tokens.
+     It is always token number 2.  */
+  undeftoken = getsym ("$undefined.");
+  undeftoken->class = STOKEN;
+  undeftoken->user_token_number = 2;
+
+  /* Read the declaration section.  Copy %{ ... %} groups to FTABLE
+     and FDEFINES file.  Also notice any %token, %left, etc. found
+     there.  */
+  putc ('\n', ftable);
+  fprintf (ftable, "\
+/* %s, made from %s\n\
+   by GNU bison %s.  */\n\
+\n", noparserflag ? "Bison-generated parse tables" : "A Bison parser", infile, VERSION);
+
+  fputs ("#define YYBISON 1  /* Identify Bison output.  */\n\n", ftable);
+  read_declarations ();
+  /* Start writing the guard and action files, if they are needed.  */
+  output_headers ();
+  /* Read in the grammar, build grammar in list form.  Write out
+     guards and actions.  */
+  readgram ();
+  /* Now we know whether we need the line-number stack.  If we do,
+     write its type into the .tab.h file.  */
+  if (fdefines)
+    reader_output_yylsp (fdefines);
+  /* Write closing delimiters for actions and guards.  */
+  output_trailers ();
+  if (yylsp_needed)
+    fputs ("#define YYLSP_NEEDED\n\n", ftable);
+  /* Assign the symbols their symbol numbers.  Write #defines for the
+     token symbols into FDEFINES if requested.  */
+  packsymbols ();
+  /* Convert the grammar into the format described in gram.h.  */
+  packgram ();
+  /* Free the symbol table data structure since symbols are now all
+     referred to by symbol number.  */
+  free_symtab ();
+}
+
+void
+reader_output_yylsp (FILE *f)
+{
+  if (yylsp_needed)
+    fprintf (f, LTYPESTR);
+}
