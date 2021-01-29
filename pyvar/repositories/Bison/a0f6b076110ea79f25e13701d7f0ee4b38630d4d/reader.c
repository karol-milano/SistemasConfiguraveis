@@ -35,6 +35,7 @@
 #include "lex.h"
 #include "gram.h"
 #include "machine.h"
+#include "complain.h"
 
 #define	LTYPESTR	"\
 \n\
@@ -61,7 +62,6 @@ typedef\n\
 /* Number of slots allocated (but not necessarily used yet) in `rline'  */
 int rline_allocated;
 
-extern char *program_name;
 extern int definesflag;
 extern int nolinesflag;
 extern int noparserflag;
@@ -79,17 +79,8 @@ extern void output_headers PARAMS((void));
 extern void output_trailers PARAMS((void));
 extern void free_symtab PARAMS((void));
 extern void open_extra_files PARAMS((void));
-extern char *int_to_string PARAMS((int));
 extern char *printable_version PARAMS((int));
-extern void fatal PARAMS((char *));
-extern void fatals PARAMS((char *, char *));
-extern void warn PARAMS((char *));
-extern void warni PARAMS((char *, int));
-extern void warns PARAMS((char *, char *));
-extern void warnss PARAMS((char *, char *, char *));
-extern void warnsss PARAMS((char *, char *, char *, char *));
 extern void unlex PARAMS((int));
-extern void done PARAMS((int));
 
 extern int skip_white_space PARAMS((void));
 extern int parse_percent_token PARAMS((void));
@@ -160,9 +151,9 @@ skip_to_char (int target)
 {
   int c;
   if (target == '\n')
-    warn(_("   Skipping to next \\n"));
+    complain (_("   Skipping to next \\n"));
   else
-    warni(_("   Skipping to next %c"), target);
+    complain (_("   Skipping to next %c"), target);
 
   do
     c = skip_white_space();
@@ -189,7 +180,7 @@ copy_string (FILE *finput, FILE *foutput, int match)
 	fatal (_("unterminated string at end of file"));
       if (c == '\n')
 	{
-	  warn (_("unterminated string"));
+	  complain (_("unterminated string"));
 	  ungetc (c, finput);
 	  c = match;		/* invent terminator */
 	  continue;
@@ -221,7 +212,6 @@ static inline void
 copy_comment (FILE *finput, FILE *foutput, int c)
 {
   int cplus_comment;
-  register int match;
   register int ended;
 
   cplus_comment = (c == '/');
@@ -431,15 +421,15 @@ read_declarations (void)
 	      break;
 
 	    default:
-	      warns(_("unrecognized: %s"), token_buffer);
+	      complain (_("unrecognized: %s"), token_buffer);
 	      skip_to_char('%');
 	  }
 	}
       else if (c == EOF)
-        fatal(_("no input grammar"));
+        fatal (_("no input grammar"));
       else
 	{
-	  warns (_("unknown character: %s"), printable_version(c));
+	  complain (_("unknown character: %s"), printable_version(c));
 	  skip_to_char('%');
 	}
     }
@@ -490,7 +480,8 @@ copy_definition (void)
 	  break;
 
 	case EOF:
-	  fatal(_("unterminated `%{' definition"));
+	  fatal ("%s",
+		 _("unterminated `%{' definition"));
 
 	default:
 	  putc(c, fattrs);
@@ -531,7 +522,7 @@ parse_token_decl (int what_is, int what_is_not)
       if (tmp_char == '%')
 	return;
       if (tmp_char == EOF)
-	fatals ("Premature EOF after %s", token_buffer);
+	fatal (_("Premature EOF after %s"), token_buffer);
 
       token = lex();
       if (token == COMMA)
@@ -568,7 +559,7 @@ parse_token_decl (int what_is, int what_is_not)
 	  symbol = symval;
 
 	  if (symbol->class == what_is_not)
-	    warns(_("symbol %s redefined"), symbol->tag);
+	    complain (_("symbol %s redefined"), symbol->tag);
 	  symbol->class = what_is;
 	  if (what_is == SNTERM && oldclass != SNTERM)
 	    symbol->value = nvars++;
@@ -578,7 +569,7 @@ parse_token_decl (int what_is, int what_is_not)
 	      if (symbol->type_name == NULL)
 		symbol->type_name = typename;
 	      else if (strcmp(typename, symbol->type_name) != 0)
-		warns(_("type redeclaration for %s"), symbol->tag);
+		complain (_("type redeclaration for %s"), symbol->tag);
 	    }
 	}
       else if (symbol && token == NUMBER)
