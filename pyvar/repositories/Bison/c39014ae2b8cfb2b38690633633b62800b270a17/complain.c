@@ -109,6 +109,8 @@ set_warning_issued (void)
 void
 warn_at (location loc, const char *message, ...)
 {
+  if (!(warnings_flag & warnings_other))
+    return;
   set_warning_issued ();
   ERROR_MESSAGE (&loc, _("warning"), message);
 }
@@ -117,6 +119,8 @@ void
 warn_at_indent (location loc, unsigned *indent,
                 const char *message, ...)
 {
+  if (!(warnings_flag & warnings_other))
+    return;
   set_warning_issued ();
   indent_ptr = indent;
   ERROR_MESSAGE (&loc, _("warning"), message);
@@ -125,6 +129,8 @@ warn_at_indent (location loc, unsigned *indent,
 void
 warn (const char *message, ...)
 {
+  if (!(warnings_flag & warnings_other))
+    return;
   set_warning_issued ();
   ERROR_MESSAGE (NULL, _("warning"), message);
 }
@@ -178,6 +184,14 @@ yacc_at (location loc, const char *message, ...)
     }
 }
 
+void
+midrule_value_at (location loc, const char *message, ...)
+{
+  if (!(warnings_flag & warnings_midrule_values))
+    return;
+  set_warning_issued ();
+  ERROR_MESSAGE (&loc, _("warning"), message);
+}
 
 /*-------------------------------------------------.
 | A severe error has occurred, we cannot proceed.  |
