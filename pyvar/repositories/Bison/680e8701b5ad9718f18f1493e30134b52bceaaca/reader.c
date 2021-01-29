@@ -1691,7 +1691,7 @@ token_translations_init (void)
 	max_user_token_number = this->user_token_number;
     }
 
-  token_translations = XCALLOC (short, max_user_token_number + 1);
+  token_translations = XCALLOC (token_number_t, max_user_token_number + 1);
 
   /* Initialize all entries for literal tokens to 2, the internal
      token number for $undefined., which represents all invalid
