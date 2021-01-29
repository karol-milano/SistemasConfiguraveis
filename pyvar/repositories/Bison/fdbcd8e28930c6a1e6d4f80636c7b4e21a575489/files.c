@@ -53,7 +53,6 @@ char *spec_defines_file = NULL; /* for --defines. */
 char *parser_file_name = NULL;
 
 char *infile = NULL;
-char *attrsfile = NULL;
 
 static char *full_base_name = NULL;
 
@@ -423,10 +422,10 @@ compute_output_file_names (void)
     src_extension = ".c";
   if (!header_extension)
     header_extension = ".h";
-  
+
   parser_file_name =
     spec_outfile ? spec_outfile : stringappend (full_base_name, src_extension);
-  
+
   /* It the defines filename if not given, we create it.  */
   if (!spec_defines_file)
     spec_defines_file = stringappend (full_base_name, header_extension);
@@ -436,6 +435,4 @@ compute_output_file_names (void)
     spec_graph_file = stringappend (short_base_name, ".vcg");
 
   spec_verbose_file = stringappend (short_base_name, EXT_OUTPUT);
-
-  attrsfile = stringappend (short_base_name, EXT_STYPE_H);
 }
