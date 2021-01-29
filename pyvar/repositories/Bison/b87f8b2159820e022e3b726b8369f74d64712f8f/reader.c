@@ -126,7 +126,7 @@ symbol_make_alias (symbol_t *symbol, char *typename)
       symval->class = token_sym;
       symval->type_name = typename;
       symval->user_token_number = symbol->user_token_number;
-      symbol->user_token_number = SALIAS;
+      symbol->user_token_number = USER_NUMBER_ALIAS;
       symval->alias = symbol;
       symbol->alias = symval;
       /* symbol and symval combined are only one symbol */
@@ -149,7 +149,7 @@ static bool
 symbol_check_alias_consistence (symbol_t *this)
 {
   /* Check only those who _are_ the aliases. */
-  if (this->alias && this->user_token_number == SALIAS)
+  if (this->alias && this->user_token_number == USER_NUMBER_ALIAS)
     {
       if (this->prec != this->alias->prec)
 	{
@@ -204,8 +204,8 @@ symbol_pack (symbol_t *this)
 	      this->number = this->alias->number;
 	    }
 	}
-      /* Do not do processing below for SALIASs.  */
-      if (this->user_token_number == SALIAS)
+      /* Do not do processing below for USER_NUMBER_ALIASs.  */
+      if (this->user_token_number == USER_NUMBER_ALIAS)
 	return TRUE;
     }
   else /* this->class == token_sym */
@@ -229,7 +229,7 @@ symbol_translation (symbol_t *this)
 {
   /* Non-terminal? */
   if (this->class == token_sym
-      && this->user_token_number != SALIAS)
+      && this->user_token_number != USER_NUMBER_ALIAS)
     {
       /* A token which translation has already been set? */
       if (token_translations[this->user_token_number] != undeftoken->number)
@@ -998,10 +998,10 @@ parse_expect_decl (void)
 |                                                                    |
 | Two symbols are entered in the table, one for the token symbol and |
 | one for the literal.  Both are given the <type>, if any, from the  |
-| declaration.  The ->user_token_number of the first is SALIAS and   |
-| the ->user_token_number of the second is set to the number, if     |
-| any, from the declaration.  The two symbols are linked via         |
-| pointers in their ->alias fields.                                  |
+| declaration.  The ->user_token_number of the first is              |
+| USER_NUMBER_ALIAS and the ->user_token_number of the second is set |
+| to the number, if any, from the declaration.  The two symbols are  |
+| linked via pointers in their ->alias fields.                       |
 |                                                                    |
 | During OUTPUT_DEFINES_TABLE, the symbol is reported thereafter,    |
 | only the literal string is retained it is the literal string that  |
@@ -1014,7 +1014,7 @@ parse_thong_decl (void)
   token_t token;
   symbol_t *symbol;
   char *typename = 0;
-  int usrtoknum = SUNDEF;
+  int usrtoknum = USER_NUMBER_UNDEFINED;
 
   token = lex ();		/* fetch typename or first token */
   if (token == tok_typename)
@@ -1035,7 +1035,7 @@ parse_thong_decl (void)
     }
   symval->class = token_sym;
   symval->type_name = typename;
-  symval->user_token_number = SALIAS;
+  symval->user_token_number = USER_NUMBER_ALIAS;
   symbol = symval;
 
   token = lex ();		/* get number or literal string */
@@ -1666,7 +1666,7 @@ token_translations_init (void)
   for (i = 0; i < ntokens; ++i)
     {
       symbol_t *this = symbols[i];
-      if (this->user_token_number != SUNDEF)
+      if (this->user_token_number != USER_NUMBER_UNDEFINED)
 	{
 	  if (this->user_token_number > max_user_token_number)
 	    max_user_token_number = this->user_token_number;
@@ -1676,7 +1676,8 @@ token_translations_init (void)
     }
 
   /* If 256 is not used, assign it to error, to follow POSIX.  */
-  if (num_256_available_p && errtoken->user_token_number == SUNDEF)
+  if (num_256_available_p
+      && errtoken->user_token_number == USER_NUMBER_UNDEFINED)
     errtoken->user_token_number = 256;
 
   /* Set the missing user numbers. */
@@ -1686,7 +1687,7 @@ token_translations_init (void)
   for (i = 0; i < ntokens; ++i)
     {
       symbol_t *this = symbols[i];
-      if (this->user_token_number == SUNDEF)
+      if (this->user_token_number == USER_NUMBER_UNDEFINED)
 	this->user_token_number = ++max_user_token_number;
       if (this->user_token_number > max_user_token_number)
 	max_user_token_number = this->user_token_number;
