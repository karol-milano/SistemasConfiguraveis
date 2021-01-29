@@ -164,7 +164,7 @@ is_identifier (uniqstr s)
 uniqstr
 symbol_id_get (symbol const *sym)
 {
-  aver (sym->user_token_number != USER_NUMBER_ALIAS);
+  aver (sym->user_token_number != USER_NUMBER_HAS_STRING_ALIAS);
   if (sym->alias)
     sym = sym->alias;
   return is_identifier (sym->tag) ? sym->tag : 0;
@@ -402,7 +402,7 @@ symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
 {
   int *user_token_numberp;
 
-  if (sym->user_token_number != USER_NUMBER_ALIAS)
+  if (sym->user_token_number != USER_NUMBER_HAS_STRING_ALIAS)
     user_token_numberp = &sym->user_token_number;
   else
     user_token_numberp = &sym->alias->user_token_number;
@@ -451,29 +451,24 @@ symbol_check_defined_processor (void *sym, void *null ATTRIBUTE_UNUSED)
 }
 
 
-/*------------------------------------------------------------------.
-| Declare the new symbol SYM.  Make it an alias of SYMVAL, and type |
-| SYMVAL with SYM's type.                                           |
-`------------------------------------------------------------------*/
-
 void
-symbol_make_alias (symbol *sym, symbol *symval, location loc)
+symbol_make_alias (symbol *sym, symbol *str, location loc)
 {
-  if (symval->alias)
+  if (str->alias)
     warn_at (loc, _("symbol `%s' used more than once as a literal string"),
-	     symval->tag);
+	     str->tag);
   else if (sym->alias)
     warn_at (loc, _("symbol `%s' given more than one literal string"),
 	     sym->tag);
   else
     {
-      symval->class = token_sym;
-      symval->user_token_number = sym->user_token_number;
-      sym->user_token_number = USER_NUMBER_ALIAS;
-      symval->alias = sym;
-      sym->alias = symval;
-      symval->number = sym->number;
-      symbol_type_set (symval, sym->type_name, loc);
+      str->class = token_sym;
+      str->user_token_number = sym->user_token_number;
+      sym->user_token_number = USER_NUMBER_HAS_STRING_ALIAS;
+      str->alias = sym;
+      sym->alias = str;
+      str->number = sym->number;
+      symbol_type_set (str, sym->type_name, loc);
     }
 }
 
@@ -486,46 +481,47 @@ symbol_make_alias (symbol *sym, symbol *symval, location loc)
 static inline void
 symbol_check_alias_consistency (symbol *this)
 {
-  symbol *alias = this;
-  symbol *orig  = this->alias;
+  symbol *sym = this;
+  symbol *str  = this->alias;
 
-  /* Check only those that _are_ the aliases.  */
-  if (!(this->alias && this->user_token_number == USER_NUMBER_ALIAS))
+  /* Check only the symbol in the symbol-string pair.  */
+  if (!(this->alias
+        && this->user_token_number == USER_NUMBER_HAS_STRING_ALIAS))
     return;
 
-  if (orig->type_name != alias->type_name)
+  if (str->type_name != sym->type_name)
     {
-      if (orig->type_name)
-	symbol_type_set (alias, orig->type_name, orig->type_location);
+      if (str->type_name)
+	symbol_type_set (sym, str->type_name, str->type_location);
       else
-	symbol_type_set (orig, alias->type_name, alias->type_location);
+	symbol_type_set (str, sym->type_name, sym->type_location);
     }
 
 
-  if (orig->destructor.code || alias->destructor.code)
+  if (str->destructor.code || sym->destructor.code)
     {
-      if (orig->destructor.code)
-	symbol_destructor_set (alias, &orig->destructor);
+      if (str->destructor.code)
+	symbol_destructor_set (sym, &str->destructor);
       else
-	symbol_destructor_set (orig, &alias->destructor);
+	symbol_destructor_set (str, &sym->destructor);
     }
 
-  if (orig->printer.code || alias->printer.code)
+  if (str->printer.code || sym->printer.code)
     {
-      if (orig->printer.code)
-	symbol_printer_set (alias, &orig->printer);
+      if (str->printer.code)
+	symbol_printer_set (sym, &str->printer);
       else
-	symbol_printer_set (orig, &alias->printer);
+	symbol_printer_set (str, &sym->printer);
     }
 
-  if (alias->prec || orig->prec)
+  if (sym->prec || str->prec)
     {
-      if (orig->prec)
-	symbol_precedence_set (alias, orig->prec, orig->assoc,
-			       orig->prec_location);
+      if (str->prec)
+	symbol_precedence_set (sym, str->prec, str->assoc,
+			       str->prec_location);
       else
-	symbol_precedence_set (orig, alias->prec, alias->assoc,
-			       alias->prec_location);
+	symbol_precedence_set (str, sym->prec, sym->assoc,
+			       sym->prec_location);
     }
 }
 
@@ -565,8 +561,8 @@ symbol_pack (symbol *this)
 	      this->number = this->alias->number;
 	    }
 	}
-      /* Do not do processing below for USER_NUMBER_ALIASes.  */
-      if (this->user_token_number == USER_NUMBER_ALIAS)
+      /* Do not do processing below for USER_NUMBER_HAS_STRING_ALIASes.  */
+      if (this->user_token_number == USER_NUMBER_HAS_STRING_ALIAS)
 	return true;
     }
   else /* this->class == token_sym */
@@ -613,7 +609,7 @@ symbol_translation (symbol *this)
 {
   /* Non-terminal? */
   if (this->class == token_sym
-      && this->user_token_number != USER_NUMBER_ALIAS)
+      && this->user_token_number != USER_NUMBER_HAS_STRING_ALIAS)
     {
       /* A token which translation has already been set? */
       if (token_translations[this->user_token_number] != undeftoken->number)
