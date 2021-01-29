@@ -25,18 +25,12 @@
 #include "gram.h"
 #include "state.h"
 #include "lalr.h"
+#include "conflicts.h"
 
 extern char **tags;
 extern int nstates;
-extern errs **err_table;
-extern char any_conflicts;
-extern char *conflicts;
 extern int final_state;
 
-extern void conflict_log PARAMS ((void));
-extern void verbose_conflict_log PARAMS ((void));
-extern void print_reductions PARAMS ((int));
-
 extern void terse PARAMS ((void));
 extern void verbose PARAMS ((void));
 
@@ -53,7 +47,7 @@ void
 terse (void)
 {
   if (any_conflicts)
-    conflict_log ();
+    print_conflicts ();
 }
 
 
@@ -63,7 +57,7 @@ verbose (void)
   int i;
 
   if (any_conflicts)
-    verbose_conflict_log ();
+    print_conflicts ();
 
   print_grammar ();
 
