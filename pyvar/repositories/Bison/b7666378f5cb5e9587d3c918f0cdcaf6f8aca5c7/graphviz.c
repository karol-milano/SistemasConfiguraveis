@@ -40,11 +40,9 @@ void
 start_graph (FILE *fout)
 {
   fprintf (fout,
-           _("/*\n"
-             " * Generated by %s.\n"
-             " * Report bugs to <%s>.\n"
-             " * Home page: <%s>.\n"
-             " */\n"
+           _("// Generated by %s.\n"
+             "// Report bugs to <%s>.\n"
+             "// Home page: <%s>.\n"
              "\n"),
            PACKAGE_STRING,
            PACKAGE_BUGREPORT,