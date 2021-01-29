@@ -30,10 +30,7 @@
 #include <getopt.h>
 #include <progname.h>
 #include <quote.h>
-
-#if HAVE_LIBTEXTSTYLE
-# include <textstyle.h>
-#endif
+#include <textstyle.h>
 
 #include "complain.h"
 #include "files.h"
@@ -590,7 +587,6 @@ command_line_location (void)
 static void
 getargs_colors (int argc _GL_UNUSED, char *argv[] _GL_UNUSED)
 {
-#if HAVE_LIBTEXTSTYLE
   for (int i = 1; i < argc; i++)
     {
       const char *arg = argv[i];
@@ -600,7 +596,6 @@ getargs_colors (int argc _GL_UNUSED, char *argv[] _GL_UNUSED)
         handle_style_option (arg + strlen ("--style="));
     }
   complain_init_color ();
-#endif
 }
 
 
