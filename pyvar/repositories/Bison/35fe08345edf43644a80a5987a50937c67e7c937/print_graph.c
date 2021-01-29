@@ -1,6 +1,7 @@
-/* Output a VCG description on generated parser, for Bison,
+/* Output a graph of the generated parser, for Bison.
 
-   Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006 Free Software
+   Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -31,15 +32,12 @@
 #include "files.h"
 #include "getargs.h"
 #include "gram.h"
+#include "graphviz.h"
 #include "lalr.h"
 #include "print_graph.h"
 #include "reader.h"
 #include "state.h"
 #include "symtab.h"
-#include "vcg.h"
-
-static graph static_graph;
-static FILE *fgraph = NULL;
 
 
 /*----------------------------.
@@ -61,7 +59,7 @@ print_core (struct obstack *oout, state *s)
       snritems = nritemset;
     }
 
-  obstack_fgrow1 (oout, "state %2d\n", s->number);
+  obstack_fgrow1 (oout, "%d", s->number);
   for (i = 0; i < snritems; i++)
     {
       item_number *sp;
@@ -75,10 +73,7 @@ print_core (struct obstack *oout, state *s)
 
       r = item_number_as_rule_number (*sp);
 
-      if (i)
-	obstack_1grow (oout, '\n');
-      obstack_fgrow1 (oout, " %s -> ",
-		      rules[r].lhs->tag);
+      obstack_fgrow1 (oout, "\n%s -> ", rules[r].lhs->tag);
 
       for (sp = rules[r].rhs; sp < sp1; sp++)
 	obstack_fgrow1 (oout, "%s ", symbols[*sp]->tag);
@@ -120,17 +115,13 @@ print_core (struct obstack *oout, state *s)
 `---------------------------------------------------------------*/
 
 static void
-print_actions (state *s, const char *node_name)
+print_actions (state const *s, FILE *fgraph)
 {
   int i;
 
-  transitions *trans = s->transitions;
-  reductions *reds = s->reductions;
-
-  static char buff[10];
-  edge e;
+  transitions const *trans = s->transitions;
 
-  if (!trans->num && !reds)
+  if (!trans->num && !s->reductions)
     return;
 
   for (i = 0; i < trans->num; i++)
@@ -139,23 +130,18 @@ print_actions (state *s, const char *node_name)
 	state *s1 = trans->states[i];
 	symbol_number sym = s1->accessing_symbol;
 
-	new_edge (&e);
-
-	if (s->number > s1->number)
-	  e.type = back_edge;
-	open_edge (&e, fgraph);
-	/* The edge source is the current node.  */
-	e.sourcename = node_name;
-	sprintf (buff, "%d", s1->number);
-	e.targetname = buff;
-	/* Shifts are blue, gotos are green, and error is red. */
-	if (TRANSITION_IS_ERROR (trans, i))
-	  e.color = red;
-	else
-	  e.color = TRANSITION_IS_SHIFT (trans, i) ? blue : green;
-	e.label = symbols[sym]->tag;
-	output_edge (&e, fgraph);
-	close_edge (fgraph);
+	/* Shifts are solid, gotos are dashed, and error is dotted.  */
+	char const *style =
+	  (TRANSITION_IS_ERROR (trans, i) ? "dotted"
+	   : TRANSITION_IS_SHIFT (trans, i) ? "solid"
+	   : "dashed");
+
+	if (TRANSITION_IS_ERROR (trans, i)
+	    && strcmp (symbols[sym]->tag, "error") != 0)
+	  abort ();
+	output_edge (s->number, s1->number,
+		     TRANSITION_IS_ERROR (trans, i) ? NULL : symbols[sym]->tag,
+		     style, fgraph);
       }
 }
 
@@ -166,29 +152,19 @@ print_actions (state *s, const char *node_name)
 `-------------------------------------------------------------*/
 
 static void
-print_state (state *s)
+print_state (state *s, FILE *fgraph)
 {
-  static char name[10];
   struct obstack node_obstack;
-  node n;
 
-  /* The labels of the nodes are their the items.  */
+  /* A node's label contains its items.  */
   obstack_init (&node_obstack);
-  new_node (&n);
-  sprintf (name, "%d", s->number);
-  n.title = name;
   print_core (&node_obstack, s);
   obstack_1grow (&node_obstack, '\0');
-  n.label = obstack_finish (&node_obstack);
-
-  open_node (fgraph);
-  output_node (&n, fgraph);
-  close_node (fgraph);
+  output_node (s->number, obstack_finish (&node_obstack), fgraph);
+  obstack_free (&node_obstack, 0);
 
   /* Output the edges.  */
-  print_actions (s, name);
-
-  obstack_free (&node_obstack, 0);
+  print_actions (s, fgraph);
 }
 
 
@@ -196,32 +172,15 @@ void
 print_graph (void)
 {
   state_number i;
-
-  /* Output file.  */
-  fgraph = xfopen (spec_graph_file, "w");
-
-  new_graph (&static_graph);
-
-  static_graph.display_edge_labels = yes;
-
-  static_graph.port_sharing = no;
-  static_graph.finetuning = yes;
-  static_graph.priority_phase = yes;
-  static_graph.splines = yes;
-
-  static_graph.crossing_weight = median;
-
-  /* Output graph options. */
-  open_graph (fgraph);
-  output_graph (&static_graph, fgraph);
+  FILE *fgraph = xfopen (spec_graph_file, "w");
+  start_graph (fgraph);
 
   /* Output nodes and edges. */
   new_closure (nritems);
   for (i = 0; i < nstates; i++)
-    print_state (states[i]);
+    print_state (states[i], fgraph);
   free_closure ();
 
-  /* Close graph. */
-  close_graph (&static_graph, fgraph);
+  finish_graph (fgraph);
   xfclose (fgraph);
 }