@@ -588,8 +579,8 @@ parse_token_decl (int what_is, int what_is_not)
         }
       else
 	{
-	  warnss(_("`%s' is invalid in %s"),
-		token_buffer,
+	  complain (_("`%s' is invalid in %s"),
+		    token_buffer,
 		(what_is == STOKEN) ? "%token" : "%nterm");
 	  skip_to_char('%');
 	}
@@ -636,8 +627,8 @@ parse_thong_decl (void)
 
   if (token != IDENTIFIER)
     {
-      warns(_("unrecognized item %s, expected an identifier"),
-	    token_buffer);
+      complain (_("unrecognized item %s, expected an identifier"),
+		token_buffer);
       skip_to_char('%');
       return;
     }
@@ -658,8 +649,8 @@ parse_thong_decl (void)
 
   if (token != IDENTIFIER || *symval->tag != '\"')
     {
-      warns(_("expected string constant instead of %s"),
-	    token_buffer);
+      complain (_("expected string constant instead of %s"),
+		token_buffer);
       skip_to_char('%');
       return;
     }
@@ -674,15 +665,15 @@ parse_thong_decl (void)
 }
 
 
-/* parse what comes after %start */
+/* Parse what comes after %start */
 
 void
 parse_start_decl (void)
 {
   if (start_flag)
-    warn(_("multiple %start declarations"));
+    complain ("%s", _("multiple %start declarations"));
   if (lex() != IDENTIFIER)
-    warn(_("invalid %start declaration"));
+    complain ("%s", _("invalid %start declaration"));
   else
     {
       start_flag = 1;
@@ -702,7 +693,7 @@ parse_type_decl (void)
 
   if (lex() != TYPENAME)
     {
-      warn(_("%type declaration has no <typename>"));
+      complain ("%s", _("%type declaration has no <typename>"));
       skip_to_char('%');
       return;
     }
@@ -719,7 +710,7 @@ parse_type_decl (void)
       if (tmp_char == '%')
 	return;
       if (tmp_char == EOF)
-	fatals ("Premature EOF after %s", token_buffer);
+	fatal (_("Premature EOF after %s"), token_buffer);
 
       t = lex();
 
@@ -734,12 +725,13 @@ parse_type_decl (void)
 	  if (symval->type_name == NULL)
 	    symval->type_name = name;
 	  else if (strcmp(name, symval->type_name) != 0)
-	    warns(_("type redeclaration for %s"), symval->tag);
+	    complain (_("type redeclaration for %s"), symval->tag);
 
 	  break;
 
 	default:
-	  warns(_("invalid %%type declaration due to item: `%s'"), token_buffer);
+	  complain (_("invalid %%type declaration due to item: %s"),
+		    token_buffer);
 	  skip_to_char('%');
 	}
     }
@@ -767,7 +759,7 @@ parse_assoc_decl (int assoc)
       if (tmp_char == '%')
 	return;
       if (tmp_char == EOF)
-	fatals ("Premature EOF after %s", token_buffer);
+	fatal (_("Premature EOF after %s"), token_buffer);
 
       t = lex();
 
@@ -785,18 +777,18 @@ parse_assoc_decl (int assoc)
 
 	case IDENTIFIER:
 	  if (symval->prec != 0)
-	    warns(_("redefining precedence of %s"), symval->tag);
+	    complain (_("redefining precedence of %s"), symval->tag);
 	  symval->prec = lastprec;
 	  symval->assoc = assoc;
 	  if (symval->class == SNTERM)
-	    warns(_("symbol %s redefined"), symval->tag);
+	    complain (_("symbol %s redefined"), symval->tag);
 	  symval->class = STOKEN;
 	  if (name)
 	    { /* record the type, if one is specified */
 	      if (symval->type_name == NULL)
 		symval->type_name = name;
 	      else if (strcmp(name, symval->type_name) != 0)
-		warns(_("type redeclaration for %s"), symval->tag);
+		complain (_("type redeclaration for %s"), symval->tag);
 	    }
 	  break;
 
@@ -808,7 +800,7 @@ parse_assoc_decl (int assoc)
             }
           else
             {
-	      warns(_("invalid text (%s) - number should be after identifier"),
+	      complain (_("invalid text (%s) - number should be after identifier"),
 			token_buffer);
 	      skip_to_char('%');
             }
@@ -818,7 +810,7 @@ parse_assoc_decl (int assoc)
 	  return;
 
 	default:
-	  warns(_("unexpected item: %s"), token_buffer);
+	  complain (_("unexpected item: %s"), token_buffer);
 	  skip_to_char('%');
 	}
 
@@ -842,7 +834,7 @@ parse_union_decl (void)
   int cplus_comment;
 
   if (typed)
