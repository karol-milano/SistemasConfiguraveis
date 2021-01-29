@@ -1,23 +1,22 @@
 /* Error handler for noninteractive utilities
-   Copyright (C) 1990-1998, 2000 Free Software Foundation, Inc.
-
+   Copyright (C) 1990-1998, 2000, 2001 Free Software Foundation, Inc.
    This file is part of the GNU C Library.  Its master source is NOT part of
    the C library, however.  The master source lives in /gd/gnu/lib.
 
    The GNU C Library is free software; you can redistribute it and/or
-   modify it under the terms of the GNU Library General Public License as
-   published by the Free Software Foundation; either version 2 of the
-   License, or (at your option) any later version.
+   modify it under the terms of the GNU Lesser General Public
+   License as published by the Free Software Foundation; either
+   version 2.1 of the License, or (at your option) any later version.
 
    The GNU C Library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
-   Library General Public License for more details.
+   Lesser General Public License for more details.
 
-   You should have received a copy of the GNU Library General Public
-   License along with the GNU C Library; see the file COPYING.LIB.  If not,
-   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
-   Boston, MA 02111-1307, USA.  */
+   You should have received a copy of the GNU Lesser General Public
+   License along with the GNU C Library; if not, write to the Free
+   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
+   02111-1307 USA.  */
 
 /* Written by David MacKenzie <djm@gnu.ai.mit.edu>.  */
 
@@ -29,6 +28,10 @@
 #if HAVE_LIBINTL_H
 # include <libintl.h>
 #endif
+#ifdef _LIBC
+# include <wchar.h>
+# define mbsrtowcs __mbsrtowcs
+#endif
 
 #if HAVE_VPRINTF || HAVE_DOPRNT || _LIBC
 # if __STDC__
@@ -52,13 +55,6 @@ void exit ();
 
 #include "error.h"
 
-#ifndef HAVE_DECL_STRERROR_R
-"this configure-time declaration test was not run"
-#endif
-#if !HAVE_DECL_STRERROR_R
-char *strerror_r ();
-#endif
-
 #ifndef _
 # define _(String) String
 #endif
@@ -83,6 +79,12 @@ unsigned int error_message_count;
 
 /* In GNU libc we want do not want to use the common name `error' directly.
    Instead make it a weak alias.  */
+extern void __error (int status, int errnum, const char *message, ...)
+     __attribute__ ((__format__ (__printf__, 3, 4)));
+extern void __error_at_line (int status, int errnum, const char *file_name,
+			     unsigned int line_number, const char *message,
+			     ...)
+     __attribute__ ((__format__ (__printf__, 5, 6)));;
 # define error __error
 # define error_at_line __error_at_line
 
@@ -93,21 +95,30 @@ unsigned int error_message_count;
 
 #else /* not _LIBC */
 
+# if !HAVE_DECL_STRERROR_R && STRERROR_R_CHAR_P
+#  ifndef HAVE_DECL_STRERROR_R
+"this configure-time declaration test was not run"
+#  endif
+char *strerror_r ();
+# endif
+
 /* The calling program should define program_name and set it to the
    name of the executing program.  */
 extern char *program_name;
 
-# ifdef HAVE_STRERROR_R
+# if HAVE_STRERROR_R || defined strerror_r
 #  define __strerror_r strerror_r
 # else
 #  if HAVE_STRERROR
-#   ifndef strerror		/* On some systems, strerror is a macro */
+#   ifndef HAVE_DECL_STRERROR
+"this configure-time declaration test was not run"
+#   endif
+#   if !HAVE_DECL_STRERROR
 char *strerror ();
 #   endif
 #  else
 static char *
-private_strerror (errnum)
-     int errnum;
+private_strerror (int errnum)
 {
   extern char *sys_errlist[];
   extern int sys_nerr;
@@ -118,15 +129,118 @@ private_strerror (errnum)
 }
 #   define strerror private_strerror
 #  endif /* HAVE_STRERROR */
-# endif	/* HAVE_STRERROR_R */
+# endif	/* HAVE_STRERROR_R || defined strerror_r */
 #endif	/* not _LIBC */
 
