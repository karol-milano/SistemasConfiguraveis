@@ -29,6 +29,8 @@
 #include "files.h"
 #include "getargs.h"
 
+int warnings_flag = Wconflicts_sr | Wconflicts_rr | Wother;
+
 bool complaint_issued;
 static unsigned *indent_ptr = 0;
 
