@@ -368,7 +368,7 @@ The same is true for optional arguments.\n\
 
       fputs (_("\
 \n\
-Operation modes:\n\
+Operation Modes:\n\
   -h, --help                 display this help and exit\n\
   -V, --version              output version information and exit\n\
       --print-localedir      output directory containing locale-dependent data\n\
@@ -376,7 +376,6 @@ Operation modes:\n\
       --print-datadir        output directory containing skeletons and XSLT\n\
                              and exit\n\
   -u, --update               apply fixes to the source grammar file and exit\n\
-  -y, --yacc                 emulate POSIX Yacc\n\
   -W, --warnings[=CATEGORY]  report the warnings falling in CATEGORY\n\
       --color[=WHEN]         whether to colorize the diagnostics\n\
       --style=FILE           specify the CSS FILE for colorizer diagnostics\n\
@@ -385,7 +384,7 @@ Operation modes:\n\
 "), stdout);
 
       fputs (_("\
-Parser:\n\
+Tuning the Parser:\n\
   -L, --language=LANGUAGE          specify the output programming language\n\
   -S, --skeleton=FILE              specify the skeleton to use\n\
   -t, --debug                      instrument the parser for tracing\n\
@@ -397,13 +396,14 @@ Parser:\n\
                                    deprecated by '-Dapi.prefix=PREFIX'\n\
   -l, --no-lines                   don't generate '#line' directives\n\
   -k, --token-table                include a table of token names\n\
+  -y, --yacc                       emulate POSIX Yacc\n\
 "), stdout);
       putc ('\n', stdout);
 
       /* Keep -d and --defines separate so that ../build-aux/cross-options.pl
        * won't assume that -d also takes an argument.  */
       fputs (_("\
-Output:\n\
+Output Files:\n\
       --defines[=FILE]       also produce a header file\n\
   -d                         likewise but cannot specify FILE (for POSIX Yacc)\n\
   -r, --report=THINGS        also produce details on the automaton\n\
