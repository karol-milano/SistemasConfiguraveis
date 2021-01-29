@@ -57,7 +57,7 @@ print_core (int state, struct obstack *node_obstack)
   short *sp;
   short *sp1;
 
-  statep = state_table[state];
+  statep = state_table[state].state;
   k = statep->nitems;
 
   if (k == 0)
@@ -88,7 +88,7 @@ print_core (int state, struct obstack *node_obstack)
     }
 }
 
-/* Output in graph_obstack edges specifications in incidence with current 
+/* Output in graph_obstack edges specifications in incidence with current
    node.  */
 static void
 print_actions (int state, const char *node_name, struct obstack *node_obstack)
@@ -126,7 +126,7 @@ print_actions (int state, const char *node_name, struct obstack *node_obstack)
 	  if (!shiftp->shifts[i])
 	    continue;
 	  state1 = shiftp->shifts[i];
-	  symbol = accessing_symbol[state1];
+	  symbol = state_table[state1].accessing_symbol;
 
 	  if (ISVAR (symbol))
 	    break;
@@ -195,7 +195,7 @@ print_actions (int state, const char *node_name, struct obstack *node_obstack)
 	  if (!shiftp->shifts[i])
 	    continue;
 	  state1 = shiftp->shifts[i];
-	  symbol = accessing_symbol[state1];
+	  symbol = state_table[state1].accessing_symbol;
 
 	  new_edge (&edge);
 	  open_edge (&edge, fgraph);
@@ -210,7 +210,7 @@ print_actions (int state, const char *node_name, struct obstack *node_obstack)
     }
 }
 
-/* Output in GRAPH_OBSTACK the current node specifications and edges 
+/* Output in GRAPH_OBSTACK the current node specifications and edges
    which go out from that node.  */
 static void
 print_state (int state)
@@ -223,28 +223,28 @@ print_state (int state)
   new_node (&node);	/* Set node attributs default value.  */
   sprintf (name, "%d", state);
   node.title = name;	/* Give a name to the node.  */
-  
-  { 
-    /* Here we begin to compute the node label. */  
+
+  {
+    /* Here we begin to compute the node label. */
     obstack_sgrow (&node_obstack, "\t\tlabel:\t\"");	/* Open Label  */
-    
-    /* Keep the size of NODE_OBSTACK before computing the label. It is 
+
+    /* Keep the size of NODE_OBSTACK before computing the label. It is
        useful to format the label.  */
     node_output_size = obstack_object_size (&node_obstack);
-    
+
     /* Compute the labels of nodes on the fly.  */
     print_core (state, &node_obstack);
     /* Compute edges and additionnal parts of node label.  */
     print_actions (state, node.title, &node_obstack);
-    
+
     obstack_sgrow (&node_obstack, "\"\n");		/* Close Label.  */
-  }    
+  }
 
   open_node (fgraph);
   /* Output a VCG formatted attributs list.  */
   output_node (&node, fgraph);
   /* Save the node label.  */
-  fwrite (obstack_base (&node_obstack), 
+  fwrite (obstack_base (&node_obstack),
 	  obstack_object_size (&node_obstack), 1, fgraph);
   close_node (fgraph);
 
@@ -256,7 +256,7 @@ void
 print_graph (void)
 {
   int i;
-  
+
   if (!graph_flag)
     return;
 
@@ -267,7 +267,7 @@ print_graph (void)
 
 #if 0
   graph.smanhattan_edges = yes;
-  graph.manhattan_edges = yes; 
+  graph.manhattan_edges = yes;
 #endif
 
   graph.display_edge_labels = yes;
