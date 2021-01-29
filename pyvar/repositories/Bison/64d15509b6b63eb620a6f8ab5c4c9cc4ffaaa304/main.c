@@ -93,10 +93,12 @@ main (int argc, char *argv[])
     exit (1);
 
   /* Output the detailed report on the grammar.  */
-  print_results ();
+  if (verbose_flag)
+    print_results ();
 
   /* Output the VCG graph.  */
-  print_graph ();
+  if (graph_flag)
+    print_graph ();
 
   /* Output the tables and the parser to ftable.  In file output.  */
   output ();
