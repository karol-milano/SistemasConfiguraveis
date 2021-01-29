@@ -1,5 +1,5 @@
 /* Declaration for error-reporting function for Bison.
-   Copyright 2000 Free Software Foundation, Inc.
+   Copyright 2000, 2001 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
@@ -248,62 +248,3 @@ fatal (message, va_alist)
   fflush (stderr);
   exit (1);
 }
-
-/*------------------------------------------------------------------.
-| A severe error has occurred, we cannot proceed. Exit with STATUS, |
-| and report the error message of the errno ERRNUM.                 |
-`------------------------------------------------------------------*/
-
-void
-#if defined VA_START && defined __STDC__
-error (int status, int errnum,
-       const char *message, ...)
-#else
-error (status, errnum, message, va_alist)
-     int status;
-     int errnum;
-     char *message;
-     va_dcl
-#endif
-{
-#ifdef VA_START
-  va_list args;
-#endif
-
-  fflush (stdout);
-  if (infile != NULL)
-    fprintf (stderr, "%s:%d: ", infile, lineno);
-  else
-    fprintf (stderr, "%s:", program_name);
-
-  fputs (_("fatal error: "), stderr);
-
-#ifdef VA_START
-  VA_START (args, message);
-  vfprintf (stderr, message, args);
-  va_end (args);
-#else
-  fprintf (stderr, message, a1, a2, a3, a4, a5, a6, a7, a8);
-#endif
-
-  if (errnum)
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
-  putc ('\n', stderr);
-  fflush (stderr);
-  if (status)
-    exit (status);
-}
