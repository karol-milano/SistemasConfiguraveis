@@ -34,28 +34,6 @@
 
 extern char *printable_version PARAMS ((int));
 
-#define	LTYPESTR	"\
-\n\
-#ifndef YYLTYPE\n\
-typedef\n\
-  struct yyltype\n\
-\
-    {\n\
-      int timestamp;\n\
-      int first_line;\n\
-      int first_column;\
-\n\
-      int last_line;\n\
-      int last_column;\n\
-      char *text;\n\
-   }\n\
-\
-  yyltype;\n\
-\n\
-#define YYLTYPE yyltype\n\
-#endif\n\
-\n"
-
 /* Number of slots allocated (but not necessarily used yet) in `rline'  */
 static int rline_allocated;
 
@@ -78,11 +56,14 @@ static bucket *startval;
    they must be unions.  */
 static int value_components_used;
 
-static int typed;		/* nonzero if %union has been seen.  */
+/* Nonzero if %union has been seen.  */
+static int typed;
 
-static int lastprec;		/* incremented for each %left, %right or %nonassoc seen */
+/* Incremented for each %left, %right or %nonassoc seen */
+static int lastprec;
 
-static int gensym_count;	/* incremented for each generated symbol */
+/* Incremented for each generated symbol */
+static int gensym_count;
 
 static bucket *errtoken;
 static bucket *undeftoken;
@@ -358,14 +339,14 @@ copy_definition (void)
 }
 
 
-/*-----------------------------------------------------------------.
-| Parse what comes after %token or %nterm.  For %token, what_is is |
-| STOKEN and what_is_not is SNTERM.  For %nterm, the arguments are |
-| reversed.                                                        |
-`-----------------------------------------------------------------*/
+/*-------------------------------------------------------------------.
+| Parse what comes after %token or %nterm.  For %token, WHAT_IS is   |
+| token_sym and WHAT_IS_NOT is nterm_sym.  For %nterm, the arguments |
+| are reversed.                                                      |
+`-------------------------------------------------------------------*/
 
 static void
-parse_token_decl (int what_is, int what_is_not)
+parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 {
   int token = 0;
   char *typename = 0;
@@ -398,7 +379,7 @@ parse_token_decl (int what_is, int what_is_not)
       else if (token == IDENTIFIER && *symval->tag == '\"' && symbol)
 	{
 	  translations = 1;
-	  symval->class = STOKEN;
+	  symval->class = token_sym;
 	  symval->type_name = typename;
 	  symval->user_token_number = symbol->user_token_number;
 	  symbol->user_token_number = SALIAS;
@@ -417,7 +398,7 @@ parse_token_decl (int what_is, int what_is_not)
 	  if (symbol->class == what_is_not)
 	    complain (_("symbol %s redefined"), symbol->tag);
 	  symbol->class = what_is;
-	  if (what_is == SNTERM && oldclass != SNTERM)
+	  if (what_is == nterm_sym && oldclass != nterm_sym)
 	    symbol->value = nvars++;
 
 	  if (typename)
@@ -436,7 +417,7 @@ parse_token_decl (int what_is, int what_is_not)
       else
 	{
 	  complain (_("`%s' is invalid in %s"),
-		    token_buffer, (what_is == STOKEN) ? "%token" : "%nterm");
+		    token_buffer, (what_is == token_sym) ? "%token" : "%nterm");
 	  skip_to_char ('%');
 	}
     }
@@ -444,7 +425,9 @@ parse_token_decl (int what_is, int what_is_not)
 }
 
 
-/* Parse what comes after %start */
+/*------------------------------.
+| Parse what comes after %start |
+`------------------------------*/
 
 static void
 parse_start_decl (void)
@@ -556,11 +539,13 @@ parse_type_decl (void)
 
 
 
-/* read in a %left, %right or %nonassoc declaration and record its information.  */
-/* assoc is either LEFT_ASSOC, RIGHT_ASSOC or NON_ASSOC.  */
+/*----------------------------------------------------------------.
+| Read in a %left, %right or %nonassoc declaration and record its |
+| information.                                                    |
+`----------------------------------------------------------------*/
 
 static void
