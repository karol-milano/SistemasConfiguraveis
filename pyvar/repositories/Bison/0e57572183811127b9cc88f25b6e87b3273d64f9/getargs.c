@@ -22,6 +22,7 @@
 #include "system.h"
 #include "getopt.h"
 #include "argmatch.h"
+#include "error.h"
 #include "complain.h"
 #include "getargs.h"
 #include "files.h"
@@ -149,37 +150,43 @@ report_argmatch (char *args)
   while ((args = strtok (NULL, ",")));
 }
 
-/*---------------------------.
-| Display the help message.  |
-`---------------------------*/
+
+/*-------------------------------------------.
+| Display the help message and exit STATUS.  |
+`-------------------------------------------*/
 
 static void
-usage (FILE *stream)
+usage (int status)
 {
-  /* Some efforts were made to ease the translators' task, please
-     continue.  */
-  fputs (_("\
-GNU bison generates parsers for LALR(1) grammars.\n"), stream);
-  putc ('\n', stream);
+  if (status != 0)
+    fprintf (stderr, _("Try `%s --help' for more information.\n"),
+	     program_name);
+  else
+    {
+      /* Some efforts were made to ease the translators' task, please
+	 continue.  */
+      fputs (_("\
+GNU bison generates parsers for LALR(1) grammars.\n"), stdout);
+      putc ('\n', stdout);
 
-  fprintf (stream, _("\
+      fprintf (stdout, _("\
 Usage: %s [OPTION]... FILE\n"), program_name);
-  putc ('\n', stream);
+      putc ('\n', stdout);
 
-  fputs (_("\
+      fputs (_("\
 If a long option shows an argument as mandatory, then it is mandatory\n\
 for the equivalent short option also.  Similarly for optional arguments.\n"),
-	 stream);
-  putc ('\n', stream);
+	     stdout);
+      putc ('\n', stdout);
 
-  fputs (_("\
+      fputs (_("\
 Operation modes:\n\
   -h, --help      display this help and exit\n\
   -V, --version   output version information and exit\n\
-  -y, --yacc      emulate POSIX yacc\n"), stream);
-  putc ('\n', stream);
+  -y, --yacc      emulate POSIX yacc\n"), stdout);
+      putc ('\n', stdout);
 
-  fputs (_("\
+      fputs (_("\
 Parser:\n\
   -S, --skeleton=FILE        specify the skeleton to use\n\
   -t, --debug                instrument the parser for debugging\n\
@@ -188,10 +195,10 @@ Parser:\n\
   -l, --no-lines             don't generate `#line' directives\n\
   -n, --no-parser            generate the tables only\n\
   -k, --token-table          include a table of token names\n\
-"), stream);
-  putc ('\n', stream);
+"), stdout);
+      putc ('\n', stdout);
 
-  fputs (_("\
+      fputs (_("\
 Output:\n\
   -d, --defines              also produce a header file\n\
   -r, --report=THINGS        also produce details on the automaton\n\
@@ -199,10 +206,10 @@ Output:\n\
   -b, --file-prefix=PREFIX   specify a PREFIX for output files\n\
   -o, --output=FILE          leave output to FILE\n\
   -g, --graph                also produce a VCG description of the automaton\n\
-"), stream);
-  putc ('\n', stream);
+"), stdout);
+      putc ('\n', stdout);
 
-  fputs (_("\
+      fputs (_("\
 THINGS is a list of comma separated words that can include:\n\
   `state'        describe the states\n\
   `itemset'      complete the core item sets with their closure\n\
@@ -210,11 +217,14 @@ THINGS is a list of comma separated words that can include:\n\
   `solved'       describe shift/reduce conflicts solving\n\
   `all'          include all the above information\n\
   `none'         disable the report\n\
-"), stream);
-  putc ('\n', stream);
+"), stdout);
+      putc ('\n', stdout);
 
-  fputs (_("\
-Report bugs to <bug-bison@gnu.org>.\n"), stream);
+      fputs (_("\
+Report bugs to <bug-bison@gnu.org>.\n"), stdout);
+    }
+
+  exit (status);
 }
 
 
@@ -223,23 +233,23 @@ Report bugs to <bug-bison@gnu.org>.\n"), stream);
 `------------------------------*/
 
 static void
-version (FILE *stream)
+version (void)
 {
   /* Some efforts were made to ease the translators' task, please
      continue.  */
-  fprintf (stream, _("bison (GNU Bison) %s"), VERSION);
-  putc ('\n', stream);
-  fputs (_("Written by Robert Corbett and Richard Stallman.\n"), stream);
-  putc ('\n', stream);
+  printf (_("bison (GNU Bison) %s"), VERSION);
+  putc ('\n', stdout);
+  fputs (_("Written by Robert Corbett and Richard Stallman.\n"), stdout);
+  putc ('\n', stdout);
 
-  fprintf (stream,
+  fprintf (stdout,
 	   _("Copyright (C) %d Free Software Foundation, Inc.\n"), 2002);
 
   fputs (_("\
 This is free software; see the source for copying conditions.  There is NO\n\
 warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
 "),
-	 stream);
+	 stdout);
 }
 
 
@@ -327,11 +337,10 @@ getargs (int argc, char *argv[])
 	break;
 
       case 'h':
-	usage (stdout);
-	exit (0);
+	usage (0);
 
       case 'V':
-	version (stdout);
+	version ();
 	exit (0);
 
       case 'g':
@@ -401,14 +410,13 @@ getargs (int argc, char *argv[])
 	exit (1);
       }
 
-  if (optind == argc)
+  if (optind != argc - 1)
     {
-      fprintf (stderr, _("%s: no grammar file given\n"), program_name);
-      exit (1);
+      error (0, 0,
+	     (optind == argc
+	      ? _("too few arguments") : _("too many arguments")));
+      usage (EXIT_FAILURE);
     }
-  if (optind < argc - 1)
-    fprintf (stderr, _("%s: extra arguments ignored after `%s'\n"),
-	     program_name, argv[optind]);
 
   infile = argv[optind];
 }
