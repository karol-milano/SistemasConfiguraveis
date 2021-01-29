@@ -90,7 +90,7 @@ symbol_new (uniqstr tag, location loc)
 
   if (nsyms == SYMBOL_NUMBER_MAXIMUM)
     fatal (_("too many symbols in input grammar (limit is %d)"),
-	   SYMBOL_NUMBER_MAXIMUM);
+           SYMBOL_NUMBER_MAXIMUM);
   nsyms++;
   return res;
 }
@@ -117,8 +117,8 @@ semantic_type_new (uniqstr tag)
 | Print a symbol.  |
 `-----------------*/
 
-#define SYMBOL_ATTR_PRINT(Attr)				\
-  if (s->Attr)						\
+#define SYMBOL_ATTR_PRINT(Attr)                         \
+  if (s->Attr)                                          \
     fprintf (f, " %s { %s }", #Attr, s->Attr)
 
 #define SYMBOL_CODE_PRINT(Attr)                         \
@@ -211,7 +211,7 @@ symbol_type_set (symbol *sym, uniqstr type_name, location loc)
   if (type_name)
     {
       if (sym->type_name)
-	symbol_redeclaration (sym, "%type", sym->type_location, loc);
+        symbol_redeclaration (sym, "%type", sym->type_location, loc);
       uniqstr_assert (type_name);
       sym->type_name = type_name;
       sym->type_location = loc;
@@ -340,7 +340,7 @@ symbol_precedence_set (symbol *sym, int prec, assoc a, location loc)
   if (a != undef_assoc)
     {
       if (sym->prec != 0)
-	symbol_redeclaration (sym, assoc_to_string (a), sym->prec_location,
+        symbol_redeclaration (sym, assoc_to_string (a), sym->prec_location,
                               loc);
       sym->prec = prec;
       sym->assoc = a;
@@ -375,7 +375,7 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
   if (declaring)
     {
       if (sym->declared)
-	warn_at (loc, _("symbol %s redeclared"), sym->tag);
+        warn_at (loc, _("symbol %s redeclared"), sym->tag);
       sym->declared = true;
     }
 }
@@ -404,7 +404,7 @@ symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
     {
       endtoken = sym;
       /* It is always mapped to 0, so it was already counted in
-	 NTOKENS.  */
+         NTOKENS.  */
       if (endtoken->number != NUMBER_UNDEFINED)
         --ntokens;
       endtoken->number = 0;
@@ -423,9 +423,9 @@ symbol_check_defined (symbol *sym)
   if (sym->class == unknown_sym)
     {
       complain_at
-	(sym->location,
-	 _("symbol %s is used, but is not defined as a token and has no rules"),
-	 sym->tag);
+        (sym->location,
+         _("symbol %s is used, but is not defined as a token and has no rules"),
+         sym->tag);
       sym->class = nterm_sym;
       sym->number = nvars++;
     }
@@ -445,10 +445,10 @@ symbol_make_alias (symbol *sym, symbol *str, location loc)
 {
   if (str->alias)
     warn_at (loc, _("symbol `%s' used more than once as a literal string"),
-	     str->tag);
+             str->tag);
   else if (sym->alias)
     warn_at (loc, _("symbol `%s' given more than one literal string"),
-	     sym->tag);
+             sym->tag);
   else
     {
       str->class = token_sym;
@@ -481,42 +481,42 @@ symbol_check_alias_consistency (symbol *this)
   if (str->type_name != sym->type_name)
     {
       if (str->type_name)
-	symbol_type_set (sym, str->type_name, str->type_location);
+        symbol_type_set (sym, str->type_name, str->type_location);
       else
-	symbol_type_set (str, sym->type_name, sym->type_location);
+        symbol_type_set (str, sym->type_name, sym->type_location);
     }
 
 
   if (str->destructor.code || sym->destructor.code)
     {
       if (str->destructor.code)
-	symbol_destructor_set (sym, &str->destructor);
+        symbol_destructor_set (sym, &str->destructor);
       else
-	symbol_destructor_set (str, &sym->destructor);
+        symbol_destructor_set (str, &sym->destructor);
     }
 
   if (str->printer.code || sym->printer.code)
     {
       if (str->printer.code)
-	symbol_printer_set (sym, &str->printer);
+        symbol_printer_set (sym, &str->printer);
       else
-	symbol_printer_set (str, &sym->printer);
+        symbol_printer_set (str, &sym->printer);
     }
 
   if (sym->prec || str->prec)
     {
       if (str->prec)
-	symbol_precedence_set (sym, str->prec, str->assoc,
-			       str->prec_location);
+        symbol_precedence_set (sym, str->prec, str->assoc,
+                               str->prec_location);
       else
-	symbol_precedence_set (str, sym->prec, sym->assoc,
-			       sym->prec_location);
+        symbol_precedence_set (str, sym->prec, sym->assoc,
+                               sym->prec_location);
     }
 }
 
 static bool
 symbol_check_alias_consistency_processor (void *this,
-					  void *null ATTRIBUTE_UNUSED)
+                                          void *null ATTRIBUTE_UNUSED)
 {
   symbol_check_alias_consistency (this);
   return true;
@@ -582,7 +582,7 @@ symbol_translation (symbol *this)
     {
       /* A token which translation has already been set? */
       if (token_translations[this->user_token_number] != undeftoken->number)
-	user_token_number_redeclaration
+        user_token_number_redeclaration
           (this->user_token_number,
            symbols[token_translations[this->user_token_number]],
            this);
@@ -670,15 +670,15 @@ void
 symbols_new (void)
 {
   symbol_table = hash_initialize (HT_INITIAL_CAPACITY,
-				  NULL,
-				  hash_symbol_hasher,
-				  hash_symbol_comparator,
-				  free);
+                                  NULL,
+                                  hash_symbol_hasher,
+                                  hash_symbol_comparator,
+                                  free);
   semantic_type_table = hash_initialize (HT_INITIAL_CAPACITY,
-				         NULL,
-				         hash_semantic_type_hasher,
-				         hash_semantic_type_comparator,
-				         free);
+                                         NULL,
+                                         hash_semantic_type_hasher,
+                                         hash_semantic_type_comparator,
+                                         free);
 }
 
 
