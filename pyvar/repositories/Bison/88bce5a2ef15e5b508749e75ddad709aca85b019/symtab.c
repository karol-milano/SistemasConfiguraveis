@@ -32,8 +32,8 @@
 
 symbol_t *errtoken = NULL;
 symbol_t *undeftoken = NULL;
-symbol_t *eoftoken = NULL;
-symbol_t *axiom = NULL;
+symbol_t *endtoken = NULL;
+symbol_t *accept = NULL;
 symbol_t *startsymbol = NULL;
 location_t startsymbol_location;
 
@@ -181,11 +181,11 @@ symbol_user_token_number_set (symbol_t *symbol,
 		 symbol->tag);
 
   symbol->user_token_number = user_token_number;
-  /* User defined EOF token? */
+  /* User defined $end token? */
   if (user_token_number == 0)
     {
-      eoftoken = symbol;
-      eoftoken->number = 0;
+      endtoken = symbol;
+      endtoken->number = 0;
       /* It is always mapped to 0, so it was already counted in
 	 NTOKENS.  */
       --ntokens;
@@ -322,7 +322,7 @@ symbol_pack (symbol_t *this)
 	 prec and assoc fields and make both the same */
       if (this->number == NUMBER_UNDEFINED)
 	{
-	  if (this == eoftoken || this->alias == eoftoken)
+	  if (this == endtoken || this->alias == endtoken)
 	    this->number = this->alias->number = 0;
 	  else
 	    {
@@ -540,8 +540,8 @@ symbols_token_translations_init (void)
   token_translations = XCALLOC (symbol_number_t, max_user_token_number + 1);
 
   /* Initialize all entries for literal tokens to 2, the internal
-     token number for $undefined., which represents all invalid
-     inputs.  */
+     token number for $undefined, which represents all invalid inputs.
+     */
   for (i = 0; i < max_user_token_number + 1; i++)
     token_translations[i] = undeftoken->number;
   symbols_do (symbol_translation, NULL);
