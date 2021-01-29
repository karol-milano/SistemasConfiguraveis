@@ -503,13 +503,6 @@ print_results (void)
      that conflicts with Posix.  */
   FILE *out = xfopen (spec_verbose_file, "w");
 
-  size_t size = obstack_object_size (&output_obstack);
-  fwrite (obstack_finish (&output_obstack), 1, size, out);
-  obstack_free (&output_obstack, NULL);
-
-  if (size)
-    fputs ("\n\n", out);
-
   reduce_output (out);
   conflicts_output (out);
 
