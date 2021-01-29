@@ -20,7 +20,7 @@
 
 #include "system.h"
 #include "getargs.h"
-#include "alloc.h"
+#include "xalloc.h"
 #include "files.h"
 #include "gram.h"
 #include "state.h"
@@ -95,7 +95,7 @@ resolve_sr_conflict (int state, int lookaheadnum)
   unsigned *fp1;
   unsigned *fp2;
   int redprec;
-  errs *errp = (errs *) xmalloc (sizeof (errs) + ntokens * sizeof (short));
+  errs *errp = (errs *) xcalloc (sizeof (errs) + ntokens * sizeof (short), 1);
   short *errtokens = errp->errs;
 
   /* find the rule to reduce by to get precedence of reduction  */
@@ -175,7 +175,7 @@ resolve_sr_conflict (int state, int lookaheadnum)
       /* Some tokens have been explicitly made errors.  Allocate
          a permanent errs structure for this state, to record them.  */
       i = (char *) errtokens - (char *) errp;
-      err_table[state] = (errs *) xmalloc ((unsigned int) i);
+      err_table[state] = (errs *) xcalloc ((unsigned int) i, 1);
       bcopy (errp, err_table[state], i);
     }
   else
@@ -269,11 +269,11 @@ initialize_conflicts (void)
 {
   int i;
 
-  conflicts = NEW2 (nstates, char);
-  shiftset = NEW2 (tokensetsize, unsigned);
-  lookaheadset = NEW2 (tokensetsize, unsigned);
+  conflicts = XCALLOC (char, nstates);
+  shiftset = XCALLOC (unsigned, tokensetsize);
+  lookaheadset = XCALLOC (unsigned, tokensetsize);
 
-  err_table = NEW2 (nstates, errs *);
+  err_table = XCALLOC (errs *, nstates);
 
   any_conflicts = 0;
 
@@ -718,7 +718,7 @@ print_reductions (int state)
 void
 finalize_conflicts (void)
 {
-  FREE (conflicts);
-  FREE (shiftset);
-  FREE (lookaheadset);
+  XFREE (conflicts);
+  XFREE (shiftset);
+  XFREE (lookaheadset);
 }
