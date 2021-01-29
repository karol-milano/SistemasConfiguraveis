@@ -383,7 +383,7 @@ symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
 {
   int *user_token_numberp;
 
-  assert (sym->class == token_sym);
+  aver (sym->class == token_sym);
 
   if (sym->user_token_number != USER_NUMBER_ALIAS)
     user_token_numberp = &sym->user_token_number;
@@ -546,7 +546,7 @@ symbol_pack (symbol *this)
 	    this->number = this->alias->number = 0;
 	  else
 	    {
-	      assert (this->alias->number != NUMBER_UNDEFINED);
+	      aver (this->alias->number != NUMBER_UNDEFINED);
 	      this->number = this->alias->number;
 	    }
 	}
@@ -555,7 +555,7 @@ symbol_pack (symbol *this)
 	return true;
     }
   else /* this->class == token_sym */
-    assert (this->number != NUMBER_UNDEFINED);
+    aver (this->number != NUMBER_UNDEFINED);
 
   symbols[this->number] = this;
   return true;
