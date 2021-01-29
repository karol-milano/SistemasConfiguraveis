@@ -91,7 +91,7 @@ main (int argc, char *argv[])
   compute_output_file_names ();
 
   /* Output the detailed report on the grammar.  */
-  if (verbose_flag)
+  if (report_flag)
     print_results ();
 
   /* Stop if there were errors, to avoid trashing previous output
