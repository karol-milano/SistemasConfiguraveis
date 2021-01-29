@@ -469,37 +469,20 @@ token_definitions_output (FILE *out)
     {
       symbol *sym = symbols[i];
       int number = sym->user_token_number;
+      uniqstr id = symbol_id_get (sym);
 
       /* At this stage, if there are literal aliases, they are part of
 	 SYMBOLS, so we should not find symbols which are the aliases
 	 here.  */
       aver (number != USER_NUMBER_ALIAS);
 
-      /* Skip error token.  */
-      if (sym == errtoken)
-	continue;
-
-      /* If this string has an alias, then it is necessarily the alias
-	 which is to be output.  */
-      if (sym->alias)
-	sym = sym->alias;
-
-      /* Don't output literal chars or strings (when defined only as a
-	 string).  Note that must be done after the alias resolution:
-	 think about `%token 'f' "f"'.  */
-      if (sym->tag[0] == '\'' || sym->tag[0] == '\"')
-	continue;
-
-      /* Don't #define nonliteral tokens whose names contain periods,
-         dashes or '$' (as does the default value of the EOF token).  */
-      if (strchr (sym->tag, '.')
-          || strchr (sym->tag, '-')
-          || strchr (sym->tag, '$'))
-	continue;
-
-      fprintf (out, "%s[[[%s]], %d]",
-	       sep, sym->tag, number);
-      sep = ",\n";
+      /* Skip error token and tokens without identifier.  */
+      if (sym != errtoken && id)
+        {
+          fprintf (out, "%s[[[%s]], %d]",
+                   sep, id, number);
+          sep = ",\n";
+        }
     }
   fputs ("])\n\n", out);
 }
