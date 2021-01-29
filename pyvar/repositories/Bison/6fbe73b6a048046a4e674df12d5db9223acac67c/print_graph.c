@@ -155,8 +155,7 @@ print_state (state *s, FILE *fgraph)
   /* A node's label contains its items.  */
   obstack_init (&node_obstack);
   print_core (&node_obstack, s);
-  obstack_1grow (&node_obstack, '\0');
-  output_node (s->number, obstack_finish (&node_obstack), fgraph);
+  output_node (s->number, obstack_finish0 (&node_obstack), fgraph);
   obstack_free (&node_obstack, 0);
 
   /* Output the edges.  */
