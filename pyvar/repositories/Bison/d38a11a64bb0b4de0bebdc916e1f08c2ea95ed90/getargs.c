@@ -20,13 +20,15 @@
    02111-1307, USA.  */
 
 #include "system.h"
-#include "getopt.h"
-#include "argmatch.h"
-#include "error.h"
+
+#include <argmatch.h>
+#include <error.h>
+#include <getopt.h>
+
 #include "complain.h"
-#include "struniq.h"
-#include "getargs.h"
 #include "files.h"
+#include "getargs.h"
+#include "uniqstr.h"
 
 int debug_flag = 0;
 int defines_flag = 0;
@@ -410,5 +412,5 @@ getargs (int argc, char *argv[])
       usage (EXIT_FAILURE);
     }
 
-  current_file = grammar_file = struniq_new (argv[optind]);
+  current_file = grammar_file = uniqstr_new (argv[optind]);
 }
