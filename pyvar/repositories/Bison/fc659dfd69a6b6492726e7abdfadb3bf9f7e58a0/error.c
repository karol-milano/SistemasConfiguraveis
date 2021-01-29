@@ -27,7 +27,6 @@
 #else
 # include "gettext.h"
 #endif
-#define _(msgid) gettext (msgid)
 
 #ifdef _LIBC
 # include <wchar.h>
@@ -55,7 +54,14 @@ void exit ();
 #endif
 
 #include "error.h"
-#include "unlocked-io.h"
+
+#if !_LIBC
+# include "unlocked-io.h"
+#endif
+
+#ifndef _
+# define _(String) String
+#endif
 
 /* If NULL, error will flush stdout, then print on stderr the program
    name, a colon and a space.  Otherwise, error will call this
@@ -74,6 +80,7 @@ unsigned int error_message_count;
 
 # define program_name program_invocation_name
 # include <errno.h>
+# include <libio/libioP.h>
 
 /* In GNU libc we want do not want to use the common name `error' directly.
    Instead make it a weak alias.  */
@@ -88,7 +95,9 @@ extern void __error_at_line (int status, int errnum, const char *file_name,
 
 # ifdef USE_IN_LIBIO
 #  include <libio/iolibio.h>
-#  define fflush(s) _IO_fflush (s)
+#  define fflush(s) INTUSE(_IO_fflush) (s)
+#  undef putc
+#  define putc(c, fp) INTUSE(_IO_putc) (c, fp)
 # endif
 
 #else /* not _LIBC */
