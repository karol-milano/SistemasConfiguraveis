@@ -27,6 +27,7 @@
 
 #include "closure.h"
 #include "complain.h"
+#include "getargs.h"
 #include "gram.h"
 #include "print-xml.h"
 
@@ -197,6 +198,18 @@ state_transitions_set (state *s, int num, state **dst)
 {
   aver (!s->transitions);
   s->transitions = transitions_new (num, dst);
+  if (trace_flag & trace_automaton)
+    {
+      const transitions *trans = s->transitions;
+      fprintf (stderr, "transitions of %d (%d):\n",
+               s->number, trans->num);
+      for (int i = 0; i < trans->num; ++i)
+        fprintf (stderr, "  %d: (%d, %s, %d)\n",
+                 i,
+                 s->number,
+                 symbols[s->transitions->states[i]->accessing_symbol]->tag,
+                 s->transitions->states[i]->number);
+    }
 }
 
 
