@@ -611,10 +611,10 @@ symbol_translation (symbol *this)
           (this->user_token_number,
            symbols[token_translations[this->user_token_number]],
            this);
-      
+
       token_translations[this->user_token_number] = this->number;
     }
-  
+
   return true;
 }
 
