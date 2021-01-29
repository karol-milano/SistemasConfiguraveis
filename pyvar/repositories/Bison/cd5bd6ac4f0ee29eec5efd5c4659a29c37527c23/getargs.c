@@ -1,5 +1,5 @@
 /* Parse command line arguments for bison.
-   Copyright 1984, 1986, 1989, 1992, 2000 Free Software Foundation, Inc.
+   Copyright 1984, 1986, 1989, 1992, 2000, 2001 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -30,13 +30,14 @@ int locations_flag = 0;
 int no_lines_flag = 0;
 int no_parser_flag = 0;
 int raw_flag = 0;
+char *skeleton = 0;
 int token_table_flag = 0;
 int verbose_flag = 0;
 int statistics_flag = 0;
 int yacc_flag = 0;	/* for -y */
 
 extern char *program_name;
-const char *shortopts = "yvdhrltknVo:b:p:";
+const char *shortopts = "yvdhrltknVo:b:p:S:";
 static struct option longopts[] =
 {
   /* Operation modes. */
@@ -46,6 +47,8 @@ static struct option longopts[] =
   {"fixed-output-files",no_argument,	0, 'y'},
 
   /* Parser. */
+  {"skeleton",		required_argument,	0, 'S'},
+  {"debug",		no_argument,		0, 'd'},
   {"locations",		no_argument, 	&locations_flag, 1},
   /* was 'a';  apparently unused -wjh */
   {"name-prefix",	required_argument, 	0, 'p'},
@@ -53,7 +56,6 @@ static struct option longopts[] =
   {"no-parser",		no_argument,		0, 'n'},
   {"raw",		no_argument,		0, 'r'},
   {"token-table",	no_argument,		0, 'k'},
-  {"debug",		no_argument,		0, 'd'},
 
   /* Output. */
   {"defines",		no_argument,		0, 'd'},
@@ -98,6 +100,7 @@ Operation modes:\n\
 
   fputs (_("\
 Parser:\n\
+  -S, --skeleton=FILE        specify the skeleton to use\n\
   -t, --debug                instrument the parser for debugging\n\
       --locations            enable locations computation\n\
   -p, --name-prefix=PREFIX   prepend PREFIX to the external symbols\n\
@@ -136,7 +139,7 @@ bison (GNU Bison) %s"), VERSION);
   putc ('\n', stream);
 
   fputs (_("\
-Copyright 1984, 1986, 1989, 1992, 2000 Free Software Foundation, Inc.\n"),
+Copyright 1984, 1986, 1989, 1992, 2000, 2001 Free Software Foundation, Inc.\n"),
 	 stream);
 
   fputs (_("\
@@ -156,73 +159,74 @@ getargs (int argc, char *argv[])
 {
   int c;
 
-  while ((c = getopt_long (argc, argv, "yvdhrltknVo:b:p:", longopts, (int *)0))
-	 != EOF)
-    {
-      switch (c)
-	{
-	case 0:
-	  /* Certain long options cause getopt_long to return 0.  */
-	  break;
-
-	case 'y':
-	  yacc_flag = 1;
-	  break;
-
-	case 'h':
-	  usage (stdout);
-	  exit (0);
-
-	case 'V':
-	  version (stdout);
-	  exit (0);
-
-	case 'v':
-	  verbose_flag = 1;
-	  break;
-
-	case 'd':
-	  defines_flag = 1;
-	  break;
-
-	case 'l':
-	  no_lines_flag = 1;
-	  break;
-
-	case 'k':
-	  token_table_flag = 1;
-	  break;
-
-	case 'r':
-	  raw_flag = 1;
-	  break;
-
-	case 'n':
-	  no_parser_flag = 1;
-	  break;
-
-	case 't':
-	  debug_flag = 1;
-	  break;
-
-	case 'o':
-	  spec_outfile = optarg;
-	  break;
-
-	case 'b':
-	  spec_file_prefix = optarg;
-	  break;
-
-	case 'p':
-	  spec_name_prefix = optarg;
-	  break;
-
-	default:
-	  fprintf (stderr, _("Try `%s --help' for more information.\n"),
-		   program_name);
-	  exit (1);
-	}
-    }
+  while ((c = getopt_long (argc, argv, shortopts, longopts, NULL)) != EOF)
+    switch (c)
+      {
+      case 0:
+	/* Certain long options cause getopt_long to return 0.  */
+	break;
+
+      case 'y':
+	yacc_flag = 1;
+	break;
+
+      case 'h':
+	usage (stdout);
+	exit (0);
+
+      case 'V':
+	version (stdout);
+	exit (0);
+
+      case 'v':
+	verbose_flag = 1;
+	break;
+
+      case 'S':
+	skeleton = optarg;
+	break;
+
+      case 'd':
+	defines_flag = 1;
+	break;
+
+      case 'l':
+	no_lines_flag = 1;
+	break;
+
+      case 'k':
+	token_table_flag = 1;
+	break;
+
+      case 'r':
+	raw_flag = 1;
+	break;
+
+      case 'n':
+	no_parser_flag = 1;
+	break;
+
+      case 't':
+	debug_flag = 1;
+	break;
+
+      case 'o':
+	spec_outfile = optarg;
+	break;
+
+      case 'b':
+	spec_file_prefix = optarg;
+	break;
+
+      case 'p':
+	spec_name_prefix = optarg;
+	break;
+
+      default:
+	fprintf (stderr, _("Try `%s --help' for more information.\n"),
+		 program_name);
+	exit (1);
+      }
 
   if (optind == argc)
     {
