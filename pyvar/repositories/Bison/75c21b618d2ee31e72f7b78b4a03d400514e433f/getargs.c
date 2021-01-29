@@ -26,6 +26,7 @@
 #include <c-strcase.h>
 #include <configmake.h>
 #include <error.h>
+#include <quotearg.h>
 
 /* Hack to get <getopt.h> to declare getopt with a prototype.  */
 #if lint && ! defined __GNU_LIBRARY__
@@ -43,6 +44,7 @@
 #include "complain.h"
 #include "files.h"
 #include "getargs.h"
+#include "muscle_tab.h"
 #include "uniqstr.h"
 
 bool debug_flag;
@@ -623,4 +625,5 @@ getargs (int argc, char *argv[])
     }
 
   current_file = grammar_file = uniqstr_new (argv[optind]);
+  MUSCLE_INSERT_C_STRING ("file_name", grammar_file);
 }
