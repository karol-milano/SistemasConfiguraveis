@@ -199,7 +199,7 @@ print_graph (void)
   output_graph (&graph, fgraph);
 
   /* Output nodes and edges. */
-  new_closure (nitems);
+  new_closure (nritems);
   for (i = 0; i < nstates; i++)
     print_state (state_table[i]);
   free_closure ();
