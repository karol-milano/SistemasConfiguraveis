@@ -21,6 +21,7 @@
 #include "system.h"
 #include "quotearg.h"
 #include "files.h"
+#include "symtab.h"
 #include "gram.h"
 #include "LR0.h"
 #include "lalr.h"
@@ -77,15 +78,15 @@ print_core (state_t *state, struct obstack *node_obstack)
       if (i)
 	obstack_1grow (node_obstack, '\n');
       obstack_fgrow1 (node_obstack, " %s -> ",
-		      escape (tags[rule_table[rule].lhs]));
+		      escape (symbols[rule_table[rule].lhs]->tag));
 
       for (sp = ritem + rule_table[rule].rhs; sp < sp1; sp++)
-	obstack_fgrow1 (node_obstack, "%s ", escape (tags[*sp]));
+	obstack_fgrow1 (node_obstack, "%s ", escape (symbols[*sp]->tag));
 
       obstack_1grow (node_obstack, '.');
 
       for (/* Nothing */; *sp >= 0; ++sp)
-	obstack_fgrow1 (node_obstack, " %s", escape (tags[*sp]));
+	obstack_fgrow1 (node_obstack, " %s", escape (symbols[*sp]->tag));
     }
 }
 
@@ -129,7 +130,7 @@ print_actions (state_t *state, const char *node_name)
 	  edge.color = red;
 	else
 	  edge.color = SHIFT_IS_SHIFT(shiftp, i) ? blue : green;
-	edge.label = escape (tags[symbol]);
+	edge.label = escape (symbols[symbol]->tag);
 	output_edge (&edge, fgraph);
 	close_edge (fgraph);
       }
