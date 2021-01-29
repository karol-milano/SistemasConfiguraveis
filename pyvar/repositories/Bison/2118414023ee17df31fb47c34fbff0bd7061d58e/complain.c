@@ -21,17 +21,9 @@
 
 #include "system.h"
 
-#if HAVE_VPRINTF || HAVE_DOPRNT || _LIBC
-# ifdef __STDC__
-#  include <stdarg.h>
-#  define VA_START(args, lastarg) va_start(args, lastarg)
-# else
-#  include <varargs.h>
-#  define VA_START(args, lastarg) va_start(args)
-# endif
-#else
-# define va_alist a1, a2, a3, a4, a5, a6, a7, a8
-# define va_dcl char *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8;
+#include <stdarg.h>
+#if ! (HAVE_VPRINTF || defined vfprintf)
+# define vfprintf(stream, message, args) _doprnt (message, args, stream)
 #endif
 
 #if STDC_HEADERS || _LIBC
@@ -74,12 +66,11 @@ extern char *program_name;
 "this configure-time declaration test was not run"
 #  endif
 #  if !HAVE_DECL_STRERROR && !defined strerror
-char *strerror PARAMS ((int));
+char *strerror (int);
 #  endif
 # else
 static char *
-private_strerror (errnum)
-     int errnum;
+private_strerror (int errnum)
 {
   extern char *sys_errlist[];
   extern int sys_nerr;
@@ -104,31 +95,18 @@ unsigned int complain_message_count;
 `--------------------------------*/
 
 void
-#if defined VA_START && defined __STDC__
 warn_at (location_t location, const char *message, ...)
-#else
-warn_at (location, message, va_alist)
-  location_t location
-  char *message;
-  va_dcl
-#endif
 {
-#ifdef VA_START
   va_list args;
-#endif
 
   fflush (stdout);
   LOCATION_PRINT (stderr, location);
   fputs (": ", stderr);
   fputs (_("warning: "), stderr);
 
-#ifdef VA_START
-  VA_START (args, message);
+  va_start (args, message);
   vfprintf (stderr, message, args);
   va_end (args);
-#else
-  fprintf (stderr, message, a1, a2, a3, a4, a5, a6, a7, a8);
-#endif
 
   ++warn_message_count;
   putc ('\n', stderr);
@@ -136,28 +114,16 @@ warn_at (location, message, va_alist)
 }
 
 void
-#if defined VA_START && defined __STDC__
 warn (const char *message, ...)
-#else
-warn (message, va_alist)
-  char *message;
-  va_dcl
-#endif
 {
-#ifdef VA_START
   va_list args;
-#endif
 
   fflush (stdout);
   fprintf (stderr, "%s: %s", infile ? infile : program_name, _("warning: "));
 
-#ifdef VA_START
-  VA_START (args, message);
+  va_start (args, message);
   vfprintf (stderr, message, args);
   va_end (args);
-#else
-  fprintf (stderr, message, a1, a2, a3, a4, a5, a6, a7, a8);
-#endif
 
   ++warn_message_count;
   putc ('\n', stderr);
@@ -169,30 +135,17 @@ warn (message, va_alist)
 `-----------------------------------------------------------*/
 
 void
-#if defined VA_START && defined __STDC__
 complain_at (location_t location, const char *message, ...)
-#else
-complain_at (location, message, va_alist)
-  location_t location;
-  char *message;
-  va_dcl
-#endif
 {
-#ifdef VA_START
   va_list args;
-#endif
 
   fflush (stdout);
   LOCATION_PRINT (stderr, location);
   fputs (": ", stderr);
 
-#ifdef VA_START
-  VA_START (args, message);
+  va_start (args, message);
   vfprintf (stderr, message, args);
   va_end (args);
-#else
-  fprintf (stderr, message, a1, a2, a3, a4, a5, a6, a7, a8);
-#endif
 
   ++complain_message_count;
   putc ('\n', stderr);
@@ -200,28 +153,16 @@ complain_at (location, message, va_alist)
 }
 
 void
-#if defined VA_START && defined __STDC__
 complain (const char *message, ...)
-#else
-complain (message, va_alist)
-     char *message;
-     va_dcl
-#endif
 {
-#ifdef VA_START
   va_list args;
-#endif
 
   fflush (stdout);
   fprintf (stderr, "%s: ", infile ? infile : program_name);
 
-#ifdef VA_START
-  VA_START (args, message);
+  va_start (args, message);
   vfprintf (stderr, message, args);
   va_end (args);
-#else
-  fprintf (stderr, message, a1, a2, a3, a4, a5, a6, a7, a8);
-#endif
 
   ++complain_message_count;
   putc ('\n', stderr);
@@ -233,61 +174,36 @@ complain (message, va_alist)
 `-------------------------------------------------*/
 
 void
-#if defined VA_START && defined __STDC__
 fatal_at (location_t location, const char *message, ...)
-#else
-fatal_at (location, message, va_alist)
-  location_t location;
-  char *message;
-  va_dcl
-#endif
 {
-#ifdef VA_START
   va_list args;
-#endif
 
   fflush (stdout);
   LOCATION_PRINT (stderr, location);
   fputs (": ", stderr);
   fputs (_("fatal error: "), stderr);
 
-#ifdef VA_START
-  VA_START (args, message);
+  va_start (args, message);
   vfprintf (stderr, message, args);
   va_end (args);
-#else
-  fprintf (stderr, message, a1, a2, a3, a4, a5, a6, a7, a8);
-#endif
   putc ('\n', stderr);
   fflush (stderr);
   exit (1);
 }
 
 void
-#if defined VA_START && defined __STDC__
 fatal (const char *message, ...)
-#else
-fatal (message, va_alist)
-     char *message;
-     va_dcl
-#endif
 {
-#ifdef VA_START
   va_list args;
-#endif
 
   fflush (stdout);
   fprintf (stderr, "%s: ", infile ? infile : program_name);
 
   fputs (_("fatal error: "), stderr);
 
-#ifdef VA_START
-  VA_START (args, message);
+  va_start (args, message);
   vfprintf (stderr, message, args);
   va_end (args);
-#else
-  fprintf (stderr, message, a1, a2, a3, a4, a5, a6, a7, a8);
-#endif
   putc ('\n', stderr);
   fflush (stderr);
   exit (1);