-    warn(_("multiple %union declarations"));
+    complain ("%s", _("multiple %union declarations"));
 
   typed = 1;
 
@@ -900,7 +892,7 @@ parse_union_decl (void)
 			}
 		    }
 		  if (c == EOF)
-		    fatal(_("unterminated comment at end of file"));
+		    fatal (_("unterminated comment at end of file"));
 
 		  if (!cplus_comment && c == '*')
 		    {
@@ -926,7 +918,7 @@ parse_union_decl (void)
 
 	case '}':
 	  if (count == 0)
-	    warn (_("unmatched close-brace (`}')"));
+	    complain (_("unmatched close-brace (`}')"));
 	  count--;
 	  if (count <= 0)
 	    {
@@ -970,7 +962,7 @@ parse_expect_decl (void)
   ungetc (c, finput);
 
   if (count <= 0 || count > 10)
-	warn(_("argument of %expect is not an integer"));
+    complain ("%s", _("argument of %expect is not an integer"));
   expected_conflicts = atoi (buffer);
 }
 
@@ -1002,23 +994,22 @@ copy_at (FILE *finput, FILE *foutput, int stack_offset)
       yylsp_needed = 1;
     }
   else
-    warns (_("@%s is invalid"), printable_version (c));
+    complain (_("@%s is invalid"), printable_version (c));
 }
 
 
-/* Get the data type (alternative in the union) of the value for symbol n in rule rule.  */
+/* Get the data type (alternative in the union) of the value for
+   symbol n in rule rule.  */
 
 char *
 get_type_name (int n, symbol_list *rule)
 {
-  static char *msg = N_("invalid $ value");
-
   register int i;
   register symbol_list *rp;
 
   if (n < 0)
     {
-      warn(_(msg));
+      complain (_("invalid $ value"));
       return NULL;
     }
 
@@ -1030,7 +1021,7 @@ get_type_name (int n, symbol_list *rule)
       rp = rp->next;
       if (rp == NULL || rp->sym == NULL)
 	{
-	  warn(_(msg));
+	  complain (_("invalid $ value"));
 	  return NULL;
 	}
       i++;
@@ -1089,7 +1080,7 @@ copy_guard (symbol_list *rule, int stack_offset)
 	    count--;
 	  else
 	    {
-	      warn(_("unmatched right brace (`}')"));
+	      complain (_("unmatched right brace (`}')"));
 	      c = getc(finput);	/* skip it */
 	    }
           break;
@@ -1136,7 +1127,8 @@ copy_guard (symbol_list *rule, int stack_offset)
 	      if (type_name)
 		fprintf(fguard, ".%s", type_name);
 	      if(!type_name && typed)
-		warns(_("$$ of `%s' has no declared type"), rule->sym->tag);
+		complain (_("$$ of `%s' has no declared type"),
+			  rule->sym->tag);
 	    }
 	  else if (isdigit(c) || c == '-')
 	    {
@@ -1151,12 +1143,12 @@ copy_guard (symbol_list *rule, int stack_offset)
 	      if (type_name)
 		fprintf(fguard, ".%s", type_name);
 	      if (!type_name && typed)
-		warnss (_("$%s of `%s' has no declared type"),
-			int_to_string(n), rule->sym->tag);
+		complain (_("$%d of `%s' has no declared type"),
+			  n, rule->sym->tag);
 	      continue;
 	    }
 	  else
-	    warns(_("$%s is invalid"), printable_version(c));
+	    complain (_("$%s is invalid"), printable_version (c));
 	  break;
 
 	case '@':
@@ -1164,7 +1156,8 @@ copy_guard (symbol_list *rule, int stack_offset)
 	  break;
 
 	case EOF:
-	  fatal (_("unterminated %%guard clause"));
+	  fatal ("%s",
+		 _("unterminated %guard clause"));
 
 	default:
 	  putc (c, fguard);
@@ -1274,8 +1267,8 @@ copy_action (symbol_list *rule, int stack_offset)
 		  if (type_name)
 		    fprintf(faction, ".%s", type_name);
 		  if(!type_name && typed)
-		    warns(_("$$ of `%s' has no declared type"),
-			  rule->sym->tag);
+		    complain (_("$$ of `%s' has no declared type"),
+			      rule->sym->tag);
 		}
 	      else if (isdigit(c) || c == '-')
 		{
@@ -1290,12 +1283,12 @@ copy_action (symbol_list *rule, int stack_offset)
 		  if (type_name)
 		    fprintf(faction, ".%s", type_name);
 		  if(!type_name && typed)
-		    warnss(_("$%s of `%s' has no declared type"),
-				int_to_string(n), rule->sym->tag);
+		    complain (_("$%d of `%s' has no declared type"),
+			      n, rule->sym->tag);
 		  continue;
 		}
 	      else
