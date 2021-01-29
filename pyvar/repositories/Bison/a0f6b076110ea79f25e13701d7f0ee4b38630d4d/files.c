@@ -50,6 +50,7 @@ Boston, MA 02111-1307, USA.  */
 #include "files.h"
 #include "alloc.h"
 #include "gram.h"
+#include "complain.h"
 
 FILE *finput = NULL;
 FILE *foutput = NULL;
@@ -78,14 +79,12 @@ extern int noparserflag;
 
 extern char	*mktemp();	/* So the compiler won't complain */
 extern char	*getenv();
-extern void	perror();
 
 char *stringappend PARAMS((char *, int, char *));
 void openfiles PARAMS((void));
 void open_extra_files PARAMS((void));
 FILE *tryopen PARAMS((char *, char *));	/* This might be a good idea */
 int tryclose PARAMS((FILE *));
-void done PARAMS((int));
 
 extern char *program_name;
 extern int verboseflag;
@@ -231,7 +230,7 @@ openfiles (void)
 
   finput = tryopen(infile, "r");
 
-  if (! noparserflag) 
+  if (! noparserflag)
     {
       filename = getenv("BISON_SIMPLE");
 #ifdef MSDOS
@@ -266,7 +265,7 @@ openfiles (void)
       /* use permanent name for actions file */
       actfile = stringappend(name_base, short_base_length, ".act");
       faction = tryopen(actfile, "w");
-    } 
+    }
 
 #ifdef MSDOS
   if (! noparserflag)
@@ -338,7 +337,7 @@ open_extra_files (void)
 
   tryclose(fparser);
 
-  if (! noparserflag) 
+  if (! noparserflag)
     {
       filename = (char *) getenv ("BISON_HAIRY");
 #ifdef MSDOS
@@ -368,20 +367,17 @@ open_extra_files (void)
 
 }
 
-	/* JF to make file opening easier.  This func tries to open file
-	   NAME with mode MODE, and prints an error message if it fails. */
+/* JF to make file opening easier.  This func tries to open file
+   NAME with mode MODE, and prints an error message if it fails. */
 FILE *
 tryopen (char *name, char *mode)
 {
   FILE	*ptr;
 
-  ptr = fopen(name, mode);
-  if (ptr == NULL)
-    {
-      fprintf(stderr, "%s: ", program_name);
-      perror(name);
-      done(2);
-    }
+  ptr = fopen (name, mode);
+  if (!ptr)
+    error (2, errno, _("cannot open file `%s'"), name);
+
   return ptr;
 }
 
@@ -395,16 +391,13 @@ tryclose (FILE *ptr)
 
   result = fclose (ptr);
   if (result == EOF)
-    {
-      fprintf (stderr, "%s: ", program_name);
-      perror ("fclose");
-      done (2);
-    }
+    error (2, errno, _("cannot close file"));
+
   return result;
 }
 
 void
-done (int k)
+done (void)
 {
   tryclose(faction);
   tryclose(fattrs);
@@ -413,8 +406,8 @@ done (int k)
   tryclose(fparser);
   tryclose(foutput);
 
-	/* JF write out the output file */
-  if (k == 0 && ftable)
+  /* JF write out the output file */
+  if (!complain_message_count && ftable)
     {
       FILE *ftmp;
       register int c;
@@ -445,8 +438,10 @@ done (int k)
     delete(tmpattrsfile);
   if (ftable)
     delete(tmptabfile);
-  if (k==0) sys$exit(SS$_NORMAL);
-  sys$exit(SS$_ABORT);
+/* Don't call exit again, we're in atexit ().
+  if (!complain_message_count)
+    sys$exit(SS$_NORMAL);
+  sys$exit(SS$_ABORT); */
 #else
 #if (defined (MSDOS) || (defined(_WIN32) && !defined(__CYGWIN32__)))
   if (actfile && ! noparserflag) unlink(actfile);
@@ -454,6 +449,7 @@ done (int k)
   if (tmptabfile) unlink(tmptabfile);
   if (tmpdefsfile) unlink(tmpdefsfile);
 #endif /* MSDOS || (_WIN32 && !__CYGWIN32__) */
-  exit(k);
+/* Don't call exit again, we're in atexit ().
+  exit (complain_message_count ? 1 : 0); */
 #endif /* not VMS, or __VMS_POSIX */
 }
