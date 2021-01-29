@@ -582,21 +582,25 @@ token_definitions_output (FILE *out)
       symbol_t *symbol = symbols[i];
       int number = symbol->user_token_number;
 
-      if (number == SALIAS)
-	continue;
+      /* At this stage, if there are literal aliases, they are part of
+	 SYMBOLS, so we should not find symbols which are the aliases
+	 here.  */
+      assert (number != USER_NUMBER_ALIAS);
+
       /* Skip error token.  */
       if (symbol == errtoken)
 	continue;
-      if (symbol->tag[0] == '\'')
-	continue;               /* skip literal character */
-      if (symbol->tag[0] == '\"')
-	{
-	  /* use literal string only if given a symbol with an alias */
-	  if (symbol->alias)
-	    symbol = symbol->alias;
-	  else
-	    continue;
-	}
+
+      /* If this string has an alias, then it is necessarily the alias
+	 which is to be output.  */
+      if (symbol->alias)
+	symbol = symbol->alias;
+
+      /* Don't output literal chars or strings (when defined only as a
+	 string).  Note that must be done after the alias resolution:
+	 think about `%token 'f' "f"'.  */
+      if (symbol->tag[0] == '\'' || symbol->tag[0] == '\"')
+	continue;
 
       /* Don't #define nonliteral tokens whose names contain periods
 	 or '$' (as does the default value of the EOF token).  */
@@ -605,6 +609,7 @@ token_definitions_output (FILE *out)
 
       fprintf (out, "%s[[[%s]], [%d]]",
 	       first ? "" : ",\n", symbol->tag, number);
+
       first = 0;
     }
 }