-		warns(_("$%s is invalid"), printable_version(c));
+		complain (_("$%s is invalid"), printable_version (c));
 
 	      break;
 
@@ -1304,7 +1297,7 @@ copy_action (symbol_list *rule, int stack_offset)
 	      break;
 
 	    case EOF:
-	      fatal(_("unmatched `{'"));
+	      fatal (_("unmatched `{'"));
 
 	    default:
 	      putc(c, faction);
@@ -1390,14 +1383,14 @@ readgram (void)
 	      t = lex();
 	      if (t != COLON)
 		{
-		  warn(_("ill-formed rule: initial symbol not followed by colon"));
+		  complain (_("ill-formed rule: initial symbol not followed by colon"));
 		  unlex(t);
 		}
 	    }
 
 	  if (nrules == 0 && t == BAR)
 	    {
-	      warn(_("grammar starts with vertical bar"));
+	      complain (_("grammar starts with vertical bar"));
 	      lhs = symval;	/* BOGUS: use a random symval */
 	    }
 	  /* start a new rule and record its lhs.  */
@@ -1428,7 +1421,7 @@ readgram (void)
 	      nvars++;
 	    }
 	  else if (lhs->class == STOKEN)
-	    warns(_("rule given for %s, which is a token"), lhs->tag);
+	    complain (_("rule given for %s, which is a token"), lhs->tag);
 
 	  /* read the rhs of the rule.  */
 
@@ -1526,7 +1519,7 @@ readgram (void)
 
 	  if (t == PREC)
 	    {
-	      warn(_("two @prec's in a row"));
+	      complain (_("two @prec's in a row"));
 	      t = lex();
 	      crule->ruleprec = symval;
 	      t = lex();
@@ -1534,7 +1527,8 @@ readgram (void)
 	  if (t == GUARD)
 	    {
 	      if (! semantic_parser)
-		warn(_("%%guard present but %%semantic_parser not specified"));
+		complain ("%s",
+			  _("%guard present but %semantic_parser not specified"));
 
 	      copy_guard(crule, rulelength);
 	      t = lex();
@@ -1543,13 +1537,13 @@ readgram (void)
 	    {
 		/* This case never occurs -wjh */
 	      if (actionflag)
-		warn(_("two actions at end of one rule"));
+		complain (_("two actions at end of one rule"));
 	      copy_action(crule, rulelength);
 	      actionflag = 1;
 	      xactions++;	/* -wjh */
 	      t = lex();
 	    }
-	  /* If $$ is being set in default way, warn if any type
+	  /* If $$ is being set in default way, report if any type
 	     mismatch.  */
 	  else if (!xactions
 		   && first_rhs
@@ -1558,13 +1552,13 @@ readgram (void)
 	      if (lhs->type_name == 0
 		  || first_rhs->type_name == 0
 		  || strcmp(lhs->type_name,first_rhs->type_name))
-		warnss(_("type clash (`%s' `%s') on default action"),
-		       lhs->type_name ? lhs->type_name : "",
-		       first_rhs->type_name ? first_rhs->type_name : "");
+		complain (_("type clash (`%s' `%s') on default action"),
+			  lhs->type_name ? lhs->type_name : "",
+			     first_rhs->type_name ? first_rhs->type_name : "");
 	    }
 	  /* Warn if there is no default for $$ but we need one.  */
 	  else if (!xactions && !first_rhs && lhs->type_name != 0)
-	    warn(_("empty rule for typed nonterminal, and no action"));
+	    complain (_("empty rule for typed nonterminal, and no action"));
 	  if (t == SEMICOLON)
 	    t = lex();
 	}
@@ -1608,7 +1602,7 @@ readgram (void)
 
       else
 	{
-	  warns(_("invalid input: %s"), token_buffer);
+	  complain (_("invalid input: %s"), token_buffer);
 	  t = lex();
 	}
     }
@@ -1616,10 +1610,10 @@ readgram (void)
   /* grammar has been read.  Do some checking */
 
   if (nsyms > MAXSHORT)
-    fatals(_("too many symbols (tokens plus nonterminals); maximum %s"),
-	   int_to_string(MAXSHORT));
+    fatal (_("too many symbols (tokens plus nonterminals); maximum %d"),
+	   MAXSHORT);
   if (nrules == 0)
-    fatal(_("no rules in the input grammar"));
+    fatal (_("no rules in the input grammar"));
 
   if (typed == 0	/* JF put out same default YYSTYPE as YACC does */
       && !value_components_used)
