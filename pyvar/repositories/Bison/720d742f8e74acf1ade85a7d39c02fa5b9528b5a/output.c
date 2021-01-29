@@ -98,25 +98,14 @@
 #include "state.h"
 #include "complain.h"
 #include "output.h"
+#include "lalr.h"
 
 extern void berror PARAMS((const char *));
 
 extern char **tags;
 extern short *user_toknums;
-extern int tokensetsize;
 extern int final_state;
-extern core **state_table;
-extern shifts **shift_table;
 extern errs **err_table;
-extern reductions **reduction_table;
-extern short *accessing_symbol;
-extern unsigned *LA;
-extern short *LAruleno;
-extern short *lookaheads;
-extern char *consistent;
-extern short *goto_map;
-extern short *from_state;
-extern short *to_state;
 
 extern void reader_output_yylsp PARAMS ((FILE *));
 
