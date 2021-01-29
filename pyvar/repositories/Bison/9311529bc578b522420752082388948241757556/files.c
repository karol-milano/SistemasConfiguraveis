@@ -141,7 +141,7 @@ xfclose (FILE *ptr)
 | Save the content of the obstack OBS in FILENAME.  |
 `--------------------------------------------------*/
 
-void
+static void
 obstack_save (struct obstack *obs, const char *filename)
 {
   FILE *out = xfopen (filename, "w");
@@ -150,6 +150,29 @@ obstack_save (struct obstack *obs, const char *filename)
   xfclose (out);
 }
 
+
+static const char *
+skeleton_find (const char *envvar, const char *skeleton)
+{
+  const char *res = getenv (envvar);
+
+#ifdef MSDOS
+  const char *cp;
+
+  /* File doesn't exist in current directory; try in INIT directory.  */
+  if (!res && (cp = getenv ("INIT")))
+    {
+      res = XMALLOC (char, strlen (cp) + strlen (skeleton) + 2);
+      sprintf (res, "%s%c%s", cp, '/', skeleton);
+    }
+#endif /* !MSDOS */
+
+  if (!res)
+    res = skeleton;
+
+  return res;
+}
+
 
 /*-----------------------------------------------------------------.
 | Open the input file.  Look for the skeletons.  Find the names of |
@@ -163,7 +186,6 @@ open_files (void)
 #ifdef MSDOS
   register char *cp;
 #endif
-  char *filename;
   int base_length;
   int short_base_length;
 
@@ -270,22 +292,7 @@ open_files (void)
   finput = xfopen (infile, "r");
 
   if (!no_parser_flag)
-    {
-      filename = getenv ("BISON_SIMPLE");
-#ifdef MSDOS
-      /* File doesn't exist in current directory; try in INIT directory.  */
-      cp = getenv ("INIT");
-      if (filename == 0 && cp != NULL)
-	{
-	  filename = XMALLOC (char, strlen (cp) + strlen (PFILE) + 2);
-	  strcpy (filename, cp);
-	  cp = filename + strlen (filename);
-	  *cp++ = '/';
-	  strcpy (cp, PFILE);
-	}
-#endif /* MSDOS */
-      fparser = xfopen (filename ? filename : PFILE, "r");
-    }
+    fparser = xfopen (skeleton_find ("BISON_SIMPLE", PFILE), "r");
 
   if (verbose_flag)
     {
@@ -346,32 +353,10 @@ open_files (void)
 void
 open_extra_files (void)
 {
-  int c;
-  char *filename;
-
   xfclose (fparser);
 
   if (!no_parser_flag)
-    {
-      filename = (char *) getenv ("BISON_HAIRY");
-#ifdef MSDOS
-      {
-	/* File doesn't exist in current directory; try in INIT
-	   directory.  */
-	char *cp = getenv ("INIT");
-	if (filename == 0 && cp != NULL)
-	  {
-	    filename = XMALLOC (char, strlen (cp) + strlen (PFILE1) + 2);
-	    strcpy (filename, cp);
-	    cp = filename + strlen (filename);
-	    *cp++ = '/';
-	    strcpy (cp, PFILE1);
-	  }
-      }
-#endif
-      fparser = xfopen (filename ? filename : PFILE1, "r");
-    }
-
+    fparser = xfopen (skeleton_find ("BISON_HAIRY", PFILE1), "r");
   fguard = xfopen (guardfile, "w");
 }
 
