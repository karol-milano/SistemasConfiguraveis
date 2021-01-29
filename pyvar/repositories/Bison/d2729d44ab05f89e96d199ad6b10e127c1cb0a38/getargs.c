@@ -34,10 +34,13 @@ char *spec_name_prefix; /* for -p.  */
 char *spec_file_prefix; /* for -b. */
 extern int fixed_outfiles;/* for -y */
   
+void usage PARAMS((FILE *));
+void getargs PARAMS((int, char *[]));
+
 extern char *program_name;
 extern char *version_string;
 
-extern void warns();	/* main.c */
+extern void warns PARAMS((char *, char *));	/* main.c */
 
 struct option longopts[] =
 {
@@ -60,8 +63,7 @@ struct option longopts[] =
 };
 
 void
-usage (stream)
-     FILE *stream;
+usage (FILE *stream)
 {
   fprintf (stream, _("\
 Usage: %s [-dhklntvyV] [-b file-prefix] [-o outfile] [-p name-prefix]\n\
@@ -75,9 +77,7 @@ Report bugs to bug-bison@gnu.org\n"),
 }
 
 void
-getargs(argc, argv)
-     int argc;
-     char *argv[];
+getargs (int argc, char *argv[])
 {
   register int c;
 