+static void
+print_errno_message (int errnum)
+{
+  char const *s;
+
+#if defined HAVE_STRERROR_R || _LIBC
+  char errbuf[1024];
+# if STRERROR_R_CHAR_P || _LIBC
+  s = __strerror_r (errnum, errbuf, sizeof errbuf);
+# else
+  if (__strerror_r (errnum, errbuf, sizeof errbuf) == 0)
+    s = errbuf;
+  else
+    s = 0;
+# endif
+#else
+  s = strerror (errnum);
+#endif
+
+#if !_LIBC
+  if (! s)
+    s = _("Unknown system error");
+#endif
+
+#if _LIBC && USE_IN_LIBIO
+  if (_IO_fwide (stderr, 0) > 0)
+    {
+      __fwprintf (stderr, L": %s", s);
+      return;
+    }
+#endif
+
+  fprintf (stderr, ": %s", s);
+}
+
+#ifdef VA_START
+static void
+error_tail (int status, int errnum, const char *message, va_list args)
+{
+# if HAVE_VPRINTF || _LIBC
+#  if _LIBC && USE_IN_LIBIO
+  if (_IO_fwide (stderr, 0) > 0)
+    {
+#   define ALLOCA_LIMIT	2000
+      size_t len = strlen (message) + 1;
+      wchar_t *wmessage = NULL;
+      mbstate_t st;
+      size_t res;
+      const char *tmp;
+
+      do
+	{
+	  if (len < ALLOCA_LIMIT)
+	    wmessage = (wchar_t *) alloca (len * sizeof (wchar_t));
+	  else
+	    {
+	      if (wmessage != NULL && len / 2 < ALLOCA_LIMIT)
+		wmessage = NULL;
+
+	      wmessage = (wchar_t *) realloc (wmessage,
+					      len * sizeof (wchar_t));
+
+	      if (wmessage == NULL)
+		{
+		  fputws_unlocked (L"out of memory\n", stderr);
+		  return;
+		}
+	    }
+
+	  memset (&st, '\0', sizeof (st));
+	  tmp =message;
+	}
+      while ((res = mbsrtowcs (wmessage, &tmp, len, &st)) == len);
+
+      if (res == (size_t) -1)
+	/* The string cannot be converted.  */
+	wmessage = (wchar_t *) L"???";
+
+      __vfwprintf (stderr, wmessage, args);
+    }
+  else
+#  endif
+    vfprintf (stderr, message, args);
+# else
+  _doprnt (message, args, stderr);
+# endif
+  va_end (args);
+
+  ++error_message_count;
+  if (errnum)
+    print_errno_message (errnum);
+# if _LIBC && USE_IN_LIBIO
+  if (_IO_fwide (stderr, 0) > 0)
+    putwc (L'\n', stderr);
+  else
+# endif
+    putc ('\n', stderr);
+  fflush (stderr);
+  if (status)
+    exit (status);
+}
+#endif
+
+
 /* Print the program name and error message MESSAGE, which is a printf-style
    format string with optional args.
    If ERRNUM is nonzero, print its corresponding system error message.
    Exit with status STATUS if it is nonzero.  */
 /* VARARGS */
-
 void
 #if defined VA_START && __STDC__
 error (int status, int errnum, const char *message, ...)
@@ -142,47 +256,48 @@ error (status, errnum, message, va_alist)
   va_list args;
 #endif
 
+  fflush (stdout);
+#ifdef _LIBC
+# ifdef USE_IN_LIBIO
+  _IO_flockfile (stderr);
+# else
+  __flockfile (stderr);
+# endif
+#endif
   if (error_print_progname)
     (*error_print_progname) ();
   else
     {
-      fflush (stdout);
-      fprintf (stderr, "%s: ", program_name);
+#if _LIBC && USE_IN_LIBIO
+      if (_IO_fwide (stderr, 0) > 0)
+	__fwprintf (stderr, L"%s: ", program_name);
+      else
+#endif
+	fprintf (stderr, "%s: ", program_name);
     }
 
 #ifdef VA_START
   VA_START (args, message);
-# if HAVE_VPRINTF || _LIBC
-  vfprintf (stderr, message, args);
-# else
-  _doprnt (message, args, stderr);
-# endif
-  va_end (args);
+  error_tail (status, errnum, message, args);
 #else
   fprintf (stderr, message, a1, a2, a3, a4, a5, a6, a7, a8);
-#endif
 
   ++error_message_count;
   if (errnum)
