@@ -323,7 +323,7 @@ compute_output_file_names (void)
   if (graph_flag)
     {
       if (! spec_graph_file)
-	spec_graph_file = concat2 (all_but_tab_ext, ".vcg");
+	spec_graph_file = concat2 (all_but_tab_ext, ".dot");
       name[names++] = spec_graph_file;
     }
 
