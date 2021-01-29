@@ -63,8 +63,6 @@ typedef enum
 /** For each warning type, its severity.  */
 static severity warnings_flag[warnings_size];
 
-static unsigned *indent_ptr = NULL;
-
 styled_ostream_t errstream = NULL;
 
 void
@@ -386,6 +384,7 @@ warnings_print_categories (warnings warn_flags, FILE *out)
  *
  * \param loc     the location, defaulting to the current file,
  *                or the program name.
+ * \param indent  optional indentation for the error message.
  * \param flags   the category for this message.
  * \param sever   to decide the prefix to put before the message
  *                (e.g., "warning").
@@ -397,8 +396,8 @@ warnings_print_categories (warnings warn_flags, FILE *out)
  */
 static
 void
-error_message (const location *loc, warnings flags, severity sever,
-               const char *message, va_list args)
+error_message (const location *loc, unsigned *indent, warnings flags,
+               severity sever, const char *message, va_list args)
 {
   unsigned pos = 0;
 
@@ -408,14 +407,14 @@ error_message (const location *loc, warnings flags, severity sever,
     pos += fprintf (stderr, "%s", current_file ? current_file : program_name);
   pos += fprintf (stderr, ": ");
 
-  if (indent_ptr)
+  if (indent)
     {
-      if (*indent_ptr)
+      if (*indent)
         sever = severity_disabled;
-      if (!*indent_ptr)
-        *indent_ptr = pos;
-      else if (*indent_ptr > pos)
-        fprintf (stderr, "%*s", *indent_ptr - pos, "");
+      if (!*indent)
+        *indent = pos;
+      else if (*indent > pos)
+        fprintf (stderr, "%*s", *indent - pos, "");
     }
 
   const char* style = severity_style (sever);
@@ -450,8 +449,8 @@ error_message (const location *loc, warnings flags, severity sever,
 /** Raise a complaint (fatal error, error or just warning).  */
 
 static void
-complains (const location *loc, warnings flags, const char *message,
-           va_list args)
+complains (const location *loc, unsigned *indent, warnings flags,
+           const char *message, va_list args)
 {
   severity s = warning_severity (flags);
   if ((flags & complaint) && complaint_status < status_complaint)
@@ -461,7 +460,7 @@ complains (const location *loc, warnings flags, const char *message,
     {
       if (severity_error <= s && ! complaint_status)
         complaint_status = status_warning_as_error;
-      error_message (loc, flags, s, message, args);
+      error_message (loc, indent, flags, s, message, args);
     }
 
   if (flags & fatal)
@@ -473,7 +472,7 @@ complain (location const *loc, warnings flags, const char *message, ...)
 {
   va_list args;
   va_start (args, message);
-  complains (loc, flags, message, args);
+  complains (loc, NULL, flags, message, args);
   va_end (args);
 }
 
@@ -482,11 +481,9 @@ complain_indent (location const *loc, warnings flags, unsigned *indent,
                  const char *message, ...)
 {
   va_list args;
-  indent_ptr = indent;
   va_start (args, message);
-  complains (loc, flags, message, args);
+  complains (loc, indent, flags, message, args);
   va_end (args);
-  indent_ptr = NULL;
 }
 
 void
