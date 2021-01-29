@@ -22,16 +22,19 @@
 #include "getopt.h"
 #include "system.h"
 #include "files.h"
+#include "getargs.h"
 
-int verboseflag;
-int definesflag;
-int debugflag;
-int nolinesflag;
+char *spec_file_prefix; /* for -b. */
+char *spec_name_prefix; /* for -p.  */
+
+int debugflag = 0;
+int definesflag = 0;
+int nolinesflag = 0;
 int noparserflag = 0;
-int toknumflag = 0;
 int rawtoknumflag = 0;
-char *spec_name_prefix; /* for -p.  */
-char *spec_file_prefix; /* for -b. */
+int toknumflag = 0;
+int verboseflag = 0;
+
 extern int fixed_outfiles;/* for -y */
 
 extern char *program_name;
