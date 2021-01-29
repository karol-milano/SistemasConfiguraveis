@@ -111,6 +111,7 @@ main (int argc, char *argv[])
   /* Close the input files. */
   close_files ();
 
+  reduce_free ();
   free_conflicts ();
   free_nullable ();
   free_derives ();
