@@ -1,5 +1,5 @@
 /* Open and close files for bison,
-   Copyright (C) 1984, 1986, 1989 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 1992 Free Software Foundation, Inc.
 
 This file is part of Bison, the GNU Compiler Compiler.
 
@@ -58,6 +58,8 @@ char *tmpattrsfile;
 char *tmptabfile;
 char *tmpdefsfile;
 
+extern int noparserflag;
+
 extern char	*mktemp();	/* So the compiler won't complain */
 extern char	*getenv();
 extern void	perror();
@@ -190,20 +192,23 @@ openfiles()
 
   finput = tryopen(infile, "r");
 
-  filename = getenv("BISON_SIMPLE");
-#ifdef MSDOS
-  /* File doesn't exist in current directory; try in INIT directory.  */
-  cp = getenv("INIT");
-  if (filename == 0 && cp != NULL)
+  if (! noparserflag) 
     {
-      filename = xmalloc(strlen(cp) + strlen(PFILE) + 2);
-      strcpy(filename, cp);
-      cp = filename + strlen(filename);
-      *cp++ = '/';
-      strcpy(cp, PFILE);
-    }
+      filename = getenv("BISON_SIMPLE");
+#ifdef MSDOS
+      /* File doesn't exist in current directory; try in INIT directory.  */
+      cp = getenv("INIT");
+      if (filename == 0 && cp != NULL)
+        {
+          filename = xmalloc(strlen(cp) + strlen(PFILE) + 2);
+          strcpy(filename, cp);
+          cp = filename + strlen(filename);
+          *cp++ = '/';
+          strcpy(cp, PFILE);
+        }
 #endif /* MSDOS */
-  fparser = tryopen(filename ? filename : PFILE, "r");
+      fparser = tryopen(filename ? filename : PFILE, "r");
+    }
 
   if (verboseflag)
     {
@@ -217,19 +222,29 @@ openfiles()
       foutput = tryopen(outfile, "w");
     }
 
+  if (noparserflag)
+    {
+      /* use permanent name for actions file */
+      actfile = stringappend(name_base, short_base_length, ".act");
+      faction = tryopen(actfile, "w");
+    } 
+
 #ifdef MSDOS
-  actfile = mktemp(stringappend(tmp_base, tmp_len, "acXXXXXX"));
+  if (! noparserflag)
+    actfile = mktemp(stringappend(tmp_base, tmp_len, "acXXXXXX"));
   tmpattrsfile = mktemp(stringappend(tmp_base, tmp_len, "atXXXXXX"));
   tmptabfile = mktemp(stringappend(tmp_base, tmp_len, "taXXXXXX"));
   tmpdefsfile = mktemp(stringappend(tmp_base, tmp_len, "deXXXXXX"));
 #else
-  actfile = mktemp(stringappend(tmp_base, tmp_len, "act.XXXXXX"));
+  if (! noparserflag)
+    actfile = mktemp(stringappend(tmp_base, tmp_len, "act.XXXXXX"));
   tmpattrsfile = mktemp(stringappend(tmp_base, tmp_len, "attrs.XXXXXX"));
   tmptabfile = mktemp(stringappend(tmp_base, tmp_len, "tab.XXXXXX"));
   tmpdefsfile = mktemp(stringappend(tmp_base, tmp_len, "defs.XXXXXX"));
 #endif /* not MSDOS */
 
-  faction = tryopen(actfile, "w+");
+  if (! noparserflag)
+    faction = tryopen(actfile, "w+");
   fattrs = tryopen(tmpattrsfile,"w+");
   ftable = tryopen(tmptabfile, "w+");
 
@@ -240,7 +255,8 @@ openfiles()
     }
 
 #ifndef MSDOS
-  unlink(actfile);
+  if (! noparserflag)
+    unlink(actfile);
   unlink(tmpattrsfile);
   unlink(tmptabfile);
   unlink(tmpdefsfile);
@@ -278,22 +294,26 @@ open_extra_files()
   int c;
   char *filename, *cp;
 
-  fclose(fparser);
+  if (fparser)
+    fclose(fparser);
 
-  filename = (char *) getenv ("BISON_HAIRY");
-#ifdef MSDOS
-  /* File doesn't exist in current directory; try in INIT directory.  */
-  cp = getenv("INIT");
-  if (filename == 0 && cp != NULL)
+  if (! noparserflag) 
     {
-      filename = xmalloc(strlen(cp) + strlen(PFILE1) + 2);
-      strcpy(filename, cp);
-      cp = filename + strlen(filename);
-      *cp++ = '/';
-      strcpy(cp, PFILE1);
-    }
+      filename = (char *) getenv ("BISON_HAIRY");
+#ifdef MSDOS
+      /* File doesn't exist in current directory; try in INIT directory.  */
+      cp = getenv("INIT");
+      if (filename == 0 && cp != NULL)
+        {
+          filename = xmalloc(strlen(cp) + strlen(PFILE1) + 2);
+          strcpy(filename, cp);
+          cp = filename + strlen(filename);
+          *cp++ = '/';
+          strcpy(cp, PFILE1);
+        }
 #endif
-  fparser= tryopen(filename ? filename : PFILE1, "r");
+      fparser= tryopen(filename ? filename : PFILE1, "r");
+    }
 
 		/* JF change from inline attrs file to separate one */
   ftmp = tryopen(attrsfile, "w");
@@ -374,7 +394,7 @@ int k;
     }
 
 #if defined (VMS) & !defined (__VMS_POSIX)
-  if (faction)
+  if (faction && ! noparserflag)
     delete(actfile);
   if (fattrs)
     delete(tmpattrsfile);
@@ -384,7 +404,7 @@ int k;
   sys$exit(SS$_ABORT);
 #else
 #ifdef MSDOS
-  if (actfile) unlink(actfile);
+  if (actfile && ! noparserflag) unlink(actfile);
   if (tmpattrsfile) unlink(tmpattrsfile);
   if (tmptabfile) unlink(tmptabfile);
   if (tmpdefsfile) unlink(tmpdefsfile);
