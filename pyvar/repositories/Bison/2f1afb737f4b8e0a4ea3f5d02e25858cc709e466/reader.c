@@ -51,7 +51,6 @@ typedef struct symbol_list
 int lineno;
 static symbol_list *grammar = NULL;
 static int start_flag = 0;
-static symbol_t *startval = NULL;
 
 /* Nonzero if components of semantic values are used, implying
    they must be unions.  */
@@ -63,11 +62,6 @@ static int typed = 0;
 /* Incremented for each %left, %right or %nonassoc seen */
 static int lastprec = 0;
 
-symbol_t *errtoken = NULL;
-symbol_t *undeftoken = NULL;
-symbol_t *eoftoken = NULL;
-symbol_t *axiom = NULL;
-
 static symbol_list *
 symbol_list_new (symbol_t *sym)
 {
@@ -81,169 +75,6 @@ symbol_list_new (symbol_t *sym)
   return res;
 }
 
-/*------------------------.
-| Operations on symbols.  |
-`------------------------*/
-
-
-/*-----------------------------------------------------------.
-| If THIS is not defined, report an error, and consider it a |
-| nonterminal.                                               |
-`-----------------------------------------------------------*/
-
-static bool
-symbol_check_defined (symbol_t *this)
-{
-  if (this->class == unknown_sym)
-    {
-      complain
-	(_("symbol %s is used, but is not defined as a token and has no rules"),
-	 this->tag);
-      this->class = nterm_sym;
-      this->number = nvars++;
-    }
-
-  return TRUE;
-}
-
-
-/*-------------------------------------------------------------------.
-| Assign a symbol number, and write the definition of the token name |
-| into FDEFINES.  Put in SYMBOLS.                                    |
-`-------------------------------------------------------------------*/
-
-static bool
-symbol_make_alias (symbol_t *symbol, char *typename)
-{
-  if (symval->alias)
-    warn (_("symbol `%s' used more than once as a literal string"),
-	  symval->tag);
-  else if (symbol->alias)
-    warn (_("symbol `%s' given more than one literal string"),
-	  symbol->tag);
-  else
-    {
-      symval->class = token_sym;
-      symval->type_name = typename;
-      symval->user_token_number = symbol->user_token_number;
-      symbol->user_token_number = USER_NUMBER_ALIAS;
-      symval->alias = symbol;
-      symbol->alias = symval;
-      /* symbol and symval combined are only one symbol */
-      nsyms--;
-      ntokens--;
-      assert (ntokens == symbol->number || ntokens == symval->number);
-      symbol->number = symval->number =
-	(symval->number < symbol->number) ? symval->number : symbol->number;
-    }
-
-  return TRUE;
-}
-
-/*---------------------------------------------------------.
-| Check that THIS, and its alias, have same precedence and |
-| associativity.                                           |
-`---------------------------------------------------------*/
-
-static bool
-symbol_check_alias_consistence (symbol_t *this)
-{
-  /* Check only those who _are_ the aliases. */
-  if (this->alias && this->user_token_number == USER_NUMBER_ALIAS)
-    {
-      if (this->prec != this->alias->prec)
-	{
-	  if (this->prec != 0 && this->alias->prec != 0)
-	    complain (_("conflicting precedences for %s and %s"),
-		      this->tag, this->alias->tag);
-	  if (this->prec != 0)
-	    this->alias->prec = this->prec;
-	  else
-	    this->prec = this->alias->prec;
-	}
-
-      if (this->assoc != this->alias->assoc)
-	{
-	  if (this->assoc != 0 && this->alias->assoc != 0)
-	    complain (_("conflicting assoc values for %s and %s"),
-		      this->tag, this->alias->tag);
-	  if (this->assoc != 0)
-	    this->alias->assoc = this->assoc;
-	  else
-	    this->assoc = this->alias->assoc;
-	}
-    }
-  return TRUE;
-}
-
-
-/*-------------------------------------------------------------------.
-| Assign a symbol number, and write the definition of the token name |
-| into FDEFINES.  Put in SYMBOLS.                                    |
-`-------------------------------------------------------------------*/
-
-static bool
-symbol_pack (symbol_t *this)
-{
-  if (this->class == nterm_sym)
-    {
-      this->number += ntokens;
-    }
-  else if (this->alias)
-    {
-      /* This symbol and its alias are a single token defn.
-	 Allocate a tokno, and assign to both check agreement of
-	 prec and assoc fields and make both the same */
-      if (this->number == NUMBER_UNDEFINED)
-	{
-	  if (this == eoftoken || this->alias == eoftoken)
-	    this->number = this->alias->number = 0;
-	  else
-	    {
-	      assert (this->alias->number != NUMBER_UNDEFINED);
-	      this->number = this->alias->number;
-	    }
-	}
-      /* Do not do processing below for USER_NUMBER_ALIASs.  */
-      if (this->user_token_number == USER_NUMBER_ALIAS)
-	return TRUE;
-    }
-  else /* this->class == token_sym */
-    {
-      assert (this->number != NUMBER_UNDEFINED);
-    }
-
-  symbols[this->number] = this;
-  return TRUE;
-}
-
-
-
-
-/*--------------------------------------------------.
-| Put THIS in TOKEN_TRANSLATIONS if it is a token.  |
-`--------------------------------------------------*/
-
-static bool
-symbol_translation (symbol_t *this)
-{
-  /* Non-terminal? */
-  if (this->class == token_sym
-      && this->user_token_number != USER_NUMBER_ALIAS)
-    {
-      /* A token which translation has already been set? */
-      if (token_translations[this->user_token_number] != undeftoken->number)
-	complain (_("tokens %s and %s both assigned number %d"),
-		  symbols[token_translations[this->user_token_number]]->tag,
-		  this->tag, this->user_token_number);
-
-      token_translations[this->user_token_number] = this->number;
-    }
-
-  return TRUE;
-}
-
-
 /*===================\
 | Low level lexing.  |
 \===================*/
