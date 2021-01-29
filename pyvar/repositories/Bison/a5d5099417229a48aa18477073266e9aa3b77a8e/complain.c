@@ -159,55 +159,6 @@ warn_at (location, message, va_alist)
   putc ('\n', stderr);
   fflush (stderr);
 }
-
-
-void
-#if defined VA_START && defined __STDC__
-warn (const char *message, ...)
-#else
-warn (message, va_alist)
-     char *message;
-     va_dcl
-#endif
-{
-#ifdef VA_START
-  va_list args;
-#endif
-
-  if (error_one_per_line)
-    {
-      static const char *old_infile;
-      static int old_lineno;
-
-      if (old_lineno == lineno &&
-	  (infile == old_infile || !strcmp (old_infile, infile)))
-	/* Simply return and print nothing.  */
-	return;
-
-      old_infile = infile;
-      old_lineno = lineno;
-    }
-
-  fflush (stdout);
-  if (infile != NULL)
-    fprintf (stderr, "%s:%d: ", infile, lineno);
-  else
-    fprintf (stderr, "%s:", program_name);
-
-  fputs (_("warning: "), stderr);
-
-#ifdef VA_START
-  VA_START (args, message);
-  vfprintf (stderr, message, args);
-  va_end (args);
-#else
-  fprintf (stderr, message, a1, a2, a3, a4, a5, a6, a7, a8);
-#endif
-
-  ++warn_message_count;
-  putc ('\n', stderr);
-  fflush (stderr);
-}
 
 /*-----------------------------------------------------------.
 | An error has occurred, but we can proceed, and die later.  |
@@ -257,53 +208,6 @@ complain_at (location, message, va_alist)
   putc ('\n', stderr);
   fflush (stderr);
 }
-
-
-void
-#if defined VA_START && defined __STDC__
-complain (const char *message, ...)
-#else
-complain (message, va_alist)
-     char *message;
-     va_dcl
-#endif
-{
-#ifdef VA_START
-  va_list args;
-#endif
-
-  if (error_one_per_line)
-    {
-      static const char *old_infile;
-      static int old_lineno;
-
-      if (old_lineno == lineno &&
-	  (infile == old_infile || !strcmp (old_infile, infile)))
-	/* Simply return and print nothing.  */
-	return;
-
-      old_infile = infile;
-      old_lineno = lineno;
-    }
-
-  fflush (stdout);
-  if (infile != NULL)
-    fprintf (stderr, "%s:%d: ", infile, lineno);
-  else
-    fprintf (stderr, "%s:", program_name);
-
-#ifdef VA_START
-  VA_START (args, message);
-  vfprintf (stderr, message, args);
-  va_end (args);
-#else
-  fprintf (stderr, message, a1, a2, a3, a4, a5, a6, a7, a8);
-#endif
-
-  ++complain_message_count;
-  putc ('\n', stderr);
-  fflush (stderr);
-}
 
 /*-------------------------------------------------.
 | A severe error has occurred, we cannot proceed.  |
@@ -354,10 +258,7 @@ fatal (message, va_alist)
 #endif
 
   fflush (stdout);
-  if (infile != NULL)
-    fprintf (stderr, "%s:%d: ", infile, lineno);
-  else
-    fprintf (stderr, "%s:", program_name);
+  fprintf (stderr, "%s: ", infile ? infile : program_name);
 
   fputs (_("fatal error: "), stderr);
 
