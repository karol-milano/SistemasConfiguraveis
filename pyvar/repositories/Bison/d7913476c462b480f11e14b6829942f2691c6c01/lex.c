@@ -24,7 +24,7 @@
 #include "getopt.h"		/* for optarg */
 #include "symtab.h"
 #include "lex.h"
-#include "alloc.h"
+#include "xalloc.h"
 #include "complain.h"
 #include "gram.h"
 
@@ -48,7 +48,7 @@ void
 init_lex (void)
 {
   maxtoken = 100;
-  token_buffer = NEW2 (maxtoken + 1, char);
+  token_buffer = XCALLOC (char, maxtoken + 1);
   unlexed = -1;
 }
 
@@ -58,7 +58,7 @@ grow_token_buffer (char *p)
 {
   int offset = p - token_buffer;
   maxtoken *= 2;
-  token_buffer = (char *) xrealloc (token_buffer, maxtoken + 1);
+  token_buffer = XREALLOC (token_buffer, char, maxtoken + 1);
   return token_buffer + offset;
 }
 
