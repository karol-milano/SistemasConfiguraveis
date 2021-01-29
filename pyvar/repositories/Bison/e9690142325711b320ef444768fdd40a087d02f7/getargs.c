@@ -52,7 +52,7 @@ bool graph_flag;
 bool xml_flag;
 bool no_lines_flag;
 bool token_table_flag;
-bool yacc_flag;	/* for -y */
+bool yacc_flag; /* for -y */
 
 bool nondeterministic_parser = false;
 bool glr_parser = false;
@@ -94,32 +94,32 @@ char *program_name;
  */
 static void
 flags_argmatch (const char *option,
-		const char * const keys[], const int values[],
-		int all, int *flags, char *args)
+                const char * const keys[], const int values[],
+                int all, int *flags, char *args)
 {
   if (args)
     {
       args = strtok (args, ",");
       while (args)
-	{
-	  int no = strncmp (args, "no-", 3) == 0 ? 3 : 0;
-	  int value = XARGMATCH (option, args + no, keys, values);
-	  if (value == 0)
-	    {
-	      if (no)
-		*flags |= all;
-	      else
-		*flags &= ~all;
-	    }
-	  else
-	    {
-	      if (no)
-		*flags &= ~value;
-	      else
-		*flags |= value;
-	    }
-	  args = strtok (NULL, ",");
-	}
+        {
+          int no = strncmp (args, "no-", 3) == 0 ? 3 : 0;
+          int value = XARGMATCH (option, args + no, keys, values);
+          if (value == 0)
+            {
+              if (no)
+                *flags |= all;
+              else
+                *flags &= ~all;
+            }
+          else
+            {
+              if (no)
+                *flags &= ~value;
+              else
+                *flags |= value;
+            }
+          args = strtok (NULL, ",");
+        }
     }
   else
     *flags |= all;
@@ -135,9 +135,9 @@ flags_argmatch (const char *option,
  *  \arg FlagName_all    the all value.
  *  \arg FlagName_flag   the flag to update.
  */
-#define FLAGS_ARGMATCH(FlagName, Args)					\
+#define FLAGS_ARGMATCH(FlagName, Args)                                  \
   flags_argmatch ("--" #FlagName, FlagName ## _args, FlagName ## _types, \
-		  FlagName ## _all, &FlagName ## _flag, Args)
+                  FlagName ## _all, &FlagName ## _flag, Args)
 
 
 /*----------------------.
@@ -265,13 +265,13 @@ usage (int status)
 {
   if (status != 0)
     fprintf (stderr, _("Try `%s --help' for more information.\n"),
-	     program_name);
+             program_name);
   else
     {
       /* For ../build-aux/cross-options.pl to work, use the format:
-		^  -S, --long[=ARGS] (whitespace)
-	 A --long option is required.
-	 Otherwise, add exceptions to ../build-aux/cross-options.pl.  */
+                ^  -S, --long[=ARGS] (whitespace)
+         A --long option is required.
+         Otherwise, add exceptions to ../build-aux/cross-options.pl.  */
 
       printf (_("Usage: %s [OPTION]... FILE\n"), program_name);
       fputs (_("\
@@ -379,14 +379,14 @@ version (void)
   putc ('\n', stdout);
 
   fprintf (stdout,
-	   _("Copyright (C) %d Free Software Foundation, Inc.\n"),
-	   PACKAGE_COPYRIGHT_YEAR);
+           _("Copyright (C) %d Free Software Foundation, Inc.\n"),
+           PACKAGE_COPYRIGHT_YEAR);
 
   fputs (_("\
 This is free software; see the source for copying conditions.  There is NO\n\
 warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
 "),
-	 stdout);
+         stdout);
 }
 
 
@@ -415,12 +415,12 @@ language_argmatch (char const *arg, int prio, location loc)
     {
       int i;
       for (i = 0; valid_languages[i].language[0]; i++)
-	if (c_strcasecmp (arg, valid_languages[i].language) == 0)
-	  {
-	    language_prio = prio;
-	    language = &valid_languages[i];
-	    return;
-	  }
+        if (c_strcasecmp (arg, valid_languages[i].language) == 0)
+          {
+            language_prio = prio;
+            language = &valid_languages[i];
+            return;
+          }
       msg = _("invalid language `%s'");
     }
   else if (language_prio == prio)
@@ -474,25 +474,25 @@ enum
 static struct option const long_options[] =
 {
   /* Operation modes. */
-  { "help",            no_argument,	  0,   'h' },
-  { "version",         no_argument,	  0,   'V' },
-  { "print-localedir", no_argument,	  0,   PRINT_LOCALEDIR_OPTION },
-  { "print-datadir",   no_argument,	  0,   PRINT_DATADIR_OPTION   },
+  { "help",            no_argument,       0,   'h' },
+  { "version",         no_argument,       0,   'V' },
+  { "print-localedir", no_argument,       0,   PRINT_LOCALEDIR_OPTION },
+  { "print-datadir",   no_argument,       0,   PRINT_DATADIR_OPTION   },
   { "warnings",        optional_argument, 0,   'W' },
 
   /* Parser. */
-  { "name-prefix",   required_argument,	  0,   'p' },
+  { "name-prefix",   required_argument,   0,   'p' },
   { "include",       required_argument,   0,   'I' },
 
   /* Output. */
-  { "file-prefix", required_argument,	0,   'b' },
-  { "output",	   required_argument,	0,   'o' },
-  { "output-file", required_argument,	0,   'o' },
-  { "graph",	   optional_argument,	0,   'g' },
+  { "file-prefix", required_argument,   0,   'b' },
+  { "output",      required_argument,   0,   'o' },
+  { "output-file", required_argument,   0,   'o' },
+  { "graph",       optional_argument,   0,   'g' },
   { "xml",         optional_argument,   0,   'x' },
-  { "report",	   required_argument,   0,   'r' },
+  { "report",      required_argument,   0,   'r' },
   { "report-file", required_argument,   0,   REPORT_FILE_OPTION },
-  { "verbose",	   no_argument,	        0,   'v' },
+  { "verbose",     no_argument,         0,   'v' },
 
   /* Hidden. */
   { "trace",         optional_argument,   0,     'T' },
@@ -502,13 +502,13 @@ static struct option const long_options[] =
 
   /* Operation modes.  */
   { "fixed-output-files", no_argument,  0,   'y' },
-  { "yacc",	          no_argument,  0,   'y' },
+  { "yacc",               no_argument,  0,   'y' },
 
   /* Parser.  */
-  { "debug",	      no_argument,               0,   't' },
-  { "define",	      required_argument,         0,   'D' },
+  { "debug",          no_argument,               0,   't' },
+  { "define",         required_argument,         0,   'D' },
   { "force-define",   required_argument,         0,   'F' },
-  { "locations",      no_argument,		 0, LOCATIONS_OPTION },
+  { "locations",      no_argument,               0, LOCATIONS_OPTION },
   { "no-lines",       no_argument,               0,   'l' },
   { "raw",            no_argument,               0,     0 },
   { "skeleton",       required_argument,         0,   'S' },
@@ -545,15 +545,15 @@ getargs (int argc, char *argv[])
   int c;
 
   while ((c = getopt_long (argc, argv, short_options, long_options, NULL))
-	 != -1)
+         != -1)
     switch (c)
       {
         /* ASCII Sorting for short options (i.e., upper case then
            lower case), and then long-only options.  */
 
       case 0:
-	/* Certain long options cause getopt_long to return 0.  */
-	break;
+        /* Certain long options cause getopt_long to return 0.  */
+        break;
 
       case 'D': /* -DNAME[=VALUE]. */
       case 'F': /* -FNAME[=VALUE]. */
@@ -567,37 +567,37 @@ getargs (int argc, char *argv[])
                                         c == 'D' ? MUSCLE_PERCENT_DEFINE_D
                                                  : MUSCLE_PERCENT_DEFINE_F);
         }
-	break;
+        break;
 
       case 'I':
-	include = AS_FILE_NAME (optarg);
-	break;
+        include = AS_FILE_NAME (optarg);
+        break;
 
       case 'L':
-	language_argmatch (optarg, command_line_prio,
-			   command_line_location ());
-	break;
+        language_argmatch (optarg, command_line_prio,
+                           command_line_location ());
+        break;
 
       case 'S':
-	skeleton_arg (AS_FILE_NAME (optarg), command_line_prio,
-		      command_line_location ());
-	break;
+        skeleton_arg (AS_FILE_NAME (optarg), command_line_prio,
+                      command_line_location ());
+        break;
 
       case 'T':
-	FLAGS_ARGMATCH (trace, optarg);
-	break;
+        FLAGS_ARGMATCH (trace, optarg);
+        break;
 
       case 'V':
-	version ();
-	exit (EXIT_SUCCESS);
+        version ();
+        exit (EXIT_SUCCESS);
 
       case 'W':
-	FLAGS_ARGMATCH (warnings, optarg);
-	break;
+        FLAGS_ARGMATCH (warnings, optarg);
+        break;
 
       case 'b':
-	spec_file_prefix = AS_FILE_NAME (optarg);
-	break;
+        spec_file_prefix = AS_FILE_NAME (optarg);
+        break;
 
       case 'd':
         /* Here, the -d and --defines options are differentiated.  */
@@ -607,81 +607,81 @@ getargs (int argc, char *argv[])
         break;
 
       case 'g':
-	graph_flag = true;
-	if (optarg)
-	  spec_graph_file = xstrdup (AS_FILE_NAME (optarg));
-	break;
+        graph_flag = true;
+        if (optarg)
+          spec_graph_file = xstrdup (AS_FILE_NAME (optarg));
+        break;
 
       case 'h':
-	usage (EXIT_SUCCESS);
+        usage (EXIT_SUCCESS);
 
       case 'k':
-	token_table_flag = true;
-	break;
+        token_table_flag = true;
+        break;
 
       case 'l':
-	no_lines_flag = true;
-	break;
+        no_lines_flag = true;
+        break;
 
       case 'o':
-	spec_outfile = AS_FILE_NAME (optarg);
-	break;
+        spec_outfile = AS_FILE_NAME (optarg);
+        break;
 
       case 'p':
-	spec_name_prefix = optarg;
-	break;
+        spec_name_prefix = optarg;
+        break;
 
       case 'r':
-	FLAGS_ARGMATCH (report, optarg);
-	break;
+        FLAGS_ARGMATCH (report, optarg);
+        break;
 
       case 't':
         muscle_percent_define_insert ("parse.trace",
                                       command_line_location (), "",
                                       MUSCLE_PERCENT_DEFINE_D);
-	break;
+        break;
 
       case 'v':
-	report_flag |= report_states;
-	break;
+        report_flag |= report_states;
+        break;
 
       case 'x':
-	xml_flag = true;
-	if (optarg)
-	  spec_xml_file = xstrdup (AS_FILE_NAME (optarg));
-	break;
+        xml_flag = true;
+        if (optarg)
+          spec_xml_file = xstrdup (AS_FILE_NAME (optarg));
+        break;
 
       case 'y':
-	yacc_flag = true;
-	break;
+        yacc_flag = true;
+        break;
 
       case LOCATIONS_OPTION:
         muscle_percent_define_ensure ("locations",
                                       command_line_location (), true);
-	break;
+        break;
 
       case PRINT_LOCALEDIR_OPTION:
-	printf ("%s\n", LOCALEDIR);
-	exit (EXIT_SUCCESS);
+        printf ("%s\n", LOCALEDIR);
+        exit (EXIT_SUCCESS);
 
       case PRINT_DATADIR_OPTION:
-	printf ("%s\n", compute_pkgdatadir ());
-	exit (EXIT_SUCCESS);
+        printf ("%s\n", compute_pkgdatadir ());
+        exit (EXIT_SUCCESS);
 
       case REPORT_FILE_OPTION:
-	spec_verbose_file = xstrdup (AS_FILE_NAME (optarg));
-	break;
+        spec_verbose_file = xstrdup (AS_FILE_NAME (optarg));
+        break;
 
       default:
-	usage (EXIT_FAILURE);
+        usage (EXIT_FAILURE);
       }
 
   if (argc - optind != 1)
     {
       if (argc - optind < 1)
-	error (0, 0, _("missing operand after `%s'"), argv[argc - 1]);
+        error (0, 0, _("missing operand after `%s'"), argv[argc - 1]);
       else
-	error (0, 0, _("extra operand `%s'"), argv[optind + 1]);
+        error (0, 0, _("extra operand `%s'"), argv[optind + 1]);
       usage (EXIT_FAILURE);
     }
 
