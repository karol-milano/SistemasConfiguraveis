@@ -124,7 +124,7 @@ warn_at_indent (location loc, unsigned *indent,
     return;
   set_warning_issued ();
   indent_ptr = indent;
-  ERROR_MESSAGE (&loc, _("warning"), message);
+  ERROR_MESSAGE (&loc, *indent ? NULL : _("warning"), message);
 }
 
 void
@@ -144,7 +144,7 @@ warn (const char *message, ...)
 void
 complain_at (location loc, const char *message, ...)
 {
-  ERROR_MESSAGE (&loc, NULL, message);
+  ERROR_MESSAGE (&loc, _("error"), message);
   complaint_issued = true;
 }
 
@@ -153,14 +153,14 @@ complain_at_indent (location loc, unsigned *indent,
                     const char *message, ...)
 {
   indent_ptr = indent;
-  ERROR_MESSAGE (&loc, NULL, message);
+  ERROR_MESSAGE (&loc, *indent ? NULL : _("error"), message);
   complaint_issued = true;
 }
 
 void
 complain (const char *message, ...)
 {
-  ERROR_MESSAGE (NULL, NULL, message);
+  ERROR_MESSAGE (NULL, _("error"), message);
   complaint_issued = true;
 }
 
