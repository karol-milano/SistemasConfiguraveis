@@ -33,6 +33,7 @@
 
 #include "complain.h"
 #include "conflicts.h"
+#include "counterexample.h"
 #include "derives.h"
 #include "files.h"
 #include "fixits.h"
@@ -144,6 +145,8 @@ main (int argc, char *argv[])
       conflicts_update_state_numbers (old_to_new, nstates_old);
       free (old_to_new);
     }
+  if (warning_is_enabled (Wcounterexample))
+    counterexample_init ();
   conflicts_print ();
   timevar_pop (tv_conflicts);
 
@@ -217,6 +220,7 @@ main (int argc, char *argv[])
   reduce_free ();
   conflicts_free ();
   grammar_free ();
+  counterexample_free ();
   output_file_names_free ();
 
   /* The scanner memory cannot be released right after parsing, as it