-parse_assoc_decl (int assoc)
+parse_assoc_decl (associativity assoc)
 {
   int k;
   char *name = NULL;
@@ -597,9 +582,9 @@ parse_assoc_decl (int assoc)
 	    complain (_("redefining precedence of %s"), symval->tag);
 	  symval->prec = lastprec;
 	  symval->assoc = assoc;
-	  if (symval->class == SNTERM)
+	  if (symval->class == nterm_sym)
 	    complain (_("symbol %s redefined"), symval->tag);
-	  symval->class = STOKEN;
+	  symval->class = token_sym;
 	  if (name)
 	    {			/* record the type, if one is specified */
 	      if (symval->type_name == NULL)
@@ -639,9 +624,11 @@ token_buffer);
 
 
 
-/* copy the union declaration into fattrs (and fdefines),
-   where it is made into the
-   definition of YYSTYPE, the type of elements of the parser value stack.  */
+/*-------------------------------------------------------------------.
+| Copy the union declaration into fattrs (and fdefines), where it is |
+| made into the definition of YYSTYPE, the type of elements of the   |
+| parser value stack.                                                |
+`-------------------------------------------------------------------*/
 
 static void
 parse_union_decl (void)
@@ -710,8 +697,11 @@ parse_union_decl (void)
     }
 }
 
-/* parse the declaration %expect N which says to expect N
-   shift-reduce conflicts.  */
+
+/*-------------------------------------------------------.
+| Parse the declaration %expect N which says to expect N |
+| shift-reduce conflicts.                                |
+`-------------------------------------------------------*/
 
 static void
 parse_expect_decl (void)
@@ -789,7 +779,7 @@ parse_thong_decl (void)
       skip_to_char ('%');
       return;
     }
-  symval->class = STOKEN;
+  symval->class = token_sym;
   symval->type_name = typename;
   symval->user_token_number = SALIAS;
   symbol = symval;
@@ -812,7 +802,7 @@ parse_thong_decl (void)
       skip_to_char ('%');
       return;
     }
-  symval->class = STOKEN;
+  symval->class = token_sym;
   symval->type_name = typename;
   symval->user_token_number = usrtoknum;
 
@@ -822,6 +812,7 @@ parse_thong_decl (void)
   nsyms--;			/* symbol and symval combined are only one symbol */
 }
 
+
 /*----------------------------------------------------------------.
 | Read from finput until `%%' is seen.  Discard the `%%'.  Handle |
 | any `%' declarations, and copy the contents of any `%{ ... %}'  |
@@ -852,11 +843,11 @@ read_declarations (void)
 	      break;
 
 	    case TOKEN:
-	      parse_token_decl (STOKEN, SNTERM);
+	      parse_token_decl (token_sym, nterm_sym);
 	      break;
 
 	    case NTERM:
-	      parse_token_decl (SNTERM, STOKEN);
+	      parse_token_decl (nterm_sym, token_sym);
 	      break;
 
 	    case TYPE:
@@ -877,16 +868,17 @@ read_declarations (void)
 	    case THONG:
 	      parse_thong_decl ();
 	      break;
+
 	    case LEFT:
-	      parse_assoc_decl (LEFT_ASSOC);
+	      parse_assoc_decl (left_assoc);
 	      break;
 
 	    case RIGHT:
-	      parse_assoc_decl (RIGHT_ASSOC);
+	      parse_assoc_decl (right_assoc);
 	      break;
 
 	    case NONASSOC:
-	      parse_assoc_decl (NON_ASSOC);
+	      parse_assoc_decl (non_assoc);
 	      break;
 
 	    case SEMANTIC_PARSER:
@@ -1234,7 +1226,7 @@ gensym (void)
 
   sprintf (token_buffer, "@%d", ++gensym_count);
   sym = getsym (token_buffer);
-  sym->class = SNTERM;
+  sym->class = nterm_sym;
   sym->value = nvars++;
   return sym;
 }
@@ -1374,13 +1366,13 @@ readgram (void)
 
 	  /* mark the rule's lhs as a nonterminal if not already so.  */
 
-	  if (lhs->class == SUNKNOWN)
+	  if (lhs->class == unknown_sym)
 	    {
-	      lhs->class = SNTERM;
+	      lhs->class = nterm_sym;
 	      lhs->value = nvars;
 	      nvars++;
 	    }
