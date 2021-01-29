@@ -1,5 +1,5 @@
 /* Input parser for bison
-   Copyright (C) 1984, 1986, 1989 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 1992 Free Software Foundation, Inc.
 
 This file is part of Bison, the GNU Compiler Compiler.
 
@@ -46,9 +46,10 @@ int rline_allocated;
 extern char *program_name;
 extern int definesflag;
 extern int nolinesflag;
+extern int noparserflag;
+extern int rawtoknumflag;
 extern bucket *symval;
 extern int numval;
-extern int failure;
 extern int expected_conflicts;
 extern char *token_buffer;
 
@@ -58,8 +59,14 @@ extern void output_headers();
 extern void output_trailers();
 extern void free_symtab();
 extern void open_extra_files();
+extern char *int_to_string();
 extern void fatal();
 extern void fatals();
+extern void warn();
+extern void warni();
+extern void warns();
+extern void warnss();
+extern void warnsss();
 extern void unlex();
 extern void done();
 
@@ -67,6 +74,7 @@ extern int skip_white_space();
 extern int parse_percent_token();
 extern int lex();
 
+void reader_output_yylsp();
 void read_declarations();
 void copy_definition();
 void parse_token_decl();
@@ -75,6 +83,7 @@ void parse_type_decl();
 void parse_assoc_decl();
 void parse_union_decl();
 void parse_expect_decl();
+void parse_thong_decl();
 void copy_action();
 void readgram();
 void record_rule_line();
@@ -82,7 +91,7 @@ void packsymbols();
 void output_token_defines();
 void packgram();
 int read_signed_integer();
-int get_type();
+static int get_type();
 
 typedef
   struct symbol_list
@@ -100,6 +109,7 @@ symbol_list *grammar;
 int start_flag;
 bucket *startval;
 char **tags;
+int *user_toknums;
 
 /* Nonzero if components of semantic values are used, implying
    they must be unions.  */
@@ -118,6 +128,25 @@ static int yylsp_needed;
 
 extern char *version_string;
 
+
+static void
+skip_to_char(target)
+     int target;
+{
+  int c;
+  if (target == '\n')
+    warn("   Skipping to next \\n");
+  else
+    warni("   Skipping to next %c", target);
+
+  do
+    c = skip_white_space();
+  while (c != target && c != EOF);
+  if (c != EOF) 
+    ungetc(c, finput);
+}
+
+
 void
 reader()
 {
@@ -164,24 +193,22 @@ reader()
   getsym("$undefined.")->class = STOKEN;
   /* Read the declaration section.  Copy %{ ... %} groups to ftable and fdefines file.
      Also notice any %token, %left, etc. found there.  */
-  fprintf(ftable, "\n/*  A Bison parser, made from %s", infile);
-  fprintf(ftable, " with Bison version %s  */\n\n", version_string);
+  if (noparserflag) 
+    fprintf(ftable, "\n/*  Bison-generated parse tables, made from %s\n",
+		infile);
+  else
+    fprintf(ftable, "\n/*  A Bison parser, made from %s\n", infile);
+  fprintf(ftable, " by  %s  */\n\n", version_string);
   fprintf(ftable, "#define YYBISON 1  /* Identify Bison output.  */\n\n");
   read_declarations();
-  /* output the definition of YYLTYPE into the fattrs and fdefines files.  */
-  /* fattrs winds up in the .tab.c file, before bison.simple.  */
-  fprintf(fattrs, LTYPESTR);
   /* start writing the guard and action files, if they are needed.  */
   output_headers();
   /* read in the grammar, build grammar in list form.  write out guards and actions.  */
   readgram();
   /* Now we know whether we need the line-number stack.
      If we do, write its type into the .tab.h file.  */
-  if (yylsp_needed)
-    {
-      if (fdefines)
-	fprintf(fdefines, LTYPESTR);
-    }
+  if (fdefines)
+    reader_output_yylsp(fdefines);
   /* write closing delimiters for actions and guards.  */
   output_trailers();
   if (yylsp_needed)
@@ -196,7 +223,13 @@ reader()
   free_symtab();
 }
 
