@@ -403,10 +403,11 @@ symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
   if (user_token_number == 0)
     {
       endtoken = sym;
-      endtoken->number = 0;
       /* It is always mapped to 0, so it was already counted in
 	 NTOKENS.  */
-      --ntokens;
+      if (endtoken->number != NUMBER_UNDEFINED)
+        --ntokens;
+      endtoken->number = 0;
     }
 }
 
