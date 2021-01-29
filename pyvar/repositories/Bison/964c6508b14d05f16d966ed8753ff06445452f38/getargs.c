@@ -365,9 +365,9 @@ Mandatory arguments to long options are mandatory for short options too.\n\
       fputs (_("\
 The same is true for optional arguments.\n\
 "), stdout);
+      putc ('\n', stdout);
 
       fputs (_("\
-\n\
 Operation Modes:\n\
   -h, --help                 display this help and exit\n\
   -V, --version              output version information and exit\n\
@@ -376,13 +376,27 @@ Operation Modes:\n\
       --print-datadir        output directory containing skeletons and XSLT\n\
                              and exit\n\
   -u, --update               apply fixes to the source grammar file and exit\n\
+  -f, --feature[=FEATURES]   activate miscellaneous features\n\
+\n\
+"), stdout);
+
+      argmatch_feature_usage (stdout);
+      putc ('\n', stdout);
+
+      fputs (_("\
+Diagnostics:\n\
   -W, --warnings[=CATEGORY]  report the warnings falling in CATEGORY\n\
       --color[=WHEN]         whether to colorize the diagnostics\n\
       --style=FILE           specify the CSS FILE for colorizer diagnostics\n\
-  -f, --feature[=FEATURES]   activate miscellaneous features\n\
 \n\
 "), stdout);
 
+      warning_usage (stdout);
+      putc ('\n', stdout);
+
+      argmatch_color_usage (stdout);
+      putc ('\n', stdout);
+
       fputs (_("\
 Tuning the Parser:\n\
   -L, --language=LANGUAGE          specify the output programming language\n\
@@ -416,18 +430,9 @@ Output Files:\n\
 "), stdout);
       putc ('\n', stdout);
 
-      argmatch_color_usage (stdout);
-      putc ('\n', stdout);
-
-      warning_usage (stdout);
-      putc ('\n', stdout);
-
       argmatch_report_usage (stdout);
       putc ('\n', stdout);
 
-      argmatch_feature_usage (stdout);
-      putc ('\n', stdout);
-
       printf (_("Report bugs to <%s>.\n"), PACKAGE_BUGREPORT);
       printf (_("%s home page: <%s>.\n"), PACKAGE_NAME, PACKAGE_URL);
       fputs (_("General help using GNU software: "
