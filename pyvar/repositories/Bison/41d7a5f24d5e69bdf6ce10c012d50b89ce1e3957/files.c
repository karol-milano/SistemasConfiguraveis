@@ -45,6 +45,7 @@ char const *spec_file_prefix = NULL;   /* for -b. */
 char const *spec_name_prefix = NULL;   /* for -p. */
 char *spec_verbose_file = NULL;  /* for --verbose. */
 char *spec_graph_file = NULL;    /* for -g. */
+char *spec_xml_file = NULL;      /* for -x. */
 char *spec_defines_file = NULL;  /* for --defines. */
 char *parser_file_name;
 
@@ -328,6 +329,13 @@ compute_output_file_names (void)
       output_file_name_check (spec_graph_file);
     }
 
+  if (xml_flag)
+    {
+      if (! spec_xml_file)
+	spec_xml_file = concat2 (all_but_tab_ext, ".xml");
+      output_file_name_check (spec_xml_file);
+    }
+
   if (report_flag)
     {
       spec_verbose_file = concat2 (all_but_tab_ext, OUTPUT_EXT);
@@ -358,6 +366,7 @@ output_file_names_free (void)
   free (all_but_ext);
   free (spec_verbose_file);
   free (spec_graph_file);
+  free (spec_xml_file);
   free (spec_defines_file);
   free (parser_file_name);
   free (dir_prefix);
