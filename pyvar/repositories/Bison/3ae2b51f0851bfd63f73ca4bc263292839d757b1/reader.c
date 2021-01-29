@@ -52,10 +52,6 @@ int lineno;
 static symbol_list *grammar = NULL;
 static int start_flag = 0;
 
-/* Nonzero if components of semantic values are used, implying
-   they must be unions.  */
-static int value_components_used;
-
 /* Nonzero if %union has been seen.  */
 static int typed = 0;
 
@@ -378,7 +374,6 @@ copy_dollar (FILE *fin, struct obstack *oout,
     {
       read_type_name (fin);
       type_name = token_buffer;
-      value_components_used = 1;
       c = getc (fin);
     }
 
@@ -525,7 +520,6 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
       if (token == tok_typename)
 	{
 	  typename = xstrdup (token_buffer);
-	  value_components_used = 1;
 	  symbol = NULL;
 	}
       else if (token == tok_identifier && *symval->tag == '\"' && symbol)
@@ -630,17 +624,12 @@ parse_type_decl (void)
 
       switch (t)
 	{
-
 	case tok_comma:
 	case tok_semicolon:
 	  break;
 
 	case tok_identifier:
-	  if (symval->type_name == NULL)
-	    symval->type_name = name;
-	  else if (strcmp (name, symval->type_name) != 0)
-	    complain (_("type redeclaration for %s"), symval->tag);
-
+	  symbol_type_set (symval, name);
 	  break;
 
 	default:
@@ -689,10 +678,6 @@ parse_assoc_decl (associativity assoc)
 	  break;
 
 	case tok_identifier:
-	  if (symval->prec != 0)
-	    complain (_("redefining precedence of %s"), symval->tag);
-	  symval->prec = lastprec;
-	  symval->assoc = assoc;
 	  if (symval->class == nterm_sym)
 	    complain (_("symbol %s redefined"), symval->tag);
 	  if (symval->number == NUMBER_UNDEFINED)
@@ -700,13 +685,9 @@ parse_assoc_decl (associativity assoc)
 	      symval->number = ntokens++;
 	      symval->class = token_sym;
 	    }
+	  symbol_precedence_set (symval, lastprec, assoc);
 	  if (name)
-	    {			/* record the type, if one is specified */
-	      if (symval->type_name == NULL)
-		symval->type_name = name;
-	      else if (strcmp (name, symval->type_name) != 0)
-		complain (_("type redeclaration for %s"), symval->tag);
-	    }
+	    symbol_type_set (symval, name);
 	  break;
 
 	case tok_number:
@@ -851,7 +832,6 @@ parse_thong_decl (void)
   if (token == tok_typename)
     {
       typename = xstrdup (token_buffer);
-      value_components_used = 1;
       token = lex ();		/* fetch first token */
     }
 
