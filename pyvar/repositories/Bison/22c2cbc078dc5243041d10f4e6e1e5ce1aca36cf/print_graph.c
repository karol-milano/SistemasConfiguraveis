@@ -1,5 +1,5 @@
-/* Output a VCG description on generated parser, for bison,
-   Copyright 1984, 1986, 1989, 2000, 2001 Free Software Foundation, Inc.
+/* Output a VCG description on generated parser, for Bison,
+   Copyright 2001 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -45,13 +45,13 @@ print_core (int state)
   core *statep;
   short *sp;
   short *sp1;
-  
+
   statep = state_table[state];
   k = statep->nitems;
 
   if (k == 0)
     return;
-  
+
   obstack_sgrow(&graph_obstack, "\t\tlabel:\t\"");
 
   for (i = 0; i < k; i++)
@@ -64,16 +64,16 @@ print_core (int state)
       rule = -(*sp);
 
       obstack_fgrow1(&graph_obstack, _("%d: "), rule);
-      obstack_fgrow1(&graph_obstack, " %s  ->  ", tags[rlhs[rule]]);  
+      obstack_fgrow1(&graph_obstack, " %s  ->  ", tags[rlhs[rule]]);
 
       for (sp = ritem + rrhs[rule]; sp < sp1; sp++)
 	obstack_fgrow1(&graph_obstack, "%s ", tags[*sp]);
 
       obstack_1grow(&graph_obstack, '.');
-  
+
       while (*sp > 0)
 	obstack_fgrow1(&graph_obstack, " %s", tags[*sp++]);
-      
+
       obstack_sgrow(&graph_obstack, "\\n");
     }
   obstack_sgrow(&graph_obstack, "\"\n");
@@ -92,7 +92,7 @@ print_actions (int state, node_t *node)
   int rule;
   static char buff[10];
   edge_t edge;
-  
+
   shiftp = shift_table[state];
   redp = reduction_table[state];
   errp = err_table[state];
@@ -119,7 +119,7 @@ print_actions (int state, node_t *node)
 
 	  if (ISVAR (symbol))
 	    break;
-	  
+
 	  {
 	    new_edge (&edge);
 
@@ -129,11 +129,11 @@ print_actions (int state, node_t *node)
 	    edge.sourcename = node->title;
 	    edge.targetname = buff;
 	    sprintf (edge.targetname, "%d", state1);
-	    edge.color = (symbol == 0) ? blue : red; 
+	    edge.color = (symbol == 0) ? blue : red;
 	    edge.label = tags[symbol];
-	    output_edge (&edge, &graph_obstack);    
+	    output_edge (&edge, &graph_obstack);
 	    close_edge (&graph_obstack);
-	  }	
+	  }
 	}
     }
   else
@@ -155,13 +155,13 @@ print_actions (int state, node_t *node)
 	  symbol = errp->errs[j];
 	}
     }
-  
+
   if (consistent[state] && redp)
     {
       rule = redp->rules[0];
       symbol = rlhs[rule];
     }
-  
+
   if (i < k)
     {
       for (; i < k; i++)
@@ -188,19 +188,19 @@ static void
 print_state (int state)
 {
   static char name[10];
-  node_t node;  
+  node_t node;
 
   new_node (&node);
   open_node (&graph_obstack);
-  
+
   sprintf(name, "%d", state);
-  node.title = name;  
+  node.title = name;
   output_node (&node, &graph_obstack);
-  
+
   print_core (state);   /* node label */
-  
+
   close_node (&graph_obstack);
-  
+
   print_actions (state, &node);	/* edges */
 }
 
@@ -209,23 +209,23 @@ void
 print_graph (void)
 {
   int i;
-  
+
   if (!graph_flag)
     return ;
   new_graph (&graph);
-  
+
   /* graph.smanhattan_edges = yes;
      graph.manhattan_edges = yes; */
-  
+
   graph.display_edge_labels = yes;
   graph.layoutalgorithm = 0;
-  
+
   graph.port_sharing = no;
   graph.finetuning = yes;
   graph.straight_phase = yes;
   graph.priority_phase = yes;
   graph.splines = yes;
-  
+
   graph.crossing_weight = median;
 
   /* Output graph options. */
@@ -239,4 +239,3 @@ print_graph (void)
   /* Close graph. */
   close_graph (&graph, &graph_obstack);
 }
-
