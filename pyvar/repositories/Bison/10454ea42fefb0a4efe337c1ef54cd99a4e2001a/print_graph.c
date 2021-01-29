@@ -202,13 +202,7 @@ print_graph (void)
 
   new_graph (&static_graph);
 
-#if 0
-  static_graph.smanhattan_edges = yes;
-  static_graph.manhattan_edges = yes;
-#endif
-
   static_graph.display_edge_labels = yes;
-  static_graph.layoutalgorithm = normal;
 
   static_graph.port_sharing = no;
   static_graph.finetuning = yes;
