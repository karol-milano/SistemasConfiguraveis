@@ -62,6 +62,7 @@ bool pure_parser = false;
 
 int report_flag = report_none;
 int trace_flag = trace_none;
+int warnings_flag = warnings_none;
 
 const char *skeleton = NULL;
 const char *include = NULL;
@@ -69,6 +70,53 @@ const char *include = NULL;
 extern char *program_name;
 
 
+/** Decode an option's set of keys.
+ *
+ *  \param option   option being decoded.
+ *  \paran keys     array of valid subarguments.
+ *  \param values   array of corresponding (int) values.
+ *  \param flag     the flags to update
+ *  \param args     colon separated list of effective subarguments to decode.
+ *                  If 0, then activate all the flags.
+ *
+ *  The special value 0 resets the flags to 0.
+ */
+static int
+flags_argmatch (const char *option, 
+		const char * const keys[], const int values[],
+		int *flags, char *args)
+{
+  if (args)
+    {
+      args = strtok (args, ",");
+      do
+	{
+	  int value = XARGMATCH (option, args, keys, values);
+	  if (value == 0)
+	    *flags = 0;
+	  else
+	    *flags |= value;
+	}
+      while ((args = strtok (NULL, ",")));
+    }
+  else
+    *flags = ~0;
+}
+
+/** Decode a set of sub arguments. 
+ *
+ *  \param FlagName  the flag familly to update.
+ *  \param args      the effective sub arguments to decode.
+ *
+ *  \arg FlagName_args   the list of keys.
+ *  \arg FlagName_types  the list of values.
+ *  \arg FlagName_flag   the flag to update.
+ */
+#define FLAGS_ARGMATCH(FlagName, Args)					\
+  flags_argmatch ("--" #FlagName, FlagName ## _args, FlagName ## _types, \
+		  &FlagName ## _flag, Args)
+
+
 /*----------------------.
 | --report's handling.  |
 `----------------------*/
@@ -100,22 +148,6 @@ static const int report_types[] =
 
 ARGMATCH_VERIFY (report_args, report_types);
 
-static void
-report_argmatch (char *args)
-{
-  args = strtok (args, ",");
-  do
-    {
-      int report = XARGMATCH ("--report", args,
-			      report_args, report_types);
-      if (report == report_none)
-	report_flag = report_none;
-      else
-	report_flag |= report;
-    }
-  while ((args = strtok (NULL, ",")));
-}
-
 
 /*---------------------.
 | --trace's handling.  |
@@ -160,26 +192,31 @@ static const int trace_types[] =
 
 ARGMATCH_VERIFY (trace_args, trace_types);
 
-static void
-trace_argmatch (char *args)
+
+/*------------------------.
+| --warnings's handling.  |
+`------------------------*/
+
+static const char * const warnings_args[] =
 {
-  if (args)
-    {
-      args = strtok (args, ",");
-      do
-	{
-	  int trace = XARGMATCH ("--trace", args,
-				 trace_args, trace_types);
-	  if (trace == trace_none)
-	    trace_flag = trace_none;
-	  else
-	    trace_flag |= trace;
-	}
-      while ((args = strtok (NULL, ",")));
-    }
-  else
-    trace_flag = trace_all;
-}
+  /* In a series of synonyms, present the most meaningful first, so
+     that argmatch_valid be more readable.  */
+  "none       - no warnings",
+  "error      - warnings are errors",
+  "yacc       - incompatibilities with POSIX YACC",
+  "all        - all of the above",
+  0
+};
+
+static const int warnings_types[] =
+{
+  warnings_none,
+  warnings_error,
+  warnings_yacc,
+  warnings_all
+};
+
+ARGMATCH_VERIFY (warnings_args, warnings_types);
 
 
 /*-------------------------------------------.
@@ -255,7 +292,7 @@ THINGS is a list of comma separated words that can include:\n\
       putc ('\n', stdout);
 
       fputs (_("\
-Report bugs to <bug-bison@gnu.org>.\n"), stdout);
+Report bugs to <" PACKAGE_BUGREPORT ">.\n"), stdout);
     }
 
   exit (status);
@@ -293,7 +330,7 @@ warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
 `----------------------*/
 
 /* Shorts options.  */