-
+void
+reader_output_yylsp(f)
+     FILE *f;
+{
+  if (yylsp_needed)
+    fprintf(f, LTYPESTR);
+}
 
 /* read from finput until %% is seen.  Discard the %%.
 Handle any % declarations,
@@ -248,7 +281,9 @@ read_declarations ()
 	    case EXPECT:
 	      parse_expect_decl();
 	      break;
-	
+	    case THONG:
+	      parse_thong_decl();
+	      break;
 	    case LEFT:
 	      parse_assoc_decl(LEFT_ASSOC);
 	      break;
@@ -273,16 +308,23 @@ read_declarations ()
 	      pure_parser = 1;
 	      break;
 
+	    case NOOP:
+	      break;
+
 	    default:
-	      fatal("junk after `%%' in definition section");
-	    }
+	      warns("unrecognized: %s", token_buffer);
+	      skip_to_char('%');
+	  }
 	}
       else if (c == EOF)
         fatal("no input grammar");
-      else if (c >= 040 && c <= 0177)
-	fatals ("unknown character `%c' in declaration section", c);
       else
-	fatals ("unknown character with code 0x%x in declaration section", c);
+	{
+		char buff[100];
+		sprintf(buff, "unknown character: %s", printable_version(c)); 
+		warn(buff);
+		skip_to_char('%');
+	}
     }
 }
 
@@ -327,8 +369,15 @@ copy_definition ()
 
 	  while (c != match)
 	    {
-	      if (c == EOF || c == '\n')
-		fatal("unterminated string");
+	      if (c == EOF)
+		fatal("unterminated string at end of file");
+	      if (c == '\n')
+		{
+		  warn("unterminated string");
+		  ungetc(c, finput);
+		  c = match;
+		  continue;
+		}
 
 	      putc(c, fattrs);
 	      
@@ -336,7 +385,7 @@ copy_definition ()
 		{
 		  c = getc(finput);
 		  if (c == EOF)
-		    fatal("unterminated string");
+		    fatal("unterminated string at end of file");
 		  putc(c, fattrs);
 		  if (c == '\n')
 		    lineno++;
@@ -426,64 +475,154 @@ void
 parse_token_decl (what_is, what_is_not)
      int what_is, what_is_not;
 {
-/*   register int start_lineno; JF */
   register int token = 0;
-  register int prev;
   register char *typename = 0;
+  register struct bucket *symbol = NULL;  /* pts to symbol being defined */
   int k;
 
-/*   start_lineno = lineno; JF */
-
   for (;;)
     {
       if(ungetc(skip_white_space(), finput) == '%')
 	return;
-
-/*      if (lineno != start_lineno)
-	return; JF */
-
-      /* we have not passed a newline, so the token now starting is in this declaration */
-      prev = token;
-
       token = lex();
       if (token == COMMA)
-	continue;
+	{
+	  symbol = NULL;
+	  continue;
+	}
       if (token == TYPENAME)
 	{
 	  k = strlen(token_buffer);
 	  typename = NEW2(k + 1, char);
 	  strcpy(typename, token_buffer);
 	  value_components_used = 1;
+	  symbol = NULL;
+	}
+      else if (token == IDENTIFIER && *symval->tag == '\"'
+		&& symbol) 
+	{
+	  translations = 1;
+	  symval->class = STOKEN;
+	  symval->type_name = typename;
+	  symval->user_token_number = symbol->user_token_number;
+	  symbol->user_token_number = SALIAS;
+
+	  symval->alias = symbol;	
+	  symbol->alias = symval;	
+	  symbol = NULL;
+
+ 	  nsyms--;   /* symbol and symval combined are only one symbol */
 	}
       else if (token == IDENTIFIER)
 	{
 	  int oldclass = symval->class;
+	  symbol = symval;
 
-	  if (symval->class == what_is_not)
-	    fatals("symbol %s redefined", symval->tag);
-	  symval->class = what_is;
+	  if (symbol->class == what_is_not)
+	    warns("symbol %s redefined", symbol->tag);
+	  symbol->class = what_is;
 	  if (what_is == SNTERM && oldclass != SNTERM)
-	    symval->value = nvars++;
+	    symbol->value = nvars++;
 
 	  if (typename)
 	    {
-	      if (symval->type_name == NULL)
-		symval->type_name = typename;
-	      else
-		fatals("type redeclaration for %s", symval->tag);
+	      if (symbol->type_name == NULL)
+		symbol->type_name = typename;
+	      else if (strcmp(typename, symbol->type_name) != 0)
+		warns("type redeclaration for %s", symbol->tag);
 	    }
 	}
-      else if (prev == IDENTIFIER && token == NUMBER)
+      else if (symbol && token == NUMBER)
         {
-	  symval->user_token_number = numval;
+	  symbol->user_token_number = numval;
 	  translations = 1;
         }
       else
-	fatal("invalid text in %token or %nterm declaration");
+	{
+	  warnss("`%s' is invalid in %s",
+		token_buffer, 
+		(what_is == STOKEN) ? "%token" : "%nterm");
+	  skip_to_char('%');
+	}
     }
 
 }
 
