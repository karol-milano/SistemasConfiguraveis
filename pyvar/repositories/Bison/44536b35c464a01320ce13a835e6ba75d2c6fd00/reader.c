@@ -483,14 +483,12 @@ copy_definition (struct obstack *oout)
 }
 
 
-/*-------------------------------------------------------------------.
-| Parse what comes after %token or %nterm.  For %token, WHAT_IS is   |
-| token_sym and WHAT_IS_NOT is nterm_sym.  For %nterm, the arguments |
-| are reversed.                                                      |
-`-------------------------------------------------------------------*/
+/*------------------------------------------.
+| Parse what comes after %token or %nterm.  |
+`------------------------------------------*/
 
 static void
-parse_token_decl (symbol_class what_is, symbol_class what_is_not)
+parse_token_decl (symbol_class class)
 {
   token_t token = tok_undef;
   char *typename = NULL;
@@ -512,60 +510,40 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 	fatal (_("Premature EOF after %s"), token_buffer);
 
       token = lex ();
-      if (token == tok_comma)
+      switch (token)
 	{
+	case tok_comma:
 	  symbol = NULL;
-	  continue;
-	}
-      if (token == tok_typename)
-	{
+	  break;
+
+	case tok_typename:
 	  typename = xstrdup (token_buffer);
 	  symbol = NULL;
-	}
-      else if (token == tok_identifier && *symval->tag == '\"' && symbol)
-	{
-	  symbol_make_alias (symbol, symval, typename);
- 	  symbol = NULL;
-	}
-      else if (token == tok_identifier)
-	{
-	  int oldclass = symval->class;
-	  symbol = symval;
-
-	  if (symbol->class == what_is_not)
-	    complain (_("symbol %s redefined"), symbol->tag);
-	  symbol->class = what_is;
-	  if (what_is == nterm_sym && oldclass != nterm_sym)
-	    symbol->number = nvars++;
-	  if (what_is == token_sym && symbol->number == NUMBER_UNDEFINED)
-	    symbol->number = ntokens++;
-
-	  if (typename)
+	  break;
+
+	case tok_identifier:
+	  if (*symval->tag == '\"' && symbol)
 	    {
-	      if (symbol->type_name == NULL)
-		symbol->type_name = typename;
-	      else if (strcmp (typename, symbol->type_name) != 0)
-		complain (_("type redeclaration for %s"), symbol->tag);
+	      symbol_make_alias (symbol, symval, typename);
+	      symbol = NULL;
 	    }
-	}
-      else if (symbol && token == tok_number)
-	{
-	  symbol->user_token_number = numval;
-	  /* User defined EOF token? */
-	  if (numval == 0)
+	  else
 	    {
-	      eoftoken = symbol;
-	      eoftoken->number = 0;
-	      /* It is always mapped to 0, so it was already counted in
-		 NTOKENS.  */
-	      --ntokens;
+	      symbol = symval;
+	      symbol_class_set (symbol, class);
+	      if (typename)
+		symbol_type_set (symbol, typename);
 	    }
-	}
-      else
-	{
+	  break;
+
+	case tok_number:
+	  symbol_user_token_number_set (symbol, numval);
+	  break;
+
+	default:
 	  complain (_("`%s' is invalid in %s"),
 		    token_buffer,
-		    (what_is == token_sym) ? "%token" : "%nterm");
+		    (class == token_sym) ? "%token" : "%nterm");
 	  skip_to_char ('%');
 	}
     }
@@ -922,11 +900,11 @@ read_declarations (void)
 	      break;
 
 	    case tok_token:
-	      parse_token_decl (token_sym, nterm_sym);
+	      parse_token_decl (token_sym);
 	      break;
 
 	    case tok_nterm:
-	      parse_token_decl (nterm_sym, token_sym);
+	      parse_token_decl (nterm_sym);
 	      break;
 
 	    case tok_type:
