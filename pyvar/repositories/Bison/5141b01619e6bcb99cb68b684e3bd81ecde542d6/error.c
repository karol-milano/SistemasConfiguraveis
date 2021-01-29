@@ -1,5 +1,5 @@
 /* Error handler for noninteractive utilities
-   Copyright (C) 1990-2000 Free Software Foundation, Inc.
+   Copyright (C) 1990-1998, 2000 Free Software Foundation, Inc.
 
    This file is part of the GNU C Library.  Its master source is NOT part of
    the C library, however.  The master source lives in /gd/gnu/lib.
@@ -26,6 +26,9 @@
 #endif
 
 #include <stdio.h>
+#if HAVE_LIBINTL_H
+# include <libintl.h>
+#endif
 
 #if HAVE_VPRINTF || HAVE_DOPRNT || _LIBC
 # if __STDC__
@@ -49,6 +52,13 @@ void exit ();
 
 #include "error.h"
 
+#ifndef HAVE_DECL_STRERROR_R
+"this configure-time declaration test was not run"
+#endif
+#if !HAVE_DECL_STRERROR_R
+char *strerror_r ();
+#endif
+
 #ifndef _
 # define _(String) String
 #endif
@@ -76,6 +86,11 @@ unsigned int error_message_count;
 # define error __error
 # define error_at_line __error_at_line
 
+# ifdef USE_IN_LIBIO
+#  include <libio/iolibio.h>
+#  define fflush(s) _IO_fflush (s)
+# endif
+
 #else /* not _LIBC */
 
 /* The calling program should define program_name and set it to the
