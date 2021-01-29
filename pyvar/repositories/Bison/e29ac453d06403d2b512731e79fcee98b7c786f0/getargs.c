@@ -561,6 +561,7 @@ static char const short_options[] =
 enum
 {
   COLOR_OPTION = CHAR_MAX + 1,
+  FIXED_OUTPUT_FILES_OPTION,
   LOCATIONS_OPTION,
   PRINT_DATADIR_OPTION,
   PRINT_LOCALEDIR_OPTION,
@@ -607,9 +608,9 @@ static struct option const long_options[] =
   { "xml",         optional_argument,   0,   'x' },
 
   /* Hidden. */
-  { "fixed-output-files", no_argument,  0,  'y' },
-  { "output-file", required_argument,   0,  'o' },
-  { "trace",       optional_argument,   0,  'T' },
+  { "fixed-output-files", no_argument,       0,  FIXED_OUTPUT_FILES_OPTION },
+  { "output-file",        required_argument, 0,  'o' },
+  { "trace",              optional_argument, 0,  'T' },
 
   {0, 0, 0, 0}
 };
@@ -665,6 +666,8 @@ getargs (int argc, char *argv[])
   int c;
   while ((c = getopt_long (argc, argv, short_options, long_options, NULL))
          != -1)
+  {
+    location loc = command_line_location ();
     switch (c)
       {
         /* ASCII Sorting for short options (i.e., upper case then
@@ -697,7 +700,7 @@ getargs (int argc, char *argv[])
                   *end = 0;
                 }
             }
-          muscle_percent_define_insert (name, command_line_location (),
+          muscle_percent_define_insert (name, loc,
                                         kind, value ? value : "",
                                         c == 'D' ? MUSCLE_PERCENT_DEFINE_D
                                                  : MUSCLE_PERCENT_DEFINE_F);
@@ -705,13 +708,11 @@ getargs (int argc, char *argv[])
         break;
 
       case 'L':
-        language_argmatch (optarg, command_line_prio,
-                           command_line_location ());
+        language_argmatch (optarg, command_line_prio, loc);
         break;
 
       case 'S':
-        skeleton_arg (optarg, command_line_prio,
-                      command_line_location ());
+        skeleton_arg (optarg, command_line_prio, loc);
         break;
 
       case 'T':
@@ -778,7 +779,7 @@ getargs (int argc, char *argv[])
 
       case 't':
         muscle_percent_define_insert ("parse.trace",
-                                      command_line_location (),
+                                      loc,
                                       muscle_keyword, "",
                                       MUSCLE_PERCENT_DEFINE_D);
         break;
@@ -803,16 +804,22 @@ getargs (int argc, char *argv[])
 
       case 'y':
         warning_argmatch ("yacc", 0, 0);
-        yacc_loc = command_line_location ();
+        yacc_loc = loc;
         break;
 
       case COLOR_OPTION:
         /* Handled in getargs_colors. */
         break;
 
+      case FIXED_OUTPUT_FILES_OPTION:
+        complain (&loc, Wdeprecated,
+                  _("deprecated option: %s, use %s"),
+                  quote ("--fixed-output-files"), quote_n (1, "-o y.tab.c"));
+        spec_outfile = "y.tab.c";
+        break;
+
       case LOCATIONS_OPTION:
-        muscle_percent_define_ensure ("locations",
-                                      command_line_location (), true);
+        muscle_percent_define_ensure ("locations", loc, true);
         break;
 
       case PRINT_LOCALEDIR_OPTION:
@@ -835,6 +842,7 @@ getargs (int argc, char *argv[])
       default:
         usage (EXIT_FAILURE);
       }
+  }
 
   if (argc - optind != 1)
     {
