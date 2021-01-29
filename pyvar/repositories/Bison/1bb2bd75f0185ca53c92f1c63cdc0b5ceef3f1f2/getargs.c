@@ -282,6 +282,7 @@ Parser:\n\
 Output:\n\
   -d, --defines[=FILE]       also produce a header file\n\
   -r, --report=THINGS        also produce details on the automaton\n\
+      --report-file=FILE     write report to FILE\n\
   -v, --verbose              same as `--report=state'\n\
   -b, --file-prefix=PREFIX   specify a PREFIX for output files\n\
   -o, --output=FILE          leave output to FILE\n\
@@ -408,7 +409,8 @@ enum
 {
   LOCATIONS_OPTION = CHAR_MAX + 1,
   PRINT_LOCALEDIR_OPTION,
-  PRINT_DATADIR_OPTION
+  PRINT_DATADIR_OPTION,
+  REPORT_FILE_OPTION
 };
 
 static struct option const long_options[] =
@@ -431,6 +433,7 @@ static struct option const long_options[] =
   { "graph",	   optional_argument,	0,   'g' },
   { "xml",         optional_argument,   0,   'x' },
   { "report",	   required_argument,   0,   'r' },
+  { "report-file", required_argument,   0,   REPORT_FILE_OPTION },
   { "verbose",	   no_argument,	        0,   'v' },
 
   /* Hidden. */
@@ -536,6 +539,10 @@ getargs (int argc, char *argv[])
 	FLAGS_ARGMATCH (report, optarg);
 	break;
 
+      case REPORT_FILE_OPTION:
+	spec_verbose_file = xstrdup (AS_FILE_NAME (optarg));
+	break;
+
       case 'T':
 	FLAGS_ARGMATCH (trace, optarg);
 	break;
