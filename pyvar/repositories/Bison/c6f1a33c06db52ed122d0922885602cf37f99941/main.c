@@ -29,6 +29,7 @@
 #include "files.h"
 #include "complain.h"
 #include "derives.h"
+#include "tables.h"
 #include "output.h"
 #include "reader.h"
 #include "lalr.h"
@@ -131,12 +132,18 @@ main (int argc, char *argv[])
       timevar_pop (TV_GRAPH);
     }
 
+  /* Compute the parser tables.  */
+  timevar_push (TV_ACTIONS);
+  tables_generate ();
+  timevar_pop (TV_ACTIONS);
+
   /* Output the tables and the parser to ftable.  In file output.  */
   timevar_push (TV_PARSER);
   output ();
   timevar_pop (TV_PARSER);
 
   timevar_push (TV_FREE);
+  tables_free ();
   states_free ();
   reduce_free ();
   conflicts_free ();
