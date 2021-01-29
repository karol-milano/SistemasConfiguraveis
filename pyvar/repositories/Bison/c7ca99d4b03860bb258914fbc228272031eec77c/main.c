@@ -105,6 +105,7 @@ main (int argc, char *argv[])
   /* Output the tables and the parser to ftable.  In file output.  */
   output ();
 
+  states_free ();
   reduce_free ();
   conflicts_free ();
   free_nullable ();
