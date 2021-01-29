@@ -66,8 +66,8 @@ usage (FILE *stream)
 {
   /* Some efforts were made to ease the translators' task, please
      continue.  */
-  fprintf (stream, _("\
-GNU bison generates parsers for LALR(1) grammars.\n"));
+  fputs (_("\
+GNU bison generates parsers for LALR(1) grammars.\n"), stream);
   putc ('\n', stream);
 
   fprintf (stream, _("\
@@ -80,14 +80,14 @@ for the equivalent short option also.  Similarly for optional arguments.\n"),
 	 stream);
   putc ('\n', stream);
 
-  fprintf (stream, _("\
+  fputs (_("\
 Operation modes:\n\
   -h, --help      display this help and exit\n\
   -V, --version   output version information and exit\n\
-  -y, --yacc      emulate POSIX yacc\n"));
+  -y, --yacc      emulate POSIX yacc\n"), stream);
   putc ('\n', stream);
 
-  fprintf (stream, _("\
+  fputs (_("\
 Parser:\n\
   -t, --debug                instrument the parser for debugging\n\
   -p, --name-prefix=PREFIX   prepend PREFIX to the external symbols\n\
@@ -95,20 +95,19 @@ Parser:\n\
   -n, --no-parser            generate the tables only\n\
   -r, --raw                  number the tokens from 3\n\
   -k, --token-table          include a table of token names\n\
-"));
+"), stream);
   putc ('\n', stream);
 
-  fprintf (stream, _("\
+  fputs (_("\
 Output:\n\
   -d, --defines              also produce a header file\n\
   -v, --verbose              also produce an explanation of the automaton\n\
   -b, --file-prefix=PREFIX   specify a PREFIX for output files\n\
-  -o, --output-file=FILE     leave output to FILE\n"));
+  -o, --output-file=FILE     leave output to FILE\n"), stream);
   putc ('\n', stream);
 
-  fprintf (stream, _("\
-Report bugs to <bug-bison@gnu.org>.\n"),
-	   program_name);
+  fputs (_("\
+Report bugs to <bug-bison@gnu.org>.\n"), stream);
 }
 
 void