-static char const short_options[] = "yvegdhr:ltknVo:b:p:S:T::";
+static char const short_options[] = "yvegdhr:ltknVo:b:p:S:T::W";
 
 /* Values for long options that do not have single-letter equivalents.  */
 enum
@@ -305,9 +342,10 @@ enum
 static struct option const long_options[] =
 {
   /* Operation modes. */
-  { "help",            no_argument,	0,   'h' },
-  { "version",         no_argument,	0,   'V' },
-  { "print-localedir", no_argument,	0,   PRINT_LOCALEDIR_OPTION },
+  { "help",            no_argument,	  0,   'h' },
+  { "version",         no_argument,	  0,   'V' },
+  { "print-localedir", no_argument,	  0,   PRINT_LOCALEDIR_OPTION },
+  { "warnings",        optional_argument, 0,   'W' },
 
   /* Parser. */
   { "name-prefix",   required_argument,	  0,   'p' },
@@ -364,21 +402,10 @@ getargs (int argc, char *argv[])
 	/* Certain long options cause getopt_long to return 0.  */
 	break;
 
-      case 'y':
-	yacc_flag = true;
+      case 'b':
+	spec_file_prefix = AS_FILE_NAME (optarg);
 	break;
 
-      case 'h':
-	usage (EXIT_SUCCESS);
-
-      case 'V':
-	version ();
-	exit (EXIT_SUCCESS);
-
-      case PRINT_LOCALEDIR_OPTION:
-	printf ("%s\n", LOCALEDIR);
-	exit (EXIT_SUCCESS);
-
       case 'g':
 	/* Here, the -g and --graph=FILE options are differentiated.  */
 	graph_flag = true;
@@ -386,9 +413,8 @@ getargs (int argc, char *argv[])
 	  spec_graph_file = AS_FILE_NAME (optarg);
 	break;
 
-      case 'v':
-	report_flag |= report_states;
-	break;
+      case 'h':
+	usage (EXIT_SUCCESS);
 
       case 'S':
 	skeleton = AS_FILE_NAME (optarg);
@@ -405,46 +431,62 @@ getargs (int argc, char *argv[])
 	  spec_defines_file = AS_FILE_NAME (optarg);
 	break;
 
+      case 'k':
+	token_table_flag = true;
+	break;
+
       case 'l':
 	no_lines_flag = true;
 	break;
 
-      case LOCATIONS_OPTION:
-	locations_flag = true;
+      case 'n':
+	no_parser_flag = true;
 	break;
 
-      case 'k':
-	token_table_flag = true;
+      case 'o':
+	spec_outfile = AS_FILE_NAME (optarg);
 	break;
 
-      case 'n':
-	no_parser_flag = true;
+      case 'p':
+	spec_name_prefix = optarg;
+	break;
+
+      case 'r':
+	FLAGS_ARGMATCH (report, optarg);
+	break;
+
+      case 'T':
+	FLAGS_ARGMATCH (trace, optarg);
 	break;
 
       case 't':
 	debug_flag = true;
 	break;
 
-      case 'o':
-	spec_outfile = AS_FILE_NAME (optarg);
-	break;
+      case 'V':
+	version ();
+	exit (EXIT_SUCCESS);
 
-      case 'b':
-	spec_file_prefix = AS_FILE_NAME (optarg);
+      case 'v':
+	report_flag |= report_states;
 	break;
 
-      case 'p':
-	spec_name_prefix = optarg;
+      case 'y':
+	yacc_flag = true;
 	break;
 
-      case 'r':
-	report_argmatch (optarg);
+      case 'W':
+	FLAGS_ARGMATCH (warnings, optarg);
 	break;
 
-      case 'T':
-	trace_argmatch (optarg);
+      case LOCATIONS_OPTION:
+	locations_flag = true;
 	break;
 
+      case PRINT_LOCALEDIR_OPTION:
+	printf ("%s\n", LOCALEDIR);
+	exit (EXIT_SUCCESS);
+
       default:
 	usage (EXIT_FAILURE);
       }
