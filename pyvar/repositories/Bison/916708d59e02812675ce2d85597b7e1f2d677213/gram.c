@@ -47,10 +47,6 @@ symbol_number *token_translations = NULL;
 
 int max_user_token_number = 256;
 
-int glr_parser = 0;
-int pure_parser = 0;
-
-
 /*--------------------------------------------------------------.
 | Return true IFF the rule has a `number' smaller than NRULES.  |
 `--------------------------------------------------------------*/
