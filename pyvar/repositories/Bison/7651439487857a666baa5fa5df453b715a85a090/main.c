@@ -103,13 +103,11 @@ main (int argc, char *argv[])
   /* Output the tables and the parser to ftable.  In file output.  */
   output ();
 
-  /* Free the symbol table data structure.  */
-  free_symtab ();
-
   reduce_free ();
   free_conflicts ();
   free_nullable ();
   free_derives ();
+  grammar_free ();
 
   /* If using alloca.c, flush the alloca'ed memory for the benefit of
      people running Bison as a library in IDEs.  */
