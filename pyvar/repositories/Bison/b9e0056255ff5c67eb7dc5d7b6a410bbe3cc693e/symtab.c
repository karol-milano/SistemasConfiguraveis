@@ -104,7 +104,7 @@ symbol_destructor_set (symbol_t *symbol, char *destructor, location_t location)
 
 
 /*----------------------------------------------------------------.
-| Set the PRITNER associated to SYMBOL.  Do nothing if passed 0.  |
+| Set the PRINTER associated to SYMBOL.  Do nothing if passed 0.  |
 `----------------------------------------------------------------*/
 
 void
@@ -330,7 +330,7 @@ symbol_pack (symbol_t *this)
 	      this->number = this->alias->number;
 	    }
 	}
-      /* Do not do processing below for USER_NUMBER_ALIASs.  */
+      /* Do not do processing below for USER_NUMBER_ALIASes.  */
       if (this->user_token_number == USER_NUMBER_ALIAS)
 	return true;
     }
