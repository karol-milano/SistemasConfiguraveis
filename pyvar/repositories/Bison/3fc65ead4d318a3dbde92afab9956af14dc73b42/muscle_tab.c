@@ -261,3 +261,18 @@ muscles_m4_output (FILE *out)
 {
   hash_do_for_each (muscle_table, muscle_m4_output_processor, out);
 }
+
+void
+muscle_boundary_grow (char const *key, boundary bound)
+{
+  char *extension;
+  MUSCLE_OBSTACK_SGROW (&muscle_obstack, bound.file);
+  obstack_1grow (&muscle_obstack, ':');
+  obstack_fgrow1 (&muscle_obstack, "%d", bound.line);
+  obstack_1grow (&muscle_obstack, '.');
+  obstack_fgrow1 (&muscle_obstack, "%d", bound.column);
+  obstack_1grow (&muscle_obstack, '\0');
+  extension = obstack_finish (&muscle_obstack);
+  muscle_grow (key, extension, "");
+  obstack_free (&muscle_obstack, extension);
+}
