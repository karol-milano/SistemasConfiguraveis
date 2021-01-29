@@ -22,6 +22,7 @@
 #include "getopt.h"
 #include "system.h"
 #include "files.h"
+#include "complain.h"
 #include "getargs.h"
 
 int debug_flag = 0;
@@ -29,12 +30,13 @@ int defines_flag = 0;
 int locations_flag = 0;
 int no_lines_flag = 0;
 int no_parser_flag = 0;
-char *skeleton = 0;
 int token_table_flag = 0;
 int verbose_flag = 0;
 int statistics_flag = 0;
 int yacc_flag = 0;	/* for -y */
 
+const char *skeleton = NULL;
+
 extern char *program_name;
 const char *shortopts = "yvdhrltknVo:b:p:S:";
 static struct option longopts[] =