+/* parse what comes after %thong 
+	the full syntax is
+		%thong <type> token number literal
+ the <type> or number may be omitted.  The number specifies the
+ user_token_number.
+
+ Two symbols are entered in the table, one for the token symbol and
+ one for the literal.  Both are given the <type>, if any, from the declaration.
+ The ->user_token_number of the first is SALIAS and the ->user_token_number
+ of the second is set to the number, if any, from the declaration.
+ The two symbols are linked via pointers in their ->alias fields.
+ 
+ during output_defines_table, the symbol is reported
+ thereafter, only the literal string is retained
+ it is the literal string that is output to yytname
+*/
+
+void
+parse_thong_decl ()
+{
+  register int token;
+  register struct bucket *symbol;
+  register char *typename = 0;
+  int k, usrtoknum;
+
+  translations = 1;
+  token = lex();		/* fetch typename or first token */
+  if (token == TYPENAME) {
+    k = strlen(token_buffer);
+    typename = NEW2(k + 1, char);
+    strcpy(typename, token_buffer);
+    value_components_used = 1;
+    token = lex();		/* fetch first token */
+  }
+
+  /* process first token */
+
+  if (token != IDENTIFIER) 
+    {
+      warns("unrecognized item %s, expected an identifier", 
+	    token_buffer);
+      skip_to_char('%');
+      return;
+    }
+  symval->class = STOKEN;
+  symval->type_name = typename;
+  symval->user_token_number = SALIAS;
+  symbol = symval;
+
+  token = lex();		/* get number or literal string */
+	
+  if (token == NUMBER) {
+    usrtoknum = numval;
+    token = lex();		/* okay, did number, now get literal */
+  }
+  else usrtoknum = 0;
+
+  /* process literal string token */
+
+  if (token != IDENTIFIER || *symval->tag != '\"') 
+    {
+      warns("expected string constant instead of %s", 
+	    token_buffer);
+      skip_to_char('%');
+      return;
+    }
+  symval->class = STOKEN;
+  symval->type_name = typename;
+  symval->user_token_number = usrtoknum;
+
+  symval->alias = symbol;	
+  symbol->alias = symval;	
+
+  nsyms--;			/* symbol and symval combined are only one symbol */
+}
 
 
 /* parse what comes after %start */
@@ -492,11 +631,14 @@ void
 parse_start_decl ()
 {
   if (start_flag)
-    fatal("multiple %start declarations");
-  start_flag = 1;
+    warn("multiple %start declarations");
   if (lex() != IDENTIFIER)
-    fatal("invalid %start declaration");
-  startval = symval;
+    warn("invalid %start declaration");
+  else
+    {
+      start_flag = 1;
+      startval = symval;
+    }
 }
 
 
@@ -508,17 +650,18 @@ parse_type_decl ()
 {
   register int k;
   register char *name;
-/*   register int start_lineno; JF */
 
   if (lex() != TYPENAME)
-    fatal("ill-formed %type declaration");
+    {
+      warn("%type declaration has no <typename>");
+      skip_to_char('%');
+      return;
+    }
 
   k = strlen(token_buffer);
   name = NEW2(k + 1, char);
   strcpy(name, token_buffer);
 
-/*   start_lineno = lineno; */
-
   for (;;)
     {
       register int t;
@@ -526,11 +669,6 @@ parse_type_decl ()
       if(ungetc(skip_white_space(), finput) == '%')
 	return;
 
-/*       if (lineno != start_lineno)
-	return; JF */
-
-      /* we have not passed a newline, so the token now starting is in this declaration */
-
       t = lex();
 
       switch (t)
@@ -543,13 +681,14 @@ parse_type_decl ()
 	case IDENTIFIER:
 	  if (symval->type_name == NULL)
 	    symval->type_name = name;
-	  else
-	    fatals("type redeclaration for %s", symval->tag);
+	  else if (strcmp(name, symval->type_name) != 0)
+	    warns("type redeclaration for %s", symval->tag);
 
 	  break;
 
 	default:
-	  fatal("invalid %type declaration");
+	  warns("invalid %%type declaration due to item: `%s'", token_buffer);
+	  skip_to_char('%');
 	}
     }
 }
