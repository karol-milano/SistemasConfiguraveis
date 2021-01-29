@@ -21,6 +21,7 @@
 #include <config.h>
 #include "system.h"
 #include "revision.h"
+#include "output.h"
 
 #include <argmatch.h>
 #include <c-strcase.h>
@@ -261,6 +262,7 @@ Operation modes:\n\
   -h, --help                 display this help and exit\n\
   -V, --version              output version information and exit\n\
       --print-localedir      output directory containing locale-dependent data\n\
+      --print-datadir        output directory containing skeletons and XSLT\n\
   -y, --yacc                 emulate POSIX Yacc\n\
 \n\
 "), stdout);
@@ -393,7 +395,8 @@ static char const short_options[] = "yvegxdhr:L:ltknVo:b:p:S:T::W";
 enum
 {
   LOCATIONS_OPTION = CHAR_MAX + 1,
-  PRINT_LOCALEDIR_OPTION
+  PRINT_LOCALEDIR_OPTION,
+  PRINT_DATADIR_OPTION
 };
 
 static struct option const long_options[] =
@@ -402,6 +405,7 @@ static struct option const long_options[] =
   { "help",            no_argument,	  0,   'h' },
   { "version",         no_argument,	  0,   'V' },
   { "print-localedir", no_argument,	  0,   PRINT_LOCALEDIR_OPTION },
+  { "print-datadir",   no_argument,	  0,   PRINT_DATADIR_OPTION   },
   { "warnings",        optional_argument, 0,   'W' },
 
   /* Parser. */
@@ -555,6 +559,10 @@ getargs (int argc, char *argv[])
 	printf ("%s\n", LOCALEDIR);
 	exit (EXIT_SUCCESS);
 
+      case PRINT_DATADIR_OPTION:
+	printf ("%s\n", compute_pkgdatadir ());
+	exit (EXIT_SUCCESS);
+
       default:
 	usage (EXIT_FAILURE);
       }
