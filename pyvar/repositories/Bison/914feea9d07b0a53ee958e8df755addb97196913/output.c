@@ -89,6 +89,7 @@
    negative short int.  Used to flag ??  */
 
 #include "system.h"
+#include "bitsetv.h"
 #include "quotearg.h"
 #include "error.h"
 #include "getargs.h"
@@ -922,7 +923,7 @@ output_actions (void)
   width = XCALLOC (short, nvectors);
 
   token_actions ();
-  XFREE (LA);
+  bitsetv_free (LA);
   XFREE (LAruleno);
 
   goto_actions ();
