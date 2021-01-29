@@ -84,6 +84,7 @@ main (int argc, char *argv[])
      conflicts.  Also resolve s/r conflicts based on precedence
      declarations.  */
   solve_conflicts ();
+  conflicts_print ();
 
   /* Output file names. */
   compute_output_file_names ();
@@ -93,7 +94,7 @@ main (int argc, char *argv[])
   if (complain_message_count)
     exit (1);
 
-  /* Print information about results, if requested.  */
+  /* Output the detailed report on the grammar.  */
   print_results ();
 
   /* Output the VCG graph.  */
