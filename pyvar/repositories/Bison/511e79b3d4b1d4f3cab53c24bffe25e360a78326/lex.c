@@ -355,7 +355,7 @@ read_type_name (FILE *fin)
 }
 
 
-int
+token_t
 lex (void)
 {
   int c;
@@ -378,7 +378,7 @@ lex (void)
     {
     case EOF:
       strcpy (token_buffer, "EOF");
-      return ENDFILE;
+      return tok_eof;
 
     case 'A':    case 'B':    case 'C':    case 'D':    case 'E':
     case 'F':    case 'G':    case 'H':    case 'I':    case 'J':
@@ -407,7 +407,7 @@ lex (void)
       *p = 0;
       ungetc (c, finput);
       symval = getsym (token_buffer);
-      return IDENTIFIER;
+      return tok_identifier;
 
     case '0':    case '1':    case '2':    case '3':    case '4':
     case '5':    case '6':    case '7':    case '8':    case '9':
@@ -426,7 +426,7 @@ lex (void)
 	  }
 	*p = 0;
 	ungetc (c, finput);
-	return NUMBER;
+	return tok_number;
       }
 
     case '\'':
@@ -458,7 +458,7 @@ lex (void)
 	symval->class = token_sym;
 	if (!symval->user_token_number)
 	  symval->user_token_number = code;
-	return IDENTIFIER;
+	return tok_identifier;
       }
 
     case '\"':
@@ -480,23 +480,23 @@ lex (void)
 	symval = getsym (token_buffer);
 	symval->class = token_sym;
 
-	return IDENTIFIER;
+	return tok_identifier;
       }
 
     case ',':
-      return COMMA;
+      return tok_comma;
 
     case ':':
-      return COLON;
+      return tok_colon;
 
     case ';':
-      return SEMICOLON;
+      return tok_semicolon;
 
     case '|':
-      return BAR;
+      return tok_bar;
 
     case '{':
-      return LEFT_CURLY;
+      return tok_left_curly;
 
     case '=':
       do
@@ -510,23 +510,23 @@ lex (void)
       if (c == '{')
 	{
 	  strcpy (token_buffer, "={");
-	  return LEFT_CURLY;
+	  return tok_left_curly;
 	}
       else
 	{
 	  ungetc (c, finput);
-	  return ILLEGAL;
+	  return tok_illegal;
 	}
 
     case '<':
       read_type_name (finput);
-      return TYPENAME;
+      return tok_typename;
 
     case '%':
       return parse_percent_token ();
 
     default:
-      return ILLEGAL;
+      return tok_illegal;
     }
 }
 
