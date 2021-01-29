@@ -272,26 +272,27 @@ The same is true for optional arguments.\n\
       fputs (_("\
 \n\
 Operation modes:\n\
-  -h, --help                 display this help and exit\n\
-  -V, --version              output version information and exit\n\
-      --print-localedir      output directory containing locale-dependent data\n\
-      --print-datadir        output directory containing skeletons and XSLT\n\
-  -y, --yacc                 emulate POSIX Yacc\n\
-  -W, --warnings[=CATEGORY]  report the warnings falling in CATEGORY\n\
+  -h, --help                       display this help and exit\n\
+  -V, --version                    output version information and exit\n\
+      --print-localedir            output directory of locale-dependent data\n\
+      --print-datadir              output directory of skeletons and XSLT\n\
+  -y, --yacc                       emulate POSIX Yacc\n\
+  -W, --warnings[=CATEGORY]        report the warnings falling in CATEGORY\n\
 \n\
 "), stdout);
 
       fputs (_("\
 Parser:\n\
-  -L, --language=LANGUAGE    specify the output programming language\n\
-                             (this is an experimental feature)\n\
-  -S, --skeleton=FILE        specify the skeleton to use\n\
-  -t, --debug                instrument the parser for debugging\n\
-      --locations            enable location support\n\
-  -D, --define=NAME[=VALUE]  same as `%define NAME \"VALUE\"'\n\
-  -p, --name-prefix=PREFIX   prepend PREFIX to the external symbols\n\
-  -l, --no-lines             don't generate `#line' directives\n\
-  -k, --token-table          include a table of token names\n\
+  -L, --language=LANGUAGE          specify the output programming language\n\
+                                   (this is an experimental feature)\n\
+  -S, --skeleton=FILE              specify the skeleton to use\n\
+  -t, --debug                      instrument the parser for debugging\n\
+      --locations                  enable location support\n\
+  -D, --define=NAME[=VALUE]        similar to `%define NAME \"VALUE\"'\n\
+  -F, --force-define=NAME[=VALUE]  override `%define NAME \"VALUE\"'\n\
+  -p, --name-prefix=PREFIX         prepend PREFIX to the external symbols\n\
+  -l, --no-lines                   don't generate `#line' directives\n\
+  -k, --token-table                include a table of token names\n\
 \n\
 "), stdout);
 
@@ -299,16 +300,16 @@ Parser:\n\
        * won't assume that -d also takes an argument.  */
       fputs (_("\
 Output:\n\
-      --defines[=FILE]       also produce a header file\n\
-  -d                         likewise but cannot specify FILE (for POSIX Yacc)\n\
-  -r, --report=THINGS        also produce details on the automaton\n\
-      --report-file=FILE     write report to FILE\n\
-  -v, --verbose              same as `--report=state'\n\
-  -b, --file-prefix=PREFIX   specify a PREFIX for output files\n\
-  -o, --output=FILE          leave output to FILE\n\
-  -g, --graph[=FILE]         also output a graph of the automaton\n\
-  -x, --xml[=FILE]           also output an XML report of the automaton\n\
-                             (the XML schema is experimental)\n\
+      --defines[=FILE]             also produce a header file\n\
+  -d                               likewise but cannot specify FILE (for POSIX)\n\
+  -r, --report=THINGS              also produce details on the automaton\n\
+      --report-file=FILE           write report to FILE\n\
+  -v, --verbose                    same as `--report=state'\n\
+  -b, --file-prefix=PREFIX         specify a PREFIX for output files\n\
+  -o, --output=FILE                leave output to FILE\n\
+  -g, --graph[=FILE]               also output a graph of the automaton\n\
+  -x, --xml[=FILE]                 also output an XML report of the automaton\n\
+                                   (the XML schema is experimental)\n\
 \n\
 "), stdout);
 
@@ -415,6 +416,7 @@ language_argmatch (char const *arg, int prio, location loc)
    Should be computed from long_options.  */
 static char const short_options[] =
   "D:"
+  "F:"
   "L:"
   "S:"
   "T::"
@@ -482,6 +484,7 @@ static struct option const long_options[] =
   /* Parser.  */
   { "debug",	      no_argument,               0,   't' },
   { "define",	      required_argument,         0,   'D' },
+  { "force-define",   required_argument,         0,   'F' },
   { "locations",      no_argument,		 0, LOCATIONS_OPTION },
   { "no-lines",       no_argument,               0,   'l' },
   { "raw",            no_argument,               0,     0 },
@@ -530,13 +533,16 @@ getargs (int argc, char *argv[])
 	break;
 
       case 'D': /* -DNAME[=VALUE]. */
+      case 'F': /* -FNAME[=VALUE]. */
         {
           char* name = optarg;
           char* value = strchr (optarg, '=');
           if (value)
             *value++ = 0;
           muscle_percent_define_insert (name, command_line_location (),
-                                        value ? value : "");
+                                        value ? value : "",
+                                        c == 'D' ? MUSCLE_PERCENT_DEFINE_D
+                                                 : MUSCLE_PERCENT_DEFINE_F);
         }
 	break;
 
