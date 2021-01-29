@@ -162,7 +162,10 @@ prepare_symbols (void)
     int j = 2;
     for (i = 0; i < nsyms; i++)
       {
-	const char *cp = quotearg_style (c_quoting_style, symbols[i]->tag);
+	char const *tag = symbols[i]->tag;
+	char const *cp = (*tag == '"'
+			  ? tag
+			  : quotearg_style (c_quoting_style, tag));
 	/* Width of the next token, including the two quotes, the
 	   comma and the space.  */
 	int width = strlen (cp) + 2;
