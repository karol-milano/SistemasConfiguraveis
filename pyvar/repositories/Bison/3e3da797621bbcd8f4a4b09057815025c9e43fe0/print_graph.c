@@ -52,7 +52,7 @@ print_core (int state)
   if (k == 0)
     return;
 
-  obstack_sgrow(&graph_obstack, "\t\tlabel:\t\"");
+  obstack_sgrow (&graph_obstack, "\t\tlabel:\t\"");
 
   for (i = 0; i < k; i++)
     {
@@ -63,20 +63,20 @@ print_core (int state)
 
       rule = -(*sp);
 
-      obstack_fgrow1(&graph_obstack, _("%d: "), rule);
-      obstack_fgrow1(&graph_obstack, " %s  ->  ", tags[rlhs[rule]]);
+      obstack_fgrow1 (&graph_obstack, _("%d: "), rule);
+      obstack_fgrow1 (&graph_obstack, " %s  ->  ", tags[rlhs[rule]]);
 
       for (sp = ritem + rrhs[rule]; sp < sp1; sp++)
-	obstack_fgrow1(&graph_obstack, "%s ", tags[*sp]);
+	obstack_fgrow1 (&graph_obstack, "%s ", tags[*sp]);
 
-      obstack_1grow(&graph_obstack, '.');
+      obstack_1grow (&graph_obstack, '.');
 
       while (*sp > 0)
-	obstack_fgrow1(&graph_obstack, " %s", tags[*sp++]);
+	obstack_fgrow1 (&graph_obstack, " %s", tags[*sp++]);
 
-      obstack_sgrow(&graph_obstack, "\\n");
+      obstack_sgrow (&graph_obstack, "\\n");
     }
-  obstack_sgrow(&graph_obstack, "\"\n");
+  obstack_sgrow (&graph_obstack, "\"\n");
 }
 
 static void
@@ -99,10 +99,12 @@ print_actions (int state, node_t *node)
 
   if (!shiftp && !redp)
     {
+#if 0
       if (final_state == state)
-	;//fprintf(f, "    $default\taccept\n");
+	fprintf (f, "    $default\taccept\n");
       else
-	;//fprintf(f, "    NO ACTIONS\n");
+	fprintf (f, "    NO ACTIONS\n");
+#endif
       return;
     }
 
@@ -193,11 +195,11 @@ print_state (int state)
   new_node (&node);
   open_node (&graph_obstack);
 
-  sprintf(name, "%d", state);
+  sprintf (name, "%d", state);
   node.title = name;
   output_node (&node, &graph_obstack);
 
-  print_core (state);   /* node label */
+  print_core (state);		/* node label */
 
   close_node (&graph_obstack);
 
@@ -211,7 +213,7 @@ print_graph (void)
   int i;
 
   if (!graph_flag)
-    return ;
+    return;
   new_graph (&graph);
 
   /* graph.smanhattan_edges = yes;
@@ -233,8 +235,8 @@ print_graph (void)
   output_graph (&graph, &graph_obstack);
 
   for (i = 0; i < nstates; i++)
-      /* Output nodes & edges. */
-      print_state (i);
+    /* Output nodes & edges. */
+    print_state (i);
 
   /* Close graph. */
   close_graph (&graph, &graph_obstack);
