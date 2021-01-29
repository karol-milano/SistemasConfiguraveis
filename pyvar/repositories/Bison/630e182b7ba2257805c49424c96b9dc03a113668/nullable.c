@@ -28,6 +28,7 @@
 #include "reader.h"
 #include "types.h"
 #include "gram.h"
+#include "reduce.h"
 #include "nullable.h"
 
 char *nullable = NULL;
@@ -64,11 +65,14 @@ set_nullable (void)
   s1 = s2 = squeue;
 
   rcount = XCALLOC (short, nrules + 1);
-  rsets = XCALLOC (shorts *, nvars) - ntokens;
+
+  /* RITEM contains all the rules, including useless productions.
+     Hence we must allocate room for useless nonterminals too.  */
+  rsets = XCALLOC (shorts *, nvars + nuseless_nonterminals) - ntokens;
   /* This is said to be more elements than we actually use.
      Supposedly nitems - nrules is enough.
      But why take the risk?  */
-  relts = XCALLOC (shorts, nitems + nvars + 1);
+  relts = XCALLOC (shorts, nitems + nvars + nuseless_nonterminals + 1);
   p = relts;
 
   for (r = ritem; *r; ++r)
