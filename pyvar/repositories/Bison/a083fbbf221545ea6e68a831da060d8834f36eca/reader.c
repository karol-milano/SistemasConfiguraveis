@@ -135,14 +135,14 @@ skip_to_char(target)
 {
   int c;
   if (target == '\n')
-    warn("   Skipping to next \\n");
+    warn(_("   Skipping to next \\n"));
   else
-    warni("   Skipping to next %c", target);
+    warni(_("   Skipping to next %c"), target);
 
   do
     c = skip_white_space();
   while (c != target && c != EOF);
-  if (c != EOF) 
+  if (c != EOF)
     ungetc(c, finput);
 }
 
@@ -193,7 +193,7 @@ reader()
   getsym("$undefined.")->class = STOKEN;
   /* Read the declaration section.  Copy %{ ... %} groups to ftable and fdefines file.
      Also notice any %token, %left, etc. found there.  */
-  if (noparserflag) 
+  if (noparserflag)
     fprintf(ftable, "\n/*  Bison-generated parse tables, made from %s\n",
 		infile);
   else
@@ -261,23 +261,23 @@ read_declarations ()
 	    case TOKEN:
 	      parse_token_decl (STOKEN, SNTERM);
 	      break;
-	
+
 	    case NTERM:
 	      parse_token_decl (SNTERM, STOKEN);
 	      break;
-	
+
 	    case TYPE:
 	      parse_type_decl();
 	      break;
-	
+
 	    case START:
 	      parse_start_decl();
 	      break;
-	
+
 	    case UNION:
 	      parse_union_decl();
 	      break;
-	
+
 	    case EXPECT:
 	      parse_expect_decl();
 	      break;
@@ -312,16 +312,16 @@ read_declarations ()
 	      break;
 
 	    default:
-	      warns("unrecognized: %s", token_buffer);
+	      warns(_("unrecognized: %s"), token_buffer);
 	      skip_to_char('%');
 	  }
 	}
       else if (c == EOF)
-        fatal("no input grammar");
+        fatal(_("no input grammar"));
       else
 	{
 		char buff[100];
-		sprintf(buff, "unknown character: %s", printable_version(c)); 
+		sprintf(buff, _("unknown character: %s"), printable_version(c));
 		warn(buff);
 		skip_to_char('%');
 	}
@@ -360,7 +360,7 @@ copy_definition ()
 	case '%':
           after_percent = -1;
 	  break;
-	      
+
 	case '\'':
 	case '"':
 	  match = c;
@@ -370,22 +370,22 @@ copy_definition ()
 	  while (c != match)
 	    {
 	      if (c == EOF)
-		fatal("unterminated string at end of file");
+		fatal(_("unterminated string at end of file"));
 	      if (c == '\n')
 		{
-		  warn("unterminated string");
+		  warn(_("unterminated string"));
 		  ungetc(c, finput);
 		  c = match;
 		  continue;
 		}
 
 	      putc(c, fattrs);
-	      
+
 	      if (c == '\\')
 		{
 		  c = getc(finput);
 		  if (c == EOF)
-		    fatal("unterminated string at end of file");
+		    fatal(_("unterminated string at end of file"));
 		  putc(c, fattrs);
 		  if (c == '\n')
 		    lineno++;
@@ -434,7 +434,7 @@ copy_definition ()
 		    c = getc(finput);
 		}
 	      else if (c == EOF)
-		fatal("unterminated comment in `%{' definition");
+		fatal(_("unterminated comment in `%{' definition"));
 	      else
 		{
 		  putc(c, fattrs);
@@ -445,7 +445,7 @@ copy_definition ()
 	  break;
 
 	case EOF:
-	  fatal("unterminated `%{' definition");
+	  fatal(_("unterminated `%{' definition"));
 
 	default:
 	  putc(c, fattrs);
@@ -499,7 +499,7 @@ parse_token_decl (what_is, what_is_not)
 	  symbol = NULL;
 	}
       else if (token == IDENTIFIER && *symval->tag == '\"'
-		&& symbol) 
+		&& symbol)
 	{
 	  translations = 1;
 	  symval->class = STOKEN;
@@ -507,8 +507,8 @@ parse_token_decl (what_is, what_is_not)
 	  symval->user_token_number = symbol->user_token_number;
 	  symbol->user_token_number = SALIAS;
 
-	  symval->alias = symbol;	
-	  symbol->alias = symval;	
+	  symval->alias = symbol;
+	  symbol->alias = symval;
 	  symbol = NULL;
 
  	  nsyms--;   /* symbol and symval combined are only one symbol */
@@ -519,7 +519,7 @@ parse_token_decl (what_is, what_is_not)
 	  symbol = symval;
 
 	  if (symbol->class == what_is_not)
-	    warns("symbol %s redefined", symbol->tag);
+	    warns(_("symbol %s redefined"), symbol->tag);
 	  symbol->class = what_is;
 	  if (what_is == SNTERM && oldclass != SNTERM)
 	    symbol->value = nvars++;
@@ -529,7 +529,7 @@ parse_token_decl (what_is, what_is_not)
 	      if (symbol->type_name == NULL)
 		symbol->type_name = typename;
 	      else if (strcmp(typename, symbol->type_name) != 0)
-		warns("type redeclaration for %s", symbol->tag);
+		warns(_("type redeclaration for %s"), symbol->tag);
 	    }
 	}
       else if (symbol && token == NUMBER)
