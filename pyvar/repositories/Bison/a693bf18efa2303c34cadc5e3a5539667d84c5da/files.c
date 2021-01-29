@@ -78,6 +78,7 @@ char *stringappend PARAMS((char *, int, char *));
 void openfiles PARAMS((void));
 void open_extra_files PARAMS((void));
 FILE *tryopen PARAMS((char *, char *));	/* This might be a good idea */
+int tryclose PARAMS((FILE *));
 void done PARAMS((int));
 
 extern char *program_name;
@@ -117,7 +118,9 @@ void
 openfiles (void)
 {
   char *name_base;
+#ifdef MSDOS
   register char *cp;
+#endif
   char *filename;
   int base_length;
   int short_base_length;
@@ -322,10 +325,12 @@ open_extra_files (void)
 {
   FILE *ftmp;
   int c;
-  char *filename, *cp;
+  char *filename;
+#ifdef MSDOS
+  char *cp;
+#endif
 
-  if (fparser)
-    fclose(fparser);
+  tryclose(fparser);
 
   if (! noparserflag) 
     {
@@ -350,7 +355,7 @@ open_extra_files (void)
   rewind(fattrs);
   while((c=getc(fattrs))!=EOF)	/* Thank god for buffering */
     putc(c,ftmp);
-  fclose(fattrs);
+  tryclose(fattrs);
   fattrs=ftmp;
 
   fguard = tryopen(guardfile, "w");
@@ -374,26 +379,33 @@ tryopen (char *name, char *mode)
   return ptr;
 }
 
-void
-done (int k)
+int
+tryclose (FILE *ptr)
 {
-  if (faction)
-    fclose(faction);
-
-  if (fattrs)
-    fclose(fattrs);
+  int result;
 
-  if (fguard)
-    fclose(fguard);
-
-  if (finput)
-    fclose(finput);
+  if (ptr == NULL)
+    return 0;
 
-  if (fparser)
-    fclose(fparser);
+  result = fclose (ptr);
+  if (result == EOF)
+    {
+      fprintf (stderr, "%s: ", program_name);
+      perror ("fclose");
+      done (2);
+    }
+  return result;
+}
 
-  if (foutput)
-    fclose(foutput);
+void
+done (int k)
+{
+  tryclose(faction);
+  tryclose(fattrs);
+  tryclose(fguard);
+  tryclose(finput);
+  tryclose(fparser);
+  tryclose(foutput);
 
 	/* JF write out the output file */
   if (k == 0 && ftable)
@@ -405,8 +417,8 @@ done (int k)
       rewind(ftable);
       while((c=getc(ftable)) != EOF)
         putc(c,ftmp);
-      fclose(ftmp);
-      fclose(ftable);
+      tryclose(ftmp);
+      tryclose(ftable);
 
       if (definesflag)
         {
@@ -415,8 +427,8 @@ done (int k)
           rewind(fdefines);
           while((c=getc(fdefines)) != EOF)
             putc(c,ftmp);
-          fclose(ftmp);
-          fclose(fdefines);
+          tryclose(ftmp);
+          tryclose(fdefines);
         }
     }
 
