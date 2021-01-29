@@ -255,14 +255,13 @@ complain_init_color (void)
       || color_mode == color_html
       || (color_mode == color_tty && isatty (STDERR_FILENO)))
     {
-      style_file_prepare ("BISON_DIAGNOSTICS_STYLE", NULL,
-                          pkgdatadir (),
-                          "diagnostics.css");
+      style_file_prepare ("BISON_STYLE", NULL, pkgdatadir (),
+                          "bison-default.css");
       /* As a fallback, use the default in the current directory.  */
       struct stat statbuf;
       if ((style_file_name == NULL || stat (style_file_name, &statbuf) < 0)
-          && stat ("diagnostics.css", &statbuf) == 0)
-        style_file_name = "diagnostics.css";
+          && stat ("bison-default.css", &statbuf) == 0)
+        style_file_name = "bison-default.css";
     }
   else
     /* No styling.  */
