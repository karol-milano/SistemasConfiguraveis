@@ -36,12 +36,13 @@
 #include "quote.h"
 #include "uniqstr.h"
 
-bool defines_flag;
-bool graph_flag;
-bool xml_flag;
-bool no_lines_flag;
-bool token_table_flag;
-bool yacc_flag; /* for -y */
+bool defines_flag = false;
+bool graph_flag = false;
+bool xml_flag = false;
+bool no_lines_flag = false;
+bool token_table_flag = false;
+bool yacc_flag = false; /* for -y */
+bool update_flag = false; /* for -u */
 
 bool nondeterministic_parser = false;
 bool glr_parser = false;
@@ -283,7 +284,10 @@ Operation modes:\n\
   -h, --help                 display this help and exit\n\
   -V, --version              output version information and exit\n\
       --print-localedir      output directory containing locale-dependent data\n\
+                             and exit\n\
       --print-datadir        output directory containing skeletons and XSLT\n\
+                             and exit\n\
+  -u, --update               apply fixes to the source grammar file\n\
   -y, --yacc                 emulate POSIX Yacc\n\
   -W, --warnings[=CATEGORY]  report the warnings falling in CATEGORY\n\
   -f, --feature[=FEATURE]    activate miscellaneous features\n\
@@ -478,6 +482,7 @@ static char const short_options[] =
   "p:"
   "r:"
   "t"
+  "u"   /* --update */
   "v"
   "x::"
   "y"
@@ -499,6 +504,7 @@ static struct option const long_options[] =
   { "version",         no_argument,       0,   'V' },
   { "print-localedir", no_argument,       0,   PRINT_LOCALEDIR_OPTION },
   { "print-datadir",   no_argument,       0,   PRINT_DATADIR_OPTION   },
+  { "update",          no_argument,       0,   'u' },
   { "warnings",        optional_argument, 0,   'W' },
 
   /* Parser. */
@@ -684,6 +690,10 @@ getargs (int argc, char *argv[])
                                       MUSCLE_PERCENT_DEFINE_D);
         break;
 
+      case 'u':
+        update_flag = true;
+        break;
+
       case 'v':
         report_flag |= report_states;
         break;
