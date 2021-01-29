@@ -569,6 +569,7 @@ enum
   STYLE_OPTION
 };
 
+/* In the same order as in usage(), and in the documentation.  */
 static struct option const long_options[] =
 {
   /* Operation modes. */
@@ -577,43 +578,39 @@ static struct option const long_options[] =
   { "print-localedir", no_argument,       0,   PRINT_LOCALEDIR_OPTION },
   { "print-datadir",   no_argument,       0,   PRINT_DATADIR_OPTION   },
   { "update",          no_argument,       0,   'u' },
-  { "warnings",        optional_argument, 0,   'W' },
-
-  /* Parser. */
-  { "name-prefix",   required_argument,   0,   'p' },
-
-  /* Output. */
+  { "feature",         optional_argument, 0,   'f' },
+
+  /* Diagnostics.  */
+  { "warnings",        optional_argument,  0, 'W' },
+  { "color",           optional_argument,  0,  COLOR_OPTION },
+  { "style",           optional_argument,  0,  STYLE_OPTION },
+
+  /* Tuning the Parser. */
+  { "language",       required_argument,   0, 'L' },
+  { "skeleton",       required_argument,   0, 'S' },
+  { "debug",          no_argument,         0, 't' },
+  { "locations",      no_argument,         0, LOCATIONS_OPTION },
+  { "define",         required_argument,   0, 'D' },
+  { "force-define",   required_argument,   0, 'F' },
+  { "name-prefix",    required_argument,   0, 'p' },
+  { "no-lines",       no_argument,         0, 'l' },
+  { "token-table",    no_argument,         0, 'k' },
+  { "yacc",           no_argument,         0, 'y' },
+
+  /* Output Files. */
+  { "defines",     optional_argument,   0,   'd' },
+  { "report",      required_argument,   0,   'r' },
+  { "report-file", required_argument,   0,   REPORT_FILE_OPTION },
+  { "verbose",     no_argument,         0,   'v' },
   { "file-prefix", required_argument,   0,   'b' },
   { "output",      required_argument,   0,   'o' },
-  { "output-file", required_argument,   0,   'o' },
   { "graph",       optional_argument,   0,   'g' },
   { "xml",         optional_argument,   0,   'x' },
-  { "report",      required_argument,   0,   'r' },
-  { "report-file", required_argument,   0,   REPORT_FILE_OPTION },
-  { "verbose",     no_argument,         0,   'v' },
 
   /* Hidden. */
+  { "fixed-output-files", no_argument,  0,  'y' },
+  { "output-file", required_argument,   0,  'o' },
   { "trace",       optional_argument,   0,  'T' },
-  { "color",       optional_argument,   0,  COLOR_OPTION },
-  { "style",       optional_argument,   0,  STYLE_OPTION },
-
-  /* Output.  */
-  { "defines",     optional_argument,   0,   'd' },
-  { "feature",     optional_argument,   0,   'f' },
-
-  /* Operation modes.  */
-  { "fixed-output-files", no_argument,  0,   'y' },
-  { "yacc",               no_argument,  0,   'y' },
-
-  /* Parser.  */
-  { "debug",          no_argument,               0,   't' },
-  { "define",         required_argument,         0,   'D' },
-  { "force-define",   required_argument,         0,   'F' },
-  { "locations",      no_argument,               0, LOCATIONS_OPTION },
-  { "no-lines",       no_argument,               0,   'l' },
-  { "skeleton",       required_argument,         0,   'S' },
-  { "language",       required_argument,         0,   'L' },
-  { "token-table",    no_argument,               0,   'k' },
 
   {0, 0, 0, 0}
 };
