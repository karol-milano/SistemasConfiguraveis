@@ -45,6 +45,7 @@ char const *spec_outfile = NULL;       /* for -o. */
 char const *spec_file_prefix = NULL;   /* for -b. */
 location spec_file_prefix_loc = EMPTY_LOCATION_INIT;
 char const *spec_name_prefix = NULL;   /* for -p. */
+location spec_name_prefix_loc = EMPTY_LOCATION_INIT;;
 char *spec_verbose_file = NULL;  /* for --verbose. */
 char *spec_graph_file = NULL;    /* for -g. */
 char *spec_xml_file = NULL;      /* for -x. */