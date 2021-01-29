@@ -252,6 +252,7 @@ complain_init_color (void)
 {
 #if HAVE_LIBTEXTSTYLE
   if (color_mode == color_yes
+      || color_mode == color_html
       || (color_mode == color_tty && isatty (STDERR_FILENO)))
     {
       style_file_prepare ("BISON_DIAGNOSTICS_STYLE", NULL,
@@ -268,9 +269,25 @@ complain_init_color (void)
     style_file_name = NULL;
 #endif
 
+  /* Workaround clang's warning (starting at Clang 3.5) about the stub
+     code of html_styled_ostream_create:
+
+     | src/complain.c:274:7: error: code will never be executed [-Werror,-Wunreachable-code]
+     |     ? html_styled_ostream_create (file_ostream_create (stderr),
+     |       ^~~~~~~~~~~~~~~~~~~~~~~~~~ */
+#if defined __clang__
+# pragma clang diagnostic push
+# pragma clang diagnostic ignored "-Wunreachable-code"
+#endif
   errstream =
-    styled_ostream_create (STDERR_FILENO, "(stderr)", TTYCTL_AUTO,
-                           style_file_name);
+    color_mode == color_html
+    ? html_styled_ostream_create (file_ostream_create (stderr),
+                                  style_file_name)
+    : styled_ostream_create (STDERR_FILENO, "(stderr)", TTYCTL_AUTO,
+                             style_file_name);
+#if defined __clang__
+# pragma clang diagnostic pop
+#endif
 }
 
 void
