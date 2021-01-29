@@ -417,15 +417,15 @@ compute_output_file_names (void)
 {
   compute_base_names ();
 
-  parser_file_name =
-    spec_outfile ? spec_outfile : stringappend (full_base_name, src_extension);
-
   /* If not yet done. */
   if (!src_extension)
     src_extension = ".c";
   if (!header_extension)
     header_extension = ".h";
   
+  parser_file_name =
+    spec_outfile ? spec_outfile : stringappend (full_base_name, src_extension);
+  
   /* It the defines filename if not given, we create it.  */
   if (!spec_defines_file)
     spec_defines_file = stringappend (full_base_name, header_extension);
