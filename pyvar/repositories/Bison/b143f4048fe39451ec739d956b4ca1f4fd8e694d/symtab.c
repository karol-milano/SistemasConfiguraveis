@@ -489,7 +489,7 @@ static inline void
 symbol_check_alias_consistency (symbol *this)
 {
   symbol *sym = this;
-  symbol *str  = this->alias;
+  symbol *str = this->alias;
 
   /* Check only the symbol in the symbol-string pair.  */
   if (!(this->alias
