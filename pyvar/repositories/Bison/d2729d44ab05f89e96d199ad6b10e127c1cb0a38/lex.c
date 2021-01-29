@@ -26,7 +26,6 @@ the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
    symval is set to a pointer to the entry found.  */
 
 #include <stdio.h>
-#include <ctype.h>
 #include "system.h"
 #include "files.h"
 #include "getopt.h"		/* for optarg */
@@ -50,19 +49,27 @@ extern char *spec_file_prefix;	/* for -b */
 extern int lineno;
 extern int translations;
 
-int parse_percent_token();
+void init_lex PARAMS((void));
+char *grow_token_buffer PARAMS((char *));
+int skip_white_space PARAMS((void));
+int safegetc PARAMS((FILE *));
+int literalchar PARAMS((char **, int *, char));
+void unlex PARAMS((int));
+int lex PARAMS((void));
+int parse_percent_token PARAMS((void));
 
 /* functions from main.c */
-extern char *printable_version();
-extern void fatal();
-extern void warni();
-extern void warn();
+extern char *printable_version PARAMS((int));
+extern void fatal PARAMS((char *));
+extern void warn PARAMS((char *));
+extern void warni PARAMS((char *, int));
+extern void warns PARAMS((char *, char *));
 
 /* Buffer for storing the current token.  */
 char *token_buffer;
 
 /* Allocated size of token_buffer, not including space for terminator.  */
-static int maxtoken;
+int maxtoken;
 
 bucket *symval;
 int numval;
@@ -72,7 +79,7 @@ static bucket *unlexed_symval;	/* by the next call to lex */
 
 
 void
-init_lex()
+init_lex (void)
 {
   maxtoken = 100;
   token_buffer = NEW2 (maxtoken + 1, char);
@@ -80,9 +87,8 @@ init_lex()
 }
 
 
-static char *
-grow_token_buffer (p)
-     char *p;
+char *
+grow_token_buffer (char *p)
 {
   int offset = p - token_buffer;
   maxtoken *= 2;
@@ -92,7 +98,7 @@ grow_token_buffer (p)
 
 
 int
-skip_white_space()
+skip_white_space (void)
 {
   register int c;
   register int inside;
@@ -162,8 +168,7 @@ skip_white_space()
 
 /* do a getc, but give error message if EOF encountered */
 int
-safegetc(f)
-  FILE *f;
+safegetc (FILE *f)
 {
   register int c = getc(f);
   if (c == EOF)
@@ -178,10 +183,7 @@ safegetc(f)
 	report error for \n
 */
 int
-literalchar(pp, pcode, term)
-  char **pp;
-  int *pcode;
-  char term;
+literalchar (char **pp, int *pcode, char term)
 {
   register int c;
   register char *p;
@@ -211,7 +213,7 @@ literalchar(pp, pcode, term)
       else if (c == 'r')  code = '\r';
       else if (c == 'f')  code = '\f';
       else if (c == 'b')  code = '\b';
-      else if (c == 'v')  code = 013;
+      else if (c == 'v')  code = '\013';
       else if (c == '\\')  code = '\\';
       else if (c == '\'')  code = '\'';
       else if (c == '\"')  code = '\"';
@@ -293,8 +295,7 @@ literalchar(pp, pcode, term)
 
 
 void
-unlex(token)
-     int token;
+unlex (int token)
 {
   unlexed = token;
   unlexed_symval = symval;
@@ -302,7 +303,7 @@ unlex(token)
 
 
 int
-lex()
+lex (void)
 {
   register int c;
   char *p;
@@ -542,8 +543,8 @@ struct percent_table_struct {
   /* These would be acceptable, but they do not affect processing */
   {"verbose", &verboseflag, NOOP}, /* -v */
   {"debug", &debugflag, NOOP},	/* -t */
-  /*	{"help", <print usage stmt>, NOOP},	/* -h */
-  /*	{"version", <print version number> ,  NOOP},	/* -V */
+  /*	{"help", <print usage stmt>, NOOP},*/	/* -h */
+  /*	{"version", <print version number> ,  NOOP},*/	/* -V */
 #endif
 
   {NULL, NULL, ILLEGAL}
@@ -553,7 +554,7 @@ struct percent_table_struct {
    Assumes the % has already been read and discarded.  */
 
 int
-parse_percent_token ()
+parse_percent_token (void)
 {
   register int c;
   register char *p;
