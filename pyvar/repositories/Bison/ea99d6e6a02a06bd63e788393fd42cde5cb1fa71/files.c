@@ -51,8 +51,17 @@ char *spec_defines_file = NULL;  /* for --defines. */
 char *parser_file_name;
 
 /* All computed output file names.  */
-static char **file_names = NULL;
-static int file_names_count = 0;
+typedef struct generated_file
+{
+  /** File name.  */
+  char *name;
+  /** Whether is a generated source file (e.g., *.c, *.java...), as
+      opposed to the report file (e.g., *.output).  When late errors
+      are detected, generated source files are removed.  */
+  bool is_source;
+} generated_file;
+static generated_file *generated_files = NULL;
+static int generated_files_size = 0;
 
 uniqstr grammar_file = NULL;
 uniqstr current_file = NULL;
@@ -332,21 +341,21 @@ compute_output_file_names (void)
     {
       if (! spec_graph_file)
         spec_graph_file = concat2 (all_but_tab_ext, ".dot");
-      output_file_name_check (&spec_graph_file);
+      output_file_name_check (&spec_graph_file, false);
     }
 
   if (xml_flag)
     {
       if (! spec_xml_file)
         spec_xml_file = concat2 (all_but_tab_ext, ".xml");
-      output_file_name_check (&spec_xml_file);
+      output_file_name_check (&spec_xml_file, false);
     }
 
   if (report_flag)
     {
       if (!spec_verbose_file)
         spec_verbose_file = concat2 (all_but_tab_ext, OUTPUT_EXT);
-      output_file_name_check (&spec_verbose_file);
+      output_file_name_check (&spec_verbose_file, false);
     }
 
   free (all_but_tab_ext);
@@ -355,7 +364,7 @@ compute_output_file_names (void)
 }
 
 void
-output_file_name_check (char **file_name)
+output_file_name_check (char **file_name, bool source)
 {
   bool conflict = false;
   if (STREQ (*file_name, grammar_file))
@@ -367,11 +376,11 @@ output_file_name_check (char **file_name)
   else
     {
       int i;
-      for (i = 0; i < file_names_count; i++)
-        if (STREQ (file_names[i], *file_name))
+      for (i = 0; i < generated_files_size; i++)
+        if (STREQ (generated_files[i].name, *file_name))
           {
             complain (NULL, Wother, _("conflicting outputs to file %s"),
-                      quote (*file_name));
+                      quote (generated_files[i].name));
             conflict = true;
           }
     }
@@ -382,9 +391,10 @@ output_file_name_check (char **file_name)
     }
   else
     {
-      file_names = xnrealloc (file_names, ++file_names_count,
-                              sizeof *file_names);
-      file_names[file_names_count-1] = xstrdup (*file_name);
+      generated_files = xnrealloc (generated_files, ++generated_files_size,
+                                   sizeof *generated_files);
+      generated_files[generated_files_size-1].name = xstrdup (*file_name);
+      generated_files[generated_files_size-1].is_source = source;
     }
 }
 
@@ -400,8 +410,8 @@ output_file_names_free (void)
   free (dir_prefix);
   {
     int i;
-    for (i = 0; i < file_names_count; i++)
-      free (file_names[i]);
+    for (i = 0; i < generated_files_size; i++)
+      free (generated_files[i].name);
   }
-  free (file_names);
+  free (generated_files);
 }