-	  else if (lhs->class == STOKEN)
+	  else if (lhs->class == token_sym)
 	    complain (_("rule given for %s, which is a token"), lhs->tag);
 
 	  /* read the rhs of the rule.  */
@@ -1534,12 +1526,12 @@ readgram (void)
 */
       else if (t == TOKEN)
 	{
-	  parse_token_decl (STOKEN, SNTERM);
+	  parse_token_decl (token_sym, nterm_sym);
 	  t = lex ();
 	}
       else if (t == NTERM)
 	{
-	  parse_token_decl (SNTERM, STOKEN);
+	  parse_token_decl (nterm_sym, token_sym);
 	  t = lex ();
 	}
       else if (t == TYPE)
@@ -1592,12 +1584,12 @@ readgram (void)
   /* Report any undefined symbols and consider them nonterminals.  */
 
   for (bp = firstsymbol; bp; bp = bp->next)
-    if (bp->class == SUNKNOWN)
+    if (bp->class == unknown_sym)
       {
 	complain (_
 		  ("symbol %s is used, but is not defined as a token and has no rules"),
 bp->tag);
-	bp->class = SNTERM;
+	bp->class = nterm_sym;
 	bp->value = nvars++;
       }
 
@@ -1684,7 +1676,7 @@ packsymbols (void)
 
   for (bp = firstsymbol; bp; bp = bp->next)
     {
-      if (bp->class == SNTERM)
+      if (bp->class == nterm_sym)
 	{
 	  bp->value += ntokens;
 	}
@@ -1724,12 +1716,12 @@ packsymbols (void)
 	    continue;		/* do not do processing below for SALIASs */
 
 	}
-      else			/* bp->class == STOKEN */
+      else			/* bp->class == token_sym */
 	{
 	  bp->value = tokno++;
 	}
 
-      if (bp->class == STOKEN)
+      if (bp->class == token_sym)
 	{
 	  if (translations && !(bp->user_token_number))
 	    bp->user_token_number = ++last_user_token_number;
@@ -1775,9 +1767,9 @@ packsymbols (void)
   if (!noparserflag)
     output_token_defines (ftable);
 
-  if (startval->class == SUNKNOWN)
+  if (startval->class == unknown_sym)
     fatal (_("the start symbol %s is undefined"), startval->tag);
-  else if (startval->class == STOKEN)
+  else if (startval->class == token_sym)
     fatal (_("the start symbol %s is a token"), startval->tag);
 
   start_symbol = startval->value;
@@ -1849,7 +1841,7 @@ packgram (void)
 	  ritem[itemno++] = p->sym->value;
 	  /* A rule gets by default the precedence and associativity
 	     of the last token in it.  */
-	  if (p->sym->class == STOKEN)
+	  if (p->sym->class == token_sym)
 	    {
 	      rprec[ruleno] = p->sym->prec;
 	      rassoc[ruleno] = p->sym->assoc;
@@ -1925,12 +1917,12 @@ reader (void)
   tabinit ();
   /* Construct the error token */
   errtoken = getsym ("error");
-  errtoken->class = STOKEN;
+  errtoken->class = token_sym;
   errtoken->user_token_number = 256;	/* Value specified by POSIX.  */
   /* Construct a token that represents all undefined literal tokens.
      It is always token number 2.  */
   undeftoken = getsym ("$undefined.");
-  undeftoken->class = STOKEN;
+  undeftoken->class = token_sym;
   undeftoken->user_token_number = 2;
 
   /* Read the declaration section.  Copy %{ ... %} groups to FTABLE
@@ -1967,9 +1959,31 @@ reader (void)
   free_symtab ();
 }
 
+
 void
 reader_output_yylsp (FILE *f)
 {
   if (yylsp_needed)
-    fprintf (f, LTYPESTR);
+    fputs ("\
+\n\
+#ifndef YYLTYPE\n\
+typedef\n\
+  struct yyltype\n\
+\
+    {\n\
+      int timestamp;\n\
+      int first_line;\n\
+      int first_column;\
+\n\
+      int last_line;\n\
+      int last_column;\n\
+      char *text;\n\
+   }\n\
+\
+  yyltype;\n\
+\n\
+#define YYLTYPE yyltype\n\
+#endif\n\
+\n",
+	   f);
 }
