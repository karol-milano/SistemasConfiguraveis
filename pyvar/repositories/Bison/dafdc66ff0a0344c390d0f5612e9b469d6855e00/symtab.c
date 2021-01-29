@@ -108,7 +108,7 @@ symbol_type_set (symbol_t *symbol, location_t location, char *type_name)
     {
       if (symbol->type_name)
 	complain_at (location,
-		     _("type redeclaration for %s"), symbol->tag);
+		     _("type redeclaration for %s"), symbol_tag_get (symbol));
       symbol->type_name = type_name;
     }
 }
@@ -127,7 +127,8 @@ symbol_precedence_set (symbol_t *symbol, location_t location,
     {
       if (symbol->prec != 0)
 	complain_at (location,
-		     _("redefining precedence of %s"), symbol->tag);
+		     _("redefining precedence of %s"),
+		     symbol_tag_get (symbol));
       symbol->prec = prec;
       symbol->assoc = assoc;
     }
@@ -145,7 +146,7 @@ void
 symbol_class_set (symbol_t *symbol, symbol_class class)
 {
   if (symbol->class != unknown_sym && symbol->class != class)
-    complain (_("symbol %s redefined"), symbol->tag);
+    complain (_("symbol %s redefined"), symbol_tag_get (symbol));
 
   if (class == nterm_sym && symbol->class != nterm_sym)
     symbol->number = nvars++;
@@ -167,7 +168,8 @@ symbol_user_token_number_set (symbol_t *symbol, int user_token_number)
 
   if (symbol->user_token_number != USER_NUMBER_UNDEFINED
       && symbol->user_token_number != user_token_number)
-    complain (_("redefining user token number of %s"), symbol->tag);
+    complain (_("redefining user token number of %s"),
+	      symbol_tag_get (symbol));
 
   symbol->user_token_number = user_token_number;
   /* User defined EOF token? */
@@ -212,7 +214,7 @@ symbol_check_defined (symbol_t *this)
       complain_at
 	(this->location,
 	 _("symbol %s is used, but is not defined as a token and has no rules"),
-	 this->tag);
+	 symbol_tag_get (this));
       this->class = nterm_sym;
       this->number = nvars++;
     }
@@ -231,10 +233,10 @@ symbol_make_alias (symbol_t *symbol, symbol_t *symval)
 {
   if (symval->alias)
     warn (_("symbol `%s' used more than once as a literal string"),
-	  symval->tag);
+	  symbol_tag_get (symval));
   else if (symbol->alias)
     warn (_("symbol `%s' given more than one literal string"),
-	  symbol->tag);
+	  symbol_tag_get (symbol));
   else
     {
       symval->class = token_sym;
@@ -267,7 +269,7 @@ symbol_check_alias_consistence (symbol_t *this)
 	{
 	  if (this->prec != 0 && this->alias->prec != 0)
 	    complain (_("conflicting precedences for %s and %s"),
-		      this->tag, this->alias->tag);
+		      symbol_tag_get (this), symbol_tag_get (this->alias));
 	  if (this->prec != 0)
 	    this->alias->prec = this->prec;
 	  else
@@ -282,7 +284,7 @@ symbol_check_alias_consistence (symbol_t *this)
 	  if (this->assoc != right_assoc
 	      && this->alias->assoc != right_assoc)
 	    complain (_("conflicting associativities for %s and %s"),
-		      this->tag, this->alias->tag);
+		      symbol_tag_get (this), symbol_tag_get (this->alias));
 	  if (this->assoc != 0)
 	    this->alias->assoc = this->assoc;
 	  else
@@ -350,8 +352,8 @@ symbol_translation (symbol_t *this)
       /* A token which translation has already been set? */
       if (token_translations[this->user_token_number] != undeftoken->number)
 	complain (_("tokens %s and %s both assigned number %d"),
-		  symbols[token_translations[this->user_token_number]]->tag,
-		  this->tag, this->user_token_number);
+		  symbol_tag_get (symbols[token_translations[this->user_token_number]]),
+		  symbol_tag_get (this), this->user_token_number);
 
       token_translations[this->user_token_number] = this->number;
     }
@@ -529,8 +531,10 @@ symbols_pack (void)
 
   if (startsymbol->class == unknown_sym)
     fatal_at (startsymbol_location,
-	      _("the start symbol %s is undefined"), startsymbol->tag);
+	      _("the start symbol %s is undefined"),
+	      symbol_tag_get (startsymbol));
   else if (startsymbol->class == token_sym)
     fatal_at (startsymbol_location,
-	      _("the start symbol %s is a token"), startsymbol->tag);
+	      _("the start symbol %s is a token"),
+	      symbol_tag_get (startsymbol));
 }
