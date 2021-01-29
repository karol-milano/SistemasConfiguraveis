@@ -19,7 +19,6 @@
    Boston, MA 02111-1307, USA.  */
 
 #include "system.h"
-#include "xalloc.h"
 #include "files.h"
 #include "gram.h"
 #include "LR0.h"
@@ -35,8 +34,9 @@
 #include "quotearg.h"
 
 static graph_t graph;
+static FILE *fgraph = NULL;
 
-static unsigned node_output_size = 0;
+static size_t node_output_size = 0;
 
 /* Return an unambiguous printable representated, allocated in slot 0,
    for NAME, suitable for C strings.  */
@@ -136,7 +136,7 @@ print_actions (int state, const char *node_name, struct obstack *node_obstack)
 
 	    if (state > state1)
 	      edge.type = back_edge;
-	    open_edge (&edge, &graph_obstack);
+	    open_edge (&edge, fgraph);
 	    /* The edge source is the current node.  */
 	    edge.sourcename = node_name;
 	    sprintf (buff, "%d", state1);
@@ -145,8 +145,8 @@ print_actions (int state, const char *node_name, struct obstack *node_obstack)
 	    /* FIXME: Be aware that quote uses static memory.  The string
 	       must be output immediately (which is the case here). */
 	    edge.label = tags[symbol] ? quote (tags[symbol]) : NULL;
-	    output_edge (&edge, &graph_obstack);
-	    close_edge (&graph_obstack);
+	    output_edge (&edge, fgraph);
+	    close_edge (fgraph);
 	  }
 	}
     }
@@ -198,14 +198,14 @@ print_actions (int state, const char *node_name, struct obstack *node_obstack)
 	  symbol = accessing_symbol[state1];
 
 	  new_edge (&edge);
-	  open_edge (&edge, &graph_obstack);
+	  open_edge (&edge, fgraph);
 	  edge.sourcename = node_name;
 	  sprintf (buff, "%d", state1);
 	  edge.targetname = buff;
 	  edge.color = red;
 	  edge.label = tags[symbol] ? quote (tags[symbol]) : NULL;
-	  output_edge (&edge, &graph_obstack);
-	  close_edge (&graph_obstack);
+	  output_edge (&edge, fgraph);
+	  close_edge (fgraph);
 	}
     }
 }
@@ -223,9 +223,6 @@ print_state (int state)
   new_node (&node);	/* Set node attributs default value.  */
   sprintf (name, "%d", state);
   node.title = name;	/* Give a name to the node.  */
-  open_node (&node_obstack);
-  /* Output a VCG formatted attributs list.  */
-  output_node (&node, &node_obstack);
   
   { 
     /* Here we begin to compute the node label. */  
@@ -241,15 +238,17 @@ print_state (int state)
     print_actions (state, node.title, &node_obstack);
     
     obstack_sgrow (&node_obstack, "\"\n");		/* Close Label.  */
-    
-    close_node (&node_obstack);
-  }
-  
-  /* `obstack_cat' NODE_OBSTACK to GRAPH_OBSTACK.  */
-  obstack_grow (&graph_obstack, 
-		obstack_base (&node_obstack), 
-		obstack_object_size (&node_obstack));
-  obstack_finish (&node_obstack);
+  }    
+
+  open_node (fgraph);
+  /* Output a VCG formatted attributs list.  */
+  output_node (&node, fgraph);
+  /* Save the node label.  */
+  fwrite (obstack_base (&node_obstack), 
+	  obstack_object_size (&node_obstack), 1, fgraph);
+  close_node (fgraph);
+
+  obstack_free (&node_obstack, 0);
 }
 
 
@@ -257,9 +256,13 @@ void
 print_graph (void)
 {
   int i;
-
+  
   if (!graph_flag)
     return;
+
+  /* Output file.  */
+  fgraph = xfopen (spec_graph_file, "w");
+
   new_graph (&graph);
 
 #if 0
@@ -268,7 +271,7 @@ print_graph (void)
 #endif
 
   graph.display_edge_labels = yes;
-  graph.layoutalgorithm = 0;
+  graph.layoutalgorithm = normal;
 
   graph.port_sharing = no;
   graph.finetuning = yes;
@@ -279,13 +282,14 @@ print_graph (void)
   graph.crossing_weight = median;
 
   /* Output graph options. */
-  open_graph (&graph_obstack);
-  output_graph (&graph, &graph_obstack);
+  open_graph (fgraph);
+  output_graph (&graph, fgraph);
 
   for (i = 0; i < nstates; i++)
     /* Output nodes & edges. */
     print_state (i);
 
   /* Close graph. */
-  close_graph (&graph, &graph_obstack);
+  close_graph (&graph, fgraph);
+  xfclose (fgraph);
 }