@@ -862,12 +862,12 @@ symbols_token_translations_init (void)
     {
       symbol *this = symbols[i];
       if (this->user_token_number != USER_NUMBER_UNDEFINED)
-	{
-	  if (this->user_token_number > max_user_token_number)
-	    max_user_token_number = this->user_token_number;
-	  if (this->user_token_number == 256)
-	    num_256_available_p = false;
-	}
+        {
+          if (this->user_token_number > max_user_token_number)
+            max_user_token_number = this->user_token_number;
+          if (this->user_token_number == 256)
+            num_256_available_p = false;
+        }
     }
 
   /* If 256 is not used, assign it to error, to follow POSIX.  */
@@ -883,13 +883,13 @@ symbols_token_translations_init (void)
     {
       symbol *this = symbols[i];
       if (this->user_token_number == USER_NUMBER_UNDEFINED)
-	this->user_token_number = ++max_user_token_number;
+        this->user_token_number = ++max_user_token_number;
       if (this->user_token_number > max_user_token_number)
-	max_user_token_number = this->user_token_number;
+        max_user_token_number = this->user_token_number;
     }
 
   token_translations = xnmalloc (max_user_token_number + 1,
-				 sizeof *token_translations);
+                                 sizeof *token_translations);
 
   /* Initialize all entries for literal tokens to the internal token
      number for $undefined, which represents all invalid inputs.  */
@@ -940,12 +940,12 @@ symbols_pack (void)
 
   if (startsymbol->class == unknown_sym)
     fatal_at (startsymbol_location,
-	      _("the start symbol %s is undefined"),
-	      startsymbol->tag);
+              _("the start symbol %s is undefined"),
+              startsymbol->tag);
   else if (startsymbol->class == token_sym)
     fatal_at (startsymbol_location,
-	      _("the start symbol %s is a token"),
-	      startsymbol->tag);
+              _("the start symbol %s is a token"),
+              startsymbol->tag);
 }
 
 
@@ -961,7 +961,7 @@ default_tagged_destructor_set (code_props const *destructor)
       complain_at (destructor->location,
                    _("redeclaration for default tagged %%destructor"));
       complain_at (default_tagged_destructor.location,
-		   _("previous declaration"));
+                   _("previous declaration"));
     }
   default_tagged_destructor = *destructor;
 }
@@ -974,7 +974,7 @@ default_tagless_destructor_set (code_props const *destructor)
       complain_at (destructor->location,
                    _("redeclaration for default tagless %%destructor"));
       complain_at (default_tagless_destructor.location,
-		   _("previous declaration"));
+                   _("previous declaration"));
     }
   default_tagless_destructor = *destructor;
 }
@@ -987,7 +987,7 @@ default_tagged_printer_set (code_props const *printer)
       complain_at (printer->location,
                    _("redeclaration for default tagged %%printer"));
       complain_at (default_tagged_printer.location,
-		   _("previous declaration"));
+                   _("previous declaration"));
     }
   default_tagged_printer = *printer;
 }
@@ -1000,7 +1000,7 @@ default_tagless_printer_set (code_props const *printer)
       complain_at (printer->location,
                    _("redeclaration for default tagless %%printer"));
       complain_at (default_tagless_printer.location,
-		   _("previous declaration"));
+                   _("previous declaration"));
     }
   default_tagless_printer = *printer;
 }
