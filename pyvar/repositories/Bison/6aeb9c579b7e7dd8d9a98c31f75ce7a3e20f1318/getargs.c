@@ -263,6 +263,7 @@ Operation modes:\n\
       --print-localedir      output directory containing locale-dependent data\n\
       --print-datadir        output directory containing skeletons and XSLT\n\
   -y, --yacc                 emulate POSIX Yacc\n\
+  -W, --warnings=[CATEGORY]  report the warnings falling in CATEGORY\n\
 \n\
 "), stdout);
 
@@ -279,16 +280,26 @@ Parser:\n\
 
       fputs (_("\
 Output:\n\
-  -d, --defines              also produce a header file\n\
+  -d, --defines[=FILE]       also produce a header file\n\
   -r, --report=THINGS        also produce details on the automaton\n\
   -v, --verbose              same as `--report=state'\n\
   -b, --file-prefix=PREFIX   specify a PREFIX for output files\n\
   -o, --output=FILE          leave output to FILE\n\
-  -g, --graph                also output a graph of the automaton\n\
-  -x, --xml                  also output an xml of the automaton\n\
+  -g, --graph[=FILE]         also output a graph of the automaton\n\
+  -x, --xml[=FILE]           also output an XML report of the automaton\n\
 \n\
 "), stdout);
 
+      fputs (_("\
+Warning categories include:\n\
+  `midrule-values'  unset or unused midrule values\n\
+  `yacc'            incompatibilities with POSIX YACC\n\
+  `all'             all the warnings\n\
+  `no-CATEGORY'     turn off warnings in CATEGORY\n\
+  `none'            turn off all the warnings\n\
+  `error'           treat warnings as errors\n\
+"), stdout);
+
       fputs (_("\
 THINGS is a list of comma separated words that can include:\n\
   `state'        describe the states\n\
