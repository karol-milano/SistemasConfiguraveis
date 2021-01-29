@@ -319,21 +319,21 @@ compute_output_file_names (void)
     {
       if (! spec_graph_file)
 	spec_graph_file = concat2 (all_but_tab_ext, ".dot");
-      output_file_name_check (spec_graph_file);
+      output_file_name_check (&spec_graph_file);
     }
 
   if (xml_flag)
     {
       if (! spec_xml_file)
 	spec_xml_file = concat2 (all_but_tab_ext, ".xml");
-      output_file_name_check (spec_xml_file);
+      output_file_name_check (&spec_xml_file);
     }
 
   if (report_flag)
     {
       if (!spec_verbose_file)
         spec_verbose_file = concat2 (all_but_tab_ext, OUTPUT_EXT);
-      output_file_name_check (spec_verbose_file);
+      output_file_name_check (&spec_verbose_file);
     }
 
   free (all_but_tab_ext);
@@ -342,18 +342,37 @@ compute_output_file_names (void)
 }
 
 void
-output_file_name_check (char const *file_name)
+output_file_name_check (char **file_name)
 {
-  if (0 == strcmp (file_name, grammar_file))
-    fatal (_("refusing to overwrite the input file %s"), quote (file_name));
-  {
-    int i;
-    for (i = 0; i < file_names_count; i++)
-      if (0 == strcmp (file_names[i], file_name))
-        warn (_("conflicting outputs to file %s"), quote (file_name));
-  }
-  file_names = xnrealloc (file_names, ++file_names_count, sizeof *file_names);
-  file_names[file_names_count-1] = xstrdup (file_name);
+  bool conflict = false;
+  if (0 == strcmp (*file_name, grammar_file))
+    {
+      complain (_("refusing to overwrite the input file %s"),
+                quote (*file_name));
+      conflict = true;
+    }
+  else
+    {
+      int i;
+      for (i = 0; i < file_names_count; i++)
+        if (0 == strcmp (file_names[i], *file_name))
+          {
+            warn (_("conflicting outputs to file %s"),
+                  quote (*file_name));
+            conflict = true;
+          }
+    }
+  if (conflict)
+    {
+      free (*file_name);
+      *file_name = strdup ("/dev/null");
+    }
+  else
+    {
+      file_names = xnrealloc (file_names, ++file_names_count,
+                              sizeof *file_names);
+      file_names[file_names_count-1] = xstrdup (*file_name);
+    }
 }
 
 void
