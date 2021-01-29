@@ -63,6 +63,7 @@ bool error_verbose = false;
 bool nondeterministic_parser = false;
 bool glr_parser = false;
 
+int feature_flag = feature_none;
 int report_flag = report_none;
 int trace_flag = trace_none;
 int warnings_flag = warnings_conflicts_sr | warnings_conflicts_rr
@@ -257,6 +258,26 @@ static const int warnings_types[] =
 
 ARGMATCH_VERIFY (warnings_args, warnings_types);
 
+/*-----------------------.
+| --feature's handling.  |
+`-----------------------*/
+
+static const char * const feature_args[] =
+{
+  "none",
+  "caret", "diagnostics-show-caret",
+  "all",
+  0
+};
+
+static const int feature_types[] =
+{
+  feature_none,
+  feature_caret, feature_caret,
+  feature_all
+};
+
+ARGMATCH_VERIFY (feature_args, feature_types);
 
 /*-------------------------------------------.
 | Display the help message and exit STATUS.  |
@@ -301,6 +322,7 @@ Operation modes:\n\
       --print-datadir        output directory containing skeletons and XSLT\n\
   -y, --yacc                 emulate POSIX Yacc\n\
   -W, --warnings[=CATEGORY]  report the warnings falling in CATEGORY\n\
+  -f, --feature[=FEATURE]    activate miscellaneous features\n\
 \n\
 "), stdout);
 
@@ -316,8 +338,8 @@ Parser:\n\
                                    deprecated by '-Dapi.prefix=PREFIX'\n\
   -l, --no-lines                   don't generate '#line' directives\n\
   -k, --token-table                include a table of token names\n\
-\n\
 "), stdout);
+      putc ('\n', stdout);
 
       /* Keep -d and --defines separate so that ../build-aux/cross-options.pl
        * won't assume that -d also takes an argument.  */
@@ -333,8 +355,8 @@ Output:\n\
   -g, --graph[=FILE]         also output a graph of the automaton\n\
   -x, --xml[=FILE]           also output an XML report of the automaton\n\
                              (the XML schema is experimental)\n\
-\n\
 "), stdout);
+      putc ('\n', stdout);
 
       fputs (_("\
 Warning categories include:\n\
@@ -360,6 +382,14 @@ THINGS is a list of comma separated words that can include:\n\
   `all'          include all the above information\n\
   `none'         disable the report\n\
 "), stdout);
+      putc ('\n', stdout);
+
+      fputs (_("\
+FEATURE is a list of comma separated words that can include:\n\
+  `caret'        show errors with carets\n\
+  `all'          all of the above\n\
+  `none'         disable all of the above\n\
+  "), stdout);
 
       putc ('\n', stdout);
       printf (_("Report bugs to <%s>.\n"), PACKAGE_BUGREPORT);
@@ -469,6 +499,7 @@ static char const short_options[] =
   "W::"
   "b:"
   "d"
+  "f::"
   "e"
   "g::"
   "h"
@@ -521,6 +552,7 @@ static struct option const long_options[] =
 
   /* Output.  */
   { "defines",     optional_argument,   0,   'd' },
+  { "flag",        optional_argument,   0,   'f' },
 
   /* Operation modes.  */
   { "fixed-output-files", no_argument,  0,   'y' },
@@ -613,6 +645,10 @@ getargs (int argc, char *argv[])
 	version ();
 	exit (EXIT_SUCCESS);
 
+      case 'f':
+        FLAGS_ARGMATCH (flag, optarg);
+        break;
+
       case 'W':
 	FLAGS_ARGMATCH (warnings, optarg);
 	break;