@@ -565,13 +704,10 @@ int assoc;
 {
   register int k;
   register char *name = NULL;
-/*  register int start_lineno; JF */
-  register int prev = 0;	/* JF added = 0 to keep lint happy */
+  register int prev = 0;
 
   lastprec++;  /* Assign a new precedence level, never 0.  */
 
-/*   start_lineno = lineno; */
-
   for (;;)
     {
       register int t;
@@ -579,11 +715,6 @@ int assoc;
       if(ungetc(skip_white_space(), finput) == '%')
 	return;
 
-      /* if (lineno != start_lineno)
-	return; JF */
-
-      /* we have not passed a newline, so the token now starting is in this declaration */
-
       t = lex();
 
       switch (t)
@@ -600,18 +731,18 @@ int assoc;
 
 	case IDENTIFIER:
 	  if (symval->prec != 0)
-	    fatals("redefining precedence of %s", symval->tag);
+	    warns("redefining precedence of %s", symval->tag);
 	  symval->prec = lastprec;
 	  symval->assoc = assoc;
 	  if (symval->class == SNTERM)
-	    fatals("symbol %s redefined", symval->tag);
+	    warns("symbol %s redefined", symval->tag);
 	  symval->class = STOKEN;
 	  if (name)
 	    { /* record the type, if one is specified */
 	      if (symval->type_name == NULL)
 		symval->type_name = name;
-	      else
-		fatals("type redeclaration for %s", symval->tag);
+	      else if (strcmp(name, symval->type_name) != 0)
+		warns("type redeclaration for %s", symval->tag);
 	    }
 	  break;
 
@@ -622,14 +753,19 @@ int assoc;
 	      translations = 1;
             }
           else	  
-	    fatal("invalid text in association declaration");
+            {
+	      warns("invalid text (%s) - number should be after identifier", 
+			token_buffer);
+	      skip_to_char('%');
+            }
 	  break;
 
 	case SEMICOLON:
 	  return;
 
 	default:
-	  fatal("malformatted association declaration");
+	  warns("unexpected item: %s", token_buffer);
+	  skip_to_char('%');
 	}
 
       prev = t;
@@ -652,7 +788,7 @@ parse_union_decl()
   int cplus_comment;
 
   if (typed)
-    fatal("multiple %union declarations");
+    warn("multiple %union declarations");
 
   typed = 1;
 
@@ -710,7 +846,7 @@ parse_union_decl()
 			}
 		    }
 		  if (c == EOF)
-		    fatal("unterminated comment");
+		    fatal("unterminated comment at end of file");
 
 		  if (!cplus_comment && c == '*')
 		    {
@@ -736,9 +872,9 @@ parse_union_decl()
 
 	case '}':
 	  if (count == 0)
-	    fatal ("unmatched close-brace (`}')");
+	    warn ("unmatched close-brace (`}')");
 	  count--;
-	  if (count == 0)
+	  if (count <= 0)
 	    {
 	      fprintf(fattrs, " YYSTYPE;\n");
 	      if (fdefines)
@@ -779,6 +915,8 @@ parse_expect_decl()
 
   ungetc (c, finput);
 
+  if (count <= 0 || count > 10)
+	warn("argument of %expect is not an integer");
   expected_conflicts = atoi (buffer);
 }
 
@@ -797,7 +935,10 @@ symbol_list *rule;
   register symbol_list *rp;
 
   if (n < 0)
-    fatal(msg);
+    {
+      warn(msg);
+      return NULL;
+    }
 
   rp = rule;
   i = 0;
@@ -806,7 +947,10 @@ symbol_list *rule;
     {
       rp = rp->next;
       if (rp == NULL || rp->sym == NULL)
-	fatal(msg);
+	{
+	  warn(msg);
+	  return NULL;
+	}
       i++;
     }
 
@@ -814,7 +958,6 @@ symbol_list *rule;
 }
 
 
-
 /* after %guard is seen in the input file,
 copy the actual guard into the guards file.
 If the guard is followed by an action, copy that into the actions file.
@@ -866,8 +1009,11 @@ int stack_offset;
 	  putc(c, fguard);
 	  if (count > 0)
 	    count--;
-	  else
-	    fatal("unmatched right brace ('}')");
+	  else 
+	    {
+	      warn("unmatched right brace (`}')");
+	      c = getc(finput);	/* skip it */
+	    }
           break;
 
 	case '\'':
