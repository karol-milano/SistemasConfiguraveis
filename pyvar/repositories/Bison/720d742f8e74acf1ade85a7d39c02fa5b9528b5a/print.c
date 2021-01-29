@@ -24,16 +24,11 @@
 #include "files.h"
 #include "gram.h"
 #include "state.h"
-
+#include "lalr.h"
 
 extern char **tags;
 extern int nstates;
-extern short *accessing_symbol;
-extern core **state_table;
-extern shifts **shift_table;
 extern errs **err_table;
-extern reductions **reduction_table;
-extern char *consistent;
 extern char any_conflicts;
 extern char *conflicts;
 extern int final_state;
