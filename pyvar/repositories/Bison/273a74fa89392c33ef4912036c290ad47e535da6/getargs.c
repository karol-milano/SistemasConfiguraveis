@@ -31,17 +31,73 @@ int defines_flag = 0;
 int locations_flag = 0;
 int no_lines_flag = 0;
 int no_parser_flag = 0;
-int report_flag = 0;
+int report_flag = report_none;
 int token_table_flag = 0;
 int yacc_flag = 0;	/* for -y */
 int graph_flag = 0;
-int trace_flag = 0;
+int trace_flag = trace_none;
 
 const char *skeleton = NULL;
 const char *include = NULL;
 
 extern char *program_name;
 
+
+/*---------------------.
+| --trace's handling.  |
+`---------------------*/
+
+static const char * const trace_args[] =
+{
+  /* In a series of synonyms, present the most meaningful first, so
+     that argmatch_valid be more readable.  */
+  "none       - no report",
+  "automaton  - contruction of the automaton",
+  "bitsets    - use of bitsets",
+  "grammar    - reading, reducing of the grammar",
+  "resource   - time and memory (where available)",
+  "sets       - grammar sets: firsts, nullable etc.",
+  "tools      - m4 invocation and preserve the temporary file",
+  "all        - all of the above",
+  0
+};
+
+static const int trace_types[] =
+{
+  trace_none,
+  trace_automaton,
+  trace_bitsets,
+  trace_grammar,
+  trace_resource,
+  trace_sets,
+  trace_tools,
+  trace_all
+};
+
+
+static void
+trace_argmatch (char *args)
+{
+  ARGMATCH_ASSERT (trace_args, trace_types);
+  if (args)
+    {
+      args = strtok (args, ",");
+      do
+	{
+	  int trace = XARGMATCH ("--trace", args,
+				 trace_args, trace_types);
+	  if (trace == trace_none)
+	    trace_flag = trace_none;
+	  else
+	    trace_flag |= trace;
+	}
+      while ((args = strtok (NULL, ",")));
+    }
+  else
+    trace_flag = trace_all;
+}
+
+
 /*----------------------.
 | --report's handling.  |
 `----------------------*/
@@ -186,7 +242,7 @@ warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
 `----------------------*/
 
 /* Shorts options.  */
-const char *short_options = "yvegdhr:ltknVo:b:p:S:";
+const char *short_options = "yvegdhr:ltknVo:b:p:S:T::";
 
 static struct option const long_options[] =
 {
@@ -207,7 +263,7 @@ static struct option const long_options[] =
   { "verbose",	   no_argument,	        0,   'v' },
 
   /* Hidden. */
-  { "trace",         no_argument,   &trace_flag,     1 },
+  { "trace",         optional_argument,   0,     'T' },
 
   /* FIXME: semantic parsers will output an `include' of an
      output file: be sure that the naem included is indeed the name of
@@ -329,6 +385,10 @@ getargs (int argc, char *argv[])
 	report_argmatch (optarg);
 	break;
 
+      case 'T':
+	trace_argmatch (optarg);
+	break;
+
       default:
 	fprintf (stderr, _("Try `%s --help' for more information.\n"),
 		 program_name);
