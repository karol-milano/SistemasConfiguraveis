@@ -235,11 +235,11 @@ prepare_tokens (void)
     int j = 0;
     for (i = 0; i < nsyms; i++)
       {
-	/* Be sure not to use twice the same quotearg slot. */
+	/* Be sure not to use twice the same QUOTEARG slot:
+	   SYMBOL_TAG_GET uses slot 0.  */
 	const char *cp =
 	  quotearg_n_style (1, c_quoting_style,
-			    quotearg_style (escape_quoting_style,
-					    symbols[i]->tag));
+			    symbol_tag_get (symbols[i]));
 	/* Width of the next token, including the two quotes, the coma
 	   and the space.  */
 	int strsize = strlen (cp) + 2;
