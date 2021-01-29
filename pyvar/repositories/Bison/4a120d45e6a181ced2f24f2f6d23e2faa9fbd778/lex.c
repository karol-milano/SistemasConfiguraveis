@@ -50,14 +50,15 @@ extern char *spec_file_prefix;	/* for -b */
 
 extern int translations;
 
-void init_lex PARAMS((void));
-char *grow_token_buffer PARAMS((char *));
-int skip_white_space PARAMS((void));
-int safegetc PARAMS((FILE *));
-int literalchar PARAMS((char **, int *, char));
-void unlex PARAMS((int));
-int lex PARAMS((void));
-int parse_percent_token PARAMS((void));
+extern void init_lex PARAMS((void));
+extern char *grow_token_buffer PARAMS((char *));
+extern int skip_white_space PARAMS((void));
+extern void unlex PARAMS((int));
+extern int lex PARAMS((void));
+extern int parse_percent_token PARAMS((void));
+
+static int safegetc PARAMS((FILE *));
+static int literalchar PARAMS((char **, int *, char));
 
 /* functions from main.c */
 extern char *printable_version PARAMS((int));
@@ -164,7 +165,7 @@ skip_white_space (void)
 }
 
 /* do a getc, but give error message if EOF encountered */
-int
+static int
 safegetc (FILE *f)
 {
   register int c = getc(f);
@@ -179,7 +180,7 @@ safegetc (FILE *f)
    return 1 unless the character is an unescaped `term' or \n
 	report error for \n
 */
-int
+static int
 literalchar (char **pp, int *pcode, char term)
 {
   register int c;
@@ -501,7 +502,7 @@ lex (void)
 	set.  A retval action returns the code.
 */
 struct percent_table_struct {
-	char *name;
+	const char *name;
 	void *setflag;
 	int retval;
 } percent_table[] =
