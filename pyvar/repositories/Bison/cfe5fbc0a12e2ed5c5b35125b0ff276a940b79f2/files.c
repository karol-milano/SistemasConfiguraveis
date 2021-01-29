@@ -83,8 +83,6 @@ extern char	*getenv();
 char *stringappend PARAMS((char *, int, char *));
 void openfiles PARAMS((void));
 void open_extra_files PARAMS((void));
-FILE *tryopen PARAMS((char *, char *));	/* This might be a good idea */
-int tryclose PARAMS((FILE *));
 
 extern char *program_name;
 extern int verboseflag;
@@ -116,7 +114,42 @@ stringappend (char *string1, int end1, char *string2)
   return ostring;
 }
 
+/*-----------------------------------------------------------------.
+| Try to open file NAME with mode MODE, and print an error message |
+| if fails.                                                        |
+`-----------------------------------------------------------------*/
 
+static FILE *
+tryopen (char *name, char *mode)
+{
+  FILE	*ptr;
+
+  ptr = fopen (name, mode);
+  if (!ptr)
+    error (2, errno, _("cannot open file `%s'"), name);
+
+  return ptr;
+}
+
+/*-------------------------------------------------------------.
+| Try to close file PTR, and print an error message if fails.  |
+`-------------------------------------------------------------*/
+
+static int
+tryclose (FILE *ptr)
+{
+  int result;
+
+  if (ptr == NULL)
+    return 0;
+
+  result = fclose (ptr);
+  if (result == EOF)
+    error (2, errno, _("cannot close file"));
+
+  return result;
+}
+
 /* JF this has been hacked to death.  Nowaday it sets up the file names for
    the output files, and opens the tmp files and the parser */
 void
@@ -367,35 +400,6 @@ open_extra_files (void)
 
 }
 
-/* JF to make file opening easier.  This func tries to open file
-   NAME with mode MODE, and prints an error message if it fails. */
-FILE *
-tryopen (char *name, char *mode)
-{
-  FILE	*ptr;
-
-  ptr = fopen (name, mode);
-  if (!ptr)
-    error (2, errno, _("cannot open file `%s'"), name);
-
-  return ptr;
-}
-
-int
-tryclose (FILE *ptr)
-{
-  int result;
-
-  if (ptr == NULL)
-    return 0;
-
-  result = fclose (ptr);
-  if (result == EOF)
-    error (2, errno, _("cannot close file"));
-
-  return result;
-}
-
 void
 done (void)
 {
