@@ -155,7 +155,10 @@ main (int argc, char *argv[])
 
   print_precedence_warnings ();
 
-  if (!update_flag)
+  /* Whether to generate output files.  */
+  bool generate = !(feature_flag & feature_syntax_only);
+
+  if (generate)
     {
       /* Output file names. */
       compute_output_file_names ();
@@ -196,7 +199,7 @@ main (int argc, char *argv[])
   timevar_pop (tv_free);
 
   /* Output the tables and the parser to ftable.  In file output.  */
-  if (!update_flag)
+  if (generate)
     {
       timevar_push (tv_parser);
       output ();
