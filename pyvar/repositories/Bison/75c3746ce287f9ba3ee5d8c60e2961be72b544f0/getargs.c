@@ -38,7 +38,7 @@
 #include "output.h"
 #include "uniqstr.h"
 
-bool defines_flag = false;
+bool header_flag = false;
 bool graph_flag = false;
 bool xml_flag = false;
 bool no_lines_flag = false;
@@ -422,11 +422,9 @@ Tuning the Parser:\n\
 "), stdout);
       putc ('\n', stdout);
 
-      /* Keep -d and --defines separate so that ../build-aux/cross-options.pl
-       * won't assume that -d also takes an argument.  */
       fputs (_("\
 Output Files:\n\
-      --defines[=FILE]          also produce a header file\n\
+  -H, --header=[FILE]           also produce a header file\n\
   -d                            likewise but cannot specify FILE (for POSIX Yacc)\n\
   -r, --report=THINGS           also produce details on the automaton\n\
       --report-file=FILE        write report to FILE\n\
@@ -545,6 +543,7 @@ language_argmatch (char const *arg, int prio, location loc)
 static char const short_options[] =
   "D:"
   "F:"
+  "H::"
   "L:"
   "S:"
   "T::"
@@ -609,6 +608,7 @@ static struct option const long_options[] =
   { "yacc",           no_argument,         0, 'y' },
 
   /* Output Files. */
+  { "header",          optional_argument,   0,   'H' },
   { "defines",         optional_argument,   0,   'd' },
   { "report",          required_argument,   0,   'r' },
   { "report-file",     required_argument,   0,   REPORT_FILE_OPTION },
@@ -719,6 +719,16 @@ getargs (int argc, char *argv[])
         }
         break;
 
+      case 'H':
+      case 'd':
+        header_flag = true;
+        if (optarg)
+          {
+            free (spec_header_file);
+            spec_header_file = xstrdup (optarg);
+          }
+        break;
+
       case 'L':
         language_argmatch (optarg, command_line_prio, loc);
         break;
@@ -763,16 +773,6 @@ getargs (int argc, char *argv[])
         spec_file_prefix = optarg;
         break;
 
-      case 'd':
-        /* Here, the -d and --defines options are differentiated.  */
-        defines_flag = true;
-        if (optarg)
-          {
-            free (spec_header_file);
-            spec_header_file = xstrdup (optarg);
-          }
-        break;
-
       case 'g':
         graph_flag = true;
         if (optarg)