@@ -1637,8 +1631,8 @@ readgram (void)
   for (bp = firstsymbol; bp; bp = bp->next)
     if (bp->class == SUNKNOWN)
       {
-	warns(_("symbol %s is used, but is not defined as a token and has no rules"),
-			bp->tag);
+	complain (_("symbol %s is used, but is not defined as a token and has no rules"),
+		  bp->tag);
 	bp->class = SNTERM;
 	bp->value = nvars++;
       }
@@ -1676,7 +1670,7 @@ get_type (void)
 
   if (t != TYPENAME)
     {
-      warn(_("ill-formed %type declaration"));
+      complain (_("ill-formed %type declaration"));
       return t;
     }
 
@@ -1700,7 +1694,7 @@ get_type (void)
 	  if (symval->type_name == NULL)
 	    symval->type_name = name;
 	  else if (strcmp(name, symval->type_name) != 0)
-	    warns(_("type redeclaration for %s"), symval->tag);
+	    complain (_("type redeclaration for %s"), symval->tag);
 
 	  break;
 
@@ -1755,8 +1749,8 @@ packsymbols (void)
 	    {
 	      if (bp->prec != 0 && bp->alias->prec != 0
 		  && bp->user_token_number == SALIAS)
-		warnss(_("conflicting precedences for %s and %s"),
-		       bp->tag, bp->alias->tag);
+		complain (_("conflicting precedences for %s and %s"),
+			  bp->tag, bp->alias->tag);
 	      if (bp->prec != 0)
 		bp->alias->prec = bp->prec;
 	      else
@@ -1765,15 +1759,15 @@ packsymbols (void)
 
 	  if (bp->assoc != bp->alias->assoc)
 	    {
-	    if (bp->assoc != 0 && bp->alias->assoc != 0
-		&& bp->user_token_number == SALIAS)
-	      warnss(_("conflicting assoc values for %s and %s"),
-		     bp->tag, bp->alias->tag);
-	    if (bp->assoc != 0)
-	      bp->alias->assoc = bp->assoc;
-	    else
-	      bp->assoc = bp->alias->assoc;
-	  }
+	      if (bp->assoc != 0 && bp->alias->assoc != 0
+		  && bp->user_token_number == SALIAS)
+		complain (_("conflicting assoc values for %s and %s"),
+			  bp->tag, bp->alias->tag);
+	      if (bp->assoc != 0)
+		bp->alias->assoc = bp->assoc;
+	      else
+		bp->assoc = bp->alias->assoc;
+	    }
 
 	  if (bp->user_token_number == SALIAS)
 	    continue;  /* do not do processing below for SALIASs */
@@ -1818,10 +1812,10 @@ packsymbols (void)
           if (bp->user_token_number == SALIAS)
 	    continue;
           if (token_translations[bp->user_token_number] != 2)
-	    warnsss(_("tokens %s and %s both assigned number %s"),
-		    tags[token_translations[bp->user_token_number]],
-		    bp->tag,
-		    int_to_string(bp->user_token_number));
+	    complain (_("tokens %s and %s both assigned number %d"),
+		      tags[token_translations[bp->user_token_number]],
+		  bp->tag,
+		  bp->user_token_number);
           token_translations[bp->user_token_number] = bp->value;
         }
     }
@@ -1832,9 +1826,9 @@ packsymbols (void)
     output_token_defines(ftable);
 
   if (startval->class == SUNKNOWN)
-    fatals(_("the start symbol %s is undefined"), startval->tag);
+    fatal (_("the start symbol %s is undefined"), startval->tag);
   else if (startval->class == STOKEN)
-    fatals(_("the start symbol %s is a token"), startval->tag);
+    fatal (_("the start symbol %s is a token"), startval->tag);
 
   start_symbol = startval->value;
 
@@ -1898,12 +1892,12 @@ output_token_defines (FILE *file)
       while ((c = *cp++) && c != '.');
       if (c != '\0')  continue;
 
-      fprintf(file, "#define\t%s\t%d\n", symbol,
-		((translations && ! rawtoknumflag)
-			? bp->user_token_number
-			: bp->value));
+      fprintf (file, "#define\t%s\t%d\n", symbol,
+	       ((translations && ! rawtoknumflag)
+		? bp->user_token_number
+		: bp->value));
       if (semantic_parser)
-        fprintf(file, "#define\tT%s\t%d\n", symbol, bp->value);
+        fprintf (file, "#define\tT%s\t%d\n", symbol, bp->value);
     }
 
   putc('\n', file);
