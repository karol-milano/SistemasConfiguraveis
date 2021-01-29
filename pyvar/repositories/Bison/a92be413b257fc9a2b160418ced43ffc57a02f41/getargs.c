@@ -235,29 +235,25 @@ usage (int status)
 	     program_name);
   else
     {
-      /* Some efforts were made to ease the translators' task, please
-	 continue.  */
+      printf (_("Usage: %s [OPTION]... FILE\n"), program_name);
       fputs (_("\
-GNU bison generates LALR(1) and GLR parsers.\n"), stdout);
-      putc ('\n', stdout);
-
-      fprintf (stdout, _("\
-Usage: %s [OPTION]... FILE\n"), program_name);
-      putc ('\n', stdout);
+Generate LALR(1) and GLR parsers.\n\
+\n\
+"), stdout);
 
       fputs (_("\
-If a long option shows an argument as mandatory, then it is mandatory\n\
-for the equivalent short option also.  Similarly for optional arguments.\n"),
-	     stdout);
-      putc ('\n', stdout);
+Mandatory arguments to long options are mandatory for short options too.\n\
+"), stdout);
 
       fputs (_("\
+\n\
 Operation modes:\n\
   -h, --help                 display this help and exit\n\
   -V, --version              output version information and exit\n\
       --print-localedir      output directory containing locale-dependent data\n\
-  -y, --yacc                 emulate POSIX Yacc\n"), stdout);
-      putc ('\n', stdout);
+  -y, --yacc                 emulate POSIX Yacc\n\
+\n\
+"), stdout);
 
       fputs (_("\
 Parser:\n\
@@ -268,8 +264,8 @@ Parser:\n\
   -l, --no-lines             don't generate `#line' directives\n\
   -n, --no-parser            generate the tables only\n\
   -k, --token-table          include a table of token names\n\
+\n\
 "), stdout);
-      putc ('\n', stdout);
 
       fputs (_("\
 Output:\n\
@@ -279,8 +275,8 @@ Output:\n\
   -b, --file-prefix=PREFIX   specify a PREFIX for output files\n\
   -o, --output=FILE          leave output to FILE\n\
   -g, --graph                also produce a VCG description of the automaton\n\
+\n\
 "), stdout);
-      putc ('\n', stdout);
 
       fputs (_("\
 THINGS is a list of comma separated words that can include:\n\
@@ -291,10 +287,8 @@ THINGS is a list of comma separated words that can include:\n\
   `all'          include all the above information\n\
   `none'         disable the report\n\
 "), stdout);
-      putc ('\n', stdout);
 
-      fputs (_("\
-Report bugs to <" PACKAGE_BUGREPORT ">.\n"), stdout);
+      printf (_("\nReport bugs to <%s>.\n"), PACKAGE_BUGREPORT);
     }
 
   exit (status);
