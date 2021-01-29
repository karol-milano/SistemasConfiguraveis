@@ -31,21 +31,10 @@
 #include "obstack.h"
 #include "print_graph.h"
 #include "vcg.h"
-#include "quotearg.h"
 
 static graph_t graph;
 static FILE *fgraph = NULL;
 
-static size_t node_output_size = 0;
-
-/* Return an unambiguous printable representated, allocated in slot 0,
-   for NAME, suitable for C strings.  */
-static char const *
-quote (char const *name)
-{
-  return quotearg_n_style (0, escape_quoting_style, name);
-}
-
 /* This part will construct the label of nodes. */
 static void
 print_core (int state, struct obstack *node_obstack)
@@ -66,7 +55,7 @@ print_core (int state, struct obstack *node_obstack)
   for (i = 0; i < k; i++)
     {
       if (i)
-	obstack_sgrow (node_obstack, "\\n");
+	obstack_1grow (node_obstack, '\n');
 
       sp1 = sp = ritem + statep->items[i];
 
@@ -77,22 +66,26 @@ print_core (int state, struct obstack *node_obstack)
 
       obstack_fgrow1 (node_obstack, "%d: ", rule);
       obstack_fgrow1 (node_obstack, " %s  ->  ",
-		      quote (tags[rule_table[rule].lhs]));
+		      tags[rule_table[rule].lhs]);
 
       for (sp = ritem + rule_table[rule].rhs; sp < sp1; sp++)
-	obstack_fgrow1 (node_obstack, "%s ", quote (tags[*sp]));
+	obstack_fgrow1 (node_obstack, "%s ", tags[*sp]);
 
       obstack_1grow (node_obstack, '.');
 
       while (*sp > 0)
-	obstack_fgrow1 (node_obstack, " %s", quote (tags[*sp++]));
+	obstack_fgrow1 (node_obstack, " %s", tags[*sp++]);
     }
 }
 
-/* Output in graph_obstack edges specifications in incidence with current
-   node.  */
+
+/*---------------------------------------------------------------.
+| Output in graph_obstack edges specifications in incidence with |
+| current node.                                                  |
+`---------------------------------------------------------------*/
+
 static void
-print_actions (int state, const char *node_name, struct obstack *node_obstack)
+print_actions (int state, const char *node_name)
 {
   int i;
   int k;
@@ -111,10 +104,12 @@ print_actions (int state, const char *node_name, struct obstack *node_obstack)
 
   if (!shiftp && !redp)
     {
+#if 0
       if (final_state == state)
 	obstack_sgrow (node_obstack, "$default: accept");
       else
 	obstack_sgrow (node_obstack, "NO ACTIONS");
+#endif
       return;
     }
 
@@ -143,9 +138,7 @@ print_actions (int state, const char *node_name, struct obstack *node_obstack)
 	    sprintf (buff, "%d", state1);
 	    edge.targetname = buff;
 	    edge.color = (symbol == 0) ? red : blue;
-	    /* FIXME: Be aware that quote uses static memory.  The string
-	       must be output immediately (which is the case here). */
-	    edge.label = tags[symbol] ? quote (tags[symbol]) : NULL;
+	    edge.label = tags[symbol];
 	    output_edge (&edge, fgraph);
 	    close_edge (fgraph);
 	  }
@@ -157,6 +150,7 @@ print_actions (int state, const char *node_name, struct obstack *node_obstack)
       k = 0;
     }
 
+#if 0
   if (errp)
     {
       int j, nerrs;
@@ -169,25 +163,29 @@ print_actions (int state, const char *node_name, struct obstack *node_obstack)
 	    continue;
 	  symbol = errp->errs[j];
 	  /* If something has been added in the NODE_OBSTACK after
-	     the declaration of the label, then we need a `\n'.  */
+	     the declaration of the label, then we need a `\n'.
 	  if (obstack_object_size (node_obstack) > node_output_size)
-	    obstack_sgrow (node_obstack, "\\n");
+	    obstack_sgrow (node_obstack, "\n");
+	    */
 	  obstack_fgrow1 (node_obstack, _("%-4s\terror (nonassociative)"),
 			  tags[symbol]);
 	}
       if (j > 0)
-	obstack_sgrow (node_obstack, "\\n");
+	obstack_1grow (node_obstack, '\n');
     }
 
   if (state_table[state].consistent && redp)
     {
       rule = redp->rules[0];
       symbol = rule_table[rule].lhs;
+      /*
       if (obstack_object_size (node_obstack) > node_output_size)
-	obstack_sgrow (node_obstack, "\\n");
+	obstack_sgrow (node_obstack, "\n");
+	*/
       obstack_fgrow2 (node_obstack, _("$default\treduce using rule %d (%s)"),
 		      rule, tags[symbol]);
     }
+#endif
 
   if (i < k)
     {
@@ -204,15 +202,19 @@ print_actions (int state, const char *node_name, struct obstack *node_obstack)
 	  sprintf (buff, "%d", state1);
 	  edge.targetname = buff;
 	  edge.color = red;
-	  edge.label = tags[symbol] ? quote (tags[symbol]) : NULL;
+	  edge.label = tags[symbol];
 	  output_edge (&edge, fgraph);
 	  close_edge (fgraph);
 	}
     }
 }
 
-/* Output in GRAPH_OBSTACK the current node specifications and edges
-   which go out from that node.  */
+
+/*-------------------------------------------------------------.
+| Output in FGRAPH the current node specifications and exiting |
+| edges.                                                       |
+`-------------------------------------------------------------*/
+
 static void
 print_state (int state)
 {
@@ -220,35 +222,22 @@ print_state (int state)
   struct obstack node_obstack;
   node_t node;
 
+  /* The labels of the nodes are their the items.  */
   obstack_init (&node_obstack);
-  new_node (&node);	/* Set node attributs default value.  */
+  new_node (&node);
   sprintf (name, "%d", state);
-  node.title = name;	/* Give a name to the node.  */
-
-  {
-    /* Here we begin to compute the node label. */
-    obstack_sgrow (&node_obstack, "\t\tlabel:\t\"");	/* Open Label  */
-
-    /* Keep the size of NODE_OBSTACK before computing the label. It is
-       useful to format the label.  */
-    node_output_size = obstack_object_size (&node_obstack);
-
-    /* Compute the labels of nodes on the fly.  */
-    print_core (state, &node_obstack);
-    /* Compute edges and additionnal parts of node label.  */
-    print_actions (state, node.title, &node_obstack);
-
-    obstack_sgrow (&node_obstack, "\"\n");		/* Close Label.  */
-  }
+  node.title = name;
+  print_core (state, &node_obstack);
+  obstack_1grow (&node_obstack, '\0');
+  node.label = obstack_finish (&node_obstack);
 
   open_node (fgraph);
-  /* Output a VCG formatted attributs list.  */
   output_node (&node, fgraph);
-  /* Save the node label.  */
-  fwrite (obstack_base (&node_obstack),
-	  obstack_object_size (&node_obstack), 1, fgraph);
   close_node (fgraph);
 
+  /* Output the edges.  */
+  print_actions (state, name);
+
   obstack_free (&node_obstack, 0);
 }
 
@@ -286,8 +275,8 @@ print_graph (void)
   open_graph (fgraph);
   output_graph (&graph, fgraph);
 
+  /* Output nodes and edges. */
   for (i = 0; i < nstates; i++)
-    /* Output nodes & edges. */
     print_state (i);
 
   /* Close graph. */
