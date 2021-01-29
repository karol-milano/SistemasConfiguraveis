@@ -172,7 +172,7 @@ print_state (state_t *state)
 void
 print_graph (void)
 {
-  int i;
+  size_t i;
 
   /* Output file.  */
   fgraph = xfopen (spec_graph_file, "w");
