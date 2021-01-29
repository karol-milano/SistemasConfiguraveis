@@ -423,15 +423,17 @@ Tuning the Parser:\n\
        * won't assume that -d also takes an argument.  */
       fputs (_("\
 Output Files:\n\
-      --defines[=FILE]       also produce a header file\n\
-  -d                         likewise but cannot specify FILE (for POSIX Yacc)\n\
-  -r, --report=THINGS        also produce details on the automaton\n\
-      --report-file=FILE     write report to FILE\n\
-  -v, --verbose              same as '--report=state'\n\
-  -b, --file-prefix=PREFIX   specify a PREFIX for output files\n\
-  -o, --output=FILE          leave output to FILE\n\
-  -g, --graph[=FILE]         also output a graph of the automaton\n\
-  -x, --xml[=FILE]           also output an XML report of the automaton\n\
+      --defines[=FILE]          also produce a header file\n\
+  -d                            likewise but cannot specify FILE (for POSIX Yacc)\n\
+  -r, --report=THINGS           also produce details on the automaton\n\
+      --report-file=FILE        write report to FILE\n\
+  -v, --verbose                 same as '--report=state'\n\
+  -b, --file-prefix=PREFIX      specify a PREFIX for output files\n\
+  -o, --output=FILE             leave output to FILE\n\
+  -g, --graph[=FILE]            also output a graph of the automaton\n\
+  -x, --xml[=FILE]              also output an XML report of the automaton\n\
+  -M, --file-prefix-map=OLD=NEW replace prefix OLD with NEW when writing file paths\n\
+                                in output files\n\
 "), stdout);
       putc ('\n', stdout);
 
@@ -552,6 +554,7 @@ static char const short_options[] =
   "h"
   "k"
   "l"
+  "M:"
   "o:"
   "p:"
   "r:"
@@ -603,14 +606,15 @@ static struct option const long_options[] =
   { "yacc",           no_argument,         0, 'y' },
 
   /* Output Files. */
-  { "defines",     optional_argument,   0,   'd' },
-  { "report",      required_argument,   0,   'r' },
-  { "report-file", required_argument,   0,   REPORT_FILE_OPTION },
-  { "verbose",     no_argument,         0,   'v' },
-  { "file-prefix", required_argument,   0,   'b' },
-  { "output",      required_argument,   0,   'o' },
-  { "graph",       optional_argument,   0,   'g' },
-  { "xml",         optional_argument,   0,   'x' },
+  { "defines",         optional_argument,   0,   'd' },
+  { "report",          required_argument,   0,   'r' },
+  { "report-file",     required_argument,   0,   REPORT_FILE_OPTION },
+  { "verbose",         no_argument,         0,   'v' },
+  { "file-prefix",     required_argument,   0,   'b' },
+  { "output",          required_argument,   0,   'o' },
+  { "graph",           optional_argument,   0,   'g' },
+  { "xml",             optional_argument,   0,   'x' },
+  { "file-prefix-map", required_argument,   0,   'M' },
 
   /* Hidden. */
   { "fixed-output-files", no_argument,       0,  FIXED_OUTPUT_FILES_OPTION },
@@ -716,6 +720,22 @@ getargs (int argc, char *argv[])
         language_argmatch (optarg, command_line_prio, loc);
         break;
 
+      case 'M': // -MOLDPREFIX=NEWPREFIX
+        {
+          char *newprefix = strchr (optarg, '=');
+          if (newprefix)
+            {
+              *newprefix = '\0';
+              add_prefix_map (optarg, newprefix + 1);
+            }
+          else
+            {
+              complain (&loc, complaint, _("invalid argument for %s: %s"),
+                        quote ("--file-prefix-map"), quotearg_n (1, optarg));
+            }
+        }
+        break;
+
       case 'S':
         skeleton_arg (optarg, command_line_prio, loc);
         break;
