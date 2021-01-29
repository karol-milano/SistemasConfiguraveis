@@ -144,16 +144,24 @@ int_to_string (int i)
   return buf;
 }
 
+static void
+fatal_banner (void)
+{
+  if (infile == 0)
+    fprintf(stderr, _("%s: fatal error: "), program_name);
+  else
+    fprintf(stderr, _("%s:%d: fatal error: "), infile, lineno);
+}
+
 /* Print the message S for a fatal error.  */
 
 void
 fatal (char *s)
 {
-  if (infile == 0)
-    fprintf(stderr, _("%s: fatal error: %s\n"), program_name, s);
-  else
-    fprintf(stderr, _("%s:%d: fatal error: %s\n"), infile, lineno, s);
-  done(1);
+  fatal_banner ();
+  fputs (s, stderr);
+  fputc ('\n', stderr);
+  done (1);
 }
 
 
@@ -163,9 +171,20 @@ fatal (char *s)
 void
 fatals (char *fmt, char *x1)
 {
-  char buffer[200];
-  sprintf(buffer, fmt, x1);
-  fatal(buffer);
+  fatal_banner ();
+  fprintf (stderr, fmt, x1);
+  fputc ('\n', stderr);
+  done (1);
+}
+
+static void
+warn_banner (void)
+{
+  if (infile == 0)
+    fprintf(stderr, _("%s: "), program_name);
+  else
+    fprintf(stderr, _("%s:%d: "), infile, lineno);
+  failure = 1;
 }
 
 /* Print a warning message S.  */
@@ -173,13 +192,9 @@ fatals (char *fmt, char *x1)
 void
 warn (char *s)
 {
-  if (infile == 0)
-    fprintf(stderr, _("%s: %s\n"), program_name, s);
-  else
-    fprintf(stderr, _("%s:%d: %s\n"),
-	    infile, lineno, s);
-
-  failure = 1;
+  warn_banner ();
+  fputs (s, stderr);
+  fputc ('\n', stderr);
 }
 
 /* Print a warning message containing the string for the integer X1.
@@ -188,9 +203,9 @@ warn (char *s)
 void
 warni (char *fmt, int x1)
 {
-  char buffer[200];
-  sprintf(buffer, fmt, x1);
-  warn(buffer);
+  warn_banner ();
+  fprintf (stderr, fmt, x1);
+  fputc ('\n', stderr);
 }
 
 /* Print a warning message containing the string X1.
@@ -199,9 +214,9 @@ warni (char *fmt, int x1)
 void
 warns (char *fmt, char *x1)
 {
-  char buffer[200];
-  sprintf(buffer, fmt, x1);
-  warn(buffer);
+  warn_banner ();
+  fprintf (stderr, fmt, x1);
+  fputc ('\n', stderr);
 }
 
 /* Print a warning message containing the two strings X1 and X2.
@@ -210,9 +225,9 @@ warns (char *fmt, char *x1)
 void
 warnss (char *fmt, char *x1, char *x2)
 {
-  char buffer[200];
-  sprintf(buffer, fmt, x1, x2);
-  warn(buffer);
+  warn_banner ();
+  fprintf (stderr, fmt, x1, x2);
+  fputc ('\n', stderr);
 }
 
 /* Print a warning message containing the 3 strings X1, X2, X3.
@@ -221,9 +236,9 @@ warnss (char *fmt, char *x1, char *x2)
 void
 warnsss (char *fmt, char *x1, char *x2, char *x3)
 {
-  char buffer[200];
-  sprintf(buffer, fmt, x1, x2, x3);
-  warn(buffer);
+  warn_banner ();
+  fprintf (stderr, fmt, x1, x2, x3);
+  fputc ('\n', stderr);
 }
 
 /* Print a message for the fatal occurence of more than MAXSHORT
@@ -232,9 +247,10 @@ warnsss (char *fmt, char *x1, char *x2, char *x3)
 void
 toomany (char *s)
 {
-  char buffer[200];
-  sprintf(buffer, _("too many %s (max %d)"), s, MAXSHORT);
-  fatal(buffer);
+  fatal_banner ();
+  fprintf (stderr, _("too many %s (max %d)"), s, MAXSHORT);
+  fputc ('\n', stderr);
+  done (1);
 }
 
 /* Abort for an internal error denoted by string S.  */
