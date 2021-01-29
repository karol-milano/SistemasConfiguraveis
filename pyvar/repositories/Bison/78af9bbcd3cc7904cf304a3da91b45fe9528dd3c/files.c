@@ -37,7 +37,7 @@ struct obstack output_obstack;
 
 char *spec_outfile = NULL;	/* for -o. */
 char *spec_file_prefix = NULL;	/* for -b. */
-char *spec_name_prefix = NULL;	/* for -p. */
+const char *spec_name_prefix = "yy";	/* for -p. */
 char *spec_verbose_file = NULL;   /* for --verbose. */
 char *spec_graph_file = NULL;   /* for -g. */
 char *spec_defines_file = NULL; /* for --defines. */
