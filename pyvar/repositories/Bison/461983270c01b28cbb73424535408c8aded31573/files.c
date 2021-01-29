@@ -398,6 +398,16 @@ output_file_name_check (char **file_name, bool source)
     }
 }
 
+void
+unlink_generated_sources (void)
+{
+  int i;
+  for (i = 0; i < generated_files_size; i++)
+    if (generated_files[i].is_source)
+      /* Ignore errors.  The file might not even exist.  */
+      unlink (generated_files[i].name);
+}
+
 void
 output_file_names_free (void)
 {
