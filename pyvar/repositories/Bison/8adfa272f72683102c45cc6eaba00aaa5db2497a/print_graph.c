@@ -19,6 +19,7 @@
    Boston, MA 02111-1307, USA.  */
 
 #include "system.h"
+#include "quotearg.h"
 #include "files.h"
 #include "gram.h"
 #include "LR0.h"
@@ -36,6 +37,13 @@
 static graph_t graph;
 static FILE *fgraph = NULL;
 
+static inline const char *
+escape (const char *s)
+{
+  return quotearg_n_style (1, escape_quoting_style, s);
+}
+
+
 /* This part will construct the label of nodes. */
 static void
 print_core (state_t *state, struct obstack *node_obstack)
@@ -49,7 +57,7 @@ print_core (state_t *state, struct obstack *node_obstack)
   sitems = itemset;
   snitems = nitemset;
 
-  obstack_fgrow1 (node_obstack, "%2d: ", state->number);
+  obstack_fgrow1 (node_obstack, "state %2d\n", state->number);
   for (i = 0; i < snitems; i++)
     {
       short *sp;
@@ -64,17 +72,17 @@ print_core (state_t *state, struct obstack *node_obstack)
       rule = -(*sp);
 
       if (i)
-	obstack_sgrow (node_obstack, "\n    ");
+	obstack_1grow (node_obstack, '\n');
       obstack_fgrow1 (node_obstack, " %s -> ",
-		      tags[rule_table[rule].lhs]);
+		      escape (tags[rule_table[rule].lhs]));
 
       for (sp = ritem + rule_table[rule].rhs; sp < sp1; sp++)
-	obstack_fgrow1 (node_obstack, "%s ", tags[*sp]);
+	obstack_fgrow1 (node_obstack, "%s ", escape (tags[*sp]));
 
       obstack_1grow (node_obstack, '.');
 
       for (/* Nothing */; *sp > 0; ++sp)
-	obstack_fgrow1 (node_obstack, " %s", tags[*sp]);
+	obstack_fgrow1 (node_obstack, " %s", escape (tags[*sp]));
     }
 }
 
@@ -113,9 +121,12 @@ print_actions (state_t *state, const char *node_name)
 	edge.sourcename = node_name;
 	sprintf (buff, "%d", state1);
 	edge.targetname = buff;
-	/* Shifts are blue, gotos are red. */
-	edge.color = SHIFT_IS_SHIFT(shiftp, i) ? blue : red;
-	edge.label = tags[symbol];
+	/* Shifts are blue, gotos are green, and error is red. */
+	if (SHIFT_IS_ERROR (shiftp, i))
+	  edge.color = red;
+	else
+	  edge.color = SHIFT_IS_SHIFT(shiftp, i) ? blue : green;
+	edge.label = escape (tags[symbol]);
 	output_edge (&edge, fgraph);
 	close_edge (fgraph);
       }
