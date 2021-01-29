@@ -1,5 +1,6 @@
 /* Output a VCG description on generated parser, for Bison,
-   Copyright 2001 Free Software Foundation, Inc.
+
+   Copyright (C) 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -19,23 +20,25 @@
    Boston, MA 02111-1307, USA.  */
 
 #include "system.h"
-#include "quotearg.h"
-#include "files.h"
-#include "symtab.h"
-#include "gram.h"
+
+#include <obstack.h>
+#include <quotearg.h>
+
 #include "LR0.h"
-#include "lalr.h"
-#include "conflicts.h"
+#include "closure.h"
 #include "complain.h"
+#include "conflicts.h"
+#include "files.h"
 #include "getargs.h"
-#include "state.h"
-#include "reader.h"
-#include "closure.h"
-#include "obstack.h"
+#include "gram.h"
+#include "lalr.h"
 #include "print_graph.h"
+#include "reader.h"
+#include "state.h"
+#include "symtab.h"
 #include "vcg.h"
 
-static graph_t graph;
+static graph static_graph;
 static FILE *fgraph = NULL;
 
 
@@ -44,11 +47,11 @@ static FILE *fgraph = NULL;
 `----------------------------*/
 
 static void
-print_core (struct obstack *oout, state_t *state)
+print_core (struct obstack *oout, state *s)
 {
   int i;
-  item_number_t *sitems = state->items;
-  int snritems   = state->nitems;
+  item_number *sitems = s->items;
+  int snritems = s->nitems;
 
   /* Output all the items of a state, not only its kernel.  */
   if (report_flag & report_itemsets)
@@ -58,26 +61,26 @@ print_core (struct obstack *oout, state_t *state)
       snritems = nritemset;
     }
 
-  obstack_fgrow1 (oout, "state %2d\n", state->number);
+  obstack_fgrow1 (oout, "state %2d\n", s->number);
   for (i = 0; i < snritems; i++)
     {
-      item_number_t *sp;
-      item_number_t *sp1;
-      rule_number_t rule;
+      item_number *sp;
+      item_number *sp1;
+      rule_number r;
 
       sp1 = sp = ritem + sitems[i];
 
       while (*sp >= 0)
 	sp++;
 
-      rule = item_number_as_rule_number (*sp);
+      r = item_number_as_rule_number (*sp);
 
       if (i)
 	obstack_1grow (oout, '\n');
       obstack_fgrow1 (oout, " %s -> ",
-		      rules[rule].lhs->tag);
+		      rules[r].lhs->tag);
 
-      for (sp = rules[rule].rhs; sp < sp1; sp++)
+      for (sp = rules[r].rhs; sp < sp1; sp++)
 	obstack_fgrow1 (oout, "%s ", symbols[*sp]->tag);
 
       obstack_1grow (oout, '.');
@@ -89,8 +92,8 @@ print_core (struct obstack *oout, state_t *state)
       if (report_flag & report_lookaheads)
 	{
 	  /* Find the reduction we are handling.  */
-	  reductions_t *reds = state->reductions;
-	  int redno = state_reduction_find (state, &rules[rule]);
+	  reductions *reds = s->reductions;
+	  int redno = state_reduction_find (s, &rules[r]);
 
 	  /* Print them if there are.  */
 	  if (reds->lookaheads && redno != -1)
@@ -116,41 +119,41 @@ print_core (struct obstack *oout, state_t *state)
 `---------------------------------------------------------------*/
 
 static void
