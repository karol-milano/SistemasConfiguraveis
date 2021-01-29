@@ -25,6 +25,7 @@
    */
 
 #include "system.h"
+#include "getargs.h"
 #include "types.h"
 #include "reader.h"
 #include "gram.h"
@@ -32,7 +33,6 @@
 
 short **derives;
 
-#if TRACE
 
 static void
 print_derives (void)
@@ -53,7 +53,6 @@ print_derives (void)
   putc ('\n', stderr);
 }
 
-#endif
 
 void
 set_derives (void)
@@ -96,9 +95,8 @@ set_derives (void)
       *q++ = -1;
     }
 
-#if TRACE
-  print_derives ();
-#endif
+  if (trace_flag)
+    print_derives ();
 
   XFREE (dset + ntokens);
   XFREE (delts);
