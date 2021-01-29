@@ -146,6 +146,8 @@ main (int argc, char *argv[])
 
   print_precedence_warnings ();
 
+  print_assoc_warnings ();
+
   /* Output file names. */
   compute_output_file_names ();
 
