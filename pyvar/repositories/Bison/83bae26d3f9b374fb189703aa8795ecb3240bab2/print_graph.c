@@ -120,6 +120,9 @@ print_actions (state const *s, FILE *fgraph)
 
   transitions const *trans = s->transitions;
 
+  /* Display reductions. */
+  output_red (s, s->reductions, fgraph);
+
   if (!trans->num && !s->reductions)
     return;
 
