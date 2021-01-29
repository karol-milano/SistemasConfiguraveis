@@ -24,6 +24,8 @@
 #include "files.h"
 #include "complain.h"
 #include "getargs.h"
+#include "xalloc.h"
+#include "options.h"
 
 int debug_flag = 0;
 int defines_flag = 0;
@@ -39,37 +41,6 @@ int graph_flag = 0;
 const char *skeleton = NULL;
 
 extern char *program_name;
-const char *shortopts = "yvgdhrltknVo:b:p:S:";
-static struct option longopts[] =
-{
-  /* Operation modes. */
-  {"help",		no_argument,	0, 'h'},
-  {"version",		no_argument, 	0, 'V'},
-  {"yacc",		no_argument,	0, 'y'},
-  {"fixed-output-files",no_argument,	0, 'y'},
-
-  /* Parser. */
-  {"skeleton",		required_argument,	0, 'S'},
-  {"debug",		no_argument,		0, 'd'},
-  {"locations",		no_argument, 	&locations_flag, 1},
-  /* was 'a';  apparently unused -wjh */
-  {"name-prefix",	required_argument, 	0, 'p'},
-  {"no-lines",		no_argument,		0, 'l'},
-  {"no-parser",		no_argument,		0, 'n'},
-  {"raw",		no_argument,		0, 'r'},
-  {"token-table",	no_argument,		0, 'k'},
-
-  /* Output. */
-  {"defines",		no_argument,		0, 'd'},
-  {"verbose",		no_argument,		0, 'v'},
-  {"file-prefix",	required_argument, 	0, 'b'},
-  {"output-file",	required_argument, 	0, 'o'},
-  {"graph",		no_argument,		0, 'g'},
-
-  /* Hidden. */
-  {"statistics",	no_argument, 	&statistics_flag, 1},
-  {0, 0, 0, 0}
-};
 
 /*---------------------------.
 | Display the help message.  |
@@ -161,6 +132,7 @@ getargs (int argc, char *argv[])
 {
   int c;
 
+  create_long_option_table ();
   while ((c = getopt_long (argc, argv, shortopts, longopts, NULL)) != EOF)
     switch (c)
       {
@@ -234,6 +206,7 @@ getargs (int argc, char *argv[])
 	exit (1);
       }
 
+  XFREE (longopts);
   if (optind == argc)
     {
       fprintf (stderr, _("%s: no grammar file given\n"), program_name);
