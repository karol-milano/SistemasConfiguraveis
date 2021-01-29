@@ -24,6 +24,7 @@
    tokens they accept.  */
 
 #include "system.h"
+#include "reader.h"
 #include "types.h"
 #include "LR0.h"
 #include "gram.h"
@@ -546,6 +547,31 @@ initialize_lookaheads (void)
     }
 }
 
+
+/*---------------------------------------.
+| Output the lookaheads for each state.  |
+`---------------------------------------*/
+
+static void
+lookaheads_print (FILE *out)
+{
+  int i, j, k;
+  fprintf (out, "Lookaheads: BEGIN\n");
+  for (i = 0; i < nstates; ++i)
+    {
+      fprintf (out, "State %d: %d lookaheads\n",
+	       i, state_table[i]->nlookaheads);
+
+      for (j = 0; j < state_table[i]->nlookaheads; ++j)
+	for (k = 0; k < ntokens; ++k)
+	  if (BITISSET (LA (state_table[i]->lookaheadsp + j), j))
+	    fprintf (out, "   on %d (%s) -> rule %d\n",
+		     k, tags[k],
+		     -LAruleno[state_table[i]->lookaheadsp + j] - 1);
+    }
+  fprintf (out, "Lookaheads: END\n");
+}
+
 void
 lalr (void)
 {
@@ -558,4 +584,7 @@ lalr (void)
   build_relations ();
   compute_FOLLOWS ();
   compute_lookaheads ();
+
+  if (trace_flag)
+    lookaheads_print (stderr);
 }
