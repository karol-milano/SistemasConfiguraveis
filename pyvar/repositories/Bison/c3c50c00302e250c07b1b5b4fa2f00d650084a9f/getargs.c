@@ -20,7 +20,6 @@
 
 #include <config.h>
 #include "system.h"
-#include "output.h"
 
 #include <argmatch.h>
 #include <c-strcase.h>
@@ -28,12 +27,13 @@
 #include <error.h>
 #include <getopt.h>
 #include <progname.h>
+#include <quote.h>
 
 #include "complain.h"
 #include "files.h"
 #include "getargs.h"
 #include "muscle-tab.h"
-#include "quote.h"
+#include "output.h"
 #include "uniqstr.h"
 
 bool defines_flag = false;
