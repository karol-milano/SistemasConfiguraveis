@@ -24,6 +24,7 @@
    do so.  */
 
 #include "system.h"
+#include "getargs.h"
 #include "types.h"
 #include "gram.h"
 #include "nullable.h"
@@ -47,9 +48,8 @@ set_nullable (void)
   char any_tokens;
   short *r1;
 
-#ifdef	TRACE
-  fprintf (stderr, "Entering set_nullable\n");
-#endif
+  if (trace_flag)
+    fprintf (stderr, "Entering set_nullable");
 
   nullable = XCALLOC (char, nvars) - ntokens;
 
