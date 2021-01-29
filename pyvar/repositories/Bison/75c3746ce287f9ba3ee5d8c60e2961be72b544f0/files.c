@@ -56,7 +56,7 @@ location spec_name_prefix_loc = EMPTY_LOCATION_INIT;
 char *spec_verbose_file = NULL;  /* for --verbose. */
 char *spec_graph_file = NULL;    /* for -g. */
 char *spec_xml_file = NULL;      /* for -x. */
-char *spec_header_file = NULL;  /* for --defines. */
+char *spec_header_file = NULL;   /* for --header. */
 char *spec_mapped_header_file = NULL;
 char *parser_file_name;
 
@@ -411,7 +411,7 @@ compute_output_file_names (void)
      ? xstrdup (spec_outfile)
      : concat2 (all_but_ext, src_extension));
 
-  if (defines_flag)
+  if (header_flag)
     {
       if (! spec_header_file)
         spec_header_file = concat2 (all_but_ext, header_extension);
