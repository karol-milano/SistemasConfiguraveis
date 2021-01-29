@@ -55,6 +55,7 @@ char const *spec_name_prefix = NULL;   /* for -p. */
 location spec_name_prefix_loc = EMPTY_LOCATION_INIT;
 char *spec_verbose_file = NULL;  /* for --verbose. */
 char *spec_graph_file = NULL;    /* for -g. */
+char *spec_html_file = NULL;     /* for --html. */
 char *spec_xml_file = NULL;      /* for -x. */
 char *spec_header_file = NULL;   /* for --header. */
 char *spec_mapped_header_file = NULL;
@@ -425,6 +426,13 @@ compute_output_file_names (void)
       output_file_name_check (&spec_graph_file, false);
     }
 
+  if (html_flag)
+    {
+      if (! spec_html_file)
+        spec_html_file = concat2 (all_but_tab_ext, ".html");
+      output_file_name_check (&spec_html_file, false);
+    }
+
   if (xml_flag)
     {
       if (! spec_xml_file)
@@ -526,6 +534,7 @@ output_file_names_free (void)
   free (all_but_ext);
   free (spec_verbose_file);
   free (spec_graph_file);
+  free (spec_html_file);
   free (spec_xml_file);
   free (spec_header_file);
   free (spec_mapped_header_file);
