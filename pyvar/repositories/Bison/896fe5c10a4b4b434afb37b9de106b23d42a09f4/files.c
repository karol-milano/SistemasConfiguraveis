@@ -49,13 +49,13 @@
 
 FILE *finput = NULL;
 FILE *foutput = NULL;
-FILE *fdefines = NULL;
-FILE *ftable = NULL;
 FILE *fguard = NULL;
 FILE *fparser = NULL;
 
 struct obstack action_obstack;
 struct obstack attrs_obstack;
+struct obstack table_obstack;
+struct obstack defines_obstack;
 
 /* File name specified with -o for the output file, or 0 if no -o.  */
 char *spec_outfile;
@@ -68,10 +68,7 @@ static char *defsfile;
 static char *tabfile;
 static char *guardfile;
 static char *actfile;
-static char *tmptabfile;
-static char *tmpdefsfile;
 
-extern char *mktemp ();		/* So the compiler won't complain */
 extern char *getenv ();
 
 extern char *program_name;
@@ -189,7 +186,7 @@ open_files (void)
 
   if (spec_outfile)
     {
-      /* -o was specified.  The precise -o name will be used for ftable.
+      /* -o was specified.  The precise -o name will be used for FTABLE.
          For other output files, remove the ".c" or ".tab.c" suffix.  */
       name_base = spec_outfile;
 #ifdef MSDOS
@@ -291,27 +288,11 @@ open_files (void)
       actfile = stringappend (name_base, short_base_length, ".act");
     }
 
-#ifdef MSDOS
-  tmptabfile = mktemp (stringappend (tmp_base, tmp_len, "taXXXXXX"));
-  tmpdefsfile = mktemp (stringappend (tmp_base, tmp_len, "deXXXXXX"));
-#else
-  tmptabfile = mktemp (stringappend (tmp_base, tmp_len, "tab.XXXXXX"));
-  tmpdefsfile = mktemp (stringappend (tmp_base, tmp_len, "defs.XXXXXX"));
-#endif /* not MSDOS */
-
-  ftable = xfopen (tmptabfile, "w+");
-
   if (defines_flag)
     {
       defsfile = stringappend (name_base, base_length, ".h");
-      fdefines = xfopen (tmpdefsfile, "w+");
     }
 
-#if !(defined (MSDOS) || (defined(_WIN32) && !defined(__CYGWIN32__)))
-  unlink (tmptabfile);
-  unlink (tmpdefsfile);
-#endif /* MSDOS || (_WIN32 && !__CYGWIN32__) */
-
   /* These are opened by `done' or `open_extra_files', if at all */
   if (spec_outfile)
     tabfile = spec_outfile;
@@ -334,6 +315,8 @@ open_files (void)
   /* Initialize the obstacks. */
   obstack_init (&action_obstack);
   obstack_init (&attrs_obstack);
+  obstack_init (&table_obstack);
+  obstack_init (&defines_obstack);
 }
 
 
@@ -384,27 +367,21 @@ done (void)
   xfclose (foutput);
 
   /* JF write out the output file */
-  if (!complain_message_count && ftable)
+  if (!complain_message_count)
     {
-      FILE *ftmp;
-      register int c;
-
-      ftmp = xfopen (tabfile, "w");
-      rewind (ftable);
-      while ((c = getc (ftable)) != EOF)
-	putc (c, ftmp);
-      xfclose (ftmp);
-      xfclose (ftable);
+      /* Output the main file.  */
+      FILE *ftab = xfopen (tabfile, "w");
+      size_t size = obstack_object_size (&table_obstack);
+      fwrite (obstack_finish (&table_obstack), 1, size, ftab);
+      xfclose (ftab);
 
+      /* Output the header file is wanted. */
       if (defines_flag)
 	{
-	  ftmp = xfopen (defsfile, "w");
-	  fflush (fdefines);
-	  rewind (fdefines);
-	  while ((c = getc (fdefines)) != EOF)
-	    putc (c, ftmp);
-	  xfclose (ftmp);
-	  xfclose (fdefines);
+	  FILE *fdefs = xfopen (defsfile, "w");
+	  size_t size = obstack_object_size (&defines_obstack);
+	  fwrite (obstack_finish (&defines_obstack), 1, size, fdefs);
+	  xfclose (fdefs);
 	}
     }
 
@@ -428,21 +405,6 @@ done (void)
       xfclose (fattrs);
     }
 
-#if defined (VMS) & !defined (__VMS_POSIX)
-  if (ftable)
-    delete (tmptabfile);
-/* Don't call exit again, we're in atexit ().
-  if (!complain_message_count)
-    sys$exit(SS$_NORMAL);
-  sys$exit(SS$_ABORT); */
-#else
-#if (defined (MSDOS) || (defined(_WIN32) && !defined(__CYGWIN32__)))
-  if (tmptabfile)
-    unlink (tmptabfile);
-  if (tmpdefsfile)
-    unlink (tmpdefsfile);
-#endif /* MSDOS || (_WIN32 && !__CYGWIN32__) */
 /* Don't call exit again, we're in atexit ().
   exit (complain_message_count ? 1 : 0); */
-#endif /* not VMS, or __VMS_POSIX */
 }
