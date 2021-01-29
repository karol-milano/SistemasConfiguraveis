@@ -1,5 +1,5 @@
 /* Top level entry point of bison,
-   Copyright (C) 1984, 1986, 1989 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 1992, 1995 Free Software Foundation, Inc.
 
 This file is part of Bison, the GNU Compiler Compiler.
 
@@ -20,7 +20,7 @@ the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 
 #include <stdio.h>
 #include "system.h"
-#include "machine.h"	/* JF for MAXSHORT */
+#include "machine.h"	/* for MAXSHORT */
 
 extern	int lineno;
 extern	int verboseflag;
@@ -28,7 +28,7 @@ extern	int verboseflag;
 /* Nonzero means failure has been detected; don't write a parser file.  */
 int failure;
 
-/* The name this program was run with, for messages. */
+/* The name this program was run with, for messages.  */
 char *program_name;
 
 extern void getargs(), openfiles(), reader(), reduce_grammar();
@@ -38,10 +38,11 @@ extern void output(), done();
 
 
 /* VMS complained about using `int'.  */
+
 int
 main(argc, argv)
-int argc;
-char *argv[];
+     int argc;
+     char *argv[];
 {
   program_name = argv[0];
   failure = 0;
@@ -53,6 +54,8 @@ char *argv[];
      In file reader.c.
      The other parts are recorded in the grammar; see gram.h.  */
   reader();
+  if (failure)
+	done(failure);
 
   /* find useless nonterminals and productions and reduce the grammar.  In
      file reduce.c */
@@ -84,12 +87,45 @@ char *argv[];
   output();
   done(failure);
 }
-
+
 /* functions to report errors which prevent a parser from being generated */
 
+
+/* Return a string containing a printable version of C:
+   either C itself, or the corresponding \DDD code.  */
+
+char *
+printable_version(c)
+     char c;
+{
+  static char buf[10];
+  if (c < ' ' || c >= '\177')
+    sprintf(buf, "\\%o", c);
+  else
+    {
+      buf[0] = c;
+      buf[1] = '\0';
+    }
+  return buf;
+}
+
+/* Generate a string from the integer I.
+   Return a ptr to internal memory containing the string.  */
+
+char *
+int_to_string(i)
+     int i;
+{
+  static char buf[20];
+  sprintf(buf, "%d", i);
+  return buf;
+}
+
+/* Print the message S for a fatal error.  */
+
 void
 fatal(s)
-char *s;
+     char *s;
 {
   extern char *infile;
 
@@ -101,38 +137,101 @@ char *s;
 }
 
 
-/* JF changed to accept/deal with variable args.
-   DO NOT change this to use varargs.  It will appear to work
-   but will break on systems that don't have the necessary library
-   functions.  This is the ONLY safe way to write such a function.  */
-/*VARARGS1*/
+/* Print a message for a fatal error.  Use FMT to construct the message
+   and incorporate string X1.  */
 
 void
-fatals(fmt,x1,x2,x3,x4,x5,x6,x7,x8)
-char *fmt;
+fatals(fmt, x1)
+     char *fmt, *x1;
 {
   char buffer[200];
-
-  sprintf(buffer, fmt, x1,x2,x3,x4,x5,x6,x7,x8);
+  sprintf(buffer, fmt, x1);
   fatal(buffer);
 }
 
+/* Print a warning message S.  */
 
 void
-toomany(s)
-char *s;
+warn(s)
+     char *s;
+{
+  extern char *infile;
+
+  if (infile == 0)
+    fprintf(stderr, "error: %s\n", s);
+  else
+    fprintf(stderr, "(\"%s\", line %d) error: %s\n", 
+	    infile, lineno, s);
+
+  failure = 1;
+}
+
+/* Print a warning message containing the string for the integer X1.
+   The message is given by the format FMT.  */
+
+void
+warni(fmt, x1)
+     char *fmt;
+     int x1;
 {
   char buffer[200];
+  sprintf(buffer, fmt, x1);
+  warn(buffer);
+}
+
+/* Print a warning message containing the string X1.
+   The message is given by the format FMT.  */
+
+void
+warns(fmt, x1)
+     char *fmt, *x1;
+{
+  char buffer[200];
+  sprintf(buffer, fmt, x1);
+  warn(buffer);
+}
+
+/* Print a warning message containing the two strings X1 and X2.
+	The message is given by the format FMT.  */
+
+void
+warnss(fmt, x1, x2)
+     char *fmt, *x1, *x2;
+{
+  char buffer[200];
+  sprintf(buffer, fmt, x1, x2);
+  warn(buffer);
+}
+
+/* Print a warning message containing the 3 strings X1, X2, X3.
+   The message is given by the format FMT.  */
+
+void
+warnsss(fmt, x1, x2, x3)
+     char *fmt, *x1, *x2, *x3;
+{
+  char buffer[200];
+  sprintf(buffer, fmt, x1, x2, x3);
+  warn(buffer);
+}
+
+/* Print a message for the fatal occurence of more than MAXSHORT
+   instances of whatever is denoted by the string S.  */
 
-	/* JF new msg */
+void
+toomany(s)
+     char *s;
+{
+  char buffer[200];
   sprintf(buffer, "limit of %d exceeded, too many %s", MAXSHORT, s);
   fatal(buffer);
 }
 
+/* Abort for an internal error denoted by string S.  */
 
 void
 berror(s)
-char *s;
+     char *s;
 {
   fprintf(stderr, "internal error, %s\n", s);
   abort();
