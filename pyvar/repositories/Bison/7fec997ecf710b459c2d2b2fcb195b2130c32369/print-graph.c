@@ -184,10 +184,8 @@ print_graph (void)
   start_graph (fgraph);
 
   /* Output nodes and edges. */
-  closure_new (nritems);
   for (int i = 0; i < nstates; i++)
     print_state (states[i], fgraph);
-  closure_free ();
 
   finish_graph (fgraph);
   xfclose (fgraph);
