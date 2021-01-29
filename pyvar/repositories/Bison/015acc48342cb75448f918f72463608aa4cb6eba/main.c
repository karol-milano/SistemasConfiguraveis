@@ -28,6 +28,7 @@
 #include "output.h"
 #include "reader.h"
 #include "lalr.h"
+#include "reduce.h"
 
 #if 0				/* XXX currently unused.  */
 /* Nonzero means failure has been detected; don't write a parser file.  */
@@ -41,7 +42,6 @@ extern void berror PARAMS((const char *));
 
 extern char *printable_version PARAMS ((int));
 
-extern void reduce_grammar PARAMS ((void));
 extern void set_nullable PARAMS ((void));
 extern void free_nullable PARAMS ((void));
 extern void generate_states PARAMS ((void));
