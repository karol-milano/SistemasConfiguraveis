@@ -207,9 +207,6 @@ print_graph (void)
 {
   int i;
 
-  if (!graph_flag)
-    return;
-
   /* Output file.  */
   fgraph = xfopen (spec_graph_file, "w");
 
