@@ -255,7 +255,7 @@ complain_init_color (void)
       || color_mode == color_html
       || (color_mode == color_tty && isatty (STDERR_FILENO)))
     {
-      style_file_prepare ("BISON_STYLE", NULL, pkgdatadir (),
+      style_file_prepare ("BISON_STYLE", "BISON_STYLEDIR", pkgdatadir (),
                           "bison-default.css");
       /* As a fallback, use the default in the current directory.  */
       struct stat statbuf;