@@ -878,8 +1024,15 @@ int stack_offset;
 
 	  while (c != match)
 	    {
-	      if (c == EOF || c == '\n')
-		fatal("unterminated string");
+	      if (c == EOF)
+		fatal("unterminated string at end of file");
+	      if (c == '\n') 
+		{
+		  warn("unterminated string");
+		  ungetc(c, finput);
+		  c = match;		/* invent terminator */
+		  continue;
+		}
 
 	      putc(c, fguard);
 	      
@@ -968,8 +1121,8 @@ int stack_offset;
 	      if (!type_name) type_name = rule->sym->type_name;
 	      if (type_name)
 		fprintf(fguard, ".%s", type_name);
-	      if(!type_name && typed)	/* JF */
-		fprintf(stderr,"%s:%d:  warning:  $$ of '%s' has no declared type.\n",infile,lineno,rule->sym->tag);
+	      if(!type_name && typed)
+		warns("$$ of `%s' has no declared type", rule->sym->tag);
 	    }
 
 	  else if (isdigit(c) || c == '-')
@@ -984,12 +1137,12 @@ int stack_offset;
 	      fprintf(fguard, "yyvsp[%d]", n - stack_offset);
 	      if (type_name)
 		fprintf(fguard, ".%s", type_name);
-	      if(!type_name && typed)	/* JF */
-		fprintf(stderr,"%s:%d:  warning:  $%d of '%s' has no declared type.\n",infile,lineno,n,rule->sym->tag);
+	      if(!type_name && typed)
+		warnss("$%s of `%s' has no declared type", int_to_string(n), rule->sym->tag);
 	      continue;
 	    }
 	  else
-	    fatals("$%c is invalid",c);	/* JF changed style */
+	    warni("$%s is invalid", printable_version(c));
 
 	  break;
 
@@ -1002,7 +1155,10 @@ int stack_offset;
 	      c = getc(finput);
 	    }
 	  else
-	    fatals("@%c is invalid",c);	/* JF changed style */
+	    {
+	      warni("@%s is invalid", printable_version(c));
+	      n = 1;
+	    }
 
 	  fprintf(fguard, "yylsp[%d]", n - stack_offset);
 	  yylsp_needed = 1;
@@ -1010,7 +1166,7 @@ int stack_offset;
 	  continue;
 
 	case EOF:
-	  fatal("unterminated %guard clause");
+	  fatal("unterminated %%guard clause");
 
 	default:
 	  putc(c, fguard);
@@ -1027,7 +1183,7 @@ int stack_offset;
     copy_action(rule, stack_offset);
   else if (c == '=')
     {
-      c = getc(finput);
+      c = getc(finput);	/* why not skip_white_space -wjh */
       if (c == '{')
 	copy_action(rule, stack_offset);
     }
@@ -1090,8 +1246,15 @@ int stack_offset;
 
 	      while (c != match)
 		{
-		  if (c == EOF || c == '\n')
-		    fatal("unterminated string");
+		  if (c == '\n')
+		    {
+		      warn("unterminated string");
+		      ungetc(c, finput);
+		      c = match;
+		      continue;
+		    }
+		  else if (c == EOF)
+		    fatal("unterminated string at end of file");
 
 		  putc(c, faction);
 
@@ -1180,8 +1343,8 @@ int stack_offset;
 		  if (!type_name) type_name = get_type_name(0, rule);
 		  if (type_name)
 		    fprintf(faction, ".%s", type_name);
-		  if(!type_name && typed)	/* JF */
-		    fprintf(stderr,"%s:%d:  warning:  $$ of '%s' has no declared type.\n",infile,lineno,rule->sym->tag);
+		  if(!type_name && typed)	
+		    warns("$$ of `%s' has no declared type", rule->sym->tag);
 		}
 	      else if (isdigit(c) || c == '-')
 		{
@@ -1195,12 +1358,13 @@ int stack_offset;
 		  fprintf(faction, "yyvsp[%d]", n - stack_offset);
 		  if (type_name)
 		    fprintf(faction, ".%s", type_name);
-		  if(!type_name && typed)	/* JF */
-		    fprintf(stderr,"%s:%d:  warning:  $%d of '%s' has no declared type.\n",infile,lineno,n,rule->sym->tag);
+		  if(!type_name && typed)	
+		    warnss("$%s of `%s' has no declared type", 
+				int_to_string(n), rule->sym->tag);
 		  continue;
 		}
 	      else
-		fatals("$%c is invalid",c);	/* JF changed format */
+		warni("$%s is invalid", printable_version(c));
 
 	      break;
 
@@ -1213,7 +1377,10 @@ int stack_offset;
 		  c = getc(finput);
 		}
 	      else
