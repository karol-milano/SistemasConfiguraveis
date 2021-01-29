@@ -19,13 +19,14 @@
 
 #include <config.h>
 
+#include "parse-simulation.h"
+
 #include <gl_linked_list.h>
 #include <gl_xlist.h>
 #include <stdlib.h>
 
 #include "lssi.h"
 #include "nullable.h"
-#include "parse-simulation.h"
 
 typedef struct parse_state
 {
@@ -595,9 +596,9 @@ print_parse_state (parse_state *ps)
   FILE *out = stderr;
   fprintf (out, "(size %zu depth %d rc %d)\n",
           ps->state_items.total_size, ps->depth, ps->reference_count);
-  print_state_item (ps->state_items.head_elt, out);
-  print_state_item (ps->state_items.tail_elt, out);
+  print_state_item (ps->state_items.head_elt, out, "");
+  print_state_item (ps->state_items.tail_elt, out, "");
   if (ps->derivs.total_size > 0)
-    derivation_print (ps->derivs.head_elt, out);
+    derivation_print (ps->derivs.head_elt, out, "");
   putc ('\n', out);
 }
