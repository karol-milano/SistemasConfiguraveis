@@ -424,7 +424,6 @@ warnings_print_categories (warnings warn_flags, FILE *out)
  *
  * \param loc     the location, defaulting to the current file,
  *                or the program name.
- * \param indent  optional indentation for the error message.
  * \param flags   the category for this message.
  * \param sever   to decide the prefix to put before the message
  *                (e.g., "warning").
@@ -436,51 +435,46 @@ warnings_print_categories (warnings warn_flags, FILE *out)
  */
 static
 void
-error_message (const location *loc, int *indent, warnings flags,
+error_message (const location *loc, warnings flags,
                severity sever, const char *message, va_list args)
 {
-  int pos = 0;
+  const char* style = flags & note ? "note" : severity_style (sever);
 
   if (loc)
-    pos += location_print (*loc, stderr);
+    location_print (*loc, stderr);
   else
-    pos += fprintf (stderr, "%s", grammar_file ? grammar_file : program_name);
-  pos += fprintf (stderr, ": ");
+    fprintf (stderr, "%s", grammar_file ? grammar_file : program_name);
+  fprintf (stderr, ": ");
 
-  if (indent)
+  if (sever != severity_disabled)
     {
-      if (*indent)
-        sever = severity_disabled;
-      if (!*indent)
-        *indent = pos;
-      else if (*indent > pos)
-        fprintf (stderr, "%*s", *indent - pos, "");
+      begin_use_class (style, stderr);
+      fprintf (stderr, "%s:", flags & note ? _("note") : severity_prefix (sever));
+      end_use_class (style, stderr);
+      fputc (' ', stderr);
     }
 
-  severity_print (sever, stderr);
   vfprintf (stderr, message, args);
   /* Print the type of warning, only if this is not a sub message
      (in which case the prefix is null).  */
   if (! (flags & silent) && sever != severity_disabled)
     warnings_print_categories (flags, stderr);
 
-  {
-    size_t l = strlen (message);
-    if (l < 2 || message[l - 2] != ':' || message[l - 1] != ' ')
-      {
-        putc ('\n', stderr);
-        flush (stderr);
-        if (loc && !(flags & no_caret))
-          location_caret (*loc, severity_style (sever), stderr);
-      }
-  }
+  size_t l = strlen (message);
+  if (l < 2 || message[l - 2] != ':' || message[l - 1] != ' ')
+    {
+      putc ('\n', stderr);
+      flush (stderr);
+      if (loc && !(flags & no_caret))
+        location_caret (*loc, style, stderr);
+    }
   flush (stderr);
 }
 
 /** Raise a complaint (fatal error, error or just warning).  */
 
 static void
-complains (const location *loc, int *indent, warnings flags,
+complains (const location *loc, warnings flags,
            const char *message, va_list args)
 {
   if ((flags & complaint) && complaint_status < status_complaint)
@@ -491,7 +485,7 @@ complains (const location *loc, int *indent, warnings flags,
     {
       if (severity_error <= s && ! complaint_status)
         complaint_status = status_warning_as_error;
-      error_message (loc, indent, flags, s, message, args);
+      error_message (loc, flags, s, message, args);
     }
 
   if (flags & fatal)
@@ -503,41 +497,39 @@ complain (location const *loc, warnings flags, const char *message, ...)
 {
   va_list args;
   va_start (args, message);
-  complains (loc, NULL, flags, message, args);
+  complains (loc, flags, message, args);
   va_end (args);
 }
 
 void
-complain_indent (location const *loc, warnings flags, int *indent,
-                 const char *message, ...)
+subcomplain (location const *loc, warnings flags, const char *message, ...)
 {
   va_list args;
   va_start (args, message);
-  complains (loc, indent, flags, message, args);
+  complains (loc, flags | note | silent, message, args);
   va_end (args);
 }
 
 void
-complain_args (location const *loc, warnings w, int *indent,
+complain_args (location const *loc, warnings w,
                int argc, char *argv[])
 {
   switch (argc)
   {
   case 1:
-    complain_indent (loc, w, indent, "%s", _(argv[0]));
+    complain (loc, w, "%s", _(argv[0]));
     break;
   case 2:
-    complain_indent (loc, w, indent, _(argv[0]), argv[1]);
+    complain (loc, w, _(argv[0]), argv[1]);
     break;
   case 3:
-    complain_indent (loc, w, indent, _(argv[0]), argv[1], argv[2]);
+    complain (loc, w, _(argv[0]), argv[1], argv[2]);
     break;
   case 4:
-    complain_indent (loc, w, indent, _(argv[0]), argv[1], argv[2], argv[3]);
+    complain (loc, w, _(argv[0]), argv[1], argv[2], argv[3]);
     break;
   case 5:
-    complain_indent (loc, w, indent, _(argv[0]), argv[1], argv[2], argv[3],
-                     argv[4]);
+    complain (loc, w, _(argv[0]), argv[1], argv[2], argv[3], argv[4]);
     break;
   default:
     complain (loc, fatal, "too many arguments for complains");
@@ -571,13 +563,11 @@ void
 duplicate_directive (char const *directive,
                      location first, location second)
 {
-  int i = 0;
   if (feature_flag & feature_caret)
-    complain_indent (&second, Wother, &i, _("duplicate directive"));
+    complain (&second, Wother, _("duplicate directive"));
   else
-    complain_indent (&second, Wother, &i, _("duplicate directive: %s"), quote (directive));
-  i += SUB_INDENT;
-  complain_indent (&first, Wother, &i, _("previous declaration"));
+    complain (&second, Wother, _("duplicate directive: %s"), quote (directive));
+  subcomplain (&first, Wother, _("previous declaration"));
   fixits_register (&second, "");
 }
 
@@ -585,12 +575,8 @@ void
 duplicate_rule_directive (char const *directive,
                           location first, location second)
 {
-  int i = 0;
-  complain_indent (&second, complaint, &i,
-                   _("only one %s allowed per rule"), directive);
-  i += SUB_INDENT;
-  complain_indent (&first, complaint, &i,
-                   _("previous declaration"));
+  complain (&second, complaint, _("only one %s allowed per rule"), directive);
+  subcomplain (&first, complaint, _("previous declaration"));
   fixits_register (&second, "");
 }
 
