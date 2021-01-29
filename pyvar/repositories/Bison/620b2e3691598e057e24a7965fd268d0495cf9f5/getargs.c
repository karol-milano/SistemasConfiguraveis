@@ -272,12 +272,12 @@ The same is true for optional arguments.\n\
       fputs (_("\
 \n\
 Operation modes:\n\
-  -h, --help                       display this help and exit\n\
-  -V, --version                    output version information and exit\n\
-      --print-localedir            output directory of locale-dependent data\n\
-      --print-datadir              output directory of skeletons and XSLT\n\
-  -y, --yacc                       emulate POSIX Yacc\n\
-  -W, --warnings[=CATEGORY]        report the warnings falling in CATEGORY\n\
+  -h, --help                 display this help and exit\n\
+  -V, --version              output version information and exit\n\
+      --print-localedir      output directory containing locale-dependent data\n\
+      --print-datadir        output directory containing skeletons and XSLT\n\
+  -y, --yacc                 emulate POSIX Yacc\n\
+  -W, --warnings[=CATEGORY]  report the warnings falling in CATEGORY\n\
 \n\
 "), stdout);
 
@@ -300,16 +300,16 @@ Parser:\n\
        * won't assume that -d also takes an argument.  */
       fputs (_("\
 Output:\n\
-      --defines[=FILE]             also produce a header file\n\
-  -d                               likewise but cannot specify FILE (for POSIX)\n\
-  -r, --report=THINGS              also produce details on the automaton\n\
-      --report-file=FILE           write report to FILE\n\
-  -v, --verbose                    same as `--report=state'\n\
-  -b, --file-prefix=PREFIX         specify a PREFIX for output files\n\
-  -o, --output=FILE                leave output to FILE\n\
-  -g, --graph[=FILE]               also output a graph of the automaton\n\
-  -x, --xml[=FILE]                 also output an XML report of the automaton\n\
-                                   (the XML schema is experimental)\n\
+      --defines[=FILE]       also produce a header file\n\
+  -d                         likewise but cannot specify FILE (for POSIX Yacc)\n\
+  -r, --report=THINGS        also produce details on the automaton\n\
+      --report-file=FILE     write report to FILE\n\
+  -v, --verbose              same as `--report=state'\n\
+  -b, --file-prefix=PREFIX   specify a PREFIX for output files\n\
+  -o, --output=FILE          leave output to FILE\n\
+  -g, --graph[=FILE]         also output a graph of the automaton\n\
+  -x, --xml[=FILE]           also output an XML report of the automaton\n\
+                             (the XML schema is experimental)\n\
 \n\
 "), stdout);
 
