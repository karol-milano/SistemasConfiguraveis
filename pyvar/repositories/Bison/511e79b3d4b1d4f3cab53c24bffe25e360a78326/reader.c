@@ -486,18 +486,18 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 	fatal (_("Premature EOF after %s"), token_buffer);
 
       token = lex ();
-      if (token == COMMA)
+      if (token == tok_comma)
 	{
 	  symbol = NULL;
 	  continue;
 	}
-      if (token == TYPENAME)
+      if (token == tok_typename)
 	{
 	  typename = xstrdup (token_buffer);
 	  value_components_used = 1;
 	  symbol = NULL;
 	}
-      else if (token == IDENTIFIER && *symval->tag == '\"' && symbol)
+      else if (token == tok_identifier && *symval->tag == '\"' && symbol)
 	{
 	  if (symval->alias)
 	    warn (_("symbol `%s' used more than once as a literal string"),
@@ -519,7 +519,7 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 	  translations = 1;
  	  symbol = NULL;
 	}
-      else if (token == IDENTIFIER)
+      else if (token == tok_identifier)
 	{
 	  int oldclass = symval->class;
 	  symbol = symval;
@@ -538,7 +538,7 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 		complain (_("type redeclaration for %s"), symbol->tag);
 	    }
 	}
-      else if (symbol && token == NUMBER)
+      else if (symbol && token == tok_number)
 	{
 	  symbol->user_token_number = numval;
 	  translations = 1;
@@ -563,7 +563,7 @@ parse_start_decl (void)
 {
   if (start_flag)
     complain (_("multiple %s declarations"), "%start");
-  if (lex () != IDENTIFIER)
+  if (lex () != tok_identifier)
     complain (_("invalid %s declaration"), "%start");
   else
     {
@@ -582,7 +582,7 @@ parse_type_decl (void)
 {
   char *name;
 
-  if (lex () != TYPENAME)
+  if (lex () != tok_typename)
     {
       complain ("%s", _("%type declaration has no <typename>"));
       skip_to_char ('%');
@@ -606,11 +606,11 @@ parse_type_decl (void)
       switch (t)
 	{
 
-	case COMMA:
-	case SEMICOLON:
+	case tok_comma:
+	case tok_semicolon:
 	  break;
 
-	case IDENTIFIER:
+	case tok_identifier:
 	  if (symval->type_name == NULL)
 	    symval->type_name = name;
 	  else if (strcmp (name, symval->type_name) != 0)
@@ -655,14 +655,14 @@ parse_assoc_decl (associativity assoc)
 
       switch (t)
 	{
-	case TYPENAME:
+	case tok_typename:
 	  name = xstrdup (token_buffer);
 	  break;
 
-	case COMMA:
+	case tok_comma:
 	  break;
 
-	case IDENTIFIER:
+	case tok_identifier:
 	  if (symval->prec != 0)
 	    complain (_("redefining precedence of %s"), symval->tag);
 	  symval->prec = lastprec;
@@ -679,8 +679,8 @@ parse_assoc_decl (associativity assoc)
 	    }
 	  break;
 
-	case NUMBER:
-	  if (prev == IDENTIFIER)
+	case tok_number:
+	  if (prev == tok_identifier)
 	    {
 	      symval->user_token_number = numval;
 	      translations = 1;
@@ -694,7 +694,7 @@ token_buffer);
 	    }
 	  break;
 
-	case SEMICOLON:
+	case tok_semicolon:
 	  return;
 
 	default:
@@ -828,7 +828,7 @@ parse_thong_decl (void)
 
   translations = 1;
   token = lex ();		/* fetch typename or first token */
-  if (token == TYPENAME)
+  if (token == tok_typename)
     {
       typename = xstrdup (token_buffer);
       value_components_used = 1;
@@ -837,7 +837,7 @@ parse_thong_decl (void)
 
   /* process first token */
 
-  if (token != IDENTIFIER)
+  if (token != tok_identifier)
     {
       complain (_("unrecognized item %s, expected an identifier"),
 		token_buffer);
@@ -851,7 +851,7 @@ parse_thong_decl (void)
 
   token = lex ();		/* get number or literal string */
 
-  if (token == NUMBER)
+  if (token == tok_number)
     {
       usrtoknum = numval;
       token = lex ();		/* okay, did number, now get literal */
@@ -861,7 +861,7 @@ parse_thong_decl (void)
 
   /* process literal string token */
 
-  if (token != IDENTIFIER || *symval->tag != '\"')
+  if (token != tok_identifier || *symval->tag != '\"')
     {
       complain (_("expected string constant instead of %s"), token_buffer);
       skip_to_char ('%');
@@ -901,54 +901,54 @@ read_declarations (void)
 
 	  switch (tok)
 	    {
-	    case TWO_PERCENTS:
+	    case tok_two_percents:
 	      return;
 
-	    case PERCENT_LEFT_CURLY:
+	    case tok_percent_left_curly:
 	      copy_definition ();
 	      break;
 
-	    case TOKEN:
+	    case tok_token:
 	      parse_token_decl (token_sym, nterm_sym);
 	      break;
 
-	    case NTERM:
+	    case tok_nterm:
 	      parse_token_decl (nterm_sym, token_sym);
 	      break;
 
-	    case TYPE:
+	    case tok_type:
 	      parse_type_decl ();
 	      break;
 
-	    case START:
+	    case tok_start:
 	      parse_start_decl ();
 	      break;
 
-	    case UNION:
+	    case tok_union:
 	      parse_union_decl ();
 	      break;
 
-	    case EXPECT:
+	    case tok_expect:
 	      parse_expect_decl ();
 	      break;
 
-	    case THONG:
+	    case tok_thong:
 	      parse_thong_decl ();
 	      break;
 
-	    case LEFT:
+	    case tok_left:
 	      parse_assoc_decl (left_assoc);
 	      break;
 
-	    case RIGHT:
+	    case tok_right:
 	      parse_assoc_decl (right_assoc);
 	      break;
 
-	    case NONASSOC:
+	    case tok_nonassoc:
 	      parse_assoc_decl (non_assoc);
 	      break;
 
-	    case NOOP:
+	    case tok_noop:
 	      break;
 
 	    default:
@@ -1203,7 +1203,7 @@ get_type (void)
 
   t = lex ();
 
-  if (t != TYPENAME)
+  if (t != tok_typename)
     {
       complain (_("invalid %s declaration"), "%type");
       return t;
@@ -1217,13 +1217,13 @@ get_type (void)
 
       switch (t)
 	{
-	case SEMICOLON:
+	case tok_semicolon:
 	  return lex ();
 
-	case COMMA:
+	case tok_comma:
 	  break;
 
-	case IDENTIFIER:
+	case tok_identifier:
 	  if (symval->type_name == NULL)
 	    symval->type_name = name;
 	  else if (strcmp (name, symval->type_name) != 0)
@@ -1269,9 +1269,9 @@ readgram (void)
 
   t = lex ();
 
-  while (t != TWO_PERCENTS && t != ENDFILE)
+  while (t != tok_two_percents && t != tok_eof)
     {
-      if (t == IDENTIFIER || t == BAR)
+      if (t == tok_identifier || t == tok_bar)
 	{
 	  int action_flag = 0;
 	  /* Number of symbols in rhs of this rule so far */
@@ -1279,7 +1279,7 @@ readgram (void)
 	  int xactions = 0;	/* JF for error checking */
 	  bucket *first_rhs = 0;
 
-	  if (t == IDENTIFIER)
+	  if (t == tok_identifier)
 	    {
 	      lhs = symval;
 
@@ -1290,14 +1290,14 @@ readgram (void)
 		}
 
 	      t = lex ();
-	      if (t != COLON)
+	      if (t != tok_colon)
 		{
 		  complain (_("ill-formed rule: initial symbol not followed by colon"));
 		  unlex (t);
 		}
 	    }
 
-	  if (nrules == 0 && t == BAR)
+	  if (nrules == 0 && t == tok_bar)
 	    {
 	      complain (_("grammar starts with vertical bar"));
 	      lhs = symval;	/* BOGUS: use a random symval */
@@ -1337,19 +1337,19 @@ readgram (void)
 	  for (;;)
 	    {
 	      t = lex ();
-	      if (t == PREC)
+	      if (t == tok_prec)
 		{
 		  t = lex ();
 		  crule->ruleprec = symval;
 		  t = lex ();
 		}
 
-	      if (!(t == IDENTIFIER || t == LEFT_CURLY))
+	      if (!(t == tok_identifier || t == tok_left_curly))
 		break;
 
 	      /* If next token is an identifier, see if a colon follows it.
 	         If one does, exit this rule now.  */
-	      if (t == IDENTIFIER)
+	      if (t == tok_identifier)
 		{
 		  bucket *ssave;
 		  int t1;
@@ -1358,7 +1358,7 @@ readgram (void)
 		  t1 = lex ();
 		  unlex (t1);
 		  symval = ssave;
-		  if (t1 == COLON)
+		  if (t1 == tok_colon)
 		    break;
 
 		  if (!first_rhs)	/* JF */
@@ -1408,7 +1408,7 @@ readgram (void)
 		  action_flag = 0;
 		}
 
-	      if (t == IDENTIFIER)
+	      if (t == tok_identifier)
 		{
 		  nitems++;
 		  p = XCALLOC (symbol_list, 1);
@@ -1430,14 +1430,14 @@ readgram (void)
 	  p1->next = p;
 	  p1 = p;
 
-	  if (t == PREC)
+	  if (t == tok_prec)
 	    {
 	      complain (_("two @prec's in a row"));
 	      t = lex ();
 	      crule->ruleprec = symval;
 	      t = lex ();
 	    }
-	  if (t == GUARD)
+	  if (t == tok_guard)
 	    {
 	      if (!semantic_parser)
 		complain (_("%%guard present but %%semantic_parser not specified"));
@@ -1445,7 +1445,7 @@ readgram (void)
 	      copy_guard (crule, rulelength);
 	      t = lex ();
 	    }
-	  else if (t == LEFT_CURLY)
+	  else if (t == tok_left_curly)
 	    {
 	      /* This case never occurs -wjh */
 	      if (action_flag)
@@ -1470,7 +1470,7 @@ readgram (void)
 	  /* Warn if there is no default for $$ but we need one.  */
 	  else if (!xactions && !first_rhs && lhs->type_name != 0)
 	    complain (_("empty rule for typed nonterminal, and no action"));
-	  if (t == SEMICOLON)
+	  if (t == tok_semicolon)
 	    t = lex ();
 	}
 #if 0
@@ -1480,31 +1480,31 @@ readgram (void)
 	b) most of them scan forward until finding a next %
 		thus they may swallow lots of intervening rules
 */
-      else if (t == TOKEN)
+      else if (t == tok_token)
 	{
 	  parse_token_decl (token_sym, nterm_sym);
 	  t = lex ();
 	}
-      else if (t == NTERM)
+      else if (t == tok_nterm)
 	{
 	  parse_token_decl (nterm_sym, token_sym);
 	  t = lex ();
 	}
-      else if (t == TYPE)
+      else if (t == tok_type)
 	{
 	  t = get_type ();
 	}
-      else if (t == UNION)
+      else if (t == tok_union)
 	{
 	  parse_union_decl ();
 	  t = lex ();
 	}
-      else if (t == EXPECT)
+      else if (t == tok_expect)
 	{
 	  parse_expect_decl ();
 	  t = lex ();
 	}
-      else if (t == START)
+      else if (t == tok_start)
 	{
 	  parse_start_decl ();
 	  t = lex ();
