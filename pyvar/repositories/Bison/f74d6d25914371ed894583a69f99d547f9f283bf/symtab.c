@@ -549,31 +549,11 @@ symbol_check_alias_consistency_processor (void *this,
 static inline bool
 symbol_pack (symbol *this)
 {
+  aver (this->number != NUMBER_UNDEFINED);
   if (this->class == nterm_sym)
-    {
-      this->number += ntokens;
-    }
-  else if (this->alias)
-    {
-      /* This symbol and its alias are a single token defn.
-	 Allocate a tokno, and assign to both check agreement of
-	 prec and assoc fields and make both the same */
-      if (this->number == NUMBER_UNDEFINED)
-	{
-	  if (this == endtoken || this->alias == endtoken)
-	    this->number = this->alias->number = 0;
-	  else
-	    {
-	      aver (this->alias->number != NUMBER_UNDEFINED);
-	      this->number = this->alias->number;
-	    }
-	}
-      /* Do not do processing below for USER_NUMBER_HAS_STRING_ALIASes.  */
-      if (this->user_token_number == USER_NUMBER_HAS_STRING_ALIAS)
-	return true;
-    }
-  else /* this->class == token_sym */
-    aver (this->number != NUMBER_UNDEFINED);
+    this->number += ntokens;
+  else if (this->user_token_number == USER_NUMBER_HAS_STRING_ALIAS)
+    return true;
 
   symbols[this->number] = this;
   return true;
