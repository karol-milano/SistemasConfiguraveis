@@ -656,13 +656,7 @@ parse_assoc_decl (associativity assoc)
 	  break;
 
 	case tok_identifier:
-	  if (symval->class == nterm_sym)
-	    complain (_("symbol %s redefined"), symval->tag);
-	  if (symval->number == NUMBER_UNDEFINED)
-	    {
-	      symval->number = ntokens++;
-	      symval->class = token_sym;
-	    }
+	  symbol_class_set (symval, token_sym);
 	  symbol_precedence_set (symval, lastprec, assoc);
 	  if (name)
 	    symbol_type_set (symval, name);
@@ -671,7 +665,7 @@ parse_assoc_decl (associativity assoc)
 	case tok_number:
 	  if (prev == tok_identifier)
 	    {
-	      symval->user_token_number = numval;
+	      symbol_user_token_number_set (symval, numval);
 	    }
 	  else
 	    {