-print_actions (state_t *state, const char *node_name)
+print_actions (state *s, const char *node_name)
 {
   int i;
 
-  transitions_t     *transitions = state->transitions;
-  reductions_t *redp = state->reductions;
+  transitions *trans = s->transitions;
+  reductions *reds = s->reductions;
 
   static char buff[10];
-  edge_t edge;
+  edge e;
 
-  if (!transitions->num && !redp)
+  if (!trans->num && !reds)
     return;
 
-  for (i = 0; i < transitions->num; i++)
-    if (!TRANSITION_IS_DISABLED (transitions, i))
+  for (i = 0; i < trans->num; i++)
+    if (!TRANSITION_IS_DISABLED (trans, i))
       {
-	state_t *state1 = transitions->states[i];
-	symbol_number_t symbol = state1->accessing_symbol;
+	state *s1 = trans->states[i];
+	symbol_number sym = s1->accessing_symbol;
 
-	new_edge (&edge);
+	new_edge (&e);
 
-	if (state->number > state1->number)
-	  edge.type = back_edge;
-	open_edge (&edge, fgraph);
+	if (s->number > s1->number)
+	  e.type = back_edge;
+	open_edge (&e, fgraph);
 	/* The edge source is the current node.  */
-	edge.sourcename = node_name;
-	sprintf (buff, "%d", state1->number);
-	edge.targetname = buff;
+	e.sourcename = node_name;
+	sprintf (buff, "%d", s1->number);
+	e.targetname = buff;
 	/* Shifts are blue, gotos are green, and error is red. */
-	if (TRANSITION_IS_ERROR (transitions, i))
-	  edge.color = red;
+	if (TRANSITION_IS_ERROR (trans, i))
+	  e.color = red;
 	else
-	  edge.color = TRANSITION_IS_SHIFT(transitions, i) ? blue : green;
-	edge.label = symbols[symbol]->tag;
-	output_edge (&edge, fgraph);
+	  e.color = TRANSITION_IS_SHIFT (trans, i) ? blue : green;
+	e.label = symbols[sym]->tag;
+	output_edge (&e, fgraph);
 	close_edge (fgraph);
       }
 }
@@ -162,27 +165,27 @@ print_actions (state_t *state, const char *node_name)
 `-------------------------------------------------------------*/
 
 static void
-print_state (state_t *state)
+print_state (state *s)
 {
   static char name[10];
   struct obstack node_obstack;
-  node_t node;
+  node n;
 
   /* The labels of the nodes are their the items.  */
   obstack_init (&node_obstack);
-  new_node (&node);
-  sprintf (name, "%d", state->number);
-  node.title = name;
-  print_core (&node_obstack, state);
+  new_node (&n);
+  sprintf (name, "%d", s->number);
+  n.title = name;
+  print_core (&node_obstack, s);
   obstack_1grow (&node_obstack, '\0');
-  node.label = obstack_finish (&node_obstack);
+  n.label = obstack_finish (&node_obstack);
 
   open_node (fgraph);
-  output_node (&node, fgraph);
+  output_node (&n, fgraph);
   close_node (fgraph);
 
   /* Output the edges.  */
-  print_actions (state, name);
+  print_actions (s, name);
 
   obstack_free (&node_obstack, 0);
 }
@@ -191,32 +194,32 @@ print_state (state_t *state)
 void
 print_graph (void)
 {
-  state_number_t i;
+  state_number i;
 
   /* Output file.  */
   fgraph = xfopen (spec_graph_file, "w");
 
-  new_graph (&graph);
+  new_graph (&static_graph);
 
 #if 0
-  graph.smanhattan_edges = yes;
-  graph.manhattan_edges = yes;
+  static_graph.smanhattan_edges = yes;
+  static_graph.manhattan_edges = yes;
 #endif
 
-  graph.display_edge_labels = yes;
-  graph.layoutalgorithm = normal;
+  static_graph.display_edge_labels = yes;
+  static_graph.layoutalgorithm = normal;
 
-  graph.port_sharing = no;
-  graph.finetuning = yes;
-  graph.straight_phase = yes;
-  graph.priority_phase = yes;
-  graph.splines = yes;
+  static_graph.port_sharing = no;
+  static_graph.finetuning = yes;
+  static_graph.long_straight_phase = yes;
+  static_graph.priority_phase = yes;
+  static_graph.splines = yes;
 
-  graph.crossing_weight = median;
+  static_graph.crossing_weight = median;
 
   /* Output graph options. */
   open_graph (fgraph);
-  output_graph (&graph, fgraph);
+  output_graph (&static_graph, fgraph);
 
   /* Output nodes and edges. */
   new_closure (nritems);
@@ -225,6 +228,6 @@ print_graph (void)
   free_closure ();
 
   /* Close graph. */
-  close_graph (&graph, fgraph);
+  close_graph (&static_graph, fgraph);
   xfclose (fgraph);
 }
