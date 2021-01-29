@@ -28,6 +28,7 @@
 #include "getargs.h"
 #include "state.h"
 #include "reader.h"
+#include "closure.h"
 #include "obstack.h"
 #include "print_graph.h"
 #include "vcg.h"
@@ -40,18 +41,22 @@ static void
 print_core (int state, struct obstack *node_obstack)
 {
   int i;
-  state_t *statep = state_table[state];
+  short *sitems = state_table[state]->items;
+  int snitems   = state_table[state]->nitems;
 
-  if (!statep->nitems)
-    return;
+  /* Output all the items of a state, not only its kernel.  */
+  closure (sitems, snitems);
+  sitems = itemset;
+  snitems = nitemset;
 
-  for (i = 0; i < statep->nitems; i++)
+  obstack_fgrow1 (node_obstack, "%2d: ", state);
+  for (i = 0; i < snitems; i++)
     {
       short *sp;
       short *sp1;
       int rule;
 
-      sp1 = sp = ritem + statep->items[i];
+      sp1 = sp = ritem + sitems[i];
 
       while (*sp > 0)
 	sp++;
@@ -59,8 +64,7 @@ print_core (int state, struct obstack *node_obstack)
       rule = -(*sp);
 
       if (i)
-	obstack_1grow (node_obstack, '\n');
-      obstack_fgrow1 (node_obstack, "%d: ", rule);
+	obstack_sgrow (node_obstack, "\n    ");
       obstack_fgrow1 (node_obstack, " %s  ->  ",
 		      tags[rule_table[rule].lhs]);
 
@@ -120,7 +124,8 @@ print_actions (int state, const char *node_name)
 	edge.sourcename = node_name;
 	sprintf (buff, "%d", state1);
 	edge.targetname = buff;
-	edge.color = (symbol == 0) ? red : blue;
+	/* Shifts are blue, gotos are red. */
+	edge.color = SHIFT_IS_SHIFT(shiftp, i) ? blue : red;
 	edge.label = tags[symbol];
 	output_edge (&edge, fgraph);
 	close_edge (fgraph);
@@ -162,24 +167,6 @@ print_actions (int state, const char *node_name)
 		      rule, tags[symbol]);
     }
 #endif
-
-  if (i < shiftp->nshifts)
-    for (; i < shiftp->nshifts; i++)
-      if (!SHIFT_IS_DISABLED (shiftp, i))
-	{
-	  int state1 = shiftp->shifts[i];
-	  int symbol = state_table[state1]->accessing_symbol;
-
-	  new_edge (&edge);
-	  open_edge (&edge, fgraph);
-	  edge.sourcename = node_name;
-	  sprintf (buff, "%d", state1);
-	  edge.targetname = buff;
-	  edge.color = red;
-	  edge.label = tags[symbol];
-	  output_edge (&edge, fgraph);
-	  close_edge (fgraph);
-	}
 }
 
 
@@ -249,8 +236,10 @@ print_graph (void)
   output_graph (&graph, fgraph);
 
   /* Output nodes and edges. */
+  new_closure (nitems);
   for (i = 0; i < nstates; i++)
     print_state (i);
+  free_closure ();
 
   /* Close graph. */
   close_graph (&graph, fgraph);
