@@ -175,7 +175,8 @@ void
 symbol_user_token_number_set (symbol_t *symbol,
 			      int user_token_number, location_t location)
 {
-  assert (symbol->class == token_sym);
+  if (symbol->class != token_sym)
+    abort ();
 
   if (symbol->user_token_number != USER_NUMBER_UNDEFINED
       && symbol->user_token_number != user_token_number)
@@ -252,7 +253,8 @@ symbol_make_alias (symbol_t *symbol, symbol_t *symval, location_t loc)
       /* symbol and symval combined are only one symbol */
       nsyms--;
       ntokens--;
-      assert (ntokens == symbol->number || ntokens == symval->number);
+      if (ntokens != symbol->number && ntokens != symval->number)
+	abort ();
       symbol->number = symval->number =
 	(symval->number < symbol->number) ? symval->number : symbol->number;
     }
@@ -322,7 +324,8 @@ symbol_pack (symbol_t *this)
 	    this->number = this->alias->number = 0;
 	  else
 	    {
-	      assert (this->alias->number != NUMBER_UNDEFINED);
+	      if (this->alias->number == NUMBER_UNDEFINED)
+		abort ();
 	      this->number = this->alias->number;
 	    }
 	}
@@ -332,7 +335,8 @@ symbol_pack (symbol_t *this)
     }
   else /* this->class == token_sym */
     {
-      assert (this->number != NUMBER_UNDEFINED);
+      if (this->number == NUMBER_UNDEFINED)
+	abort ();
     }
 
   symbols[this->number] = this;
