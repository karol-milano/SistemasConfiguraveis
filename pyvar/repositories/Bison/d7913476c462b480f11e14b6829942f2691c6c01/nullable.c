@@ -26,7 +26,7 @@
 #include "system.h"
 #include "types.h"
 #include "gram.h"
-#include "alloc.h"
+#include "xalloc.h"
 #include "nullable.h"
 
 char *nullable = NULL;
@@ -52,17 +52,17 @@ set_nullable (void)
   fprintf (stderr, _("Entering set_nullable"));
 #endif
 
-  nullable = NEW2 (nvars, char) - ntokens;
+  nullable = XCALLOC (char, nvars) - ntokens;
 
-  squeue = NEW2 (nvars, short);
+  squeue = XCALLOC (short, nvars);
   s1 = s2 = squeue;
 
-  rcount = NEW2 (nrules + 1, short);
-  rsets = NEW2 (nvars, shorts *) - ntokens;
+  rcount = XCALLOC (short, nrules + 1);
+  rsets = XCALLOC (shorts *, nvars) - ntokens;
   /* This is said to be more elements than we actually use.
      Supposedly nitems - nrules is enough.
      But why take the risk?  */
-  relts = NEW2 (nitems + nvars + 1, shorts);
+  relts = XCALLOC (shorts, nitems + nvars + 1);
   p = relts;
 
   r = ritem;
@@ -122,15 +122,15 @@ set_nullable (void)
 	}
     }
 
-  FREE (squeue);
-  FREE (rcount);
-  FREE (rsets + ntokens);
-  FREE (relts);
+  XFREE (squeue);
+  XFREE (rcount);
+  XFREE (rsets + ntokens);
+  XFREE (relts);
 }
 
 
 void
 free_nullable (void)
 {
-  FREE (nullable + ntokens);
+  XFREE (nullable + ntokens);
 }