-    {
-#if defined HAVE_STRERROR_R || _LIBC
-      char errbuf[1024];
-# if HAVE_WORKING_STRERROR_R || _LIBC
-      fprintf (stderr, ": %s", __strerror_r (errnum, errbuf, sizeof errbuf));
-# else
-      /* Don't use __strerror_r's return value because on some systems
-	 (at least DEC UNIX 4.0[A-D]) strerror_r returns `int'.  */
-      __strerror_r (errnum, errbuf, sizeof errbuf);
-      fprintf (stderr, ": %s", errbuf);
-# endif
-#else
-      fprintf (stderr, ": %s", strerror (errnum));
-#endif
-    }
+    print_errno_message (errnum);
   putc ('\n', stderr);
   fflush (stderr);
   if (status)
     exit (status);
+#endif
+
+#ifdef _LIBC
+# ifdef USE_IN_LIBIO
+  _IO_funlockfile (stderr);
+# else
+  __funlockfile (stderr);
+# endif
+#endif
 }
 
 /* Sometimes we want to have at most one error per line.  This
@@ -212,8 +327,9 @@ error_at_line (status, errnum, file_name, line_number, message, va_alist)
       static const char *old_file_name;
       static unsigned int old_line_number;
 
-      if (old_line_number == line_number &&
-	  (file_name == old_file_name || !strcmp (old_file_name, file_name)))
+      if (old_line_number == line_number
+	  && (file_name == old_file_name
+	      || strcmp (old_file_name, file_name) == 0))
 	/* Simply return and print nothing.  */
 	return;
 
@@ -221,50 +337,58 @@ error_at_line (status, errnum, file_name, line_number, message, va_alist)
       old_line_number = line_number;
     }
 
+  fflush (stdout);
+#ifdef _LIBC
+# ifdef USE_IN_LIBIO
+  _IO_flockfile (stderr);
+# else
+  __flockfile (stderr);
+# endif
+#endif
   if (error_print_progname)
     (*error_print_progname) ();
   else
     {
-      fflush (stdout);
-      fprintf (stderr, "%s:", program_name);
+#if _LIBC && USE_IN_LIBIO
+      if (_IO_fwide (stderr, 0) > 0)
+	__fwprintf (stderr, L"%s: ", program_name);
+      else
+#endif
+	fprintf (stderr, "%s:", program_name);
     }
 
   if (file_name != NULL)
-    fprintf (stderr, "%s:%d: ", file_name, line_number);
+    {
+#if _LIBC && USE_IN_LIBIO
+      if (_IO_fwide (stderr, 0) > 0)
+	__fwprintf (stderr, L"%s:%d: ", file_name, line_number);
+      else
+#endif
+	fprintf (stderr, "%s:%d: ", file_name, line_number);
+    }
 
 #ifdef VA_START
   VA_START (args, message);
-# if HAVE_VPRINTF || _LIBC
-  vfprintf (stderr, message, args);
-# else
-  _doprnt (message, args, stderr);
-# endif
-  va_end (args);
+  error_tail (status, errnum, message, args);
 #else
   fprintf (stderr, message, a1, a2, a3, a4, a5, a6, a7, a8);
-#endif
 
   ++error_message_count;
   if (errnum)
-    {
-#if defined HAVE_STRERROR_R || _LIBC
-      char errbuf[1024];
-# if HAVE_WORKING_STRERROR_R || _LIBC
-      fprintf (stderr, ": %s", __strerror_r (errnum, errbuf, sizeof errbuf));
-# else
-      /* Don't use __strerror_r's return value because on some systems
-	 (at least DEC UNIX 4.0[A-D]) strerror_r returns `int'.  */
-      __strerror_r (errnum, errbuf, sizeof errbuf);
-      fprintf (stderr, ": %s", errbuf);
-# endif
-#else
-      fprintf (stderr, ": %s", strerror (errnum));
-#endif
-    }
+    print_errno_message (errnum);
   putc ('\n', stderr);
   fflush (stderr);
   if (status)
     exit (status);
+#endif
+
+#ifdef _LIBC
+# ifdef USE_IN_LIBIO
+  _IO_funlockfile (stderr);
+# else
+  __funlockfile (stderr);
+# endif
+#endif
 }
 
 #ifdef _LIBC
