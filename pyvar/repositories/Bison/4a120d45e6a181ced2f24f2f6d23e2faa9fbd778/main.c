@@ -27,25 +27,28 @@
 
 extern	int verboseflag;
 
+#if 0                           /* XXX currently unused.  */
 /* Nonzero means failure has been detected; don't write a parser file.  */
-int failure;
+static int failure;
+#endif
 
 /* The name this program was run with, for messages.  */
 char *program_name;
 
-char *printable_version PARAMS((int));
-void toomany PARAMS((char *));
-void berror PARAMS((char *));
+extern char *printable_version PARAMS((int));
+extern void berror PARAMS((const char *));
 
 extern void getargs PARAMS((int, char *[]));
 extern void openfiles PARAMS((void));
 extern void reader PARAMS((void));
 extern void reduce_grammar PARAMS((void));
 extern void set_derives PARAMS((void));
+extern void free_derives PARAMS((void));
 extern void set_nullable PARAMS((void));
 extern void generate_states PARAMS((void));
 extern void lalr PARAMS((void));
 extern void initialize_conflicts PARAMS((void));
+extern void finalize_conflicts PARAMS((void));
 extern void verbose PARAMS((void));
 extern void terse PARAMS((void));
 extern void output PARAMS((void));
@@ -105,6 +108,9 @@ main (int argc, char *argv[])
   /* output the tables and the parser to ftable.  In file output. */
   output();
 
+  finalize_conflicts();
+  free_derives();
+
   exit (complain_message_count ? 1 : 0);
 }
 
@@ -131,7 +137,7 @@ printable_version (int c)
 /* Abort for an internal error denoted by string S.  */
 
 void
-berror (char *s)
+berror (const char *s)
 {
   fprintf (stderr, _("%s: internal error: %s\n"), program_name, s);
   abort();