@@ -699,7 +530,7 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 	}
       else if (token == tok_identifier && *symval->tag == '\"' && symbol)
 	{
-	  symbol_make_alias (symbol, typename);
+	  symbol_make_alias (symbol, symval, typename);
  	  symbol = NULL;
 	}
       else if (token == tok_identifier)
@@ -762,7 +593,7 @@ parse_start_decl (void)
   else
     {
       start_flag = 1;
-      startval = symval;
+      startsymbol = symval;
     }
 }
 
@@ -1401,7 +1232,7 @@ readgram (void)
 
 	    if (!start_flag)
 	      {
-		startval = lhs;
+		startsymbol = lhs;
 		start_flag = 1;
 	      }
 
@@ -1599,7 +1430,7 @@ readgram (void)
     fatal (_("no rules in the input grammar"));
 
   /* Report any undefined symbols and consider them nonterminals.  */
-  symbols_do (symbol_check_defined, NULL);
+  symbols_check_defined ();
 
   /* Insert the initial rule, which line is that of the first rule
      (not that of the start symbol):
@@ -1607,14 +1438,13 @@ readgram (void)
      axiom: %start EOF.  */
   p = symbol_list_new (axiom);
   p->line = grammar->line;
-  p->next = symbol_list_new (startval);
+  p->next = symbol_list_new (startsymbol);
   p->next->next = symbol_list_new (eoftoken);
   p->next->next->next = symbol_list_new (NULL);
   p->next->next->next->next = grammar;
   nrules += 1;
   nritems += 3;
   grammar = p;
-  startval = axiom;
 
   if (nsyms > SHRT_MAX)
     fatal (_("too many symbols (tokens plus nonterminals); maximum %d"),
@@ -1649,85 +1479,6 @@ read_additionnal_code (void)
 }
 
 
-/*------------------------------------------------------------------.
-| Set TOKEN_TRANSLATIONS.  Check that no two symbols share the same |
-| number.                                                           |
-`------------------------------------------------------------------*/
-
-static void
-token_translations_init (void)
-{
-  int num_256_available_p = TRUE;
-  int i;
-
-  /* Find the highest user token number, and whether 256, the POSIX
-     preferred user token number for the error token, is used.  */
-  max_user_token_number = 0;
-  for (i = 0; i < ntokens; ++i)
-    {
-      symbol_t *this = symbols[i];
-      if (this->user_token_number != USER_NUMBER_UNDEFINED)
-	{
-	  if (this->user_token_number > max_user_token_number)
-	    max_user_token_number = this->user_token_number;
-	  if (this->user_token_number == 256)
-	    num_256_available_p = FALSE;
-	}
-    }
-
-  /* If 256 is not used, assign it to error, to follow POSIX.  */
-  if (num_256_available_p
-      && errtoken->user_token_number == USER_NUMBER_UNDEFINED)
-    errtoken->user_token_number = 256;
-
-  /* Set the missing user numbers. */
-  if (max_user_token_number < 256)
-    max_user_token_number = 256;
-
-  for (i = 0; i < ntokens; ++i)
-    {
-      symbol_t *this = symbols[i];
-      if (this->user_token_number == USER_NUMBER_UNDEFINED)
-	this->user_token_number = ++max_user_token_number;
-      if (this->user_token_number > max_user_token_number)
-	max_user_token_number = this->user_token_number;
-    }
-
-  token_translations = XCALLOC (symbol_number_t, max_user_token_number + 1);
-
-  /* Initialize all entries for literal tokens to 2, the internal
-     token number for $undefined., which represents all invalid
-     inputs.  */
-  for (i = 0; i < max_user_token_number + 1; i++)
-    token_translations[i] = undeftoken->number;
-  symbols_do (symbol_translation, NULL);
-}
-
-
-/*----------------------------------------------------------------.
-| Assign symbol numbers, and write definition of token names into |
-| FDEFINES.  Set up vectors SYMBOL_TABLE, TAGS of symbols.        |
-`----------------------------------------------------------------*/
-
-static void
-packsymbols (void)
-{
-  symbols = XCALLOC (symbol_t *, nsyms);
-
-  symbols_do (symbol_check_alias_consistence, NULL);
-  symbols_do (symbol_pack, NULL);
-
-  token_translations_init ();
-
-  if (startval->class == unknown_sym)
-    fatal (_("the start symbol %s is undefined"), startval->tag);
-  else if (startval->class == token_sym)
-    fatal (_("the start symbol %s is a token"), startval->tag);
-
-  start_symbol = startval->number;
-}
-
-
 /*---------------------------------------------------------------.
 | Convert the rules into the representation using RRHS, RLHS and |
 | RITEM.                                                         |
@@ -1862,7 +1613,7 @@ reader (void)
 
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
-  packsymbols ();
+  symbols_pack ();
 
   /* Convert the grammar into the format described in gram.h.  */
   packgram ();
