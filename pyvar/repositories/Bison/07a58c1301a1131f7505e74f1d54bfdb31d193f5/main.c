@@ -30,6 +30,7 @@
 #include "lalr.h"
 #include "reduce.h"
 #include "nullable.h"
+#include "print.h"
 
 #if 0				/* XXX currently unused.  */
 /* Nonzero means failure has been detected; don't write a parser file.  */
@@ -46,8 +47,6 @@ extern char *printable_version PARAMS ((int));
 extern void generate_states PARAMS ((void));
 extern void initialize_conflicts PARAMS ((void));
 extern void finalize_conflicts PARAMS ((void));
-extern void verbose PARAMS ((void));
-extern void terse PARAMS ((void));
 
 
 /* VMS complained about using `int'.  */
@@ -96,12 +95,8 @@ main (int argc, char *argv[])
      declarations.  */
   initialize_conflicts ();
 
-  /* Print information about results, if requested.  In file print.
-     */
-  if (verboseflag)
-    verbose ();
-  else
-    terse ();
+  /* Print information about results, if requested.  */
+  print_results ();
 
   /* Output the tables and the parser to ftable.  In file output.  */
   output ();
