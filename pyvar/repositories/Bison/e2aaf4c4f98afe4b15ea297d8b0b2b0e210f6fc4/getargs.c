@@ -24,7 +24,6 @@
 #include "argmatch.h"
 #include "complain.h"
 #include "getargs.h"
-#include "options.h"
 #include "files.h"
 
 int debug_flag = 0;
@@ -186,6 +185,61 @@ warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
 | Process the options.  |
 `----------------------*/
 
+/* Shorts options.  */
+const char *short_options = "yvegdhr:ltknVo:b:p:S:";
+
+static struct option const long_options[] =
+{
+  /* Operation modes. */
+  { "help",          no_argument,		0,   'h' },
+  { "version",       no_argument,		0,   'V' },
+
+  /* Parser. */
+  { "name-prefix",   required_argument,	  0,   'p' },
+  { "include",       required_argument,   0,   'I' },
+
+  /* Output. */
+  { "file-prefix", required_argument,	0,   'b' },
+  { "output",	   required_argument,	0,   'o' },
+  { "output-file", required_argument,	0,   'o' },
+  { "graph",	   optional_argument,	0,   'g' },
+  { "report",	   required_argument,   0,   'r' },
+  { "verbose",	   no_argument,	        0,   'v' },
+
+  /* Hidden. */
+  { "trace",         no_argument,   &trace_flag,     1 },
+
+  /* FIXME: semantic parsers will output an `include' of an
+     output file: be sure that the naem included is indeed the name of
+     the output file.  */ /* FIXME Should we activate this options ?
+     */
+  { "output",      required_argument,     0, 'o' },
+  { "file-prefix", required_argument,     0, 'b' },
+  { "name-prefix", required_argument,     0, 'p' },
+
+  /*
+   * Percent and command line declarations.
+   */
+
+  /* Output.  */
+  { "defines",     optional_argument,   0,   'd' },
+
+  /* Operation modes.  */
+  { "fixed-output-files", no_argument,  0,   'y' },
+  { "yacc",	          no_argument,  0,   'y' },
+
+  /* Parser.  */
+  { "debug",	      no_argument,               0,   't' },
+  { "locations",      no_argument, &locations_flag,     1 },
+  { "no-lines",       no_argument,               0,   'l' },
+  { "no-parser",      no_argument,               0,   'n' },
+  { "raw",            no_argument,               0,     0 },
+  { "skeleton",       required_argument,         0,   'S' },
+  { "token-table",    no_argument,               0,   'k' },
+
+  {0, 0, 0, 0}
+};
+
 /* Under DOS, there is no difference on the case.  This can be
    troublesome when looking for `.tab' etc.  */
 #ifdef MSDOS
@@ -199,8 +253,7 @@ getargs (int argc, char *argv[])
 {
   int c;
 
-  struct option *longopts = long_option_table_new ();
-  while ((c = getopt_long (argc, argv, shortopts, longopts, NULL)) != EOF)
+  while ((c = getopt_long (argc, argv, short_options, long_options, NULL)) != EOF)
     switch (c)
       {
       case 0:
@@ -282,8 +335,6 @@ getargs (int argc, char *argv[])
 	exit (1);
       }
 
-  free (longopts);
-
   if (optind == argc)
     {
       fprintf (stderr, _("%s: no grammar file given\n"), program_name);
