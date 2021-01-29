@@ -1,5 +1,5 @@
 /* Top level entry point of bison,
-   Copyright 1984, 1986, 1989, 1992, 1995, 2000
+   Copyright 1984, 1986, 1989, 1992, 1995, 2000, 2001
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -35,6 +35,8 @@
 #include "conflicts.h"
 #include "print_graph.h"
 #include "muscle_tab.h"
+#include "symtab.h"
+#include "lex.h"
 
 /* The name this program was run with, for messages.  */
 char *program_name;
@@ -81,7 +83,15 @@ main (int argc, char *argv[])
      lookahead is not enough to disambiguate the parsing.  In file
      conflicts.  Also resolve s/r conflicts based on precedence
      declarations.  */
-  initialize_conflicts ();
+  solve_conflicts ();
+
+  /* Output file names. */
+  compute_output_file_names ();
+
+  /* Stop if there were errors, to avoid trashing previous output
+     files.  */
+  if (complain_message_count)
+    exit (1);
 
   /* Print information about results, if requested.  */
   print_results ();
@@ -92,12 +102,19 @@ main (int argc, char *argv[])
   /* Output the tables and the parser to ftable.  In file output.  */
   output ();
 
-  finalize_conflicts ();
+  /* Free the symbol table data structure.  */
+  free_symtab ();
+
+  lex_free ();
+
+  /* Close the input files. */
+  close_files ();
+
+  free_conflicts ();
   free_nullable ();
   free_derives ();
 
-  if (!complain_message_count)
-    output_files ();
+  output_files ();
 
   exit (complain_message_count ? 1 : 0);
 }
