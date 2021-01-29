@@ -104,6 +104,23 @@ flush (FILE *out)
   fflush (out);
 }
 
+bool
+is_styled (FILE *out)
+{
+  if (out != stderr)
+    return false;
+  if (color_debug)
+    return true;
+#if HAVE_LIBTEXTSTYLE
+  return (color_mode == color_yes
+          || color_mode == color_html
+          || (color_mode == color_tty && isatty (STDERR_FILENO)));
+#else
+  return false;
+#endif
+}
+
+
 /*------------------------.
 | --warnings's handling.  |
 `------------------------*/
@@ -288,9 +305,7 @@ void
 complain_init_color (void)
 {
 #if HAVE_LIBTEXTSTYLE
-  if (color_mode == color_yes
-      || color_mode == color_html
-      || (color_mode == color_tty && isatty (STDERR_FILENO)))
+  if (is_styled (stderr))
     {
       style_file_prepare ("BISON_STYLE", "BISON_STYLEDIR", pkgdatadir (),
                           "bison-default.css");
