@@ -343,10 +343,10 @@ token_definitions_output (FILE *out)
       symbol *sym = symbols[i];
       int number = sym->user_token_number;
 
-      /* At this stage, if there are literal aliases, they are part of
-	 SYMBOLS, so we should not find symbols which are the aliases
-	 here.  */
-      aver (number != USER_NUMBER_ALIAS);
+      /* At this stage, if there are literal string aliases, they are
+         part of SYMBOLS, so we should not find their aliased symbols
+         here.  */
+      aver (number != USER_NUMBER_HAS_STRING_ALIAS);
 
       /* Skip error token.  */
       if (sym == errtoken)
