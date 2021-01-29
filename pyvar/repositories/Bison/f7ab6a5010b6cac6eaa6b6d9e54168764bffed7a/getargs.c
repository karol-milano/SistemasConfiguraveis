@@ -207,9 +207,10 @@ for the equivalent short option also.  Similarly for optional arguments.\n"),
 
       fputs (_("\
 Operation modes:\n\
-  -h, --help      display this help and exit\n\
-  -V, --version   output version information and exit\n\
-  -y, --yacc      emulate POSIX yacc\n"), stdout);
+  -h, --help                 display this help and exit\n\
+  -V, --version              output version information and exit\n\
+      --print-localedir      output directory containing locale-dependent data\n\
+  -y, --yacc                 emulate POSIX yacc\n"), stdout);
       putc ('\n', stdout);
 
       fputs (_("\
@@ -289,14 +290,16 @@ const char *short_options = "yvegdhr:ltknVo:b:p:S:T::";
 /* Values for long options that do not have single-letter equivalents.  */
 enum
 {
-  LOCATIONS_OPTION = CHAR_MAX + 1
+  LOCATIONS_OPTION = CHAR_MAX + 1,
+  PRINT_LOCALEDIR_OPTION
 };
 
 static struct option const long_options[] =
 {
   /* Operation modes. */
-  { "help",          no_argument,		0,   'h' },
-  { "version",       no_argument,		0,   'V' },
+  { "help",            no_argument,	0,   'h' },
+  { "version",         no_argument,	0,   'V' },
+  { "print-localedir", no_argument,	0,   PRINT_LOCALEDIR_OPTION },
 
   /* Parser. */
   { "name-prefix",   required_argument,	  0,   'p' },
@@ -364,6 +367,10 @@ getargs (int argc, char *argv[])
 	version ();
 	exit (EXIT_SUCCESS);
 
+      case PRINT_LOCALEDIR_OPTION:
+	printf ("%s\n", LOCALEDIR);
+	exit (EXIT_SUCCESS);
+
       case 'g':
 	/* Here, the -g and --graph=FILE options are differentiated.  */
 	graph_flag = true;