-		fatal("invalid @-construct");
+		{
+		  warn("invalid @-construct");
+		  n = 1;
+		}
 
 	      fprintf(faction, "yylsp[%d]", n - stack_offset);
 	      yylsp_needed = 1;
@@ -1221,7 +1388,7 @@ int stack_offset;
 	      continue;
 
 	    case EOF:
-	      fatal("unmatched '{'");
+	      fatal("unmatched `{'");
 
 	    default:
 	      putc(c, faction);
@@ -1297,21 +1464,26 @@ readgram()
 	  if (t == IDENTIFIER)
 	    {
 	      lhs = symval;
+
+	      if (!start_flag)
+		{
+		  startval = lhs;
+		  start_flag = 1;
+		}
     
 	      t = lex();
 	      if (t != COLON)
-		fatal("ill-formed rule");
+		{
+		  warn("ill-formed rule: initial symbol not followed by colon");
+		  unlex(t);
+		}
 	    }
 
-	  if (nrules == 0)
+	  if (nrules == 0 && t == BAR)
 	    {
-	      if (t == BAR)
-		fatal("grammar starts with vertical bar");
-
-	      if (!start_flag)
-		startval = lhs;
+	      warn("grammar starts with vertical bar");
+	      lhs = symval;	/* BOGUS: use a random symval */
 	    }
-
 	  /* start a new rule and record its lhs.  */
 
 	  nrules++;
@@ -1340,13 +1512,19 @@ readgram()
 	      nvars++;
 	    }
 	  else if (lhs->class == STOKEN)
-	    fatals("rule given for %s, which is a token", lhs->tag);
+	    warns("rule given for %s, which is a token", lhs->tag);
 
 	  /* read the rhs of the rule.  */
 
 	  for (;;)
 	    {
 	      t = lex();
+	      if (t == PREC)
+		{
+		  t = lex();
+		  crule->ruleprec = symval;
+		  t = lex();
+		}
 
 	      if (! (t == IDENTIFIER || t == LEFT_CURLY)) break;
 
@@ -1377,7 +1555,7 @@ readgram()
 		  register bucket *sdummy;
 
 		  /* Since the action was written out with this rule's */
-		  /* number, we must write give the new rule this number */
+		  /* number, we must give the new rule this number */
 		  /* by inserting the new rule before it.  */
 
 		  /* Make a dummy nonterminal, a gensym.  */
@@ -1423,7 +1601,7 @@ readgram()
 		  xactions++;	/* JF */
 		}
 	      rulelength++;
-	    }
+	    }	/* end of  read rhs of rule */
 
 	  /* Put an empty link in the list to mark the end of this rule  */
 	  p = NEW(symbol_list);
@@ -1432,6 +1610,7 @@ readgram()
 
 	  if (t == PREC)
 	    {
+	      warn("two @prec's in a row");
 	      t = lex();
 	      crule->ruleprec = symval;
 	      t = lex();
@@ -1439,15 +1618,18 @@ readgram()
 	  if (t == GUARD)
 	    {
 	      if (! semantic_parser)
-		fatal("%guard present but %semantic_parser not specified");
+		warn("%%guard present but %%semantic_parser not specified");
 
 	      copy_guard(crule, rulelength);
 	      t = lex();
 	    }
 	  else if (t == LEFT_CURLY)
 	    {
-	      if (actionflag) fatal("two actions at end of one rule");
+		/* This case never occurs -wjh */
+	      if (actionflag)  warn("two actions at end of one rule");
 	      copy_action(crule, rulelength);
+	      actionflag = 1;
+	      xactions++;	/* -wjh */
 	      t = lex();
 	    }
 	  /* If $$ is being set in default way,
@@ -1456,22 +1638,23 @@ readgram()
 	    {
 	      if (lhs->type_name == 0 || first_rhs->type_name == 0
 		  || strcmp(lhs->type_name,first_rhs->type_name))
-		fprintf(stderr, "%s:%d:  warning:  type clash ('%s' '%s') on default action\n",
-			infile,
-			lineno,
+		warnss("type clash (`%s' `%s') on default action",
 			lhs->type_name ? lhs->type_name : "",
 			first_rhs->type_name ? first_rhs->type_name : "");
 	    }
 	  /* Warn if there is no default for $$ but we need one.  */
 	  else if (!xactions && !first_rhs && lhs->type_name != 0)
-	    fprintf(stderr,
-		    "%s:%d:  warning: empty rule for typed nonterminal, and no action\n",
-		    infile,
-		    lineno);
+	    warn("empty rule for typed nonterminal, and no action");
 	  if (t == SEMICOLON)
 	    t = lex();
-	}
-      /* these things can appear as alternatives to rules.  */
+	}    
+#if 0
+  /* these things can appear as alternatives to rules.  */
+/* NO, they cannot.
+	a) none of the documentation allows them
+	b) most of them scan forward until finding a next %
+		thus they may swallow lots of intervening rules
+*/
       else if (t == TOKEN)
 	{
 	  parse_token_decl(STOKEN, SNTERM);
@@ -1501,15 +1684,22 @@ readgram()
 	  parse_start_decl();
 	  t = lex();
 	}
