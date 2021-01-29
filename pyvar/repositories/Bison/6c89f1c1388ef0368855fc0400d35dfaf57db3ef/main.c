@@ -25,6 +25,7 @@
 #include "files.h"
 #include "complain.h"
 #include "derives.h"
+#include "output.h"
 
 #if 0				/* XXX currently unused.  */
 /* Nonzero means failure has been detected; don't write a parser file.  */
@@ -35,7 +36,6 @@ static int failure;
 char *program_name;
 
 extern char *printable_version PARAMS ((int));
-extern void berror PARAMS ((const char *));
 
 extern void openfiles PARAMS ((void));
 extern void reader PARAMS ((void));
@@ -48,7 +48,6 @@ extern void initialize_conflicts PARAMS ((void));
 extern void finalize_conflicts PARAMS ((void));
 extern void verbose PARAMS ((void));
 extern void terse PARAMS ((void));
-extern void output PARAMS ((void));
 
 
 /* VMS complained about using `int'.  */
