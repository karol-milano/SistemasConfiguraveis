@@ -48,6 +48,7 @@
 bool debug_flag;
 bool defines_flag;
 bool graph_flag;
+bool xml_flag;
 bool locations_flag;
 bool no_lines_flag;
 bool token_table_flag;
@@ -285,6 +286,7 @@ Output:\n\
   -b, --file-prefix=PREFIX   specify a PREFIX for output files\n\
   -o, --output=FILE          leave output to FILE\n\
   -g, --graph                also output a graph of the automaton\n\
+  -x, --xml                  also output an xml of the automaton\n\
 \n\
 "), stdout);
 
@@ -387,7 +389,7 @@ language_argmatch (char const *arg, int prio, location const *loc)
 `----------------------*/
 
 /* Shorts options.  */
-static char const short_options[] = "yvegdhr:L:ltknVo:b:p:S:T::W";
+static char const short_options[] = "yvegxdhr:L:ltknVo:b:p:S:T::W";
 
 /* Values for long options that do not have single-letter equivalents.  */
 enum
@@ -413,6 +415,7 @@ static struct option const long_options[] =
   { "output",	   required_argument,	0,   'o' },
   { "output-file", required_argument,	0,   'o' },
   { "graph",	   optional_argument,	0,   'g' },
+  { "xml",         optional_argument,   0,   'x' },
   { "report",	   required_argument,   0,   'r' },
   { "verbose",	   no_argument,	        0,   'v' },
 
@@ -470,6 +473,13 @@ getargs (int argc, char *argv[])
 	  spec_graph_file = xstrdup (AS_FILE_NAME (optarg));
 	break;
 
+      case 'x':
+	/* Here, the -x and --xml=FILE options are differentiated.  */
+	xml_flag = true;
+	if (optarg)
+	  spec_xml_file = xstrdup (AS_FILE_NAME (optarg));
+	break;
+
       case 'h':
 	usage (EXIT_SUCCESS);
 
