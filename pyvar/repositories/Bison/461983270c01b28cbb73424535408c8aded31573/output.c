@@ -704,6 +704,11 @@ output (void)
   /* Process the selected skeleton file.  */
   output_skeleton ();
 
+  /* If late errors were generated, destroy the generated source
+     files. */
+  if (complaint_status)
+    unlink_generated_sources ();
+
   obstack_free (&format_obstack, NULL);
 }
 