+#endif
+
       else
-	fatal("invalid input");
+	{
+	  warns("invalid input: %s", token_buffer);
+	  t = lex();
+	}
     }
 
+  /* grammar has been read.  Do some checking */
+
   if (nsyms > MAXSHORT)
-    fatals("too many symbols (tokens plus nonterminals); maximum %d",
-	   MAXSHORT);
+    fatals("too many symbols (tokens plus nonterminals); maximum %s",
+	   int_to_string(MAXSHORT));
   if (nrules == 0)
-    fatal("no input grammar");
+    fatal("no rules in the input grammar");
 
   if (typed == 0	/* JF put out same default YYSTYPE as YACC does */
       && !value_components_used)
@@ -1527,9 +1717,8 @@ readgram()
   for (bp = firstsymbol; bp; bp = bp->next)
     if (bp->class == SUNKNOWN)
       {
-	fprintf(stderr, "symbol %s used, not defined as token, and no rules for it\n",
+	warns("symbol %s is used, but is not defined as a token and has no rules",
 			bp->tag);
-	failure = 1;
 	bp->class = SNTERM;
 	bp->value = nvars++;
       }
@@ -1547,15 +1736,15 @@ record_rule_line ()
     {
       rline_allocated = nrules * 2;
       rline = (short *) xrealloc (rline,
-				  rline_allocated * sizeof (short));
+				 rline_allocated * sizeof (short));
     }
   rline[nrules] = lineno;
 }
 
 
 /* read in a %type declaration and record its information for get_type_name to access */
-
-int
+/* this is unused.  it is only called from the #if 0 part of readgram */
+static int
 get_type()
 {
   register int k;
@@ -1564,8 +1753,11 @@ get_type()
 
   t = lex();
 
-  if (t != TYPENAME)
-    fatal("ill-formed %type declaration");
+  if (t != TYPENAME) 
+    {
+      warn("ill-formed %type declaration");
+      return t;
+    }
 
   k = strlen(token_buffer);
   name = NEW2(k + 1, char);
@@ -1586,8 +1778,8 @@ get_type()
 	case IDENTIFIER:
 	  if (symval->type_name == NULL)
 	    symval->type_name = name;
-	  else
-	    fatals("type redeclaration for %s", symval->tag);
+	  else if (strcmp(name, symval->type_name) != 0)
+	    warns("type redeclaration for %s", symval->tag);
 
 	  break;
 
@@ -1614,6 +1806,8 @@ packsymbols()
 
   tags = NEW2(nsyms + 1, char *);
   tags[0] = "$";
+  user_toknums = NEW2(nsyms + 1, int);
+  user_toknums[0] = 0;
 
   sprec = NEW2(nsyms, short);
   sassoc = NEW2(nsyms, short);
@@ -1627,16 +1821,53 @@ packsymbols()
 	{
 	  bp->value += ntokens;
 	}
-      else
+      else if (bp->alias)
+	{
+		/* this symbol and its alias are a single token defn.
+		  allocate a tokno, and assign to both
+		  check agreement of ->prec and ->assoc fields 
+			and make both the same
+		*/
+		if (bp->value == 0)
+			bp->value = bp->alias->value = tokno++;
+
+		if (bp->prec != bp->alias->prec) {
+			if (bp->prec != 0 && bp->alias->prec != 0
+					&& bp->user_token_number == SALIAS)
+				warnss("conflicting precedences for %s and %s",
+					bp->tag, bp->alias->tag);
+			if (bp->prec != 0) bp->alias->prec = bp->prec;
+			else bp->prec = bp->alias->prec;
+		}
+
+		if (bp->assoc != bp->alias->assoc) {
+			if (bp->assoc != 0 && bp->alias->assoc != 0
+					&& bp->user_token_number == SALIAS)
+				warnss("conflicting assoc values for %s and %s",
+					bp->tag, bp->alias->tag);
+			if (bp->assoc != 0) bp->alias->assoc = bp->assoc;
+			else bp->assoc = bp->alias->assoc;
+		}
+
+		if (bp->user_token_number == SALIAS)
+			continue;  /* do not do processing below for SALIASs */
+
+ 	}
+      else  /* bp->class == STOKEN */
+	{
+	  bp->value = tokno++;
+	}
+
+      if (bp->class == STOKEN)
 	{
 	  if (translations && !(bp->user_token_number))
 	    bp->user_token_number = ++last_user_token_number;
 	  if (bp->user_token_number > max_user_token_number)
 	    max_user_token_number = bp->user_token_number;
-	  bp->value = tokno++;
 	}
 
       tags[bp->value] = bp->tag;
+      user_toknums[bp->value] = bp->user_token_number;
       sprec[bp->value] = bp->prec;
       sassoc[bp->value] = bp->assoc;
 
@@ -1653,28 +1884,24 @@ packsymbols()
 	 which represents all invalid inputs.  */
       for (i = 0; i <= max_user_token_number; i++)
         token_translations[i] = 2;      
-    }
 
