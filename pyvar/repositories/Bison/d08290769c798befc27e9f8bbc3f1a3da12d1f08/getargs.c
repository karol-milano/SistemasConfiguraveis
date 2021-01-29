@@ -43,15 +43,15 @@
 #include "getargs.h"
 #include "uniqstr.h"
 
-int debug_flag = 0;
-int defines_flag = 0;
-int locations_flag = 0;
-int no_lines_flag = 0;
-int no_parser_flag = 0;
+bool debug_flag;
+bool defines_flag;
+bool locations_flag;
+bool no_lines_flag;
+bool no_parser_flag;
 int report_flag = report_none;
-int token_table_flag = 0;
-int yacc_flag = 0;	/* for -y */
-int graph_flag = 0;
+bool token_table_flag;
+bool yacc_flag;	/* for -y */
+bool graph_flag;
 int trace_flag = trace_none;
 
 bool nondeterministic_parser = false;
@@ -284,6 +284,12 @@ warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
 /* Shorts options.  */
 const char *short_options = "yvegdhr:ltknVo:b:p:S:T::";
 
+/* Values for long options that do not have single-letter equivalents.  */
+enum
+{
+  LOCATIONS_OPTION = CHAR_MAX + 1
+};
+
 static struct option const long_options[] =
 {
   /* Operation modes. */
@@ -314,7 +320,7 @@ static struct option const long_options[] =
 
   /* Parser.  */
   { "debug",	      no_argument,               0,   't' },
-  { "locations",      no_argument, &locations_flag,     1 },
+  { "locations",      no_argument,		 0, LOCATIONS_OPTION },
   { "no-lines",       no_argument,               0,   'l' },
   { "no-parser",      no_argument,               0,   'n' },
   { "raw",            no_argument,               0,     0 },
@@ -346,7 +352,7 @@ getargs (int argc, char *argv[])
 	break;
 
       case 'y':
-	yacc_flag = 1;
+	yacc_flag = true;
 	break;
 
       case 'h':
@@ -358,7 +364,7 @@ getargs (int argc, char *argv[])
 
       case 'g':
 	/* Here, the -g and --graph=FILE options are differentiated.  */
-	graph_flag = 1;
+	graph_flag = true;
 	if (optarg)
 	  spec_graph_file = AS_FILE_NAME (optarg);
 	break;
@@ -377,25 +383,29 @@ getargs (int argc, char *argv[])
 
       case 'd':
 	/* Here, the -d and --defines options are differentiated.  */
-	defines_flag = 1;
+	defines_flag = true;
 	if (optarg)
 	  spec_defines_file = AS_FILE_NAME (optarg);
 	break;
 
       case 'l':
-	no_lines_flag = 1;
+	no_lines_flag = true;
+	break;
+
+      case LOCATIONS_OPTION:
+	locations_flag = true;
 	break;
 
       case 'k':
-	token_table_flag = 1;
+	token_table_flag = true;
 	break;
 
       case 'n':
-	no_parser_flag = 1;
+	no_parser_flag = true;
 	break;
 
       case 't':
-	debug_flag = 1;
+	debug_flag = true;
 	break;
 
       case 'o':
