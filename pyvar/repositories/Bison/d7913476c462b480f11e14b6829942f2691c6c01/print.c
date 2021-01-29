@@ -20,7 +20,7 @@
 
 
 #include "system.h"
-#include "alloc.h"
+#include "xalloc.h"
 #include "files.h"
 #include "gram.h"
 #include "LR0.h"
@@ -29,7 +29,7 @@
 #include "getargs.h"
 #include "state.h"
 #include "reader.h"
-
+#include "print.h"
 
 #if 0
 static void
