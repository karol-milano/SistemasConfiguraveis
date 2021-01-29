@@ -250,7 +250,7 @@ static void
 usage (int status)
 {
   if (status != 0)
-    fprintf (stderr, _("Try `%s --help' for more information.\n"),
+    fprintf (stderr, _("Try '%s --help' for more information.\n"),
              program_name);
   else
     {
@@ -292,7 +292,7 @@ Parser:\n\
   -L, --language=LANGUAGE          specify the output programming language\n\
   -S, --skeleton=FILE              specify the skeleton to use\n\
   -t, --debug                      instrument the parser for tracing\n\
-                                   same as `-Dparse.trace'\n\
+                                   same as '-Dparse.trace'\n\
       --locations                  enable location support\n\
   -D, --define=NAME[=VALUE]        similar to '%define NAME \"VALUE\"'\n\
   -F, --force-define=NAME[=VALUE]  override '%define NAME \"VALUE\"'\n\
@@ -311,7 +311,7 @@ Output:\n\
   -d                         likewise but cannot specify FILE (for POSIX Yacc)\n\
   -r, --report=THINGS        also produce details on the automaton\n\
       --report-file=FILE     write report to FILE\n\
-  -v, --verbose              same as `--report=state'\n\
+  -v, --verbose              same as '--report=state'\n\
   -b, --file-prefix=PREFIX   specify a PREFIX for output files\n\
   -o, --output=FILE          leave output to FILE\n\
   -g, --graph[=FILE]         also output a graph of the automaton\n\
@@ -322,37 +322,37 @@ Output:\n\
 
       fputs (_("\
 Warning categories include:\n\
-  `midrule-values'    unset or unused midrule values\n\
-  `yacc'              incompatibilities with POSIX Yacc\n\
-  `conflicts-sr'      S/R conflicts (enabled by default)\n\
-  `conflicts-rr'      R/R conflicts (enabled by default)\n\
-  `deprecated'        obsolete constructs\n\
-  `empty-rule'        empty rules without %empty\n\
-  `precedence'        useless precedence and associativity\n\
-  `other'             all other warnings (enabled by default)\n\
-  `all'               all the warnings\n\
-  `no-CATEGORY'       turn off warnings in CATEGORY\n\
-  `none'              turn off all the warnings\n\
-  `error[=CATEGORY]'  treat warnings as errors\n\
+  'midrule-values'    unset or unused midrule values\n\
+  'yacc'              incompatibilities with POSIX Yacc\n\
+  'conflicts-sr'      S/R conflicts (enabled by default)\n\
+  'conflicts-rr'      R/R conflicts (enabled by default)\n\
+  'deprecated'        obsolete constructs\n\
+  'empty-rule'        empty rules without %empty\n\
+  'precedence'        useless precedence and associativity\n\
+  'other'             all other warnings (enabled by default)\n\
+  'all'               all the warnings\n\
+  'no-CATEGORY'       turn off warnings in CATEGORY\n\
+  'none'              turn off all the warnings\n\
+  'error[=CATEGORY]'  treat warnings as errors\n\
 "), stdout);
       putc ('\n', stdout);
 
       fputs (_("\
 THINGS is a list of comma separated words that can include:\n\
-  `state'        describe the states\n\
-  `itemset'      complete the core item sets with their closure\n\
-  `lookahead'    explicitly associate lookahead tokens to items\n\
-  `solved'       describe shift/reduce conflicts solving\n\
-  `all'          include all the above information\n\
-  `none'         disable the report\n\
+  'state'        describe the states\n\
+  'itemset'      complete the core item sets with their closure\n\
+  'lookahead'    explicitly associate lookahead tokens to items\n\
+  'solved'       describe shift/reduce conflicts solving\n\
+  'all'          include all the above information\n\
+  'none'         disable the report\n\
 "), stdout);
       putc ('\n', stdout);
 
       fputs (_("\
 FEATURE is a list of comma separated words that can include:\n\
-  `caret'        show errors with carets\n\
-  `all'          all of the above\n\
-  `none'         disable all of the above\n\
+  'caret'        show errors with carets\n\
+  'all'          all of the above\n\
+  'none'         disable all of the above\n\
   "), stdout);
 
       putc ('\n', stdout);
