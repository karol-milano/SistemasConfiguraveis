@@ -30,7 +30,7 @@
 #include "quote.h"
 
 /* Buffer for storing the current token.  */
-struct obstack token_obstack;
+static struct obstack token_obstack;
 const char *token_buffer = NULL;
 
 bucket *symval;
