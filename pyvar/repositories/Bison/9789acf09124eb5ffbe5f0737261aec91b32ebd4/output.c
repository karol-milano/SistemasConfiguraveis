@@ -21,7 +21,6 @@
 #include <config.h>
 #include "system.h"
 
-#include <assert.h>
 #include <configmake.h>
 #include <error.h>
 #include <get-errno.h>
@@ -637,7 +636,7 @@ output_skeleton (void)
     argv[i++] = full_m4bison;
     argv[i++] = full_skeleton;
     argv[i++] = NULL;
-    assert (i <= ARRAY_CARDINALITY (argv));
+    aver (i <= ARRAY_CARDINALITY (argv));
   }
 
   init_subpipe ();
