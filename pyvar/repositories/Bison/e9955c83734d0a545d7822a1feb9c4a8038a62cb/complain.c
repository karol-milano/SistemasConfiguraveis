@@ -114,6 +114,56 @@ unsigned int complain_message_count;
 | Report a warning, and proceed.  |
 `--------------------------------*/
 
+void
+#if defined VA_START && defined __STDC__
+warn_at (int location, const char *message, ...)
+#else
+warn_at (location, message, va_alist)
+  int location
+  char *message;
+  va_dcl
+#endif
+{
+#ifdef VA_START
+  va_list args;
+#endif
+
+  if (error_one_per_line)
+    {
+      static const char *old_infile;
+      static int old_lineno;
+
+      if (old_lineno == location &&
+	  (infile == old_infile || !strcmp (old_infile, infile)))
+	/* Simply return and print nothing.  */
+	return;
+
+      old_infile = infile;
+      old_lineno = location;
+    }
+
+  fflush (stdout);
+  if (infile != NULL)
+    fprintf (stderr, "%s:%d: ", infile, location);
+  else
+    fprintf (stderr, "%s:", program_name);
+
+  fputs (_("warning: "), stderr);
+
+#ifdef VA_START
+  VA_START (args, message);
+  vfprintf (stderr, message, args);
+  va_end (args);
+#else
+  fprintf (stderr, message, a1, a2, a3, a4, a5, a6, a7, a8);
+#endif
+
+  ++warn_message_count;
+  putc ('\n', stderr);
+  fflush (stderr);
+}
+
+
 void
 #if defined VA_START && defined __STDC__
 warn (const char *message, ...)
@@ -166,6 +216,54 @@ warn (message, va_alist)
 | An error has occurred, but we can proceed, and die later.  |
 `-----------------------------------------------------------*/
 
+void
+#if defined VA_START && defined __STDC__
+complain_at (int location, const char *message, ...)
+#else
+complain_at (location, message, va_alist)
+  int location;
+  char *message;
+  va_dcl
+#endif
+{
+#ifdef VA_START
+  va_list args;
+#endif
+
+  if (error_one_per_line)
+    {
+      static const char *old_infile;
+      static int old_lineno;
+
+      if (old_lineno == location &&
+	  (infile == old_infile || !strcmp (old_infile, infile)))
+	/* Simply return and print nothing.  */
+	return;
+
+      old_infile = infile;
+      old_lineno = location;
+    }
+
+  fflush (stdout);
+  if (infile != NULL)
+    fprintf (stderr, "%s:%d: ", infile, location);
+  else
+    fprintf (stderr, "%s:", program_name);
+
+#ifdef VA_START
+  VA_START (args, message);
+  vfprintf (stderr, message, args);
+  va_end (args);
+#else
+  fprintf (stderr, message, a1, a2, a3, a4, a5, a6, a7, a8);
+#endif
+
+  ++complain_message_count;
+  putc ('\n', stderr);
+  fflush (stderr);
+}
+
+
 void
 #if defined VA_START && defined __STDC__
 complain (const char *message, ...)
@@ -216,6 +314,40 @@ complain (message, va_alist)
 | A severe error has occurred, we cannot proceed.  |
 `-------------------------------------------------*/
 
+void
+#if defined VA_START && defined __STDC__
+fatal_at (int location, const char *message, ...)
+#else
+fatal (location, message, va_alist)
+  int location;
+  char *message;
+  va_dcl
+#endif
+{
+#ifdef VA_START
+  va_list args;
+#endif
+
+  fflush (stdout);
+  if (infile != NULL)
+    fprintf (stderr, "%s:%d: ", infile, location);
+  else
+    fprintf (stderr, "%s:", program_name);
+
+  fputs (_("fatal error: "), stderr);
+
+#ifdef VA_START
+  VA_START (args, message);
+  vfprintf (stderr, message, args);
+  va_end (args);
+#else
+  fprintf (stderr, message, a1, a2, a3, a4, a5, a6, a7, a8);
+#endif
+  putc ('\n', stderr);
+  fflush (stderr);
+  exit (1);
+}
+
 void
 #if defined VA_START && defined __STDC__
 fatal (const char *message, ...)
