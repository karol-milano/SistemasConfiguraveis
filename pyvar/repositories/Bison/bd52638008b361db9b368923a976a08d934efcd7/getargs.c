@@ -343,13 +343,14 @@ Warning categories include:\n\
   `yacc'            incompatibilities with POSIX Yacc\n\
   `conflicts-sr'    S/R conflicts (enabled by default)\n\
   `conflicts-rr'    R/R conflicts (enabled by default)\n\
+  `deprecated'      obsolete constructs\n\
   `other'           all other warnings (enabled by default)\n\
   `all'             all the warnings\n\
   `no-CATEGORY'     turn off warnings in CATEGORY\n\
   `none'            turn off all the warnings\n\
   `error'           treat warnings as errors\n\
-\n\
 "), stdout);
+      putc ('\n', stdout);
 
       fputs (_("\
 THINGS is a list of comma separated words that can include:\n\
