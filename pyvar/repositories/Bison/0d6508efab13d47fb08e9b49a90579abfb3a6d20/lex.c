@@ -33,7 +33,7 @@
 char *token_buffer;
 
 /* Allocated size of token_buffer, not including space for terminator.  */
-int maxtoken;
+static int maxtoken;
 
 bucket *symval;
 int numval;
@@ -51,7 +51,7 @@ init_lex (void)
 }
 
 
-char *
+static char *
 grow_token_buffer (char *p)
 {
   int offset = p - token_buffer;
