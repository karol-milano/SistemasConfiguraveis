@@ -84,7 +84,7 @@ main (int argc, char *argv[])
      lookahead is not enough to disambiguate the parsing.  In file
      conflicts.  Also resolve s/r conflicts based on precedence
      declarations.  */
-  solve_conflicts ();
+  conflicts_solve ();
   conflicts_print ();
 
   /* Output file names. */
@@ -107,7 +107,7 @@ main (int argc, char *argv[])
   output ();
 
   reduce_free ();
-  free_conflicts ();
+  conflicts_free ();
   free_nullable ();
   free_derives ();
   grammar_free ();
