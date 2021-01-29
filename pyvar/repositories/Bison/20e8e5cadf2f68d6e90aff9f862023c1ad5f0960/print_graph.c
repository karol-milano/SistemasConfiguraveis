@@ -32,10 +32,18 @@
 #include "obstack.h"
 #include "print_graph.h"
 #include "vcg.h"
-#include "quote.h"
+#include "quotearg.h"
 
 static graph_t graph;
 
+/* Return an unambiguous printable representated, allocated in slot 0,
+   for NAME, suitable for C strings.  */
+static char const *
+quote (char const *name)
+{
+  return quotearg_n_style (0, escape_quoting_style, name);
+}
+
 /* This part will construct the label of nodes. */
 static void
 print_core (int state)
@@ -67,7 +75,7 @@ print_core (int state)
 
       rule = -(*sp);
 
-      obstack_fgrow1 (&graph_obstack, _("%d: "), rule);
+      obstack_fgrow1 (&graph_obstack, "%d: ", rule);
       obstack_fgrow1 (&graph_obstack, " %s  ->  ", quote (tags[rlhs[rule]]));
 
       for (sp = ritem + rrhs[rule]; sp < sp1; sp++)
