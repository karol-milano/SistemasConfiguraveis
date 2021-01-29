@@ -61,7 +61,7 @@ typedef enum
 /** For each warning type, its severity.  */
 static severity warnings_flag[warnings_size];
 
-static unsigned *indent_ptr = 0;
+static unsigned *indent_ptr = NULL;
 
 /*------------------------.
 | --warnings's handling.  |
@@ -166,6 +166,25 @@ warnings_argmatch (char *args)
 }
 
 
+static const char*
+severity_prefix (severity s)
+{
+  switch (s)
+    {
+    case severity_disabled:
+    case severity_unset:
+      return "";
+    case severity_warning:
+      return _("warning");
+    case severity_error:
+      return  _("error");
+    case severity_fatal:
+      return _("fatal error");
+    }
+  abort ();
+}
+
+
 /*-----------.
 | complain.  |
 `-----------*/
@@ -251,7 +270,8 @@ warnings_print_categories (warnings warn_flags, FILE *f)
  * \param loc     the location, defaulting to the current file,
  *                or the program name.
  * \param flags   the category for this message.
- * \param prefix  put before the message (e.g., "warning").
+ * \param sever   to decide the prefix to put before the message
+ *                (e.g., "warning").
  * \param message the error message, a printf format string.  Iff it
  *                ends with ": ", then no trailing newline is printed,
  *                and the caller should print the remaining
@@ -260,7 +280,7 @@ warnings_print_categories (warnings warn_flags, FILE *f)
  */
 static
 void
-error_message (const location *loc, warnings flags, const char *prefix,
+error_message (const location *loc, warnings flags, severity sever,
                const char *message, va_list args)
 {
   unsigned pos = 0;
@@ -274,7 +294,7 @@ error_message (const location *loc, warnings flags, const char *prefix,
   if (indent_ptr)
     {
       if (*indent_ptr)
-        prefix = NULL;
+        sever = severity_disabled;
       if (!*indent_ptr)
         *indent_ptr = pos;
       else if (*indent_ptr > pos)
@@ -282,13 +302,13 @@ error_message (const location *loc, warnings flags, const char *prefix,
       indent_ptr = NULL;
     }
 
-  if (prefix)
-    fprintf (stderr, "%s: ", prefix);
+  if (sever != severity_disabled)
+    fprintf (stderr, "%s: ", severity_prefix (sever));
 
   vfprintf (stderr, message, args);
   /* Print the type of warning, only if this is not a sub message
      (in which case the prefix is null).  */
-  if (! (flags & silent) && prefix)
+  if (! (flags & silent) && sever != severity_disabled)
     warnings_print_categories (flags, stderr);
 
   {
@@ -317,13 +337,9 @@ complains (const location *loc, warnings flags, const char *message,
 
   if (severity_warning <= s)
     {
-      const char* prefix =
-        s == severity_fatal ? _("fatal error")
-        : s == severity_error ? _("error")
-        : _("warning");
       if (severity_error <= s && ! complaint_status)
         complaint_status = status_warning_as_error;
-      error_message (loc, flags, prefix, message, args);
+      error_message (loc, flags, s, message, args);
     }
 
   if (flags & fatal)
