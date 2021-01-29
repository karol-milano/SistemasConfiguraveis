@@ -466,7 +466,7 @@ copy_definition (void)
 static void
 parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 {
-  int token = 0;
+  token_t token = 0;
   char *typename = 0;
 
   /* The symbol being defined.  */
@@ -593,7 +593,7 @@ parse_type_decl (void)
 
   for (;;)
     {
-      int t;
+      token_t t;
       int tmp_char = ungetc (skip_white_space (), finput);
 
       if (tmp_char == '%')
@@ -643,7 +643,7 @@ parse_assoc_decl (associativity assoc)
 
   for (;;)
     {
-      int t;
+      token_t t;
       int tmp_char = ungetc (skip_white_space (), finput);
 
       if (tmp_char == '%')
@@ -821,7 +821,7 @@ parse_expect_decl (void)
 static void
 parse_thong_decl (void)
 {
-  int token;
+  token_t token;
   struct bucket *symbol;
   char *typename = 0;
   int usrtoknum;
@@ -1198,12 +1198,12 @@ static int
 get_type (void)
 {
   int k;
-  int t;
+  token_t token;
   char *name;
 
-  t = lex ();
+  token = lex ();
 
-  if (t != tok_typename)
+  if (token != tok_typename)
     {
       complain (_("invalid %s declaration"), "%type");
       return t;
@@ -1213,9 +1213,9 @@ get_type (void)
 
   for (;;)
     {
-      t = lex ();
+      token = lex ();
 
-      switch (t)
+      switch (token)
 	{
 	case tok_semicolon:
 	  return lex ();
@@ -1232,7 +1232,7 @@ get_type (void)
 	  break;
 
 	default:
-	  return t;
+	  return token;
 	}
     }
 }
@@ -1253,7 +1253,7 @@ get_type (void)
 static void
 readgram (void)
 {
-  int t;
+  token_t t;
   bucket *lhs = NULL;
   symbol_list *p;
   symbol_list *p1;
@@ -1352,7 +1352,7 @@ readgram (void)
 	      if (t == tok_identifier)
 		{
 		  bucket *ssave;
-		  int t1;
+		  token_t t1;
 
 		  ssave = symval;
 		  t1 = lex ();