-  for (bp = firstsymbol; bp; bp = bp->next)
-    {
-      if (bp->value >= ntokens) continue;
-      if (translations)
-	{
-	  if (token_translations[bp->user_token_number] != 2)
-	    {
-	    	/* JF made this a call to fatals() */
-	      fatals( "tokens %s and %s both assigned number %d",
+      for (bp = firstsymbol; bp; bp = bp->next)
+        {
+          if (bp->value >= ntokens) continue;		  /* non-terminal */
+          if (bp->user_token_number == SALIAS) continue;  
+          if (token_translations[bp->user_token_number] != 2)
+	    warnsss("tokens %s and %s both assigned number %s",
 			      tags[token_translations[bp->user_token_number]],
 			      bp->tag,
-			      bp->user_token_number);
-	    }
-	  token_translations[bp->user_token_number] = bp->value;
-	}
+			      int_to_string(bp->user_token_number));
+          token_translations[bp->user_token_number] = bp->value;
+        }
     }
 
   error_token_number = errtoken->value;
 
-  output_token_defines(ftable);
+  if (! noparserflag)
+    output_token_defines(ftable);
 
   if (startval->class == SUNKNOWN)
     fatals("the start symbol %s is undefined", startval->tag);
@@ -1711,37 +1938,45 @@ packsymbols()
     }
 }
       
-
+/* For named tokens, but not literal ones, define the name.  
+   The value is the user token number.  
+*/
 void
 output_token_defines(file)
 FILE *file;
 {
   bucket *bp;
+  register char *cp, *symbol;
+  register char c;
 
   for (bp = firstsymbol; bp; bp = bp->next)
     {
-      if (bp->value >= ntokens) continue;
-
-      /* For named tokens, but not literal ones, define the name.  */
-      /* The value is the user token number.  */
+      symbol = bp->tag;				/* get symbol */
 
-      if ('\'' != *tags[bp->value] && bp != errtoken)
+      if (bp->value >= ntokens) continue;
+      if (bp->user_token_number == SALIAS) continue;
+      if ('\'' == *symbol) continue;	/* skip literal character */
+      if (bp == errtoken) continue; 	/* skip error token */
+      if ('\"' == *symbol) 
 	{
-	  register char *cp = tags[bp->value];
-	  register char c;
+		/* use literal string only if given a symbol with an alias */
+		if (bp->alias)
+			symbol = bp->alias->tag;
+		else
+			continue;
+	}
 
-	  /* Don't #define nonliteral tokens whose names contain periods.  */
+      /* Don't #define nonliteral tokens whose names contain periods.  */
+      cp = symbol;
+      while ((c = *cp++) && c != '.');
+      if (c != '\0')  continue;
 
-	  while ((c = *cp++) && c != '.');
-	  if (!c)
-	    {
-              fprintf(file, "#define\t%s\t%d\n", tags[bp->value],
-			    (translations ? bp->user_token_number : bp->value));
-	      if (semantic_parser)
-                fprintf(file, "#define\tT%s\t%d\n", tags[bp->value],
-			      bp->value);
-	    }
-	}
+      fprintf(file, "#define\t%s\t%d\n", symbol,
+		((translations && ! rawtoknumflag) 
+			? bp->user_token_number 
+			: bp->value));
+      if (semantic_parser)
+        fprintf(file, "#define\tT%s\t%d\n", symbol, bp->value);
     }
 
   putc('\n', file);
