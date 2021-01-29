@@ -351,6 +351,8 @@ compute_output_file_names (void)
 void
 output_file_name_check (char const *file_name)
 {
+  if (0 == strcmp (file_name, grammar_file))
+    fatal (_("refusing to overwrite the input file %s"), quote (file_name));
   {
     int i;
     for (i = 0; i < file_names_count; i++)
