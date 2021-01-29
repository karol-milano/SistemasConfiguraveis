@@ -33,6 +33,7 @@
 #include "print.h"
 #include "LR0.h"
 #include "conflicts.h"
+#include "print_graph.h"
 
 /* The name this program was run with, for messages.  */
 char *program_name;
@@ -83,6 +84,9 @@ main (int argc, char *argv[])
   /* Print information about results, if requested.  */
   print_results ();
 
+  /* Output the VCG graph. */
+  print_graph ();
+
   /* Output the tables and the parser to ftable.  In file output.  */
   output ();
 
