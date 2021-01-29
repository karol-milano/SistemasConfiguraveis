@@ -26,6 +26,8 @@
 #include "complain.h"
 #include "derives.h"
 #include "output.h"
+#include "reader.h"
+#include "lalr.h"
 
 #if 0				/* XXX currently unused.  */
 /* Nonzero means failure has been detected; don't write a parser file.  */
@@ -40,12 +42,10 @@ extern void berror PARAMS((const char *));
 extern char *printable_version PARAMS ((int));
 
 extern void openfiles PARAMS ((void));
-extern void reader PARAMS ((void));
 extern void reduce_grammar PARAMS ((void));
 extern void set_nullable PARAMS ((void));
 extern void free_nullable PARAMS ((void));
 extern void generate_states PARAMS ((void));
-extern void lalr PARAMS ((void));
 extern void initialize_conflicts PARAMS ((void));
 extern void finalize_conflicts PARAMS ((void));
 extern void verbose PARAMS ((void));
