@@ -1,5 +1,5 @@
 /* Declaration for error-reporting function for Bison.
-   Copyright 2000, 2001 Free Software Foundation, Inc.
+   Copyright (C) 2000, 2001, 2002  Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
@@ -130,6 +130,35 @@ warn_at (location, message, va_alist)
   fputs (": ", stderr);
   fputs (_("warning: "), stderr);
 
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
+void
+#if defined VA_START && defined __STDC__
+warn (const char *message, ...)
+#else
+warn (message, va_alist)
+  char *message;
+  va_dcl
+#endif
+{
+#ifdef VA_START
+  va_list args;
+#endif
+
+  fflush (stdout);
+  fprintf (stderr, "%s: %s", infile ? infile : program_name, _("warning: "));
+
 #ifdef VA_START
   VA_START (args, message);
   vfprintf (stderr, message, args);
@@ -165,6 +194,35 @@ complain_at (location, message, va_alist)
   LOCATION_PRINT (stderr, location);
   fputs (": ", stderr);
 
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
+void
+#if defined VA_START && defined __STDC__
+complain (const char *message, ...)
+#else
+complain (message, va_alist)
+     char *message;
+     va_dcl
+#endif
+{
+#ifdef VA_START
+  va_list args;
+#endif
+
+  fflush (stdout);
+  fprintf (stderr, "%s: ", infile ? infile : program_name);
+
 #ifdef VA_START
   VA_START (args, message);
   vfprintf (stderr, message, args);
@@ -186,7 +244,7 @@ void
 #if defined VA_START && defined __STDC__
 fatal_at (location_t location, const char *message, ...)
 #else
-fatal (location, message, va_alist)
+fatal_at (location, message, va_alist)
   location_t location;
   char *message;
   va_dcl
