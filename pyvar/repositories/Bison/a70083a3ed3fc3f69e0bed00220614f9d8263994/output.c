@@ -99,6 +99,7 @@
 #include "complain.h"
 #include "output.h"
 #include "lalr.h"
+#include "reader.h"
 
 extern void berror PARAMS((const char *));
 
@@ -107,7 +108,6 @@ extern short *user_toknums;
 extern int final_state;
 extern errs **err_table;
 
-extern void reader_output_yylsp PARAMS ((FILE *));
 
 static int nvectors;
 static int nentries;
