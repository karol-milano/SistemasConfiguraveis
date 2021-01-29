@@ -277,7 +277,8 @@ Parser:\n\
                              (this is an experimental feature)\n\
   -S, --skeleton=FILE        specify the skeleton to use\n\
   -t, --debug                instrument the parser for debugging\n\
-      --locations            enable locations computation\n\
+      --locations            enable location support\n\
+  -D, --define=NAME[=VALUE]  same as `%define NAME \"VALUE\"'\n\
   -p, --name-prefix=PREFIX   prepend PREFIX to the external symbols\n\
   -l, --no-lines             don't generate `#line' directives\n\
   -k, --token-table          include a table of token names\n\
@@ -413,6 +414,7 @@ language_argmatch (char const *arg, int prio, location const *loc)
 /* Shorts options.
    Should be computed from long_options.  */
 static char const short_options[] =
+  "D:"
   "L:"
   "S:"
   "T::"
@@ -479,6 +481,7 @@ static struct option const long_options[] =
 
   /* Parser.  */
   { "debug",	      no_argument,               0,   't' },
+  { "define",	      required_argument,         0,   'D' },
   { "locations",      no_argument,		 0, LOCATIONS_OPTION },
   { "no-lines",       no_argument,               0,   'l' },
   { "raw",            no_argument,               0,     0 },
@@ -497,6 +500,19 @@ static struct option const long_options[] =
 # define AS_FILE_NAME(File) (File)
 #endif
 
+/* Build a location for the current command line argument. */
+static
+location
+command_line_location()
+{
+  location res;
+  /* "<command line>" is used in GCC's messages about -D. */
+  boundary_set (&res.start, uniqstr_new ("<command line>"), optind, -1);
+  res.end = res.start;
+  return res;
+}
+
+
 void
 getargs (int argc, char *argv[])
 {
@@ -506,15 +522,23 @@ getargs (int argc, char *argv[])
 	 != -1)
     switch (c)
       {
+        /* ASCII Sorting for short options (i.e., upper case then
+           lower case), and then long-only options.  */
+
       case 0:
 	/* Certain long options cause getopt_long to return 0.  */
 	break;
 
-      case 'd':
-	/* Here, the -d and --defines options are differentiated.  */
-	defines_flag = true;
-	if (optarg)
-	  spec_defines_file = xstrdup (AS_FILE_NAME (optarg));
+      case 'D': /* -DNAME[=VALUE]. */
+        {
+          char* name = optarg;
+          char* value = strchr (optarg, '=');
+          if (value)
+            *value++ = 0;
+          else
+            value = "";
+          muscle_percent_define_insert (name, command_line_location (), value);
+        }
 	break;
 
       case 'I':
@@ -548,6 +572,13 @@ getargs (int argc, char *argv[])
 	spec_file_prefix = AS_FILE_NAME (optarg);
 	break;
 
+      case 'd':
+        /* Here, the -d and --defines options are differentiated.  */
+        defines_flag = true;
+        if (optarg)
+          spec_defines_file = xstrdup (AS_FILE_NAME (optarg));
+        break;
+
       case 'g':
 	graph_flag = true;
 	if (optarg)
