@@ -46,6 +46,7 @@
 #include "reduce.h"
 #include "scan-code.h"
 #include "scan-gram.h"
+#include "scan-skel.h"
 #include "symtab.h"
 #include "tables.h"
 #include "uniqstr.h"
@@ -175,6 +176,7 @@ main (int argc, char *argv[])
   muscle_free ();
   uniqstrs_free ();
   code_scanner_free ();
+  skel_scanner_free ();
   quotearg_free ();
   timevar_pop (TV_FREE);
 
