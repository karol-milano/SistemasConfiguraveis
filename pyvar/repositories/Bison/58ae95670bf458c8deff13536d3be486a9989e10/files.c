@@ -51,7 +51,7 @@ location spec_name_prefix_loc = EMPTY_LOCATION_INIT;
 char *spec_verbose_file = NULL;  /* for --verbose. */
 char *spec_graph_file = NULL;    /* for -g. */
 char *spec_xml_file = NULL;      /* for -x. */
-char *spec_defines_file = NULL;  /* for --defines. */
+char *spec_header_file = NULL;  /* for --defines. */
 char *parser_file_name;
 
 /* All computed output file names.  */
@@ -335,8 +335,8 @@ compute_output_file_names (void)
 
   if (defines_flag)
     {
-      if (! spec_defines_file)
-        spec_defines_file = concat2 (all_but_ext, header_extension);
+      if (! spec_header_file)
+        spec_header_file = concat2 (all_but_ext, header_extension);
     }
 
   if (graph_flag)
@@ -429,7 +429,7 @@ output_file_names_free (void)
   free (spec_verbose_file);
   free (spec_graph_file);
   free (spec_xml_file);
-  free (spec_defines_file);
+  free (spec_header_file);
   free (parser_file_name);
   free (dir_prefix);
   for (int i = 0; i < generated_files_size; i++)
