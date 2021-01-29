@@ -577,7 +577,7 @@ token_definitions_output (FILE *out)
       if (number == SALIAS)
 	continue;
       /* Skip error token.  */
-      if (symbol->value == error_token_number)
+      if (symbol->number == error_token_number)
 	continue;
       if (symbol->tag[0] == '\'')
 	continue;               /* skip literal character */
@@ -600,7 +600,7 @@ token_definitions_output (FILE *out)
       if (semantic_parser)
 	/* FIXME: This is probably wrong, and should be just as
 	   above. --akim.  */
-	fprintf (out, "# define T%s\t%d\n", symbol->tag, symbol->value);
+	fprintf (out, "# define T%s\t%d\n", symbol->tag, symbol->number);
       first = 0;
     }
 }
