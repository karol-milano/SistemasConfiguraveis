@@ -31,6 +31,10 @@
 #include <progname.h>
 #include <quote.h>
 
+#if HAVE_LIBTEXTSTYLE
+# include <textstyle.h>
+#endif
+
 #include "complain.h"
 #include "files.h"
 #include "muscle-tab.h"
@@ -501,10 +505,12 @@ static char const short_options[] =
 /* Values for long options that do not have single-letter equivalents.  */
 enum
 {
-  LOCATIONS_OPTION = CHAR_MAX + 1,
-  PRINT_LOCALEDIR_OPTION,
+  COLOR_OPTION = CHAR_MAX + 1,
+  LOCATIONS_OPTION,
   PRINT_DATADIR_OPTION,
-  REPORT_FILE_OPTION
+  PRINT_LOCALEDIR_OPTION,
+  REPORT_FILE_OPTION,
+  STYLE_OPTION
 };
 
 static struct option const long_options[] =
@@ -531,7 +537,9 @@ static struct option const long_options[] =
   { "verbose",     no_argument,         0,   'v' },
 
   /* Hidden. */
-  { "trace",         optional_argument,   0,     'T' },
+  { "trace",       optional_argument,   0,  'T' },
+  { "color",       optional_argument,   0,  COLOR_OPTION },
+  { "style",       optional_argument,   0,  STYLE_OPTION },
 
   /* Output.  */
   { "defines",     optional_argument,   0,   'd' },
@@ -575,11 +583,33 @@ command_line_location (void)
 }
 
 
+/* Handle the command line options for color support.  Do it early, so
+   that error messages from getargs be also colored as per the user's
+   request.  This is consistent with the way GCC and Clang behave.  */
+
+static void
+getargs_colors (int argc _GL_UNUSED, char *argv[] _GL_UNUSED)
+{
+#if HAVE_LIBTEXTSTYLE
+  for (int i = 1; i < argc; i++)
+    {
+      const char *arg = argv[i];
+      if (STRPREFIX_LIT ("--color=", arg))
+        handle_color_option (arg + strlen ("--color="));
+      else if (STRPREFIX_LIT ("--style=", arg))
+        handle_style_option (arg + strlen ("--style="));
+    }
+  complain_init_color ();
+#endif
+}
+
+
 void
 getargs (int argc, char *argv[])
 {
-  int c;
+  getargs_colors (argc, argv);
 
+  int c;
   while ((c = getopt_long (argc, argv, short_options, long_options, NULL))
          != -1)
     switch (c)
@@ -723,6 +753,10 @@ getargs (int argc, char *argv[])
         yacc_loc = command_line_location ();
         break;
 
+      case COLOR_OPTION:
+        /* Handled in getargs_colors. */
+        break;
+
       case LOCATIONS_OPTION:
         muscle_percent_define_ensure ("locations",
                                       command_line_location (), true);
@@ -741,6 +775,10 @@ getargs (int argc, char *argv[])
         spec_verbose_file = xstrdup (AS_FILE_NAME (optarg));
         break;
 
+      case STYLE_OPTION:
+        /* Handled in getargs_colors. */
+        break;
+
       default:
         usage (EXIT_FAILURE);
       }
