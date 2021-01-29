@@ -89,7 +89,9 @@ Output:\n\
   -d, --defines              also produce a header file\n\
   -v, --verbose              also produce an explanation of the automaton\n\
   -b, --file-prefix=PREFIX   specify a PREFIX for output files\n\
-  -o, --output-file=FILE     leave output to FILE\n"), stream);
+  -o, --output-file=FILE     leave output to FILE\n\
+  -g, --graph                also produce a VCG graph description of the \
+automaton\n"), stream);
   putc ('\n', stream);
 
   fputs (_("\
@@ -153,7 +155,9 @@ getargs (int argc, char *argv[])
 	exit (0);
 
       case 'g':
+	/* Here, the -g and --graph=FILE options are differentiated.  */
 	graph_flag = 1;
+	spec_graph_file = optarg;
 	break;
 
       case 'v':
@@ -165,7 +169,9 @@ getargs (int argc, char *argv[])
 	break;
 
       case 'd':
+	/* Here, the -d and --defines options are differentiated.  */
 	defines_flag = 1;
+	spec_defines_file = optarg;
 	break;
 
       case 'l':
