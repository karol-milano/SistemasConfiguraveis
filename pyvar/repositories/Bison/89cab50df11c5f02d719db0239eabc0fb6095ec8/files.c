@@ -232,7 +232,7 @@ open_files (void)
 
       static char FIXED_NAME_BASE[] = "y.y";
 
-      name_base = yaccflag ? FIXED_NAME_BASE : infile;
+      name_base = yacc_flag ? FIXED_NAME_BASE : infile;
 
       /* BASE_LENGTH gets length of NAME_BASE, sans ".y" suffix if any.  */
 
@@ -255,7 +255,7 @@ open_files (void)
 
   finput = xfopen (infile, "r");
 
-  if (!noparserflag)
+  if (!no_parser_flag)
     {
       filename = getenv ("BISON_SIMPLE");
 #ifdef MSDOS
@@ -273,7 +273,7 @@ open_files (void)
       fparser = xfopen (filename ? filename : PFILE, "r");
     }
 
-  if (verboseflag)
+  if (verbose_flag)
     {
 #ifdef MSDOS
       outfile = stringappend (name_base, short_base_length, ".out");
@@ -285,7 +285,7 @@ open_files (void)
       foutput = xfopen (outfile, "w");
     }
 
-  if (noparserflag)
+  if (no_parser_flag)
     {
       /* use permanent name for actions file */
       actfile = stringappend (name_base, short_base_length, ".act");
@@ -293,32 +293,32 @@ open_files (void)
     }
 
 #ifdef MSDOS
-  if (!noparserflag)
+  if (!no_parser_flag)
     actfile = mktemp (stringappend (tmp_base, tmp_len, "acXXXXXX"));
   tmpattrsfile = mktemp (stringappend (tmp_base, tmp_len, "atXXXXXX"));
   tmptabfile = mktemp (stringappend (tmp_base, tmp_len, "taXXXXXX"));
   tmpdefsfile = mktemp (stringappend (tmp_base, tmp_len, "deXXXXXX"));
 #else
-  if (!noparserflag)
+  if (!no_parser_flag)
     actfile = mktemp (stringappend (tmp_base, tmp_len, "act.XXXXXX"));
   tmpattrsfile = mktemp (stringappend (tmp_base, tmp_len, "attrs.XXXXXX"));
   tmptabfile = mktemp (stringappend (tmp_base, tmp_len, "tab.XXXXXX"));
   tmpdefsfile = mktemp (stringappend (tmp_base, tmp_len, "defs.XXXXXX"));
 #endif /* not MSDOS */
 
-  if (!noparserflag)
+  if (!no_parser_flag)
     faction = xfopen (actfile, "w+");
   fattrs = xfopen (tmpattrsfile, "w+");
   ftable = xfopen (tmptabfile, "w+");
 
-  if (definesflag)
+  if (defines_flag)
     {
       defsfile = stringappend (name_base, base_length, ".h");
       fdefines = xfopen (tmpdefsfile, "w+");
     }
 
 #if !(defined (MSDOS) || (defined(_WIN32) && !defined(__CYGWIN32__)))
-  if (!noparserflag)
+  if (!no_parser_flag)
     unlink (actfile);
   unlink (tmpattrsfile);
   unlink (tmptabfile);
@@ -364,7 +364,7 @@ open_extra_files (void)
 
   xfclose (fparser);
 
-  if (!noparserflag)
+  if (!no_parser_flag)
     {
       filename = (char *) getenv ("BISON_HAIRY");
 #ifdef MSDOS
@@ -417,7 +417,7 @@ done (void)
       xfclose (ftmp);
       xfclose (ftable);
 
-      if (definesflag)
+      if (defines_flag)
 	{
 	  ftmp = xfopen (defsfile, "w");
 	  fflush (fdefines);
@@ -430,7 +430,7 @@ done (void)
     }
 
 #if defined (VMS) & !defined (__VMS_POSIX)
-  if (faction && !noparserflag)
+  if (faction && !no_parser_flag)
     delete (actfile);
   if (fattrs)
     delete (tmpattrsfile);
@@ -442,7 +442,7 @@ done (void)
   sys$exit(SS$_ABORT); */
 #else
 #if (defined (MSDOS) || (defined(_WIN32) && !defined(__CYGWIN32__)))
-  if (actfile && !noparserflag)
+  if (actfile && !no_parser_flag)
     unlink (actfile);
   if (tmpattrsfile)
     unlink (tmpattrsfile);
