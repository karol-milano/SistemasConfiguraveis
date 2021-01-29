@@ -100,13 +100,13 @@
 #include "output.h"
 #include "lalr.h"
 #include "reader.h"
+#include "conflicts.h"
 
 extern void berror PARAMS((const char *));
 
 extern char **tags;
 extern short *user_toknums;
 extern int final_state;
-extern errs **err_table;
 
 
 static int nvectors;
