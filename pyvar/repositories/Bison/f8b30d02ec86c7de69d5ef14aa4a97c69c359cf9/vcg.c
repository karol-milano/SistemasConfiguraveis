@@ -809,7 +809,7 @@ output_graph (graph *g, FILE *fout)
     fprintf (fout, "\tcrossing_optimization:\t%s\n",
 	     get_decision_str (g->crossing_optimization));
 
-  if (g->view != G_VIEW)
+  if (g->view != normal_view)
     fprintf (fout, "\tview:\t%s\n", get_view_str (g->view));
 
   if (g->edges != G_EDGES)
