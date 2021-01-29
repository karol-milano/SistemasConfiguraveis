@@ -253,6 +253,9 @@ Generate LALR(1) and GLR parsers.\n\
 
       fputs (_("\
 Mandatory arguments to long options are mandatory for short options too.\n\
+"), stdout);
+      fputs (_("\
+The same is true for optional arguments.\n\
 "), stdout);
 
       fputs (_("\
@@ -279,9 +282,12 @@ Parser:\n\
 \n\
 "), stdout);
 
+      /* Keep -d and --defines separate so that ../build-aux/cross-options.pl
+       * won't assume that -d also takes an argument.  */
       fputs (_("\
 Output:\n\
-  -d, --defines[=FILE]       also produce a header file\n\
+      --defines[=FILE]       also produce a header file\n\
+  -d                         likewise but cannot specify FILE (for POSIX Yacc)\n\
   -r, --report=THINGS        also produce details on the automaton\n\
       --report-file=FILE     write report to FILE\n\
   -v, --verbose              same as `--report=state'\n\
@@ -410,7 +416,7 @@ static char const short_options[] =
   "S:"
   "T::"
   "V"
-  "W"
+  "W::"
   "b:"
   "d"
   "e"
@@ -503,27 +509,17 @@ getargs (int argc, char *argv[])
 	/* Certain long options cause getopt_long to return 0.  */
 	break;
 
-      case 'b':
-	spec_file_prefix = AS_FILE_NAME (optarg);
-	break;
-
-      case 'g':
-	/* Here, the -g and --graph=FILE options are differentiated.  */
-	graph_flag = true;
+      case 'd':
+	/* Here, the -d and --defines options are differentiated.  */
+	defines_flag = true;
 	if (optarg)
-	  spec_graph_file = xstrdup (AS_FILE_NAME (optarg));
+	  spec_defines_file = xstrdup (AS_FILE_NAME (optarg));
 	break;
 
-      case 'x':
-	/* Here, the -x and --xml=FILE options are differentiated.  */
-	xml_flag = true;
-	if (optarg)
-	  spec_xml_file = xstrdup (AS_FILE_NAME (optarg));
+      case 'I':
+	include = AS_FILE_NAME (optarg);
 	break;
 
-      case 'h':
-	usage (EXIT_SUCCESS);
-
       case 'L':
 	language_argmatch (optarg, 0, NULL);
 	break;
@@ -532,17 +528,34 @@ getargs (int argc, char *argv[])
 	skeleton_arg (AS_FILE_NAME (optarg), 0, NULL);
 	break;
 
-      case 'I':
-	include = AS_FILE_NAME (optarg);
+      case 'T':
+	FLAGS_ARGMATCH (trace, optarg);
 	break;
 
-      case 'd':
-	/* Here, the -d and --defines options are differentiated.  */
-	defines_flag = true;
+      case 'V':
+	version ();
+	exit (EXIT_SUCCESS);
+
+      case 'W':
 	if (optarg)
-	  spec_defines_file = xstrdup (AS_FILE_NAME (optarg));
+	  FLAGS_ARGMATCH (warnings, optarg);
+	else
+	  warnings_flag |= warnings_all;
+	break;
+
+      case 'b':
+	spec_file_prefix = AS_FILE_NAME (optarg);
+	break;
+
+      case 'g':
+	graph_flag = true;
+	if (optarg)
+	  spec_graph_file = xstrdup (AS_FILE_NAME (optarg));
 	break;
 
+      case 'h':
+	usage (EXIT_SUCCESS);
+
       case 'k':
 	token_table_flag = true;
 	break;
@@ -563,35 +576,22 @@ getargs (int argc, char *argv[])
 	FLAGS_ARGMATCH (report, optarg);
 	break;
 
-      case REPORT_FILE_OPTION:
-	spec_verbose_file = xstrdup (AS_FILE_NAME (optarg));
-	break;
-
-      case 'T':
-	FLAGS_ARGMATCH (trace, optarg);
-	break;
-
       case 't':
 	debug_flag = true;
 	break;
 
-      case 'V':
-	version ();
-	exit (EXIT_SUCCESS);
-
       case 'v':
 	report_flag |= report_states;
 	break;
 
-      case 'y':
-	yacc_flag = true;
+      case 'x':
+	xml_flag = true;
+	if (optarg)
+	  spec_xml_file = xstrdup (AS_FILE_NAME (optarg));
 	break;
 
-      case 'W':
-	if (optarg)
-	  FLAGS_ARGMATCH (warnings, optarg);
-	else
-	  warnings_flag |= warnings_all;
+      case 'y':
+	yacc_flag = true;
 	break;
 
       case LOCATIONS_OPTION:
@@ -606,6 +606,10 @@ getargs (int argc, char *argv[])
 	printf ("%s\n", compute_pkgdatadir ());
 	exit (EXIT_SUCCESS);
 
+      case REPORT_FILE_OPTION:
+	spec_verbose_file = xstrdup (AS_FILE_NAME (optarg));
+	break;
+
       default:
 	usage (EXIT_FAILURE);
       }
