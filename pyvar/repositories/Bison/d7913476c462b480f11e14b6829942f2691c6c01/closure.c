@@ -19,10 +19,11 @@
    02111-1307, USA.  */
 
 #include "system.h"
-#include "alloc.h"
+#include "xalloc.h"
 #include "gram.h"
 #include "closure.h"
 #include "derives.h"
+#include "warshall.h"
 
 short *itemset;
 short *itemsetend;
@@ -122,7 +123,7 @@ set_firsts (void)
 
   varsetsize = rowsize = WORDSIZE (nvars);
 
-  firsts = NEW2 (nvars * rowsize, unsigned);
+  firsts = XCALLOC (unsigned, nvars * rowsize);
 
   row = firsts;
   for (i = ntokens; i < nsyms; i++)
@@ -171,7 +172,7 @@ set_fderives (void)
   int ruleno;
   int i;
 
-  fderives = NEW2 (nvars * rulesetsize, unsigned) - ntokens * rulesetsize;
+  fderives = XCALLOC (unsigned, nvars * rulesetsize) - ntokens * rulesetsize;
 
   set_firsts ();
 
@@ -208,17 +209,17 @@ set_fderives (void)
   print_fderives ();
 #endif
 
-  FREE (firsts);
+  XFREE (firsts);
 }
 
 
 void
 new_closure (int n)
 {
-  itemset = NEW2 (n, short);
+  itemset = XCALLOC (short, n);
 
   rulesetsize = WORDSIZE (nrules + 1);
-  ruleset = NEW2 (rulesetsize, unsigned);
+  ruleset = XCALLOC (unsigned, rulesetsize);
 
   set_fderives ();
 }
@@ -310,7 +311,7 @@ closure (short *core, int n)
 void
 free_closure (void)
 {
-  FREE (itemset);
-  FREE (ruleset);
-  FREE (fderives + ntokens * rulesetsize);
+  XFREE (itemset);
+  XFREE (ruleset);
+  XFREE (fderives + ntokens * rulesetsize);
 }
