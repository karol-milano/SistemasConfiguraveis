@@ -19,22 +19,21 @@
    Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
    02111-1307, USA.  */
 
-#include <stdio.h>
-#include "getopt.h"
 #include "system.h"
-#include "files.h"
+#include "getopt.h"
+#include "argmatch.h"
 #include "complain.h"
 #include "getargs.h"
-#include "xalloc.h"
 #include "options.h"
+#include "files.h"
 
 int debug_flag = 0;
 int defines_flag = 0;
 int locations_flag = 0;
 int no_lines_flag = 0;
 int no_parser_flag = 0;
+int report_flag = 0;
 int token_table_flag = 0;
-int verbose_flag = 0;
 int yacc_flag = 0;	/* for -y */
 int graph_flag = 0;
 int trace_flag = 0;
@@ -44,6 +43,48 @@ const char *include = NULL;
 
 extern char *program_name;
 
+/*----------------------.
+| --report's handling.  |
+`----------------------*/
+
+static const char * const report_args[] =
+{
+  /* In a series of synonyms, present the most meaningful first, so
+     that argmatch_valid be more readable.  */
+  "none",
+  "state", "states",
+  "itemset", "itemsets",
+  "lookahead", "lookaheads",
+  "all",
+  0
+};
+
+static const int report_types[] =
+{
+  report_none,
+  report_states, report_states,
+  report_states | report_itemsets, report_states | report_itemsets,
+  report_states | report_lookaheads, report_states | report_lookaheads,
+  report_all
+};
+
+
+static void
+report_argmatch (char *args)
+{
+  ARGMATCH_ASSERT (report_args, report_types);
+  do
+    {
+      int report = XARGMATCH ("--report", args,
+			      report_args, report_types);
+      if (report == report_none)
+	report_flag = report_none;
+      else
+	report_flag |= report;
+    }
+  while ((args = strtok (NULL, ",")));
+}
+
 /*---------------------------.
 | Display the help message.  |
 `---------------------------*/
@@ -89,10 +130,18 @@ Parser:\n\
   fputs (_("\
 Output:\n\
   -d, --defines              also produce a header file\n\
-  -v, --verbose              also produce an explanation of the automaton\n\
+  -r, --report=THINGS        also produce details on the automaton\n\
+  -v, --verbose              same as `--report=state'\n\
   -b, --file-prefix=PREFIX   specify a PREFIX for output files\n\
   -o, --output=FILE          leave output to FILE\n\
   -g, --graph                also produce a VCG description of the automaton\n\
+\n\
+THINGS is a list of comma separated words that can include:\n\
+  `state'        describe the states\n\
+  `itemset'      complete the core item sets with their closure\n\
+  `lookahead'    explicitly associate lookaheads to items\n\
+  `all'          include all the above information\n\
+  `none'         disable the report\n\
 "), stream);
   putc ('\n', stream);
 
@@ -170,7 +219,7 @@ getargs (int argc, char *argv[])
 	break;
 
       case 'v':
-	verbose_flag = 1;
+	report_flag |= report_states;
 	break;
 
       case 'S':
@@ -196,10 +245,6 @@ getargs (int argc, char *argv[])
 	token_table_flag = 1;
 	break;
 
-      case 'r':
-	fatal (_("`%s' is no longer supported"), "--raw");
-	break;
-
       case 'n':
 	no_parser_flag = 1;
 	break;
@@ -220,6 +265,10 @@ getargs (int argc, char *argv[])
 	spec_name_prefix = optarg;
 	break;
 
+      case 'r':
+	report_argmatch (optarg);
+	break;
+
       default:
 	fprintf (stderr, _("Try `%s --help' for more information.\n"),
 		 program_name);
