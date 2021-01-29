@@ -65,40 +65,44 @@ FILE *fparser = NULL;
 char *spec_outfile;
 
 char *infile;
-char *outfile;
-char *defsfile;
-char *tabfile;
 char *attrsfile;
-char *guardfile;
-char *actfile;
-char *tmpattrsfile;
-char *tmptabfile;
-char *tmpdefsfile;
+
+static char *outfile;
+static char *defsfile;
+static char *tabfile;
+static char *guardfile;
+static char *actfile;
+static char *tmpattrsfile;
+static char *tmptabfile;
+static char *tmpdefsfile;
 
 extern int noparserflag;
 
 extern char	*mktemp();	/* So the compiler won't complain */
 extern char	*getenv();
 
-char *stringappend PARAMS((char *, int, char *));
-void openfiles PARAMS((void));
-void open_extra_files PARAMS((void));
+extern char *stringappend PARAMS((const char *, int, const char *));
+extern void openfiles PARAMS((void));
+extern void open_extra_files PARAMS((void));
+
+int fixed_outfiles = 0;
 
 extern char *program_name;
 extern int verboseflag;
 extern int definesflag;
-int fixed_outfiles = 0;
 
 
 char *
-stringappend (char *string1, int end1, char *string2)
+stringappend (const char *string1, int end1, const char *string2)
 {
   register char *ostring;
-  register char *cp, *cp1;
+  register char *cp;
+  register const char *cp1;
   register int i;
 
-  cp = string2;  i = 0;
-  while (*cp++) i++;
+  cp1 = string2;
+  i = 0;
+  while (*cp1++) i++;
 
   ostring = NEW2(i+end1+1, char);
 
@@ -120,7 +124,7 @@ stringappend (char *string1, int end1, char *string2)
 `-----------------------------------------------------------------*/
 
 static FILE *
-tryopen (char *name, char *mode)
+tryopen (const char *name, const char *mode)
 {
   FILE	*ptr;
 
@@ -164,9 +168,9 @@ openfiles (void)
   int short_base_length;
 
 #if defined (VMS) & !defined (__VMS_POSIX)
-  char *tmp_base = "sys$scratch:b_";
+  const char *tmp_base = "sys$scratch:b_";
 #else
-  char *tmp_base = "/tmp/b.";
+  const char *tmp_base = "/tmp/b.";
 #endif
   int tmp_len;
 
@@ -240,7 +244,9 @@ openfiles (void)
       /* -o was not specified; compute output file name from input
 	 or use y.tab.c, etc., if -y was specified.  */
 
-      name_base = fixed_outfiles ? "y.y" : infile;
+      static char FIXED_NAME_BASE[] = "y.y";
+
+      name_base = fixed_outfiles ? FIXED_NAME_BASE : infile;
 
       /* BASE_LENGTH gets length of NAME_BASE, sans ".y" suffix if any.  */
 
