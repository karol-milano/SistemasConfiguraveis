@@ -36,11 +36,10 @@ const char *token_buffer = NULL;
 bucket *symval;
 int numval;
 
-/* these two describe a token to be reread */
+/* A token to be reread, see unlex and lex. */
 static token_t unlexed = tok_undef;
-/* by the next call to lex */
 static bucket *unlexed_symval = NULL;
-
+static const char *unlexed_token_buffer = NULL;
 
 void
 lex_init (void)
@@ -325,6 +324,7 @@ void
 unlex (token_t token)
 {
   unlexed = token;
+  unlexed_token_buffer = token_buffer;
   unlexed_symval = symval;
 }
 
@@ -369,6 +369,7 @@ lex (void)
     {
       token_t res = unlexed;
       symval = unlexed_symval;
+      token_buffer = unlexed_token_buffer;
       unlexed = tok_undef;
       return res;
     }
