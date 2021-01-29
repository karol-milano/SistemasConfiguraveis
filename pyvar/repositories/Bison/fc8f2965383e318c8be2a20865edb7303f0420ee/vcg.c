@@ -96,7 +96,6 @@ new_graph (graph *g)
   g->dirty_edge_labels = G_DIRTY_EDGE_LABELS;
   g->finetuning = G_FINETUNING;
   g->ignore_singles = G_IGNORE_SINGLES;
-  g->long_straight_phase = G_LONG_STRAIGHT_PHASE;
   g->priority_phase = G_PRIORITY_PHASE;
   g->manhattan_edges = G_MANHATTAN_EDGES;
   g->smanhattan_edges = G_SMANHATTAN_EDGES;
@@ -797,9 +796,6 @@ output_graph (graph *g, FILE *fout)
   if (g->ignore_singles != G_IGNORE_SINGLES)
     fprintf (fout, "\tignore_singles:\t%s\n",
 	     get_decision_str (g->ignore_singles));
-  if (g->long_straight_phase != G_LONG_STRAIGHT_PHASE)
-    fprintf (fout, "\tlong_straight_phase:\t%s\n",
-	     get_decision_str (g->long_straight_phase));
   if (g->priority_phase != G_PRIORITY_PHASE)
     fprintf (fout, "\tpriority_phase:\t%s\n",
 	     get_decision_str (g->priority_phase));
