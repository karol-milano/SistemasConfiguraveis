@@ -1,6 +1,7 @@
 /* Declaration for error-reporting function for Bison.
 
-   Copyright (C) 2000, 2001, 2002, 2004, 2005 Free Software Foundation, Inc.
+   Copyright (C) 2000, 2001, 2002, 2004, 2005, 2006
+   Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
@@ -32,49 +33,65 @@
    name of the executing program.  */
 extern char *program_name;
 
-/* This variable is set each time `warn' is called.  */
-bool warning_issued;
-
-/* This variable is set each time `complain' is called.  */
 bool complaint_issued;
 
 
-/*--------------------------------.
-| Report a warning, and proceed.  |
-`--------------------------------*/
 
+/** Report an error message.
+ *
+ * \param loc     the location, defaulting to the current file,
+ *                or the program name.
+ * \param prefix  put before the message (e.g., "warning").
+ * \param message the error message, a printf format string.
+ * \param args    the arguments of the format string.
+ */
+static
 void
-warn_at (location loc, const char *message, ...)
+error_message (location *loc,
+	       const char *prefix,
+	       const char *message, va_list args)
 {
-  va_list args;
-
-  location_print (stderr, loc);
+  if (loc)
+    location_print (stderr, *loc);
+  else
+    fputs (current_file ? current_file : program_name, stderr);
   fputs (": ", stderr);
-  fputs (_("warning: "), stderr);
 
-  va_start (args, message);
+  if (prefix)
+    fprintf (stderr, "%s: ", prefix);
+
   vfprintf (stderr, message, args);
   va_end (args);
-
-  warning_issued = true;
   putc ('\n', stderr);
+  fflush (stderr);
+}
+
+/** Wrap error_message() with varargs handling. */
+#define ERROR_MESSAGE(Loc, Prefix, Message)	\
+{						\
+  va_list args;					\
+  va_start (args, Message);			\
+  error_message (Loc, Prefix, Message, args);	\
+}
+
+
+/*--------------------------------.
+| Report a warning, and proceed.  |
+`--------------------------------*/
+
+void
+warn_at (location loc, const char *message, ...)
+{
+  ERROR_MESSAGE (&loc, _("warning"), message);
 }
 
 void
 warn (const char *message, ...)
 {
-  va_list args;
-
-  fprintf (stderr, "%s: %s", current_file ? current_file : program_name, _("warning: "));
+  ERROR_MESSAGE (NULL, _("warning"), message);
+}
 
-  va_start (args, message);
-  vfprintf (stderr, message, args);
-  va_end (args);
 
-  warning_issued = true;
-  putc ('\n', stderr);
-}
-
 /*-----------------------------------------------------------.
 | An error has occurred, but we can proceed, and die later.  |
 `-----------------------------------------------------------*/
@@ -82,34 +99,18 @@ warn (const char *message, ...)
 void
 complain_at (location loc, const char *message, ...)
 {
-  va_list args;
-
-  location_print (stderr, loc);
-  fputs (": ", stderr);
-
-  va_start (args, message);
-  vfprintf (stderr, message, args);
-  va_end (args);
-
+  ERROR_MESSAGE (&loc, NULL, message);
   complaint_issued = true;
-  putc ('\n', stderr);
 }
 
 void
 complain (const char *message, ...)
 {
-  va_list args;
-
-  fprintf (stderr, "%s: ", current_file ? current_file : program_name);
-
-  va_start (args, message);
-  vfprintf (stderr, message, args);
-  va_end (args);
-
+  ERROR_MESSAGE (NULL, NULL, message);
   complaint_issued = true;
-  putc ('\n', stderr);
 }
-
+
+
 /*-------------------------------------------------.
 | A severe error has occurred, we cannot proceed.  |
 `-------------------------------------------------*/
@@ -117,31 +118,13 @@ complain (const char *message, ...)
 void
 fatal_at (location loc, const char *message, ...)
 {
-  va_list args;
-
-  location_print (stderr, loc);
-  fputs (": ", stderr);
-  fputs (_("fatal error: "), stderr);
-
-  va_start (args, message);
-  vfprintf (stderr, message, args);
-  va_end (args);
-  putc ('\n', stderr);
+  ERROR_MESSAGE (&loc, _("fatal error"), message);
   exit (EXIT_FAILURE);
 }
 
 void
 fatal (const char *message, ...)
 {
-  va_list args;
-
-  fprintf (stderr, "%s: ", current_file ? current_file : program_name);
-
-  fputs (_("fatal error: "), stderr);
-
-  va_start (args, message);
-  vfprintf (stderr, message, args);
-  va_end (args);
-  putc ('\n', stderr);
+  ERROR_MESSAGE (NULL, _("fatal error"), message);
   exit (EXIT_FAILURE);
 }
