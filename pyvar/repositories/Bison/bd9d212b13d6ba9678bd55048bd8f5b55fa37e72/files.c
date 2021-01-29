@@ -76,7 +76,7 @@ uniqstr current_file = NULL;
    empty string (meaning the current directory); otherwise it is
    `dir/'.  */
 
-static char *all_but_ext;
+char *all_but_ext;
 static char *all_but_tab_ext;
 char *dir_prefix;
 
@@ -328,7 +328,6 @@ compute_output_file_names (void)
       output_file_name_check (spec_verbose_file);
     }
 
-  free (all_but_ext);
   free (all_but_tab_ext);
   free (src_extension);
   free (header_extension);
@@ -350,6 +349,7 @@ output_file_name_check (char const *file_name)
 void
 output_file_names_free (void)
 {
+  free (all_but_ext);
   free (spec_verbose_file);
   free (spec_graph_file);
   free (spec_defines_file);