@@ -539,8 +539,8 @@ parse_token_decl (what_is, what_is_not)
         }
       else
 	{
-	  warnss("`%s' is invalid in %s",
-		token_buffer, 
+	  warnss(_("`%s' is invalid in %s"),
+		token_buffer,
 		(what_is == STOKEN) ? "%token" : "%nterm");
 	  skip_to_char('%');
 	}
@@ -548,7 +548,7 @@ parse_token_decl (what_is, what_is_not)
 
 }
 
-/* parse what comes after %thong 
+/* parse what comes after %thong
 	the full syntax is
 		%thong <type> token number literal
  the <type> or number may be omitted.  The number specifies the
@@ -559,7 +559,7 @@ parse_token_decl (what_is, what_is_not)
  The ->user_token_number of the first is SALIAS and the ->user_token_number
  of the second is set to the number, if any, from the declaration.
  The two symbols are linked via pointers in their ->alias fields.
- 
+
  during output_defines_table, the symbol is reported
  thereafter, only the literal string is retained
  it is the literal string that is output to yytname
@@ -585,9 +585,9 @@ parse_thong_decl ()
 
   /* process first token */
 
-  if (token != IDENTIFIER) 
+  if (token != IDENTIFIER)
     {
-      warns("unrecognized item %s, expected an identifier", 
+      warns(_("unrecognized item %s, expected an identifier"),
 	    token_buffer);
       skip_to_char('%');
       return;
@@ -598,7 +598,7 @@ parse_thong_decl ()
   symbol = symval;
 
   token = lex();		/* get number or literal string */
-	
+
   if (token == NUMBER) {
     usrtoknum = numval;
     token = lex();		/* okay, did number, now get literal */
@@ -607,9 +607,9 @@ parse_thong_decl ()
 
   /* process literal string token */
 
-  if (token != IDENTIFIER || *symval->tag != '\"') 
+  if (token != IDENTIFIER || *symval->tag != '\"')
     {
-      warns("expected string constant instead of %s", 
+      warns(_("expected string constant instead of %s"),
 	    token_buffer);
       skip_to_char('%');
       return;
@@ -618,8 +618,8 @@ parse_thong_decl ()
   symval->type_name = typename;
   symval->user_token_number = usrtoknum;
 
-  symval->alias = symbol;	
-  symbol->alias = symval;	
+  symval->alias = symbol;
+  symbol->alias = symval;
 
   nsyms--;			/* symbol and symval combined are only one symbol */
 }
@@ -631,9 +631,9 @@ void
 parse_start_decl ()
 {
   if (start_flag)
-    warn("multiple %start declarations");
+    warn(_("multiple %start declarations"));
   if (lex() != IDENTIFIER)
-    warn("invalid %start declaration");
+    warn(_("invalid %start declaration"));
   else
     {
       start_flag = 1;
@@ -653,7 +653,7 @@ parse_type_decl ()
 
   if (lex() != TYPENAME)
     {
-      warn("%type declaration has no <typename>");
+      warn(_("%type declaration has no <typename>"));
       skip_to_char('%');
       return;
     }
@@ -682,12 +682,12 @@ parse_type_decl ()
 	  if (symval->type_name == NULL)
 	    symval->type_name = name;
 	  else if (strcmp(name, symval->type_name) != 0)
-	    warns("type redeclaration for %s", symval->tag);
+	    warns(_("type redeclaration for %s"), symval->tag);
 
 	  break;
 
 	default:
-	  warns("invalid %%type declaration due to item: `%s'", token_buffer);
+	  warns(_("invalid %%type declaration due to item: `%s'"), token_buffer);
 	  skip_to_char('%');
 	}
     }
@@ -731,18 +731,18 @@ int assoc;
 
 	case IDENTIFIER:
 	  if (symval->prec != 0)
-	    warns("redefining precedence of %s", symval->tag);
+	    warns(_("redefining precedence of %s"), symval->tag);
 	  symval->prec = lastprec;
 	  symval->assoc = assoc;
 	  if (symval->class == SNTERM)
-	    warns("symbol %s redefined", symval->tag);
+	    warns(_("symbol %s redefined"), symval->tag);
 	  symval->class = STOKEN;
 	  if (name)
 	    { /* record the type, if one is specified */
 	      if (symval->type_name == NULL)
 		symval->type_name = name;
 	      else if (strcmp(name, symval->type_name) != 0)
-		warns("type redeclaration for %s", symval->tag);
+		warns(_("type redeclaration for %s"), symval->tag);
 	    }
 	  break;
 
@@ -752,9 +752,9 @@ int assoc;
 	      symval->user_token_number = numval;
 	      translations = 1;
             }
-          else	  
+          else
             {
-	      warns("invalid text (%s) - number should be after identifier", 
+	      warns(_("invalid text (%s) - number should be after identifier"),
 			token_buffer);
 	      skip_to_char('%');
             }
@@ -764,7 +764,7 @@ int assoc;
 	  return;
 
 	default:
-	  warns("unexpected item: %s", token_buffer);
+	  warns(_("unexpected item: %s"), token_buffer);
 	  skip_to_char('%');
 	}
 
@@ -788,7 +788,7 @@ parse_union_decl()
   int cplus_comment;
 
   if (typed)
-    warn("multiple %union declarations");
+    warn(_("multiple %union declarations"));
 
   typed = 1;
 
@@ -846,7 +846,7 @@ parse_union_decl()
 			}
 		    }
 		  if (c == EOF)
-		    fatal("unterminated comment at end of file");
+		    fatal(_("unterminated comment at end of file"));
 
 		  if (!cplus_comment && c == '*')
 		    {
@@ -872,7 +872,7 @@ parse_union_decl()
 
 	case '}':
 	  if (count == 0)
-	    warn ("unmatched close-brace (`}')");
+	    warn (_("unmatched close-brace (`}')"));
 	  count--;
 	  if (count <= 0)
 	    {
@@ -916,7 +916,7 @@ parse_expect_decl()
   ungetc (c, finput);
 
   if (count <= 0 || count > 10)
-	warn("argument of %expect is not an integer");
+	warn(_("argument of %expect is not an integer"));
   expected_conflicts = atoi (buffer);
 }
 
@@ -929,14 +929,14 @@ get_type_name(n, rule)
 int n;
 symbol_list *rule;
 {
-  static char *msg = "invalid $ value";
+  static char *msg = N_("invalid $ value");
 
   register int i;
   register symbol_list *rp;
 
   if (n < 0)
     {
-      warn(msg);
+      warn(_(msg));
       return NULL;
     }
 
@@ -948,7 +948,7 @@ symbol_list *rule;
       rp = rp->next;
       if (rp == NULL || rp->sym == NULL)
 	{
-	  warn(msg);
+	  warn(_(msg));
 	  return NULL;
 	}
       i++;
@@ -1009,9 +1009,9 @@ int stack_offset;
 	  putc(c, fguard);
 	  if (count > 0)
 	    count--;
-	  else 
+	  else
 	    {
-	      warn("unmatched right brace (`}')");
+	      warn(_("unmatched right brace (`}')"));
 	      c = getc(finput);	/* skip it */
 	    }
           break;
@@ -1025,22 +1025,22 @@ int stack_offset;
 	  while (c != match)
 	    {
 	      if (c == EOF)
-		fatal("unterminated string at end of file");
-	      if (c == '\n') 
+		fatal(_("unterminated string at end of file"));
+	      if (c == '\n')
 		{
-		  warn("unterminated string");
+		  warn(_("unterminated string"));
 		  ungetc(c, finput);
 		  c = match;		/* invent terminator */
 		  continue;
 		}
 
 	      putc(c, fguard);
-	      
+
 	      if (c == '\\')
 		{
 		  c = getc(finput);
 		  if (c == EOF)
-		    fatal("unterminated string");
+		    fatal(_("unterminated string"));
 		  putc(c, fguard);
 		  if (c == '\n')
 		    lineno++;
@@ -1089,7 +1089,7 @@ int stack_offset;
 		    c = getc(finput);
 		}
 	      else if (c == EOF)
-		fatal("unterminated comment");
+		fatal(_("unterminated comment"));
 	      else
 		{
 		  putc(c, fguard);
@@ -1122,7 +1122,7 @@ int stack_offset;
 	      if (type_name)
 		fprintf(fguard, ".%s", type_name);
 	      if(!type_name && typed)
-		warns("$$ of `%s' has no declared type", rule->sym->tag);
+		warns(_("$$ of `%s' has no declared type"), rule->sym->tag);
 	    }
 
 	  else if (isdigit(c) || c == '-')
@@ -1138,11 +1138,11 @@ int stack_offset;
 	      if (type_name)
 		fprintf(fguard, ".%s", type_name);
 	      if(!type_name && typed)
-		warnss("$%s of `%s' has no declared type", int_to_string(n), rule->sym->tag);
+		warnss(_("$%s of `%s' has no declared type"), int_to_string(n), rule->sym->tag);
 	      continue;
 	    }
 	  else
-	    warni("$%s is invalid", printable_version(c));
+	    warni(_("$%s is invalid"), printable_version(c));
 
 	  break;
 
@@ -1156,7 +1156,7 @@ int stack_offset;
 	    }
 	  else
 	    {
-	      warni("@%s is invalid", printable_version(c));
+	      warni(_("@%s is invalid"), printable_version(c));
 	      n = 1;
 	    }
 
@@ -1166,7 +1166,7 @@ int stack_offset;
 	  continue;
 
 	case EOF:
-	  fatal("unterminated %%guard clause");
+	  fatal(_("unterminated %%guard clause"));
 
 	default:
 	  putc(c, fguard);
@@ -1248,13 +1248,13 @@ int stack_offset;
 		{
 		  if (c == '\n')
 		    {
-		      warn("unterminated string");
+		      warn(_("unterminated string"));
 		      ungetc(c, finput);
 		      c = match;
 		      continue;
 		    }
 		  else if (c == EOF)
-		    fatal("unterminated string at end of file");
+		    fatal(_("unterminated string at end of file"));
 
 		  putc(c, faction);
 
@@ -1262,7 +1262,7 @@ int stack_offset;
 		    {
 		      c = getc(finput);
 		      if (c == EOF)
-			fatal("unterminated string");
+			fatal(_("unterminated string"));
 		      putc(c, faction);
 		      if (c == '\n')
 			lineno++;
@@ -1311,7 +1311,7 @@ int stack_offset;
 		        c = getc(finput);
 		    }
 		  else if (c == EOF)
-		    fatal("unterminated comment");
+		    fatal(_("unterminated comment"));
 		  else
 		    {
 		      putc(c, faction);
@@ -1343,8 +1343,8 @@ int stack_offset;
 		  if (!type_name) type_name = get_type_name(0, rule);
 		  if (type_name)
 		    fprintf(faction, ".%s", type_name);
-		  if(!type_name && typed)	
-		    warns("$$ of `%s' has no declared type", rule->sym->tag);
+		  if(!type_name && typed)
+		    warns(_("$$ of `%s' has no declared type"), rule->sym->tag);
 		}
 	      else if (isdigit(c) || c == '-')
 		{
@@ -1358,13 +1358,13 @@ int stack_offset;
 		  fprintf(faction, "yyvsp[%d]", n - stack_offset);
 		  if (type_name)
 		    fprintf(faction, ".%s", type_name);
-		  if(!type_name && typed)	
-		    warnss("$%s of `%s' has no declared type", 
+		  if(!type_name && typed)
+		    warnss(_("$%s of `%s' has no declared type"),
 				int_to_string(n), rule->sym->tag);
 		  continue;
 		}
 	      else
-		warni("$%s is invalid", printable_version(c));
+		warni(_("$%s is invalid"), printable_version(c));
 
 	      break;
 
@@ -1378,7 +1378,7 @@ int stack_offset;
 		}
 	      else
 		{
-		  warn("invalid @-construct");
+		  warn(_("invalid @-construct"));
 		  n = 1;
 		}
 
@@ -1388,7 +1388,7 @@ int stack_offset;
 	      continue;
 
 	    case EOF:
-	      fatal("unmatched `{'");
+	      fatal(_("unmatched `{'"));
 
 	    default:
 	      putc(c, faction);
@@ -1470,18 +1470,18 @@ readgram()
 		  startval = lhs;
 		  start_flag = 1;
 		}
-    
+
 	      t = lex();
 	      if (t != COLON)
 		{
-		  warn("ill-formed rule: initial symbol not followed by colon");
+		  warn(_("ill-formed rule: initial symbol not followed by colon"));
 		  unlex(t);
 		}
 	    }
 
 	  if (nrules == 0 && t == BAR)
 	    {
-	      warn("grammar starts with vertical bar");
+	      warn(_("grammar starts with vertical bar"));
 	      lhs = symval;	/* BOGUS: use a random symval */
 	    }
 	  /* start a new rule and record its lhs.  */
@@ -1512,7 +1512,7 @@ readgram()
 	      nvars++;
 	    }
 	  else if (lhs->class == STOKEN)
