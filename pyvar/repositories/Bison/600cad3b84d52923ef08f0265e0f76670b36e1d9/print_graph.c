@@ -36,6 +36,8 @@
 
 static graph_t graph;
 
+static unsigned node_output_size = 0;
+
 /* Return an unambiguous printable representated, allocated in slot 0,
    for NAME, suitable for C strings.  */
 static char const *
@@ -46,7 +48,7 @@ quote (char const *name)
 
 /* This part will construct the label of nodes. */
 static void
-print_core (int state)
+print_core (int state, struct obstack *node_obstack)
 {
   int i;
   int k;
@@ -61,12 +63,10 @@ print_core (int state)
   if (k == 0)
     return;
 
-  obstack_sgrow (&graph_obstack, "\t\tlabel:\t\"");
-
   for (i = 0; i < k; i++)
     {
       if (i)
-	obstack_sgrow (&graph_obstack, "\\n");
+	obstack_sgrow (node_obstack, "\\n");
 
       sp1 = sp = ritem + statep->items[i];
 
@@ -75,23 +75,23 @@ print_core (int state)
 
       rule = -(*sp);
 
-      obstack_fgrow1 (&graph_obstack, "%d: ", rule);
-      obstack_fgrow1 (&graph_obstack, " %s  ->  ", quote (tags[rlhs[rule]]));
+      obstack_fgrow1 (node_obstack, "%d: ", rule);
+      obstack_fgrow1 (node_obstack, " %s  ->  ", quote (tags[rlhs[rule]]));
 
       for (sp = ritem + rrhs[rule]; sp < sp1; sp++)
-	obstack_fgrow1 (&graph_obstack, "%s ", quote (tags[*sp]));
+	obstack_fgrow1 (node_obstack, "%s ", quote (tags[*sp]));
 
-      obstack_1grow (&graph_obstack, '.');
+      obstack_1grow (node_obstack, '.');
 
       while (*sp > 0)
-	obstack_fgrow1 (&graph_obstack, " %s", quote (tags[*sp++]));
-
+	obstack_fgrow1 (node_obstack, " %s", quote (tags[*sp++]));
     }
-  obstack_sgrow (&graph_obstack, "\"\n");
 }
 
+/* Output in graph_obstack edges specifications in incidence with current 
+   node.  */
 static void
-print_actions (int state, node_t *node)
+print_actions (int state, const char *node_name, struct obstack *node_obstack)
 {
   int i;
   int k;
@@ -110,12 +110,10 @@ print_actions (int state, node_t *node)
 
   if (!shiftp && !redp)
     {
-#if 0
       if (final_state == state)
-	fprintf (f, "    $default\taccept\n");
+	obstack_sgrow (node_obstack, "$default: accept");
       else
-	fprintf (f, "    NO ACTIONS\n");
-#endif
+	obstack_sgrow (node_obstack, "NO ACTIONS");
       return;
     }
 
@@ -139,10 +137,11 @@ print_actions (int state, node_t *node)
 	    if (state > state1)
 	      edge.type = back_edge;
 	    open_edge (&edge, &graph_obstack);
-	    edge.sourcename = node->title;
+	    /* The edge source is the current node.  */
+	    edge.sourcename = node_name;
 	    sprintf (buff, "%d", state1);
 	    edge.targetname = buff;
-	    edge.color = (symbol == 0) ? blue : red;
+	    edge.color = (symbol == 0) ? red : blue;
 	    /* FIXME: Be aware that quote uses static memory.  The string
 	       must be output immediately (which is the case here). */
 	    edge.label = tags[symbol] ? quote (tags[symbol]) : NULL;
@@ -168,13 +167,25 @@ print_actions (int state, node_t *node)
 	  if (!errp->errs[j])
 	    continue;
 	  symbol = errp->errs[j];
+	  /* If something has been added in the NODE_OBSTACK after
+	     the declaration of the label, then we need a `\n'.  */
+	  if (obstack_object_size (node_obstack) > node_output_size)
+	    obstack_sgrow (node_obstack, "\\n");
+	  obstack_fgrow1 (node_obstack, _("%-4s\terror (nonassociative)"),
+			  tags[symbol]);
 	}
+      if (j > 0)
+	obstack_sgrow (node_obstack, "\\n");
     }
 
   if (consistent[state] && redp)
     {
       rule = redp->rules[0];
       symbol = rlhs[rule];
+      if (obstack_object_size (node_obstack) > node_output_size)
+	obstack_sgrow (node_obstack, "\\n");
+      obstack_fgrow2 (node_obstack, _("$default\treduce using rule %d (%s)"),
+		      rule, tags[symbol]);
     }
 
   if (i < k)
@@ -188,7 +199,7 @@ print_actions (int state, node_t *node)
 
 	  new_edge (&edge);
 	  open_edge (&edge, &graph_obstack);
-	  edge.sourcename = node->title;
+	  edge.sourcename = node_name;
 	  sprintf (buff, "%d", state1);
 	  edge.targetname = buff;
 	  edge.color = red;
@@ -199,24 +210,46 @@ print_actions (int state, node_t *node)
     }
 }
 
+/* Output in GRAPH_OBSTACK the current node specifications and edges 
+   which go out from that node.  */
 static void
 print_state (int state)
 {
   static char name[10];
+  struct obstack node_obstack;
   node_t node;
 
-  new_node (&node);
-  open_node (&graph_obstack);
-
+  obstack_init (&node_obstack);
+  new_node (&node);	/* Set node attributs default value.  */
   sprintf (name, "%d", state);
-  node.title = name;
-  output_node (&node, &graph_obstack);
-
-  print_core (state);		/* node label */
-
-  close_node (&graph_obstack);
-
-  print_actions (state, &node);	/* edges */
+  node.title = name;	/* Give a name to the node.  */
+  open_node (&node_obstack);
+  /* Output a VCG formatted attributs list.  */
+  output_node (&node, &node_obstack);
+  
+  { 
+    /* Here we begin to compute the node label. */  
+    obstack_sgrow (&node_obstack, "\t\tlabel:\t\"");	/* Open Label  */
+    
+    /* Keep the size of NODE_OBSTACK before computing the label. It is 
+       useful to format the label.  */
+    node_output_size = obstack_object_size (&node_obstack);
+    
+    /* Compute the labels of nodes on the fly.  */
+    print_core (state, &node_obstack);
+    /* Compute edges and additionnal parts of node label.  */
+    print_actions (state, node.title, &node_obstack);
+    
+    obstack_sgrow (&node_obstack, "\"\n");		/* Close Label.  */
+    
+    close_node (&node_obstack);
+  }
+  
+  /* `obstack_cat' NODE_OBSTACK to GRAPH_OBSTACK.  */
+  obstack_grow (&graph_obstack, 
+		obstack_base (&node_obstack), 
+		obstack_object_size (&node_obstack));
+  obstack_finish (&node_obstack);
 }
 
 
@@ -229,8 +262,10 @@ print_graph (void)
     return;
   new_graph (&graph);
 
-  /* graph.smanhattan_edges = yes;
-     graph.manhattan_edges = yes; */
+#if 0
+  graph.smanhattan_edges = yes;
+  graph.manhattan_edges = yes; 
+#endif
 
   graph.display_edge_labels = yes;
   graph.layoutalgorithm = 0;
