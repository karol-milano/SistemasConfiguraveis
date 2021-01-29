@@ -66,41 +66,6 @@ symbol_new (const char *tag, location_t location)
 }
 
 
-/*-----------------------------------------------------------------.
-| Return the tag of this SYMBOL in a printable form.  Warning: use |
-| the first QUOTEARG slot: 0.                                      |
-`-----------------------------------------------------------------*/
-
-const char *
-symbol_tag_get (symbol_t *symbol)
-{
-  return quotearg_style (escape_quoting_style, symbol->tag);
-}
-
-
-/*------------------------------------------------------------.
-| Return the tag of this SYMBOL in a printable form.  Use the |
-| QUOTEARG slot number N.                                     |
-`------------------------------------------------------------*/
-
-const char *
-symbol_tag_get_n (symbol_t *symbol, int n)
-{
-  return quotearg_n_style (n, escape_quoting_style, symbol->tag);
-}
-
-
-/*-------------------------------.
-| Print the tag of this SYMBOL.  |
-`-------------------------------*/
-
-void
-symbol_tag_print (symbol_t *symbol, FILE *out)
-{
-  fputs (symbol_tag_get (symbol), out);
-}
-
-
 /*------------------------------------------------------------------.
 | Set the TYPE_NAME associated to SYMBOL.  Does nothing if passed 0 |
 | as TYPE_NAME.                                                     |
@@ -113,7 +78,7 @@ symbol_type_set (symbol_t *symbol, char *type_name, location_t location)
     {
       if (symbol->type_name)
 	complain_at (location,
-		     _("type redeclaration for %s"), symbol_tag_get (symbol));
+		     _("type redeclaration for %s"), symbol->tag);
       symbol->type_name = type_name;
     }
 }
@@ -131,7 +96,7 @@ symbol_destructor_set (symbol_t *symbol, char *destructor, location_t location)
       if (symbol->destructor)
 	complain_at (location,
 		     _("%s redeclaration for %s"),
-		     "%destructor", symbol_tag_get (symbol));
+		     "%destructor", symbol->tag);
       symbol->destructor = destructor;
       symbol->destructor_location = location;
     }
@@ -150,7 +115,7 @@ symbol_printer_set (symbol_t *symbol, char *printer, location_t location)
       if (symbol->printer)
 	complain_at (location,
 		     _("%s redeclaration for %s"),
-		     "%printer", symbol_tag_get (symbol));
+		     "%printer", symbol->tag);
       symbol->printer = printer;
       symbol->printer_location = location;
     }
@@ -171,7 +136,7 @@ symbol_precedence_set (symbol_t *symbol,
       if (symbol->prec != 0)
 	complain_at (location,
 		     _("redefining precedence of %s"),
-		     symbol_tag_get (symbol));
+		     symbol->tag);
       symbol->prec = prec;
       symbol->assoc = assoc;
     }
@@ -189,7 +154,7 @@ void
 symbol_class_set (symbol_t *symbol, symbol_class class, location_t location)
 {
   if (symbol->class != unknown_sym && symbol->class != class)
-    complain_at (location, _("symbol %s redefined"), symbol_tag_get (symbol));
+    complain_at (location, _("symbol %s redefined"), symbol->tag);
 
   if (class == nterm_sym && symbol->class != nterm_sym)
     symbol->number = nvars++;
@@ -213,7 +178,7 @@ symbol_user_token_number_set (symbol_t *symbol,
   if (symbol->user_token_number != USER_NUMBER_UNDEFINED
       && symbol->user_token_number != user_token_number)
     complain_at (location, _("redefining user token number of %s"),
-		 symbol_tag_get (symbol));
+		 symbol->tag);
 
   symbol->user_token_number = user_token_number;
   /* User defined EOF token? */
@@ -258,7 +223,7 @@ symbol_check_defined (symbol_t *this)
       complain_at
 	(this->location,
 	 _("symbol %s is used, but is not defined as a token and has no rules"),
-	 symbol_tag_get (this));
+	 this->tag);
       this->class = nterm_sym;
       this->number = nvars++;
     }
@@ -277,10 +242,10 @@ symbol_make_alias (symbol_t *symbol, symbol_t *symval)
 {
   if (symval->alias)
     warn (_("symbol `%s' used more than once as a literal string"),
-	  symbol_tag_get (symval));
+	  symval->tag);
   else if (symbol->alias)
     warn (_("symbol `%s' given more than one literal string"),
-	  symbol_tag_get (symbol));
+	  symbol->tag);
   else
     {
       symval->class = token_sym;
@@ -313,7 +278,7 @@ symbol_check_alias_consistence (symbol_t *this)
 	{
 	  if (this->prec != 0 && this->alias->prec != 0)
 	    complain (_("conflicting precedences for %s and %s"),
-		      symbol_tag_get (this), symbol_tag_get (this->alias));
+		      this->tag, this->alias->tag);
 	  if (this->prec != 0)
 	    this->alias->prec = this->prec;
 	  else
@@ -328,7 +293,7 @@ symbol_check_alias_consistence (symbol_t *this)
 	  if (this->assoc != right_assoc
 	      && this->alias->assoc != right_assoc)
 	    complain (_("conflicting associativities for %s and %s"),
-		      symbol_tag_get (this), symbol_tag_get (this->alias));
+		      this->tag, this->alias->tag);
 	  if (this->assoc != 0)
 	    this->alias->assoc = this->assoc;
 	  else
@@ -396,8 +361,8 @@ symbol_translation (symbol_t *this)
       /* A token which translation has already been set? */
       if (token_translations[this->user_token_number] != undeftoken->number)
 	complain (_("tokens %s and %s both assigned number %d"),
-		  symbol_tag_get (symbols[token_translations[this->user_token_number]]),
-		  symbol_tag_get (this), this->user_token_number);
+		  symbols[token_translations[this->user_token_number]]->tag,
+		  this->tag, this->user_token_number);
 
       token_translations[this->user_token_number] = this->number;
     }
@@ -454,6 +419,8 @@ symbol_get (const char *key, location_t location)
   symbol_t probe;
   symbol_t *entry;
 
+  /* Keep the symbol in a printable form.  */
+  key = quotearg_style (escape_quoting_style, key);
   (const char *) probe.tag = key;
   entry = hash_lookup (symbol_table, &probe);
 
@@ -598,9 +565,9 @@ symbols_pack (void)
   if (startsymbol->class == unknown_sym)
     fatal_at (startsymbol_location,
 	      _("the start symbol %s is undefined"),
-	      symbol_tag_get (startsymbol));
+	      startsymbol->tag);
   else if (startsymbol->class == token_sym)
     fatal_at (startsymbol_location,
 	      _("the start symbol %s is a token"),
-	      symbol_tag_get (startsymbol));
+	      startsymbol->tag);
 }
