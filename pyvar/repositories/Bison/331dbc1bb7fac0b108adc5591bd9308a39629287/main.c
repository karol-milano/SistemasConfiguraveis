@@ -53,7 +53,6 @@ main (int argc, char *argv[])
   getargs (argc, argv);
 
   muscle_init ();
-  open_files ();
 
   /* Read the input.  Copy some parts of it to FGUARD, FACTION, FTABLE
      and FATTRS.  In file reader.c.  The other parts are recorded in
@@ -103,14 +102,9 @@ main (int argc, char *argv[])
   /* Output the tables and the parser to ftable.  In file output.  */
   output ();
 
-  /* Close the input files. */
-  close_files ();
-
   /* Free the symbol table data structure.  */
   free_symtab ();
 
-  lex_free ();
-
   reduce_free ();
   free_conflicts ();
   free_nullable ();
