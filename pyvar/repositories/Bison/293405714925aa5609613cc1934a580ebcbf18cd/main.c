@@ -45,6 +45,10 @@ main(argc, argv)
      char *argv[];
 {
   program_name = argv[0];
+  setlocale (LC_ALL, "");
+  bindtextdomain (PACKAGE, LOCALEDIR);
+  textdomain (PACKAGE);
+
   failure = 0;
   lineno = 0;
   getargs(argc, argv);
@@ -130,9 +134,9 @@ fatal(s)
   extern char *infile;
 
   if (infile == 0)
-    fprintf(stderr, "fatal error: %s\n", s);
+    fprintf(stderr, _("fatal error: %s\n"), s);
   else
-    fprintf(stderr, "\"%s\", line %d: %s\n", infile, lineno, s);
+    fprintf(stderr, _("\"%s\", line %d: %s\n"), infile, lineno, s);
   done(1);
 }
 
@@ -158,9 +162,9 @@ warn(s)
   extern char *infile;
 
   if (infile == 0)
-    fprintf(stderr, "error: %s\n", s);
+    fprintf(stderr, _("error: %s\n"), s);
   else
-    fprintf(stderr, "(\"%s\", line %d) error: %s\n", 
+    fprintf(stderr, _("(\"%s\", line %d) error: %s\n"),
 	    infile, lineno, s);
 
   failure = 1;
@@ -223,7 +227,7 @@ toomany(s)
      char *s;
 {
   char buffer[200];
-  sprintf(buffer, "limit of %d exceeded, too many %s", MAXSHORT, s);
+  sprintf(buffer, _("limit of %d exceeded, too many %s"), MAXSHORT, s);
   fatal(buffer);
 }
 
@@ -233,6 +237,6 @@ void
 berror(s)
      char *s;
 {
-  fprintf(stderr, "internal error, %s\n", s);
+  fprintf(stderr, _("internal error, %s\n"), s);
   abort();
 }
