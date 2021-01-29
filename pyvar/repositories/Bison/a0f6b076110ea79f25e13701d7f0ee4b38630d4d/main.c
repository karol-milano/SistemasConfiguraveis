@@ -22,10 +22,10 @@
 #include <stdio.h>
 #include "system.h"
 #include "machine.h"	/* for MAXSHORT */
+#include "files.h"
+#include "complain.h"
 
-extern	int lineno;
 extern	int verboseflag;
-extern	char *infile;
 
 /* Nonzero means failure has been detected; don't write a parser file.  */
 int failure;
@@ -34,14 +34,6 @@ int failure;
 char *program_name;
 
 char *printable_version PARAMS((int));
-char *int_to_string PARAMS((int));
-void fatal PARAMS((char *));
-void fatals PARAMS((char *, char *));
-void warn PARAMS((char *));
-void warni PARAMS((char *, int));
-void warns PARAMS((char *, char *));
-void warnss PARAMS((char *, char *, char *));
-void warnsss PARAMS((char *, char *, char *, char *));
 void toomany PARAMS((char *));
 void berror PARAMS((char *));
 
@@ -57,7 +49,6 @@ extern void initialize_conflicts PARAMS((void));
 extern void verbose PARAMS((void));
 extern void terse PARAMS((void));
 extern void output PARAMS((void));
-extern void done PARAMS((int));
 
 
 /* VMS complained about using `int'.  */
@@ -70,17 +61,20 @@ main (int argc, char *argv[])
   bindtextdomain (PACKAGE, LOCALEDIR);
   textdomain (PACKAGE);
 
-  failure = 0;
   lineno = 0;
   getargs(argc, argv);
+
+  /* Be ready to clean up if we exit.*/
+  atexit (done);
+
   openfiles();
 
   /* read the input.  Copy some parts of it to fguard, faction, ftable and fattrs.
      In file reader.c.
      The other parts are recorded in the grammar; see gram.h.  */
-  reader();
-  if (failure)
-	done(failure);
+  reader ();
+  if (complain_message_count)
+    exit (1);
 
   /* find useless nonterminals and productions and reduce the grammar.  In
      file reduce.c */
@@ -110,8 +104,9 @@ main (int argc, char *argv[])
 
   /* output the tables and the parser to ftable.  In file output. */
   output();
-  done(failure);
-  return failure;
+  done ();
+
+  exit (complain_message_count ? 1 : 0);
 }
 
 /* functions to report errors which prevent a parser from being generated */
@@ -134,137 +129,11 @@ printable_version (int c)
   return buf;
 }
 
-/* Generate a string from the integer I.
-   Return a ptr to internal memory containing the string.  */
-
-char *
-int_to_string (int i)
-{
-  static char buf[20];
-  sprintf(buf, "%d", i);
-  return buf;
-}
-
-/* Display filename and lino if available.  */
-
-static void
-banner (void)
-{
-  if (infile == 0)
-    fprintf(stderr, "%s: ", program_name);
-  else
-    fprintf(stderr, "%s:%d: ", infile, lineno);
-}
-
-static void
-fatal_banner (void)
-{
-  banner ();
-  fputs (_("fatal error: "), stderr);
-}
-
-/* Print the message S for a fatal error.  */
-
-void
-fatal (char *s)
-{
-  fatal_banner ();
-  fputs (s, stderr);
-  fputc ('\n', stderr);
-  done (1);
-}
-
-
-/* Print a message for a fatal error.  Use FMT to construct the message
-   and incorporate string X1.  */
-
-void
-fatals (char *fmt, char *x1)
-{
-  fatal_banner ();
-  fprintf (stderr, fmt, x1);
-  fputc ('\n', stderr);
-  done (1);
-}
-
-static void
-warn_banner (void)
-{
-  banner ();
-  failure = 1;
-}
-
-/* Print a warning message S.  */
-
-void
-warn (char *s)
-{
-  warn_banner ();
-  fputs (s, stderr);
-  fputc ('\n', stderr);
-}
-
-/* Print a warning message containing the string for the integer X1.
-   The message is given by the format FMT.  */
-
-void
-warni (char *fmt, int x1)
-{
-  warn_banner ();
-  fprintf (stderr, fmt, x1);
-  fputc ('\n', stderr);
-}
-
-/* Print a warning message containing the string X1.
-   The message is given by the format FMT.  */
-
-void
-warns (char *fmt, char *x1)
-{
-  warn_banner ();
-  fprintf (stderr, fmt, x1);
-  fputc ('\n', stderr);
-}
-
-/* Print a warning message containing the two strings X1 and X2.
-	The message is given by the format FMT.  */
-
-void
-warnss (char *fmt, char *x1, char *x2)
-{
-  warn_banner ();
-  fprintf (stderr, fmt, x1, x2);
-  fputc ('\n', stderr);
-}
-
-/* Print a warning message containing the 3 strings X1, X2, X3.
-   The message is given by the format FMT.  */
-
-void
-warnsss (char *fmt, char *x1, char *x2, char *x3)
-{
-  warn_banner ();
-  fprintf (stderr, fmt, x1, x2, x3);
-  fputc ('\n', stderr);
-}
-
-/* Print a message for the fatal occurence of more than MAXSHORT
-   instances of whatever is denoted by the string S.  */
-
-void
-toomany (char *s)
-{
-  fatal_banner ();
-  fprintf (stderr, _("too many %s (max %d)"), s, MAXSHORT);
-  fputc ('\n', stderr);
-  done (1);
-}
-
 /* Abort for an internal error denoted by string S.  */
 
 void
 berror (char *s)
 {
-  fprintf(stderr, _("%s: internal error: %s\n"), program_name, s);
+  fprintf (stderr, _("%s: internal error: %s\n"), program_name, s);
   abort();
 }
