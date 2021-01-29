@@ -95,7 +95,7 @@
 #include "alloc.h"
 #include "files.h"
 #include "gram.h"
-#include "state.h"
+#include "LR0.h"
 #include "complain.h"
 #include "output.h"
 #include "lalr.h"
@@ -104,9 +104,6 @@
 
 extern void berror PARAMS((const char *));
 
-extern char **tags;
-extern short *user_toknums;
-extern int final_state;
 
 
 static int nvectors;