-	    warns("rule given for %s, which is a token", lhs->tag);
+	    warns(_("rule given for %s, which is a token"), lhs->tag);
 
 	  /* read the rhs of the rule.  */
 
@@ -1610,7 +1610,7 @@ readgram()
 
 	  if (t == PREC)
 	    {
-	      warn("two @prec's in a row");
+	      warn(_("two @prec's in a row"));
 	      t = lex();
 	      crule->ruleprec = symval;
 	      t = lex();
@@ -1618,7 +1618,7 @@ readgram()
 	  if (t == GUARD)
 	    {
 	      if (! semantic_parser)
-		warn("%%guard present but %%semantic_parser not specified");
+		warn(_("%%guard present but %%semantic_parser not specified"));
 
 	      copy_guard(crule, rulelength);
 	      t = lex();
@@ -1626,7 +1626,7 @@ readgram()
 	  else if (t == LEFT_CURLY)
 	    {
 		/* This case never occurs -wjh */
-	      if (actionflag)  warn("two actions at end of one rule");
+	      if (actionflag)  warn(_("two actions at end of one rule"));
 	      copy_action(crule, rulelength);
 	      actionflag = 1;
 	      xactions++;	/* -wjh */
@@ -1638,16 +1638,16 @@ readgram()
 	    {
 	      if (lhs->type_name == 0 || first_rhs->type_name == 0
 		  || strcmp(lhs->type_name,first_rhs->type_name))
-		warnss("type clash (`%s' `%s') on default action",
+		warnss(_("type clash (`%s' `%s') on default action"),
 			lhs->type_name ? lhs->type_name : "",
 			first_rhs->type_name ? first_rhs->type_name : "");
 	    }
 	  /* Warn if there is no default for $$ but we need one.  */
 	  else if (!xactions && !first_rhs && lhs->type_name != 0)
-	    warn("empty rule for typed nonterminal, and no action");
+	    warn(_("empty rule for typed nonterminal, and no action"));
 	  if (t == SEMICOLON)
 	    t = lex();
-	}    
+	}
 #if 0
   /* these things can appear as alternatives to rules.  */
 /* NO, they cannot.
@@ -1688,7 +1688,7 @@ readgram()
 
       else
 	{
-	  warns("invalid input: %s", token_buffer);
+	  warns(_("invalid input: %s"), token_buffer);
 	  t = lex();
 	}
     }
@@ -1696,10 +1696,10 @@ readgram()
   /* grammar has been read.  Do some checking */
 
   if (nsyms > MAXSHORT)
-    fatals("too many symbols (tokens plus nonterminals); maximum %s",
+    fatals(_("too many symbols (tokens plus nonterminals); maximum %s"),
 	   int_to_string(MAXSHORT));
   if (nrules == 0)
-    fatal("no rules in the input grammar");
+    fatal(_("no rules in the input grammar"));
 
   if (typed == 0	/* JF put out same default YYSTYPE as YACC does */
       && !value_components_used)
@@ -1717,7 +1717,7 @@ readgram()
   for (bp = firstsymbol; bp; bp = bp->next)
     if (bp->class == SUNKNOWN)
       {
-	warns("symbol %s is used, but is not defined as a token and has no rules",
+	warns(_("symbol %s is used, but is not defined as a token and has no rules"),
 			bp->tag);
 	bp->class = SNTERM;
 	bp->value = nvars++;
@@ -1753,9 +1753,9 @@ get_type()
 
   t = lex();
 
-  if (t != TYPENAME) 
+  if (t != TYPENAME)
     {
-      warn("ill-formed %type declaration");
+      warn(_("ill-formed %type declaration"));
       return t;
     }
 
@@ -1779,7 +1779,7 @@ get_type()
 	  if (symval->type_name == NULL)
 	    symval->type_name = name;
 	  else if (strcmp(name, symval->type_name) != 0)
-	    warns("type redeclaration for %s", symval->tag);
+	    warns(_("type redeclaration for %s"), symval->tag);
 
 	  break;
 
@@ -1825,7 +1825,7 @@ packsymbols()
 	{
 		/* this symbol and its alias are a single token defn.
 		  allocate a tokno, and assign to both
-		  check agreement of ->prec and ->assoc fields 
+		  check agreement of ->prec and ->assoc fields
 			and make both the same
 		*/
 		if (bp->value == 0)
@@ -1834,7 +1834,7 @@ packsymbols()
 		if (bp->prec != bp->alias->prec) {
 			if (bp->prec != 0 && bp->alias->prec != 0
 					&& bp->user_token_number == SALIAS)
-				warnss("conflicting precedences for %s and %s",
+				warnss(_("conflicting precedences for %s and %s"),
 					bp->tag, bp->alias->tag);
 			if (bp->prec != 0) bp->alias->prec = bp->prec;
 			else bp->prec = bp->alias->prec;
@@ -1843,7 +1843,7 @@ packsymbols()
 		if (bp->assoc != bp->alias->assoc) {
 			if (bp->assoc != 0 && bp->alias->assoc != 0
 					&& bp->user_token_number == SALIAS)
-				warnss("conflicting assoc values for %s and %s",
+				warnss(_("conflicting assoc values for %s and %s"),
 					bp->tag, bp->alias->tag);
 			if (bp->assoc != 0) bp->alias->assoc = bp->assoc;
 			else bp->assoc = bp->alias->assoc;
@@ -1883,14 +1883,14 @@ packsymbols()
 	 the internal token number for $undefined.,
 	 which represents all invalid inputs.  */
       for (i = 0; i <= max_user_token_number; i++)
-        token_translations[i] = 2;      
+        token_translations[i] = 2;
 
       for (bp = firstsymbol; bp; bp = bp->next)
         {
           if (bp->value >= ntokens) continue;		  /* non-terminal */
-          if (bp->user_token_number == SALIAS) continue;  
+          if (bp->user_token_number == SALIAS) continue;
           if (token_translations[bp->user_token_number] != 2)
-	    warnsss("tokens %s and %s both assigned number %s",
+	    warnsss(_("tokens %s and %s both assigned number %s"),
 			      tags[token_translations[bp->user_token_number]],
 			      bp->tag,
 			      int_to_string(bp->user_token_number));
@@ -1904,9 +1904,9 @@ packsymbols()
     output_token_defines(ftable);
 
   if (startval->class == SUNKNOWN)
-    fatals("the start symbol %s is undefined", startval->tag);
+    fatals(_("the start symbol %s is undefined"), startval->tag);
   else if (startval->class == STOKEN)
-    fatals("the start symbol %s is a token", startval->tag);
+    fatals(_("the start symbol %s is a token"), startval->tag);
 
   start_symbol = startval->value;
 
@@ -1937,9 +1937,9 @@ packsymbols()
 #endif
     }
 }
-      
-/* For named tokens, but not literal ones, define the name.  
-   The value is the user token number.  
+
+/* For named tokens, but not literal ones, define the name.
+   The value is the user token number.
 */
 void
 output_token_defines(file)
@@ -1957,7 +1957,7 @@ FILE *file;
       if (bp->user_token_number == SALIAS) continue;
       if ('\'' == *symbol) continue;	/* skip literal character */
       if (bp == errtoken) continue; 	/* skip error token */
-      if ('\"' == *symbol) 
+      if ('\"' == *symbol)
 	{
 		/* use literal string only if given a symbol with an alias */
 		if (bp->alias)
@@ -1972,8 +1972,8 @@ FILE *file;
       if (c != '\0')  continue;
 
       fprintf(file, "#define\t%s\t%d\n", symbol,
-		((translations && ! rawtoknumflag) 
-			? bp->user_token_number 
+		((translations && ! rawtoknumflag)
+			? bp->user_token_number
 			: bp->value));
       if (semantic_parser)
         fprintf(file, "#define\tT%s\t%d\n", symbol, bp->value);
