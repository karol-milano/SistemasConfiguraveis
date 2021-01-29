@@ -403,7 +403,7 @@ compute_base_names (void)
 
       /* Computes the extensions from the grammar file name.  */
       filename_split (infile, &base, &tab, &ext);
-      if (ext)
+      if (ext && !yacc_flag)
 	compute_exts_from_gf (ext);
     }
 }
@@ -425,7 +425,7 @@ compute_output_file_names (void)
     src_extension = ".c";
   if (!header_extension)
     header_extension = ".h";
-
+  
   /* It the defines filename if not given, we create it.  */
   if (!spec_defines_file)
     spec_defines_file = stringappend (full_base_name, header_extension);
