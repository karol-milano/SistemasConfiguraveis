@@ -53,6 +53,10 @@ char *spec_graph_file = NULL;    /* for -g. */
 char *spec_defines_file = NULL;  /* for --defines. */
 char *parser_file_name;
 
+/* All computed output file names.  */
+static char **file_names = NULL;
+static int file_names_count = 0;
+
 uniqstr grammar_file = NULL;
 uniqstr current_file = NULL;
 
@@ -292,11 +296,6 @@ compute_file_name_parts (void)
 void
 compute_output_file_names (void)
 {
-  char const *name[4];
-  int i;
-  int j;
-  int names = 0;
-
   compute_file_name_parts ();
 
   /* If not yet done. */
@@ -305,7 +304,7 @@ compute_output_file_names (void)
   if (!header_extension)
     header_extension = xstrdup (".h");
 
-  name[names++] = parser_file_name =
+  parser_file_name =
     (spec_outfile
      ? xstrdup (spec_outfile)
      : concat2 (all_but_ext, src_extension));
@@ -314,33 +313,40 @@ compute_output_file_names (void)
     {
       if (! spec_defines_file)
 	spec_defines_file = concat2 (all_but_ext, header_extension);
-      name[names++] = spec_defines_file;
     }
 
   if (graph_flag)
     {
       if (! spec_graph_file)
 	spec_graph_file = concat2 (all_but_tab_ext, ".dot");
-      name[names++] = spec_graph_file;
+      output_file_name_check (spec_graph_file);
     }
 
   if (report_flag)
     {
       spec_verbose_file = concat2 (all_but_tab_ext, OUTPUT_EXT);
-      name[names++] = spec_verbose_file;
+      output_file_name_check (spec_verbose_file);
     }
 
-  for (j = 0; j < names; j++)
-    for (i = 0; i < j; i++)
-      if (strcmp (name[i], name[j]) == 0)
-	warn (_("conflicting outputs to file %s"), quote (name[i]));
-
   free (all_but_ext);
   free (all_but_tab_ext);
   free (src_extension);
   free (header_extension);
 }
 
+void
+output_file_name_check (char const *file_name)
+{
+  {
+    int i;
+    for (i = 0; i < file_names_count; i++)
+      if (0 == strcmp (file_names[i], file_name))
+        warn (_("conflicting outputs to file %s"), quote (file_name));
+  }
+  file_names = xnrealloc (file_names, ++file_names_count, sizeof *file_names);
+  file_names[file_names_count-1] = xstrdup (file_name);
+}
+
 void
 output_file_names_free (void)
 {
@@ -349,4 +355,10 @@ output_file_names_free (void)
   free (spec_defines_file);
   free (parser_file_name);
   free (dir_prefix);
+  {
+    int i;
+    for (i = 0; i < file_names_count; i++)
+      free (file_names[i]);
+  }
+  free (file_names);
 }
