@@ -488,8 +488,13 @@ parse_token_decl (int what_is, int what_is_not)
 
   for (;;)
     {
-      if(ungetc(skip_white_space(), finput) == '%')
+      int tmp_char = ungetc (skip_white_space (), finput);
+
+      if (tmp_char == '%')
 	return;
+      if (tmp_char == EOF)
+	fatals ("Premature EOF after %s", token_buffer);
+
       token = lex();
       if (token == COMMA)
 	{
@@ -671,9 +676,12 @@ parse_type_decl (void)
   for (;;)
     {
       register int t;
+      int tmp_char = ungetc (skip_white_space (), finput);
 
-      if(ungetc(skip_white_space(), finput) == '%')
+      if (tmp_char == '%')
 	return;
+      if (tmp_char == EOF)
+	fatals ("Premature EOF after %s", token_buffer);
 
       t = lex();
 
@@ -716,9 +724,12 @@ parse_assoc_decl (int assoc)
   for (;;)
     {
       register int t;
+      int tmp_char = ungetc (skip_white_space (), finput);
 
-      if(ungetc(skip_white_space(), finput) == '%')
+      if (tmp_char == '%')
 	return;
+      if (tmp_char == EOF)
+	fatals ("Premature EOF after %s", token_buffer);
 
       t = lex();
 
