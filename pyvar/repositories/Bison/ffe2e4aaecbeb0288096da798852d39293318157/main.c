@@ -35,6 +35,7 @@
 #include "conflicts.h"
 #include "derives.h"
 #include "files.h"
+#include "fixits.h"
 #include "getargs.h"
 #include "gram.h"
 #include "lalr.h"
@@ -205,6 +206,7 @@ main (int argc, char *argv[])
   conflicts_free ();
   grammar_free ();
   output_file_names_free ();
+  fixits_free ();
 
   /* The scanner memory cannot be released right after parsing, as it
      contains things such as user actions, prologue, epilogue etc.  */
