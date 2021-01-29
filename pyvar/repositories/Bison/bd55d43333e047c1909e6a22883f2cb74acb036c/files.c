@@ -342,7 +342,8 @@ compute_output_file_names (void)
   if (graph_flag)
     {
       if (! spec_graph_file)
-        spec_graph_file = concat2 (all_but_tab_ext, ".dot");
+        spec_graph_file = concat2 (all_but_tab_ext,
+                                   304 <= required_version ? ".gv" : ".dot");
       output_file_name_check (&spec_graph_file, false);
     }
 
