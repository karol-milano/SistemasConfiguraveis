@@ -23,13 +23,10 @@
 #include "system.h"
 
 #include <argmatch.h>
-#include <stdarg.h>
 #include <progname.h>
+#include <stdarg.h>
 #include <sys/stat.h>
-
-#if HAVE_LIBTEXTSTYLE
-# include <textstyle.h>
-#endif
+#include <textstyle.h>
 
 #include "complain.h"
 #include "files.h"
@@ -68,41 +65,33 @@ static severity warnings_flag[warnings_size];
 
 static unsigned *indent_ptr = NULL;
 
-#if HAVE_LIBTEXTSTYLE
 styled_ostream_t errstream = NULL;
-#endif
 
 void
-begin_use_class (const char *s _GL_UNUSED, FILE *out _GL_UNUSED)
+begin_use_class (const char *s, FILE *out)
 {
-#if HAVE_LIBTEXTSTYLE
   if (out == stderr)
     {
       styled_ostream_begin_use_class (errstream, s);
       styled_ostream_flush_to_current_style (errstream);
     }
-#endif
 }
 
 void
-end_use_class (const char *s _GL_UNUSED, FILE *out _GL_UNUSED)
+end_use_class (const char *s, FILE *out)
 {
-#if HAVE_LIBTEXTSTYLE
   if (out == stderr)
     {
       styled_ostream_end_use_class (errstream, s);
       styled_ostream_flush_to_current_style (errstream);
     }
-#endif
 }
 
 void
-flush (FILE *out _GL_UNUSED)
+flush (FILE *out)
 {
-#if HAVE_LIBTEXTSTYLE
   if (out == stderr)
     ostream_flush (errstream, FLUSH_THIS_STREAM);
-#endif
   fflush (out);
 }
 
@@ -267,10 +256,11 @@ complain_init_color (void)
   else
     /* No styling.  */
     style_file_name = NULL;
+#endif
+
   errstream =
     styled_ostream_create (STDERR_FILENO, "(stderr)", TTYCTL_AUTO,
                            style_file_name);
-#endif
 }
 
 void
