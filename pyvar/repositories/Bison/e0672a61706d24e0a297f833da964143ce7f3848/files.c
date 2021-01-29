@@ -133,6 +133,15 @@ openfiles()
   strlwr (infile);
 #endif /* MSDOS */
 
+#if (defined(_WIN32) && !defined(__CYGWIN32__))
+  tmp_base = getenv ("TEMP");		/* Windows95 defines this ... */
+  if (tmp_base == 0)
+    tmp_base = getenv ("Temp");		/* ... while NT prefers this */
+  if (tmp_base == 0)
+    tmp_base = "";
+  strlwr (infile);
+#endif /* _WIN32 && !__CYGWIN32__ */
+
   tmp_len = strlen (tmp_base);
 
   if (spec_outfile)
@@ -263,13 +272,13 @@ openfiles()
       fdefines = tryopen(tmpdefsfile, "w+");
     }
 
-#ifndef MSDOS
+#if !(defined (MSDOS) || (defined(_WIN32) && !defined(__CYGWIN32__)))
   if (! noparserflag)
     unlink(actfile);
   unlink(tmpattrsfile);
   unlink(tmptabfile);
   unlink(tmpdefsfile);
-#endif
+#endif /* MSDOS || (_WIN32 && !__CYGWIN32__) */
 
 	/* These are opened by `done' or `open_extra_files', if at all */
   if (spec_outfile)
@@ -412,12 +421,12 @@ int k;
   if (k==0) sys$exit(SS$_NORMAL);
   sys$exit(SS$_ABORT);
 #else
-#ifdef MSDOS
+#if (defined (MSDOS) || (defined(_WIN32) && !defined(__CYGWIN32__)))
   if (actfile && ! noparserflag) unlink(actfile);
   if (tmpattrsfile) unlink(tmpattrsfile);
   if (tmptabfile) unlink(tmptabfile);
   if (tmpdefsfile) unlink(tmpdefsfile);
-#endif /* MSDOS */
+#endif /* MSDOS || (_WIN32 && !__CYGWIN32__) */
   exit(k);
 #endif /* not VMS, or __VMS_POSIX */
 }
