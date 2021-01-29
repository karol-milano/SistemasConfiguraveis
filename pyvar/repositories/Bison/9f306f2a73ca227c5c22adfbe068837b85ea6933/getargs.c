@@ -1,23 +1,22 @@
-/* Parse command line arguments for bison,
-   Copyright (C) 1984, 1986, 1989, 1992 Free Software Foundation, Inc.
+/* Parse command line arguments for bison.
+   Copyright (C) 1984, 1986, 1989, 1992, 2000 Free Software Foundation, Inc.
 
-This file is part of Bison, the GNU Compiler Compiler.
+   This file is part of Bison, the GNU Compiler Compiler.
 
-Bison is free software; you can redistribute it and/or modify
-it under the terms of the GNU General Public License as published by
-the Free Software Foundation; either version 2, or (at your option)
-any later version.
+   Bison is free software; you can redistribute it and/or modify it
+   under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
 
-Bison is distributed in the hope that it will be useful,
-but WITHOUT ANY WARRANTY; without even the implied warranty of
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-GNU General Public License for more details.
-
-You should have received a copy of the GNU General Public License
-along with Bison; see the file COPYING.  If not, write to
-the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
-Boston, MA 02111-1307, USA.  */
+   Bison is distributed in the hope that it will be useful, but
+   WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+   General Public License for more details.
 
+   You should have received a copy of the GNU General Public License
+   along with Bison; see the file COPYING.  If not, write to the Free
+   Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
+   02111-1307, USA.  */
 
 #include <stdio.h>
 #include "getopt.h"
@@ -34,9 +33,6 @@ int rawtoknumflag = 0;
 char *spec_name_prefix; /* for -p.  */
 char *spec_file_prefix; /* for -b. */
 extern int fixed_outfiles;/* for -y */
-  
-void usage PARAMS((FILE *));
-void getargs PARAMS((int, char *[]));
 
 extern char *program_name;
 
@@ -62,17 +58,56 @@ struct option longopts[] =
   {0, 0, 0, 0}
 };
 
+/*---------------------------.
+| Display the help message.  |
+`---------------------------*/
 void
 usage (FILE *stream)
 {
+  /* Some efforts were made to ease the translators' task, please
+     continue.  */
+  fprintf (stream, _("\
+GNU bison generates parsers for LALR(1) grammars.\n"));
+  putc ('\n', stream);
+
+  fprintf (stream, _("\
+Usage: %s [OPTION]... FILE\n"), program_name);
+  putc ('\n', stream);
+
+  fputs (_("\
+If a long option shows an argument as mandatory, then it is mandatory\n\
+for the equivalent short option also.  Similarly for optional arguments.\n"),
+	 stream);
+  putc ('\n', stream);
+
+  fprintf (stream, _("\
+Operation modes:\n\
+  -h, --help      display this help and exit\n\
+  -V, --version   output version information and exit\n\
+  -y, --yacc      emulate POSIX yacc\n"));
+  putc ('\n', stream);
+
+  fprintf (stream, _("\
+Parser:\n\
+  -t, --debug                instrument the parser for debugging\n\
+  -p, --name-prefix=PREFIX   prepend PREFIX to the external symbols\n\
+  -l, --no-lines             don't generate `#line' directives\n\
+  -n, --no-parser            generate the tables only\n\
+  -r, --raw                  number the tokens from 3\n\
+  -k, --token-table          include a table of token names\n\
+"));
+  putc ('\n', stream);
+
+  fprintf (stream, _("\
+Output:\n\
+  -d, --defines              also produce a header file\n\
+  -v, --verbose              also produce an explanation of the automaton\n\
+  -b, --file-prefix=PREFIX   specify a PREFIX for output files\n\
+  -o, --output-file=FILE     leave output to FILE\n"));
+  putc ('\n', stream);
+
   fprintf (stream, _("\
-Usage: %s [-dhklntvyV] [-b file-prefix] [-o outfile] [-p name-prefix]\n\
-       [--debug] [--defines] [--fixed-output-files] [--no-lines]\n\
-       [--verbose] [--version] [--help] [--yacc]\n\
-       [--no-parser] [--token-table]\n\
-       [--file-prefix=prefix] [--name-prefix=prefix]\n\
-       [--output=outfile] grammar-file\n\n\
-Report bugs to bug-bison@gnu.org\n"),
+Report bugs to <bug-bison@gnu.org>.\n"),
 	   program_name);
 }
 
@@ -101,7 +136,7 @@ getargs (int argc, char *argv[])
 	case 'y':
 	  fixed_outfiles = 1;
 	  break;
-	  
+
 	case 'h':
 	  usage (stdout);
 	  exit (0);
@@ -109,19 +144,19 @@ getargs (int argc, char *argv[])
 	case 'V':
 	  printf ("%s\n", VERSION_STRING);
 	  exit (0);
-	  
+
 	case 'v':
 	  verboseflag = 1;
 	  break;
-	  
+
 	case 'd':
 	  definesflag = 1;
 	  break;
-	  
+
 	case 'l':
 	  nolinesflag = 1;
 	  break;
-	  
+
 	case 'k':
 	  toknumflag = 1;
 	  break;
@@ -129,27 +164,27 @@ getargs (int argc, char *argv[])
 	case 'r':
 	  rawtoknumflag = 1;
 	  break;
-	  
+
 	case 'n':
 	  noparserflag = 1;
 	  break;
-	  
+
 	case 't':
 	  debugflag = 1;
 	  break;
-	  
+
 	case 'o':
 	  spec_outfile = optarg;
 	  break;
-	  
+
 	case 'b':
 	  spec_file_prefix = optarg;
 	  break;
-	  
+
 	case 'p':
 	  spec_name_prefix = optarg;
 	  break;
-	  
+
 	default:
 	  usage (stderr);
 	  exit (1);
@@ -162,8 +197,8 @@ getargs (int argc, char *argv[])
       exit(1);
     }
   if (optind < argc - 1)
-    fprintf(stderr, _("%s: extra arguments ignored after '%s'\n"),
-		program_name, argv[optind]);
+    fprintf(stderr, _("%s: extra arguments ignored after `%s'\n"),
+	    program_name, argv[optind]);
 
   infile = argv[optind];
 }
