@@ -54,36 +54,46 @@ symbol_new (const char *tag)
   res->class = unknown_sym;
 
   nsyms++;
-
   return res;
 }
 
 
-/*-----------------------------------------.
-| Set the TYPE_NAME associated to SYMBOL.  |
-`-----------------------------------------*/
+/*------------------------------------------------------------------.
+| Set the TYPE_NAME associated to SYMBOL.  Does nothing if passed 0 |
+| as TYPE_NAME.                                                     |
+`------------------------------------------------------------------*/
 
 void
 symbol_type_set (symbol_t *symbol, char *type_name)
 {
-  if (symbol->type_name)
-    complain (_("type redeclaration for %s"), symbol->tag);
-  symbol->type_name = type_name;
+  if (type_name)
+    {
+      if (symbol->type_name)
+	complain (_("type redeclaration for %s"), symbol->tag);
+      symbol->type_name = type_name;
+    }
 }
 
 
-/*------------------------------------------.
-| Set the PRECEDENCE associated to SYMBOL.  |
-`------------------------------------------*/
+/*------------------------------------------------------------------.
+| Set the PRECEDENCE associated to SYMBOL.  Does nothing if invoked |
+| with UNDEF_ASSOC as ASSOC.                                        |
+`------------------------------------------------------------------*/
 
 void
 symbol_precedence_set (symbol_t *symbol,
 		       int prec, associativity assoc)
 {
-  if (symbol->prec != 0)
-    complain (_("redefining precedence of %s"), symbol->tag);
-  symbol->prec = prec;
-  symbol->assoc = assoc;
+  if (assoc != undef_assoc)
+    {
+      if (symbol->prec != 0)
+	complain (_("redefining precedence of %s"), symbol->tag);
+      symbol->prec = prec;
+      symbol->assoc = assoc;
+    }
+
+  /* Only terminals have a precedence. */
+  symbol_class_set (symbol, token_sym);
 }
 
 
@@ -176,7 +186,7 @@ symbol_check_defined (symbol_t *this)
 `-------------------------------------------------------------------*/
 
 void
-symbol_make_alias (symbol_t *symbol, symbol_t *symval, char *typename)
+symbol_make_alias (symbol_t *symbol, symbol_t *symval)
 {
   if (symval->alias)
     warn (_("symbol `%s' used more than once as a literal string"),
@@ -187,7 +197,6 @@ symbol_make_alias (symbol_t *symbol, symbol_t *symval, char *typename)
   else
     {
       symval->class = token_sym;
-      symval->type_name = typename;
       symval->user_token_number = symbol->user_token_number;
       symbol->user_token_number = USER_NUMBER_ALIAS;
       symval->alias = symbol;
@@ -226,8 +235,12 @@ symbol_check_alias_consistence (symbol_t *this)
 
       if (this->assoc != this->alias->assoc)
 	{
-	  if (this->assoc != 0 && this->alias->assoc != 0)
-	    complain (_("conflicting assoc values for %s and %s"),
+	  /* FIXME: For some reason (probably the S/R => keep the S),
+	     the right assoc is chosen has the ``not set''.  This is
+	     not nice, fix this!  */
+	  if (this->assoc != right_assoc
+	      && this->alias->assoc != right_assoc)
+	    complain (_("conflicting associativities for %s and %s"),
 		      this->tag, this->alias->tag);
 	  if (this->assoc != 0)
 	    this->alias->assoc = this->assoc;
