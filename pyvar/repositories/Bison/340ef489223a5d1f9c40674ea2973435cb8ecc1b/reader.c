@@ -30,15 +30,8 @@
 #include "complain.h"
 #include "output.h"
 #include "reader.h"
+#include "conflicts.h"
 
-extern bucket *symval;
-extern int numval;
-extern int expected_conflicts;
-extern char *token_buffer;
-extern int maxtoken;
-
-extern void tabinit PARAMS ((void));
-extern void free_symtab PARAMS ((void));
 extern char *printable_version PARAMS ((int));
 
 #define	LTYPESTR	"\
