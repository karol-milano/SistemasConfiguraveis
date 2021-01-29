@@ -223,8 +223,7 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
 void
 symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
 {
-  if (sym->class != token_sym)
-    abort ();
+  assert (sym->class == token_sym);
 
   if (sym->user_token_number != USER_NUMBER_UNDEFINED
       && sym->user_token_number != user_token_number)
@@ -295,8 +294,7 @@ symbol_make_alias (symbol *sym, symbol *symval, location loc)
       /* sym and symval combined are only one symbol.  */
       nsyms--;
       ntokens--;
-      if (ntokens != sym->number && ntokens != symval->number)
-	abort ();
+      assert (ntokens == sym->number || ntokens == symval->number);
       sym->number = symval->number =
 	(symval->number < sym->number) ? symval->number : sym->number;
       symbol_type_set (symval, sym->type_name, loc);
@@ -389,8 +387,7 @@ symbol_pack (symbol *this)
 	    this->number = this->alias->number = 0;
 	  else
 	    {
-	      if (this->alias->number == NUMBER_UNDEFINED)
-		abort ();
+	      assert (this->alias->number != NUMBER_UNDEFINED);
 	      this->number = this->alias->number;
 	    }
 	}
@@ -399,10 +396,7 @@ symbol_pack (symbol *this)
 	return true;
     }
   else /* this->class == token_sym */
-    {
-      if (this->number == NUMBER_UNDEFINED)
-	abort ();
-    }
+    assert (this->number != NUMBER_UNDEFINED);
 
   symbols[this->number] = this;
   return true;
