@@ -471,10 +471,10 @@ token_definitions_output (FILE *out)
       int number = sym->user_token_number;
       uniqstr id = symbol_id_get (sym);
 
-      /* At this stage, if there are literal aliases, they are part of
-	 SYMBOLS, so we should not find symbols which are the aliases
-	 here.  */
-      aver (number != USER_NUMBER_ALIAS);
+      /* At this stage, if there are literal string aliases, they are
+         part of SYMBOLS, so we should not find their aliased symbols
+         here.  */
+      aver (number != USER_NUMBER_HAS_STRING_ALIAS);
 
       /* Skip error token and tokens without identifier.  */
       if (sym != errtoken && id)
