@@ -34,7 +34,7 @@
 #include "LR0.h"
 #include "conflicts.h"
 #include "print_graph.h"
-#include "macrotab.h"
+#include "muscle_tab.h"
 
 /* The name this program was run with, for messages.  */
 char *program_name;
@@ -52,7 +52,7 @@ main (int argc, char *argv[])
   lineno = 0;
   getargs (argc, argv);
 
-  macro_init ();
+  muscle_init ();
   open_files ();
 
   /* Read the input.  Copy some parts of it to FGUARD, FACTION, FTABLE
