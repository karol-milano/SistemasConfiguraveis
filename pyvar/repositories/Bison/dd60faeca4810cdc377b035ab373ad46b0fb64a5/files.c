@@ -51,11 +51,11 @@ FILE *finput = NULL;
 FILE *foutput = NULL;
 FILE *fdefines = NULL;
 FILE *ftable = NULL;
-FILE *fattrs = NULL;
 FILE *fguard = NULL;
 FILE *fparser = NULL;
 
 struct obstack action_obstack;
+struct obstack attrs_obstack;
 
 /* File name specified with -o for the output file, or 0 if no -o.  */
 char *spec_outfile;
@@ -68,7 +68,6 @@ static char *defsfile;
 static char *tabfile;
 static char *guardfile;
 static char *actfile;
-static char *tmpattrsfile;
 static char *tmptabfile;
 static char *tmpdefsfile;
 
@@ -293,16 +292,13 @@ open_files (void)
     }
 
 #ifdef MSDOS
-  tmpattrsfile = mktemp (stringappend (tmp_base, tmp_len, "atXXXXXX"));
   tmptabfile = mktemp (stringappend (tmp_base, tmp_len, "taXXXXXX"));
   tmpdefsfile = mktemp (stringappend (tmp_base, tmp_len, "deXXXXXX"));
 #else
-  tmpattrsfile = mktemp (stringappend (tmp_base, tmp_len, "attrs.XXXXXX"));
   tmptabfile = mktemp (stringappend (tmp_base, tmp_len, "tab.XXXXXX"));
   tmpdefsfile = mktemp (stringappend (tmp_base, tmp_len, "defs.XXXXXX"));
 #endif /* not MSDOS */
 
-  fattrs = xfopen (tmpattrsfile, "w+");
   ftable = xfopen (tmptabfile, "w+");
 
   if (defines_flag)
@@ -312,7 +308,6 @@ open_files (void)
     }
 
 #if !(defined (MSDOS) || (defined(_WIN32) && !defined(__CYGWIN32__)))
-  unlink (tmpattrsfile);
   unlink (tmptabfile);
   unlink (tmpdefsfile);
 #endif /* MSDOS || (_WIN32 && !__CYGWIN32__) */
@@ -336,8 +331,9 @@ open_files (void)
 #endif /* not MSDOS */
 #endif /* not VMS */
 
-  /* Setup the action obstack. */
+  /* Initialize the obstacks. */
   obstack_init (&action_obstack);
+  obstack_init (&attrs_obstack);
 }
 
 
@@ -350,12 +346,8 @@ open_files (void)
 void
 open_extra_files (void)
 {
-  FILE *ftmp;
   int c;
   char *filename;
-#ifdef MSDOS
-  char *cp;
-#endif
 
   xfclose (fparser);
 
@@ -363,36 +355,29 @@ open_extra_files (void)
     {
       filename = (char *) getenv ("BISON_HAIRY");
 #ifdef MSDOS
-      /* File doesn't exist in current directory; try in INIT directory.  */
-      cp = getenv ("INIT");
-      if (filename == 0 && cp != NULL)
-	{
-	  filename = XMALLOC (char, strlen (cp) + strlen (PFILE1) + 2);
-	  strcpy (filename, cp);
-	  cp = filename + strlen (filename);
-	  *cp++ = '/';
-	  strcpy (cp, PFILE1);
-	}
+      {
+	/* File doesn't exist in current directory; try in INIT
+	   directory.  */
+	char *cp = getenv ("INIT");
+	if (filename == 0 && cp != NULL)
+	  {
+	    filename = XMALLOC (char, strlen (cp) + strlen (PFILE1) + 2);
+	    strcpy (filename, cp);
+	    cp = filename + strlen (filename);
+	    *cp++ = '/';
+	    strcpy (cp, PFILE1);
+	  }
+      }
 #endif
       fparser = xfopen (filename ? filename : PFILE1, "r");
     }
 
-  /* JF change from inline attrs file to separate one */
-  ftmp = xfopen (attrsfile, "w");
-  rewind (fattrs);
-  while ((c = getc (fattrs)) != EOF)	/* Thank god for buffering */
-    putc (c, ftmp);
-  xfclose (fattrs);
-  fattrs = ftmp;
-
   fguard = xfopen (guardfile, "w");
-
 }
 
 void
 done (void)
 {
-  xfclose (fattrs);
   xfclose (fguard);
   xfclose (finput);
   xfclose (fparser);
@@ -423,16 +408,27 @@ done (void)
 	}
     }
 
+  /* If we output only the table, dump the actions in ACTION_OBSTACK.
+     */
   if (no_parser_flag)
     {
       FILE *faction = xfopen (actfile, "w");
       size_t size = obstack_object_size (&action_obstack);
       fwrite (obstack_finish (&action_obstack), 1, size, faction);
-      fclose (faction);
+      xfclose (faction);
     }
+
+  /* If we produced a semantic parser ATTRS_OBSTACK must be dumped
+     into its own file, ATTTRSFILE.  */
+  if (semantic_parser)
+    {
+      FILE *fattrs = xfopen (attrsfile, "w");
+      size_t size = obstack_object_size (&attrs_obstack);
+      fwrite (obstack_finish (&attrs_obstack), 1, size, fattrs);
+      xfclose (fattrs);
+    }
+
 #if defined (VMS) & !defined (__VMS_POSIX)
-  if (fattrs)
-    delete (tmpattrsfile);
   if (ftable)
     delete (tmptabfile);
 /* Don't call exit again, we're in atexit ().
@@ -441,8 +437,6 @@ done (void)
   sys$exit(SS$_ABORT); */
 #else
 #if (defined (MSDOS) || (defined(_WIN32) && !defined(__CYGWIN32__)))
-  if (tmpattrsfile)
-    unlink (tmpattrsfile);
   if (tmptabfile)
     unlink (tmptabfile);
   if (tmpdefsfile)
