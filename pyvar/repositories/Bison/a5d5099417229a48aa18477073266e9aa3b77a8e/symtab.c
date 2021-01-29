@@ -238,13 +238,13 @@ symbol_check_defined (symbol_t *this)
 `-------------------------------------------------------------------*/
 
 void
-symbol_make_alias (symbol_t *symbol, symbol_t *symval)
+symbol_make_alias (symbol_t *symbol, symbol_t *symval, location_t loc)
 {
   if (symval->alias)
-    warn (_("symbol `%s' used more than once as a literal string"),
+    warn_at (loc, _("symbol `%s' used more than once as a literal string"),
 	  symval->tag);
   else if (symbol->alias)
-    warn (_("symbol `%s' given more than one literal string"),
+    warn_at (loc, _("symbol `%s' given more than one literal string"),
 	  symbol->tag);
   else
     {
@@ -277,8 +277,9 @@ symbol_check_alias_consistence (symbol_t *this)
       if (this->prec != this->alias->prec)
 	{
 	  if (this->prec != 0 && this->alias->prec != 0)
-	    complain (_("conflicting precedences for %s and %s"),
-		      this->tag, this->alias->tag);
+	    complain_at (this->alias->location,
+			 _("conflicting precedences for %s and %s"),
+			 this->tag, this->alias->tag);
 	  if (this->prec != 0)
 	    this->alias->prec = this->prec;
 	  else
@@ -292,8 +293,9 @@ symbol_check_alias_consistence (symbol_t *this)
 	     not nice, fix this!  */
 	  if (this->assoc != right_assoc
 	      && this->alias->assoc != right_assoc)
-	    complain (_("conflicting associativities for %s and %s"),
-		      this->tag, this->alias->tag);
+	    complain_at (this->alias->location,
+			 _("conflicting associativities for %s and %s"),
+			 this->tag, this->alias->tag);
 	  if (this->assoc != 0)
 	    this->alias->assoc = this->assoc;
 	  else
@@ -360,9 +362,10 @@ symbol_translation (symbol_t *this)
     {
       /* A token which translation has already been set? */
       if (token_translations[this->user_token_number] != undeftoken->number)
-	complain (_("tokens %s and %s both assigned number %d"),
-		  symbols[token_translations[this->user_token_number]]->tag,
-		  this->tag, this->user_token_number);
+	complain_at (this->location,
+		     _("tokens %s and %s both assigned number %d"),
+		     symbols[token_translations[this->user_token_number]]->tag,
+		     this->tag, this->user_token_number);
 
       token_translations[this->user_token_number] = this->number;
     }
