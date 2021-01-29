@@ -338,7 +338,8 @@ compute_output_file_names (void)
 
   if (report_flag)
     {
-      spec_verbose_file = concat2 (all_but_tab_ext, OUTPUT_EXT);
+      if (!spec_verbose_file)
+        spec_verbose_file = concat2 (all_but_tab_ext, OUTPUT_EXT);
       output_file_name_check (spec_verbose_file);
     }
 
