@@ -800,83 +800,6 @@ parse_expect_decl (void)
 }
 
 
-/*-------------------------------------------------------------------.
-| Parse what comes after %thong.  the full syntax is                 |
-|                                                                    |
-|                %thong <type> token number literal                  |
-|                                                                    |
-| the <type> or number may be omitted.  The number specifies the     |
-| user_token_number.                                                 |
-|                                                                    |
-| Two symbols are entered in the table, one for the token symbol and |
-| one for the literal.  Both are given the <type>, if any, from the  |
-| declaration.  The ->user_token_number of the first is              |
-| USER_NUMBER_ALIAS and the ->user_token_number of the second is set |
-| to the number, if any, from the declaration.  The two symbols are  |
-| linked via pointers in their ->alias fields.                       |
-|                                                                    |
-| During OUTPUT_DEFINES_TABLE, the symbol is reported thereafter,    |
-| only the literal string is retained it is the literal string that  |
-| is output to yytname                                               |
-`-------------------------------------------------------------------*/
-
-static void
-parse_thong_decl (void)
-{
-  token_t token;
-  symbol_t *symbol;
-  char *typename = 0;
-  int usrtoknum = USER_NUMBER_UNDEFINED;
-
-  token = lex ();		/* fetch typename or first token */
-  if (token == tok_typename)
-    {
-      typename = xstrdup (token_buffer);
-      token = lex ();		/* fetch first token */
-    }
-
-  /* process first token */
-
-  if (token != tok_identifier)
-    {
-      complain (_("unrecognized item %s, expected an identifier"),
-		token_buffer);
-      skip_to_char ('%');
-      return;
-    }
-  symval->class = token_sym;
-  symval->type_name = typename;
-  symval->user_token_number = USER_NUMBER_ALIAS;
-  symbol = symval;
-
-  token = lex ();		/* get number or literal string */
-
-  if (token == tok_number)
-    {
-      usrtoknum = numval;
-      token = lex ();		/* okay, did number, now get literal */
-    }
-
-  /* process literal string token */
-
-  if (token != tok_identifier || *symval->tag != '\"')
-    {
-      complain (_("expected string constant instead of %s"), token_buffer);
-      skip_to_char ('%');
-      return;
-    }
-  symval->class = token_sym;
-  symval->type_name = typename;
-  symval->user_token_number = usrtoknum;
-
-  symval->alias = symbol;
-  symbol->alias = symval;
-
-  /* symbol and symval combined are only one symbol.  */
-  nsyms--;
-}
-
-
 static void
 parse_muscle_decl (void)
 {
@@ -1022,10 +945,6 @@ read_declarations (void)
 	      parse_expect_decl ();
 	      break;
 
-	    case tok_thong:
-	      parse_thong_decl ();
-	      break;
-
 	    case tok_left:
 	      parse_assoc_decl (left_assoc);
 	      break;
