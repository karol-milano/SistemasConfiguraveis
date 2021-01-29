@@ -89,9 +89,9 @@ Output:\n\
   -d, --defines              also produce a header file\n\
   -v, --verbose              also produce an explanation of the automaton\n\
   -b, --file-prefix=PREFIX   specify a PREFIX for output files\n\
-  -o, --output-file=FILE     leave output to FILE\n\
-  -g, --graph                also produce a VCG graph description of the \
-automaton\n"), stream);
+  -o, --output=FILE          leave output to FILE\n\
+  -g, --graph                also produce a VCG description of the automaton\n\
+"), stream);
   putc ('\n', stream);
 
   fputs (_("\
