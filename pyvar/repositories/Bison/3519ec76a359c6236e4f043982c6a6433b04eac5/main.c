@@ -29,6 +29,7 @@
 #include "reader.h"
 #include "lalr.h"
 #include "reduce.h"
+#include "nullable.h"
 
 #if 0				/* XXX currently unused.  */
 /* Nonzero means failure has been detected; don't write a parser file.  */
@@ -42,8 +43,6 @@ extern void berror PARAMS((const char *));
 
 extern char *printable_version PARAMS ((int));
 
-extern void set_nullable PARAMS ((void));
-extern void free_nullable PARAMS ((void));
 extern void generate_states PARAMS ((void));
 extern void initialize_conflicts PARAMS ((void));
 extern void finalize_conflicts PARAMS ((void));
