@@ -55,7 +55,7 @@ symbol_new (const char *tag, location_t location)
 
   res->number = NUMBER_UNDEFINED;
   res->prec = 0;
-  res->assoc = right_assoc;
+  res->assoc = undef_assoc;
   res->user_token_number = USER_NUMBER_UNDEFINED;
 
   res->alias = NULL;
@@ -129,7 +129,7 @@ symbol_printer_set (symbol_t *symbol, char *printer, location_t location)
 
 void
 symbol_precedence_set (symbol_t *symbol,
-		       int prec, associativity assoc, location_t location)
+		       int prec, assoc_t assoc, location_t location)
 {
   if (assoc != undef_assoc)
     {
@@ -288,15 +288,12 @@ symbol_check_alias_consistence (symbol_t *this)
 
       if (this->assoc != this->alias->assoc)
 	{
-	  /* FIXME: For some reason (probably the S/R => keep the S),
-	     the right assoc is chosen has the ``not set''.  This is
-	     not nice, fix this!  */
-	  if (this->assoc != right_assoc
-	      && this->alias->assoc != right_assoc)
+	  if (this->assoc != undef_assoc && this->alias->assoc != undef_assoc)
 	    complain_at (this->alias->location,
-			 _("conflicting associativities for %s and %s"),
-			 this->tag, this->alias->tag);
-	  if (this->assoc != 0)
+			 _("conflicting associativities for %s (%s) and %s (%s)"),
+			 this->tag, assoc_to_string (this->assoc),
+			 this->alias->tag, assoc_to_string (this->alias->assoc));
+	  if (this->assoc != undef_assoc)
 	    this->alias->assoc = this->assoc;
 	  else
 	    this->assoc = this->alias->assoc;
