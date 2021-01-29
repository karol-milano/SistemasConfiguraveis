@@ -135,9 +135,9 @@ fatal(s)
   extern char *infile;
 
   if (infile == 0)
-    fprintf(stderr, _("fatal error: %s\n"), s);
+    fprintf(stderr, _("bison: fatal error: %s\n"), s);
   else
-    fprintf(stderr, _("\"%s\", line %d: %s\n"), infile, lineno, s);
+    fprintf(stderr, _("%s:%d: fatal error: %s\n"), infile, lineno, s);
   done(1);
 }
 
@@ -163,9 +163,9 @@ warn(s)
   extern char *infile;
 
   if (infile == 0)
-    fprintf(stderr, _("error: %s\n"), s);
+    fprintf(stderr, _("bison: %s\n"), s);
   else
-    fprintf(stderr, _("(\"%s\", line %d) error: %s\n"),
+    fprintf(stderr, _("%s:%d: %s\n"),
 	    infile, lineno, s);
 
   failure = 1;
@@ -228,7 +228,7 @@ toomany(s)
      char *s;
 {
   char buffer[200];
-  sprintf(buffer, _("limit of %d exceeded, too many %s"), MAXSHORT, s);
+  sprintf(buffer, _("too many %s (max %d)"), s, MAXSHORT);
   fatal(buffer);
 }
 
@@ -238,6 +238,6 @@ void
 berror(s)
      char *s;
 {
-  fprintf(stderr, _("internal error, %s\n"), s);
+  fprintf(stderr, _("bison: internal error: %s\n"), s);
   abort();
 }