@@ -542,44 +542,44 @@ struct percent_table_struct
 
 struct percent_table_struct percent_table[] =
 {
-  { "token",		NULL,			TOKEN },
-  { "term",		NULL,			TOKEN },
-  { "nterm",		NULL,			NTERM },
-  { "type",		NULL,			TYPE },
-  { "guard",		NULL,			GUARD },
-  { "union",		NULL,			UNION },
-  { "expect",		NULL,			EXPECT },
-  { "thong",		NULL,			THONG },
-  { "start",		NULL,			START },
-  { "left",		NULL,			LEFT },
-  { "right",		NULL,			RIGHT },
-  { "nonassoc",		NULL,			NONASSOC },
-  { "binary",		NULL,			NONASSOC },
-  { "prec",		NULL,			PREC },
-  { "locations",	&locations_flag,	NOOP },		/* -l */
-  { "no_lines",		&no_lines_flag,		NOOP },		/* -l */
-  { "raw",		&raw_flag,		NOOP },		/* -r */
-  { "token_table",	&token_table_flag,	NOOP },		/* -k */
-  { "yacc",		&yacc_flag,		NOOP },		/* -y */
-  { "fixed_output_files",&yacc_flag,		NOOP },		/* -y */
-  { "defines",		&defines_flag,		NOOP },		/* -d */
-  { "no_parser",	&no_parser_flag,	NOOP },		/* -n */
+  { "token",		NULL,			tok_token },
+  { "term",		NULL,			tok_token },
+  { "nterm",		NULL,			tok_nterm },
+  { "type",		NULL,			tok_type },
+  { "guard",		NULL,			tok_guard },
+  { "union",		NULL,			tok_union },
+  { "expect",		NULL,			tok_expect },
+  { "thong",		NULL,			tok_thong },
+  { "start",		NULL,			tok_start },
+  { "left",		NULL,			tok_left },
+  { "right",		NULL,			tok_right },
+  { "nonassoc",		NULL,			tok_nonassoc },
+  { "binary",		NULL,			tok_nonassoc },
+  { "prec",		NULL,			tok_prec },
+  { "locations",	&locations_flag,	tok_noop },		/* -l */
+  { "no_lines",		&no_lines_flag,		tok_noop },		/* -l */
+  { "raw",		&raw_flag,		tok_noop },		/* -r */
+  { "token_table",	&token_table_flag,	tok_noop },		/* -k */
+  { "yacc",		&yacc_flag,		tok_noop },		/* -y */
+  { "fixed_output_files",&yacc_flag,		tok_noop },		/* -y */
+  { "defines",		&defines_flag,		tok_noop },		/* -d */
+  { "no_parser",	&no_parser_flag,	tok_noop },		/* -n */
 #if 0
   /* For the time being, this is not enabled yet, while it's possible
      though, since we use obstacks.  The only risk is with semantic
      parsers which will output an `include' of an output file: be sure
      that the naem included is indeed the name of the output file.  */
-  { "output_file",	&spec_outfile,		SETOPT },	/* -o */
-  { "file_prefix",	&spec_file_prefix,	SETOPT },	/* -b */
-  { "name_prefix",	&spec_name_prefix,	SETOPT },	/* -p */
+  { "output_file",	&spec_outfile,		tok_setopt },	/* -o */
+  { "file_prefix",	&spec_file_prefix,	tok_setopt },	/* -b */
+  { "name_prefix",	&spec_name_prefix,	tok_setopt },	/* -p */
 #endif
-  { "verbose",		&verbose_flag,		NOOP },		/* -v */
-  { "debug",		&debug_flag,		NOOP },		/* -t */
-  { "semantic_parser",	&semantic_parser,	NOOP },
-  { "pure_parser",	&pure_parser,		NOOP },
-/*    {"help", <print usage stmt>, NOOP}, *//* -h */
-/*    {"version", <print version number> ,  NOOP}, *//* -V */
-  { NULL, NULL, ILLEGAL}
+  { "verbose",		&verbose_flag,		tok_noop },		/* -v */
+  { "debug",		&debug_flag,		tok_noop },		/* -t */
+  { "semantic_parser",	&semantic_parser,	tok_noop },
+  { "pure_parser",	&pure_parser,		tok_noop },
+/*    {"help", <print usage stmt>, tok_noop}, *//* -h */
+/*    {"version", <print version number> ,  tok_noop}, *//* -V */
+  { NULL, NULL, tok_illegal}
 };
 
 /* Parse a token which starts with %.
@@ -601,28 +601,28 @@ parse_percent_token (void)
   switch (c)
     {
     case '%':
-      return TWO_PERCENTS;
+      return tok_two_percents;
 
     case '{':
-      return PERCENT_LEFT_CURLY;
+      return tok_percent_left_curly;
 
     case '<':
-      return LEFT;
+      return tok_left;
 
     case '>':
-      return RIGHT;
+      return tok_right;
 
     case '2':
-      return NONASSOC;
+      return tok_nonassoc;
 
     case '0':
-      return TOKEN;
+      return tok_token;
 
     case '=':
-      return PREC;
+      return tok_prec;
     }
   if (!isalpha (c))
-    return ILLEGAL;
+    return tok_illegal;
 
   p = token_buffer;
   *p++ = '%';
@@ -646,15 +646,15 @@ parse_percent_token (void)
     if (strcmp (token_buffer + 1, tx->name) == 0)
       break;
 
-  if (tx->retval == SETOPT)
+  if (tx->retval == tok_setopt)
     {
       *((char **) (tx->set_flag)) = optarg;
-      return NOOP;
+      return tok_noop;
     }
   if (tx->set_flag)
     {
       *((int *) (tx->set_flag)) = 1;
-      return NOOP;
+      return tok_noop;
     }
   return tx->retval;
 }
