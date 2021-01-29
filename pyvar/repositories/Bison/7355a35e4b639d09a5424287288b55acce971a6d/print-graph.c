@@ -184,10 +184,10 @@ print_graph (void)
   start_graph (fgraph);
 
   /* Output nodes and edges. */
-  new_closure (nritems);
+  closure_new (nritems);
   for (int i = 0; i < nstates; i++)
     print_state (states[i], fgraph);
-  free_closure ();
+  closure_free ();
 
   finish_graph (fgraph);
   xfclose (fgraph);
