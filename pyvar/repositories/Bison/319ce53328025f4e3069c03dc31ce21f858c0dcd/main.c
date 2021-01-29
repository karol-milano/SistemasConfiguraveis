@@ -135,7 +135,7 @@ fatal(s)
   extern char *infile;
 
   if (infile == 0)
-    fprintf(stderr, _("bison: fatal error: %s\n"), s);
+    fprintf(stderr, _("%s: fatal error: %s\n"), program_name, s);
   else
     fprintf(stderr, _("%s:%d: fatal error: %s\n"), infile, lineno, s);
   done(1);
@@ -163,7 +163,7 @@ warn(s)
   extern char *infile;
 
   if (infile == 0)
-    fprintf(stderr, _("bison: %s\n"), s);
+    fprintf(stderr, _("%s: %s\n"), program_name, s);
   else
     fprintf(stderr, _("%s:%d: %s\n"),
 	    infile, lineno, s);
@@ -238,6 +238,6 @@ void
 berror(s)
      char *s;
 {
-  fprintf(stderr, _("bison: internal error: %s\n"), s);
+  fprintf(stderr, _("%s: internal error: %s\n"), program_name, s);
   abort();
 }
