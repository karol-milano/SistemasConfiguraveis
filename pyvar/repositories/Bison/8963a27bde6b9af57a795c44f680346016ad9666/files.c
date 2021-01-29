@@ -71,19 +71,15 @@ static char *tmpattrsfile;
 static char *tmptabfile;
 static char *tmpdefsfile;
 
-extern char	*mktemp();	/* So the compiler won't complain */
-extern char	*getenv();
-
-extern char *stringappend PARAMS((const char *, int, const char *));
-extern void openfiles PARAMS((void));
-extern void open_extra_files PARAMS((void));
+extern char *mktemp ();		/* So the compiler won't complain */
+extern char *getenv ();
 
 int fixed_outfiles = 0;
 
 extern char *program_name;
 
 
-char *
+static char *
 stringappend (const char *string1, int end1, const char *string2)
 {
   register char *ostring;
@@ -93,9 +89,10 @@ stringappend (const char *string1, int end1, const char *string2)
 
   cp1 = string2;
   i = 0;
-  while (*cp1++) i++;
+  while (*cp1++)
+    i++;
 
-  ostring = NEW2(i+end1+1, char);
+  ostring = NEW2 (i + end1 + 1, char);
 
   cp = ostring;
   cp1 = string1;
@@ -115,9 +112,9 @@ stringappend (const char *string1, int end1, const char *string2)
 `-----------------------------------------------------------------*/
 
 static FILE *
-tryopen (const char *name, const char *mode)
+xfopen (const char *name, const char *mode)
 {
-  FILE	*ptr;
+  FILE *ptr;
 
   ptr = fopen (name, mode);
   if (!ptr)
@@ -131,7 +128,7 @@ tryopen (const char *name, const char *mode)
 `-------------------------------------------------------------*/
 
 static int
-tryclose (FILE *ptr)
+xfclose (FILE *ptr)
 {
   int result;
 
@@ -148,7 +145,7 @@ tryclose (FILE *ptr)
 /* JF this has been hacked to death.  Nowaday it sets up the file names for
    the output files, and opens the tmp files and the parser */
 void
-openfiles (void)
+open_files (void)
 {
   char *name_base;
 #ifdef MSDOS
@@ -173,9 +170,9 @@ openfiles (void)
 #endif /* MSDOS */
 
 #if (defined(_WIN32) && !defined(__CYGWIN32__))
-  tmp_base = getenv ("TEMP");		/* Windows95 defines this ... */
+  tmp_base = getenv ("TEMP");	/* Windows95 defines this ... */
   if (tmp_base == 0)
-    tmp_base = getenv ("Temp");		/* ... while NT prefers this */
+    tmp_base = getenv ("Temp");	/* ... while NT prefers this */
   if (tmp_base == 0)
     tmp_base = "";
   strlwr (infile);
@@ -183,19 +180,19 @@ openfiles (void)
 
 #if (defined(unix) || defined(__unix) || defined(__unix__) || defined(__EMX__))
   {
-    char *tmp_ptr = getenv("TMPDIR");
+    char *tmp_ptr = getenv ("TMPDIR");
 
     if (tmp_ptr != 0)
       tmp_base = stringappend (tmp_ptr, strlen (tmp_ptr), "/b.");
   }
-#endif  /* unix || __unix || __unix__ */
+#endif /* unix || __unix || __unix__ */
 
   tmp_len = strlen (tmp_base);
 
   if (spec_outfile)
     {
       /* -o was specified.  The precise -o name will be used for ftable.
-	 For other output files, remove the ".c" or ".tab.c" suffix.  */
+         For other output files, remove the ".c" or ".tab.c" suffix.  */
       name_base = spec_outfile;
 #ifdef MSDOS
       strlwr (name_base);
@@ -233,7 +230,7 @@ openfiles (void)
   else
     {
       /* -o was not specified; compute output file name from input
-	 or use y.tab.c, etc., if -y was specified.  */
+         or use y.tab.c, etc., if -y was specified.  */
 
       static char FIXED_NAME_BASE[] = "y.y";
 
@@ -247,105 +244,105 @@ openfiles (void)
       short_base_length = base_length;
 
 #ifdef VMS
-      name_base = stringappend(name_base, short_base_length, "_tab");
+      name_base = stringappend (name_base, short_base_length, "_tab");
 #else
 #ifdef MSDOS
-      name_base = stringappend(name_base, short_base_length, "_tab");
+      name_base = stringappend (name_base, short_base_length, "_tab");
 #else
-      name_base = stringappend(name_base, short_base_length, ".tab");
+      name_base = stringappend (name_base, short_base_length, ".tab");
 #endif /* not MSDOS */
 #endif
       base_length = short_base_length + 4;
     }
 
-  finput = tryopen(infile, "r");
+  finput = xfopen (infile, "r");
 
-  if (! noparserflag)
+  if (!noparserflag)
     {
-      filename = getenv("BISON_SIMPLE");
+      filename = getenv ("BISON_SIMPLE");
 #ifdef MSDOS
       /* File doesn't exist in current directory; try in INIT directory.  */
-      cp = getenv("INIT");
+      cp = getenv ("INIT");
       if (filename == 0 && cp != NULL)
-        {
-          filename = xmalloc(strlen(cp) + strlen(PFILE) + 2);
-          strcpy(filename, cp);
-          cp = filename + strlen(filename);
-          *cp++ = '/';
-          strcpy(cp, PFILE);
-        }
+	{
+	  filename = xmalloc (strlen (cp) + strlen (PFILE) + 2);
+	  strcpy (filename, cp);
+	  cp = filename + strlen (filename);
+	  *cp++ = '/';
+	  strcpy (cp, PFILE);
+	}
 #endif /* MSDOS */
-      fparser = tryopen(filename ? filename : PFILE, "r");
+      fparser = xfopen (filename ? filename : PFILE, "r");
     }
 
   if (verboseflag)
     {
 #ifdef MSDOS
-      outfile = stringappend(name_base, short_base_length, ".out");
+      outfile = stringappend (name_base, short_base_length, ".out");
 #else
       /* We used to use just .out if spec_name_prefix (-p) was used,
-	 but that conflicts with Posix.  */
-      outfile = stringappend(name_base, short_base_length, ".output");
+         but that conflicts with Posix.  */
+      outfile = stringappend (name_base, short_base_length, ".output");
 #endif
-      foutput = tryopen(outfile, "w");
+      foutput = xfopen (outfile, "w");
     }
 
   if (noparserflag)
     {
       /* use permanent name for actions file */
-      actfile = stringappend(name_base, short_base_length, ".act");
-      faction = tryopen(actfile, "w");
+      actfile = stringappend (name_base, short_base_length, ".act");
+      faction = xfopen (actfile, "w");
     }
 
 #ifdef MSDOS
-  if (! noparserflag)
-    actfile = mktemp(stringappend(tmp_base, tmp_len, "acXXXXXX"));
-  tmpattrsfile = mktemp(stringappend(tmp_base, tmp_len, "atXXXXXX"));
-  tmptabfile = mktemp(stringappend(tmp_base, tmp_len, "taXXXXXX"));
-  tmpdefsfile = mktemp(stringappend(tmp_base, tmp_len, "deXXXXXX"));
+  if (!noparserflag)
+    actfile = mktemp (stringappend (tmp_base, tmp_len, "acXXXXXX"));
+  tmpattrsfile = mktemp (stringappend (tmp_base, tmp_len, "atXXXXXX"));
+  tmptabfile = mktemp (stringappend (tmp_base, tmp_len, "taXXXXXX"));
+  tmpdefsfile = mktemp (stringappend (tmp_base, tmp_len, "deXXXXXX"));
 #else
-  if (! noparserflag)
-    actfile = mktemp(stringappend(tmp_base, tmp_len, "act.XXXXXX"));
-  tmpattrsfile = mktemp(stringappend(tmp_base, tmp_len, "attrs.XXXXXX"));
-  tmptabfile = mktemp(stringappend(tmp_base, tmp_len, "tab.XXXXXX"));
-  tmpdefsfile = mktemp(stringappend(tmp_base, tmp_len, "defs.XXXXXX"));
+  if (!noparserflag)
+    actfile = mktemp (stringappend (tmp_base, tmp_len, "act.XXXXXX"));
+  tmpattrsfile = mktemp (stringappend (tmp_base, tmp_len, "attrs.XXXXXX"));
+  tmptabfile = mktemp (stringappend (tmp_base, tmp_len, "tab.XXXXXX"));
+  tmpdefsfile = mktemp (stringappend (tmp_base, tmp_len, "defs.XXXXXX"));
 #endif /* not MSDOS */
 
-  if (! noparserflag)
-    faction = tryopen(actfile, "w+");
-  fattrs = tryopen(tmpattrsfile,"w+");
-  ftable = tryopen(tmptabfile, "w+");
+  if (!noparserflag)
+    faction = xfopen (actfile, "w+");
+  fattrs = xfopen (tmpattrsfile, "w+");
+  ftable = xfopen (tmptabfile, "w+");
 
   if (definesflag)
     {
-      defsfile = stringappend(name_base, base_length, ".h");
-      fdefines = tryopen(tmpdefsfile, "w+");
+      defsfile = stringappend (name_base, base_length, ".h");
+      fdefines = xfopen (tmpdefsfile, "w+");
     }
 
 #if !(defined (MSDOS) || (defined(_WIN32) && !defined(__CYGWIN32__)))
-  if (! noparserflag)
-    unlink(actfile);
-  unlink(tmpattrsfile);
-  unlink(tmptabfile);
-  unlink(tmpdefsfile);
+  if (!noparserflag)
+    unlink (actfile);
+  unlink (tmpattrsfile);
+  unlink (tmptabfile);
+  unlink (tmpdefsfile);
 #endif /* MSDOS || (_WIN32 && !__CYGWIN32__) */
 
-	/* These are opened by `done' or `open_extra_files', if at all */
+  /* These are opened by `done' or `open_extra_files', if at all */
   if (spec_outfile)
     tabfile = spec_outfile;
   else
-    tabfile = stringappend(name_base, base_length, ".c");
+    tabfile = stringappend (name_base, base_length, ".c");
 
 #ifdef VMS
-  attrsfile = stringappend(name_base, short_base_length, "_stype.h");
-  guardfile = stringappend(name_base, short_base_length, "_guard.c");
+  attrsfile = stringappend (name_base, short_base_length, "_stype.h");
+  guardfile = stringappend (name_base, short_base_length, "_guard.c");
 #else
 #ifdef MSDOS
-  attrsfile = stringappend(name_base, short_base_length, ".sth");
-  guardfile = stringappend(name_base, short_base_length, ".guc");
+  attrsfile = stringappend (name_base, short_base_length, ".sth");
+  guardfile = stringappend (name_base, short_base_length, ".guc");
 #else
-  attrsfile = stringappend(name_base, short_base_length, ".stype.h");
-  guardfile = stringappend(name_base, short_base_length, ".guard.c");
+  attrsfile = stringappend (name_base, short_base_length, ".stype.h");
+  guardfile = stringappend (name_base, short_base_length, ".guard.c");
 #endif /* not MSDOS */
 #endif /* not VMS */
 }
@@ -367,47 +364,47 @@ open_extra_files (void)
   char *cp;
 #endif
 
-  tryclose(fparser);
+  xfclose (fparser);
 
-  if (! noparserflag)
+  if (!noparserflag)
     {
       filename = (char *) getenv ("BISON_HAIRY");
 #ifdef MSDOS
       /* File doesn't exist in current directory; try in INIT directory.  */
-      cp = getenv("INIT");
+      cp = getenv ("INIT");
       if (filename == 0 && cp != NULL)
-        {
-          filename = xmalloc(strlen(cp) + strlen(PFILE1) + 2);
-          strcpy(filename, cp);
-          cp = filename + strlen(filename);
-          *cp++ = '/';
-          strcpy(cp, PFILE1);
-        }
+	{
+	  filename = xmalloc (strlen (cp) + strlen (PFILE1) + 2);
+	  strcpy (filename, cp);
+	  cp = filename + strlen (filename);
+	  *cp++ = '/';
+	  strcpy (cp, PFILE1);
+	}
 #endif
-      fparser= tryopen(filename ? filename : PFILE1, "r");
+      fparser = xfopen (filename ? filename : PFILE1, "r");
     }
 
-		/* JF change from inline attrs file to separate one */
-  ftmp = tryopen(attrsfile, "w");
-  rewind(fattrs);
-  while((c=getc(fattrs))!=EOF)	/* Thank god for buffering */
-    putc(c,ftmp);
-  tryclose(fattrs);
-  fattrs=ftmp;
+  /* JF change from inline attrs file to separate one */
+  ftmp = xfopen (attrsfile, "w");
+  rewind (fattrs);
+  while ((c = getc (fattrs)) != EOF)	/* Thank god for buffering */
+    putc (c, ftmp);
+  xfclose (fattrs);
+  fattrs = ftmp;
 
-  fguard = tryopen(guardfile, "w");
+  fguard = xfopen (guardfile, "w");
 
 }
 
 void
 done (void)
 {
-  tryclose(faction);
-  tryclose(fattrs);
-  tryclose(fguard);
-  tryclose(finput);
-  tryclose(fparser);
-  tryclose(foutput);
+  xfclose (faction);
+  xfclose (fattrs);
+  xfclose (fguard);
+  xfclose (finput);
+  xfclose (fparser);
+  xfclose (foutput);
 
   /* JF write out the output file */
   if (!complain_message_count && ftable)
@@ -415,42 +412,46 @@ done (void)
       FILE *ftmp;
       register int c;
 
-      ftmp=tryopen(tabfile, "w");
-      rewind(ftable);
-      while((c=getc(ftable)) != EOF)
-        putc(c,ftmp);
-      tryclose(ftmp);
-      tryclose(ftable);
+      ftmp = xfopen (tabfile, "w");
+      rewind (ftable);
+      while ((c = getc (ftable)) != EOF)
+	putc (c, ftmp);
+      xfclose (ftmp);
+      xfclose (ftable);
 
       if (definesflag)
-        {
-          ftmp = tryopen(defsfile, "w");
-          fflush(fdefines);
-          rewind(fdefines);
-          while((c=getc(fdefines)) != EOF)
-            putc(c,ftmp);
-          tryclose(ftmp);
-          tryclose(fdefines);
-        }
+	{
+	  ftmp = xfopen (defsfile, "w");
+	  fflush (fdefines);
+	  rewind (fdefines);
+	  while ((c = getc (fdefines)) != EOF)
+	    putc (c, ftmp);
+	  xfclose (ftmp);
+	  xfclose (fdefines);
+	}
     }
 
 #if defined (VMS) & !defined (__VMS_POSIX)
-  if (faction && ! noparserflag)
-    delete(actfile);
+  if (faction && !noparserflag)
+    delete (actfile);
   if (fattrs)
-    delete(tmpattrsfile);
+    delete (tmpattrsfile);
   if (ftable)
-    delete(tmptabfile);
+    delete (tmptabfile);
 /* Don't call exit again, we're in atexit ().
   if (!complain_message_count)
     sys$exit(SS$_NORMAL);
   sys$exit(SS$_ABORT); */
 #else
 #if (defined (MSDOS) || (defined(_WIN32) && !defined(__CYGWIN32__)))
-  if (actfile && ! noparserflag) unlink(actfile);
-  if (tmpattrsfile) unlink(tmpattrsfile);
-  if (tmptabfile) unlink(tmptabfile);
-  if (tmpdefsfile) unlink(tmpdefsfile);
+  if (actfile && !noparserflag)
+    unlink (actfile);
+  if (tmpattrsfile)
+    unlink (tmpattrsfile);
+  if (tmptabfile)
+    unlink (tmptabfile);
+  if (tmpdefsfile)
+    unlink (tmpdefsfile);
 #endif /* MSDOS || (_WIN32 && !__CYGWIN32__) */
 /* Don't call exit again, we're in atexit ().
   exit (complain_message_count ? 1 : 0); */
