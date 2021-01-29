@@ -190,11 +190,6 @@ symbol_check_alias_consistence (symbol_t *this)
 static bool
 symbol_pack (symbol_t *this)
 {
-  if (getenv ("DEBUG"))
-    fprintf (stderr, "Packing %s, %s, number = %d\n",
-	     this->tag,
-	     this->class == nterm_sym ? "nterm" : "TERM",
-	     this->number);
   if (this->class == nterm_sym)
     {
       this->number += ntokens;
@@ -223,8 +218,6 @@ symbol_pack (symbol_t *this)
       assert (this->number != -1);
     }
 
-  if (getenv ("DEBUG"))
-    fprintf (stderr, "Setting %d = %s\n", this->number, this->tag);
   symbols[this->number] = this;
   return TRUE;
 }
@@ -239,10 +232,6 @@ symbol_pack (symbol_t *this)
 static bool
 symbol_translation (symbol_t *this)
 {
-  if (getenv ("DEBUG"))
-    fprintf (stderr, "Considering Setting UserVal %s = %d (val = %d)\n",
-	     this->tag, this->user_token_number, this->number);
-
   /* Non-terminal? */
   if (this->class == token_sym
       && this->user_token_number != SALIAS)
@@ -253,9 +242,6 @@ symbol_translation (symbol_t *this)
 		  symbols[token_translations[this->user_token_number]]->tag,
 		  this->tag, this->user_token_number);
 
-      if (getenv ("DEBUG"))
-	fprintf (stderr, "Setting UserVal %s = %d (val = %d)\n",
-		 this->tag, this->user_token_number, this->number);
       token_translations[this->user_token_number] = this->number;
     }
 
@@ -720,12 +706,7 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 	  if (what_is == nterm_sym && oldclass != nterm_sym)
 	    symbol->number = nvars++;
 	  if (what_is == token_sym && symbol->number == -1)
-	    {
-	      symbol->number = ntokens++;
-	      if (getenv ("DEBUG"))
-		fprintf (stderr, "Set %s to %d\n",
-			 symbol->tag, symbol->number);
-	    }
+	    symbol->number = ntokens++;
 
 	  if (typename)
 	    {
@@ -1659,9 +1640,6 @@ readgram (void)
     fatal (_("too many symbols (tokens plus nonterminals); maximum %d"),
 	   MAXSHORT);
 
-  if (getenv ("DEBUG"))
-    fprintf (stderr, "nsyms == ntokens + nvars: %d == %d + %d\n",
-	     nsyms, ntokens, nvars);
   assert (nsyms == ntokens + nvars);
 }
 
@@ -1706,16 +1684,10 @@ token_translations_init (void)
   for (i = 0; i < ntokens; ++i)
     {
       symbol_t *this = symbols[i];
-      if (getenv ("DEBUG"))
-	fprintf (stderr, "UserVal %s = %d (val = %d)\n",
-		 this->tag, this->user_token_number, this->number);
       if (this->user_token_number == SUNDEF)
 	this->user_token_number = ++last_user_token_number;
       if (this->user_token_number > max_user_token_number)
 	max_user_token_number = this->user_token_number;
-      if (getenv ("DEBUG"))
-	fprintf (stderr, "Now: UserVal %s = %d (val = %d)\n",
-		 this->tag, this->user_token_number, this->number);
     }
 
   token_translations = XCALLOC (short, max_user_token_number + 1);
