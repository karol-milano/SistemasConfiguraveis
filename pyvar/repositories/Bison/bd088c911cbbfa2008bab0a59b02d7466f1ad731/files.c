@@ -72,8 +72,12 @@ extern int noparserflag;
 extern char	*mktemp();	/* So the compiler won't complain */
 extern char	*getenv();
 extern void	perror();
-FILE	*tryopen();	/* This might be a good idea */
-void done();
+
+char *stringappend PARAMS((char *, int, char *));
+void openfiles PARAMS((void));
+void open_extra_files PARAMS((void));
+FILE *tryopen PARAMS((char *, char *));	/* This might be a good idea */
+void done PARAMS((int));
 
 extern char *program_name;
 extern int verboseflag;
@@ -81,11 +85,8 @@ extern int definesflag;
 int fixed_outfiles = 0;
 
 
-char*
-stringappend(string1, end1, string2)
-char *string1;
-int end1;
-char *string2;
+char *
+stringappend (char *string1, int end1, char *string2)
 {
   register char *ostring;
   register char *cp, *cp1;
@@ -102,7 +103,8 @@ char *string2;
     *cp++ = *cp1++;
 
   cp1 = string2;
-  while (*cp++ = *cp1++) ;
+  while ((*cp++ = *cp1++))
+    ;
 
   return ostring;
 }
@@ -111,7 +113,7 @@ char *string2;
 /* JF this has been hacked to death.  Nowaday it sets up the file names for
    the output files, and opens the tmp files and the parser */
 void
-openfiles()
+openfiles (void)
 {
   char *name_base;
   register char *cp;
@@ -142,6 +144,15 @@ openfiles()
   strlwr (infile);
 #endif /* _WIN32 && !__CYGWIN32__ */
 
+#if (defined(unix) || defined(__unix) || defined(__unix__))
+  {
+    char *tmp_ptr = getenv("TMPDIR");
+
+    if (tmp_ptr != 0)
+      tmp_base = stringappend (tmp_ptr, strlen (tmp_ptr), "/b.");
+  }
+#endif  /* unix || __unix || __unix__ */
+
   tmp_len = strlen (tmp_base);
 
   if (spec_outfile)
@@ -306,7 +317,7 @@ openfiles()
 This is done when %semantic_parser is seen in the declarations section.  */
 
 void
-open_extra_files()
+open_extra_files (void)
 {
   FILE *ftmp;
   int c;
@@ -348,9 +359,7 @@ open_extra_files()
 	/* JF to make file opening easier.  This func tries to open file
 	   NAME with mode MODE, and prints an error message if it fails. */
 FILE *
-tryopen(name, mode)
-char *name;
-char *mode;
+tryopen (char *name, char *mode)
 {
   FILE	*ptr;
 
@@ -365,8 +374,7 @@ char *mode;
 }
 
 void
-done(k)
-int k;
+done (int k)
 {
   if (faction)
     fclose(faction);
