@@ -1,5 +1,5 @@
 /* Open and close files for bison,
-   Copyright (C) 1984, 1986, 1989, 1992, 2000 Free Software Foundation, Inc.
+   Copyright 1984, 1986, 1989, 1992, 2000 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -53,9 +53,10 @@ FILE *fdefines = NULL;
 FILE *ftable = NULL;
 FILE *fattrs = NULL;
 FILE *fguard = NULL;
-FILE *faction = NULL;
 FILE *fparser = NULL;
 
+struct obstack action_obstack;
+
 /* File name specified with -o for the output file, or 0 if no -o.  */
 char *spec_outfile;
 
@@ -289,25 +290,18 @@ open_files (void)
     {
       /* use permanent name for actions file */
       actfile = stringappend (name_base, short_base_length, ".act");
-      faction = xfopen (actfile, "w");
     }
 
 #ifdef MSDOS
-  if (!no_parser_flag)
-    actfile = mktemp (stringappend (tmp_base, tmp_len, "acXXXXXX"));
   tmpattrsfile = mktemp (stringappend (tmp_base, tmp_len, "atXXXXXX"));
   tmptabfile = mktemp (stringappend (tmp_base, tmp_len, "taXXXXXX"));
   tmpdefsfile = mktemp (stringappend (tmp_base, tmp_len, "deXXXXXX"));
 #else
-  if (!no_parser_flag)
-    actfile = mktemp (stringappend (tmp_base, tmp_len, "act.XXXXXX"));
   tmpattrsfile = mktemp (stringappend (tmp_base, tmp_len, "attrs.XXXXXX"));
   tmptabfile = mktemp (stringappend (tmp_base, tmp_len, "tab.XXXXXX"));
   tmpdefsfile = mktemp (stringappend (tmp_base, tmp_len, "defs.XXXXXX"));
 #endif /* not MSDOS */
 
-  if (!no_parser_flag)
-    faction = xfopen (actfile, "w+");
   fattrs = xfopen (tmpattrsfile, "w+");
   ftable = xfopen (tmptabfile, "w+");
 
@@ -318,8 +312,6 @@ open_files (void)
     }
 
 #if !(defined (MSDOS) || (defined(_WIN32) && !defined(__CYGWIN32__)))
-  if (!no_parser_flag)
-    unlink (actfile);
   unlink (tmpattrsfile);
   unlink (tmptabfile);
   unlink (tmpdefsfile);
@@ -343,6 +335,9 @@ open_files (void)
   guardfile = stringappend (name_base, short_base_length, ".guard.c");
 #endif /* not MSDOS */
 #endif /* not VMS */
+
+  /* Setup the action obstack. */
+  obstack_init (&action_obstack);
 }
 
 
@@ -397,7 +392,6 @@ open_extra_files (void)
 void
 done (void)
 {
-  xfclose (faction);
   xfclose (fattrs);
   xfclose (fguard);
   xfclose (finput);
@@ -429,9 +423,14 @@ done (void)
 	}
     }
 
+  if (no_parser_flag)
+    {
+      FILE *faction = xfopen (actfile, "w");
+      size_t size = obstack_object_size (&action_obstack);
+      fwrite (obstack_finish (&action_obstack), 1, size, faction);
+      fclose (faction);
+    }
 #if defined (VMS) & !defined (__VMS_POSIX)
-  if (faction && !no_parser_flag)
-    delete (actfile);
   if (fattrs)
     delete (tmpattrsfile);
   if (ftable)
@@ -442,8 +441,6 @@ done (void)
   sys$exit(SS$_ABORT); */
 #else
 #if (defined (MSDOS) || (defined(_WIN32) && !defined(__CYGWIN32__)))
-  if (actfile && !no_parser_flag)
-    unlink (actfile);
   if (tmpattrsfile)
     unlink (tmpattrsfile);
   if (tmptabfile)
