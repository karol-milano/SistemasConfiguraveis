@@ -86,15 +86,15 @@ main (int argc, char *argv[])
   /* Output file names. */
   compute_output_file_names ();
 
+  /* Output the detailed report on the grammar.  */
+  if (verbose_flag)
+    print_results ();
+
   /* Stop if there were errors, to avoid trashing previous output
      files.  */
   if (complain_message_count)
     exit (1);
 
-  /* Output the detailed report on the grammar.  */
-  if (verbose_flag)
-    print_results ();
-
   /* Output the VCG graph.  */
   if (graph_flag)
     print_graph ();
