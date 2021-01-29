@@ -372,17 +372,25 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 	}
       else if (token == IDENTIFIER && *symval->tag == '\"' && symbol)
 	{
+	  if (symval->alias)
+	    warn (_("symbol `%s' used more than once as a literal string"),
+		  symval->tag);
+	  else if (symbol->alias)
+	    warn (_("symbol `%s' given more than one literal string"),
+		  symbol->tag);
+	  else
+	    {
+	      symval->class = token_sym;
+	      symval->type_name = typename;
+	      symval->user_token_number = symbol->user_token_number;
+	      symbol->user_token_number = SALIAS;
+	      symval->alias = symbol;
+	      symbol->alias = symval;
+	      /* symbol and symval combined are only one symbol */
+	      nsyms--;
+	    }
 	  translations = 1;
-	  symval->class = token_sym;
-	  symval->type_name = typename;
-	  symval->user_token_number = symbol->user_token_number;
-	  symbol->user_token_number = SALIAS;
-
-	  symval->alias = symbol;
-	  symbol->alias = symval;
-	  symbol = NULL;
-
-	  nsyms--;		/* symbol and symval combined are only one symbol */
+ 	  symbol = NULL;
 	}
       else if (token == IDENTIFIER)
 	{
