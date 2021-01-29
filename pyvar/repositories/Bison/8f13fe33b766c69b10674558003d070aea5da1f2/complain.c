@@ -47,18 +47,62 @@ void exit ();
 
 #include "complain.h"
 
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
 
 #ifdef _LIBC
 /* In the GNU C library, there is a predefined variable for this.  */
+
 # define program_name program_invocation_name
+# include <errno.h>
+
+/* In GNU libc we want do not want to use the common name `error' directly.
+   Instead make it a weak alias.  */
+# define error __error
+# define error_at_line __error_at_line
+
+# ifdef USE_IN_LIBIO
+#  include <libio/iolibio.h>
+#  define fflush(s) _IO_fflush (s)
+# endif
+
 #else /* not _LIBC */
+
 /* The calling program should define program_name and set it to the
    name of the executing program.  */
 extern char *program_name;
-#endif
+
+# ifdef HAVE_STRERROR_R
+#  define __strerror_r strerror_r
+# else
+#  if HAVE_STRERROR
+#   ifndef strerror		/* On some systems, strerror is a macro */
+char *strerror ();
+#   endif
+#  else
+static char *
+private_strerror (errnum)
+     int errnum;
+{
+  extern char *sys_errlist[];
+  extern int sys_nerr;
+
+  if (errnum > 0 && errnum <= sys_nerr)
+    return _(sys_errlist[errnum]);
+  return _("Unknown system error");
+}
+#   define strerror private_strerror
+#  endif /* HAVE_STRERROR */
+# endif	/* HAVE_STRERROR_R */
+#endif	/* not _LIBC */
 
 /* This variable is incremented each time `warn' is called.  */
 unsigned int warn_message_count;
