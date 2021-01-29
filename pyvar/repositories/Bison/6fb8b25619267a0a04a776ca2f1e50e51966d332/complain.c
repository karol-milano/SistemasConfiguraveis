@@ -29,7 +29,7 @@
 #include "files.h"
 #include "getargs.h"
 
-int warnings_flag = Wconflicts_sr | Wconflicts_rr | Wother;
+warnings warnings_flag = Wconflicts_sr | Wconflicts_rr | Wother;
 
 bool complaint_issued;
 static unsigned *indent_ptr = 0;
@@ -40,6 +40,7 @@ static unsigned *indent_ptr = 0;
  *
  * \param loc     the location, defaulting to the current file,
  *                or the program name.
+ * \param flags   the category for this message.
  * \param prefix  put before the message (e.g., "warning").
  * \param message the error message, a printf format string.  Iff it
  *                ends with ": ", then no trailing newline is printed,
@@ -49,10 +50,10 @@ static unsigned *indent_ptr = 0;
  */
 static
 void
-error_message (location *loc,
-               const char *prefix,
+error_message (const location *loc, warnings flags, const char *prefix,
                const char *message, va_list args)
 {
+  (void) flags;
   unsigned pos = 0;
 
   if (loc)
@@ -84,133 +85,86 @@ error_message (location *loc,
   }
 }
 
-/** Wrap error_message() with varargs handling. */
-#define ERROR_MESSAGE(Loc, Prefix, Message)     \
-{                                               \
-  va_list args;                                 \
-  va_start (args, Message);                     \
-  error_message (Loc, Prefix, Message, args);   \
-  va_end (args);                                \
-}
-
-
-/*--------------------------------.
-| Report a warning, and proceed.  |
-`--------------------------------*/
+/** Raise a complaint. That can be a fatal error, a complaint or just a
+    warning.  */
 
-void
-set_warning_issued (void)
+static inline void
+complains (const location *loc, warnings flags, const char *message,
+           va_list args)
 {
-  static bool warning_issued = false;
-  if (!warning_issued && (warnings_flag & Werror))
+  if (flags & complaint)
     {
-      fprintf (stderr, "%s: warnings being treated as errors\n", program_name);
+      error_message (loc, complaint, NULL, message, args);
       complaint_issued = true;
     }
-  warning_issued = true;
-}
-
-void
-warn_at (location loc, const char *message, ...)
-{
-  if (!(warnings_flag & Wother))
-    return;
-  set_warning_issued ();
-  ERROR_MESSAGE (&loc, _("warning"), message);
-}
-
-void
-warn_at_indent (location loc, unsigned *indent,
-                const char *message, ...)
-{
-  if (!(warnings_flag & Wother))
-    return;
-  set_warning_issued ();
-  indent_ptr = indent;
-  ERROR_MESSAGE (&loc, _("warning"), message);
+  else if (flags & fatal)
+    {
+      error_message (loc, fatal, _("fatal error"), message, args);
+      exit (EXIT_FAILURE);
+    }
+  else if (flags & Wyacc)
+    {
+      if (yacc_flag)
+        {
+          error_message (loc, flags, NULL, message, args);
+          complaint_issued = true;
+        }
+      else if (warnings_flag & Wyacc)
+        {
+          set_warning_issued ();
+          error_message (loc, flags, _("warning"), message, args);
+        }
+    }
+  else
+    {
+      if (! (warnings_flag & flags))
+        return;
+      set_warning_issued ();
+      error_message (loc, flags, _("warning"), message, args);
+    }
 }
 
 void
-warn (const char *message, ...)
+complain (warnings flags, const char *message, ...)
 {
-  if (!(warnings_flag & Wother))
-    return;
-  set_warning_issued ();
-  ERROR_MESSAGE (NULL, _("warning"), message);
+  va_list args;
+  va_start (args, message);
+  complains (NULL, flags, message, args);
+  va_end (args);
 }
 
-
-/*-----------------------------------------------------------.
-| An error has occurred, but we can proceed, and die later.  |
-`-----------------------------------------------------------*/
-
 void
-complain_at (location loc, const char *message, ...)
+complain_at (location loc, warnings flags, const char *message, ...)
 {
-  ERROR_MESSAGE (&loc, NULL, message);
-  complaint_issued = true;
+  va_list args;
+  va_start (args, message);
+  complains (&loc, flags, message, args);
+  va_end (args);
 }
 
-void
-complain_at_indent (location loc, unsigned *indent,
-                    const char *message, ...)
+void complain_at_indent (location loc, warnings flags, unsigned *indent,
+                         const char *message, ...)
 {
   indent_ptr = indent;
-  ERROR_MESSAGE (&loc, NULL, message);
-  complaint_issued = true;
-}
 
-void
-complain (const char *message, ...)
-{
-  ERROR_MESSAGE (NULL, NULL, message);
-  complaint_issued = true;
+  va_list args;
+  va_start (args, message);
+  complains (&loc, flags, message, args);
+  va_end (args);
 }
 
-
-/*--------------------------------------------------------------.
-| An incompatibility with POSIX Yacc: mapped either to warn* or |
-| complain* depending on yacc_flag.                             |
-`--------------------------------------------------------------*/
+/*--------------------------------.
+| Report a warning, and proceed.  |
+`--------------------------------*/
 
 void
-yacc_at (location loc, const char *message, ...)
+set_warning_issued (void)
 {
-  if (yacc_flag)
+  static bool warning_issued = false;
+  if (!warning_issued && (warnings_flag & Werror))
     {
-      ERROR_MESSAGE (&loc, NULL, message);
+      fprintf (stderr, "%s: warnings being treated as errors\n", program_name);
       complaint_issued = true;
     }
-  else if (warnings_flag & Wyacc)
-    {
-      set_warning_issued ();
-      ERROR_MESSAGE (&loc, _("warning"), message);
-    }
-}
-
-void
-midrule_value_at (location loc, const char *message, ...)
-{
-  if (!(warnings_flag & Wmidrule_values))
-    return;
-  set_warning_issued ();
-  ERROR_MESSAGE (&loc, _("warning"), message);
-}
-
-/*-------------------------------------------------.
-| A severe error has occurred, we cannot proceed.  |
-`-------------------------------------------------*/
-
-void
-fatal_at (location loc, const char *message, ...)
-{
-  ERROR_MESSAGE (&loc, _("fatal error"), message);
-  exit (EXIT_FAILURE);
-}
-
-void
-fatal (const char *message, ...)
-{
-  ERROR_MESSAGE (NULL, _("fatal error"), message);
-  exit (EXIT_FAILURE);
+  warning_issued = true;
 }
