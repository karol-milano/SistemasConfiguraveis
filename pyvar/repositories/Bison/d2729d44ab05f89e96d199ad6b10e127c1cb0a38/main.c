@@ -24,6 +24,7 @@ the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 
 extern	int lineno;
 extern	int verboseflag;
+extern	char *infile;
 
 /* Nonzero means failure has been detected; don't write a parser file.  */
 int failure;
@@ -31,18 +32,37 @@ int failure;
 /* The name this program was run with, for messages.  */
 char *program_name;
 
-extern void getargs(), openfiles(), reader(), reduce_grammar();
-extern void set_derives(), set_nullable(), generate_states();
-extern void lalr(), initialize_conflicts(), verbose(), terse();
-extern void output(), done();
+char *printable_version PARAMS((int));
+char *int_to_string PARAMS((int));
+void fatal PARAMS((char *));
+void fatals PARAMS((char *, char *));
+void warn PARAMS((char *));
+void warni PARAMS((char *, int));
+void warns PARAMS((char *, char *));
+void warnss PARAMS((char *, char *, char *));
+void warnsss PARAMS((char *, char *, char *, char *));
+void toomany PARAMS((char *));
+void berror PARAMS((char *));
+
+extern void getargs PARAMS((int, char *[]));
+extern void openfiles PARAMS((void));
+extern void reader PARAMS((void));
+extern void reduce_grammar PARAMS((void));
+extern void set_derives PARAMS((void));
+extern void set_nullable PARAMS((void));
+extern void generate_states PARAMS((void));
+extern void lalr PARAMS((void));
+extern void initialize_conflicts PARAMS((void));
+extern void verbose PARAMS((void));
+extern void terse PARAMS((void));
+extern void output PARAMS((void));
+extern void done PARAMS((int));
 
 
 /* VMS complained about using `int'.  */
 
 int
-main(argc, argv)
-     int argc;
-     char *argv[];
+main (int argc, char *argv[])
 {
   program_name = argv[0];
   setlocale (LC_ALL, "");
@@ -100,8 +120,7 @@ main(argc, argv)
    either C itself, or the corresponding \DDD code.  */
 
 char *
-printable_version(c)
-     int c;
+printable_version (int c)
 {
   static char buf[10];
   if (c < ' ' || c >= '\177')
@@ -118,8 +137,7 @@ printable_version(c)
    Return a ptr to internal memory containing the string.  */
 
 char *
-int_to_string(i)
-     int i;
+int_to_string (int i)
 {
   static char buf[20];
   sprintf(buf, "%d", i);
@@ -129,11 +147,8 @@ int_to_string(i)
 /* Print the message S for a fatal error.  */
 
 void
-fatal(s)
-     char *s;
+fatal (char *s)
 {
-  extern char *infile;
-
   if (infile == 0)
     fprintf(stderr, _("%s: fatal error: %s\n"), program_name, s);
   else
@@ -146,8 +161,7 @@ fatal(s)
    and incorporate string X1.  */
 
 void
-fatals(fmt, x1)
-     char *fmt, *x1;
+fatals (char *fmt, char *x1)
 {
   char buffer[200];
   sprintf(buffer, fmt, x1);
@@ -157,11 +171,8 @@ fatals(fmt, x1)
 /* Print a warning message S.  */
 
 void
-warn(s)
-     char *s;
+warn (char *s)
 {
-  extern char *infile;
-
   if (infile == 0)
     fprintf(stderr, _("%s: %s\n"), program_name, s);
   else
@@ -175,9 +186,7 @@ warn(s)
    The message is given by the format FMT.  */
 
 void
-warni(fmt, x1)
-     char *fmt;
-     int x1;
+warni (char *fmt, int x1)
 {
   char buffer[200];
   sprintf(buffer, fmt, x1);
@@ -188,8 +197,7 @@ warni(fmt, x1)
    The message is given by the format FMT.  */
 
 void
-warns(fmt, x1)
-     char *fmt, *x1;
+warns (char *fmt, char *x1)
 {
   char buffer[200];
   sprintf(buffer, fmt, x1);
@@ -200,8 +208,7 @@ warns(fmt, x1)
 	The message is given by the format FMT.  */
 
 void
-warnss(fmt, x1, x2)
-     char *fmt, *x1, *x2;
+warnss (char *fmt, char *x1, char *x2)
 {
   char buffer[200];
   sprintf(buffer, fmt, x1, x2);
@@ -212,8 +219,7 @@ warnss(fmt, x1, x2)
    The message is given by the format FMT.  */
 
 void
-warnsss(fmt, x1, x2, x3)
-     char *fmt, *x1, *x2, *x3;
+warnsss (char *fmt, char *x1, char *x2, char *x3)
 {
   char buffer[200];
   sprintf(buffer, fmt, x1, x2, x3);
@@ -224,8 +230,7 @@ warnsss(fmt, x1, x2, x3)
    instances of whatever is denoted by the string S.  */
 
 void
-toomany(s)
-     char *s;
+toomany (char *s)
 {
   char buffer[200];
   sprintf(buffer, _("too many %s (max %d)"), s, MAXSHORT);
@@ -235,8 +240,7 @@ toomany(s)
 /* Abort for an internal error denoted by string S.  */
 
 void
-berror(s)
-     char *s;
+berror (char *s)
 {
   fprintf(stderr, _("%s: internal error: %s\n"), program_name, s);
   abort();
