@@ -24,6 +24,7 @@
 #include "argmatch.h"
 #include "error.h"
 #include "complain.h"
+#include "struniq.h"
 #include "getargs.h"
 #include "files.h"
 
@@ -419,5 +420,5 @@ getargs (int argc, char *argv[])
       usage (EXIT_FAILURE);
     }
 
-  infile = xstrdup (argv[optind]);
+  current_file = grammar_file = struniq_new (argv[optind]);
 }
