@@ -25,7 +25,7 @@
    */
 
 #include "system.h"
-#include "alloc.h"
+#include "xalloc.h"
 #include "types.h"
 #include "gram.h"
 #include "derives.h"
@@ -37,8 +37,8 @@ short **derives;
 static void
 print_derives (void)
 {
-  register int i;
-  register short *sp;
+  int i;
+  short *sp;
 
   printf (_("\n\n\nDERIVES\n\n"));
 
@@ -60,15 +60,15 @@ print_derives (void)
 void
 set_derives (void)
 {
-  register int i;
-  register int lhs;
-  register shorts *p;
-  register short *q;
-  register shorts **dset;
-  register shorts *delts;
+  int i;
+  int lhs;
+  shorts *p;
+  short *q;
+  shorts **dset;
+  shorts *delts;
 
-  dset = NEW2 (nvars, shorts *) - ntokens;
-  delts = NEW2 (nrules + 1, shorts);
+  dset = XCALLOC (shorts *, nvars) - ntokens;
+  delts = XCALLOC (shorts, nrules + 1);
 
   p = delts;
   for (i = nrules; i > 0; i--)
@@ -83,8 +83,8 @@ set_derives (void)
 	}
     }
 
-  derives = NEW2 (nvars, short *) - ntokens;
-  q = NEW2 (nvars + nrules, short);
+  derives = XCALLOC (short *, nvars) - ntokens;
+  q = XCALLOC (short, nvars + nrules);
 
   for (i = ntokens; i < nsyms; i++)
     {
@@ -102,13 +102,13 @@ set_derives (void)
   print_derives ();
 #endif
 
-  FREE (dset + ntokens);
-  FREE (delts);
+  XFREE (dset + ntokens);
+  XFREE (delts);
 }
 
 void
 free_derives (void)
 {
-  FREE (derives[ntokens]);
-  FREE (derives + ntokens);
+  XFREE (derives[ntokens]);
+  XFREE (derives + ntokens);
 }
