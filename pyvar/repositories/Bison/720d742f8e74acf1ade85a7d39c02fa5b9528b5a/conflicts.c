@@ -24,16 +24,9 @@
 #include "files.h"
 #include "gram.h"
 #include "state.h"
-
+#include "lalr.h"
 
 extern char **tags;
-extern int tokensetsize;
-extern char *consistent;
-extern short *accessing_symbol;
-extern shifts **shift_table;
-extern unsigned *LA;
-extern short *LAruleno;
-extern short *lookaheads;
 extern int fixed_outfiles;
 
 extern void initialize_conflicts PARAMS ((void));
