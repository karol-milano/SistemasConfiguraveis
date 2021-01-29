@@ -26,9 +26,8 @@
 #include "state.h"
 #include "lalr.h"
 #include "conflicts.h"
-
-extern char **tags;
-extern int fixed_outfiles;
+#include "reader.h"
+#include "LR0.h"
 
 int any_conflicts = 0;
 errs **err_table;
