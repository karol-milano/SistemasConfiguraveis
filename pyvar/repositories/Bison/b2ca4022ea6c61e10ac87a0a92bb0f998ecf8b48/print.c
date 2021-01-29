@@ -23,14 +23,13 @@
 #include "alloc.h"
 #include "files.h"
 #include "gram.h"
-#include "state.h"
+#include "LR0.h"
 #include "lalr.h"
 #include "conflicts.h"
 #include "getargs.h"
 #include "state.h"
+#include "reader.h"
 
-extern char **tags;
-extern int final_state;
 
 #if 0
 static void
