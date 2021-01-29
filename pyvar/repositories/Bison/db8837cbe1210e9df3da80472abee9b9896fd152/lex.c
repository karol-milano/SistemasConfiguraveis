@@ -32,12 +32,12 @@
 static struct obstack token_obstack;
 const char *token_buffer = NULL;
 
-bucket *symval = NULL;
+symbol_t *symval = NULL;
 int numval;
 
 /* A token to be reread, see unlex and lex. */
 static token_t unlexed = tok_undef;
-static bucket *unlexed_symval = NULL;
+static symbol_t *unlexed_symval = NULL;
 static const char *unlexed_token_buffer = NULL;
 
 void
