@@ -462,12 +462,18 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 {
   int token = 0;
   char *typename = 0;
-  struct bucket *symbol = NULL;	/* pts to symbol being defined */
 
+  /* The symbol being defined.  */
+  struct bucket *symbol = NULL;
+
+  /* After `%token' and `%nterm', any number of symbols maybe be
+     defined.  */
   for (;;)
     {
       int tmp_char = ungetc (skip_white_space (), finput);
 
+      /* `%' (for instance from `%token', or from `%%' etc.) is the
+	 only valid means to end this declaration.  */
       if (tmp_char == '%')
 	return;
       if (tmp_char == EOF)
