@@ -26,11 +26,6 @@
 # define vfprintf(stream, message, args) _doprnt (message, args, stream)
 #endif
 
-#if STDC_HEADERS || _LIBC
-# include <stdlib.h>
-# include <string.h>
-#endif
-
 #include "complain.h"
 #include "files.h"
 
@@ -38,36 +33,18 @@
 # define _(String) String
 #endif
 
-#ifdef _LIBC
-/* In the GNU C library, there is a predefined variable for this.  */
-
-# define program_name program_invocation_name
-# include <errno.h>
-
-/* In GNU libc we want do not want to use the common name `error' directly.
-   Instead make it a weak alias.  */
-# define error __error
-# define error_at_line __error_at_line
-
-# ifdef USE_IN_LIBIO
-#  include <libio/iolibio.h>
-#  define fflush(s) _IO_fflush (s)
-# endif
-
-#else /* not _LIBC */
-
 /* The calling program should define program_name and set it to the
    name of the executing program.  */
 extern char *program_name;
 
-# if HAVE_STRERROR
-#  ifndef HAVE_DECL_STRERROR
+#if HAVE_STRERROR
+# ifndef HAVE_DECL_STRERROR
 "this configure-time declaration test was not run"
-#  endif
-#  if !HAVE_DECL_STRERROR && !defined strerror
+# endif
+# if !HAVE_DECL_STRERROR && !defined strerror
 char *strerror (int);
-#  endif
-# else
+# endif
+#else
 static char *
 private_strerror (int errnum)
 {
@@ -78,9 +55,8 @@ private_strerror (int errnum)
     return _(sys_errlist[errnum]);
   return _("Unknown system error");
 }
-#  define strerror private_strerror
-# endif /* HAVE_STRERROR */
-#endif	/* not _LIBC */
+# define strerror private_strerror
+#endif /* HAVE_STRERROR */
 
 /* This variable is set each time `warn' is called.  */
 bool warning_issued;
@@ -94,12 +70,12 @@ bool complaint_issued;
 `--------------------------------*/
 
 void
-warn_at (location_t location, const char *message, ...)
+warn_at (location loc, const char *message, ...)
 {
   va_list args;
 
   fflush (stdout);
-  location_print (stderr, location);
+  location_print (stderr, loc);
   fputs (": ", stderr);
   fputs (_("warning: "), stderr);
 
@@ -134,12 +110,12 @@ warn (const char *message, ...)
 `-----------------------------------------------------------*/
 
 void
-complain_at (location_t location, const char *message, ...)
+complain_at (location loc, const char *message, ...)
 {
   va_list args;
 
   fflush (stdout);
-  location_print (stderr, location);
+  location_print (stderr, loc);
   fputs (": ", stderr);
 
   va_start (args, message);
@@ -173,12 +149,12 @@ complain (const char *message, ...)
 `-------------------------------------------------*/
 
 void
-fatal_at (location_t location, const char *message, ...)
+fatal_at (location loc, const char *message, ...)
 {
   va_list args;
 
   fflush (stdout);
-  location_print (stderr, location);
+  location_print (stderr, loc);
   fputs (": ", stderr);
   fputs (_("fatal error: "), stderr);
 
