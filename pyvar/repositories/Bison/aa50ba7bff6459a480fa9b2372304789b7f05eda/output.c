@@ -21,6 +21,7 @@
 #include <config.h>
 #include "system.h"
 
+#include <assert.h>
 #include <configmake.h>
 #include <error.h>
 #include <get-errno.h>
@@ -40,6 +41,7 @@
 #include "symtab.h"
 #include "tables.h"
 
+# define ARRAY_CARDINALITY(Array) (sizeof (Array) / sizeof *(Array))
 
 static struct obstack format_obstack;
 
@@ -564,6 +566,7 @@ output_skeleton (void)
     argv[i++] = full_m4bison;
     argv[i++] = full_skeleton;
     argv[i++] = NULL;
+    assert (i <= ARRAY_CARDINALITY (argv));
   }
 
   init_subpipe ();
